package RefactorF4Acc::Refactoring;

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

@RefactorF4Acc::Refactoring::ISA = qw(Exporter);

@RefactorF4Acc::Refactoring::EXPORT_OK = qw(
    &refactor_all_subroutines
    &refactor_includes
    &refactor_called_functions
    &refactor_subroutine_signature
);

# -----------------------------------------------------------------------------

#TODO: We need to split this into argument/globals refactoring and the other refactoring operations
#TODO: The former should only be done in marked subs and their dependencies
#TODO: The latter must be done everywhere
sub refactor_all_subroutines {
    ( my $stref ) = @_;
    for my $f ( keys %{ $stref->{'Subroutines'} } ) {
        my $Sf = $stref->{'Subroutines'}{$f};
        if ( not defined $Sf->{'Status'} ) {
            $Sf->{'Status'} = $UNREAD;
            print "WARNING: no Status for $f\n" if $W;
        }
        next if $Sf->{'Status'} == $UNREAD;
        next if $Sf->{'Status'} == $READ;
        next if $Sf->{'Status'} == $FROM_BLOCK;
      $stref = refactor_subroutine_main( $f, $stref );
    }
    return $stref;
}    # END of refactor_all_subroutines()

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

#  -----------------------------------------------------------------------------
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

=pod

=begin markdown

## Info refactoring `refactor_subroutine_main()`

Essentially, call `refactor_globals()` and then call `create_refactored_source()`

for every line:

- check if it needs changing:
- need to mark the insert points for subroutine calls that replace the refactored blocks! 
This is a node called 'RefactoredSubroutineCall'
- we also need the "entry point" for adding the declarations for the localized global variables 'ExGlobVarDecls'

* Signature: add the globals to the signature
(* VarDecls: keep as is)
* ExGlobVarDecls: add new var decls
* SubroutineCall: add globals for that subroutine to the call
* RefactoredSubroutineCall: insert a new subroutine call instead of the "begin of block" comment. 
* InBlock: skip; we need to handle the blocks separately
* BeginBlock: insert the new subroutine signature and variable declarations
* EndBlock: insert END
                      
=end markdown
=cut

sub refactor_subroutine_main {
    ( my $f, my $stref ) = @_;
    if ($V) {
        print "\n\n";
        print "#" x 80, "\n";
        print "Refactoring $f\n";
        print "REFACTORING SUBROUTINE $f\n";
        print "#" x 80, "\n";
    }
    my $Sf = $stref->{'Subroutines'}{$f};
    # First merge source lines and tags into annotated lines @{$annlines}
    my @lines = @{ $Sf->{'Lines'} };
    my @info = defined $Sf->{'Info'} ? @{ $Sf->{'Info'} } : ();
    my $annlines = [];
    for my $line (@lines) {
        my $tags = shift @info;
        push @{$annlines}, [ $line, $tags ];
    }
    # @{$rlines} is the list of refactored lines
    my $rlines = $annlines;

#croak "FIXME: if a sub calls another sub that has 'RefactorGlobals' == 1, and itself has 'RefactorGlobals' == 2,
# then this sub should be the root for the refactoring
## This means that is should be the root for the includes, no need to go any higher! 
## Also, the 'Common' includes from any sub with 'RefactorGlobals' == 1 must be lifted
## The main task is to rewrite any subroutine signatures for 'RefactorGlobals' == 1 subs so they take the globals as arguments.
#";
    if ( $Sf->{'HasCommons'} ) {
        if ( $Sf->{'RefactorGlobals'} == 1 ) {
          $rlines = refactor_globals( $stref, $f, $annlines );
        } elsif ( $Sf->{'RefactorGlobals'} == 2 ) {
            $rlines = refactor_calls_globals( $stref, $f, $annlines );
        }
    }

    if (   not exists $Sf->{'RefactoredCode'}
        or $Sf->{'RefactoredCode'} == []
        or exists $stref->{'BuildSources'}{'C'}{ $Sf->{'Source'} } )
    {
        $stref = create_refactored_source( $stref, $f, $rlines );
    }
    return $stref;
}    # END of refactor_subroutine_main()

# -----------------------------------------------------------------------------

