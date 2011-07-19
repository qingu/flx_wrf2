#!/usr/bin/perl
use warnings;
use strict;

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
=cut


die "Please specifiy FORTRAN source to refactor\n" if not @ARGV;
my $f=$ARGV[0];
my %commons=();
parse_fortran_src ($f,0,\%commons);

sub parse_fortran_src {
	(my $f, my $is_incl, my $commons_ref)=@_;
	open my $SRC,'<',$f;
	my @lines=();
	my $prevline='';
# 0. Slurp the source; strip the comments
# 1. Join up the continuation lines 
# TODO: split lines with ; 
	my $line='';
	while (<$SRC>) {
		$line=$_;
		chomp $line;
# Skip blanks
		$line=~/^\s*$/ && next;
# Strip comments
		if ($line=~/^[C\*\!]/i && $line!~/C\s+(?:BEGIN|END)\s+\w+/) {
			next;
		}
		$line=~s/\s+\!.*$//;

		if ($line=~/^\s+[\+\&]/) { # continuation line
			$line=~s/^\s+[\+\&]\s*/ /;
			$prevline.=$line;
		} else {
			push @lines, lc($prevline);
			$prevline=$line;
		}
	}
	push @lines, lc($line);

	close $SRC;
	my %vars=();
	my %kind=();
	my %commons=();
	my %occs=();
	
# 2. Parse the type declarations in the source, create a table %vars
print "\n VAR DECLS in $f:\n";	
	for my $line (@lines) {
#	print "LINE:",$line,"\n";
		if ($line=~/(logical|integer|real|double\s+precision|character|character\*?(?:\d+|\(\*\)))\s+(.+)\s*$/) {
#			print "HIT\n";
			my $type=$1;
			my $varlst=$2;
			$varlst=~s/\(.*?\)/(0)/g; # clean up arrays
			my @tvars=split(/\s*\,\s*/,$varlst);
			my $p='';
			for my $var (@tvars) {
				$var=~s/^\s+//;
				$var=~s/\s+$//;
				if ($var=~s/\(.*?\)//) {
					$var=~s/\*\d+//; # FIXME: char string handling is not correct!
					$kind{$var}=1;
				$p='()';
			} else {
				$kind{$var}=0;
			}			
			$vars{$var}=$type;
			print $type,$p,"\t<",$var,">\n";
			}
		}
	}
	print "\nCOMMON VARS in $f\n" if $is_incl==1;
	for my $line (@lines) {
# 3. Parse includes, recursively doing 0/1/2
		if ($is_incl==0 and $line=~/^\s*include\s+\'(\w+)\'/) { # no nested includes!
			print $line,"\n";
			my $inc=$1;
			my $commons_ref=parse_fortran_src($inc,1,$commons_ref);	
		}
# 4. For includes, parse common blocks, create %commons
		if ($is_incl==1 and $line=~/^\s*common\s+\/\w+\/\s+(.+)$/) {
			my $commonlst=$1;
			my @tcommons=split(/\s*\,\s*/,$commonlst);
			for my $v (@tcommons) {
				if (not defined $vars{$v}) {
					print "MISSING: <",$v,">\n";
				} else {
					$commons_ref->{$v}=$vars{$v};
				}
			}
		}
	}
	if ($is_incl==1) {
		return $commons_ref;
	}
	print "\nCOMMON VARS:\n\n";
	for my $v (keys %{$commons_ref}) {
		print $commons_ref->{$v},"\t",$v,"\n";
	}
# 5. Split the source based on the block markers
# As there could be several blocks (later), use a hash per block
	my %blocks=();
	my $in_block=0;
	my $block='OUTER';
	for my $line (@lines) {
# skip subroutine decl
		$line=~/^\s+subroutine/ && next;
		$line=~/(integer|real|double\s+precision|character\*?(?:\d+|\(\*\)))\s+(.+)\s*$/ && next;
		if ($line=~/^C\s+BEGIN\s+(\w+)/) {
			$in_block=1;
			$block=$1;
			next;
		}
		if ($line=~/^C\s+END\s+(\w+)/) {
			$in_block=0;
			next;
		}
		if ($in_block) {
			push @{$blocks{$block}}, $line;
		} else {
			push @{$blocks{'OUTER'}}, $line;
		}
	}
# So now we have split the file in blocks, we have identified the common vars.

# 6. Identify which vars are used
#	- in both => these become function arguments
#	- only in "outer" => do nothing for those
#	- only in "inner" => can be removed from outer variable declarations
# Find all vars used in each block, starting with the outer block
# It is best to loop over all vars per line per block, because we can remove the encountered vars
	for my $block (keys %blocks) {
		my @lines=@{$blocks{$block}};
		my %tvars=%vars; # Hurray for pass-by-value!
			print "\nVARS in $block:\n\n";
		for my $line (@lines) {
			for my $var (keys %tvars) {
				if ($line=~/\W$var\W/) {
					print "$var\n";				
					$occs{$block}{$var}=$var;
					delete $tvars{$var};
				}
			}
		}
	}
	my %args=();
	for my $block (keys %occs) {
		next if $block eq 'OUTER';
				print "\nARGS for $block:\n";
		for my $v (keys %{$occs{$block}}) {
			if (exists $occs{'OUTER'}{$v}) {
				print "$v\n";
				push @{$args{$block}},$v;
			}
		}
	}
# 7. Identify which commons are used in inner, make them function arguments
# This is almost the same as above
	for my $block (keys %blocks) {
		next if $block eq 'OUTER';
		my @lines=@{$blocks{$block}};
		my %tvars=%{$commons_ref}; # Hurray for pass-by-value!
			print "\nCOMMON VARS in $block:\n\n";
		for my $line (@lines) {
			for my $var (keys %tvars) {
				if ($line=~/\W$var\W/) {
					print "$var\n";				
					push @{$args{$block}},$var;
					delete $tvars{$var};
				}
			}
		}
	}
# Construct the subroutine signatures
	for my $block (keys %blocks) {
		next if $block eq 'OUTER';
		my $sig="\tsubroutine $block(\n";
		my $decls='';
		for my $argv (@{$args{$block}}) {
			$sig.="     &\t $argv,\n";
			my $type=$vars{$argv} || $commons_ref->{$argv};
			
			$decls.=$type.' '.$argv."\n";
		}
		$sig=~s/\,$/)\n/s;
		print $sig;
		print $decls;
	}


}



