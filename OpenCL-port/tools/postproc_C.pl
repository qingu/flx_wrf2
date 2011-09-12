#!/usr/bin/perl 
use warnings;
use strict;

# 
# perl  ../OpenCL-port/tools/postproc_C.pl timemanager_particles_main_loop.c > tmp.c
# gcc -c -Wall -I$GPU_HOME/include  tmp.c

# remove extern function declarations, replace by includes to the header files
#=> means we should generate the header files as well! Or maybe just put those "extern" declarations in separate header files ...
# replace 'F2C-ACC: Type not recognized.' by the type of the variable 
# => need to look up that variable 
my $vtype='double';

while (<>) {
    s/F2C\-ACC\:\ Type\ not\ recognized\./$vtype/g;
        /^\s+extern\s+\w+\s+\w+[;,]/ && do {
        s|^|\/\/|;
    }; # because parameters are macros, not variables
 
#*  float float and similar need to be removed
    /float\s+(float|sngl)/ && do {
        s|^|\/\/|;
    };
    
    /int\s+(int)/ && do {
        s|^|\/\/|;
    };
    
    /(short|int)\s+(int2|short)/ && do {
        s|^|\/\/|;
    };
    
    /(long|int)\s+(int8|long)/ && do {
        s|^|\/\/|;
    };
    
    /^\s+extern\s+\w+\s+\w+[;,]/ && do {
        s|^|\/\/|;
    }; # because parameters are macros, not variables. Ad hoc: I should make a list of all parameters and test against that!
    s/int\(/(int)(/g; # int is a FORTRAN primitive converting float to int
    s/(int2|short)\(/(int)(/g; # int is a FORTRAN primitive converting float to int
    s/(int8|long)\(/(long)(/g; # int is a FORTRAN primitive converting float to int
    s/float\(/(float)(/g; # float is a FORTRAN primitive converting int to float
    s/(dfloat|dble)\(/(double)(/g; # dble is a FORTRAN primitive converting int to float
    s/sngl\(/(/g; # sngl is a FORTRAN primitive converting double to float
    /goto\ C__(\d+):/ && do {
        my $label=$1;
        if (isBreak($label)) {
            eval("s/goto\\ C__$label:/break/");
        } else {
            s/C__(\d+)\:/C__$1/;
        }
    };
#    s/goto\ C__37:/break/; # must have a list of all gotos that are breaks
    /^\s+C__(\d+)/ && do {
        my $label=$1;
        if (isNoop($label)) {
            s|^|\/\/|;
        }
    };
    print $_;
}

sub isBreak {
(my $label)=@_;
    return 1;
}

sub isNoop {
(my $label)=@_;
    return 1;
}
