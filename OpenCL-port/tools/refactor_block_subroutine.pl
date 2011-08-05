#!/usr/bin/perl
use warnings;
use strict;

=TODOs
- for the root, we do need the include of the common vars.
- The 'is root for' approach is broken: somehow, in Fortran, two subroutines share vars if they both include the same common block, even if they don't depend on one another.
- So what I actually need is not the first encounter of an include, for example initialize() nad advance() both include 'includehanna';
- So what happens is that the values for those variable are set in initialize() and used in advance(). That means that they must be function args of both routines and declared in the one above that!
So the rule is: if, in a given subroutine, only a single subroutine uses a given include, that subroutine is the root; but if there is more than one, it must be the one above that!
     
=cut

=pod

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


After building this structure, what we need is to go through it an revert it so it becomes index => information

とにかく, コード　は:

=cut

use Data::Dumper;
use File::Find;
our $V = 0;

&main();
# -----------------------------------------------------------------------------
sub main {
	die "Please specifiy FORTRAN subroutine to refactor\n" if not @ARGV;
	my $subname = $ARGV[0];
	
	my $stateref = {
		'Includes'   => {},
		    # $name => {Root =>$source, Type => Common | Param | Both,'Commons'    => {},    'Parameters' => {},    }
		'Subroutines' => {
			#		 $name => {
			#			'Source' => $src,
			#			'Lines' =>[],
			#			'Blocks'=>{$block=>[]},
			#		  'HasBlocks'=>0|1
			#		  'Nodes'=>	{
			#		  	'SubroutineCall'=>{
			#		  		$name=>{'Pos'=>[$index,...],'Globals'=>[],...};
			#            }
			#		    'Signature'=>{'Pos'=>[$index,...],'Globals'=>[],...};
			#		    'VarDecls'=>
			#		    'RefactoredCode' => {},
			#		  }
	
		},
		
		
	};
	# Find all subroutines in the source code tree
	$stateref = find_subroutines_and_includes($stateref);
	
	# First we analyse the code for use of globals and blocks to be transformed into subroutines	
	$stateref = parse_fortran_src( $subname, $stateref );
	
	# Then we create an "inverted index" of the information we have gathered, by line of the orginal source.
	# One important point is that we must mark all blocks to be refactored as such, so those lines can be skipped!
#	$stateref = get_info_per_line($stateref);	
#	show_info($stateref);

	# Refactor the source
	$stateref = refactor_code('timemanager',$stateref);	
	print Dumper($stateref->{'Subroutines'}{'timemanager'}{'RefactoredCode'});
	print Dumper($stateref->{'Subroutines'}{'particles_main_loop'}{'RefactoredCode'});
#	$stateref = refactor_all($stateref);
	# Emit the refactored source
	emit_refactored_code($stateref);
	
	exit(0);

} # END of main()
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
# This is the most important routine
# It parses the FORTRAN source as discussed above
# T
sub parse_fortran_src {
	( my $f, my $stref ) = @_;
    # Read the source and do some minimal processsing
	$stref = read_fortran_src( $f, $stref );

	my $is_incl = exists $stref->{'Includes'}{$f} ? 1 : 0;   
	
	# 2. Parse the type declarations in the source, create a table %vars
	$stref = get_var_decls( $f, $stref );

	# 3. Parse includes, recursively doing 0/1/2
	if ( not $is_incl ) {
		$stref = detect_blocks( $f, $stref );
		$stref = parse_includes( $f, $stref );		
		$stref = parse_subroutine_calls( $f, $stref );		
		$stref = identify_globals_used_in_subroutine( $f, $stref );		
	# 5. Split the source based on the block markers
	# As there could be several blocks (later), use a hash per block
	# This could happen in any file except includes; but include processing never comes here
	    if ($stref->{'Subroutines'}{$f}{'HasBlocks'}) {
	        $stref = separate_blocks( $f, $stref );
	    }		
	    $stref = identify_loops_breaks( $f, $stref );
	}
	else {    # includes
		 # 4. For includes, parse common blocks and parameters, create $stref->{'Commons'}
		$stref = get_commons_params_from_includes( $f, $stref );
	}

#	for my $i ( keys %{ $stref->{'Subroutines'}{$f}{'Includes'} } ) {
#		if ( $stref->{'Includes'}{$i}{'Type'} eq 'Common' ) {
#			$stref->{'Subroutines'}{$f}{'HasCommons'} = 1;
#			last;
#		}
#	}


	return $stref;

}    # END of parse_fortran_src()

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
* BeginDo: just remove the label
* EndDo: replace CONTINUE by END DO
(* Break: keep as is; add a comment to identify it as a break)
* BreakTarget: replace CONTINUE with "call noop"
=cut
sub refactor_code {
	( my $f, my $stref ) = @_;
    if ($V) {
        print "\n\n";
        print "#" x 80, "\n";
        print "Refactoring $f\n";
        print "#" x 80, "\n";
    }

    my @lines    = @{ $stref->{'Subroutines'}{$f}{'Lines'} };
    my @info     = @{ $stref->{'Subroutines'}{$f}{'Info'} };
    my $annlines = [];
    for my $line (@lines) {     
        my $tags = shift @info;
       push @{$annlines}, [ $line, $tags ];
    }
    
    my $rlines = [];
    if ( $stref->{'Subroutines'}{$f}{'HasCommons'} ) {
        
        for my $annline ( @{$annlines} ) {
            my $line      = $annline->[0]||'';
            my $tags_lref = $annline->[1];
#           if ( not defined $tags_lref ) { die "BOOM!" }
            my %tags = ( defined $tags_lref ) ? %{$tags_lref} : ();
            print '*** ' . join( ',', keys(%tags) ). "\n";
            print '*** '.$line."\n";
            my $skip = 0;

            if ( exists $tags{'Signature'} ) {
                my $name = $tags{'Signature'}{'Name'};
                my @args = @{ $tags{'Signature'}{'Args'} };
                  my @exglobs=();
                  for my $inc (keys %{ $stref->{'Subroutines'}{$f}{'Globals'} }){
                    print "INFO: INC $inc in $f\n";
                    if (not exists $stref->{'Includes'}{$inc}{'Root'} ) { die "$inc has no Root in $f"}
                    if (  $stref->{'Includes'}{$inc}{'Root'} eq $f ) {
                        print "INFO: $f is root for $inc\n";
                        next;
                    } 
#                   else {
#                       print "INFO: $f is not root for $inc\n";
#                   }
                     @exglobs=(@exglobs,@{ $stref->{'Subroutines'}{$f}{'Globals'}{$inc} } );
                  }
                my $rline =
                    '      subroutine ' 
                  . $name . '('
                  . join( ',', ( @args, @exglobs ) ) . ')';
                $tags{'Refactored'} = 1;
                push @${rlines}, [ $rline, $tags_lref ];
                $skip = 1;
            }
            if ( exists $tags{'ExGlobVarDecls'} ) {
                for my $inc (keys %{  $stref->{'Subroutines'}{$f}{'Globals'} }) {
                    if ($stref->{'Subroutines'}{$f}{'Includes'}{$inc}==-1 ) {
                        my $rline="      include '$inc'";
                        $tags_lref->{'Include'}{'Name'}=$inc;
                       push @{$rlines}, [ $rline, $tags_lref ];
                    }
                }
                
                for my $inc (keys %{  $stref->{'Subroutines'}{$f}{'Globals'} }) {
                    for my $var ( @{  $stref->{'Subroutines'}{$f}{'Globals'}{$inc} } ) {
                        my $rline = $stref->{'Subroutines'}{$f}{'Commons'}{$var}{'Decl'};
                        if (not defined $rline) {
                            $rline ="*** NO DECL for $var!";
                        }                   
                        push @{$rlines}, [ $rline, $tags_lref ];
                    }
                }
            }
            if ( exists $tags{'Include'} ) {
                my $inc =$tags{'Include'}{'Name'};
                print "INFO: INC $inc in $f\n";
                if ( $stref->{'Includes'}{$inc}{'Type'} eq 'Common' and $stref->{'Includes'}{$inc}{'Root'} ne $f) {
                    $skip = 1;
                }
            }
            if ( exists $tags{'SubroutineCall'} ) {
#               print "SUBCALL: $line\n";               
                # simply tag the common vars onto the arguments
                my $name=$tags{'SubroutineCall'}{'Name'};
                my @globals=();
                for my $inc (keys %{ $stref->{'Subroutines'}{$name}{'Globals'} }) {             
                    @globals=(@globals,@{ $stref->{'Subroutines'}{$name}{'Globals'}{$inc} });
                }   
                if (@globals) {unshift @globals,''}             
                my $global_args_str = join(',',@globals);
                my $orig_args_str=$tags{'SubroutineCall'}{'Args'};
                $line=~s/call\s.*$//;
                my $rline = "call $name($orig_args_str $global_args_str)\n";
                push @{$rlines}, [ $line.$rline, $tags_lref ];
                $skip=1;
            }
            push @{$rlines}, $annline unless $skip;
        }
    }
    $annlines = $rlines;
    $rlines   = []; 
    
    if ( $stref->{'Subroutines'}{$f}{'HasBlocks'} == 1 ) {
    	my @blocks=();
        my $name='NONE'; 
        for my $annline ( @{$annlines} ) {
            my $line = $annline->[0];
#           print "$line\n";
            my $tags_lref = $annline->[1];
            my %tags = ( defined $tags_lref ) ? %{$tags_lref} : ( 'Nil' => [] );
            my $skip = 0;
            
            if ( exists $tags{'RefactoredSubroutineCall'} ) {
                $name = $tags{'RefactoredSubroutineCall'}{'Name'};
                push @blocks,$name;
                my @args =
                  @{ $stref->{'Subroutines'}{$name}{'Args'} };
                my $rline =
                  '      call ' . $name . '(' . join( ',', @args ) . ')';
                delete $tags_lref->{'Comments'};
                push @{$rlines}, [ $rline, $tags_lref ];
                # Here we must emit the code for the new subroutine
                print STDERR "Create code for new subroutine $name!\n";             
                # The subroutine code has already been analysed but not refactored in terms of replacing commons in calls
                # The problem is that there is no Info, so the best thing to do seems to generate a source file with
                # the includes of the parent and parse that 
                # I see now that to figure out which globals to turn into locals, we need to know which globals
                # are used in each subroutine called. So we need to propagate 'Globals' upwards, unless the subroutine
                # is the root for the globals; but that means we need to separate the globals per include                
                $skip = 1;
            }
            if ( exists $tags{'InBlock'} or exists $tags{'EndBlock'} ) {                
                if ($name ne 'NONE') {
                    push @{ $stref->{'Subroutines'}{$name}{'Info'} },$tags_lref ;
                }               
                $skip=1;
#               if( exists $tags{'EndBlock'} and $name ne 'NONE') {
#                   die Dumper($stref->{'Subroutines'}{$name});
#               }
            }
            push @{$rlines}, $annline unless $skip;
        }       
    
	    for my $name (@blocks) {
	        $stref=create_subroutine_source($name,$stref);
	        # Now we must parse this source
	        local $V=1;     
	        $stref = get_var_decls( $name, $stref );
	        $stref = detect_blocks( $name, $stref );
	        $stref = parse_includes( $name, $stref );      
	        $stref = parse_subroutine_calls( $name, $stref );      
	        $stref = identify_globals_used_in_subroutine( $name, $stref );     
	        # Now we're ready to refactor this source
	        $stref = refactor_code($name,$stref); # shiver!
	    }
    } # HasBlocks
    $annlines = $rlines;
    $rlines   = [];
    for my $annline ( @{$annlines} ) {
        my $line      = $annline->[0] || ''; # FIXME: why would line be undefined?
        my $tags_lref = $annline->[1];
        my %tags      = %{$tags_lref};
        if ( not exists $tags{'Comments'} ) {
            print $line,"\n";
            my @split_lines = split_long_line($line);
            for my $sline (@split_lines) {      
                push @{ $stref->{'Subroutines'}{$f}{'RefactoredCode'} }, $sline;
            }
        } else {            
            push @{ $stref->{'Subroutines'}{$f}{'RefactoredCode'} }, $line;
        }
    }

    return $stref;
} # END Of refactor_code()
# -----------------------------------------------------------------------------
sub refactor_all {
	( my $stref ) = @_;
	for my $f ( keys %{ $stref->{'Subroutines'} } ) {
	   $stref = refactor_code($f,$stref);
    }
	return $stref;
} # END Of refactor_all()
# -----------------------------------------------------------------------------
sub emit_refactored_code { (my $stateref)=@_;
	
} # END of emit_refactored_code()
# -----------------------------------------------------------------------------


