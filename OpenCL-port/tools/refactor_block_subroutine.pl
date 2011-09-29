#!/usr/bin/perl
use warnings;
use strict;

=TODOs
- Create intermediate directories for converted files
- Determine if a subroutine argument is I, O or I/O => OK
- Determine variables with same name as functions. F2C-ACC doesn't remove those, although it should. => OK
- Refactor FUNCTIONS!! and translate to C and emit headers as well
- Declarations from F2C-ACC are broken, emit our own => OK
- But F2C-ACC's function calls are wrong too! They use the non-pointer vars where they should use the pointers! => OK
- Put F2C-ACC into our tree, if the license allows it. => OK
=cut

=pod
Draft Outline  

0.2 Get rid of "common" variables, move them into function arguments 
		This is refactoring, and there is really only one proper way to do this:
		- parse the FORTRAN source in a labeled-block-aware way
		- check which variables from the common block are used
		- put them in the function signature
		- for variables declared outside the block in question, find the ones that are used within the block
		and add them to the function signature as well

Now, I don't have a full FORTRAN parser, but let's see what we can do with some limiting assumptions:
- assume the block is simply identified with a comment "C BEGIN blockname" and "C END blockname"
- assume any line starting with /^\s[\+\&]/ is a continuation line, deal with these first
- assume that _all_ variables in includecom are common, and _all_ variable in includepar are parameters?
That won't do. No, we read the includes, and parse the "common" blocks
- we're only really interested in a few specific intrinsic types: 
/(integer|real|double\s+precision|character\*?(?:\d+|\(\*\)))\s+(.+)\s*$/ 

The most difficult bit is finding the variables, I guess \W$varname\W should do?

With these assumptions, we can write a crude parser and function arg identifier as follows:
0. Slurp the source; strip the comments
1. Join up the continuation lines (maybe split lines with ; )
2. Parse the type declarations in the source, create a table %vars
3. Parse includes, recursively doing 0/1/2
4. For includes, parse common blocks, create %commons
5. Split the source based on the block markers
6. Identify which vars are used
	- in both => these become function arguments
	- only in "outer" => do nothing for those
	- only in "inner" => can be removed from outer variable declarations
7. Identify which commons are used in inner, make them function arguments

Not necessarily in this order:
8. When encountering a CALL, recurse and resolve globals (but only that)
9. When encountering a  function call, idem; although I'd prefer it if functions would be pure!
10. F2C-ACC is a bit buggy, so help it a bit: identify which CONTINUE statements are actually END DO
and replace them accordingly; for the other CONTINUE statements, it might be better to 
ensure that instead of CONTINUE, they do nothing in a different way. 
The only reliable way I found is to replace the continue with call noop, where noop is a subroutine that does nothing

How do we replace the args in a subroutine call?

- Find a subroutine call
- first check if we now about it by looking in a list of subroutine calls => We use 'IsSub'
- if we know it, it means we have resolved the globals, the list should be added to the node;
then just add the globals to the call
- otherwise, add the index in the list of source lines to a hash of subs 
- in fact, this can be a hash of "anythings", i.e.
 
    $stref->{'Nodes'}{$filename}{'SubroutineCall'}{$name}={'Pos'=>[$index,...],'Globals'=>[],...};
    
    As this is a "global", I need to pass it around between calls.
- recurse and figure out globals used. also, store the signature in the node hash
- add the globals to the end of the signature, and emit the new code.
- it would be nice to emit the code in a hash 

    $refactored_sources{$filename}=\@lines;
    
- return the list of all the globals to be added to the call
- update the call in %refactored_sources

    'Subroutines' => { 
                    $name => {
                       'Source' => $src,
                       'Lines' =>[$line],
                       'Blocks'=>{},
                       'HasBlocks'=>0|1
                       'Signature'=>{'Pos'=>[$index,...],'Globals'=>[],...};
                       'VarDecls'=>
                       'RefactoredCode' => {},    
                       'Status' => 0|1|2|3        
                     }
    }

Status: for programs, subroutines, functions and includes 
    0: after find_subroutines_functions_and_includes() 
    1: after read_fortran_src()
    2: after parse_fortran_src()
    3: after create_subroutine_source_from_block()
After building this structure, what we need is to go through it an revert it so it becomes index => information

とにかく, コード　は:

=cut

use Getopt::Std;

use File::Find;
use File::Copy;
use Digest::MD5;
our $V              = 0;
our $noop           = 1;
our $call_tree_only = 0;
our $main_tree      = 0;
our $gen_sub        = 0;
our $translate      = 0;
our $sub_to_translate='';

our $targetdir = '../RefactoredSources';
use Data::Dumper;

&main();

# -----------------------------------------------------------------------------
sub main {
	if ( not @ARGV ) {
		die "Please specifiy FORTRAN subroutine or program to refactor\n";
	}
	my %opts = ();
	getopts( 'vhCTNbB', \%opts );
	my $subname = $ARGV[0];
	$subname =~ s/\.f$//;

	#	  die %opts;
	$V = ( $opts{'v'} ) ? 1 : 0;
	my $help = ( $opts{'h'} ) ? 1 : 0;
	if ($help) {
		die "
    $0 [-hvC] <toplevel subroutine name> [<(extracted) subroutine name>]
    -h: help
    -v: verbose
    -C: Only generate call tree, don't refactor or emit
    -T: Translate <subroutine name> and dependencies to C 
    -N: Don't replace CONTINUE by CALL NOOP
    -b: Generate SCons build script, currently ignored 
    -B: Build FLEXPART (implies -b)
    ";
	}

	if ( $opts{'C'} ) {
		$call_tree_only = 1;
		$main_tree = $ARGV[1] ? 0 : 1;
		print "\nCall tree for $subname:\n\n" if $main_tree;
	}
	if ( $opts{'T'} ) {
		if ( !@ARGV ) {
			die "Please specify a target subroutine to translate.\n";
		}
		$translate = 1;
		$sub_to_translate=$ARGV[1];
	}
	$noop = ( $opts{'N'} ) ? 0 : 1;
	my $gen = ( $opts{'b'} || $opts{'B'} ) ? 1 : 0;
	my $build = ( $opts{'B'} ) ? 1 : 0;

	my $stateref = {
		'Top'          => $subname,
		'Includes'     => {},
		'Subroutines'  => {},
		'BuildSources' => {}
		,    # sources to be built, need to disinguish between C and Fortran
		'Targets' => {}
		,    # targets for translation to C, make this {'BuildSources'}{'C'}
		'Indents' => 0
	};

	# Find all subroutines in the source code tree
	$stateref = find_subroutines_functions_and_includes($stateref);

# First we analyse the code for use of globals and blocks to be transformed into subroutines
	$stateref = parse_fortran_src( $subname, $stateref );

	# Refactor the source
	$stateref = refactor_all_subroutines($stateref);
	$stateref = refactor_includes($stateref);
#    $stateref = refactor_functions($stateref);
    
	if ( not $call_tree_only ) {

		# Emit the refactored source
		emit_all($stateref);
	} elsif ( $call_tree_only and $ARGV[1] ) {
		$subname = $ARGV[1];
		$gen_sub = 1;
		print "\nCall tree for $subname:\n\n";
		$stateref = parse_fortran_src( $subname, $stateref );
	}
	if ( $translate == 1 ) {
		$translate = 2;
		$subname   = $sub_to_translate;
		print "\nTranslating $subname to C\n";
		$gen_sub = 1;
		$stateref = parse_fortran_src( $subname, $stateref );
		$stateref = refactor_C_targets($stateref);
		emit_C_targets($stateref);
		&translate_to_C($stateref);
	}
	create_build_script($stateref);
	if ($build) {
		build_flexpart();
	}
	exit(0);

}    # END of main()

# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
# This is the most important routine
# It parses the FORTRAN source as discussed above
# Identification of
# Signature
# VarDecl
# InBlock etc
# Includes
=haskell
-- We really need to use the State monad!
parse_fortran_src :: String -> STRef -> STRef
parse_fortran_src  f stref =
    let
        stref' = read_fortran_src f stref
        m_incls = Hash.lookup "Includes" stref
        is_incl = case m_incls of
            Just incls -> Hash.member f incls
            Nothing -> False
        stref'' = get_var_decls f stref'
=cut
sub parse_fortran_src {
	( my $f, my $stref ) = @_;

	# Read the source and do some minimal processsing
	$stref = read_fortran_src( $f, $stref );

	my $is_incl = exists $stref->{'Includes'}{$f} ? 1 : 0;

	# 2. Parse the type declarations in the source, create a table %vars
	$stref = get_var_decls( $f, $stref );

	# 3. Parse includes, recursively doing 0/1/2
	if ( not $is_incl ) {

		#		die if $f eq 'timemanager';
		$stref = detect_blocks( $f, $stref );

		#		die Dumper($stref->{'Subroutines'}{'llij_lc'}) if $f=~/latlon_to_ij/;
		$stref = parse_includes( $f, $stref );

		$stref = parse_subroutine_calls( $f, $stref );
		$stref = identify_globals_used_in_subroutine( $f, $stref );
        $stref = determine_argument_io_direction($f,$stref);
# 5. Split the source based on the block markers
# As there could be several blocks (later), use a hash per block
# This could happen in any file except includes; but include processing never comes here
		if ( $stref->{'Subroutines'}{$f}{'HasBlocks'} == 1 ) {
			$stref = separate_blocks( $f, $stref );
		}
		$stref = identify_loops_breaks( $f, $stref );
		$stref->{'Subroutines'}{$f}{'Status'} = 2;
	} else {    # includes
		 # 4. For includes, parse common blocks and parameters, create $stref->{'Commons'}
		$stref = get_commons_params_from_includes( $f, $stref );
	}

	return $stref;

}    # END of parse_fortran_src()

