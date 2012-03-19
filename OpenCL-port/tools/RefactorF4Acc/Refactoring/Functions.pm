package RefactorF4Acc::Refactoring::Functions;

use RefactorF4Acc::Config;
use RefactorF4Acc::Utils;
use RefactorF4Acc::Refactoring::Common qw( create_refactored_source );

# 
#   (c) 2010-2012 Wim Vanderbauwhede <wim@dcs.gla.ac.uk>
#   

use vars qw( $VERSION );
$VERSION = "1.0.0";

use warnings::unused;
use warnings;
use warnings FATAL => qw(uninitialized);
use strict;
use Carp;
use Data::Dumper;

use Exporter;

@RefactorF4Acc::Refactoring::Functions::ISA = qw(Exporter);

@RefactorF4Acc::Refactoring::Functions::EXPORT_OK = qw(
    &refactor_called_functions
);

=pod
Functions
    refactor_called_functions()
    refactor_function()
=cut


# -----------------------------------------------------------------------------
sub refactor_called_functions {
    ( my $stref ) = @_;

    for my $f ( keys %{ $stref->{'Functions'} } ) {
        my $Ff = $stref->{'Functions'}{$f};

        #       warn "REFACTORING FUNCTION $f? ";
        if ( defined $Ff->{'Called'} ) {

            #           warn "YES\n";
            $stref = refactor_function( $f, $stref );
        } else {

            #           warn "NOT REFACTORING FUNCTION $f\n";
            #           die if $f eq 'cspanf';
        }
    }
    return $stref;
}    # END of refactor_called_functions()

# -----------------------------------------------------------------------------
sub refactor_function {
    ( my $f, my $stref ) = @_;
    if ($V) {
        print "\n\n";
        print "#" x 80, "\n";
        print "Refactoring $f\n";
        print "#" x 80, "\n";
    }
    my $Ff = $stref->{'Functions'}{$f};
    print "REFACTORING FUNCTION $f\n" if $V;

    #   die Dumper( $Ff ) if $f eq 'gser';
    my @lines = @{ $Ff->{'Lines'} };

    my @info =
      defined $Ff->{'Info'}
      ? @{ $Ff->{'Info'} }
      : ();

    my $annlines = [];
    for my $line (@lines) {
        my $tags = shift @info;
        push @{$annlines}, [ $line, $tags ];
    }

    my $rlines = $annlines;

    if (   not exists $Ff->{'RefactoredCode'}
        or $Ff->{'RefactoredCode'} == []
        or exists $stref->{'BuildSources'}{'C'}{ $Ff->{'Source'} } )
    {
        $stref = create_refactored_source( $stref, $f, $rlines );
    }

    #   print STDERR "REFACTORED $f\n";
    #    die Dumper($Ff->{'RefactoredCode'}) ;
    return $stref;

}    # END of refactor_function()
# -----------------------------------------------------------------------------
