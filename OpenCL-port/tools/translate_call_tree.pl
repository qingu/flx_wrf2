#!/usr/bin/perl
use warnings;
use strict;
my %calls=();
our $top='';
sub get_calls {
    my $f=shift;
    open my $IN,'<',$f;
    while(<$IN>) {
    	chomp;
    	/Call\ tree\ for\ (\w+):/ && do {
    		$top=$1;
    	};
    	/^\s+.*?\.f$/ && do {
    		s/^\s+\w+\s+//;
    		$calls{$_}++;
    	};
    }
    close $IN;
}

die if not @ARGV;
my $f=$ARGV[0];
&get_calls($f);


print "\n\nSources referenced from $top:\n\n";
for my $file (sort keys %calls) {
#	$file=~s/\.f$//;
   print $file,"\n";
   print "f2c $file\n";
   system "f2c $file";
   die;
} 