# -----------------------------------------------------------------------------
sub refactor_globals {
	
	( my $stref, my $f, my $annlines ) = @_;
	print "REFACTORING GLOBALS in $f\n" if $V;
	my $rlines = [];
	my @globs  = ();
	my $s=$stref->{'Subroutines'}{$f}{'Source'};
	my $is_C_target=exists $stref->{'BuildSources'}{'C'}{$s}?1:0;
		
	# Quick and dirty way to get the Kinds of all arguments
	my %maybe_args = ();
	for my $inc ( keys %{ $stref->{'Subroutines'}{$f}{'Globals'} } ) {
		if (defined $stref->{'Subroutines'}{$f}{'Globals'}{$inc}) {
		@globs = ( @globs, @{ $stref->{'Subroutines'}{$f}{'Globals'}{$inc} } );
		}
		if (defined $stref->{'Includes'}{$inc}{'Vars'}) {
		%maybe_args=(%maybe_args,%{ $stref->{'Includes'}{$inc}{'Vars'}  });
		}
	}
	%maybe_args=(%{ $stref->{'Subroutines'}{$f}{'Vars'} },%maybe_args);	
	my %globals            = map { $_ => 1 } @globs;
	my %args               = ();
	my %conflicting_locals = ();
	for my $annline ( @{$annlines} ) {
		my $line      = $annline->[0] || '';
		my $tags_lref = $annline->[1];
		my %tags      = ( defined $tags_lref ) ? %{$tags_lref} : ();
		print '*** ' . join( ',', keys(%tags) ) . "\n" if $V;
		print '*** ' . $line . "\n" if $V;
		my $skip = 0;

		if ( exists $tags{'Signature'} ) {
			my $name = $tags{'Signature'}{'Name'};
			%args = map { $_ => 1 } @{ $tags{'Signature'}{'Args'} };
			my @exglobs = ();
			for my $inc ( keys %{ $stref->{'Subroutines'}{$f}{'Globals'} } ) {
				print "INFO: INC $inc in $f\n" if $V;
				if ( not exists $stref->{'Includes'}{$inc}{'Root'} ) {
					die "$inc has no Root in $f";
				}
				if ( $stref->{'Includes'}{$inc}{'Root'} eq $f ) {
					print "INFO: $f is root for $inc\n" if $V;
					next;
				}
				if (defined $stref->{'Subroutines'}{$f}{'Globals'}{$inc} ) {
					for my $var ( @{ $stref->{'Subroutines'}{$f}{'Globals'}{$inc} } ) {
						if (not exists $stref->{'Subroutines'}{$f}{'Vars'}{$var}){
						$stref->{'Subroutines'}{$f}{'Vars'}{$var}=$stref->{'Includes'}{$inc}{'Vars'}{$var};
						}
					}
				@exglobs = (
					@exglobs, @{ $stref->{'Subroutines'}{$f}{'Globals'}{$inc} }
				);
				}
			}			
			my $args_ref =
			  ordered_union( $tags{'Signature'}{'Args'}, \@exglobs );
			  $stref->{'Subroutines'}{$f}{'RefactoredArgList'} = $args_ref;
			my $args_str = join( ',', @{$args_ref} );
			my $rline = '';
			if ( $stref->{'Subroutines'}{$f}{'Program'} ) {
				$rline = '      program ' . $name;
			} else {
				$rline = '      subroutine ' . $name . '(' . $args_str . ')';
			}
			$tags{'Refactored'} = 1;
			push @${rlines}, [ $rline, $tags_lref ];
			# IO direction information
			for my $arg ( @{$args_ref} ) {
				if (exists  $stref->{'Subroutines'}{$f}{'RefactoredArgs'}{$arg} ) {
				    my $iodir = $stref->{'Subroutines'}{$f}{'RefactoredArgs'}{$arg};
				    my $kind='Unknown';
				    if (exists $maybe_args{$arg}{'Kind'}) {
				    	$kind=$maybe_args{$arg}{'Kind'};
				    }
				    my $ntabs=' ' x 8;
				    if ($iodir eq 'In' and $kind eq 'Scalar') {
				    	$ntabs='';
				    } elsif ($iodir eq 'Out') {
				    	$ntabs=' ' x 4;
				    }
				    my $comment ="C      $ntabs$arg:\t$iodir, $kind"; 
				    push @${rlines}, [ $comment, {'Comment'=>1} ];
				} else {
					warn "NO IO info for $arg in $f\n";
				}
			}
			$skip = 1;
		}

		if ( exists $tags{'Include'} ) {
			my $inc = $tags{'Include'}{'Name'};
			print "INFO: INC $inc in $f\n" if $V;
			if (
				$stref->{'Includes'}{$inc}{'Type'} eq 'Common' and (
					$stref->{'Includes'}{$inc}{'Root'} ne $f

#                or ( ($stref->{'Includes'}{$inc}{'Root'} eq $f) and ($f eq $stref->{'Top'}))
				)
			  )
			{
				if ($V) {
					print "SKIPPED $inc: Root: ",
					  ( $stref->{'Includes'}{$inc}{'Root'} ne $f ) ? 0 : 1,
					  "\tTop:",
					  (       ( $stref->{'Includes'}{$inc}{'Root'} eq $f )
						  and ( $f eq $stref->{'Top'} ) ) ? 1 : 0, "\n";
				}
				$skip = 1;
			}
		}

		if ( exists $tags{'ExGlobVarDecls'} ) {

			# We abuse ExGlobVarDecls as a hook for the addional includes
			for my $inc ( keys %{ $stref->{'Subroutines'}{$f}{'Globals'} } ) {
				print "INC: $inc, root: $stref->{'Includes'}{$inc}{'Root'} \n"
				  if $V;
				if (    $stref->{'Subroutines'}{$f}{'Includes'}{$inc} < 0
					and $f eq $stref->{'Includes'}{$inc}{'Root'} )
				{   # and $f ne $stref->{'Top'}) { # FIXME: not sure about this!
					my $rline = "      include '$inc'";
					$tags_lref->{'Include'}{'Name'} = $inc;
					push @{$rlines}, [ $rline, $tags_lref ];
				}
			}

			for my $inc ( keys %{ $stref->{'Subroutines'}{$f}{'Globals'} } ) {
				print "INFO: GLOBALS from INC $inc in $f\n" if $V;
				for
				  my $var ( @{ $stref->{'Subroutines'}{$f}{'Globals'}{$inc} } )
				{
					if ( exists $args{$var} ) {
						my $rline = "*** ARG MASKS GLOB $var in $f!";
						push @{$rlines}, [ $rline, $tags_lref ];
					} else {
						if (
							exists $stref->{'Subroutines'}{$f}{'Commons'}
							{$inc} )
						{
							if ( $f ne $stref->{'Includes'}{$inc}{'Root'} ) {
								print "\tGLOBAL $var from $inc in $f\n" if $V;
								my $rline =
								  $stref->{'Subroutines'}{$f}{'Commons'}{$inc}
								  {$var}{'Decl'};
								if ( not defined $rline ) {
									print "*** NO DECL for $var in $f!\n" if $V;
									$rline = "*** NO DECL for $var in $f!";
								}
								push @{$rlines}, [ $rline, $tags_lref ];
							} elsif ($V) {
								print
"*** NO COMMONS from $inc because $f is Root\n";
								last;
							}
						} elsif ($V) {
							print "*** NO COMMONS for $inc in $f ";
							if ( $f eq $stref->{'Includes'}{$inc}{'Root'} ) {
								print '(Root)' . "\n";
							} else {
								print 'BUT NOT ROOT!' . "\n";
							}
							last;
						}
					}
				}    # for
			}
		}
		if ( exists $tags{'VarDecl'} ) {
			my @vars  = @{ $tags{'VarDecl'} };			
			my $rline = $line;
			my @nvars=();
			for my $var (@vars) {
				if (exists $stref->{'Functions'}{$var} and $is_C_target) {
					print "WARNING: $var in $f is a function!\n";
					$stref->{'Subroutines'}{$f}{'CalledFunctions'}{$var}=1;					
				} else {
				if ( exists $globals{$var} and not exists $args{$var} ) {
					print STDERR
"WARNING: local $var in $f ($stref->{'Subroutines'}{$f}{'Source'}) conflicts with global of same name, will be renamed to $var\_LOCAL\n";

# We should actually rename these conflicting vars, rather than removing them.
# The complication is that the global of the same name might have to be passed to a subroutine call
# So in each call we must check first for the local, then for the global
					my $nvar = $var . '_LOCAL';
					$conflicting_locals{$var} = $nvar;                    
					$rline =~ s/\b$var\b/$nvar/;
					push @nvars,$nvar;
				} else {
					push @nvars,$var;
				}
				}
			}
			$rline =~ s/,\s*$//;
			if ($line!~/\(.*?\)/) { # FIXME: can't handle arrays yet!
                # NEW code
                my $spaces=$line;
                $spaces=~s/[^\s].*$//;
			    $rline=$spaces.$stref->{'Subroutines'}{$f}{'Vars'}{$vars[0]}{'Type'}.' '.join(',',@nvars)."\n";			    
			} 
			
			push @{$rlines}, [ $rline, $tags_lref ];
			$skip = 1;
		}
		if ( exists $tags{'SubroutineCall'} ) {
			# simply tag the common vars onto the arguments
			my $name    = $tags{'SubroutineCall'}{'Name'};
			my @globals = ();
			for my $inc ( keys %{ $stref->{'Subroutines'}{$name}{'Globals'} } )
			{
				next if $stref->{'Includes'}{$inc}{'Root'} eq $name;
				if (defined $stref->{'Subroutines'}{$name}{'Globals'}{$inc} ) {
				@globals = (
					@globals,
					@{ $stref->{'Subroutines'}{$name}{'Globals'}{$inc} }
				);
				}
			}
			my $orig_args = [];
			for my $arg ( @{ $tags{'SubroutineCall'}{'Args'} } ) {
				if ( exists $conflicting_locals{$arg} ) {
					push @{$orig_args}, $conflicting_locals{$arg};
				} else {
					push @{$orig_args}, $arg;
				}
			}

			my $args_ref = ordered_union( $orig_args, \@globals );
			my $args_str = join( ',', @{$args_ref} );
			$line =~ s/call\s.*$//;
			my $rline = "call $name($args_str)\n";
			push @{$rlines}, [ $line . $rline, $tags_lref ];
			$skip = 1;
		}
		if ( not exists $tags{'Comments'} and $skip == 0 ) {
			my $rline = $line;
			for my $lvar ( keys %conflicting_locals ) {
				if ( $rline =~ /\b$lvar\b/ ) {

#                   print  "REPLACING $lvar with $conflicting_locals{$lvar} in $f LINE '$line'\n";
					$rline =~ s/\b$lvar\b/$conflicting_locals{$lvar}/g;
				}
			}
			push @{$rlines}, [ $rline, $tags_lref ];
			$skip = 1;
		}
		push @{$rlines}, $annline unless $skip;
	}
	return $rlines;
}    # END of refactor_globals()

# -----------------------------------------------------------------------------
sub refactor_blocks {
	( my $stref, my $f, my $annlines ) = @_;
	my $rlines = [];
	print "REFACTORING BLOCKS in $f\n" if $V;
	my @blocks = ();
	my $name   = 'NONE';
	for my $annline ( @{$annlines} ) {
		my $line      = $annline->[0];
		my $tags_lref = $annline->[1];
		my %tags =
		  ( defined $tags_lref )
		  ? %{$tags_lref}
		  : ( 'Nil' => [] );    # FIXME: needed?
		my $skip = 0;
		if ( exists $tags{'RefactoredSubroutineCall'} ) {
			$name = $tags{'RefactoredSubroutineCall'}{'Name'};
			$tags{'RefactoredSubroutineCall'}{'Args'} =
			  [ @{ $stref->{'Subroutines'}{$f}{'Blocks'}{$name}{'Args'} } ];
			push @blocks, $name;

			#we should refactor the block here to get the correct args
			#                $stref=$refactor_block_->($name,$f,$stref);
			my @args = @{ $stref->{'Subroutines'}{$name}{'Args'} };
			my $rline = 'C     call ' . $name . '(' . join( ',', @args ) . ')';
			$tags_lref = {%tags};
			delete $tags_lref->{'Comments'};
			push @{$rlines}, [ $rline, $tags_lref ];
			$skip = 1;
		}
		if ( exists $tags{'InBlock'} or exists $tags{'EndBlock'} ) {
			if ( $name ne 'NONE' ) {
				push @{ $stref->{'Subroutines'}{$f}{'Blocks'}{$name}{'Info'} },
				  $tags_lref;
			}
			$skip = 1;
		}
		push @{$rlines}, $annline unless $skip;
	}

	for my $name (@blocks) {
		$stref = create_subroutine_source_from_block( $name, $f, $stref );

		# Now we must parse this source
		$stref = get_var_decls( $name, $stref );
		$stref = parse_includes( $name, $stref );
		$stref = parse_subroutine_calls( $name, $stref );
		$stref = identify_globals_used_in_subroutine( $name, $stref );
        $stref = determine_argument_io_direction($name,$stref);
		# Now we're ready to refactor this source
		$stref = refactor_subroutine( $name, $stref );    # shiver!
	}

	# Now go through the lines again and create the proper call
	#        $annlines=$rlines;
	for my $annline ( @{$rlines} ) {
		my $line      = $annline->[0];
		my $tags_lref = $annline->[1];
		my %tags =
		  ( defined $tags_lref )
		  ? %{$tags_lref}
		  : ( 'Nil' => [] );                              # FIXME: needed?
		if ( exists $tags{'RefactoredSubroutineCall'} ) {

			# simply tag the common vars onto the arguments
			my $name    = $tags{'RefactoredSubroutineCall'}{'Name'};
			my @globals = ();
			for my $inc ( keys %{ $stref->{'Subroutines'}{$name}{'Globals'} } )
			{
				next if $stref->{'Includes'}{$inc}{'Root'} eq $name;
				@globals = (
					@globals,
					@{ $stref->{'Subroutines'}{$name}{'Globals'}{$inc} }
				);
			}
			my $orig_args = [];

			# FIXME: do I need to check for conflicting locals?
			for my $arg ( @{ $tags{'RefactoredSubroutineCall'}{'Args'} } ) {

		  #                    if (exists $conflicting_locals{$arg}) {
		  #                        push @{$orig_args},$conflicting_locals{$arg};
		  #                    } else {
				push @{$orig_args}, $arg;

				#                    }
			}
			my $args_ref = ordered_union( $orig_args, \@globals );
			my $args_str = join( ',', @{$args_ref} );
			my $rline = "      call $name($args_str)";
			$annline->[0] = $rline;
		}
	}

	return ( $stref, $rlines );
}    # END of refactor_blocks()

# -----------------------------------------------------------------------------

#* BeginDo: just remove the label
#* EndDo: replace label CONTINUE by END DO
#* Break: keep as is; add a comment to identify it as a break
#* Goto: Do nothing
#* GotoTarget: Do nothing
#* NoopBreakTarget: replace CONTINUE with "call noop"
#* BreakTarget: Do nothing
sub create_refactored_source {
	( my $stref, my $f, my $annlines ) = @_;
	print "CREATING FINAL $f CODE\n" if $V;
	my $rlines      = [];
	my @extra_lines = ();
	$stref->{'Subroutines'}{$f}{'RefactoredCode'} =[];
	for my $annline ( @{$annlines} ) {
		my $line = $annline->[0] || '';    # FIXME: why would line be undefined?
		my $tags_lref = $annline->[1] || {};
		my %tags = %{$tags_lref};

		# BeginDo: just remove the label
		if ( exists $tags{'BeginDo'} ) {
			$line =~ s/do\s+\d+\s+/do /;
		}

# EndDo: replace label CONTINUE by END DO; if no continue, remove label & add end do on next line
		if ( exists $tags{'EndDo'} ) {
			my $is_goto_target = 0;
			if ( $stref->{'Subroutines'}{$f}{'Gotos'}
				{ $tags{'EndDo'}{'Label'} } )
			{

				# this is an end do which serves as a goto target
				$is_goto_target = 1;
			}
			my $count = $tags{'EndDo'}{'Count'};
			if ( $line =~ /^\s{0,4}\d+\s+continue/ ) {
				if ( $is_goto_target == 0 ) {
					$line = '      end do';
					$count--;
				} elsif ($noop) {
					$line =~ s/continue/call noop/;
				}
			} elsif ( $line =~ /^\d+\s+\w/ ) {
				if ( $is_goto_target == 0 ) {
					$line =~ s/^\d+//;
				}
			}
			while ( $count > 0 ) {
				push @extra_lines, '      end do';
				$count--;
			}
		}
		if ( $noop && (exists $tags{'NoopBreakTarget'} || exists $tags{'NoopTarget'})) {
			$line =~ s/continue/call noop/;
		}
		if ( exists $tags{'Break'} ) {
			$line .= '  !Break';
			# $line=~s/goto\s+(\d+)/call break($1)/;
		}

		if ( exists $tags{'PlaceHolders'} ) {
			my @phs = @{ $tags{'PlaceHolders'} };
			for my $ph (@phs) {
				my $str = $stref->{'Subroutines'}{$f}{'StringConsts'}{$ph};
				$line =~ s/$ph/$str/;
			}
		}
		if ( not exists $tags{'Comments'} ) {
			print $line, "\n" if $V;
			my @split_lines = split_long_line($line);
			for my $sline (@split_lines) {
				push @{ $stref->{'Subroutines'}{$f}{'RefactoredCode'} }, $sline;
			}
			if (@extra_lines) {
				for my $extra_line (@extra_lines) {
					push @{ $stref->{'Subroutines'}{$f}{'RefactoredCode'} },
					  $extra_line;
				}
				@extra_lines = ();
			}
		} else {
			push @{ $stref->{'Subroutines'}{$f}{'RefactoredCode'} }, $line;
		}
	}
	return $stref;
}    # END of create_refactored_source()

# -----------------------------------------------------------------------------

=info_refactoring

for every line
- check if it needs changing:
- need to mark the insert points for subroutine calls that replace the refactored blocks! 
This is a node called 'RefactoredSubroutineCall'
- we also need the "entry point" for adding the declarations for the localized global variables 'ExGlobVarDecls'

* Signature: add the globals to the signature
(* VarDecls: keep as is)
* ExGlobVarDecls: add new var decls
* SubroutineCall: add globals for that subroutine to the call
* RefactoredSubroutineCall: insert a new subroutine call instead of the "begin of block" comment. 
* InBlock: skip; we need to handle the blocks separately
* BeginBlock: insert the new subroutine signature and variable declarations
* EndBlock: insert END
                      

=cut

