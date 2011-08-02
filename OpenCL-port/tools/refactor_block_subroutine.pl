#!/usr/bin/perl
use warnings;
use strict;

=todos
One of the assumptions is that there is a single subroutine per file and that the names match
This is not always the case. Obviously, as soon as there is more than one sub per file, the names can't match.
So we must split out the subroutines to meet the convention, best to do this in a pre-processing step.
Alternatively, we could create a map of file=>[subs], that might actually be better

BUGS:
- there are duplicates between the original var decls and the ex-globals: ix, jy; but they are not globals!
CAUSE: the "common" variables are not fully global and I should not put them all in one big namespace.
Basically, we need to store the commons per include, and only use the union of the commons in all include files that
are of InclType = Common 

- nspec from includecom is not transformed into an argument -> TODO
Now we have the includes separated out, we need to treat the "common" variables on a per-include basis
Also, for the root, we do need the include of the common vars.

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

We need a lookup table between sources and subroutines, so that we can descend into the right file. $sub => $source
So I guess we change 'Sources' to 'Subroutines' with a field 'Source'

とにかく, コード　は:

=cut

use Data::Dumper;
use File::Find;

our $V = 1;

die "Please specifiy FORTRAN subroutine to refactor\n" if not @ARGV;
my $subname = $ARGV[0];

my $stateref = {
	'Includes'   => {},
	    # $name => {Root =>$source, Type => Common | Param | Both,'Commons'    => {},    'Parameters' => {},    }
	'Subroutines' => {

		#		 for every file, a list of the source lines.
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
		#		    ...
		#		  }

	},
	'RefactoredSources' => {},
};

# First we analyse the code for use of globals and blocks to be transformed into subroutines
$stateref = find_subroutines($stateref);
$stateref = parse_fortran_src( $subname, $stateref );

# Then we create an "inverted index" of the information we have gathered, by line of the orginal source.
# One important point is that we must mark all blocks to be refactored as such, so those lines can be skipped!

$stateref = get_info_per_line($stateref);

#show_info($stateref);

# Refactor the source
$stateref = refactor_code($stateref);

# Emit the refactored source

exit(0);

sub parse_fortran_src {
	( my $f, my $stref ) = @_;

	$stref = read_fortran_src( $f, $stref );

	my $is_incl = exists $stref->{'Includes'}{$f} ? 1 : 0;
	my $has_blocks = $stref->{'Subroutines'}{$f}{'HasBlocks'};

	#    $stref = mark_comments( $f, $stref );

	# 2. Parse the type declarations in the source, create a table %vars

	$stref = get_var_decls( $f, $stref );

	# 3. Parse includes, recursively doing 0/1/2
	if ( not $is_incl ) {
		$stref = parse_includes( $f, $stref );
		$stref = parse_subroutine_calls( $f, $stref );
		$stref = remove_globals_from_subroutines( $f, $stref );
	}
	else {    # includes
		 # 4. For includes, parse common blocks and parameters, create $stref->{'Commons'}
		$stref = get_commons_params_from_includes( $f, $stref );
	}

	for my $i ( keys %{ $stref->{'Subroutines'}{$f}{'Nodes'}{'Include'} } ) {
		if ( $stref->{'Includes'}{$i}{'Type'} eq 'Common' ) {
			$stref->{'Subroutines'}{$f}{'HasCommons'} = 1;
			last;
		}
	}

# 5. Split the source based on the block markers
# As there could be several blocks (later), use a hash per block
# This could happen in any file except includes; but include processing never comes here
	if ($has_blocks) {
		$stref = refactor_blocks( $f, $stref );
	}

	return $stref;

}    # END of parse_fortran_src()