# -----------------------------------------------------------------------------

sub refactor_globals {
    ( my $stref, my $f, my $annlines ) = @_;
    
#   croak "FIXME: the caller of a sub with RefactorGlobals should refactor its globals!";
    my $Sf = $stref->{'Subroutines'}{$f};
    if ($Sf->{'RefactorGlobals'}==2) {
        warn "FIXME: the caller of a sub with RefactorGlobals ($f) should refactor its globals!";
        # Which child has RefactorGlobals==1?
        my @additional_includes=();
        for my $cs ($Sf->{'CalledSubs'}) {          
            if ($stref->{'Subroutines'}{$cs}{'RefactorGlobals'}==1) {
                for my $inc ($stref->{'Subroutines'}{$cs}{'CommonIncludes'}) {
                    if (not exists $Sf->{'CommonIncludes'}{$inc}) {
                        push @additional_includes, $inc;
                        croak "$inc from $cs was missing from $f"; 
                    } 
                }
                
            }
        }       
    }
    print "REFACTORING GLOBALS in $f\n" if $V;
    my $rlines      = [];
    my $s           = $Sf->{'Source'};
    my $is_C_target = exists $stref->{'BuildSources'}{'C'}{$s} ? 1 : 0;
    my $idx         = 0;
    for my $annline ( @{$annlines} ) {
        my $line      = $annline->[0] || '';
        my $tags_lref = $annline->[1];
        my %tags      = ( defined $tags_lref ) ? %{$tags_lref} : ();
        print '*** ' . join( ',', keys(%tags) ) . "\n" if $V;
        print '*** ' . $line . "\n" if $V;
        my $skip = 0;

        if ( exists $tags{'Signature'} ) {
            if (not exists $Sf->{'HasRefactoredArgs'} ) {
                 # Do this before the analysis for RefactoredArgs!
                 $stref = refactor_subroutine_signature( $stref, $f );
            }
#           croak $line if $f eq 'particles_main_loop';
            $rlines =
              create_refactored_subroutine_signature( $stref, $f, $annline,
                $rlines );
#               croak Dumper($rlines) if $f eq 'particles_main_loop';
            $skip = 1;
        }

        if ( exists $tags{'Include'} ) {
            $skip = skip_common_include_statement( $stref, $f, $annline );
        }

        if ( exists $tags{'ExGlobVarDecls'} ) {
            die if $f eq 'timemanager';

            # First, abuse ExGlobVarDecls as a hook for the addional includes
            $rlines =
              create_new_include_statements( $stref, $f, $annline, $rlines );

            # Then generate declarations for ex-globals
            $rlines =
              create_exglob_var_declarations( $stref, $f, $annline, $rlines );

# While we're here, might as well generate the declarations for remapping and reshaping.
# If the subroutine contains a call to a function that requires this, of course.
# Executive decision: do this only for the routines to be translated to C/OpenCL
            for my $called_sub ( keys %{ $Sf->{'CalledSubs'} } ) {
                if ( exists $stref->{'SubsToTranslate'}{$called_sub} ) {

                 # OK, we need to do the remapping, so create the machinery here
                 # 1. Get the arguments of the called sub

# 2. Work out if they need reshaping. If so, create the declarations for the new 1-D arrays

# 3. Work out which remapped arrays will be used; create the declarations for these arrays

                }
            }

        }
        if ( exists $tags{'VarDecl'} ) {
            $rlines = create_refactored_vardecls( $stref, $f, $annline, $rlines,
                $is_C_target );
            $skip = 1;
        }
        if ( exists $tags{'SubroutineCall'} ) {

            # simply tag the common vars onto the arguments
            $rlines = create_refactored_subroutine_call( $stref, $f, $annline,
                $rlines );
                
            $skip = 1;
        }

        if ( not exists $tags{'Comments'} and $skip == 0 ) {
            $rlines =
              rename_conflicting_locals( $stref, $f, $annline, $rlines );
            $skip = 1;
        }
        push @{$rlines}, $annline unless $skip;
        $idx++;
    }
    return $rlines;
    
}    # END of refactor_globals()