sub parse_subroutine_calls {
	( my $f, my $stref ) = @_;
	           print "PARSING SUBROUTINE CALLS in $f\n";
	my $srcref = $stref->{'Subroutines'}{$f}{'Lines'};
	if ( defined $srcref ) {
		my %child_include_count=();
		my %called_subs=();
		for my $index ( 0 .. scalar( @{$srcref} ) - 1 ) {
			my $line = $srcref->[$index];
			next if  $line =~ /^C\s+/ ;
			print "<$line>\n";
			if ( $line =~ /call\s(\w+)\((.*)\)/ ) { 	
				my $name   = $1;
				my $argstr = $2;
				$called_subs{$name}=$name; 
                $stref->{'Subroutines'}{$f}{'Info'}->[$index]{'SubroutineCall'}{'Args'}=$argstr;
                $stref->{'Subroutines'}{$f}{'Info'}->[$index]{'SubroutineCall'}{'Name'}=$name;
				if (
					 $stref->{'Subroutines'}{$name}{'Status'}==0
				  )
				{
					print "\tCALL $name\n";
					
#					print "Processing SUBROUTINE $name\n" if $V;
					$stref = parse_fortran_src( $name, $stref );
#					$stref->{'Subroutines'}{$name}{'Status'}=2;
                    
                    for my $inc ( keys %{ $stref->{'Subroutines'}{$name}{'Includes'} } ) {
                        if ( $stref->{'Includes'}{$inc}{'Type'} eq 'Common') {
                    	   $child_include_count{$f}{$inc}++;
#                    	   print $child_include_count{$f}{$inc};
#                    	   print '<>',join(',',keys %{ $stref->{'Subroutines'}{$f}{'Includes'} })," in $f\n";
                        }
                    }
                                                           
				}
			}
		}
		print "ANALYZING called subs in $f\n";
		my %globs=();		
		my @child_is_root=();
		for my $inc (keys %{$child_include_count{$f}}) {
			if (not exists $stref->{'Subroutines'}{$f}{'Includes'}{$inc}) {
				 if ($child_include_count{$f}{$inc}==1 ) {
					push @child_is_root,$inc;					
				} elsif ($child_include_count{$f}{$inc}>1) {
	                print "INFO: $inc occurs in more than one child, not present in parent => make parent $f root\n";
	                $stref->{'Includes'}{$inc}{'Root'}=$f;
	                $stref->{'Subroutines'}{$f}{'Includes'}{$inc}=-1;
	           }
			}
		}
		
	    for my $name (keys %called_subs) {	    	
	    	my $root_inc='';                      
            for my $inc (@child_is_root) {            	
                if (exists $stref->{'Subroutines'}{$name}{'Includes'}{$inc}) {
                	$stref->{'Includes'}{$inc}{'Root'}=$name;
                	$root_inc=$inc;
                    print "INFO: $name is root for $inc\n";                    
                }
            }
            for my $inc (keys %{ $stref->{'Subroutines'}{$name}{'Globals'} }) {
            	next if $inc eq $root_inc;            
                $globs{$inc}=union($globs{$inc}, $stref->{'Subroutines'}{$name}{'Globals'}{$inc});                
	       }                       
        }
#        print Dumper($stref->{'Subroutines'}{$f});
		for my $inc (keys %{ $stref->{'Subroutines'}{$f}{'Includes'} }) {
			print "INFO: $inc in $f\n";
			next unless $stref->{'Includes'}{$inc}{'Type'} eq 'Common';
			if (exists $stref->{'Subroutines'}{$f}{'Globals'}{$inc}) {
			     $stref->{'Subroutines'}{$f}{'Globals'}{$inc}=union($stref->{'Subroutines'}{$f}{'Globals'}{$inc},$globs{$inc});
			} else {
				$stref->{'Subroutines'}{$f}{'Globals'}{$inc}=$globs{$inc};
			}
		}
#		die Dumper($stref->{'Subroutines'}{$f}{'Globals'}) if $f eq 'timemanager'; 
	}
	return $stref;
} # END of parse_subroutine_calls()
# -----------------------------------------------------------------------------
# Identify which globals from the includes are used in the subroutine 
sub identify_globals_used_in_subroutine {
	( my $f, my $stref ) = @_;
	local $V=0;
	my $srcref = $stref->{'Subroutines'}{$f}{'Lines'};
	if ( defined $srcref ) {
		my %commons=();
		if (not exists $stref->{'Subroutines'}{$f}{'Commons'} ) {
			for my $i ( keys %{ $stref->{'Subroutines'}{$f}{'Includes'} } ) {
	            if ( $stref->{'Includes'}{$i}{'Type'} eq 'Common' ) {
	            	$commons{$i}= $stref->{'Includes'}{$i}{'Commons'};
	            }
			}					
			$stref->{'Subroutines'}{$f}{'Commons'}=\%commons;
			$stref->{'Subroutines'}{$f}{'HasCommons'}=1;
		} else {
			%commons=%{ $stref->{'Subroutines'}{$f}{'Commons'} };
		}
		
		for my $inc (keys %commons) {
			print "GLOBAL VAR ANALYSIS for $inc in $f\n";
			my @inherited_globs = (defined $stref->{'Subroutines'}{$f}{'Globals'}{$inc}) ? @{ $stref->{'Subroutines'}{$f}{'Globals'}{$inc} } : ();
			my @globs = ();
		my @tvars = keys %{ $commons{$inc} };
		
		if ($V) {
			for my $global ( @tvars ) {
				print "$global\n";
			}
		}
		for my $index ( 0 .. scalar( @{$srcref} ) - 1 ) {
			my $line = $srcref->[$index];
			if ( $line =~ /^C\s+/ ) {
				next;
			}
			if ( $line =~ /^\s+subroutine\s+(\w+)\((.*)\)/ ) {
				my $name   = $1;
				my $argstr = $2;
				my @args   = split( /\s*,\s*/, $argstr );

#				$stref->{'Subroutines'}{$f}{'Nodes'}{'Signature'}{'Args'} =
#				  \@args;
#				$stref->{'Subroutines'}{$f}{'Nodes'}{'Signature'}{'Name'} =
#				  $name;
#				push
#				  @{ $stref->{'Subroutines'}{$f}{'Nodes'}{'Signature'}{'Pos'} },
#				  $index;
				  $stref->{'Subroutines'}{$f}{'Info'}->[$index]{'Signature'}{'Args'}=\@args;
				  $stref->{'Subroutines'}{$f}{'Info'}->[$index]{'Signature'}{'Name'}=$name;
			}
			for my $var ( @tvars ) {
				next if not defined $var;
				if ( $line =~ /\W$var\W/ ) {
					print "FOUND $var in $line\n" if $V;
					push @globs, $var;
					undef $var;
				}
			}
		}
		@globs=@{ union(\@globs,\@inherited_globs)  };
		if ($V) {
			print "\nCOMMON VARS from $inc in subroutine $f:\n\n";
			for my $var (@globs) {
				print "$var\n";
			}
		}
		$stref->{'Subroutines'}{$f}{'Globals'}{$inc} =
		  \@globs;		 
		}
	}	
	return $stref;
} # END of identify_globals_used_in_subroutine()
# -----------------------------------------------------------------------------
sub detect_blocks {
	( my $s, my $stref ) = @_;
    my $srcref = $stref->{'Subroutines'}{$s}{'Lines'};
    if ( defined $srcref ) {
        my $has_blocks = 0;    
        for my $index ( 0 .. scalar( @{$srcref} ) - 1 ) {
            my $line = $srcref->[$index];        
            $stref->{'Subroutines'}{$s}{'Info'}->[$index]={};
            if ( $line =~ /^C\s/i ) {
              $stref->{'Subroutines'}{$s}{'Info'}->[$index]{'Comments'}={};            
                if ( $line =~ /C\s+BEGIN\sSUBROUTINE\s\w+/ ) {
                    $has_blocks = 1;
                }
                print "$line\n" if $V;
                next;
            }
            if ( $line =~ /^\!\s/ ) {
              $stref->{'Subroutines'}{$s}{'Info'}->[$index]{'TrailingComments'}={};
                print "$line\n" if $V;
                next;
            }
            print "$line\n" if $V;
        }
        $stref->{'Subroutines'}{$s}{'HasBlocks'} = $has_blocks;
    }
    return $stref;
} # END of detect_blocks()
# -----------------------------------------------------------------------------
sub create_subroutine_source {
    ( my $f, my $stref ) = @_;
    my $srcref = $stref->{'Subroutines'}{$f}{'Lines'};
    if ( defined $srcref ) {
    
	    my @lines    = @{ $stref->{'Subroutines'}{$f}{'Lines'} };
#	    my @info     = @{ $stref->{'Subroutines'}{$f}{'Info'} };
#	    my $annlines = [];
	    
	    my $rlines = [$stref->{'Subroutines'}{$f}{'Sig'}];
	    for my $inc (keys %{$stref->{'Subroutines'}{$f}{'Includes'} } ) {
            push @{$rlines}, "        include '$inc'" ;
        }
	    for my $decl (@{$stref->{'Subroutines'}{$f}{'Decls'} } ) {
	    	push @{$rlines}, "  $decl";
	    }           
        for my $line (@lines) {     
           push @{$rlines},  $line;
        }
        push @{$rlines},'      end';
        $stref->{'Subroutines'}{$f}{'Lines'} =$rlines;
        $stref->{'Subroutines'}{$f}{'Info'} =[];
        $stref->{'Subroutines'}{$f}{'Status'}=1;
        delete $stref->{'Subroutines'}{$f}{'Decls'};
        delete $stref->{'Subroutines'}{$f}{'Sig'};
        delete $stref->{'Subroutines'}{$f}{'Args'};
    }     
    return $stref;
} # END of create_subroutine_source()
# -----------------------------------------------------------------------------
        
