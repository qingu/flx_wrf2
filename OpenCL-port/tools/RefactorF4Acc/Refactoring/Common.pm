package RefactorF4Acc::Refactoring::Common;

use RefactorF4Acc::Config;
use RefactorF4Acc::Utils;
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

@RefactorF4Acc::Refactoring::Common::ISA = qw(Exporter);

@RefactorF4Acc::Refactoring::Common::EXPORT_OK = qw(
    &context_free_refactorings
    &create_refactored_source
    &get_annotated_sourcelines
    &split_long_line    
);

#* BeginDo: just remove the label
#* EndDo: replace label CONTINUE by END DO
#* Break: keep as is; add a comment to identify it as a break
#* Goto: Do nothing
#* GotoTarget: Do nothing
#* NoopBreakTarget: replace CONTINUE with "call noop"
#* BreakTarget: Do nothing
sub context_free_refactorings {
    ( my $stref, my $f ) = @_;
    print "CREATING FINAL $f CODE\n" if $V;
    my @extra_lines = ();
    my $sub_or_func =
      ( exists $stref->{'Subroutines'}{$f} ) ? 'Subroutines' : 'Functions';
    my $Sf = $stref->{$sub_or_func}{$f};
    if ($Sf->{'Status'}!=2 ) {
    	croak caller;
    }    
    my $annlines=get_annotated_sourcelines($stref,$f);
    $Sf->{'RefactoredCode'} =[];
    for my $annline ( @{$annlines} ) {
        if (not defined $annline or not defined $annline->[0]) {
            croak "Undefined source code line for $f in create_refactored_source()";
        }
        my $line = $annline->[0];
        my $tags_lref = $annline->[1] || {};
        my %tags = %{$tags_lref};

        # BeginDo: just remove the label
        if ( exists $tags{'BeginDo'} ) {
            $line =~ s/do\s+\d+\s+/do /;
        }
        # EndDo: replace label CONTINUE by END DO; 
        # if no continue, remove label & add end do on next line
        if ( exists $tags{'EndDo'} ) {
            my $is_goto_target = 0;
            if (
                $Sf->{'Gotos'}{ $tags{'EndDo'}{'Label'} } )
            {
                # this is an end do which serves as a goto target
                $is_goto_target = 1;
            }
            my $count = $tags{'EndDo'}{'Count'};
            if ( exists $tags{'Continue'} ) {
                if ( $is_goto_target == 0 ) {
                    $line = '      end do';
                    $count--;
                } elsif ($noop) {
                    $line =~ s/continue/call noop/;
                }
            } elsif ( $line =~ /^\d+\s+\w/ ) {
                if ( $is_goto_target == 0 ) {
                    $line =~ s/^\d+//;
                }
            }
            while ( $count > 0 ) {
                push @extra_lines, '      end do';
                $count--;
            }
        }
        if ( $noop
            && ( exists $tags{'NoopBreakTarget'} || exists $tags{'NoopTarget'} )
          )
        {
            $line =~ s/continue/call noop/;
        }
        if ( exists $tags{'Break'} ) {
            $line .= '  !Break';
            # $line=~s/goto\s+(\d+)/call break($1)/;
        }
        if ( exists $tags{'PlaceHolders'} ) {
            my @phs = @{ $tags{'PlaceHolders'} };
            for my $ph (@phs) {
                my $str = $Sf->{'StringConsts'}{$ph};
                $line =~ s/$ph/$str/;
            }
        }
        if (exists $tags{'VarDecl'} ) {
#        	warn "$sub_or_func $f: $line\n";
        	my @vars=@{$tags{'VarDecl'}};
        	for my $var (@vars) {
        		my $spaces = $Sf->{'Vars'}{$var}{'Decl'};
        		$spaces=~s/\S.*$//;
        		my $extra_line = $spaces.$Sf->{'Vars'}{$var}{'Type'}.' :: '.$var;
#        		warn $extra_line."\n";
                push @{ $Sf->{'RefactoredCode'} },[$extra_line,{'Extra'=>1,'VarDecl'=>1}];        		
        	}
        } else {
        push @{ $Sf->{'RefactoredCode'} }, [$line, $tags_lref];
        }
            if (@extra_lines) {
                for my $extra_line (@extra_lines) {
                    push @{ $Sf->{'RefactoredCode'} },
                      [$extra_line,{'Extra'=>1}];
                }
                @extra_lines = ();
            }        
    }
    return $stref;
}    # END of context_free_refactorings()

# -----------------------------------------------------------------------------
sub create_refactored_source {
   ( my $stref, my $f,  ) = @_;
    print "CREATING FINAL $f CODE\n" if $V;
    die join(' ; ', caller ) if $stref!~/0x/;
    my $sub_or_func_or_inc = sub_func_or_incl($f,$stref);
    my $Sf = $stref->{$sub_or_func_or_inc}{$f};
    my $annlines = get_annotated_sourcelines( $stref,  $f);
    $Sf->{'RefactoredCode'} =[];
    for my $annline ( @{$annlines} ) {
        if (not defined $annline or not defined $annline->[0]) {
            croak "Undefined source code line for $f in create_refactored_source()";
        }
        my $line = $annline->[0] || '';
        my $tags_lref = $annline->[1] || {};
        if ( not exists $tags_lref->{'Comments'} ) {
            print $line, "\n" if $V;
            my @split_lines = split_long_line($line);
            for my $sline (@split_lines) {
                push @{ $Sf->{'RefactoredCode'} }, [$sline,$tags_lref];
            }
        } else {
            push @{ $Sf->{'RefactoredCode'} }, [$line, $tags_lref];
        }
    }
    return $stref;	
} # END of create_refactored_source()
# -----------------------------------------------------------------------------