# -----------------------------------------------------------------------------
sub refactor_calls_globals {
    ( my $stref, my $f, my $annlines ) = @_;
#    my $Sf = $stref->{'Subroutines'}{$f};
#    if ($Sf->{'RefactorGlobals'}==2) {
#        warn "FIXME: the caller of a sub with RefactorGlobals ($f) should refactor its globals!";
#        # Which child has RefactorGlobals==1?
#        my @additional_includes=();
#        for my $cs (keys %{ $Sf->{'CalledSubs'} }) {
#            
#            if ($stref->{'Subroutines'}{$cs}{'RefactorGlobals'}==1) {
#               warn $cs,"\n";         
#                for my $inc (keys %{ $stref->{'Subroutines'}{$cs}{'CommonIncludes'} }) {
#                   warn "\t",$inc,"\n";
#                    if (not exists $Sf->{'IncludeFiles'}{$inc} and $stref->{'IncludeFiles'}{$inc}{'InclType'} eq 'Common') {
#                        push @additional_includes, $inc;
#                        warn "$inc from $cs was missing from $f\n"; 
#                    } 
#                }
#                
#            }
#        }       
#    }

    print "REFACTORING CALLS WITH GLOBALS in $f\n" if $V;
    my $rlines      = [];
    
    my $idx         = 0;
    for my $annline ( @{$annlines} ) {
        my $line      = $annline->[0] || '';
        my $tags_lref = $annline->[1];
        my %tags      = ( defined $tags_lref ) ? %{$tags_lref} : ();
        print '*** ' . join( ',', keys(%tags) ) . "\n" if $V;
        print '*** ' . $line . "\n" if $V;
        my $skip = 0;


        if ( exists $tags{'Include'} ) {

            # First, add addional includes if required
            $rlines =
              create_additional_include_statements( $stref, $f, $annline, $rlines );

## While we're here, might as well generate the declarations for remapping and reshaping.
## If the subroutine contains a call to a function that requires this, of course.
## Executive decision: do this only for the routines to be translated to C/OpenCL
#            for my $called_sub ( keys %{ $Sf->{'CalledSubs'} } ) {
#                if ( exists $subs_to_translate{$called_sub} ) {
#
#                 # OK, we need to do the remapping, so create the machinery here
#                 # 1. Get the arguments of the called sub
#
## 2. Work out if they need reshaping. If so, create the declarations for the new 1-D arrays
#
## 3. Work out which remapped arrays will be used; create the declarations for these arrays
#
#                }
#            }
            $skip = 1;
        }
        if ( exists $tags{'SubroutineCall'} ) {

            # simply tag the common vars onto the arguments
            $rlines = create_refactored_subroutine_call( $stref, $f, $annline,
                $rlines );
                
            $skip = 1;
        }

        push @{$rlines}, $annline unless $skip;
        $idx++;
    }
    
    return $rlines;
    
}    # END of refactor_calls_globals()

# -----------------------------------------------------------------------------
sub refactor_subroutine_signature {
    ( my $stref, my $f ) = @_;
    my $Sf = $stref->{'Subroutines'}{$f};
    if ($V) {
        if ( exists $Sf->{'Args'} ) {
            print "SUB $f ORIG ARGS:" . join( ',', @{ $Sf->{'Args'} } ), "\n";
        } else {
            print "SUB $f ORIG ARGS: ()\n";
        }
    }
#   my %args               = map { $_ => 1 } @{ $Sf->{'Args'} };
    my @exglobs            = ();
    my @nexglobs           = ();
    my $conflicting_params = $Sf->{'ConflictingParams'};
    for my $inc ( keys %{ $Sf->{'Globals'} } ) {
        print "INFO: INC $inc in $f\n" if $V;
        if ( not exists $stref->{'IncludeFiles'}{$inc}{'Root'} ) {
            die "$inc has no Root in $f";
        }
        if ( $stref->{'IncludeFiles'}{$inc}{'Root'} eq $f ) {
            print "INFO: $f is root for $inc (lookup)\n" if $V;
            next;
        }
        if ( defined $Sf->{'Globals'}{$inc} ) {
            for my $var ( @{ $Sf->{'Globals'}{$inc} } ) {
                if ( not exists $Sf->{'Vars'}{$var} ) {
                    $Sf->{'Vars'}{$var} =
                      $stref->{'IncludeFiles'}{$inc}{'Vars'}{$var};
                }
            }
            print "$inc:"
              . join( ',', @{ $Sf->{'Globals'}{$inc} } ), "\n"
              if $V;
            @exglobs = ( @exglobs, @{ $Sf->{'Globals'}{$inc} } );
        }
    }
    for my $var (@exglobs) {
        if ( exists $conflicting_params->{$var} ) {
            print
"WARNING: CONFLICT in arguments for $f, renamed $var to ${var}_GLOB\n"
              if $W;
            push @nexglobs, $conflicting_params->{$var};
            $Sf->{'Vars'}{ $conflicting_params->{$var} } = $Sf->{'Vars'}{$var};
        } else {
            push @nexglobs, $var;
        }
    }
    my $args_ref = ordered_union( $Sf->{'Args'}, \@nexglobs );
    $Sf->{'RefactoredArgs'}{'List'} = $args_ref;
    return $stref;
}    # END of refactor_subroutine_signature()