# =============================================================================

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
	if ($V) {
		print "\n\n";
		print "#" x 80, "\n";
		print "Refactoring\n";
		print "#" x 80, "\n\n";
	}
	( my $stref ) = @_;

	#FIXME: DEBUG ONLY!
	my $f = 'timemanager';

	#	for my $f ( keys %{ $stref->{'Subroutines'} } ) {
	print "\nSUBROUTINE: $f\n\n";
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
			if ( not defined $tags_lref ) { die "BOOM!" }
			my %tags = ( defined $tags_lref ) ? %{$tags_lref} : ( 'Nil' => [] );
			print '*** ' . join( ',', keys(%tags) ), "\n";
			print "$line\n";
			my $skip = 0;

			if ( exists $tags{'Signature'} ) {
				my $name = $tags{'Signature'}{'Name'};
				my @args = @{ $tags{'Signature'}{'Args'} };
				my @exglobs =
				  @{ $stref->{'Subroutines'}{$f}{'Nodes'}{'ExGlobVarDecls'}
					  {'Globals'} };
				my $rline =
				    '      subroutine ' 
				  . $name . '('
				  . join( ',', ( @args, @exglobs ) ) . ')';
				$tags{'Refactored'} = 1;
				push @${rlines}, [ $rline, $tags_lref ];
				$skip = 1;
			}
			if ( exists $tags{'ExGlobVarDecls'} ) {
				for my $var ( @{ $tags{'ExGlobVarDecls'}{'Globals'} } ) {
					my $rline = $stref->{'Subroutines'}{$f}{'Commons'}{$var}{'Decl'};					
					push @{$rlines}, [ $rline, $tags_lref ];
				}
			}
			if ( exists $tags{'Include'} ) {
				( my $inc, my $r ) = each %{ $tags{'Include'} };
				if ( $stref->{'Includes'}{$inc}{'Type'} eq 'Common' ) {
					$skip = 1;
				}
			}
			push @{$rlines}, $annline unless $skip;
		}
	}
	$annlines = $rlines;
	$rlines   = [];

	if ( $stref->{'Subroutines'}{$f}{'HasBlocks'} == 1 ) {
		for my $annline ( @{$annlines} ) {
			my $line = $annline->[0];
			print "$line\n";
			my $tags_lref = $annline->[1];
			my %tags = ( defined $tags_lref ) ? %{$tags_lref} : ( 'Nil' => [] );
			my $skip = 0;

			if ( exists $tags{'RefactoredSubroutineCall'} ) {
				my $name = $tags{'RefactoredSubroutineCall'}{'Name'};
				my @args =
				  @{ $stref->{'Subroutines'}{$f}{'Blocks'}{$name}{'Args'} };

#                        my @exglobs = @{ $stref->{'Sources'}{$f}{'Nodes'}{'ExGlobVarDecls'}{'Globals'} };
				my $rline =
				  '      call ' . $name . '(' . join( ',', @args ) . ')';
				delete $tags_lref->{'Comments'};
				push @{$rlines}, [ $rline, $tags_lref ];
				$skip = 1;
			}
			push @{$rlines}, $annline unless $skip;
		}
	}
	$annlines = $rlines;
	$rlines   = [];
	for my $annline ( @{$annlines} ) {
		my $line      = $annline->[0];
		my $tags_lref = $annline->[1];
		my %tags      = %{$tags_lref};
		if ( not exists $tags{'Comments'} ) {

			#                	print "ORIG: $line\n";
			my @split_lines = split_long_line($line);
			for my $sline (@split_lines) {
				print "$sline\n";
			}
		}
		else {

			#                	print "$line\n";
		}
	}
	die;

	#	}
	return $stref;
}

sub show_info {
	if ($V) {
		print "\n\n";
		print "#" x 80, "\n";
		print "Info\n";
		print "#" x 80, "\n\n";
	}
	( my $stref ) = @_;

	for my $f ( keys %{ $stref->{'Subroutines'} } ) {
		print "\nSUBROUTINE: $f\n\n";
		if ( exists $stref->{'Subroutines'}{$f}{'Lines'} ) {
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
			}
		}

	}

}

