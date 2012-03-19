package RefactorF4Acc::Refactoring::Includes;

use RefactorF4Acc::Config;
use RefactorF4Acc::Utils;
use RefactorF4Acc::Refactoring::Common qw( split_long_line );
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

@RefactorF4Acc::Refactoring::Includes::ISA = qw(Exporter);

@RefactorF4Acc::Refactoring::Includes::EXPORT_OK = qw(
    &refactor_includes
);

=pod
Includes
    refactor_includes()
    refactor_include()  
=cut

# -----------------------------------------------------------------------------
# In fact, "preconditioning" might be the better term
sub refactor_includes {
    ( my $stref ) = @_;

    for my $f ( keys %{ $stref->{'IncludeFiles'} } ) {

        if (   $stref->{'IncludeFiles'}{$f}{'InclType'} eq 'Common'
            or $stref->{'IncludeFiles'}{$f}{'InclType'} eq 'Parameter' )
        {
            print "\nREFACTORING INCLUDE $f\n" if $V;
            refactor_include( $f, $stref );
        }
    }
    return $stref;
}

# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
sub refactor_include {
    ( my $f, my $stref ) = @_;

    if ($V) {
        print "\n\n";
        print "#" x 80, "\n";
        print "Refactoring INC $f\n";
        print "#" x 80, "\n";
    }

    my @lines = @{ $stref->{'IncludeFiles'}{$f}{'Lines'} };
    my @info =
      defined $stref->{'IncludeFiles'}{$f}{'Info'}
      ? @{ $stref->{'IncludeFiles'}{$f}{'Info'} }
      : ();
    my $annlines = [];
    for my $line (@lines) {
        my $tags = shift @info;
        push @{$annlines}, [ $line, $tags ];
    }

#   my $rlines = [];
    for my $annline ( @{$annlines} ) {
        my $line      = $annline->[0] || '';
        my $tags_lref = $annline->[1];
        my %tags      = ( defined $tags_lref ) ? %{$tags_lref} : ();
        print '*** ' . join( ',', keys(%tags) ) . "\n" if $V;
        print '*** ' . $line . "\n" if $V;
        my $skip = 0;
        if ( exists $tags{'Common'} ) {
            $skip = 1;
        }
        if ( exists $tags{'VarDecl'} ) {
            my @nvars = ();
            for my $var ( @{ $annline->[1]{'VarDecl'} } ) {
                if ( $stref->{'IncludeFiles'}{$f}{'InclType'} ne 'Parameter'
                    and
                    exists $stref->{'IncludeFiles'}{$f}{'ConflictingGlobals'}
                    {$var} )
                {
                    my $gvar =
                      $stref->{'IncludeFiles'}{$f}{'ConflictingGlobals'}{$var};
                    print
"WARNING: CONFLICT in var decls in $f: renaming $var to $gvar\n"
                      if $W;
                    push @nvars, $gvar;
                    $line =~ s/\b$var\b/$gvar/;
                } else {
                    push @nvars, $var;
                }
            }
            $annline->[1]{'VarDecl'} = [@nvars];
        }
        if ( $skip == 0 ) {

            if ( not exists $tags{'Comments'} ) {
                print $line, "\n" if $V;
                my @split_lines = split_long_line($line);
                for my $sline (@split_lines) {
                    push @{ $stref->{'IncludeFiles'}{$f}{'RefactoredCode'} },
                      $sline;
                }
            } else {
                push @{ $stref->{'IncludeFiles'}{$f}{'RefactoredCode'} }, $line;
            }
        }
    }

    return $stref;

}    # refactor_include()