sub refactor_subroutine {
	( my $f, my $stref ) = @_;
	if ($V) {
		print "\n\n";
		print "#" x 80, "\n";
		print "Refactoring $f\n";
		print "#" x 80, "\n";
	}

	print "REFACTORING SUBROUTINE $f\n" if $V;
	#print Dumper($stref->{'Subroutines'}{$f}{'Info'}) if $f eq 'llij_lc';
	my @lines = @{ $stref->{'Subroutines'}{$f}{'Lines'} };
	my @info =
	  defined $stref->{'Subroutines'}{$f}{'Info'}
	  ? @{ $stref->{'Subroutines'}{$f}{'Info'} }
	  : ();
	my $annlines = [];
	for my $line (@lines) {
		my $tags = shift @info;
		push @{$annlines}, [ $line, $tags ];
	}

	my $rlines = $annlines;

	if ( $stref->{'Subroutines'}{$f}{'HasCommons'} ) {
		$rlines = refactor_globals( $stref, $f, $annlines );
	}

	if ( $stref->{'Subroutines'}{$f}{'HasBlocks'} == 1 ) {
		( $stref, $rlines ) = refactor_blocks( $stref, $f, $rlines );
	}    # HasBlocks

	if ( not exists $stref->{'Subroutines'}{$f}{'RefactoredCode'}
		or $stref->{'Subroutines'}{$f}{'RefactoredCode'} == [] or exists $stref->{'BuildSources'}{'C'}{ $stref->{'Subroutines'}{$f}{'Source'} } )
	{		
		$stref = create_refactored_source( $stref, $f, $rlines );
	}

#   print STDERR "REFACTORED $f\n";
#    die Dumper($stref->{'Subroutines'}{$f}{'RefactoredCode'}) if $f eq 'hanna_short' and $translate==2;
	return $stref;
}    # END of refactor_subroutine()

# -----------------------------------------------------------------------------
sub refactor_all_subroutines {
	( my $stref ) = @_;

	#	print Dumper(keys %{ $stref->{'Subroutines'} });
	for my $f ( keys %{ $stref->{'Subroutines'} } ) {

		if ( not defined $stref->{'Subroutines'}{$f}{'Status'} ) {
			$stref->{'Subroutines'}{$f}{'Status'} = 0;
			print STDERR "WARNING: no Status for $f\n";
			print "WARNING: no Status for $f\n";
		}
		next                    if $stref->{'Subroutines'}{$f}{'Status'} == 0;
		warn "Not parsed: $f\n" if $stref->{'Subroutines'}{$f}{'Status'} == 1;
		next                    if $stref->{'Subroutines'}{$f}{'Status'} == 3;
		$stref = refactor_subroutine( $f, $stref );
	}

	return $stref;
}    # END of refactor_all_subroutines()
#  -----------------------------------------------------------------------------
sub refactor_C_targets {
    ( my $stref ) = @_;
print "\nREFACTORING C TARGETS\n";
    #   print Dumper(keys %{ $stref->{'Subroutines'} });
    for my $f ( keys %{ $stref->{'Subroutines'} } ) {
    	if (exists $stref->{'BuildSources'}{'C'}{ $stref->{'Subroutines'}{$f}{'Source'} } ) {
            $stref = refactor_subroutine( $f, $stref );
    	}
    }
    return $stref;	
}
# -----------------------------------------------------------------------------
sub emit_C_targets {
	( my $stref ) = @_;
    print "\nEMITTING C TARGETS\n";	
	for my $f ( keys %{ $stref->{'Subroutines'} } ) {
		if (exists $stref->{'BuildSources'}{'C'}{ $stref->{'Subroutines'}{$f}{'Source'} } ) {
            emit_refactored_subroutine( $f, $targetdir, $stref,1 );
		}
    }	
}
# -----------------------------------------------------------------------------
# In fact, "preconditioning" might be the better term
sub refactor_includes {
	( my $stref ) = @_;

	for my $f ( keys %{ $stref->{'Includes'} } ) {
		
		if (   $stref->{'Includes'}{$f}{'Type'} eq 'Common'
			or $stref->{'Includes'}{$f}{'Type'} eq 'Parameter' )
		{
			print "\nREFACTORING INCLUDE $f\n" if $V;
			refactor_include( $f, $stref );
		}
	}
	return $stref;
}

# -----------------------------------------------------------------------------
sub refactor_include {
	( my $f, my $stref ) = @_;
	
	if ($V) {
		print "\n\n";
		print "#" x 80, "\n";
		print "Refactoring $f\n";
		print "#" x 80, "\n";
	}
#	print Dumper( $stref->{'Includes'}{$f} );
	my @lines = @{ $stref->{'Includes'}{$f}{'Lines'} };
	my @info =
	  defined $stref->{'Includes'}{$f}{'Info'}
	  ? @{ $stref->{'Includes'}{$f}{'Info'} }
	  : ();
	my $annlines = [];
	for my $line (@lines) {
		my $tags = shift @info;
		push @{$annlines}, [ $line, $tags ];
	}

	my $rlines = [];
	for my $annline ( @{$annlines} ) {
		my $line      = $annline->[0] || '';
		my $tags_lref = $annline->[1];
		my %tags      = ( defined $tags_lref ) ? %{$tags_lref} : ();
		print '*** ' . join( ',', keys(%tags) ) . "\n" if $V;
		print '*** ' . $line . "\n" if $V;
		my $skip = 0;
		if ( exists $tags{'Common'} ) {
			$skip = 1;
		}

		if ( $skip == 0 ) {

			if ( not exists $tags{'Comments'} ) {
				print $line, "\n" if $V;
				my @split_lines = split_long_line($line);
				for my $sline (@split_lines) {
					push @{ $stref->{'Includes'}{$f}{'RefactoredCode'} },
					  $sline;
				}
			} else {
				push @{ $stref->{'Includes'}{$f}{'RefactoredCode'} }, $line;
			}
		}
	}

	return $stref;

}
# -----------------------------------------------------------------------------
sub refactor_function {
    ( my $f, my $stref ) = @_;
    if ($V) {
        print "\n\n";
        print "#" x 80, "\n";
        print "Refactoring $f\n";
        print "#" x 80, "\n";
    }

    print "REFACTORING FUNCTION $f\n" if $V;
    #print Dumper($stref->{'Subroutines'}{$f}{'Info'}) if $f eq 'llij_lc';
    my @lines = @{ $stref->{'Subroutines'}{$f}{'Lines'} };
    my @info =
      defined $stref->{'Functions'}{$f}{'Info'}
      ? @{ $stref->{'Functions'}{$f}{'Info'} }
      : ();
    my $annlines = [];
    for my $line (@lines) {
        my $tags = shift @info;
        push @{$annlines}, [ $line, $tags ];
    }

    my $rlines = $annlines;

    if ( not exists $stref->{'Functions'}{$f}{'RefactoredCode'}
        or $stref->{'Functions'}{$f}{'RefactoredCode'} == [] or exists $stref->{'BuildSources'}{'C'}{ $stref->{'Functions'}{$f}{'Source'} } )
    {       
        $stref = create_refactored_source( $stref, $f, $rlines );
    }

#   print STDERR "REFACTORED $f\n";
#    die Dumper($stref->{'Functions'}{$f}{'RefactoredCode'}) ;
    return $stref;

    return $stref;

} # END of refactor_function()
# -----------------------------------------------------------------------------
sub emit_refactored_include {
	( my $f, my $dir, my $stref ) = @_;
	my $srcref = $stref->{'Includes'}{$f}{'RefactoredCode'};
	if ( defined $srcref ) {
		print "INFO: emitting refactored code for include $f\n" if $V;
		my $mode = '>';
		open my $SRC, $mode, "$dir/$f" or die $!;
		for my $line ( @{$srcref} ) {
			print $SRC "$line\n";
			print "$line\n" if $V;
		}
		close $SRC;
	}
}

# -----------------------------------------------------------------------------
sub emit_refactored_subroutine {
	( my $f, my $dir, my $stref, my $overwrite ) = @_;
	my $srcref = $stref->{'Subroutines'}{$f}{'RefactoredCode'};
	my $s      = $stref->{'Subroutines'}{$f}{'Source'};
	print "INFO: emitting refactored code for $f in $s\n" if $V;
	my $mode = '>';
	if ( -e "$dir/$s" and not $overwrite) {
		$mode = '>>';
	} else {
		if ( not exists $stref->{'BuildSources'}{'C'}{$s}
		and not exists $stref->{'BuildSources'}{'F'}{$s} 
		) {
			$stref->{'BuildSources'}{'F'}{$s} = 1;
		}
	}
	open my $SRC, $mode, "$dir/$s" or die $!;
	if ( $mode eq '>>' ) {
		print $SRC "\nC *** SUBROUTINE $f ***\n";
	}
	for my $line ( @{$srcref} ) {
		print $SRC "$line\n";
		print "$line\n" if $V;
	}
	close $SRC;
}    # END of emit_refactored_subroutine()

# -----------------------------------------------------------------------------
sub emit_all {
	( my $stref ) = @_;

	if ( not -e $targetdir ) {
		mkdir $targetdir;
		my @incs = glob('include*');
		map { copy( $_, "$targetdir/$_" ) }
		  @incs;    # Perl::Critic wants a for-loop, drat it

	} elsif ( not -d $targetdir ) {
		die "$targetdir exists but is not a directory!\n";
	} else {
		my @oldsrcs = glob("$targetdir/*.f");
		map { unlink $_ } @oldsrcs;

		# Check if includes have changed
		my @incs = glob('include*');
		for my $inc (@incs) {
			open( my $OLD, $inc );
			binmode($OLD);
			open( my $NEW, $inc );
			binmode($NEW);
			if ( Digest::MD5->new->addfile($OLD)->hexdigest ne
				Digest::MD5->new->addfile($NEW)->hexdigest )
			{
				copy( $inc, "$targetdir/$inc" );
			}
			close $OLD;
			close $NEW;
		}
	}
	for my $f ( keys %{ $stref->{'Subroutines'} } ) {
		emit_refactored_subroutine( $f, $targetdir, $stref,0 );
	}
	for my $f ( keys %{ $stref->{'Includes'} } ) {
		emit_refactored_include( $f, $targetdir, $stref );
	}

	# copy functions
	my %funcsrcs = ();
	for my $func ( keys %{ $stref->{'Functions'} } ) {
		if ( not exists $funcsrcs{ $stref->{'Functions'}{$func}{'Source'} } ) {
			$funcsrcs{ $stref->{'Functions'}{$func}{'Source'} } = 1;
			$stref->{'BuildSources'}{'F'}
			  { $stref->{'Functions'}{$func}{'Source'} } = 1;
		} else {
			$funcsrcs{ $stref->{'Functions'}{$func}{'Source'} }++;
		}
	}
	for my $funcsrc ( keys %funcsrcs ) {
		copy( $funcsrc, "$targetdir/$funcsrc" );
	}

	# NOOP source
	if ($noop) {
		copy( '../OpenCL-port/tools/noop.c', "$targetdir/noop.c" );
#		$stref->{'BuildSources'}{'C'}{'noop.c'} = 1;
	}

}    # END of emit_all()

# -----------------------------------------------------------------------------
sub translate_to_C {
	( my $stref ) = @_;

# At first, all we do is get the call tree and translate all sources to C with F2C_ACC
# The next step is to fix the bugs in F2C_ACC via post-processing (later maybe actually debug F2C_ACC)
	chdir $targetdir;
	print "\n", "=" x 80, "\n" if $V;
	print "TRANSLATING TO C\n\n" if $V;
	print `pwd`                  if $V;
	foreach my $csrc ( keys %{ $stref->{'BuildSources'}{'C'} } ) {
		if (-e $csrc) {		
		my $cmd = "../OpenCL-port/tools/f2c $csrc";
		print $cmd, "\n" if $V;
		system($cmd);
		} else {
			print "WARNING: $csrc does not exist\n";
		}
	}

# A minor problem is that we need to translate all includes contained in the tree as well
	foreach my $inc ( keys %{ $stref->{'BuildSources'}{'H'} } ) {
		my $cmd = "f2c $inc -H";
		print $cmd, "\n" if $V;
		system($cmd);
	}
	my $i=0;
	print "\nPOSTPROCESSING C CODE\n\n";
	foreach my $csrc ( keys %{ $stref->{'BuildSources'}{'C'} } ) {
		$csrc=~s/\.f/\.c/;
	   postprocess_C($stref,$csrc,$i);
#	   die if $csrc=~/hanna\./;
	   $i++;
	}
	 # Test the generated code	
	foreach my $ii ( 0 .. $i-1 ) {	  
	   my $cmd='gcc -Wall -c -I$GPU_HOME/include tmp'.$ii.'.c';
	   print $cmd,"\n";
       system $cmd;       
	}	
	
}    # END of translate_to_C()
# -----------------------------------------------------------------------------
# We need a separate pass I think to get the C function signatures
# Then we need to change all array accesses used as arguments to pointers:
# a[i] => a+i
# Every arg in C must be a pointer (FORTRAN uses pass-by-ref)
# So any arg in a call that is not a pointer is wrong
# We can assume that if the arg is say v and v__G exists, then
# it should be v__G
# vdepo[FTNREF1D(i,1)] => vdepo+FTNREF1D(i,1)
#
# Next, we need to figure out which arguments can remain non-pointer scalars
# That means:
# - parse the C function signature
# - find corresponding arguments in the FORTRAN signature
# - if they are Input Scalar, don't make them pointers
# - in that case, comment out the corresponding "int v = *v__G;" line

