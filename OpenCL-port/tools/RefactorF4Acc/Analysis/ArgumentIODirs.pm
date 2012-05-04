package RefactorF4Acc::Analysis::ArgumentIODirs;


use RefactorF4Acc::Config;
use RefactorF4Acc::Utils;
use RefactorF4Acc::Refactoring::Common qw( get_annotated_sourcelines );
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
    my $c;
    if ($V) {
    $c = (defined $stref->{Counter}) ? $stref->{Counter} : 0;
    print "\t" x $c, $f,"\n";
    }
    
    my $Sf = $stref->{'Subroutines'}{$f};
    if ( exists $Sf->{'CalledSubs'} ) {
        for my $calledsub ( keys %{ $Sf->{'CalledSubs'} } ) {
            $stref->{Counter}++ if $V;
            $stref = determine_argument_io_direction_rec( $calledsub, $stref );
            $stref->{Counter}-- if $V;
        }
#   die "Resolved IO for called subs, now use it!\n" if $f =~ /advance/;
        print "\t" x $c, "--------\n" if $V;
        $stref = determine_argument_io_direction_core( $stref, $f );
    } else {
#    	print "\t" x $c; print "LEAF\n";
# For a leaf, this should resolve all
# For a non-leaf, we should merge the declarations from the calls
# This is more tricky than it seems because a sub can be called multiple times with different arguments.
# So first we need to determine the argument of the call, then map them to the arguments of the sub
#        $stref = refactor_subroutine_signature( $stref, $f );
        $stref = determine_argument_io_direction_core( $stref, $f );
    }
    return $stref;
}    # determine_argument_io_direction_rec()

# -----------------------------------------------------------------------------
sub determine_argument_io_direction_core {
    ( my $stref, my $f ) = @_;
    my $Sf      = $stref->{'Subroutines'}{$f};

    #   local $V=1 if $f=~/advance/;
    print "DETERMINE IO DIR FOR SUB $f\n" if $V;
#    my $ref_sig_args    = $Sf->{'RefactoredArgs'}{'List'};
#    my $args            = $Sf->{'RefactoredArgs'}{'Set'};# map { $_ => 'Unknown' } @{$ref_sig_args};
#    print 'determine_argument_io_direction_core() '.$f."\n".Dumper($args);
#    my $called_sub_args = {};
#    my $called_sub      = "";

    # Then for each of these, we go through the args.
    # If an arg has a non-'U' value, we overwrite it.
    $stref = analyse_src_for_iodirs($stref,$f);
    $Sf=$stref->{'Subroutines'}{$f};
    my $args = $Sf->{'RefactoredArgs'}{'Set'};
#    print "ARGS of $f after analyse_src_for_iodirs:\n". Dumper( $args  );

#    # Add the iodirs from the called sub analysis to the refactored args 
#    for my $carg ( keys %{$called_sub_args} ) {
#           
#            	if (exists $args->{$carg} ) {
#            		 if ( $called_sub_args->{$carg} eq 'InMaybeOut' ) { 
#                    $args->{$carg}{'IODir'} = 'In';
#            		 } else {
#            		 	$args->{$carg}{'IODir'} = $called_sub_args->{$carg}; 
#            		 }
#            	} else {
#            		warn "$carg is not an argument for $f\n";
#            		warn Dumper($args);
#            	}
#        }    

    my $maybe_args = ( get_maybe_args_globs( $stref, $f ) )[0];
    for my $arg ( keys %{ $args} ) {
#    	print $arg,"\n";
#    	print Dumper( $maybe_args->{$arg} ),"\n";
#        $args->{$arg}{'IODir'} = $args->{$arg};
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
#        print Dumper( $args ),"\n";
        $args->{$arg}{'Kind'}  = $kind;
        $args->{$arg}{'Type'}  = $type;
        $args->{$arg}{'Shape'} = $shape;
    }
#    die "==>".Dumper($args) if $f=~/caldate/;
     # FIXME: I don't think this should be done here
#TODO   $stref = remap_args( $stref, $f );   
#TODO   $stref = reshape_args( $stref, $f );    
    $stref->{'Subroutines'}{$f}{'RefactoredArgs'}{'Set'}=$args;
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
    
    if ( $args_ref->{$mvar}{'IODir'} eq 'Out' or $args_ref->{$mvar}{'IODir'} eq 'InMaybeOut' ) {
        print "FOUND InOut ARG $mvar\n" if $V;
        $args_ref->{$mvar}{'IODir'} = 'InOut';
    } elsif ( $args_ref->{$mvar}{'IODir'} eq 'Unknown' ) {
        print "FOUND In ARG $mvar\n" if $V;
        $args_ref->{$mvar}{'IODir'} = 'In';
    }
    return $args_ref;
}