# =============================================================================
sub parse_subroutine_calls {
	( my $f, my $stref ) = @_;
	my $srcref = $stref->{'Subroutines'}{$f}{'Lines'};
	if ( defined $srcref ) {
		for my $index ( 0 .. scalar( @{$srcref} ) - 1 ) {
			my $line = $srcref->[$index];
			if ( $line =~ /^C\s+/ ) {
				next;
			}
			if ( $line =~ /call\s(\w+)\((.*)\)/ ) {

				#			print $line, "\n" if $V;
				my $name   = $1;
				my $argstr = $2;

# Not nice, but as we push the index and the args at the same time, it should be OK
				push @{ $stref->{'Subroutines'}{$f}{'Nodes'}{'SubroutineCall'}
					  {$name}{'Pos'} }, $index;
				push @{ $stref->{'Subroutines'}{$f}{'Nodes'}{'SubroutineCall'}
					  {$name}{'Args'} }, $argstr;

				if (
					not exists $stref->{'Subroutines'}{$name}

					#				or not exists $stref->{'Subroutines'}{$name}{'IsSub'}
				  )
				{

					#				$stref->{'Subroutines'}{$name}{'IsIncl'} = 0;
					#				$stref->{'Subroutines'}{$name}{'IsSub'}  = 1;
					print "Processing SUBROUTINE $name\n";
					$stref = parse_fortran_src( $name, $stref );
				}

				#			else {
				#				print "DIED in $f, $name call\n";
				#				die Dumper($stref->{'Sources'}{$f});
				#			}
			}
		}
	}
	return $stref;
}

sub remove_globals_from_subroutines {

# we descend in the subroutine
# we resolve all globals
# so all we need to do really here is add a list of the used globals to the Node
# 7. Identify which commons are used in inner, make them function arguments
# This is almost the same as above
	( my $f, my $stref ) = @_;
	my $srcref = $stref->{'Subroutines'}{$f}{'Lines'};
	if ( defined $srcref ) {
		my @args_from_globs = ();

		#	my %tvars = %{ $stref->{'Commons'} };    # Hurray for pass-by-value!
		# 'Commons' depends on includes with Type = 'Common'.
		# So get the list of the Includes of Type Common in $f, and get the Commons for each of these includes
		
		my %commons=();
		if (not exists $stref->{'Subroutines'}{$f}{'Commons'} ) {
		for my $i ( keys %{ $stref->{'Subroutines'}{$f}{'Nodes'}{'Include'} } ) {
            if ( $stref->{'Includes'}{$i}{'Type'} eq 'Common' ) {
            	%commons=(%commons, %{ $stref->{'Includes'}{$i}{'Commons'} });
            }
		}
		$stref->{'Subroutines'}{$f}{'Commons'}=\%commons;
		} else {
			%commons=%{ $stref->{'Subroutines'}{$f}{'Commons'} };
		}
		my @tvars = keys %commons; #map { $_ => 1 } keys( %{ $stref->{'Commons'} } );
		print "GLOBAL VAR ANALYSIS in $f\n";
		for my $global ( @tvars ) {
			print "$global\n";
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

# FIXME: this assumes a single subroutine per file. So we should actually ensure that this is the case!
				$stref->{'Subroutines'}{$f}{'Nodes'}{'Signature'}{'Args'} =
				  \@args;
				$stref->{'Subroutines'}{$f}{'Nodes'}{'Signature'}{'Name'} =
				  $name;
				push
				  @{ $stref->{'Subroutines'}{$f}{'Nodes'}{'Signature'}{'Pos'} },
				  $index;
			}
			for my $var ( @tvars ) {
				next if not defined $var;
				if ( $line =~ /\W$var\W/ ) {
					print "FOUND $var in $line\n";
					push @args_from_globs, $var;
					undef $var;
				}
			}
		}
		if ($V) {
			print "\nCOMMON VARS in subroutine $f:\n\n";
			for my $var (@args_from_globs) {
				print "$var\n";
			}
		}
		$stref->{'Subroutines'}{$f}{'Nodes'}{'ExGlobVarDecls'}{'Globals'} =
		  \@args_from_globs;		 
	}
	return $stref;
}

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
				push @{ $stref->{'Subroutines'}{$f}{'Nodes'}{'Include'}{$name}
					  {'Pos'} },
				  $index;

				if ( not exists $stref->{'Includes'}{$name} ) {

					#				$line = 'C ' . $line;
					print $line, "\n" if $V;
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
}

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

				#			$tvarlst =~ s/\(.*?\)/(0)/g;    # clean up arrays
				#            $tvarlst =~ s/\(//;

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

				push
				  @{ $stref->{'Subroutines'}{$f}{'Nodes'}{'VarDecl'}{'Pos'} },
				  $index;
				if ($first) {
					$first = 0;
					push
					  @{ $stref->{'Subroutines'}{$f}{'Nodes'}{'ExGlobVarDecls'}
						  {'Pos'} },
					  $index;
				}
			}

		}

		$stref->{$sub_or_incl}{$f}{'Vars'} =  \%vars;    
	}
	return $stref;
}

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
				push
				  @{ $stref->{'Includes'}{$f}{'Nodes'}{'Common'}{$f}{'Pos'} },
				  $index;    # FIXME: rm $f
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
				push @{ $stref->{'Includes'}{$f}{'Nodes'}{'Parameter'}{$f}
					  {'Pos'} }, $index;    # FIXME: rm $f

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
}

