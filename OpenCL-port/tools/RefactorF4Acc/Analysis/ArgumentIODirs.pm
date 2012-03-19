package RefactorF4Acc::Analysis::ArgumentIODirs;

use RefactorF4Acc::Config;
use RefactorF4Acc::Utils;
use RefactorF4Acc::Refactoring::Subroutines::Signatures qw( refactor_subroutine_signature );
use RefactorF4Acc::Refactoring::Subroutines::Calls qw( refactor_subroutine_call_args);
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

@RefactorF4Acc::Analysis::ArgumentIODirs::ISA = qw(Exporter);

@RefactorF4Acc::Analysis::ArgumentIODirs::EXPORT_OK = qw(
    &determine_argument_io_direction_rec
);

# -----------------------------------------------------------------------------
# We do a recusive descent for all called subroutines, and for the leaves we do the analysis
sub determine_argument_io_direction_rec {
    ( my $f, my $stref ) = @_;
    my $c = (defined $stref->{Counter}) ? $stref->{Counter} : 0;
    print "\t" x $c; print "$f\n";
    my $Sf = $stref->{'Subroutines'}{$f};
    if ( exists $Sf->{'CalledSubs'} ) {
        for my $calledsub ( keys %{ $Sf->{'CalledSubs'} } ) {
            $stref->{Counter}++;
            $stref = determine_argument_io_direction_rec( $calledsub, $stref );
            $stref->{Counter}--;
        }
#   die "Resolved IO for called subs, now use it!\n" if $f =~ /advance/;
        $stref = determine_argument_io_direction_core( $stref, $f );
    } else {
# For a leaf, this should resolve all
# For a non-leaf, we should merge the declarations from the calls
# This is more tricky than it seems because a sub can be called multiple times with different arguments.
# So first we need to determine the argument of the call, then map them to the arguments of the sub
        $stref = refactor_subroutine_signature( $stref, $f );
        $stref = determine_argument_io_direction_core( $stref, $f );
    }
    return $stref;
}    # determine_argument_io_direction_rec()