# -----------------------------------------------------------------------------
sub find_vars {
    ( my $line, my $args_ref, my $subref ) = @_;
#    warn "find_vars()\n".Dumper($args_ref);  
#    my %args = %{$args_ref};
    my @chunks = split( /\W+/, $line );
    for my $mvar (@chunks) {    
#    	warn "MVAR:$mvar\n";	
        if ( exists $args_ref->{$mvar} && exists $args_ref->{$mvar}{'IODir'} ) {
#        	warn "MVAR OK!:$mvar\n";      	
            $args_ref = $subref->( $mvar, $args_ref );
        }
    }
#    print "find_vars() RETURN:\n".Dumper($args_ref);
    return $args_ref;
}    # END of find_vars()
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
# The code needs to be reworked:
# The main issue is that the names of the args a sub is called with is not the same as the name in the signature.
# So we need to establish the mapping. This is what get_iodirs_from_subcall() should do -- and nothing else.

sub get_iodirs_from_subcall {
	( my $stref, my $f, my $index, my $annlines ) = @_;
	
	my $Sf    = $stref->{'Subroutines'}{$f};
#	my $tags = ${get_annotated_sourcelines($stref,$f)}[$index][1];
	my $line = $annlines->[$index][0];
	my $tags = $annlines->[$index][1];
#	print Dumper($tags);
	my $name  = $tags->{'SubroutineCall'}{'Name'};			 	
	my $Sname = $stref->{'Subroutines'}{$name};
#	print "get_iodirs_from_subcall() for $name in $f\n";
#	print Dumper( $Sname->{ 'RefactoredArgs' } );
    if (not exists $tags->{'SubroutineCall'} or not exists $tags->{'SubroutineCall'}{'RefactoredArgs'}) {
#    	warn "ASSUMING call to $name in $f has NO RefactoredArgs\n";
       $stref = refactor_subroutine_call_args( $stref, $f, $index );
    } 
#print "CALL TO $name in $f:".Dumper( $Sname->{ 'RefactoredArgs' })   if $name=~/interpol_all/;	
	my $args = $Sf->{'RefactoredArgs'}{'Set'};
	my $called_arg_iodirs = {};

	# Now get the RefactoredArgs
	my $ref_call_args =
#	  $Sf->{'Info'}->[$index]{'SubroutineCall'}{'RefactoredArgs'};
	  $tags->{'SubroutineCall'}{'RefactoredArgs'};
    # Get the RefactoredArgs List for the signature
	my $ref_sig_args = $Sname->{'RefactoredArgs'}{'List'};
##FIXME: experimental!
##    croak "FIXME: need to make sure all calls & sigs are refactored before doing IO analysis!!!";
#    if ( not defined $ref_sig_args or scalar( @{$ref_sig_args} ) == 0) {
#    	warn "NO RefactoredArgs for $name, using Args instead\n";    	
#        $ref_sig_args = $Sname->{'Args'};
#	    $Sname->{'RefactoredArgs'}={};
#	    $Sname->{'RefactoredArgs'}{'List'}=$Sname->{'Args'};
#    }
#	#               print " SIG $name: ",join(',',@{ $ref_sig_args })."\n";
	my $ca = scalar( @{$ref_call_args} );
	my $sa = scalar( @{$ref_sig_args} );
#	if ($name eq 'calcfluxes') {
#		die Dumper($Sname);
#	}
	if ( $ca != $sa ) {
        print "WARNING ($f): NOT SAME LENGTH! ($ca<>$sa)\n" if $W;
		print "\n$f".'->'.$name.":\nCALL:".Dumper( $ref_call_args )."\nSIG:". Dumper( $ref_sig_args )."\n";
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
			  s/\b(?:int|int2|int8|short|long|sngl|dfloat|dble|float)\(// 
			  && $call_arg =~ s/\)$//; # FIXME: was (^|\W), OK? 

			# Clean up call args for comparison
			$call_arg =~ s/(\w+)\(.*?\)/$1/g;
			$i++;
			if ( exists $args->{$call_arg} ) {

				# This means that $call_arg is an argument of the caller $f
				# look up the IO direction for the corresponding $sig_arg
				$called_arg_iodirs->{$call_arg} =
				  $Sname->{'RefactoredArgs'}{'Set'}{$sig_arg}{'IODir'};
			} else {
				if ( $call_arg =~ /\W/ ) {
					print
"INFO: ARG $call_arg in call to $name in $f is an expression\n"
					  if $V;
					my @maybe_args = split( /\W+/, $call_arg );
					for my $maybe_arg (@maybe_args) {
						if ( exists $args->{$maybe_arg}
							and not exists $called_arg_iodirs->{$maybe_arg} )
						{
							print
"INFO: Setting IO dir for $maybe_arg in call to $name in $f to In\n"
							  if $V;
							$called_arg_iodirs->{$maybe_arg} = 'In';
							if (    scalar keys %{ $Sname->{'Callers'} } == 1
								and $Sname->{'Callers'}{$f} == 1
								and
								$Sname->{'RefactoredArgs'}{'Set'}{$sig_arg}{'IODir'} ne
								'In' )
							{
								print
"INFO: $name in $f is called only once; $sig_arg is an expression, setting IODir to 'In'\n"
								  if $I;
								$Sname->{'RefactoredArgs'}{'Set'}{$sig_arg}{'IODir'} =
								  'In';
							}
						}
					}
				} elsif ( $call_arg =~ /^\s*[\d\.]+\s*$/ ) {
					if (    scalar keys %{ $Sname->{'Callers'} } == 1
						and $Sname->{'Callers'}{$f} == 1
						and $Sname->{'RefactoredArgs'}{'Set'}{$sig_arg}{'IODir'} ne
						'In' )
					{
						print
"INFO: $name in $f is called only once; $sig_arg is a numeric constant, setting IODir to 'In'\n"
						  if $I;
						$Sname->{'RefactoredArgs'}{'Set'}{$sig_arg}{'IODir'} = 'In';
					}
				} else {

				   # This means the call argument must be a local variable of $f
				   #					print "LOCAL $call_arg for call to $name in $f\n";
                    if (exists $Sname->{'RefactoredArgs'}{'Set'}{$sig_arg}) {
    					$called_arg_iodirs->{$call_arg} =
	   				  $Sname->{'RefactoredArgs'}{'Set'}{$sig_arg}{'IODir'};
		      			if ( $called_arg_iodirs->{$call_arg} eq 'InOut' ) {
				    		$called_arg_iodirs->{$call_arg} = 'InMaybeOut';
					   }
                    } else {
                        print "WARNING:Could not determine IODir for $call_arg in $name because there is no RefactoredArgs{$sig_arg}\n";
                    }
				}
			}
		}
	}
	return ( $called_arg_iodirs, $stref );
}    # END of get_iodirs_from_subcall()

