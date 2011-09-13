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

# For parameters:
# What we need is a lookup src file => sub => includes
# for my $f (  keys %{ $stref->{'BuildSources'}{'F'}{'Subs'} } )
# or better, detect the actual subroutine and get the list of parameter-type includes:

# 
#        for my $i ( keys %{ $stref->{'Subroutines'}{$f}{'Includes'} } ) {
#            if ( $stref->{'Includes'}{$i}{'Type'} eq 'Parameter' ) {
#               $stref->{'Includes'}{$f}{'Parameters'}{$var} 
# }

my $stref={

'Subroutines' => {
    'particles_main_loop' => {
        'Includes' => {
            'includepar' => {
                'Type'=>'Parameter'
            }
        },
        'Vars' => {
              'xtra1' => { 'Type' => 'double precision' },
        'ytra1' => { 'Type' => 'double precision' },
        },
        'Gotos' =>{
        	'37' => 'NoopBreakTarget'
        }
    }
},
    'Includes' => {
        'includepar' => {
            'Type' => 'Parameter',
            'Parameters' => {}
        }
    }
};
use Data::Dumper;

my $csrc=$ARGV[0];

postprocess_C($stref,$csrc);
system('gcc -c -Wall -I$GPU_HOME/include  tmp.c');

sub postprocess_C {
	(my $stref, my $csrc) = @_;
	my $sub='';
	my %params=();
	my %vars=();
	my %labels=();
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
	
	open my $CSRC,'<',$csrc;
	open my $PPCSRC,'>','tmp.c'; # FIXME
	while (my $line =<$CSRC>) {
	    $line=~/^\s*void\s+(\w+)_\s+\(.*?\)\s+\{/ && do {
	        $sub= $1;
	        
	        for my $i ( keys %{ $stref->{'Subroutines'}{$sub}{'Includes'} } ) {
	            if ( $stref->{'Includes'}{$i}{'Type'} eq 'Parameter' ) {
	               %params = (%params,%{ $stref->{'Includes'}{$i}{'Parameters'} });
	             }
	        }
	        %vars=%{ $stref->{'Subroutines'}{$sub}{'Vars'} };
	        %labels=%{ $stref->{'Subroutines'}{$sub}{'Gotos'} };
	    };
	    $line=~/F2C\-ACC\:\ Type\ not\ recognized\./ && do {
	        my @chunks=split(/\,/,$line);
	        for my $chunk (@chunks) {
	            $chunk =~/F2C\-ACC\:\ Type\ not\ recognized\.\ \*?(\w+)/ && do {
	                my $var=$1;                
	                my $ftype=$vars{$var}{'Type'};
	                my $vtype=toCType($ftype);
	                $chunk=~s/F2C\-ACC\:\ Type\ not\ recognized\./$vtype/;
	            };        
	        }
	        $line=join(',',@chunks);
	    };
	   next if $line=~/^\s*extern\s+void\s+noop/;
	   if ($line=~/^\s*extern\s+\w+\s+(\w+)_\(/) {
	   	   my $inc=$1;
	   	   my $hfile=$inc.'.h';
	   	   
	   	   if (not -e $hfile) {
	   	       $line=~s/^\s*extern\s+//; 
	   	       open my $INC,'>',$hfile;
	   	       my $shield=$hfile;
	   	       $shield=~s/\./_/;
	   	       $shield='_'.uc($shield).'_';
	   	       print $INC '#ifndef '.$shield."\n";
	   	       print $INC '#define '.$shield."\n";
	   	       print $INC $line;
	   	       print $INC '#endif //'.$shield."\n";
	   	       close $INC;
	   	   }
           print $PPCSRC '#include "'.$hfile.'"'."\n";
           next;	   	
	   }
	   
	    $line=~/^\s+extern\s+\w+\s+\w+[;,]/ && do {        
	        $line=~s|^|\/\/|;
	    }; # because parameters are macros, not variables
	 
	#*  float float and similar need to be removed
	    $line=~/float\s+(float|sngl)/ && do {
	        $line=~s|^|\/\/|;
	    };
	    
	    $line=~/int\s+(int)/ && do {
	        $line=~s|^|\/\/|;
	    };
	    
	    $line=~/(short|int)\s+(int2|short)/ && do {
	        $line=~s|^|\/\/|;
	    };
	    
	    $line=~/(long|int)\s+(int8|long)/ && do {
	        $line=~s|^|\/\/|;
	    };
	    
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
	    print $PPCSRC $line;
	}
	close $CSRC;
	close $PPCSRC;	
}

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
}