sub refactor_blocks {
	( my $f, my $stref ) = @_;

	my $srcref = $stref->{'Subroutines'}{$f}{'Lines'};
	my %vars   = %{ $stref->{'Subroutines'}{$f}{'Vars'} };
	my %occs   = ();

	#        my %occs=%{$stref->{'Occs'}{$f}};
	my %blocks   = ();
	my $in_block = 0;
	my $block    = 'OUTER';
	for my $index ( 0 .. scalar( @{$srcref} ) - 1 ) {
		my $line = $srcref->[$index];

#		if ( $line =~ /^C\s+/ && $line !~ /^C\s+(BEGIN|END)/ ) {
#			next;
#		}
#		# skip subroutine decl
#		$line =~ /^\s+subroutine/ && next;
#		$line =~
#/(logical|integer|real|double\s+precision|character|character\*?(?:\d+|\(\*\)))\s+(.+)\s*$/
#		  && next;
		if ( $line =~ /^C\s+BEGIN\s+(\w+)/ ) {
			$in_block = 1;
			$block    = $1;
			push @{ $blocks{'OUTER'} }, $line;
			push @{ $stref->{'Subroutines'}{$f}{'Nodes'}
				  {'RefactoredSubroutineCall'}{'Pos'} }, $index;
			$stref->{'Subroutines'}{$f}{'Nodes'}{'RefactoredSubroutineCall'}
			  {'Name'} = $block;
			push @{ $stref->{'Subroutines'}{$f}{'Nodes'}{'BeginBlock'}{'Pos'} },
			  $index;
			next;
		}
		if ( $line =~ /^C\s+END\s+(\w+)/ ) {
			$in_block = 0;
			push @{ $stref->{'Subroutines'}{$f}{'Nodes'}{'EndBlock'}{'Pos'} },
			  $index;
			next;
		}
		if ($in_block) {
			push @{ $blocks{$block} }, $line;
			push @{ $stref->{'Subroutines'}{$f}{'Nodes'}{'InBlock'}{'Pos'} },
			  $index;
		}
		else {
			push @{ $blocks{'OUTER'} }, $line;
		}
	}

	for my $block ( keys %blocks ) {
		$stref->{'Subroutines'}{$f}{'Blocks'}{$block}{'Lines'} =
		  $blocks{$block};
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
		$stref->{'Subroutines'}{$f}{'Blocks'}{$block}{'Occs'} = $occs{$block};
	}

	my %args = ();
	for my $block ( keys %occs ) {
		next if $block eq 'OUTER';
		print "\nARGS for $block:\n" if $V;
		for my $var ( keys %{ $occs{$block} } ) {
			if ( exists $occs{'OUTER'}{$var} ) {
				print "$var\n" if $V;
				push @{ $args{$block} }, $var;
			}
		}
	}

	# 7. Identify which commons are used in inner, make them function arguments
	# This is the same as in remove_globals
       my %commons=();
        for my $i ( keys %{ $stref->{'Subroutines'}{$f}{'Nodes'}{'Include'} } ) {
            if ( $stref->{'Includes'}{$i}{'Type'} eq 'Common' ) {
                %commons=(%commons, %{ $stref->{'Includes'}{$i}{'Commons'} });
            }
        }
	   $stref->{'Subroutines'}{$f}{'Commons'}=\%commons;
	# This is almost the same as above
	for my $block ( keys %blocks ) {
		next if $block eq 'OUTER';
		my @lines = @{ $blocks{$block} };
#		my %tvars =
#		  map { $_ => 1 }
#		  keys( %{ $stref->{'Commons'} } );    # Hurray for pass-by-value!
        my @tvars=keys %commons;
		for my $line (@lines) {
			for my $var ( @tvars ) {
				next if not defined $var;
				if ( $line =~ /\W$var\W/ ) {

					push @{ $args{$block} }, $var;
					undef $var;
				}
			}
		}
		if ($V) {
			print "\nCOMMON VARS in block $block:\n\n";
			for my $var ( @{ $args{$block} } ) {
				print "$var\n";
			}
		}
		$stref->{'Subroutines'}{$f}{'Blocks'}{$block}{'Args'} = $args{$block};
	}

	# Construct the subroutine signatures
	for my $block ( keys %blocks ) {
		next if $block eq 'OUTER';
		my $sig   = "\tsubroutine $block(\n";
		my $decls = '';
		for my $argv ( @{ $args{$block} } ) {
			$sig .= "     &\t $argv,\n";
			my $type = $vars{$argv} || $commons{$argv};
			$decls .= $type . ' ' . $argv . "\n";
		}
		$sig =~ s/\,$/)\n/s;
		$stref->{'Subroutines'}{$f}{'Blocks'}{$block}{'Args'}  = $args{$block};
		$stref->{'Subroutines'}{$f}{'Blocks'}{$block}{'Sig'}   = $sig;
		$stref->{'Subroutines'}{$f}{'Blocks'}{$block}{'Decls'} = $decls;
		print $sig   if $V;
		print $decls if $V;
	}
	return $stref;
}    # END of refactor_blocks()