# --------------------------------------------------------------------------------
sub rename_conflicting_locals {
    ( my $stref, my $f, my $annline, my $rlines ) = @_;
    my $line               = $annline->[0] || '';
    my $tags_lref          = $annline->[1];
    my $Sf                 = $stref->{'Subroutines'}{$f};
    my %conflicting_locals = ();
    if ( exists $Sf->{'ConflictingGlobals'} ) {
        %conflicting_locals = %{ $Sf->{'ConflictingGlobals'} };
    }
    my $rline = $line;
    for my $lvar ( keys %conflicting_locals ) {
        if ( $rline =~ /\b$lvar\b/ ) {
            print
"WARNING: CONFLICT in $f, renaming $lvar with $conflicting_locals{$lvar}\n"
              if $W;
            $rline =~ s/\b$lvar\b/$conflicting_locals{$lvar}/g;
        }
    }
    push @{$rlines}, [ $rline, $tags_lref ];
    return $rlines;
}    # END of rename_conflicting_locals()

# --------------------------------------------------------------------------------
sub create_refactored_vardecls {
    ( my $stref, my $f, my $annline, my $rlines, my $is_C_target ) = @_;
    my $Sf        = $stref->{'Subroutines'}{$f};
    my $line      = $annline->[0] || '';
    my $tags_lref = $annline->[1];
    my %tags      = ( defined $tags_lref ) ? %{$tags_lref} : ();
    my %args      = map { $_ => 1 } @{ $Sf->{'Args'} };
    my $globals = ( get_maybe_args_globs( $stref, $f ) )[1];
    my $skip=0;
#   my %conflicting_locals = ();
#   if ( exists $Sf->{'ConflictingGlobals'} ) {
#       %conflicting_locals = %{ $Sf->{'ConflictingGlobals'} };
#   }
    
    my @vars      = @{ $tags{'VarDecl'} };
    my @nvars = (); 
    my $rline = $line;
    for my $var (@vars) {
        my $skip_var = 0;
        if ( exists $stref->{'Functions'}{$var} ) {
            if ($is_C_target) {
                print "WARNING: $var in $f is a function!\n" if $W;
                $skip_var = 1;
            }
        }
        if ( not $skip_var ) {
            if ( exists $globals->{$var} and not exists $args{$var} ) {
                print
"WARNING: CONFLICT in $f ($Sf->{'Source'}):  renaming local $var to $var\_LOCAL\n"
                  if $W;
                my $nvar = $var . '_LOCAL';
#               $conflicting_locals{$var} = $nvar;
                $rline =~ s/\b$var\b/$nvar/;
                push @nvars, $nvar;
            } else {
                push @nvars, $var;
            }
        }
    } # @vars
    
    $rline =~ s/,\s*$//;
    my $spaces = $line;
    $spaces =~ s/[^\s].*$//;

    if ( $line !~ /\(.*?\)/ ) {   
    # If the line does not contain array decls,
    # remove the spaces from the original line and use them for the new line
        $rline =
            $spaces
          . $Sf->{'Vars'}{ $vars[0] }{'Type'} . ' '
          . join( ',', @nvars ) . "\n";       
    } else {    
        # For arrays, we split the declaration over multiple lines
        # And we use the declaration from the include                   
        for my $tnvar (@nvars) {
            $rline=$Sf->{'Vars'}{ $tnvar }{'Decl'};
            $rline=~s/^\s+//;
            $rline= $spaces.$rline;
            $tags_lref->{'VarDecl'} = [$tnvar];
            push @{$rlines}, [ $rline, $tags_lref ];
        }
        $skip=1;
    }

    push @{$rlines}, [ $rline, $tags_lref ] unless $skip==1;
    return $rlines;
}    # END of create_refactored_vardecls()