sub postprocess_C {
    (my $stref, my $csrc,my $i) = @_;
    print "POSTPROC $csrc\n";
    my $sub='';
    my $argstr='';
    my %params=();
    my %vars=();
    my %argvars=();
    my %labels=();
    my %input_scalars=();
    # We need to check if this particular label is a Break
    # So we need a list of all labels per subroutine.
    my $isBreak = sub  {
        (my $label)=@_;
        return ( $labels{$label} eq 'BreakTarget' || $labels{$label} eq 'NoopBreakTarget');    
    };
    
    my $isNoop =sub {
    (my $label)=@_;
        return ( $labels{$label} eq 'NoopBreakTarget');
    };
        
#    my %functions = %{ $stref->{'Functions'} };
    
    open my $CSRC,'<',$csrc;
    open my $PPCSRC,'>','tmp'.$i.'.c'; # FIXME
    my $skip=0;
   
    while (my $line =<$CSRC>) {    	
    	my $decl='';
        $line=~/^\s*void\s+(\w+)_\s+\(\s*(.*?)\s*\)\s+\{/ && do {
            $sub= $1;
            $argstr = $2;
            
            my @args=split(/\s*\,\s*/,$argstr);
            
            %argvars = map {
            	s/^\w+\s+\*?//;
            	s/^F2C-ACC.*?\.\s+\*?//;
            	$_ => 1;            	
            } @args;                                    
            
            for my $i ( keys %{ $stref->{'Subroutines'}{$sub}{'Includes'} } ) {
                if ( $stref->{'Includes'}{$i}{'Type'} eq 'Parameter' ) {
                   %params = (%params,%{ $stref->{'Includes'}{$i}{'Parameters'} });
                 }
            }
            %vars=%{ $stref->{'Subroutines'}{$sub}{'Vars'} };           
            for my $arg (@args) {            	
                $arg=~s/^\w+\s+\*//;
                $arg=~s/^F2C-ACC.*?\.\s+\*?//;
                    my $var=$arg;      
                    $var=~s/__G//;   
                    if (exists $vars{$var} and $vars{$var}{'Type'}) {         
                    my $ftype=$vars{$var}{'Type'};
                    my $ctype=toCType($ftype);
                    my $iodir=$stref->{'Subroutines'}{$sub}{'RefactoredArgs'}{$var};
                    my $kind=$vars{$var}{'Kind'};
#                    print "ARG $var\n" if ( $iodir eq 'In' and $kind eq 'Scalar');
                    if ( $iodir eq 'In' and $kind eq 'Scalar') {
                    	$arg="$ctype $var";
                    } else {
                    	$arg="$ctype *$arg";
                    }
                    } else {
                        die "No entry for $var in $sub\n".Dumper(%vars);
                    }                    
            }
            $line="\t void ${sub}_( ".join(',',@args)." ){\n";             
            
             
            %labels=();
            if (exists $stref->{'Subroutines'}{$sub}{'Gotos'}) {
            %labels=%{ $stref->{'Subroutines'}{$sub}{'Gotos'} };
            }
            $decl=$line;
                                        $decl=~s/\{.*$/;/;
                my $hfile="$sub.h";
               open my $INC,'>',$hfile;
               my $shield=$hfile;
               $shield=~s/\./_/;
               $shield='_'.uc($shield).'_';
               print $INC '#ifndef '.$shield."\n";
               print $INC '#define '.$shield."\n";
               print $INC $decl,"\n";
               print $INC '#endif //'.$shield."\n";
               close $INC;          
                        
            $skip=1;
        };
        
        $line=~/(\w+)=\*(\w+)__G;/ && do {
        	if ($1 eq $2){
        	   my $var=$1;        	   
               my $iodir=$stref->{'Subroutines'}{$sub}{'RefactoredArgs'}{$var};
               my $kind=$vars{$var}{'Kind'};
               if ( $iodir eq 'In' and $kind eq 'Scalar') {
                	$line=~s|^|\/\/|;
                	$input_scalars{$var.'__G'}=$var
               }        	   
        	}
        };
        $line=~/F2C\-ACC\:\ Type\ not\ recognized\./ && do {
            my @chunks=split(/\,/,$line);
            for my $chunk (@chunks) {
                $chunk =~/F2C\-ACC\:\ Type\ not\ recognized\.\ \*?(\w+)/ && do {
                    my $var=$1;      
                    $var=~s/__G//;   
                    if (exists $vars{$var} and $vars{$var}{'Type'}) {         
                    my $ftype=$vars{$var}{'Type'};
                    my $vtype=toCType($ftype);
                    $chunk=~s/F2C\-ACC\:\ Type\ not\ recognized\./$vtype/;
                    } else {
                    	die "No entry for $var in $sub\n".Dumper(%vars);
                    }
                };        
            }
            $line=join(',',@chunks);            
        };
#        if ($decl ne '') {
#        	$decl=$line;
#                $decl=~s/\{.*$/;/;
#                my $hfile="$sub.h";
#               open my $INC,'>',$hfile;
#               my $shield=$hfile;
#               $shield=~s/\./_/;
#               $shield='_'.uc($shield).'_';
#               print $INC '#ifndef '.$shield."\n";
#               print $INC '#define '.$shield."\n";
#               print $INC $decl,"\n";
#               print $INC '#endif //'.$shield."\n";
#               close $INC;        	
#        }
        $line=~/F2C\-ACC\:\ xUnOp\ not\ supported\./ && do { # FIXME: we assume the unitary operation is .not.
            my @chunks=split(/\,/,$line);
            for my $chunk (@chunks) {
                $chunk =~s/F2C\-ACC\:\ xUnOp\ not\ supported\./\!/;
            }
            $line=join(',',@chunks);            
        	
        };
       next if $line=~/^\s*extern\s+void\s+noop/;
       if ($skip==0) {
        if ($line=~/^\s*extern\s+\w+\s+(\w+)_\(/) {
           my $inc=$1;
           my $hfile=$inc.'.h';
           
           if (not -e $hfile) {
               $line=~s/^\s*extern\s+//; 
#               open my $INC,'>',$hfile;
#               my $shield=$hfile;
#               $shield=~s/\./_/;
#               $shield='_'.uc($shield).'_';
#               print $INC '#ifndef '.$shield."\n";
#               print $INC '#define '.$shield."\n";
#               print $INC $line;
#               print $INC '#endif //'.$shield."\n";
#               close $INC;
           }
           print $PPCSRC '#include "'.$hfile.'"'."\n";
           next;        
       }

            
        $line=~/^\s+extern\s+\w+\s+\w+[;,]/ && do {        
            $line=~s|^|\/\/|;
        }; # because parameters are macros, not variables
     
    #*  float float and similar need to be removed
        $line=~/float\s+(float|sngl|sqrt)/ && do {
            $line=~s|^|\/\/|;
        };
        
        $line=~/int\s+(int|mod)/ && do {
            $line=~s|^|\/\/|;
        };
        
        $line=~/(short|int)\s+(int2|short)/ && do {
            $line=~s|^|\/\/|;
        };
        
        $line=~/(long|int)\s+(int8|long)/ && do {
            $line=~s|^|\/\/|;
        };        
        if ( $line=~/^\s*(?:\w+\s+)?\w+\s+(\w+);/) { # FIXME: only works for types consisting of single strings, e.g. double precision will NOT match!
        	my $mf=$1;
        	if (exists  $stref->{'Subroutines'}{$sub}{'CalledFunctions'}{$mf}) {        	        
        	 $line=~s|^|\/\/|;
        	}
        }
        $line=~s/int\(/(int)(/g; # int is a FORTRAN primitive converting float to int
        $line=~s/(int2|short)\(/(int)(/g; # int is a FORTRAN primitive converting float to int
        $line=~s/(int8|long)\(/(long)(/g; # int is a FORTRAN primitive converting float to int
        $line=~s/float\(/(float)(/g; # float is a FORTRAN primitive converting int to float
        $line=~s/(dfloat|dble)\(/(double)(/g; # dble is a FORTRAN primitive converting int to float
        $line=~s/sngl\(/(/g; # sngl is a FORTRAN primitive converting double to float
        
        $line=~/goto\ C__(\d+):/ && do {
            my $label=$1;
            if ($isBreak->($label)) {
                $_=$line;
                eval("s/goto\\ C__$label:/break/");
                $line=$_;
            } else {
                $line=~s/C__(\d+)\:/C__$1/;
            }
        };
    #    s/goto\ C__37:/break/; # must have a list of all gotos that are breaks
        $line=~/^\s+C__(\d+)/ && do {
            my $label=$1;
            if ($isNoop->($label)) {
                $line=~s|^|\/\/|;
            }
        };
        # Subroutine call
        $line!~/\#define/ && $line=~s/\s([\+\-\*\/\%])\s/$1/g; # super ad-hoc!
        $line=~/(^|^.*?\{\s)\s*(\w+)_\(\s([\+\*\,\w\(\)\[\]]+)\s\);/ && do {
        	
        	# We need to replace the arguments with the correct ones.
        	my $maybe_if=$1;
        	my $calledsub=$2;
        	my $argstr=$3; 
        	my @args=split(/\s*\,\s*/,$argstr); # FIXME: this will split things like v1,indzindicator[FTNREF1D(i,1)],v3       
        	my $ii=0;
        	my $called_sub_args=$stref->{'Subroutines'}{$calledsub}{'RefactoredArgList'};
        	my @nargs=();  	
        	for my $jj (1..scalar @{$called_sub_args}) {
        		my $arg=shift @args;
        		my $called_sub_arg=$called_sub_args->[$ii]; $ii++;
        		my $is_input_scalar= ( $stref->{'Subroutines'}{$calledsub}{'Vars'}{$called_sub_arg}{'Kind'} eq 'Scalar' ) &&( $stref->{'Subroutines'}{$calledsub}{'RefactoredArgs'}{$called_sub_arg} eq 'In')?1:0;
#        		print "CALLED SUB $calledsub ARG: $called_sub_arg\n";
#        		my $targ=$arg;
        		if ($arg=~/^\((\w+)\)$/) {
        			$arg=$1;
        		}
#        		$targ=~s/[\(\)]//g;
                if ($arg=~/(\w+)\[/){
                	my $var=$1;
                	# What is the type of $var?
                	my %calledsubvars=%{ $stref->{'Subroutines'}{$calledsub}{'Vars'} };
                    my $ftype=$calledsubvars{$called_sub_arg}{'Type'};
                    my $tftype=$vars{$var}{'Type'};
                    if ($ftype ne $tftype) {
                    	print "WARNING: $tftype $var ($sub) <> $ftype $called_sub_arg ($calledsub)\n";
                    }
                    my $ctype=toCType($ftype);
                	  my $cptype=$ctype.'*';
        		  
        		  while ($arg!~/\]/){
        			 my $targ= shift @args;
#        			 print "TARG: $targ\t";
        			 $arg.=','. $targ;
#        			 print $arg,"\n";	
        		  }
        		  
        		  if (not $is_input_scalar) {
        		  $arg=~s/\[/+/g;
        		$arg=~s/\]//g;
        		$arg="($cptype)($arg)";
        		  }
#        		die $arg;
                }
        		
#        		print $arg,"\n";
        		if (exists $argvars{$arg.'__G'}) { 
        			# this is an argument variable
        			# if the called function argument type is Input Scalar
        			# and the argument variable is in %input_scalars
        			# then don't add __G        			
        			# Still not good: the arg for the called sub must be positional! So we must get the signature and count the position ... 
        			# which means we need to parse the source first.
        			
#        			print " SUBCALL $calledsub: $called_sub_arg: $is_input_scalar:" . $stref->{'Subroutines'}{$calledsub}{'Vars'}{$called_sub_arg}{'Kind'} .','. $stref->{'Subroutines'}{$calledsub}{'RefactoredArgs'}{$called_sub_arg}."\n";
        			
        			if (not exists $input_scalars{$arg.'__G'}) {
        				# means v__G in enclosing sub signature is a pointer
        				if (not $is_input_scalar) {
        					# means the arg of the called sub is a pointer 
        			         $arg.='__G';
        				} else {
        					# means the arg of the called sub is a scalar
#        					$arg;
        				}
        			} else {
                        # means v in enclosing sub signature is a scalar
	                    if (not $is_input_scalar) {
	                     $arg='&'.$arg;
	                    }                                                        				
        			}
        		} elsif (exists $vars{$arg} and $vars{$arg}{'Kind'} ne 'Array') {
        			# means $arg is a Scalar
        			if (not $is_input_scalar) {
        			 $arg='&'.$arg;
        			}
        		}
        		push @nargs,$arg;
        	}
        	my $nargstr=join(',',@nargs);
        	chomp $line;
        	$line=~/^\s+if/ && do {
        		$line=~s/^.*?\{//;
        	};
        	$line=~s/\(.*//;
        	$line.='('.$nargstr.');'."\n";
        	my $close_if=($maybe_if=~/if\s*\(/)?'}':'';
        	$line=$maybe_if.$line.$close_if;
#        	die $line if $calledsub=~/initialize/;
        };
        
       } else {
       	    $skip=0;
       }
       # VERY AD-HOC: get rid of write() statements
       $line=~/^\s*write\(/ && do {
       	$line=~s|^|\/\/|;
       };
       # fix % on float
       # This is a pain: need to get the types of the operands and figure out the cases:
       # int float, float int, float float
       # FIXME: we assume float, float
       $line=~s/\s+([\w\(\)]+)\s*\%\s*([\w\(\)]+)/ mod($1,$2)/;
        print $PPCSRC $line;
    }
    close $CSRC;
    close $PPCSRC;  
} # END of postprocess_C()
# -----------------------------------------------------------------------------
sub toCType { (my $ftype)=@_;
    my %corr= (
            'logical' => 'int',
            'integer' => 'int',
            'real' => 'float',
            'double precision' => 'double',
            'doubleprecision' => 'double',
            'character' => 'char'
            );
    if (exists($corr{$ftype})) {
        return $corr{$ftype};
    } else {
        warn "NO TYPE for $ftype\n";
        return 'NOTYPE';
    }
} # END of toCType()
# -----------------------------------------------------------------------------
sub create_build_script {
	( my $stref ) = @_;

	# First attempt, Fortran only
	my @gfs = (
		'/opt/local/bin/gfortran-mp-4.6',
		'/usr/local/bin/gfortran-4.6', '/usr/bin/gfortran'
	);
	my $gfortran = 'gfortran';
	for my $mgf (@gfs) {
		if ( -e $mgf ) {
			$gfortran = $mgf;
			last;
		}
	}
	my @fsourcelst = sort keys %{ $stref->{'BuildSources'}{'F'} };
	my $fsources = join( ',', map { "'" . $_ . "'" } @fsourcelst );

	my $csources = '';
	if ( exists $stref->{'BuildSources'}{'C'} ) {
		my @csourcelst = sort keys %{ $stref->{'BuildSources'}{'C'} };
		$csources = join( ',', map { s/\.f$/.c/; "'" . $_ . "'" } @csourcelst );
	}
	my $date  = localtime;
	my $scons = <<ENDSCONS;
# Generated build script for refactored FLEXPART source code
# $date

csources =[$csources]

fsources = [$fsources]

envC=Environment(CC='gcc',CPPPATH=['/Users/wim/SoC_Research/F2C-ACC/include/']); # FIXME: use ENV
if csources:
    envC.Library('wrfc',csources)

FFLAGS  = ['-O3', '-m64', '-fconvert=little-endian', '-frecord-marker=4']
envF=Environment(FORTRAN='$gfortran',FORTRANFLAGS=FFLAGS,FORTRANPATH=['.','/opt/local/include','/usr/local/include'])
if csources:
    envF.Program('flexpart_wrf',fsources,LIBS=['netcdff','wrfc','m'],LIBPATH=['.','/opt/local/lib','/usr/local/lib'])	
else:
    envF.Program('flexpart_wrf',fsources,LIBS=['netcdff','m'],LIBPATH=['.','/opt/local/lib','/usr/local/lib'])
ENDSCONS
	open my $SC, '>', "$targetdir/SConstruct.flx_wrf";
	print $SC $scons;
	print $scons if $V;
	close $SC;

}    # END of create_build_script()

# -----------------------------------------------------------------------------
sub build_flexpart {
	system('scons -f SConstruct.flx_wrf');
}

# -----------------------------------------------------------------------------

sub parse_subroutine_calls {
	( my $f, my $stref ) = @_;
	print "PARSING SUBROUTINE CALLS in $f\n" if $V;
	my $src = $stref->{'Subroutines'}{$f}{'Source'};
	if ( $translate == 2 || ( $call_tree_only && ( $gen_sub || $main_tree ) ) )
	{
		if ( $translate != 2 ) {
			my $nspaces =
			  64 - $stref->{'Indents'} - length($f);    # -length($src) -2;
			print ' ' x $stref->{'Indents'}, $f, ' ' x $nspaces, $src, "\n";
		} # else {
			if ($translate==2) {
			if ( not exists $stref->{'BuildSources'}{'C'}{$src} ) {
				print "ADDING $src to C BuildSources\n" if $V;
				$stref->{'BuildSources'}{'C'}{$src} = 1;
				$stref->{'Subroutines'}{$f}{'Status'} = 4;
			}
			for my $inc ( keys %{ $stref->{'Subroutines'}{$f}{'Includes'} } ) {
				if ( not exists $stref->{'BuildSources'}{'H'}{$inc} ) {
					print "ADDING $inc to C Header BuildSources\n" if $V;
					$stref->{'BuildSources'}{'H'}{$inc} = 1;
				}
			}
		}
	}
	my $srcref = $stref->{'Subroutines'}{$f}{'Lines'};
	if ( defined $srcref ) {
		my %child_include_count = ();
		my %called_subs         = ();
		for my $index ( 0 .. scalar( @{$srcref} ) - 1 ) {
			my $line = $srcref->[$index];
			next if $line =~ /^C\s+/;
			if ( $line =~ /call\s(\w+)\((.*)\)/ || $line =~ /call\s(\w+)\s*$/ )
			{
				my $name = $1;
				my $argstr = $2 || '';
				if ( $argstr =~ /^\s*$/ ) {
					$argstr = '';
				}
				$called_subs{$name} = $name;
				$stref->{'Subroutines'}{$f}{'Info'}
				  ->[$index]{'SubroutineCall'}{'Args'} = $argstr;                
				my $tvarlst = $argstr;
				if ( $tvarlst =~ /\(((?:[^\(\),]*?,)+[^\(]*?)\)/ ) {
					while ( $tvarlst =~ /\(((?:[^\(\),]*?,)+[^\(]*?)\)/ ) {
						my $chunk  = $1;
						my $chunkr = $chunk;
						$chunkr =~ s/,/;/g;
						my $pos = index( $tvarlst, $chunk );
						substr( $tvarlst, $pos, length($chunk), $chunkr );
					}
				}

				my @tvars   = split( /\s*\,\s*/, $tvarlst );
				my $p       = '';
				my @argvars = ();
				for my $var (@tvars) {
					$var =~ s/^\s+//;
					$var =~ s/\s+$//;
					$var =~ s/;/,/g;
					push @argvars, $var;
				}

				$stref->{'Subroutines'}{$f}{'Info'}
				  ->[$index]{'SubroutineCall'}{'Args'} = \@argvars;
				$stref->{'Subroutines'}{$f}{'Info'}
				  ->[$index]{'SubroutineCall'}{'Name'} = $name;
				if ( $stref->{'Subroutines'}{$name}{'Status'} < 2 or $gen_sub )
				{
					print "\tCALL $name\n" if $V;

					# Propagating down includes
					for my $inc (
						keys %{ $stref->{'Subroutines'}{$f}{'Includes'} } )
					{
						if (
							not
							exists $stref->{'Subroutines'}{$name}{'Includes'}
							{$inc} )
						{
							print "Propagating DOWN $inc from $f to $name\n"
							  if $V;
							$stref->{'Subroutines'}{$name}{'Includes'}{$inc} =
							  -3;
						} else {
							print
"NO NEED TO propagate DOWN $inc from $f to $name\n"
							  if $V;
						}
					}

					#					print "Processing SUBROUTINE $name\n" if $V;
					if ( $call_tree_only && ( $gen_sub || $main_tree ) ) {
						$stref->{'Indents'} += 4;
					}
					$stref = parse_fortran_src( $name, $stref );
					if ( $call_tree_only && ( $gen_sub || $main_tree ) ) {
						$stref->{'Indents'} -= 4;
					}

					#					$stref->{'Subroutines'}{$name}{'Status'}=2;
					print "Postprocessing INCLUDES for $name\n" if $V;
					for my $inc (
						keys %{ $stref->{'Subroutines'}{$name}{'Includes'} } )
					{
						if ( $stref->{'Includes'}{$inc}{'Type'} eq 'Common' ) {
							$child_include_count{$f}{$inc}++;

#                    	   print $child_include_count{$f}{$inc};
#                    	   print '<>',join(',',keys %{ $stref->{'Subroutines'}{$f}{'Includes'} })," in $f\n";
						}
					}

				}
			}
		}
		print "ANALYZING called subs in $f\n" if $V;
		my %globs         = ();
		my @child_is_root = ();
		for my $inc ( keys %{ $child_include_count{$f} } ) {
			if ( not exists $stref->{'Subroutines'}{$f}{'Includes'}{$inc} ) {
				if ( $child_include_count{$f}{$inc} == 1 ) {
					push @child_is_root, $inc;
				} elsif ( $child_include_count{$f}{$inc} > 1 ) {
					print
"INFO: $inc occurs in more than one child, not present in parent => make parent $f root\n"
					  if $V;
					$stref->{'Includes'}{$inc}{'Root'} = $f;
					$stref->{'Subroutines'}{$f}{'Includes'}{$inc} = -1;
				}
			}
		}
        $stref->{'Subroutines'}{$f}{'CalledSubs'}=\%called_subs;
		for my $name ( keys %called_subs ) {
			my $root_inc = '';
			for my $inc (@child_is_root) {
				if ( exists $stref->{'Subroutines'}{$name}{'Includes'}{$inc} ) {
					$stref->{'Includes'}{$inc}{'Root'} = $name;
					$root_inc = $inc;
					print "INFO: $name is root for $inc\n" if $V;
				}
			}
			for my $inc ( keys %{ $stref->{'Subroutines'}{$name}{'Globals'} } )
			{
				next if $inc eq $root_inc;
				$globs{$inc} =
				  union( $globs{$inc},
					$stref->{'Subroutines'}{$name}{'Globals'}{$inc} );
			}
		}
		for my $inc ( keys %{ $stref->{'Subroutines'}{$f}{'Includes'} } ) {
			print "INFO: $inc in $f\n" if $V;
			next unless $stref->{'Includes'}{$inc}{'Type'} eq 'Common';
			if ( exists $stref->{'Subroutines'}{$f}{'Globals'}{$inc} ) {
				$stref->{'Subroutines'}{$f}{'Globals'}{$inc} =
				  union( $stref->{'Subroutines'}{$f}{'Globals'}{$inc},
					$globs{$inc} );
			} else {
				$stref->{'Subroutines'}{$f}{'Globals'}{$inc} = $globs{$inc};
			}
		}
	}
	return $stref;
}    # END of parse_subroutine_calls()

# -----------------------------------------------------------------------------
# Identify which globals from the includes are used in the subroutine
sub identify_globals_used_in_subroutine {
	( my $f, my $stref ) = @_;
	my $srcref = $stref->{'Subroutines'}{$f}{'Lines'};
	if ( defined $srcref ) {
		my %commons = ();
		print "COMMONS ANALYSIS in $f\n" if $V;
		if ( not exists $stref->{'Subroutines'}{$f}{'Commons'} ) {
			for my $inc ( keys %{ $stref->{'Subroutines'}{$f}{'Includes'} } ) {
				if ( $stref->{'Includes'}{$inc}{'Type'} eq 'Common' ) {
					print "COMMONS from $inc in $f? " if $V;
					$commons{$inc} = $stref->{'Includes'}{$inc}{'Commons'};
				}
			}
			$stref->{'Subroutines'}{$f}{'Commons'}    = \%commons;
			$stref->{'Subroutines'}{$f}{'HasCommons'} = 1;
		} else {
			print "already done\n" if $V;
			%commons = %{ $stref->{'Subroutines'}{$f}{'Commons'} };
		}
		my $first = 1;
		for my $inc ( keys %commons ) {
			print "\nGLOBAL VAR ANALYSIS for $inc in $f\n" if $V;
			my @inherited_globs =
			  ( defined $stref->{'Subroutines'}{$f}{'Globals'}{$inc} )
			  ? @{ $stref->{'Subroutines'}{$f}{'Globals'}{$inc} }
			  : ();
			my @globs = ();
			my %tvars = %{ $commons{$inc} };
			for my $index ( 0 .. scalar( @{$srcref} ) - 1 ) {
				my $line = $srcref->[$index];
				if ( $line =~ /^C\s+/ ) {
					next;
				}

				# We shouldn't look for globals in the declarations, silly!
				if ( $line =~
/(logical|integer|real|double\s+precision|character|character\*?(?:\d+|\(\*\)))\s+(.+)\s*$/
				  )
				{
					next;
				}

				# FIXME: Not sure why this is done here?
				if ( $first && $line =~ /^\s+subroutine\s+(\w+)\((.*)\)/ ) {
					my $name   = $1;
					my $argstr = $2;
					$argstr =~ s/^\s+//;
					$argstr =~ s/\s+$//;
					my @args = split( /\s*,\s*/, $argstr );

#					print "ARGS FOR $f ($inc): <",join(',',@args),">\n" if $V and $f=~/particles_/;
#	                print STDERR "ARGS for $f ($inc): <",join(',',@args),">\n" if $V and $f=~/particles_/;
					$stref->{'Subroutines'}{$f}{'Info'}
					  ->[$index]{'Signature'}{'Args'} = \@args;
					$stref->{'Subroutines'}{$f}{'Info'}
					  ->[$index]{'Signature'}{'Name'} = $name;
					$stref->{'Subroutines'}{$f}{'Args'} = \@args;
				}
				if ( $first && $line =~ /^\s+program\s+(\w+)\s*$/ ) {
					my $name = $1;
					$stref->{'Subroutines'}{$f}{'Info'}
					  ->[$index]{'Signature'}{'Args'} = [];
					$stref->{'Subroutines'}{$f}{'Info'}
					  ->[$index]{'Signature'}{'Name'} = $name;
				}

				#	            # Need to skip literal strings and formats!
				#	            my $tline=$line;
				#	            while ($tline=~/\'.+?\'/) {
				#	                $tline=~s/\'.*?\'//;
				#	            }
				my @chunks = split( /\W+/, $line );
				for my $mvar (@chunks) {
#				next if $mvar =~/\b(?:if|then|do|goto|integer|real|call|\d+)\b/; # is slower!
# if a var on a line is declared locally, it is obviously not a global!
					if ( exists $tvars{$mvar}
						and not $stref->{'Subroutines'}{$f}{'Vars'}{$mvar} )
					{
						print "FOUND global $mvar in $line\n" if $V;
						push @globs, $mvar;
						delete $tvars{$mvar};
					}
				}
			}    # for each line
			@globs = @{ union( \@globs, \@inherited_globs ) };
			if ($V) {
				print "\nALL GLOBAL VARS from $inc in subroutine $f:\n\n";
				for my $var (@globs) {
					print "$var\n";
				}
				print "\n";
			}
			$stref->{'Subroutines'}{$f}{'Globals'}{$inc} = \@globs;
			$first = 0;
		}
	}
	return $stref;
}    # END of identify_globals_used_in_subroutine()

# -----------------------------------------------------------------------------
# To determine if a subroutine argument is I, O or IO:
# if it appears only on the LHS of an '=' => O
# if does not appear on the LHS of an '=' => I
# otherwise => IO
# So start by setting them all to 'I'
# so, look for '=' and split in LHS/RHS
 
 
sub determine_argument_io_direction {
	( my $f, my $stref ) = @_;
	my $srcref = $stref->{'Subroutines'}{$f}{'Lines'};
	print "DETERMINE IO DIR FOR SUB $f\n" if $V;
    my @exglobs = ();
    for my $inc ( keys %{ $stref->{'Subroutines'}{$f}{'Globals'} } ) {
    	if (defined $stref->{'Subroutines'}{$f}{'Globals'}{$inc}) {
            @exglobs = (
                @exglobs, @{ $stref->{'Subroutines'}{$f}{'Globals'}{$inc} }
            );
    	}
    }
    my $args_ref = union( $stref->{'Subroutines'}{$f}{'Args'}, \@exglobs );
    
    my %args = map { $_ => 'Unknown' } @{ $args_ref };
    
    # Now, we need to get the values for args used in called subs
    # So we need a list of called subs.
    for my $cs (keys %{ $stref->{'Subroutines'}{$f}{'CalledSubs'} }) {
    	print "CALLED SUB: $cs\n" if $V;
    	for my $cs_arg (keys %{ $stref->{'Subroutines'}{$cs}{'RefactoredArgs'} }) {
    		print "\tCSARG: $cs_arg\n" if $V;
    		if (exists $args{$cs_arg} and $stref->{'Subroutines'}{$cs}{'RefactoredArgs'}{$cs_arg} ne 'Unknown' ) {
    			print "\t\tINHERIT ARG IO for $cs_arg from $cs\n" if $V; 
    			$args{$cs_arg}= $stref->{'Subroutines'}{$cs}{'RefactoredArgs'}{$cs_arg};
    		}
    	}    	
    }
    # Then for each of these, we go through the args.
    # If an arg has a non-'U' value, we overwrite it.	
	
	if ( defined $srcref ) {
		for my $index ( 0 .. scalar( @{$srcref} ) - 1 ) {
			my $line = $srcref->[$index];
			if ( $line =~ /^C\s+/ ) {
				next;
			}
                # Skip the declarations
                if ( $line =~
/(logical|integer|real|double\s+precision|character|character\*?(?:\d+|\(\*\)))\s+(.+)\s*$/
                  )
                {
                    next;
                }
			
			if ( $line =~ /\s+(\w+)(?:\([^=]*\))?\s*=\s*(.+?)\s*$/ and $line!~/^\s*do\s+.+\s*=/) { # Assignment, but not a loop. This is weak! 
			
				 my $var=$1;
				 my $rhs=$2;
				 if (exists $args{$var} ) {
                    
				    if( $args{$var} eq 'Unknown') {
				    	print "LINE: $line\n" if $V;
					   print "ARG $var: 'Out'\n" if $V;
					   $args{$var}='Out';
				    } elsif ($args{$var} eq 'In') {
				    	print "LINE: $line\n" if $V;
                        print "ARG $var: 'InOut'\n" if $V;
                        $args{$var}='InOut';
				    }
				 }
				 if ($line=~/^\s*if/) {				 	
				    (my $cond,my $rest) = split(/\s+(\w+)(?:\([^=]*\))?\s*=\s*/,$line);				    
#				    print "COND: $cond\n";
#				    print "REST: $rest\n";
                    find_vars($cond,\%args, \&set_io_dir);
				 } 
#				 print "RHS: $rhs\n";
                find_vars($rhs,\%args, \&set_io_dir);	 

			} else { # not an assignment, do as before
				print "LINE: $line\n" if $V;
				find_vars($line,\%args, \&set_io_dir);			 
			}
		}
	}
	$stref->{'Subroutines'}{$f}{'RefactoredArgs'}=\%args;
#	die Dumper($stref->{'Subroutines'}{$f}{'RefactoredArgs'}) if $f=~/timemanager/;
	return $stref;
} # determine_argument_io_direction()
# -----------------------------------------------------------------------------
sub set_io_dir {
                        (my $mvar, my $args_ref)=@_;
                            if( $args_ref->{$mvar} eq 'Out') {                      
                                print "FOUND InOut ARG $mvar\n" if $V;
                                $args_ref->{$mvar}='InOut';
                            } elsif ($args_ref->{$mvar} eq 'Unknown') {
                                print "FOUND In ARG $mvar\n" if $V;
                                $args_ref->{$mvar}='In';                           
                            }              
                            return $args_ref;                       
	
}
# -----------------------------------------------------------------------------
sub find_vars {
	(my $line, my $args_ref, my $subref)=@_;
	my %args=%{$args_ref};
                my @chunks = split( /\W+/, $line );
                for my $mvar (@chunks) {
                    if ( exists $args{$mvar} ) {
                    	$args_ref=$subref->($mvar,$args_ref)
                    }
                }
    return $args_ref;                
} # END of find_vars()
# -----------------------------------------------------------------------------
sub detect_blocks {
	( my $s, my $stref ) = @_;
	print "CHECKING BLOCKS in $s\n" if $V;
	$stref->{'Subroutines'}{$s}{'HasBlocks'} = 0;
	my $srcref = $stref->{'Subroutines'}{$s}{'Lines'};
	for my $line ( @{$srcref} ) {
		if ( $line =~ /^C\s/i ) {
			if ( $line =~ /^C\s+BEGIN\sSUBROUTINE\s(\w+)/ ) {
				$stref->{'Subroutines'}{$s}{'HasBlocks'} = 1;
				print "SUB $s HAS BLOCK: $1\n" if $V;
				last;
			}
		}
	}
	return $stref;
}    # END of detect_blocks()

# -----------------------------------------------------------------------------
sub create_subroutine_source_from_block {
	( my $f, my $p, my $stref ) = @_;
	print "CREATING SOURCE for $f\n" if $V;

	#        print STDERR "KEYS in $p\n";
	#        for my $k (sort keys %{$stref->{'Subroutines'}{$p}}) {
	#        	print STDERR "$k\n";
	#        };

	my @lines = @{ $stref->{'Subroutines'}{$p}{'Blocks'}{$f}{'Lines'} };
	my @info  = @{ $stref->{'Subroutines'}{$p}{'Blocks'}{$f}{'Info'} };

	#	    my $annlines = [];
	my $index = 0;

	my $rlines = [];
	push @{$rlines}, $stref->{'Subroutines'}{$p}{'Blocks'}{$f}{'Sig'};
	$stref->{'Subroutines'}{$f}{'Info'}->[$index]{'Signature'}{'Name'} = $f;
	$stref->{'Subroutines'}{$f}{'Info'}->[$index]{'Signature'}{'Args'} =
	  $stref->{'Subroutines'}{$p}{'Blocks'}{$f}{'Args'};
	$index++;
	for my $inc (
		keys %{ $stref->{'Subroutines'}{$p}{'Blocks'}{$f}{'Includes'} } )
	{
		push @{$rlines}, "        include '$inc'";
		$stref->{'Subroutines'}{$f}{'Info'}->[$index]{'Include'}{'Name'} = $inc;
		$index++;
	}
	my $first = 1;
	for my $decl ( @{ $stref->{'Subroutines'}{$p}{'Blocks'}{$f}{'Decls'} } ) {
		my $var = shift @{ $stref->{'Subroutines'}{$p}{'Blocks'}{$f}{'Args'} };
		push @{$rlines}, "  $decl";
		if ( $first == 1 ) {
			$stref->{'Subroutines'}{$f}{'Info'}->[$index]{'ExGlobVarDecls'} =
			  {};
			$first = 0;
		}
		$stref->{'Subroutines'}{$f}{'Info'}->[$index]{'VarDecl'} = [$var];
		$index++;
	}
	for my $line (@lines) {
		push @{$rlines}, $line;
		my $tags_lref = shift @info;
		$stref->{'Subroutines'}{$f}{'Info'}->[$index] = $tags_lref;
		$index++;
	}
	push @{$rlines}, '      end';
	$stref->{'Subroutines'}{$f}{'Lines'} = $rlines;

	#        $stref->{'Subroutines'}{$f}{'Info'} =[];
	$stref->{'Subroutines'}{$f}{'Status'} = 3;
	$stref->{'Subroutines'}{$f}{'HasBlocks'} = 0;
	$stref->{'Subroutines'}{$f}{'Program'}   = 0;
	$stref->{'Subroutines'}{$f}{'StringConsts'} =
	  $stref->{'Subroutines'}{$p}{'StringConsts'};
	my $extract_sub_src = $stref->{'Subroutines'}{$p}{'Source'};
	$extract_sub_src =~ s/\.f$//;
	$extract_sub_src .= "_$f.f";
	$stref->{'Subroutines'}{$f}{'Source'} = $extract_sub_src;

	if ($V) {
		@lines = @{ $stref->{'Subroutines'}{$f}{'Lines'} };
		@info  = @{ $stref->{'Subroutines'}{$f}{'Info'} };
		my $annlines = [];
		for my $line (@lines) {
			my $tags = shift @info;
			push @{$annlines}, [ $line, $tags ];
		}
		for my $annline ( @{$annlines} ) {
			my $line      = $annline->[0] || '';
			my $tags_lref = $annline->[1];
			my %tags      = ( defined $tags_lref ) ? %{$tags_lref} : ();
			print '*** ' . join( ',', keys(%tags) ) . "\n" if $V;
			print '*** ' . $line . "\n" if $V;
		}
	}

	#         print STDERR "KEYS in $f\n";
	#        for my $k (sort keys %{$stref->{'Subroutines'}{$f}}) {
	#            print STDERR "$k\n";
	#        };

	return $stref;
}    # END of create_subroutine_source_from_block()

# -----------------------------------------------------------------------------

sub parse_includes {
	( my $f, my $stref ) = @_;
	print "PARSING INCLUDES for $f\n" if $V;
	my $srcref = $stref->{'Subroutines'}{$f}{'Lines'};
	for my $index ( 0 .. scalar( @{$srcref} ) - 1 ) {
		my $line = $srcref->[$index];
		if ( $line =~ /^C\s+/ or $line =~ /^\!\s/ ) {
			next;
		}

		if ( $line =~ /^\s*include\s+\'(\w+)\'/ )
		{    # TODO: nested includes not supported!

			my $name = $1;
			print "FOUND include $name in $f\n" if $V;
			$stref->{'Subroutines'}{$f}{'Includes'}{$name} = $index;
			$stref->{'Subroutines'}{$f}{'Info'}->[$index]{'Include'}{'Name'} =
			  $name;
			if ( $stref->{'Includes'}{$name}{'Status'} == 0 ) {
				print $line, "\n" if $V;

				# Initial guess for Root
				$stref->{'Includes'}{$name}{'Root'}      = $f;
				$stref->{'Includes'}{$name}{'HasBlocks'} = 0;
				$stref = parse_fortran_src( $name, $stref );
			} else {
				print $line, " already processed\n" if $V;
			}
		}
	}

	return $stref;
}    # END of parse_includes()

# -----------------------------------------------------------------------------

sub get_var_decls {
	( my $f, my $stref ) = @_;

	my $is_incl = exists $stref->{'Includes'}{$f} ? 1 : 0;
	my $sub_or_incl = $is_incl ? 'Includes' : 'Subroutines';

	my $srcref = $stref->{$sub_or_incl}{$f}{'Lines'};
	if ( defined $srcref ) {
		print "\nVAR DECLS in $f:\n" if $V;
		my %vars  = ();
		my $first = 1;
		for my $index ( 0 .. scalar( @{$srcref} ) - 1 ) {
			my $line = $srcref->[$index];

			#			print $line,"\n";
			#            $stref->{$sub_or_incl}{$f}{'Info'}->[$index]={};
			if ( $line =~ /^C\s+/ ) {
				next;
			}
			if ( $line =~ /^\!\s/ ) {
				$stref->{$sub_or_incl}{$f}{'Info'}
				  ->[$index]{'TrailingComments'} = {};
				next;
			}

			# real surfstrn(0:nxmaxn-1,0:nymaxn-1,1,2,maxnests)
			if ( $line =~
/(logical|integer|real|double\s+precision|character|character\*?(?:\d+|\(\*\)))\s+(.+)\s*$/
			  )
			{
				my $type    = $1;
				my $varlst  = $2;
				my $tvarlst = $varlst;

				if ( $tvarlst =~ /\(((?:[^\(\),]*?,)+[^\(]*?)\)/ ) {
					while ( $tvarlst =~ /\(((?:[^\(\),]*?,)+[^\(]*?)\)/ ) {
						my $chunk  = $1;
						my $chunkr = $chunk;
						$chunkr =~ s/,/;/g;
						my $pos = index( $tvarlst, $chunk );
						substr( $tvarlst, $pos, length($chunk), $chunkr );
					}
				}

				my @tvars    = split( /\s*\,\s*/, $tvarlst );
				my $p        = '';
				my @varnames = ();
				for my $var (@tvars) {
					$var =~ s/^\s+//;
					$var =~ s/\s+$//;
					my $tvar = $var;
					$tvar =~ s/\(.*?\)/(0)/g;
					if ( $tvar =~ s/\(.*?\)// ) {
						$tvar =~ s/\*\d+//
						  ;    # FIXME: char string handling is not correct!
						$vars{$tvar}{'Kind'} = 'Array';
						$p = '()';
					} else {
						$vars{$tvar}{'Kind'} = 'Scalar';
					}
					$vars{$tvar}{'Type'} = $type;
					$var =~ s/;/,/g;
					$vars{$tvar}{'Decl'} = "        $type $var"
					  ; # TODO: this should maybe not be a textual representation
					push @varnames, $tvar;
				}
				print "\t", join( ',', @varnames ), "\n" if $V;

				#              print "$f : $sub_or_incl; $index\n" if $V;
				$stref->{$sub_or_incl}{$f}{'Info'}->[$index]{'VarDecl'} =
				  \@varnames;
				if ($first) {
					$first = 0;
					$stref->{$sub_or_incl}{$f}{'Info'}
					  ->[$index]{'ExGlobVarDecls'} = {};
				}
			}
		}
		$stref->{$sub_or_incl}{$f}{'Vars'} = \%vars;
	}	
	return $stref;
}    # END of get_var_decls()

# -----------------------------------------------------------------------------

sub get_commons_params_from_includes {
	( my $f, my $stref ) = @_;
	my $srcref = $stref->{'Includes'}{$f}{'Lines'};
	if ( defined $srcref ) {
		my %vars        = %{ $stref->{'Includes'}{$f}{'Vars'} };
		my $has_pars    = 0;
		my $has_commons = 0;

		for my $index ( 0 .. scalar( @{$srcref} ) - 1 ) {
			my $line = $srcref->[$index];
			if ( $line =~ /^C\s+/ ) {
				next;
			}
			if ( $line =~ /^\s*common\s+\/[\w\d]+\/\s+(.+)$/ ) {
				my $commonlst = $1;
				$has_commons = 1;
				my @tcommons = split( /\s*\,\s*/, $commonlst );
				for my $var (@tcommons) {
					if ( not defined $vars{$var} ) {
						print STDERR "MISSING: <", $var, ">\n";
					} else {
						print $var, "\t", $vars{$var}{'Type'}, "\n" if $V;
						$stref->{'Includes'}{$f}{'Commons'}{$var} = $vars{$var};
					}
				}
				$stref->{'Includes'}{$f}{'Info'}->[$index]{'Common'} = {};
			}

			if ( $line =~ /parameter\s*\(\s*(.*)\s*\)/ ) {

				my $parliststr = $1;
				$has_pars = 1;
				my @partups = split( /\s*,\s*/, $parliststr );
				my @pvars =
				  map { s/\s*=.+//; $_ } @partups;    # Perl::Critic, EYHO

				for my $var (@pvars) {
					if ( not defined $vars{$var} ) {
						print STDERR "NOT A PARAMETER: <", $var, ">\n";
					} else {
						$stref->{'Includes'}{$f}{'Parameters'}{$var} =
						  $vars{$var};
					}
				}
				$stref->{'Includes'}{$f}{'Info'}->[$index]{'Parameter'} = {};
			}
		}

		if ($V) {
			print "\nCOMMONS for $f:\n\n";
			for my $v ( sort keys %{ $stref->{'Includes'}{$f}{'Commons'} } ) {
				print $v, "\n";
			}
		}

		# FIXME!
		# An include file should basically only contain parameters and commons.
		# If it contains commons, we should remove them!
		if ( $has_commons && $has_pars ) {
			die
"The include file $f contains both parameters and commons, this is not yet supported.\n";
		} elsif ($has_commons) {
			$stref->{'Includes'}{$f}{'Type'} = 'Common';
		} elsif ($has_pars) {
			$stref->{'Includes'}{$f}{'Type'} = 'Parameter';
		} else {
			$stref->{'Includes'}{$f}{'Type'} = 'None';
		}
		for my $var ( keys %vars ) {
			if (
				(
					$has_pars
					and not
					exists( $stref->{'Includes'}{$f}{'Parameters'}{$var} )
				)
				or ( $has_commons
					and not exists( $stref->{'Includes'}{$f}{'Commons'}{$var} )
				)
			  )
			{
				warn Dumper( $stref->{'Includes'}{$f}{'Lines'} );
				die
"The include $f contains a variable $var that is neither a parameter nor a common variable, this is not supported\n";
			}
		}
	}
	return $stref;
}    # END of get_commons_params_from_includes()

# -----------------------------------------------------------------------------

sub separate_blocks {
	( my $f, my $stref ) = @_;

	my $srcref   = $stref->{'Subroutines'}{$f}{'Lines'};
	my %vars     = %{ $stref->{'Subroutines'}{$f}{'Vars'} };
	my %occs     = ();
	my %blocks   = ();
	my $in_block = 0;
	my $block    = 'OUTER';
	for my $index ( 0 .. scalar( @{$srcref} ) - 1 ) {
		my $line = $srcref->[$index];

		if ( $line =~ /^C\s+BEGIN\sSUBROUTINE\s(\w+)/ ) {
			$in_block = 1;
			$block    = $1;
			push @{ $blocks{'OUTER'} }, $line;
			$stref->{'Subroutines'}{$f}{'Info'}
			  ->[$index]{'RefactoredSubroutineCall'}{'Name'} = $block;
			$stref->{'Subroutines'}{$f}{'Info'}
			  ->[$index]{'BeginBlock'}{'Name'} = $block;
			next;
		}
		if ( $line =~ /^C\s+END\sSUBROUTINE\s(\w+)/ ) {
			$in_block = 0;
			$block    = $1;
			push @{ $blocks{$block} }, $line;
			$stref->{'Subroutines'}{$f}{'Info'}->[$index]{'EndBlock'}{'Name'} =
			  $block;
			next;
		}
		if ($in_block) {
			push @{ $blocks{$block} }, $line;
			$stref->{'Subroutines'}{$f}{'Info'}->[$index]{'InBlock'}{'Name'} =
			  $block;
		} else {
			push @{ $blocks{'OUTER'} }, $line;
		}
	}

	for my $block ( keys %blocks ) {
		next if $block eq 'OUTER';
		$stref->{'Subroutines'}{$f}{'Blocks'}{$block}{'Lines'} =
		  $blocks{$block};
		$stref->{'Subroutines'}{$f}{'Blocks'}{$block}{'Source'} =
		  $stref->{'Subroutines'}{$f}{'Source'};
	}

  # So now we have split the file in blocks, we have identified the common vars.

# 6. Identify which vars are used
#   - in both => these become function arguments
#   - only in "outer" => do nothing for those
#   - only in "inner" => can be removed from outer variable declarations
# Find all vars used in each block, starting with the outer block
# It is best to loop over all vars per line per block, because we can remove the encountered vars
	for my $block ( keys %blocks ) {
		my @lines = @{ $blocks{$block} };
		my %tvars = %vars;                  # Hurray for pass-by-value!
		print "\nVARS in $block:\n\n" if $V;

		# FIXME: rework as in identify_globals_used_in_subroutine()
		for my $line (@lines) {
			my $tline = $line;
			$tline =~ s/\'.+?\'//;
			for my $var ( keys %tvars ) {
				if ( $tline =~ /\W$var\W/ or $tline =~ /\W$var\s*$/ ) {
					print "FOUND $var\n" if $V;
					$occs{$block}{$var} = $var;
					delete $tvars{$var};
				}
			}
		}

		#		$stref->{'Subroutines'}{$block}{'Occs'} = $occs{$block};
	}

 #	my %args = ();
 #	for my $block ( keys %occs ) {
 #		next if $block eq 'OUTER';
 #		print "\nARGS for $block:\n" if $V;
 #		for my $var ( keys %{ $occs{$block} } ) {
 #			if ( exists $occs{'OUTER'}{$var} ) {
 #				print "$var\n" if $V;
 #				push @{ $args{$block} }, $var;
 #			}
 #		}
 #	}
 # WV: we do this later
 #	# 7. Identify which commons are used in inner, make them function arguments
 #	# This is the same as in remove_globals
 #       my %commons=();
 #        for my $i ( keys %{ $stref->{'Subroutines'}{$f}{'Includes'} } ) {
 #            if ( $stref->{'Includes'}{$i}{'Type'} eq 'Common' ) {
 #                %commons=(%commons, %{ $stref->{'Includes'}{$i}{'Commons'} });
 #            }
 #        }
 #	   $stref->{'Subroutines'}{$f}{'Commons'}=\%commons;
 #	# This is almost the same as above
 #	for my $block ( keys %blocks ) {
 #		next if $block eq 'OUTER';
 #		my @lines = @{ $blocks{$block} };
 #        my @tvars=keys %commons;
 #		for my $line (@lines) {
 #			for my $var ( @tvars ) {
 #				next if not defined $var;
 #				if ( $line =~ /\W$var\W/ ) {
 #					push @{ $args{$block} }, $var;
 #					undef $var;
 #				}
 #			}
 #		}
 #		if ($V) {
 #			print "\nCOMMON VARS in block $block:\n\n";
 #			for my $var ( @{ $args{$block} } ) {
 #				print "$var\n";
 #			}
 #		}
 #		$stref->{'Subroutines'}{$block}{'Args'} = $args{$block};
 #	}

	# Construct the subroutine signatures
	my %args = ();
	for my $block ( keys %blocks ) {
		next if $block eq 'OUTER';

		print "\nARGS for BLOCK $block:\n" if $V;
		for my $var ( keys %{ $occs{$block} } ) {
			if ( exists $occs{'OUTER'}{$var} ) {
				print "$var\n" if $V;
				push @{ $args{$block} }, $var;
			}
		}
		$stref->{'Subroutines'}{$block}{'Args'} = $args{$block};
		my $sig   = "      subroutine $block(";
		my $decls = [];
		for my $argv ( @{ $args{$block} } ) {
			$sig .= "$argv,";
			my $decl = $vars{$argv}{'Decl'};    #|| $commons{$argv}{'Decl'};
			push @{$decls}, $decl;
		}
		$sig =~ s/\,$/)\n/s;
		$stref->{'Subroutines'}{$f}{'Blocks'}{$block}{'Args'}  = $args{$block};
		$stref->{'Subroutines'}{$f}{'Blocks'}{$block}{'Sig'}   = $sig;
		$stref->{'Subroutines'}{$f}{'Blocks'}{$block}{'Decls'} = $decls;

#        $stref->{'Subroutines'}{$f}{'Blocks'}{$block}{'Lines'} = $blocks{$block};
#        $stref->{'Subroutines'}{$f}{'Blocks'}{$block}{'Source'} = $stref->{'Subroutines'}{$f}{'Source'};
		for my $inc ( keys %{ $stref->{'Subroutines'}{$f}{'Includes'} } ) {

			#        	if($stref->{'Subroutines'}{$f}{'Includes'}{$inc}!=-1) {
			$stref->{'Subroutines'}{$f}{'Blocks'}{$block}{'Includes'}{$inc} =
			  -2;

			#        	}
		}
		if ($V) {
			print $sig, "\n";
			print join( "\n", @{$decls} ), "\n";
		}
	}

	return $stref;
}    # END of separate_blocks()

# -----------------------------------------------------------------------------
# FIXME: "error: break statement not within loop or switch"
sub identify_loops_breaks {
	( my $f, my $stref ) = @_;

	my $srcref = $stref->{'Subroutines'}{$f}{'Lines'};

	my %do_loops = ();
	my %gotos    = ();

	#	my %labels=();
	my $nest = 0;
	for my $index ( 0 .. scalar( @{$srcref} ) - 1 ) {
		my $line = $srcref->[$index];
		next if $line =~ /^C\s+/;

		# BeginDo:
		$line =~ /^\s+do\s+(\d+)\s+\w/ && do {
			my $label = $1;
			$stref->{'Subroutines'}{$f}{'Info'}->[$index]{'BeginDo'}{'Label'} =
			  $label;
			if ( not exists $do_loops{$label} ) {
				@{ $do_loops{$label} } = ( [$index], $nest );
				$nest++;
			} else {
				push @{ $do_loops{$label}[0] }, $index;

#        		print STDERR "WARNING: $f: Found duplicate label $label at: ".join(',',@{ $do_loops{$label}[0] })."\n";
			}
			next;
		};

		# Goto
		$line =~ /^\s+.*?[\)\ ]\s*goto\s+(\d+)\s*$/ && do {
			my $label = $1;
			$stref->{'Subroutines'}{$f}{'Info'}->[$index]{'Goto'}{'Label'} =
			  $label;
			$stref->{'Subroutines'}{$f}{'Gotos'}{$label} = 1;
			push @{ $gotos{$label} } , [ $index, $nest ];
			next;
		};

		# continue can be end of do loop or break target (amongs others?)
		$line =~ /^\s{0,4}(\d+)\s+(continue|\w)/ && do {
			my $label = $1;
			my $is_cont = $2 eq 'continue' ? 1 : 0;
			if ( exists $do_loops{$label} ) {
				if ( $nest == $do_loops{$label}[1] + 1 ) {
					$stref->{'Subroutines'}{$f}{'Info'}
					  ->[$index]{'EndDo'}{'Label'} = $label;
					$stref->{'Subroutines'}{$f}{'Info'}
					  ->[$index]{'EndDo'}{'Count'} =
					  scalar @{ $do_loops{$label}[0] };
					delete $do_loops{$label};
					$nest--;
				} else {
					print STDERR
"WARNING: $f: Found continue for label $label but nesting level is wrong: $nest<>$do_loops{$label}[1]\n";
				}
			} elsif ( exists $gotos{$label} ) {
				my $target = 'GotoTarget';
				for my $pair (@{$gotos{$label} }) {
					(my $tindex, my $tnest)=@{$pair};
					$target = 'GotoTarget';
					if ( $nest <= $tnest ) { # What if there are several gotos point to one label?
						if ($tnest>0) {					
							if ($is_cont) {
								$target = 'NoopBreakTarget';
								$stref->{'Subroutines'}{$f}{'Info'}
								  ->[ $tindex ]{'Break'}{'Label'} = $label;
							} else {
								$target = 'BreakTarget';
								$stref->{'Subroutines'}{$f}{'Info'}
								  ->[ $tindex  ]{'Break'}{'Label'} = $label;
		
		#                    	print STDERR "WARNING: $f: Found BREAK target not NOOP for label $label\n";
							}
						} else {
							if ($is_cont) {
                                $target = 'NoopTarget';
						  }
#							print "WARNING: goto $label ($tindex) is not in loop ($f)\n" if $translate==2; 
						}					
				    } else {
					   print STDERR
"WARNING: $f: Found GOTO target not BREAK for label $label: wrong nesting $nest<>$gotos{$label}[1]\n";
				    }
			 }
				$stref->{'Subroutines'}{$f}{'Info'}
				  ->[$index]{$target}{'Label'} = $label;
				$stref->{'Subroutines'}{$f}{'Gotos'}{$label} = $target;
				delete $gotos{$label};

			}
			next;
		};

   # When an open() fails, you can pass a label to some place for error handling
   # Some evil code combines this end-of-do-block labels
		$line =~ /^\s+open.*?\,\s*err\s*=\s*(\d+)\s*\)/ && do {
			my $label = $1;
			$stref->{'Subroutines'}{$f}{'Gotos'}{$label} = 1;
			next;
		};
	}
	return $stref;
}    # END of identify_loops_breaks()

# -----------------------------------------------------------------------------
# This subroutine reads the FORTRAN source and does very little else:
# - it combines continuation lines in a single line
# - it lowercases everything
# - it detects and normalises comments
# - it detects block markers (for factoring blocks out into subs)
# The routine is called by parse_fortran_src()
# A better way is to extract all subs in a single pass
# I guess the best wat is to first join the lines, then separate the subs
sub read_fortran_src {
	( my $s, my $stref ) = @_;

	my $is_incl = exists $stref->{'Includes'}{$s} ? 1 : 0;
	# FIXME: handle Functions too!
	
	my $sub_or_func = exists $stref->{'Subroutines'}{$s} ? 'Subroutines' : 'Functions';
	my $sub_func_incl = $is_incl ? 'Includes' : $sub_or_func;
	my $f = $is_incl ? $s : $stref->{'Subroutines'}{$s}{'Source'};

	#    warn "$s: $f,",$stref->{$sub_func_incl}{$s}{'Status'},"\n";
	#    die "$f: $sub_func_incl $s" if $f=~/map_proj_wrf_subaa/;
	if ( $stref->{$sub_func_incl}{$s}{'Status'} == 0 ) {
		my $ok = 1;
		open my $SRC, '<', $f or do {
			print STDERR "Can't find '$f' ($s)\n";
			$ok = 0;
		};
		if ($ok) {
			print "READING SOURCE for $f\n" if $V;
			local $V = 0;
			my $lines    = [];
			my $prevline = '';

			# 0. Slurp the source; standardise the comments
			# 1. Join up the continuation lines
			# TODO: split lines with ;
			# TODO: Special case: comments in continuation lines.
			# For now, I just throw them away.
			my $cont = 0;

			my %strconsts             = ();
			my @phs                   = ();
			my @placeholders_per_line = ();
			my $ct                    = 0;

			my $line = '';
			while (<$SRC>) {
				$line = $_;
				chomp $line;

				# Skip blanks
				$line =~ /^\s*$/ && next;

				# Detect and standardise comments
				if ( $line =~ /^[CD\*\!]/i or $line =~ /^\ {6}\s*\!/i ) {
					$line =~ s/^\s*[CcDd\*\!]/C /;
				} elsif ( $line =~ /\s+\!.*$/ )
				{    # FIXME: trailing comments are discarded!
					my $tline = $line;
					$tline =~ s/\'.+?\'//;
					if ( $tline =~ /\s+\!.*$/ ) {

				  # convert trailing comments into comments on the previous line
						( $line, my $comment ) = split( /\s+\!/, $line );
					}
				}

				if ( $line =~ /^\ {5}[^0\s]/ ) {    # continuation line
					$line =~ s/^\s{5}.\s*/ /;
					$prevline .= $line;
					$cont = 1;
				} elsif ( $line =~ /^\&/ ) {
					$line =~ s/^\&\t*/ /;
					$prevline .= $line;
					$cont = 1;
				} elsif ( $line =~ /^\t[1-9]/ ) {
					$line =~ s/^\t[0-9]/ /;
					$prevline .= $line;
					$cont = 1;
				} elsif ( $prevline =~ /\&\s&$/ ) {
					$prevline =~ s/\&\s&$//;
					$prevline .= $line;
					$cont = 1;
				} elsif ( $line =~ /^C\ / && ( $cont == 1 ) ) {

					# A comment occuring after a continuation line. Skip!
					next;
				} else {

 #                    warn "TAB FORMAT for $prevline ?\n" if $prevline =~/9100/;
 #                    ($prevline=~/^\t/ || $prevline=~/^\d+\t/ ) && do {
 #                        warn "TAB FORMAT for $prevline\n" ;
 #                    };
					my $sixspaces = ' ' x 6;
					$prevline =~ s/^\t/$sixspaces/;
					$prevline =~ /^(\d+)\t/ && do {
						my $label  = $1;
						my $ndig   = length($label);
						my $spaces = ' ' x ( 6 - $ndig );
						my $str    = $label . $spaces;
						$prevline =~ s/^(\d+)\t/$str/;
					};
					if ( substr( $prevline, 0, 2 ) ne 'C ' ) {
						if ( $prevline !~ /^\s+include\s+\'/i ) {

							# replace string constants by placeholders
							while ( $prevline =~ /(\'.*?\')/ ) {
								my $strconst = $1;
								my $ph       = '__PH' . $ct . '__';
								push @phs, $ph;
								$strconsts{$ph} = $strconst;
								$prevline =~ s/\'.*?\'/$ph/;
								$ct++;
							}
						}

	 # remove trailing comments
	 #	               	( $prevline, my $comment ) = split( /\s+\!/, $prevline );
					}
					my $lcprevline =
					  ( substr( $prevline, 0, 2 ) eq 'C ' )
					  ? $prevline
					  : lc($prevline);
					$lcprevline =~ s/__ph(\d+)__/__PH$1__/g;

					#	                  warn "$lcprevline\n";
					push @{$lines},
					  $lcprevline;    # unless $lcprevline eq ''; # HACK
					push @placeholders_per_line, [@phs];
					@phs      = ();
					$prevline = $line;
					$cont     = 0;
				}
			}

			# There can't be strings on the last line (except in a include?)
			# and substr($prevline,-length($line),length($prevline)) ne $line
			if ( $line ne $prevline )
			{    # Too weak, if there are comments in between it breaks!
				my $lcprevline =
				  ( substr( $prevline, 0, 2 ) eq 'C ' )
				  ? $prevline
				  : lc($prevline);
				push @{$lines}, $lcprevline;
			}

			# HACK! FIXME!
			if (    $f =~ /^include/
				and length($line) != length($prevline)
				and substr( $prevline, -length($line), length($prevline) ) eq
				$line )
			{

				# the last line was already appended to the previous line!
			} else {
				my $lcline =
				  ( substr( $line, 0, 2 ) eq 'C ' ) ? $line : lc($line);
				push @{$lines}, $lcline;
			}
			push @placeholders_per_line, [];
			push @placeholders_per_line, [];
			close $SRC;

			#	        die if $f =~ /coordtrafo/;
			#	        die Dumper($lines) if $f =~ /coordtrafo/;
			my $name = 'NONE';
			my $ok   = 0;
			if ($is_incl) {
				$ok                                  = 1;
				$name                                = $s;
				$stref->{$sub_func_incl}{$s}{'Status'} = 1;
			}
			my $index = 0;
			for my $line ( @{$lines} ) {
				my $phs_ref = shift @placeholders_per_line;

#	        	print STDERR '[',join(',',@{$phs_ref}),"]\n";
# If it's a subroutine source, skip all lines before the matching subroutine signature
#and all lines from (and including) the next non-matching subroutine signature
				if (   $is_incl == 0
					&& $line =~ /^\s+(?:program|subroutine)\s+(\w+)/ )
				{
					$name = $1;

					#	            	warn "\t$name\n";
					$ok                                           = 1;
					$index                                        = 0;
					$stref->{$sub_func_incl}{$name}{'Status'}       = 1;
					$stref->{$sub_func_incl}{$name}{'HasBlocks'}    = 0;
					$stref->{$sub_func_incl}{$name}{'StringConsts'} = \%strconsts
					  ; # Means we have all consts in the file, not just the sub, but who cares?
				}
				if ( $ok == 1 ) {
					push @{ $stref->{$sub_func_incl}{$name}{'Lines'} }, $line;
					if ( $line =~ /^C/ ) {
						$stref->{$sub_func_incl}{$name}{'Info'}
						  ->[$index]{'Comments'} = {};
					}
					$stref->{$sub_func_incl}{$name}{'Info'}->[$index] =
					  { 'PlaceHolders' => $phs_ref }
					  if @{$phs_ref};
					$index++;
				}

			}
		}    # if OK
	}    # if Status==0

  #    die Dumper($stref->{$sub_or_incl}{'includehanna'}) if $f=~/includehanna/;
	return $stref;
}    # END of read_fortran_src()

# -----------------------------------------------------------------------------
# Find all source files in the current directory
sub find_subroutines_functions_and_includes {
	my $stref = shift;
	my $dir   = '.';
	my $ext   = '.f';

	# find sources (borrowed from PerlMonks)
	my %src_files = ();
	my $tf_finder = sub {
		return if !-f;
		return if !/\.f$/;
		$src_files{$File::Find::name} = 1;
	};
	find( $tf_finder, $dir );

	for my $src ( keys %src_files ) {
		open my $SRC, '<', $src;
		while ( my $line = <$SRC> ) {

			# Skip blanks
			$line =~ /^\s*$/ && next;

			# Detect and standardise comments
			$line =~ /^[C\*\!]/i && next;
			$line =~ /^\s+(subroutine|program)\s+(\w+)/i && do {
				my $is_prog = $1 eq 'program' ? 1 : 0;
				if ( $is_prog == 1 ) {
					print "Found program $2 in $src\n" if $V;
				}
				my $sub = lc($2);
				if (
					not exists $stref->{'Subroutines'}{$sub}{'Source'}
					or (    $src =~ /$sub\.f/
						and $stref->{'Subroutines'}{$sub}{'Source'} !~
						/$sub\.f/ )
				  )
				{
					if (    exists $stref->{'Subroutines'}{$sub}{'Source'}
						and $src =~ /$sub\.f/
						and $stref->{'Subroutines'}{$sub}{'Source'} !~
						/$sub\.f/ )
					{
						print STDERR "WARNING: Ignoring source "
						  . $stref->{'Subroutines'}{$sub}{'Source'}
						  . " because source $src matches subroutine name $sub.\n";
					}
					$stref->{'Subroutines'}{$sub}{'Source'}  = $src;
					$stref->{'Subroutines'}{$sub}{'Status'}  = 0;
					$stref->{'Subroutines'}{$sub}{'Program'} = $is_prog;
				} else {
					print STDERR
"WARNING: Ignoring source $src for $sub because another source, "
					  . $stref->{'Subroutines'}{$sub}{'Source'}
					  . " exists.\n";
				}
			};
			$line =~ /^\s*include\s+\'(\w+)\'/ && do {
				my $inc = $1;
				if ( not exists $stref->{'Includes'}{$inc} ) {
					$stref->{'Includes'}{$inc}{'Status'} = 0;
				}
			};
			$line =~ /^\s*\w*\s+function\s+(\w+)/i && do {
				my $func = $1;
				$stref->{'Functions'}{$func}{'Source'} = $src;
			};

		}
		close $SRC;
	}
	return $stref;
}    # END of find_subroutines_functions_and_includes()

# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
sub show_info {
	( my $stref ) = @_;
	if ($V) {
		print "\n\n";
		print "#" x 80, "\n";
		print "Info\n";
		print "#" x 80, "\n\n";
	}

	for my $f ( keys %{ $stref->{'Subroutines'} } ) {

		if (    exists $stref->{'Subroutines'}{$f}{'Lines'}
			and exists $stref->{'Subroutines'}{$f}{'Info'} )
		{
			print "\nSUBROUTINE: $f\n\n";

			#           die Dumper($stref->{'Subroutines'}{$f}{'Info'});
			my @lines = @{ $stref->{'Subroutines'}{$f}{'Lines'} };
			my @info  = @{ $stref->{'Subroutines'}{$f}{'Info'} };
			if ( scalar(@lines) != scalar(@info) ) {
				die scalar(@lines) . '!=' . scalar(@info) . " for $f";
			} else {

				for my $i ( 0 .. @lines - 1 ) {
					my $line = $lines[$i];
					my $item = $info[$i];
					if ( defined $item ) {
						print $line, "\t\t**** ";
						print join( ',', keys %{$item} ), "\n";
					}
				}
				print "\n";
			}
		} else {
			print "WARNING: No info for $f\n";
		}

	}

}

# -----------------------------------------------------------------------------
sub insert_lines {
	( my $lref, my $srcref, my $idx ) = @_;    # \@lines, \@src_lines, $idx;
	my $nsrc = [ @{$srcref} ];
	splice( @{$nsrc}, $idx, 0, @{$lref} );
	return $nsrc;
}    # END of insert_lines()

# -----------------------------------------------------------------------------

=info2
We also need a convenience function to split long lines.
- count the number of characters, i.e. length()
- find the last comma before we exceed 64 characters (I guess it's really 72-5?):
=cut

sub split_long_line {
	my $line   = shift;
	my @chunks = @_;

	my $nchars = 64;
	if ( scalar(@chunks) == 0 ) {
		print "\nLINE: \n$line\n" if $V;
		$nchars = 72;
	}
	my $split_on  = ',';
	my $split_on2 = ' ';
	my $split_on3 = '.ro.';
	my $split_on4 = '.dna.';

	my $smart = 0;
	if ( length($line) > $nchars ) {
		my $patt  = '';
		my $ll    = length($line);
		my $rline = join( '', reverse( split( '', $line ) ) );

		#		print $rline,"\n";
		#		print "$ll - $nchars = ",$ll - $nchars,"\n";
		my $idx  = index( $rline, $split_on,  $ll - $nchars );
		my $idx2 = index( $rline, $split_on2, $ll - $nchars );
		my $idx3 = index( $rline, $split_on3, $ll - $nchars );
		my $idx4 = index( $rline, $split_on4, $ll - $nchars );
		if ( $idx < 0 && $idx2 < 0 && $idx3 < 0 && $idx4 < 0 ) {
			warn "WARNING: Can't split line \n$line\n" if $V;
		} elsif ( $idx >= 0 ) {
			print "Split line on ", $ll - $idx, ", '$split_on'\n" if $V;
		} elsif ( $idx < 0 && $idx2 >= 0 ) {
			$idx = $idx2;
			print "Split line on ", $ll - $idx2, ", '$split_on2'\n" if $V;
		} elsif ( $idx < 0 && $idx2 < 0 && $idx3 >= 0 ) {
			$idx = $idx3;
			print "SPLIT line on ", $ll - $idx, ", '$split_on3'\n" if $V;

			# Need smarter split
			$smart = 1;
			$patt = join( '', reverse( split( '', $split_on3 ) ) );
		} elsif ( $idx < 0 && $idx2 < 0 && $idx4 >= 0 ) {
			$idx = $idx4;
			print "SPLIT line on ", $ll - $idx, ", '$split_on4'\n" if $V;

			# Need smarter split
			$smart = 1;
			$patt = join( '', reverse( split( '', $split_on4 ) ) );
		}

#		if ($smart==1) {
#			die substr( $line, 0, $ll - $idx3, '' ) if length(substr( $line, 0, $ll - $idx3, '' ))>$nchars;
#		}
		push @chunks, substr( $line, 0, $ll - $idx, '' );
		print "CHUNKS:\n", join( "\n", @chunks ), "\n" if $V;
		print "REST:\n", $line, "\n" if $V;
		&split_long_line( $line, @chunks );
	} else {
		push @chunks, $line;

		my @split_lines = ();
		if ( @chunks > 1 ) {
			my $fst = 1;
			for my $chunk (@chunks) {
				if ($fst) {
					$fst = 0;
				} else {
					if ( $chunk =~ /^\s*$/ ) {
						$chunk = '';
					} else {

						#						$chunk = '     &  ' . $chunk;
						$chunk = '     &' . $chunk;
					}
				}
				push @split_lines, $chunk;
			}
		} else {
			@split_lines = @chunks;
		}
		return @split_lines;
	}
}

# -----------------------------------------------------------------------------
sub union {
	( my $aref, my $bref ) = @_;
	my %as = map { $_ => 1 } @{$aref};
	for my $elt ( @{$bref} ) {
		$as{$elt} = 1;
	}
	my @us = sort keys %as;
	return \@us;
}    # END of union()

# -----------------------------------------------------------------------------
# This union is obtained by removing duplicates from @b. It is a bit slower but preserves the order
sub ordered_union {
	( my $aref, my $bref ) = @_;
	my @us = @{$aref};
	my %as = map { $_ => 1 } @{$aref};
	for my $elt ( @{$bref} ) {
		if ( not exists $as{$elt} ) {
			push @us, $elt;
		}
	}
	return \@us;
}    # END of ordered_union()

# -----------------------------------------------------------------------------
