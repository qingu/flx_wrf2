#!/usr/bin/perl
use warnings;
use strict;

# obtainted with perl translate_main_particles_loop_functions.pl timemanager_particles_loop.f
my @oldfiles=qw(
timemanager_particles_loop		
advance
calcfluxes
drydepokernel
drydepokernel_nest
hanna
hanna1
hanna_short
initialize
interpol_all
interpol_all_nests
interpol_misslev
interpol_misslev_nests
interpol_vdep
interpol_vdep_nests
interpol_wind
interpol_wind_nests
interpol_wind_short
interpol_wind_short_nests
windalign
);

my %files=(
timemanager_particles_loop => 0,
advance => 1,
calcfluxes => 1,
drydepokernel =>1,
drydepokernel_nest =>1,
hanna =>2,
hanna1 =>2,
hanna_short =>2,
initialize => 1,
interpol_all =>2,
interpol_all_nests =>2,
interpol_misslev =>2,
interpol_misslev_nests =>2,
interpol_vdep =>2,
interpol_vdep_nests =>2,
interpol_wind =>2,
interpol_wind_nests =>2,
interpol_wind_short =>2,
interpol_wind_short_nests =>2,
windalign =>2
);



my $src=$ARGV[0];


my %types=();
my %arrays=();
my %scalars=();

get_types($src);

my @includes=glob("include*.h");
for my $include (@includes) {
	get_types($include);
}

#for my $v (keys %types) {
#	print $v,"\t",$types{$v},"\n";
#}
#exit;
my @errors=`gcc -c $src 2>&1`;

my %args=();

for my $err (@errors) {
	
	if ($err =~/error:\ \‘(\w+)\’\ undeclared/) {
#		print "<$err>\n";
		my $var=$1;
		if (exists $types{$var}) {
			if (exists( $arrays{$var}) &&  ($arrays{$var}==0) ) {
			$arrays{$var}=1;
			}
			if (exists( $scalars{$var}) &&  ($scalars{$var}==0) ) {
			$scalars{$var}=1;
			}
		my $type=$types{$var};
		$args{$var}="$type $var,\n";
		} else {
			print "WARNING: no type found for $var\n";
		}
	}
}
print "\n// ARGUMENTS FOR 'COMMON' VARIABLES:\n\n";
for my $var (sort keys %args) {
	print $args{$var};
}

print '=' x 80 , "\n";
print "ARRAYS\n";
#my $n=scalar keys %arrays;
my $i=0;
for my $arr (sort keys %arrays) {
	next unless $arrays{$arr}==1;
	$i++;
	print "$i: $types{$arr} $arr\n";
#	print("ack '$arr\\(.*?\\)\\s*=' ../*.f\n" );
#	print("ack '$arr\\(.*?\\)\\s*[^=]' ../*.f\n");
	my $out='';
	my $ro=1;
	for my $file (keys %files) {
		my $lev=$files{$file};
		my $w=`grep -i -P '$arr\\(.*?\\)\\s*=' ../$file.f`;
		my $r=`grep -i -P '$arr\\(.*?\\)\\s*[^=]' ../$file.f`;
		if ($w=~/$arr/ or $r=~/$arr/) {
			$out.= "$file:\n";
			if ($w=~/$arr/){
				$out.= "\tASSIGN $lev\n" ;
				$ro=0;
			};
			$out.= "\tREAD $lev\n" if $r=~/$arr/;
		}
	}
	if ($ro==1) {
		print "\tREAD-ONLY\n";
	} else {
		print $out;
	}
#	die;
print '-' x 80 , "\n";
}



print '=' x 80 , "\n";
print "SCALARS\n";
#my $n=scalar keys %arrays;
$i=0;
for my $arr (sort keys %scalars) {
	next unless $scalars{$arr}==1;
	$i++;
	print "$i: $arr\n";
	for my $file (keys %files) {
		my $lev=$files{$file};
	my $w=`grep -i -P '$arr\\s*=' ../$file.f`;
	my $r=`grep -i -P '$arr\\s*[^=\\w]' ../$file.f`;
	if ($w=~/$arr/ or $r=~/$arr/) {
			print "$file:\n";
			print "\tASSIGN $lev\n" if $w=~/$arr/;
			print "\tREAD $lev\n" if $r=~/$arr/;
	}

	}
#	die;
print '-' x 80 , "\n";
}


sub get_types {
	my $src=shift;
	open my $SRC,"<$src";
	$src=~s/\.c//;
	my $args=0;
	while(my $line=<$SRC>) {
		if ($line=~/^\s*(?:static\s+)?(\w+)\s+([\w\,\[\]\(\)\-\+\*\ ]+)\s*;/) {
			my $type=$1;
			my $varlst=$2;
			my @vars=split(/\s*\,\s*/,$varlst);
			my $p='';
			for my $var (@vars) {
				if ($var=~s/\[.*//) {
					$p='*';
				$arrays{$var}=0;			
			} else {
				$scalars{$var}=0;
			}

			$types{$var}=$type.$p;
			$p='';
			}
		}
		if ($line=~/^\s*\w+\*?\s*$src\s*\(/) {
				$args=1;
				print "// ORIGINAL ARGUMENTS:\n\n";
				}
		if ($line=~/ifdef\ GEN_ARGS/) {
			$args=-1;
#			die;
		}
		if ($args==1) {
#			print "ARGLINE: $line";
			if ($line=~/^\s*(\w+\*?)\s+([\w\,\*\s]+)/) {
				my $type=$1;
				my $varlst=$2;
				$varlst=~s/\,\s*$//;
				my $arglst=$type.' '.$varlst;
#				print $arglst;
				my @var_type_tuples=split(/\s*\,\s*/,$arglst);
				for my $vtt (@var_type_tuples) {
					$vtt=~s/\s+$//;
					$vtt=~s/^\s+//;
					(my $type, my $var)=split(/\s+/,$vtt);
					print "$type $var,\n";
					if ($type=~/\*/) {
						$arrays{$var}=1;			
					} else {
						$scalars{$var}=1;
					}
					$types{$var}=$type;
				}
			}
		}
	}
	close $SRC;
}