# --------------------------------------------------------------------------------
sub create_exglob_var_declarations {
    ( my $stref, my $f, my $annline, my $rlines ) = @_;
    my $Sf                 = $stref->{'Subroutines'}{$f};
#   my $line               = $annline->[0] || '';
    my $tags_lref          = $annline->[1];
#   my %tags               = ( defined $tags_lref ) ? %{$tags_lref} : ();
    my %args               = map { $_ => 1 } @{ $Sf->{'Args'} };
    my $conflicting_params = $Sf->{'ConflictingParams'};

    for my $inc ( keys %{ $Sf->{'Globals'} } ) {
        print "INFO: GLOBALS from INC $inc in $f\n" if $V;
        for my $var ( @{ $Sf->{'Globals'}{$inc} } ) {
            if ( exists $args{$var} ) {
                my $rline = "*** ARG MASKS GLOB $var in $f!";
                push @{$rlines}, [ $rline, $tags_lref ];
            } else {
                if ( exists $Sf->{'Commons'}{$inc} ) {
                    if ( $f ne $stref->{'IncludeFiles'}{$inc}{'Root'} ) {
                        print "\tGLOBAL $var from $inc in $f\n" if $V;                      
                        my $rline = $Sf->{'Commons'}{$inc}{$var}{'Decl'};
                        if ( exists $conflicting_params->{$var} ) {
                            my $gvar = $conflicting_params->{$var};
                            print
"WARNING: CONFLICT in arg decls for $f: renaming $var to ${var}_GLOB\n"
                              if $W;
                            $rline =~ s/\b$var\b/$gvar/;
                        }
                        if ( not defined $rline ) {
                            print "*** NO DECL for $var in $f, taking from INC $inc!\n" if $V;
#                           $rline = "*** NO DECL for $var in $f!";
                            # FIXME: is it OK to just generate the decls here?
                            my $decl_from_inc = $stref->{IncludeFiles}{$inc}{Vars}{$var}{Decl};
                            $rline ="$decl_from_inc"." ! from $inc";            
                        }
                        push @{$rlines}, [ $rline, $tags_lref ];
                    } elsif ($V) {
                        print last;
                    }
                } elsif ($V) {
                    print "*** NO COMMONS for $inc in $f ";
                    if ( $f eq $stref->{'IncludeFiles'}{$inc}{'Root'} ) {
                        print '(Root)' . "\n";
                    } else {
                        print 'BUT NOT ROOT!' . "\n";
                    }
                    last;
                }
            }
        }    # for
    }
#   die if $f=~/particles_main/;
    return $rlines;
}    # END of create_exglob_var_declarations()
# --------------------------------------------------------------------------------
sub create_additional_include_statements {
    ( my $stref, my $f, my $annline, my $rlines ) = @_;
    my $Sf        = $stref->{'Subroutines'}{$f};    
        # Which child has RefactorGlobals==1?
    my @additional_includes=();
    for my $cs (keys %{ $Sf->{'CalledSubs'} }) {             
        if ($stref->{'Subroutines'}{$cs}{'RefactorGlobals'}==1) {
            for my $inc (keys %{ $stref->{'Subroutines'}{$cs}{'CommonIncludes'} }) {
                if (not exists $Sf->{'Includes'}{$inc} and $stref->{'IncludeFiles'}{$inc}{'InclType'} eq 'Common') {
                    push @additional_includes, $inc;
                } 
            }
        }
    }        
    
    my $tags_lref = $annline->[1];
    for my $inc (@additional_includes) {
            print "INFO: instantiating merged INC $inc in $f\n" if $V;
            my $rline = "      include '$inc'";
            $tags_lref->{'Include'}{'Name'} = $inc;
            push @{$rlines}, [ $rline, $tags_lref ];        
    }

    return $rlines;
}    # END of create_additional_include_statements()