sub parse_includes {
	( my $f, my $stref ) = @_;
	my $srcref = $stref->{'Subroutines'}{$f}{'Lines'};
	if ( defined $srcref ) {
		for my $index ( 0 .. scalar( @{$srcref} ) - 1 ) {
			my $line = $srcref->[$index];
			if ( $line =~ /^C\s+/ ) {
				next;
			}

			if ( $line =~ /^\s*include\s+\'(\w+)\'/ )
			{    # TODO: nested includes not supported!

				my $name = $1;
				$stref->{'Subroutines'}{$f}{'Includes'}{$name}=$index;
                $stref->{'Subroutines'}{$f}{'Info'}->[$index]{'Include'}{'Name'}=$name;
				if ( $stref->{'Includes'}{$name}{'Status'} == 0 ) {
					#				$line = 'C ' . $line;
					print $line, "\n" if $V;
					# Initial guess for Root
					$stref->{'Includes'}{$name}{'Root'} = $f;
					$stref = parse_fortran_src( $name, $stref );
				}
				else {
					print $line, " already processed\n" if $V;
				}

			}
		}
	}
	return $stref;
} # END of parse_includes()
# -----------------------------------------------------------------------------

sub get_var_decls {
	( my $f, my $stref ) = @_;
	
    my $is_incl = exists $stref->{'Includes'}{$f} ? 1 : 0;
    my $sub_or_incl = $is_incl ? 'Includes' : 'Subroutines';
#    my $f = $is_incl ? $s : $stref->{'Subroutines'}{$s}{'Source'};
	
	my $srcref = $stref->{$sub_or_incl}{$f}{'Lines'};
	if ( defined $srcref ) {
		print "\n VAR DECLS in $f:\n" if $V;
		my %vars  = ();
		my $first = 1;
		for my $index ( 0 .. scalar( @{$srcref} ) - 1 ) {
			my $line = $srcref->[$index];

			if ( $line =~ /^C\s+/ ) {
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
#print $line,"\n";
				if ( $tvarlst =~ /\(((?:[^\(\),]*?,)+[^\(]*?)\)/ ) {
					while ( $tvarlst =~ /\(((?:[^\(\),]*?,)+[^\(]*?)\)/ ) {
						my $chunk  = $1;
						my $chunkr = $chunk;
						$chunkr =~ s/,/;/g;
						my $pos = index( $tvarlst, $chunk );
						substr( $tvarlst, $pos, length($chunk), $chunkr );

						#	print "FOUND $line:\n$chunk\t$chunkr\n$tvarlst\n";
					}
				}

 #			$tvarlst =~ s/\(([^\(\),]*?),([^\(]*?)\)/($1;$2)/g && print $tvarlst ,"\n";
				my @tvars = split( /\s*\,\s*/, $tvarlst );
				my $p = '';
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
					}
					else {
						$vars{$tvar}{'Kind'} = 'Scalar';
					}
					$vars{$tvar}{'Type'} = $type;
					$var =~ s/;/,/g;
					$vars{$tvar}{'Decl'} = "      $type $var"
					  ; # TODO: this should maybe not be a textual representation
					print $type, $p, "\t<", $tvar, ">: $var\n" if $V;
				}

			  $stref->{'Subroutines'}{$f}{'Info'}->[$index]{'VarDecl'}={};
				if ($first) {
					$first = 0;
					  $stref->{'Subroutines'}{$f}{'Info'}->[$index]{'ExGlobVarDecls'}={};
				}
			}

		}

		$stref->{$sub_or_incl}{$f}{'Vars'} =  \%vars;    
	}
	return $stref;
} # END of get_var_decls()
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
						print "MISSING: <", $var, ">\n";
					}
					else {
						print $var, "\t", $vars{$var}{'Type'}, "\n" if $V;
						$stref->{'Includes'}{$f}{'Commons'}{$var} = $vars{$var};
					}
				}
