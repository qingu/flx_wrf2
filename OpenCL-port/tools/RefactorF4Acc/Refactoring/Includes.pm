package RefactorF4Acc::Refactoring::Includes;

use RefactorF4Acc::Config;
use RefactorF4Acc::Utils;
use RefactorF4Acc::Refactoring::Common qw( get_annotated_sourcelines create_refactored_source );

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
  &create_refactored_include_source
);

=pod
Includes
    refactor_includes()
    refactor_include()  
    create_refactored_include_source()    
=cut

# -----------------------------------------------------------------------------
# In fact, "preconditioning" might be the better term
# I guess I should defer splitting the lines until the end
sub refactor_includes {
	( my $stref ) = @_;

	for my $f ( keys %{ $stref->{'IncludeFiles'} } ) {

		if (   $stref->{'IncludeFiles'}{$f}{'InclType'} eq 'Common'
			or $stref->{'IncludeFiles'}{$f}{'InclType'} eq 'Parameter' )
		{
			print "\nREFACTORING INCLUDE $f\n" if $V;
			$stref = refactor_include( $f, $stref );
			$stref = create_refactored_source($stref, $f);
		}
	}
	return $stref;
}

# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
sub refactor_include {
	( my $f, my $stref ) = @_;

	print "\n\n", '#' x 80, "\nRefactoring INC $f\n", '#' x 80, "\n" if $V;

	my $annlines = get_annotated_sourcelines( $stref, $f );

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

#			if ( not exists $tags{'Comments'} ) {
#				print $line, "\n" if $V;
#				my @split_lines = split_long_line($line);
#				for my $sline (@split_lines) {
#					push @{ $stref->{'IncludeFiles'}{$f}{'RefactoredCode'} },
#					  [ $sline, $tags_lref ];
#				}
#			} else {
				push @{ $stref->{'IncludeFiles'}{$f}{'RefactoredCode'} },
				  [ $line, $tags_lref ];
#			}
		}
	}

	return $stref;

} # END of refactor_include()

# -----------------------------------------------------------------------------
#sub create_refactored_include_source {
#	( my $f, my $stref ) = @_;
#
#	my $annlines = get_annotated_sourcelines( $stref, $f );
#	$stref->{'IncludeFiles'}{$f}{'RefactoredCode'} = [];
#	for my $annline ( @{$annlines} ) {
#		my $line = $annline->[0] || '';
#		my $tags_lref = $annline->[1];
#		if ( not exists $tags_lref->{'Comments'} ) {
#			print $line, "\n" if $V;
#			my @split_lines = split_long_line($line);
#			for my $sline (@split_lines) {
#				push @{ $stref->{'IncludeFiles'}{$f}{'RefactoredCode'} },
#				  [ $sline, $tags_lref ];
#			}
#		} else {
#			push @{ $stref->{'IncludeFiles'}{$f}{'RefactoredCode'} },
#			  [ $line, $tags_lref ];
#		}
#	}
#
#	return $stref;
#
#} # END of create_refactored_include_source() 