# -----------------------------------------------------------------------------
sub determine_argument_io_direction_core {
    ( my $stref, my $f ) = @_;
    my $Sf      = $stref->{'Subroutines'}{$f};
    my $srcref  = $Sf->{'Lines'};
    my $tagsref = $Sf->{'Info'};

    #   local $V=1 if $f=~/advance/;
    print "DETERMINE IO DIR FOR SUB $f\n" if $V;
    my $ref_sig_args    = $Sf->{'RefactoredArgs'}{'List'};
    my %args            = map { $_ => 'Unknown' } @{$ref_sig_args};
    my $called_sub_args = {};
    my $called_sub      = "";

    # Then for each of these, we go through the args.
    # If an arg has a non-'U' value, we overwrite it.

    if ( defined $srcref ) {
        for my $index ( 0 .. scalar( @{$srcref} ) - 1 ) {
            my $line = $srcref->[$index];

            my $tags = $tagsref->[$index];
            if ( $line =~ /^C\s+/ ) {
                next;
            }

            # Skip the declarations
            if ( exists $tags->{'VarDecl'} ) { next; }

            # Write & File open statements
            if ( $line =~ /^\s+(?:write|open)\s*\(\s*(.+)$/ ) {
                find_vars( $1, \%args, \&set_io_dir );
                for my $csub ( keys %{$called_sub_args} ) {
                    if ( %{ $called_sub_args->{$csub} } ) {
                        find_vars( $1, $called_sub_args->{$csub},
                            \&set_io_dir );
                    }
                }

            }
            if ( exists $tags->{'SubroutineCall'} ) {
                my $name  = $tags->{'SubroutineCall'}{'Name'};
                my $Sname = $stref->{'Subroutines'}{$name};
                ( my $iodirs, $stref ) =
                  get_iodirs_from_subcall( $stref, $f, $index );
                for my $var ( keys %{$iodirs} ) {
                    if ( exists $args{$var} ) {
                        if ( $iodirs->{$var} eq 'In' ) {
                            if ( $args{$var} eq 'Unknown' ) {
                                $args{$var} = 'In';
                            } elsif ( $args{$var} eq 'Out' ) {

       # if the parent arg is Out and the child arg is In, parent arg stays Out!
                                $args{$var} = 'Out';
                            }
                        } elsif ( $iodirs->{$var} eq 'InOut' ) {
                            if ( $args{$var} eq 'Unknown' ) {
                                $args{$var} = 'InOut';
                            } elsif ( $args{$var} eq 'Out' ) {
                                $args{$var} = 'Out';
                            }
                        } elsif ( $iodirs->{$var} eq 'Out' ) {
                            if ( $args{$var} eq 'Unknown' ) {
                                $args{$var} = 'Out';
                            } elsif ( $args{$var} eq 'In' ) {
                                $args{$var} = 'InOut';
                            }
                        } else {
                            print
"WARNING: IO direction for $var in call to $name in $f is Unknown\n"
                              if $W;
                        }
                    } else {

                        #                               print "$var is LOCAL".$iodirs->{$var}."\n";
                    }
                }
                if ( scalar keys %{ $Sname->{'Callers'} } == 1
                    and $Sname->{'Callers'}{$f} == 1 )
                {
                    $called_sub = $name;
                } else {
                    $called_sub = "";
                }
                if ( $line =~ /^\s*if\s*\((.+)\)\s+call\s+/ ) {
                    my $cond = $1;
                    $cond =~ s/[\(\)]+//g;
                    $cond =~ s/\.(eq|ne|gt|ge|lt|le|and|or|not|eqv|neqv)\./ /;
                    find_vars( $cond, \%args, \&set_io_dir );
                    for my $csub ( keys %{$called_sub_args} ) {
                        if ( %{ $called_sub_args->{$csub} } ) {
                            find_vars( $cond, $called_sub_args->{$csub},
                                \&set_io_dir );
                        }
                    }
                }
                if ( $called_sub ne "" ) {
                    $called_sub_args->{$called_sub} = $iodirs;
                }
                next;
            }

            # Encounter Assignment
            if (    $line =~ /\s+(\w+)(?:\([^=]*\))?\s*=\s*(.+?)\s*$/
                and $line !~ /^\s*do\s+.+\s*=/ )
            {    # Assignment, but not a loop. FIXME: This is weak!
                my $var = $1;
                my $rhs = $2;
                if ( exists $args{$var} ) {

                    if ( $args{$var} eq 'Unknown' ) {
                        print "LINE: $line\n"     if $V;
                        print "ARG $var: 'Out'\n" if $V;
                        $args{$var} = 'Out';
                    } elsif ( $args{$var} eq 'In' ) {
                        print "LINE: $line\n"       if $V;
                        print "ARG $var: 'InOut'\n" if $V;
                        $args{$var} = 'InOut';
                    }
                }
                if ( $line =~ /^\s*if/ ) {
                    my $cond =
                      ( split( /\s+(\w+)(?:\([^=]*\))?\s*=\s*/, $line ) )[0];
                    find_vars( $cond, \%args, \&set_io_dir );
                    for my $csub ( keys %{$called_sub_args} ) {
                        if ( %{ $called_sub_args->{$csub} } ) {
                            find_vars( $cond, $called_sub_args->{$csub},
                                \&set_io_dir );
                        }
                    }

                }
                find_vars( $rhs, \%args, \&set_io_dir );
                for my $csub ( keys %{$called_sub_args} ) {
                    if ( %{ $called_sub_args->{$csub} } ) {
                        find_vars( $rhs, $called_sub_args->{$csub},
                            \&set_io_dir );
                    }
                }

            } else {    # not an assignment, do as before
                print "LINE: $line\n" if $V;
                find_vars( $line, \%args, \&set_io_dir );
                for my $csub ( keys %{$called_sub_args} ) {
                    if ( %{ $called_sub_args->{$csub} } ) {
                        find_vars( $line, $called_sub_args->{$csub},
                            \&set_io_dir );
                    }
                }

            }
        }
    }
    for my $csub ( keys %{$called_sub_args} ) {
        for my $arg ( keys %{ $called_sub_args->{$csub} } ) {
            if ( $called_sub_args->{$csub}{$arg} eq 'InMaybeOut' ) {

         #                  print "ARG $arg for call to $csub in $f is actually 'In'\n";
         #                  $called_sub_args->{$csub}{$arg}='In';
                $stref->{'Subroutines'}{$csub}{'RefactoredArgs'}{$arg}
                  {'IODir'} = 'In';
            }
        }
    }

    my $maybe_args = ( get_maybe_args_globs( $stref, $f ) )[0];
    for my $arg ( keys %args ) {
        $Sf->{'RefactoredArgs'}{$arg}{'IODir'} = $args{$arg};
        my $kind  = 'Unknown';
        my $type  = 'Unknown';
        my $shape = [];
        if ( exists $maybe_args->{$arg}{'Type'} ) {
            $kind  = $maybe_args->{$arg}{'Kind'};
            $type  = $maybe_args->{$arg}{'Type'};
            $shape = $maybe_args->{$arg}{'Shape'};
        } else {
            print "WARNING: No kind/type info for $arg in $f\n" if $W;
        }

        $Sf->{'RefactoredArgs'}{$arg}{'Kind'}  = $kind;
        $Sf->{'RefactoredArgs'}{$arg}{'Type'}  = $type;
        $Sf->{'RefactoredArgs'}{$arg}{'Shape'} = $shape;
    }
     # FIXME: I don't think this should be done here
#TODO   $stref = remap_args( $stref, $f );   
#TODO   $stref = reshape_args( $stref, $f );    
    return $stref;
}    # determine_argument_io_direction_core()

# -----------------------------------------------------------------------------
# To determine if a subroutine argument is I, O or IO:
# if it appears only on the LHS of an '=' => O
# if does not appear on the LHS of an '=' => I
# otherwise => IO
# So start by setting them all to 'I'
# so, look for '=' and split in LHS/RHS

# -----------------------------------------------------------------------------
# This function works on RHS variables, i.e. variables being read
# The rules are
# Read =>
#   Unknown => In
#   Out => InOut
# Write =>
#   Out
sub set_io_dir {
    ( my $mvar, my $args_ref ) = @_;
    if ( $args_ref->{$mvar} eq 'Out' or $args_ref->{$mvar} eq 'InMaybeOut' ) {
        print "FOUND InOut ARG $mvar\n" if $V;

        #               warn "$mvar is InMaybeOut\n";
        $args_ref->{$mvar} = 'InOut';
    } elsif ( $args_ref->{$mvar} eq 'Unknown' ) {
        print "FOUND In ARG $mvar\n" if $V;
        $args_ref->{$mvar} = 'In';
    }
    return $args_ref;
}

# -----------------------------------------------------------------------------
sub find_vars {
    ( my $line, my $args_ref, my $subref ) = @_;
    my %args = %{$args_ref};
    my @chunks = split( /\W+/, $line );
    for my $mvar (@chunks) {
        if ( exists $args{$mvar} ) {
            $args_ref = $subref->( $mvar, $args_ref );
        }
    }
    return $args_ref;
}    # END of find_vars()
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
sub get_iodirs_from_subcall {
	( my $stref, my $f, my $index ) = @_;

	# First refactor!
	$stref = refactor_subroutine_call_args( $stref, $f, $index );
	my $Sf    = $stref->{'Subroutines'}{$f};
	my $tags  = $Sf->{'Info'}->[$index];
	my $name  = $tags->{'SubroutineCall'}{'Name'};
	my $Sname = $stref->{'Subroutines'}{$name};
	my %args =
	  map { $_ => 1 } @{ $Sf->{'RefactoredArgs'}{'List'} };
	my $called_arg_iodirs = {};

	# Now get the RefactoredArgs
	my $ref_call_args =
	  $Sf->{'Info'}->[$index]{'SubroutineCall'}{'RefactoredArgs'};

#                print "CALL to $name in $f\n";#" (".join(',',@{ $Sf->{'RefactoredArgs'}{'List'} }).")\n";
#               print "CALL $name: ",join(',',@{ $ref_call_args })."\n";
# Get the RefactoredArgList
	my $ref_sig_args = $Sname->{'RefactoredArgs'}{'List'};
#FIXME: experimental!
    croak "FIXME: need to make sure all calls & sigs are refactored before doing IO analysis!!!";
    if ( scalar( @{$ref_sig_args} ) == 0) {
        $ref_sig_args = $Sname->{'Args'};
	    $Sname->{'RefactoredArgs'}={};
	    $Sname->{'RefactoredArgs'}{'List'}=$Sname->{'Args'};
    }
	#               print " SIG $name: ",join(',',@{ $ref_sig_args })."\n";
	my $ca = scalar( @{$ref_call_args} );
	my $sa = scalar( @{$ref_sig_args} );
	if ( $ca != $sa ) {
        print "WARNING ($f): NOT SAME LENGTH! ($ca<>$sa)\n" if $W;
		print $f.'->'.$name.': CALL:'.Dumper( $ref_call_args )."\nSIG:". Dumper( $ref_sig_args );
        croak;
	} else {
		my $i = 0;
		for my $call_arg ( @{$ref_call_args} ) {
			my $sig_arg = $ref_sig_args->[$i];

			# int is a FORTRAN primitive converting float to int
			# int2|short is a FORTRAN primitive converting float to int
			# int8|long is a FORTRAN primitive converting float to int
			# float is a FORTRAN primitive converting int to float
			# dfloat|dble is a FORTRAN primitive converting int to float
			# sngl is a FORTRAN primitive converting double to float
			$call_arg =~
			  s/(^|\W)(?:int|int2|int8|short|long|sngl|dfloat|dble|float)\(//
			  && $call_arg =~ s/\)$//;

			# Clean up call args for comparison
			$call_arg =~ s/(\w+)\(.*?\)/$1/g;
			$i++;
			if ( exists $args{$call_arg} ) {

				# This means that $call_arg is an argument of the caller $f
				# look up the IO direction for the corresponding $sig_arg
				$called_arg_iodirs->{$call_arg} =
				  $Sname->{'RefactoredArgs'}{$sig_arg}{'IODir'};
			} else {
				if ( $call_arg =~ /\W/ ) {
					print
"INFO: ARG $call_arg in call to $name in $f is an expression\n"
					  if $V;
					my @maybe_args = split( /\W+/, $call_arg );
					for my $maybe_arg (@maybe_args) {
						if ( exists $args{$maybe_arg}
							and not exists $called_arg_iodirs->{$maybe_arg} )
						{
							print
"INFO: Setting IO dir for $maybe_arg in call to $name in $f to In\n"
							  if $V;
							$called_arg_iodirs->{$maybe_arg} = 'In';
							if (    scalar keys %{ $Sname->{'Callers'} } == 1
								and $Sname->{'Callers'}{$f} == 1
								and
								$Sname->{'RefactoredArgs'}{$sig_arg}{'IODir'} ne
								'In' )
							{
								print
"INFO: $name in $f is called only once; $sig_arg is an expression, setting IODir to 'In'\n"
								  if $I;
								$Sname->{'RefactoredArgs'}{$sig_arg}{'IODir'} =
								  'In';
							}
						}
					}
				} elsif ( $call_arg =~ /^\s*[\d\.]+\s*$/ ) {
					if (    scalar keys %{ $Sname->{'Callers'} } == 1
						and $Sname->{'Callers'}{$f} == 1
						and $Sname->{'RefactoredArgs'}{$sig_arg}{'IODir'} ne
						'In' )
					{
						print
"INFO: $name in $f is called only once; $sig_arg is a numeric constant, setting IODir to 'In'\n"
						  if $I;
						$Sname->{'RefactoredArgs'}{$sig_arg}{'IODir'} = 'In';
					}
				} else {

				   # This means the call argument must be a local variable of $f
				   #					print "LOCAL $call_arg for call to $name in $f\n";
                    if (exists $Sname->{'RefactoredArgs'}{$sig_arg}) {
					$called_arg_iodirs->{$call_arg} =
					  $Sname->{'RefactoredArgs'}{$sig_arg}{'IODir'};
					if ( $called_arg_iodirs->{$call_arg} eq 'InOut' ) {
						$called_arg_iodirs->{$call_arg} = 'InMaybeOut';
					}
                    } else {
                        warn "Could not determine IODir for $call_arg in $name because there is no RefactoredArgs\n";
                    }
				}
			}
		}
	}
	return ( $called_arg_iodirs, $stref );
}    # END of get_iodirs_from_subcall()

# -----------------------------------------------------------------------------
