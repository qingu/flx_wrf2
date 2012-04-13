package RefactorF4Acc::Inventory;

use RefactorF4Acc::Config qw ($V $W $UNREAD);
# 
#   (c) 2010-2012 Wim Vanderbauwhede <wim@dcs.gla.ac.uk>
#   

use vars qw( $VERSION );
$VERSION = "1.0.0";

use warnings;
use strict;

use Exporter;

@RefactorF4Acc::Inventory::ISA = qw(Exporter);

@RefactorF4Acc::Inventory::EXPORT = qw(
    &find_subroutines_functions_and_includes
);

use File::Find;

# Find all source files in the current directory
sub find_subroutines_functions_and_includes {	
    my $stref = shift;
    my $dir   = '.';

    # find sources (borrowed from PerlMonks)
    my %src_files = ();
    my $tf_finder = sub {
        return if !-f;
        return if !/\.f(?:90)?$/ ;
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

            # Find subroutine/program signatures
            $line =~ /^\s*(subroutine|program)\s+(\w+)/i && do {            	
                my $is_prog = ($1 eq 'program') ? 1 : 0;
                if ( $is_prog == 1 ) {
                    print "Found program $2 in $src\n" if $V;
                }                
                my $sub  = lc($2);
                $stref->{'Subroutines'}{$sub}={};
                my $Ssub = $stref->{'Subroutines'}{$sub};
                if (
                    not exists $Ssub->{'Source'}
                    or (    $src =~ /$sub\.f(?:90)?/
                        and $Ssub->{'Source'} !~ /$sub\.f(?:90)?/ )
                  )
                {
                    if (    exists $Ssub->{'Source'}
                        and $src =~ /$sub\.f(?:90)?/
                        and $Ssub->{'Source'} !~ /$sub\.f(?:90)?/ )
                    {
                        print "WARNING: Ignoring source "
                          . $Ssub->{'Source'}
                          . " because source $src matches subroutine name $sub.\n"
                          if $W;
                    }
                    $Ssub->{'Source'}  = $src;
                    $Ssub->{'Status'}  = $UNREAD;
                    $Ssub->{'Program'} = $is_prog;

                } else {
                    print
"WARNING: Ignoring source $src for $sub because another source, "
                      . $Ssub->{'Source'}
                      . " exists.\n"
                      if $W;
                }
            };

            # Find include statements
            $line =~ /^\s*include\s+\'(\w+)\'/ && do {
                my $inc = $1;
                if ( not exists $stref->{'IncludeFiles'}{$inc} ) {
                    $stref->{'IncludeFiles'}{$inc}{'Status'} = $UNREAD;
                }
            };

            # Find function signatures
            $line =~ /^\s*\w*\s+function\s+(\w+)/i && do {
                my $func = lc($1);
                $stref->{'Functions'}{$func}{'Source'} = $src;
                $stref->{'Functions'}{$func}{'Status'} = $UNREAD;
            };

        }
        close $SRC;
    }
    return $stref;
}    # END of find_subroutines_functions_and_includes()