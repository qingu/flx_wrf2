#!/usr/bin/perl
use warnings;
use strict;
my %calls=();
sub get_calls {
    my $f=shift;
    my $n=shift;
    $n++;
    open my $IN,"<$f.f";
    while(<$IN>) {
        /^C/i && next;
        /^\s*\!/ && next;
        if (
                /^\s+.*?\s+call\s+/ 
           ) {
        
            my $f=$1;
            $calls{$f}++;

            print "\t" x $n;
            print "$f\n";
            &get_calls($f,$n);
#            $n--;
        }
    }
    $n--;
    close $IN;
}

die if not @ARGV;
my $f=$ARGV[0];
$f=~s/\.f$//;
&get_calls($f,0);

# my $GPU_ROOT=$ENV{'GPU_ROOT'};

print "\n\nFunctions called from $f:\n\n";
for my $file (sort keys %calls) {
   print $file,"\n";
#   system("$GPU_ROOT/F2C-ACC --comment --Fixed --Generate=C $file.f  --OutputFile=F2C_translated_files/$file.c");
} 