#				push
#				  @{ $stref->{'Includes'}{$f}{'Nodes'}{'Common'}{$f}{'Pos'} },
#				  $index;    # FIXME: rm $f
				  $stref->{'Includes'}{$f}{'Info'}->[$index]{'Common'}={ },
			}

			if ( $line =~ /parameter\s*\(\s*(.*)\s*\)/ ) {
				my $parliststr = $1;
				$has_pars = 1;
				my @partups = split( /\s*,\s*/, $parliststr );
				my @pvars = map { s/\s*=.+//; $_ } @partups;

				for my $var (@pvars) {
					if ( not defined $vars{$var} ) {
						print "NOT A PARAMETER: <", $var, ">\n";
					}
					else {

		#                    print $var, "\t",  $vars{$var}{'Type'}, "\n" if $V;
						$stref->{'Includes'}{$f}{'Parameters'}{$var} = $vars{$var};
					}
				}
#				push @{ $stref->{'Includes'}{$f}{'Nodes'}{'Parameter'}{$f}
#					  {'Pos'} }, $index;    # FIXME: rm $f
					  $stref->{'Includes'}{$f}{'Info'}->[$index]{'Parameter'}={ },

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
		}
		elsif ($has_commons) {
			$stref->{'Includes'}{$f}{'Type'} = 'Common';
		}
		elsif ($has_pars) {
			$stref->{'Includes'}{$f}{'Type'} = 'Parameter';
		}
		else {
			$stref->{'Includes'}{$f}{'Type'} = 'None';
		}
		for my $var ( keys %vars ) {
			if (   ( $has_pars and not exists( $stref->{'Includes'}{$f}{'Parameters'}{$var} ) )
				or ( $has_commons and not exists( $stref->{'Includes'}{$f}{'Commons'}{$var} ) )
			  )
			{
				die
"The include $f contains a variable $var that is neither a parameter nor a common variable, this is not supported\n";
			}
		}
	}
	return $stref;
} # END of get_commons_params_from_includes()
# -----------------------------------------------------------------------------