sub read_fortran_src {
	( my $s, my $stref ) = @_;

	my $is_incl = exists $stref->{'Includes'}{$s} ? 1 : 0;
	my $sub_or_incl = $is_incl ? 'Includes' : 'Subroutines';
	my $f = $is_incl ? $s : $stref->{'Subroutines'}{$s}{'Source'};

	my $ok = 1;
	open my $SRC, '<', $f or do {
		print STDERR "Can't find $f\n";
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

				#			push @{$lines}, '! ' . $comment;
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
				$line =~ s/^\s{5}./ /;
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
		my $has_blocks = 0;
		for my $index ( 0 .. scalar( @{$lines} ) - 1 ) {
			my $line = $lines->[$index];
			if ( $line =~ /^C\s/i ) {
				push
				  @{ $stref->{$sub_or_incl}{$s}{'Nodes'}{'Comments'}{'Pos'} },
				  $index;
				if ( $line =~ /C\s+BEGIN\s+\w+/ ) {
					$has_blocks = 1;
				}
				print "$line\n" if $V;
				next;
			}
			if ( $line =~ /^\!\s/ ) {
				push @{ $stref->{$sub_or_incl}{$s}{'Nodes'}{'TrailingComments'}
					  {'Pos'} }, $index;
				print "$line\n" if $V;
				next;
			}
			push @{ $stref->{$sub_or_incl}{$s}{'Nodes'}{'Nil'}{'Pos'} }, $index;
			print "$line\n" if $V;
		}
		$stref->{$sub_or_incl}{$s}{'Status'}    = 1;
		$stref->{$sub_or_incl}{$s}{'Lines'}     = $lines;
		$stref->{$sub_or_incl}{$s}{'HasBlocks'} = $has_blocks;
		$stref->{$sub_or_incl}{$s}{'Info'}      = [];
	}

	return $stref;
}