# -----------------------------------------------------------------------------
# Purely for clarity, maybe this routine should take the arguments as arguments?
# What we want in this routine is determine IO dirs for leaves and look them up for non-leaves
sub analyse_src_for_iodirs {
    (my $stref,my $f)=@_;
#    local $V=1;
#    print "analyse_src_for_iodirs() $f\n";
    my $Sf=$stref->{'Subroutines'}{$f};
        if (not exists $Sf->{'HasRefactoredArgs'} or $Sf->{'HasRefactoredArgs'}==0) {
        $stref = refactor_subroutine_signature( $stref, $f );
    }
#    my $ref_sig_args    = $Sf->{'RefactoredArgs'}{'List'};
#    print Dumper( $Sf  );
#    print Dumper( $Sf->{'RefactoredArgs'}  );
    my $args            = $Sf->{'RefactoredArgs'}{'Set'} ;    
#    my $called_sub_args = {}; 
#    my $called_sub      = "";
    
    my $annlines=get_annotated_sourcelines($stref,$f);
        for my $index ( 0 .. scalar( @{$annlines} ) - 1 ) {
            my $line = $annlines->[$index][0];
            my $tags = $annlines->[$index][1];
#            print $line,"\n";
#            print Dumper( $tags );
            if ( $line =~ /^\!\s+/ ) {
                next;
            }
            # Skip the signature            
            if ( exists $tags->{'Signature'} ) {
            	 next; }
            # Skip the declarations
            if ( exists $tags->{'VarDecl'} ) { next; }

            # Write & File open statements
            if ( $line =~ /^\s+(?:write|open)\s*\(\s*(.+)$/ ) {
                find_vars( $1, $args, \&set_io_dir );
#                for my $csub ( keys %{$called_sub_args} ) {
#                    if ( %{ $called_sub_args->{$csub} } ) {
#                        find_vars( $1, $called_sub_args->{$csub},
#                            \&set_io_dir );
#                    }
#                }

            }
            if ( exists $tags->{'SubroutineCall'} && exists $tags->{'SubroutineCall'}{'Name'}) {
                my $name  = $tags->{'SubroutineCall'}{'Name'};
#                my $Sname = $stref->{'Subroutines'}{$name};
                ( my $iodirs, $stref ) =
                  get_iodirs_from_subcall( $stref, $f, $index, $annlines );
#                   die "FIXME: surely we should use the recursion for this!?";
                for my $var ( keys %{$iodirs} ) {
                	# Damn Perl! exists $args->{$var}{'IODir'} creates the entry for $var if it did not exist!
                    if ( exists $args->{$var} && exists $args->{$var}{'IODir'}) {
                        if ( $iodirs->{$var} eq 'In' ) {
                            if ( $args->{$var}{'IODir'} eq 'Unknown' ) {
                                $args->{$var}{'IODir'} = 'In';
                            } elsif ( $args->{$var}{'IODir'} eq 'Out' ) {

       # if the parent arg is Out and the child arg is In, parent arg stays Out!
                                $args->{$var}{'IODir'} = 'Out';
                            }
                        } elsif ( $iodirs->{$var} eq 'InOut' ) {
                            if ( $args->{$var}{'IODir'} eq 'Unknown' ) {
                                $args->{$var}{'IODir'} = 'InOut';
                            } elsif ( $args->{$var}{'IODir'} eq 'Out' ) {
                                $args->{$var}{'IODir'} = 'Out';
                            }
                        } elsif ( $iodirs->{$var} eq 'Out' ) {
                            if ( $args->{$var}{'IODir'} eq 'Unknown' ) {
                                $args->{$var}{'IODir'} = 'Out';
                            } elsif ( $args->{$var}{'IODir'} eq 'In' ) {
                                $args->{$var}{'IODir'} = 'InOut';
                            }
                        } else {
                            print
"WARNING: IO direction for $var in call to $name in $f is Unknown\n"
                              if $V;
                        }
                    } else {

                        #                               print "$var is LOCAL".$iodirs->{$var}."\n";
                    }
                }
#                if ( scalar keys %{ $Sname->{'Callers'} } == 1
#                    and $Sname->{'Callers'}{$f} == 1 )
#                {
#                    $called_sub = $name;
#                } else {
#                    $called_sub = "";
#                }
                if ( $line =~ /^\s*if\s*\((.+)\)\s+call\s+/ ) {
                    my $cond = $1;
                    $cond =~ s/[\(\)]+//g;
                    $cond =~ s/\.(eq|ne|gt|ge|lt|le|and|or|not|eqv|neqv)\./ /;
                    find_vars( $cond, $args, \&set_io_dir );
#                    for my $csub ( keys %{$called_sub_args} ) {
#                        if ( %{ $called_sub_args->{$csub} } ) {
#                            find_vars( $cond, $called_sub_args->{$csub},
#                                \&set_io_dir );
#                        }
#                    }
                }
#                if ( $called_sub ne "" ) {
#                    $called_sub_args->{$called_sub} = $iodirs;
#                }
                next;
            } # SubroutineCall

            # Encounter Assignment
            if ($line=~/=/ and $line !~ /^\s*do\s+.+\s*=/ ) {
            	my $tline=$line;
            	$tline=~s/^\s+//;
            	$tline=~s/\s+$//;
            	(my $var, my $rhs)=split(/\s*=\s*/,$tline);
            	
#            	print "<$var> = <$rhs>\n"; 
            	
#            if (    $line =~ /\s+(\w+)(?:\([^=]*\))?\s*=\s*(.+?)\s*$/
#                and $line !~ /^\s*do\s+.+\s*=/ )
#            {    # Assignment, but not a loop. FIXME: This is weak!
#                my $var = $1;
#                my $rhs = $2;
                if ( exists $args->{$var} &&
                	 exists $args->{$var}{'IODir'} ) {                	
                    if ( $args->{$var}{'IODir'} eq 'Unknown' ) {
                        print "ALINE: $line\n"     if $V;
                        print "ARG $var: 'Out'\n" if $V;
                        $args->{$var}{'IODir'} = 'Out';
                    } elsif ( $args->{$var}{'IODir'} eq 'In' ) {
                        print "ALINE: $line\n"       if $V;
                        print "ARG $var: 'InOut'\n" if $V;
                        $args->{$var}{'IODir'} = 'InOut';
                    }
                } 
                
                if ( $line =~ /^\s*if/ ) {
                    my $cond =
                      ( split( /\s+(\w+)(?:\([^=]*\))?\s*=\s*/, $line ) )[0];
                    find_vars( $cond, $args, \&set_io_dir );
#                    for my $csub ( keys %{$called_sub_args} ) {
#                        if ( %{ $called_sub_args->{$csub} } ) {
#                            find_vars( $cond, $called_sub_args->{$csub},
#                                \&set_io_dir );
#                        }
#                    }

                }
                
                find_vars( $rhs, $args, \&set_io_dir );
#                for my $csub ( keys %{$called_sub_args} ) {
#                    if ( %{ $called_sub_args->{$csub} } ) {
#                        find_vars( $rhs, $called_sub_args->{$csub},
#                            \&set_io_dir );
#                    }
#                }
#            }
            } else {    # not an assignment, do as before
                print "NON-ASSIGNMENT LINE: $line\n" if $V;
                find_vars( $line, $args, \&set_io_dir );                
#                for my $csub ( keys %{$called_sub_args} ) {
#                    if ( %{ $called_sub_args->{$csub} } ) {
#                        find_vars( $line, $called_sub_args->{$csub},
#                            \&set_io_dir );
#                    }
#                }

            }
        }
        
        for my $arg (keys %{ $args } ) {
        	if (exists $stref->{'Subroutines'}{$f}{'RefactoredArgs'}{'Set'}{$arg}) {
                $stref->{'Subroutines'}{$f}{'RefactoredArgs'}{'Set'}{$arg} = $args->{$arg};                
        	} 
        }
#        for my $arg (keys %{ $stref->{'Subroutines'}{$f}{'RefactoredArgs'}{'Set'} } ) {
#        	if (not exists $stref->{'Subroutines'}{$f}{'RefactoredArgs'}{'Set'}{$arg}{'IODir'}) {die;
#                delete $stref->{'Subroutines'}{$f}{'RefactoredArgs'}{'Set'}{$arg};
#        	}
#        }
#        print "RETURN from analyse_src_for_iodirs(): \n".Dumper(  $stref->{'Subroutines'}{$f}{'RefactoredArgs'}{'Set'} );
        return $stref;
        
#        print "RETURN from analyse_src_for_iodirs(): ".Dumper( $called_sub_args );
#        return $called_sub_args;
} # END of analyse_src_for_iodirs()
# -----------------------------------------------------------------------------

    