# A convenience function to split long lines.
# - count the number of characters, i.e. length()
# - find the last comma before we exceed 64 characters (I guess it's really 72-5?):

sub split_long_line {
    my $line   = shift;
    my @chunks = @_;

    my $nchars = 64;
    if ( scalar(@chunks) == 0 ) {
        print "\nLINE: \n$line\n" if $V;
        $nchars = 72;
    }
    my $split_on  = ',';
    my $split_on2 = ' ';
    my $split_on3 = '.ro.';
    my $split_on4 = '.dna.';

    my $smart = 0;
    if ( length($line) > $nchars ) {
        my $patt  = '';
        my $ll    = length($line);
        my $rline = join( '', reverse( split( '', $line ) ) );

        #       print $rline,"\n";
        #       print "$ll - $nchars = ",$ll - $nchars,"\n";
        my $idx  = index( $rline, $split_on,  $ll - $nchars );
        my $idx2 = index( $rline, $split_on2, $ll - $nchars );
        my $idx3 = index( $rline, $split_on3, $ll - $nchars );
        my $idx4 = index( $rline, $split_on4, $ll - $nchars );
        if ( $idx < 0 && $idx2 < 0 && $idx3 < 0 && $idx4 < 0 ) {
            print "WARNING: Can't split line \n$line\n" if $W;
        } elsif ( $idx >= 0 ) {
            print "Split line on ", $ll - $idx, ", '$split_on'\n" if $V;
        } elsif ( $idx < 0 && $idx2 >= 0 ) {
            $idx = $idx2;
            print "Split line on ", $ll - $idx2, ", '$split_on2'\n"
              if $V;
        } elsif ( $idx < 0 && $idx2 < 0 && $idx3 >= 0 ) {
            $idx = $idx3;
            print "SPLIT line on ", $ll - $idx, ", '$split_on3'\n"
              if $V;

            # Need smarter split
            $smart = 1;
            $patt = join( '', reverse( split( '', $split_on3 ) ) );
        } elsif ( $idx < 0 && $idx2 < 0 && $idx4 >= 0 ) {
            $idx = $idx4;
            print "SPLIT line on ", $ll - $idx, ", '$split_on4'\n"
              if $V;

            # Need smarter split
            $smart = 1;
            $patt = join( '', reverse( split( '', $split_on4 ) ) );
        }

#       if ($smart==1) {
#           die substr( $line, 0, $ll - $idx3, '' ) if length(substr( $line, 0, $ll - $idx3, '' ))>$nchars;
#       }
        push @chunks, substr( $line, 0, $ll - $idx, '' );
        print "CHUNKS:\n", join( "\n", @chunks ), "\n" if $V;
        print "REST:\n", $line, "\n" if $V;
        &split_long_line( $line, @chunks );
    } else {
        push @chunks, $line;

        my @split_lines = ();
        if ( @chunks > 1 ) {
            my $fst = 1;
            my $rest=scalar @chunks;
            for my $chunk (@chunks) {
            	if ($rest>0) {
            		$rest--;
            		$chunk.= ' &'; # WARNING: FREE FORM!            		
            	}
                if ($fst) {                	
                    $fst = 0;
                } else {
                    if ( $chunk =~ /^\s*$/ ) {
                        $chunk = '';
                    } else {

                        #                       $chunk = '     &  ' . $chunk;
#                        $chunk = '     &' . $chunk;
                        $chunk = '      ' . $chunk; # WARNING: free form but with 6 spaces ...
                    }
                }
                push @split_lines, $chunk;
            }
        } else {
            @split_lines = @chunks;
        }
        if (   $split_lines[0] !~ /^\!/
            && $split_lines[0] =~ /\t/
            && $split_lines[0] !~ /^\s{6}/
            && $split_lines[0] !~ /^\t/ )
        {

            # problematic tab!
            print "WARNING: Pathological TAB in " . $split_lines[0] . "\n"
              if $W;
            my $sixspaces = ' ' x 6;
            $split_lines[0] =~ s/^\ +\t//;
            if ( length( $split_lines[0] ) > 66 ) {
                $split_lines[0] =~ s/^\s+//;
                $split_lines[0] =~ s/\s+$//;
            }
            if ( length( $split_lines[0] ) > 66 ) {
                print "WARNING: Line still too long: " . $split_lines[0] . "\n"
                  if $W;
            }
            $split_lines[0] = $sixspaces . $split_lines[0]
              unless $split_lines[0] =~ /^\s+\d+/;
        }
        return @split_lines;
    }
} # END of split_long_line()

# -----------------------------------------------------------------------------
sub get_annotated_sourcelines {
    ( my $stref, my $f ) = @_;
    my $sub_or_func_or_inc = sub_func_or_incl( $f, $stref );
    my $Sf = $stref->{$sub_or_func_or_inc}{$f};
    
    
    my $annlines=[];    
    if ($Sf->{'Status'}==2) {          
    if (not exists $Sf->{'RefactoredCode'}) {
        $Sf->{'RefactoredCode'} = [];
        $annlines=[ @{ $Sf->{'AnnLines'} } ]; # We want a copy!
    } else {
        $annlines=$Sf->{'RefactoredCode'}; # Here a ref is OK
    }	  
    } else {
    	warn "get_annotated_sourcelines( $f ) \n";
    	die caller;
    } 
	return $annlines;
} # END of get_annotated_sourcelines()