sub get_info_per_line {
	if ($V) {
		print "\n\n";
		print "#" x 80, "\n";
		print "Collecting information by line\n";
		print "#" x 80, "\n\n";
	}

	( my $stref ) = @_;

	for my $f ( keys %{ $stref->{'Subroutines'} } ) {
		print "SOURCE: $f\n" if $V;
		if ( exists $stref->{'Subroutines'}{$f}{'Info'} ) {
			my $aref = $stref->{'Subroutines'}{$f}{'Info'} || [];
			my @info = @{$aref};
			for my $node ( keys %{ $stref->{'Subroutines'}{$f}{'Nodes'} } ) {

				#			next if $node eq 'Globals';
				print "\tNODE: $node\n" if $V;
				if ( exists $stref->{'Subroutines'}{$f}{'Nodes'}{$node}{'Pos'} )
				{
					my @indices =
					  @{ $stref->{'Subroutines'}{$f}{'Nodes'}{$node}{'Pos'} };
					for my $index (@indices) {

						#					$info[$index]={};
						$info[$index]->{$node} =
						  $stref->{'Subroutines'}{$f}{'Nodes'}{$node};
					}
				}
				else {
					for my $key (
						keys %{ $stref->{'Subroutines'}{$f}{'Nodes'}{$node} } )
					{
						print "\t\tNAME: $key\n" if $V;
						my @indices =
						  @{ $stref->{'Subroutines'}{$f}{'Nodes'}{$node}{$key}
							  {'Pos'} };
						my @attrs = ();
						my $i     = 0;
						for my $index (@indices) {
							my $tref = {};
							for my $kkey (
								keys %{
									$stref->{'Subroutines'}{$f}{'Nodes'}{$node}
									  {$key}
								}
							  )
							{

	 # We assume that all these entries are lists with a one-on-one match to Pos
								$tref->{$kkey} =
								  $stref->{'Subroutines'}{$f}{'Nodes'}{$node}
								  {$key}{$kkey}[$i];
							}

							#						$info[$index]={};
							$info[$index]->{$node} = { $key => $tref };
							$i++;
						}
					}
				}
			}
			$stref->{'Subroutines'}{$f}{'Info'} = \@info;
		}
		else {
			print "No info for $f\n";
			$stref->{'Subroutines'}{$f}{'Info'} = [];
		}

		#		if ($V) {
		#			for my $i ( 0 .. @info - 1 ) {
		#				print $i, "\t";
		#				if ( defined $info[$i] ) {
		#					for my $item ( @{ $info[$i] } ) {
		#						print $item->[0], "\t";
		#					}
		#
		#				}
		#				else {
		#					print "Nil";
		#				}
		#				print "\n";
		#			}
		#		}
	}

	return $stref;
}

#sub Info{ (my $f,my $stref) =@_;
#	return $stref->{'Subroutines'}{$f}{'Info'} ;
#}
#
#sub inBlock { (my $info, my $idx)=@_;
#	for my $item (@{ $info->[$idx] }) {
#			if ($item->[0] eq 'InBlock') {
#				return 1;
#			}
#	}
#	return 0;
#}

sub insert_lines {
	( my $lref, my $srcref, my $idx ) = @_;    # \@lines, \@src_lines, $idx;
	my $nsrc = [ @{$srcref} ];
	splice( @{$nsrc}, $idx, 0, @{$lref} );
	return $nsrc;
}

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

# Find all source files in the current directory
sub find_subroutines {
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
				my $sub = $1;
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
		}
		close $SRC;
	}
	return $stref;
}