# --------------------------------------------------------------------------------
# --------------------------------------------------------------------------------
sub create_new_include_statements {
    ( my $stref, my $f, my $annline, my $rlines ) = @_;
    my $Sf        = $stref->{'Subroutines'}{$f};    
    
    my $tags_lref = $annline->[1];

    for my $inc ( keys %{ $Sf->{'Globals'} } ) {
        print "INC: $inc, root: $stref->{'IncludeFiles'}{$inc}{'Root'} \n"
          if $V;
        if ( exists $Sf->{'CommonIncludes'}{$inc}
            and $f eq $stref->{'IncludeFiles'}{$inc}{'Root'} )
        {    
            print "INFO: instantiating merged INC $inc in $f\n" if $V;
            my $rline = "      include '$inc'";
            $tags_lref->{'Include'}{'Name'} = $inc;
            push @{$rlines}, [ $rline, $tags_lref ];
        }
    }
    return $rlines;
}    # END of create_new_include_statements()

# --------------------------------------------------------------------------------
sub skip_common_include_statement {
    ( my $stref, my $f, my $annline ) = @_;
#   my $line      = $annline->[0] || '';
    my $tags_lref = $annline->[1];
    my %tags      = ( defined $tags_lref ) ? %{$tags_lref} : ();
    my $skip      = 0;
    my $inc       = $tags{'Include'}{'Name'};
    print "INFO: INC $inc in $f\n" if $V;
    if ( $stref->{'IncludeFiles'}{$inc}{'InclType'} eq 'Common' ) {

        if ($V) {
            print "SKIPPED $inc: Root: ",
              ( $stref->{'IncludeFiles'}{$inc}{'Root'} ne $f ) ? 0 : 1,
              "\tTop:",
              (       ( $stref->{'IncludeFiles'}{$inc}{'Root'} eq $f )
                  and ( $f eq $stref->{'Top'} ) ) ? 1 : 0, "\n";
        }
        $skip = 1;
    }
    return $skip;
}    # END of skip_common_include_statement()

# --------------------------------------------------------------------------------
sub create_refactored_subroutine_signature {
    ( my $stref, my $f, my $annline, my $rlines ) = @_;
    my $Sf        = $stref->{'Subroutines'}{$f};
#   my $line      = $annline->[0] || '';
    my $tags_lref = $annline->[1];
    my %tags      = ( defined $tags_lref ) ? %{$tags_lref} : ();
#   ( my $maybe_args, my $globals ) = get_maybe_args_globs( $stref, $f );
    my $args_ref = $Sf->{'RefactoredArgs'}{'List'};
    my $args_str = join( ',', @{$args_ref} );
    print "NEW ARGS: $args_str\n" if $V;
    my $rline = '';

    if ( $Sf->{'Program'} ) {
        $rline = '      program ' . $f;
    } else {
        $rline = '      subroutine ' . $f . '(' . $args_str . ')';
    }
    $tags{'Refactored'} = 1;
    $Sf->{'HasRefactoredArgs'} = 1;
    push @{$rlines}, [ $rline, $tags_lref ];

    # IO direction information
    for my $arg ( @{$args_ref} ) {
        if ( exists $Sf->{'RefactoredArgs'}{$arg}{'IODir'} ) {
            my $iodir = $Sf->{'RefactoredArgs'}{$arg}{'IODir'};
            my $kind  = $Sf->{'RefactoredArgs'}{$arg}{'Kind'};    #Unknown';
            my $type  = $Sf->{'RefactoredArgs'}{$arg}{'Type'};    #Unknown';

            my $ntabs = ' ' x 8;
            if ( $iodir eq 'In' and $kind eq 'Scalar' ) {
                $ntabs = '';
            } elsif ( $iodir eq 'Out' ) {
                $ntabs = ' ' x 4;
            }
            my $comment = "C      $ntabs$arg:\t$iodir, $kind, $type";
            push @${rlines}, [ $comment, { 'Comment' => 1 } ];
        } else {
            print "WARNING: No IO info for $arg in $f\n" if $W;
        }
    }
    return $rlines;
}    # END of create_refactored_subroutine_signature()