sub separate_blocks {
	( my $f, my $stref ) = @_;
    local $V=0;
	my $srcref = $stref->{'Subroutines'}{$f}{'Lines'};
	my %vars   = %{ $stref->{'Subroutines'}{$f}{'Vars'} };
	my %occs   = ();
	my %blocks   = ();
	my $in_block = 0;
	my $block    = 'OUTER';
	for my $index ( 0 .. scalar( @{$srcref} ) - 1 ) {
		my $line = $srcref->[$index];

		if ( $line =~ /^C\s+BEGIN\sSUBROUTINE\s(\w+)/ ) {
			$in_block = 1;
			$block    = $1;
			push @{ $blocks{'OUTER'} }, $line;
			  $stref->{'Subroutines'}{$f}{'Info'}->[$index]{'RefactoredSubroutineCall'}{'Name'} =$block;
			  $stref->{'Subroutines'}{$f}{'Info'}->[$index]{'BeginBlock'}{'Name'} =$block;
			next;
		}
		if ( $line =~ /^C\s+END\sSUBROUTINE\s(\w+)/ ) {
			$in_block = 0;
			$block    = $1;
			push @{ $blocks{$block} }, $line;
			  $stref->{'Subroutines'}{$f}{'Info'}->[$index]{'EndBlock'}{'Name'} =$block;
			next;
		}
		if ($in_block) {
			push @{ $blocks{$block} }, $line;
			  $stref->{'Subroutines'}{$f}{'Info'}->[$index]{'InBlock'}{'Name'} =$block;
		}
		else {
			push @{ $blocks{'OUTER'} }, $line;
		}
	}

	for my $block ( keys %blocks ) {
		next if $block eq 'OUTER';
        $stref->{'Subroutines'}{$f}{'Blocks'}{$block}{'Lines'} = $blocks{$block};
        $stref->{'Subroutines'}{$f}{'Blocks'}{$block}{'Source'} = $stref->{'Subroutines'}{$f}{'Source'};
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
		for my $line (@lines) {
			for my $var ( keys %tvars ) {
				if ( $line =~ /\W$var\W/ ) {
					print "$var\n" if $V;
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
		
        print "\nARGS for $block:\n" if $V;
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
			my $decl=$vars{$argv}{'Decl'} ;#|| $commons{$argv}{'Decl'};
			push @{$decls},$decl;			
		}
		$sig =~ s/\,$/)\n/s;
		$stref->{'Subroutines'}{$f}{'Blocks'}{$block}{'Args'}  = $args{$block};
		$stref->{'Subroutines'}{$f}{'Blocks'}{$block}{'Sig'}   = $sig;
		$stref->{'Subroutines'}{$f}{'Blocks'}{$block}{'Decls'} = $decls;
#        $stref->{'Subroutines'}{$f}{'Blocks'}{$block}{'Lines'} = $blocks{$block};
#        $stref->{'Subroutines'}{$f}{'Blocks'}{$block}{'Source'} = $stref->{'Subroutines'}{$f}{'Source'};
        for my $inc (keys %{$stref->{'Subroutines'}{$f}{'Includes'}}) {
        	if($stref->{'Subroutines'}{$f}{'Includes'}{$inc}!=-1) {
		      $stref->{'Subroutines'}{$f}{'Blocks'}{$block}{'Includes'}{$inc} = -2;
        	}
        }
		if ($V) {
		print $sig,"\n";
		print join("|n",@{$decls}),"\n";
		}		
	}
	return $stref;
} # END of separate_blocks()
# -----------------------------------------------------------------------------
sub identify_loops_breaks {
    ( my $f, my $stref ) = @_;
    local $V=0;
    my $srcref = $stref->{'Subroutines'}{$f}{'Lines'};
    
    my %do_loops=();
    my %gotos=();
    my $nest=0;
    for my $index ( 0 .. scalar( @{$srcref} ) - 1 ) {
        my $line = $srcref->[$index];
        next if $line =~ /^C\s+/;
# BeginDo: 
        $line=~/^\s+do\s+(\d+)\s+\w/ && do {
        	my $label=$1;
        	$stref->{'Subroutines'}{$f}{'Info'}->[$index]{'BeginDo'}{'Label'} =$label;
        	if (not exists $do_loops{$label} ) {  
        	   @{$do_loops{$label}}=([$index],$nest);
        	   $nest++;
        	} else {        		
        		push @{ $do_loops{$label}[0] },$index;
#        		print STDERR "WARNING: $f: Found duplicate label $label at: ".join(',',@{ $do_loops{$label}[0] })."\n";
        	}
        	next;
        };
# Goto        
        $line=~/^\s+.*\s+goto\s+(\d+)\s*$/ && do {
            my $label=$1;
            $stref->{'Subroutines'}{$f}{'Info'}->[$index]{'Goto'}{'Label'} =$label;
            @{$gotos{$label}}=($index,$nest);            
            next;
        };
        
# continue can be end of do loop or break target (amongs others?)
        $line=~/^\s{0,4}(\d+)\s+(continue|\w+)/ && do {
        	my $label=$1;
        	my $is_cont = $2 eq 'continue' ? 1 : 0 ;
            if (exists $do_loops{$label} ) {
            	if ($nest==$do_loops{$label}[1]+1) {            
                    $stref->{'Subroutines'}{$f}{'Info'}->[$index]{'EndDo'}{'Label'} =$label;
                    $stref->{'Subroutines'}{$f}{'Info'}->[$index]{'EndDo'}{'Count'} = scalar @{ $do_loops{$label}[0] };
                    delete $do_loops{$label};
                    $nest--;        	
            	} else {
            		print STDERR "WARNING: $f: Found continue for label $label but nesting level is wrong: $nest<>$do_loops{$label}[1]\n";
            	}
            } elsif (exists $gotos{$label}) {                
                	my $target = 'GotoTarget';
                	if ($nest<=$gotos{$label}[1]) {                                
                    if ($is_cont ) {             
                    	$target = 'NoopBreakTarget';       
                        $stref->{'Subroutines'}{$f}{'Info'}->[$gotos{$label}[0]]{'Break'}{'Label'} =$label;
                    } else {
                    	$target = 'BreakTarget';                    	
                    	$stref->{'Subroutines'}{$f}{'Info'}->[$gotos{$label}[0]]{'Break'}{'Label'} =$label;
#                    	print STDERR "WARNING: $f: Found BREAK target not NOOP for label $label\n";                    	
                    }
                	} else {
                		print STDERR "WARNING: $f: Found GOTO target not BREAK for label $label: wrong nesting $nest<>$gotos{$label}[1]\n";
                	}
                    $stref->{'Subroutines'}{$f}{'Info'}->[$index]{$target}{'Label'} =$label;
                    delete $gotos{$label};                            
            	
            }
            next;
        };
    }
	return $stref;
} # END of identify_loops_breaks()
# -----------------------------------------------------------------------------
# This subroutine reads the FORTRAN source and does very little else:
# - it combines continuation lines in a single line
# - it lowercases everything
# - it detects and normalises comments
# - it detects block markers (for factoring blocks out into subs)
# The routine is called by parse_fortran_src()
sub read_fortran_src {
	( my $s, my $stref ) = @_;

	my $is_incl = exists $stref->{'Includes'}{$s} ? 1 : 0;
	my $sub_or_incl = $is_incl ? 'Includes' : 'Subroutines';
	my $f = $is_incl ? $s : $stref->{'Subroutines'}{$s}{'Source'};

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
		my $cont   = 0;
		my $sub_ok = 0;
		my $line   = '';
		while (<$SRC>) {
			$line = $_;
			chomp $line;

			# Skip blanks
			$line =~ /^\s*$/ && next;

			# Detect and standardise comments
			if ( $line =~ /^[C\*\!]/i ) {
				$line =~ s/^[Cc\*\!]/C /;
			}
			elsif ( $line =~ /\s+\!.*$/ ) {
				# convert trailing comments into comments on the previous line
				( $line, my $comment ) = split( /\s+\!/, $line );
			}

  # If it's a subroutine source, skip all lines before the matching subroutine signature
  #and all lines from (and including) the next non-matching subroutine signature
        if ($is_incl==0) { 
			if ( $line !~ /^C/ and $line =~ /subroutine\s+/i ) {
				$sub_ok = 0;
				if ( $line =~ /subroutine\s+$s/i ) {
					$sub_ok = 1;
				}
			}
			next unless $sub_ok;
        }
			if ( $line =~ /^\s{5}[^0\s]/ ) {    # continuation line
				$line =~ s/^\s{5}.\s*/ /;
				$prevline .= $line;
				$cont = 1;
			}
			elsif ( $line =~ /^\&/ ) {
				$line =~ s/^\&\t*/ /;
				$prevline .= $line;
				$cont = 1;
			}
			elsif ( $line =~ /^\t[1-9]/ ) {
				$line =~ s/^\t[0-9]/ /;
				$prevline .= $line;
				$cont = 1;
			}
			elsif ( $prevline =~ /\&\s&$/ ) {
				$prevline =~ s/\&\s&$//;
				$prevline .= $line;
				$cont = 1;
			}
			elsif ( $line =~ /^C\ / && ( $cont == 1 ) ) {

				# A comment occuring after a continuation line. Skip!
				next;
			}
			else {
				my $lcprevline =
				  ( substr( $prevline, 0, 2 ) eq 'C ' )
				  ? $prevline
				  : lc($prevline);
				push @{$lines}, $lcprevline;
				$prevline = $line;
				$cont     = 0;
			}
		}
		if ( $line ne $prevline ) {
			my $lcprevline =
			  ( substr( $prevline, 0, 2 ) eq 'C ' ) ? $prevline : lc($prevline);
			push @{$lines}, $lcprevline;
		}
		my $lcline = ( substr( $line, 0, 2 ) eq 'C ' ) ? $line : lc($line);
		push @{$lines}, $lcline;
		close $SRC;
		
 		$stref->{$sub_or_incl}{$s}{'Status'}    = 1;
		$stref->{$sub_or_incl}{$s}{'Lines'}     = $lines;
	}

	return $stref;
} # END of read_fortran_src()
# -----------------------------------------------------------------------------
# Find all source files in the current directory
sub find_subroutines_and_includes {
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
            $line =~ /^\s+subroutine\s+(\w+)/i && do {
                my $sub = lc($1);
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
                        print "WARNING: Ignoring source "
                          . $stref->{'Subroutines'}{$sub}{'Source'}
                          . " because source $src matches subroutine name $sub.\n";
                    }
                    $stref->{'Subroutines'}{$sub}{'Source'} = $src;
                    $stref->{'Subroutines'}{$sub}{'Status'} = 0;
                }
                else {
                    print
"WARNING: Ignoring source $src for $sub because another source, "
                      . $stref->{'Subroutines'}{$sub}{'Source'}
                      . " exists.\n";
                }
            };
             $line =~ /^\s*include\s+\'(\w+)\'/ && do {
             	my $inc=$1;
             	if (not exists $stref->{'Includes'}{$inc}) {
             		 $stref->{'Includes'}{$inc}{'Status'}=0;
             	}
             };
            
        }
        close $SRC;
    }
    return $stref;
} # END of find_subroutines_and_includes()

# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
sub show_info {
    if ($V) {
        print "\n\n";
        print "#" x 80, "\n";
        print "Info\n";
        print "#" x 80, "\n\n";
    }
    ( my $stref ) = @_;

    for my $f ( keys %{ $stref->{'Subroutines'} } ) {
        
        if ( exists $stref->{'Subroutines'}{$f}{'Lines'} and exists $stref->{'Subroutines'}{$f}{'Info'}) {
            print "\nSUBROUTINE: $f\n\n";
#           die Dumper($stref->{'Subroutines'}{$f}{'Info'});
            my @lines = @{ $stref->{'Subroutines'}{$f}{'Lines'} };
            my @info  = @{ $stref->{'Subroutines'}{$f}{'Info'} };
            if ( scalar(@lines) != scalar(@info) ) {
                die scalar(@lines) . '!=' . scalar(@info) . " for $f";
            }
            else {

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
} # END of insert_lines()
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
		$nchars = 72;
	}
	my $split_on  = ',';
	my $split_on2 = ' ';

	if ( length($line) > $nchars ) {
		my $ll    = length($line);
		my $rline = join( '', reverse( split( '', $line ) ) );
		my $idx   = index( $rline, $split_on, $ll - $nchars );
		my $idx2  = index( $rline, $split_on2, $ll - $nchars );
		if ( $idx < 0 && $idx2 < 0 ) {
			die "Could not split line $line";
		}
		elsif ( $idx < 0 && $idx2 >= 0 ) {
			$idx = $idx2;
		}
		push @chunks, substr( $line, 0, $ll - $idx, '' );
		&split_long_line( $line, @chunks );
	}
	else {
		push @chunks, $line;
		my @split_lines = ();
		if ( @chunks > 1 ) {
			my $fst = 1;
			for my $chunk (@chunks) {
				if ($fst) {
					$fst = 0;
				}
				else {
					if ( $chunk =~ /^\s*$/ ) {
						$chunk = '';
					}
					else {
						$chunk = '     &  ' . $chunk;
					}
				}
				push @split_lines, $chunk;
			}
		}
		else {
			@split_lines = @chunks;
		}
		return @split_lines;
	}
}
# -----------------------------------------------------------------------------
sub union {
	(my $aref, my $bref) =@_;
	my %a = map { $_ => 1 } @{ $aref };
	for my $elt (@{ $bref} ) {
		  $a{$elt}=1;
	}
	my @u=sort keys %a;
	return \@u;
} # END of union()
# -----------------------------------------------------------------------------