# ----------------------------------------------------------------------------------------------------
sub create_refactored_subroutine_call {
    ( my $stref, my $f, my $annline, my $rlines ) = @_;
    my $Sf        = $stref->{'Subroutines'}{$f};
    my $line      = $annline->[0] || '';
    my $tags_lref = $annline->[1];
    my %tags      = ( defined $tags_lref ) ? %{$tags_lref} : ();

    # simply tag the common vars onto the arguments
    my $name = $tags{'SubroutineCall'}{'Name'};

    my $conflicting_locals = {};
    if ( exists $Sf->{'ConflictingGlobals'} ) {
        $conflicting_locals = $Sf->{'ConflictingGlobals'};
    }
    my $globals = determine_exglob_subroutine_call_args( $stref, $f, $name );
    my $orig_args = [];
    for my $arg ( @{ $tags{'SubroutineCall'}{'Args'} } ) {
        if ( exists $conflicting_locals->{$arg} ) {
            push @{$orig_args}, $conflicting_locals->{$arg};
        } else {
            push @{$orig_args}, $arg;
        }
    }
    my $args_ref = ordered_union( $orig_args, $globals );

    my $args_str = join( ',', @{$args_ref} );
    $line =~ s/call\s.*$//;
    my $rline = "call $name($args_str)\n";
    push @{$rlines}, [ $line . $rline, $tags_lref ];
    return $rlines;
}    # END of create_refactored_subroutine_call()

# ----------------------------------------------------------------------------------------------------
sub determine_exglob_subroutine_call_args {
    ( my $stref, my $f, my $name ) = @_;
    my $Sf                 = $stref->{'Subroutines'}{$f};
    my $Sname              = $stref->{'Subroutines'}{$name};
    my %conflicting_locals = ();
    my %conflicting_params = ();
    if ( exists $Sf->{'ConflictingParams'} ) {
        %conflicting_params = %{ $Sf->{'ConflictingParams'} };
    }
    if ( exists $Sf->{'ConflictingGlobals'} ) {
        %conflicting_locals = %{ $Sf->{'ConflictingGlobals'} };
    }
    my %conflicting_exglobs_params = ();
    if (%conflicting_params) {
        %conflicting_exglobs_params =
          ( %conflicting_locals, %conflicting_params );
    }
    my @globals = ();
    for my $inc ( keys %{ $Sname->{'Globals'} } ) {
        next if $stref->{'IncludeFiles'}{$inc}{'Root'} eq $name;
        if ( defined $Sname->{'Globals'}{$inc} ) {
            if (%conflicting_exglobs_params) {
                for my $var ( @{ $Sname->{'Globals'}{$inc} } ) {
                    if ( exists $conflicting_exglobs_params{$var} ) {
                        print
"WARNING: CONFLICT in call to $name in $f:renaming $var with ${var}_GLOB!\n"
                          if $W;
                        push @globals, $conflicting_exglobs_params{$var};
                    } else {
                        push @globals, $var;
                    }
                }
            } else {
                @globals = ( @globals, @{ $Sname->{'Globals'}{$inc} } );
            }
        }
    }

    return \@globals;
}    # END of determine_exglob_subroutine_call_args

# ----------------------------------------------------------------------------------------------------
sub refactor_subroutine_call_args {
    ( my $stref, my $f, my $idx ) = @_;
    my $Sf   = $stref->{'Subroutines'}{$f};
    my $tags = $Sf->{'Info'}[$idx];

    # simply tag the common vars onto the arguments
    my $name               = $tags->{'SubroutineCall'}{'Name'};
    my $Sname              = $stref->{'Subroutines'}{$name};
    my %conflicting_locals = ();
    my %conflicting_params = ();
    if ( exists $Sf->{'ConflictingParams'} ) {
        %conflicting_params = %{ $Sf->{'ConflictingParams'} };
    }
    if ( exists $Sf->{'ConflictingGlobals'} ) {
        %conflicting_locals = %{ $Sf->{'ConflictingGlobals'} };
    }
    my %conflicting_exglobs_params = ();
    if (%conflicting_params) {
        %conflicting_exglobs_params =
          ( %conflicting_locals, %conflicting_params );
    }
    my @globals = ();
    for my $inc ( keys %{ $Sname->{'Globals'} } ) {
        next if $stref->{'IncludeFiles'}{$inc}{'Root'} eq $name;
        if ( defined $Sname->{'Globals'}{$inc} ) {
            if (%conflicting_exglobs_params) {
                for my $var ( @{ $Sname->{'Globals'}{$inc} } ) {
                    if ( exists $conflicting_exglobs_params{$var} ) {
                        print
"WARNING: CONFLICT in call to $name in $f:renaming $var with ${var}_GLOB!\n"
                          if $W;
                        push @globals, $conflicting_exglobs_params{$var};
                    } else {
                        push @globals, $var;
                    }
                }
            } else {
                @globals = ( @globals, @{ $Sname->{'Globals'}{$inc} } );
            }
        }
    }

    my $orig_args = [];
    for my $arg ( @{ $tags->{'SubroutineCall'}{'Args'} } ) {
        if ( exists $conflicting_locals{$arg} ) {
            push @{$orig_args}, $conflicting_locals{$arg};
        } else {
            push @{$orig_args}, $arg;
        }
    }
    my $args_ref = ordered_union( $orig_args, \@globals );
    $tags->{'SubroutineCall'}{'RefactoredArgs'} = $args_ref;
    $Sf->{'Info'}[$idx] = $tags;
    return $stref;
}    # END of refactor_subroutine_call_args
# -----------------------------------------------------------------------------

#* BeginDo: just remove the label
#* EndDo: replace label CONTINUE by END DO
#* Break: keep as is; add a comment to identify it as a break
#* Goto: Do nothing
#* GotoTarget: Do nothing
#* NoopBreakTarget: replace CONTINUE with "call noop"
#* BreakTarget: Do nothing
sub create_refactored_source {
    ( my $stref, my $f, my $annlines ) = @_;
    print "CREATING FINAL $f CODE\n" if $V;
#   my $rlines      = [];
    my @extra_lines = ();
    my $sub_or_func =
      ( exists $stref->{'Subroutines'}{$f} ) ? 'Subroutines' : 'Functions';
    my $Sf = $stref->{$sub_or_func}{$f};
    $Sf->{'RefactoredCode'} = [];
    
    for my $annline ( @{$annlines} ) {
        if (not defined $annline or not defined $annline->[0]) {
            print "BOOM!";
        }
        my $line = $annline->[0] || '';    # FIXME: why would line be undefined?
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
            if ( $line =~ /^\s{0,4}\d+\s+continue/ ) {
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
        if ( not exists $tags{'Comments'} ) {
            print $line, "\n" if $V;
            my @split_lines = split_long_line($line);
            for my $sline (@split_lines) {
                push @{ $Sf->{'RefactoredCode'} }, $sline;
            }
            if (@extra_lines) {
                for my $extra_line (@extra_lines) {
                    push @{ $Sf->{'RefactoredCode'} },
                      $extra_line;
                }
                @extra_lines = ();
            }
        } else {
            push @{ $Sf->{'RefactoredCode'} }, $line;
        }
    }
    return $stref;
}    # END of create_refactored_source()

# -----------------------------------------------------------------------------
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
            for my $chunk (@chunks) {
                if ($fst) {
                    $fst = 0;
                } else {
                    if ( $chunk =~ /^\s*$/ ) {
                        $chunk = '';
                    } else {

                        #                       $chunk = '     &  ' . $chunk;
                        $chunk = '     &' . $chunk;
                    }
                }
                push @split_lines, $chunk;
            }
        } else {
            @split_lines = @chunks;
        }
        if (   $split_lines[0] !~ /^C/
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
}

# -----------------------------------------------------------------------------