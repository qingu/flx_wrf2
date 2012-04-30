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
$Data::Dumper::Indent=0;

use Exporter;

@RefactorF4Acc::Refactoring::Common::ISA = qw(Exporter);

@RefactorF4Acc::Refactoring::Common::EXPORT_OK = qw(
    &context_free_refactorings
    &create_refactored_source
    &get_annotated_sourcelines
    &split_long_line    
    &format_f95_decl
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
    my $sub_or_func = sub_func_or_incl($f, $stref);
#      ( exists $stref->{'Subroutines'}{$f} ) ? 'Subroutines' : 'Functions';
    my $Sf = $stref->{$sub_or_func}{$f};
    if ($Sf->{'Status'}!=$PARSED ) {
    	croak caller;
    }    
    my $annlines=get_annotated_sourcelines($stref,$f);
    my $firstdecl=1;
    $Sf->{'RefactoredCode'} =[];
    for my $annline ( @{$annlines} ) {
        if (not defined $annline or not defined $annline->[0]) {
            croak "Undefined source code line for $f in create_refactored_source()";
        }
        my $line = $annline->[0];
#        print "LINE: <$line>\n";
        my $tags_lref = $annline->[1] || {};
        my %tags = %{$tags_lref};

        # BeginDo: just remove the label
        if ( exists $tags{'BeginDo'} ) {
            $line =~ s/do\s+\d+\s+/do /;
        }
        # EndDo: replace label CONTINUE by END DO; 
        # if no continue, remove label & add end do on next line
        if ( exists $tags{'EndDo'} ) {
#warn "$f: END DO $line\n";
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
                push @extra_lines, ['      end do', {'EndDo'=>1}];
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
#        croak "FIXME: this VarDecl refactoring breaks the comparison in ArgumentIODirs.pm line 214!!!";
        if (exists $tags{'VarDecl'} and not exists $tags{'FunctionSig'} ) {
        	my @vars=@{$tags{'VarDecl'}};
        	# first create all parameter declarations
        	if ($firstdecl==1) {
        		$tags_lref->{'ExGlobVarDecls'} = {};
        		$firstdecl=0;
        		for my $par ( @{ $Sf->{'Parameters'}{'OrderedList'} } ) {        			
        			# What we need is a new formatter
        			my $new_line=format_f95_par_decl($Sf,$par);
        			push @extra_lines, [$new_line, {'Extra'=>1, 'Parameter'=>1}]; 
        		}
        		my @vars_not_pars =grep {not exists  $Sf->{'Parameters'}{$_} } @vars;
        		my $filtered_line = '';
        		if (@vars_not_pars) {
        		  $filtered_line = format_f95_multiple_var_decls($Sf->{'Vars'},@vars_not_pars);
        		  my %tr = %{ $tags_lref };
                  $tr{'Extra'}=1;
        		  push @extra_lines, [$filtered_line,\%tr];
        		}
        		$line = '!! Original line for info !! '.$line;$tags_lref->{'Deleted'} =1;
        	} else {
        	
        	if (scalar @vars==1) { 
        		if (exists ($Sf->{'Parameters'}{$vars[0]} ) ){
        			# Remove this line
        			$line = '!! Original line for info !! '.$line;$tags_lref->{'Deleted'} =1;
        		} else {
        		  $line = format_f95_var_decl($Sf->{'Vars'},$vars[0]);
        		}
        	} else {
        		# filter out parameters
        		my @vars_not_pars =grep {not exists  $Sf->{'Parameters'}{$_} } @vars;
        		if (@vars_not_pars ) {
        		  $line = format_f95_multiple_var_decls($Sf->{'Vars'},@vars_not_pars);
        		} else {
        			$line = '!! Original line for info !! '.$line;$tags_lref->{'Deleted'} =1;
        		}
        	}
        	}
#        	warn "$sub_or_func $f: $line\n";
        	
#        	for my $var (@vars) {
#        		my $extra_line = format_f95_decl($Sf->{'Vars'},$var);
##        		my $spaces = $Sf->{'Vars'}{$var}{'Decl'};
##        		$spaces=~s/\S.*$//;
##        		my $extra_line = $spaces.$Sf->{'Vars'}{$var}{'Type'}.' :: '.$var;
##        		warn $extra_line."\n";
#                push @{ $Sf->{'RefactoredCode'} },[$extra_line,{'Extra'=>1,'VarDecl'=>[$var] }];        		
#        	}
        } 
        if (not keys %tags) {
            while ($line=~/\.\s+(?:eq|ne|gt|lt)\./){
            $line=~s/\.\s+(eq|ne|gt|lt)\./ .$1. /;
            }
            while ($line=~/\.(?:eq|ne|gt|lt)\s+\./){
            $line=~s/\.(eq|ne|gt|lt)\s+\./ .$1. /;
            }
            
        }
    if (exists $tags{'Parameter'}) {
    	$line = '!! Original line for info !! '.$line;$tags_lref->{'Deleted'} =1;
#    	$line='';$tags_lref ={};

    }
        push @{ $Sf->{'RefactoredCode'} }, [$line, $tags_lref] if $line ne '';
        #}
            if (@extra_lines) {
#            	warn "Extra lines in context free refactoring:\n";
                for my $extra_line (@extra_lines) {
                    push @{ $Sf->{'RefactoredCode'} }, $extra_line;
                }
                @extra_lines = ();
            }        
    }
if ($f eq 'NONE') {
    print "REFACTORED LINES ($f):\n";
    
    for my $tmpline (@{ $Sf->{'RefactoredCode'} }) {
    	print $tmpline->[0],"\t",join(';',keys %{$tmpline->[1]} ),"\n";
    } 
    print "=================\n";
}
#    die if $f eq 'advance';
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
        if ( not exists $tags_lref->{'Comments'} and not exists $tags_lref->{'Deleted'}) {
            print $line, "\n" if $V;
            if ($line=~/;/ && $line!~/[\'\"]/) {            	
            	my $spaces=$line;
            	$spaces=~s/\S.*$//;
            	$line=~s/^\s+//;
                my @split_lines = split(/\s*;\s*/,$line);
                for my $sline (@split_lines) {
                    push @{ $Sf->{'RefactoredCode'} }, [$spaces.$sline,$tags_lref];
                }	
            } else {
                $line=~s/\s+\!\!.*$//;# FIXME: ad-hoc to remove comments from context-free refactoring
	            my @split_lines = split_long_line($line);
	            for my $sline (@split_lines) {
	                push @{ $Sf->{'RefactoredCode'} }, [$sline,$tags_lref];
	            }
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

    my $nchars = 64+28;
    if ( scalar(@chunks) == 0 ) {
        print "\nLINE: \n$line\n" if $V;
        $nchars = 72+28;
    }
    my $split_on  = ',';
    my $split_on2 = ' ';
    my $split_on3 = '.ro.';
    my $split_on4 = '.dna.';
# FIXME: add split on ';' and on operators (F95)
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
        
        my @fin_lines=();
        for my $chunk (@split_lines) {
        if ($chunk=~/^\s*\&\s*$/) {        	
        	$chunk='';        	
        } elsif ($chunk=~/\n\s*\&\s*$/m){
            $chunk=~s/\n.*$//m;                    	
        }
        push @fin_lines, $chunk;
        }
        if ($fin_lines[-1]=~/\&\s*$/) {
        	$fin_lines[-1]=~s/\s*\&\s*$//;
        }
        return @fin_lines;
    }
} # END of split_long_line()

# -----------------------------------------------------------------------------
sub get_annotated_sourcelines {
    ( my $stref, my $f ) = @_;
    my $sub_or_func_or_inc = sub_func_or_incl( $f, $stref );
    my $Sf = $stref->{$sub_or_func_or_inc}{$f};
    
    
    my $annlines=[];    
    if ($Sf->{'Status'}==$PARSED) {          
	    if (not exists $Sf->{'RefactoredCode'}) {
	        $Sf->{'RefactoredCode'} = [];
	        $annlines=[ @{ $Sf->{'AnnLines'} } ]; # We want a copy!
	    } else {
	        $annlines=$Sf->{'RefactoredCode'}; # Here a ref is OK
	    }	  
    } else {
    	warn "get_annotated_sourcelines( $f ) \n";
    	warn "STATUS: $Sf->{'Status'} \n";
    	warn Dumper($Sf); 
    	die caller;
    } 
	return $annlines;
} # END of get_annotated_sourcelines()
# -----------------------------------------------------------------------------

sub format_f95_decl {
	(my $Sfv,my $var_is_par ) = @_;
	(my $var, my $is_par, my $val)=@{$var_is_par};
	my $Sv=$Sfv->{$var};
	if (not exists $Sv->{'Decl'}) {
		print "WARNING: VAR $var does not exist in format_f95_decl()!\n" if $W;croak $var;
	}
    my $spaces = $Sv->{'Decl'};
    $spaces=~s/\S.*$//;
    # FIXME: for multiple vars, we need to split this in multiple statements. 
    # So I guess as soon as the Shape is not empty, need to split.
    my $shape = $Sv->{'Shape'};
    die Dumper($shape) if join('',@{$shape})=~/;/;
    my $dim='';
    if (@{$shape}) {
    	my @dims=();    	    	
    	for my $i (0..(@{$shape}/2-1) ){
    		my $range = ($shape->[2*$i] eq '1') ? $shape->[2*$i+1] : $shape->[2*$i].':'.$shape->[2*$i+1];
    		push @dims,$range;
    	}
    	$dim=', dimension('.join(',',@dims).') ';
    }
    my $decl_line = $spaces.$Sv->{'Type'}.$dim.($is_par ? ', parameter ' : '').' :: '.$var.($is_par ? ' = '.$val : '');
#    die $decl_line  if $dim;
	return $decl_line	
} # format_f95_decl() 
# -----------------------------------------------------------------------------

sub format_f95_var_decl {
    (my $Sfv,my $var ) = @_;    
    my $Sv=$Sfv->{$var};
    if (not exists $Sv->{'Decl'}) {
        print "WARNING: VAR $var does not exist in format_f95_decl()!\n" if $W;croak $var;
    }
    my $spaces = $Sv->{'Decl'};
    $spaces=~s/\S.*$//;
    # FIXME: for multiple vars, we need to split this in multiple statements. 
    # So I guess as soon as the Shape is not empty, need to split.
    my $shape = $Sv->{'Shape'};
    die Dumper($shape) if join('',@{$shape})=~/;/;
    my $dim='';
    if (@{$shape}) {
        my @dims=();                
        for my $i (0..(@{$shape}/2-1) ){
            my $range = ($shape->[2*$i] eq '1') ? $shape->[2*$i+1] : $shape->[2*$i].':'.$shape->[2*$i+1];
            push @dims,$range;
        }
        $dim=', dimension('.join(',',@dims).') ';
    }
    my $decl_line = $spaces.$Sv->{'Type'}.$dim.' :: '.$var. ' !! Context-free !! ';
#    die $decl_line  if $dim;
    return $decl_line   
} # format_f95_var_decl() 
# -----------------------------------------------------------------------------
sub format_f95_multiple_decl {
    (my $Sfv,my $var_is_par_tups) = @_;
    my @vars=map { $_->[0] } @{$var_is_par_tups};
    
    my @var_vals = map {"$_->[0] = $_->[2]"} @{$var_is_par_tups};
    my %test = map { ($_->[1],1) } @{$var_is_par_tups};
    my $Sv=$Sfv->{$vars[0]};
    if (not exists $Sv->{'Decl'}) {
        print "WARNING: VAR $vars[0] does not exist in format_f95_decl()!\n" if $W;croak $vars[0];
    } 
    my $spaces = $Sv->{'Decl'};
    $spaces=~s/\S.*$//;
    my $type=$Sv->{'Type'};
    
    # FIXME: for multiple vars, we need to split this in multiple statements. 
    # So I guess as soon as the Shape is not empty, need to split.
    my $split=(exists $test{0} and exists $test{1});
    if (!$split) {
    for my $var (@vars) {    	
        my $shape = $Sfv->{$var}{'Shape'};
        if (@{$shape}>0 && @vars>1) {
        	$split=1;
        	last;
        }
    }    
    }
    
    
    if ($split) {
        
        my $decl_line = $spaces;#.$Sv->{'Type'}.' :: '.join(', ',@vars);
    	# What we need to do is split these into separate statements with semicolons
    	for my $tup (@{$var_is_par_tups}) {
    		(my $var, my $is_par, my $val)=@{$tup};    		
            my $dim='';
            my $shape=$Sfv->{$var}{'Shape'};            
	        if (@{$shape}>1) {
	        	
	            my @dims=();                
	            for my $i (0..(@{$shape}/2-1) ){
                    my $range = ("$shape->[2*$i]" eq '1') ? $shape->[2*$i+1] : $shape->[2*$i].':'.$shape->[2*$i+1];
                    push @dims,$range;	            		            
	            }
	            $dim=', dimension('.join(',',@dims).') ';
	        }
    		
    		my $decl='';
    		if ($is_par) {
    			$decl = "$type $dim ,parameter :: $var = $val; "; # FIXME: it is possible that $val is a function of another parameter
    		} else {
    			$decl = "$type $dim :: $var; ";
    		}
    		$decl_line.=$decl;    	
    	}
    	return $decl_line;
    } else {
    	# for Shape, it means they are all empty OR there is just one!
            my $dim='';
            if (@vars==1) {
            my $shape=$Sfv->{$vars[0]}{'Shape'};
            if (@{$shape}) {
                my @dims=();                
                for my $i (0..(@{$shape}/2-1) ){
                    my $range = ($shape->[2*$i] eq '1') ? $shape->[2*$i+1] : $shape->[2*$i].':'.$shape->[2*$i+1];
                    push @dims,$range;                                  
                }
                $dim=', dimension('.join(',',@dims).') ';
            }
            }    	
    	my $decl_line = $spaces.$type.$dim;
    	if (exists $test{1}) {    	
            $decl_line .= ' ,parameter :: '.join(', ',@var_vals);
            
        } else {
            $decl_line .= ' :: '.join(', ',@vars);        
        }
        return $decl_line;
    }
} # format_f95_multiple_decl() 

# -----------------------------------------------------------------------------
sub format_f95_multiple_var_decls {
    (my $Sfv,my @vars) = @_;
    
    my $Sv=$Sfv->{$vars[0]};
    if (not exists $Sv->{'Decl'}) {
        print "WARNING: VAR $vars[0] does not exist in format_f95_decl()!\n" if $W;croak $vars[0];
    } 
    my $spaces = $Sv->{'Decl'};
    $spaces=~s/\S.*$//;
    my $type=$Sv->{'Type'};
    
    # FIXME: for multiple vars, we need to split this in multiple statements. 
    # So I guess as soon as the Shape is not empty, need to split.
    my $split=0;
    if (!$split) {
    for my $var (@vars) {       
        my $shape = $Sfv->{$var}{'Shape'};
        if (@{$shape}>0 && @vars>1) {
            $split=1;
            last;
        }
    }    
    }
        
    if ($split) {
        
        my $decl_line = $spaces;#.$Sv->{'Type'}.' :: '.join(', ',@vars);
        # What we need to do is split these into separate statements with semicolons
        for my $var (@vars) {
                     
            my $dim='';
            my $shape=$Sfv->{$var}{'Shape'};            
            if (@{$shape}>1) {
                
                my @dims=();                
                for my $i (0..(@{$shape}/2-1) ){
                    my $range = ("$shape->[2*$i]" eq '1') ? $shape->[2*$i+1] : $shape->[2*$i].':'.$shape->[2*$i+1];
                    push @dims,$range;                                  
                }
                $dim=', dimension('.join(',',@dims).') ';
            }
                        
            my $decl = "$type $dim :: $var; ";
            $decl_line.=$decl;      
        }
        return $decl_line;
    } else {
        # for Shape, it means they are all empty OR there is just one!
            my $dim='';
            if (@vars==1) {
            my $shape=$Sfv->{$vars[0]}{'Shape'};
            if (@{$shape}) {
                my @dims=();                
                for my $i (0..(@{$shape}/2-1) ){
                    my $range = ($shape->[2*$i] eq '1') ? $shape->[2*$i+1] : $shape->[2*$i].':'.$shape->[2*$i+1];
                    push @dims,$range;                                  
                }
                $dim=', dimension('.join(',',@dims).') ';
            }
            }       
        my $decl_line = $spaces.$type.$dim.' :: '.join(', ',@vars). ' !! Context-free, multi !! ';            
        return $decl_line;
    }
} # format_f95_multiple_var_decls() 
# ----------------------------------------------------------------------------------------------------

# This could work but it means the code has to be regenerated every time a parameter changes ... 
sub resolve_params {
	(my $Sf, my $val)=@_;
	
	           $val=~s/\s*$//;
	           $val=~s/^\s+//;
	           
                if ($val=~/(^|\W)[a-df-z_]\w*(\W|$)/) {
               print "CALL: $val\n"; 	
                my @chunks=split(/\s*[\/\+\-\*]\s*/,$val);
                    my @maybe_pars;
                    for my $chunk (@chunks) {
                    	print "[$chunk]\n";
                        if ($chunk=~/^[a-z_]\w*/) {                        	                        	
                            if (exists $Sf->{'Parameters'}{$chunk}) {
                                push @maybe_pars, $chunk;                                
                            } else {
                            	croak "Can't find PARAM $chunk"; 
                            }
                        }
                    }
                print "VAL:<$val>\n";
                if (@maybe_pars) {
                    for my $par (	@maybe_pars ) {
                    	print "TEST PAR:{$par}\n";
                	   my $tval=$Sf->{'Parameters'}{$par}{'Val'};
                	   print 'PAR:',$par,' VAL:',$tval,"\n";
                	   $val=~s/(^|\W)$par(\W|$)/$1$tval$2/;
                	   print "AFTER SUB:<$val>\n";
                    }                    
#                    die;
                    resolve_params($Sf,$val);
                } else {
                	return $val;
                }
                } else {
                	return $val;
                }                
}

# -----------------------------------------------------------------------------

sub format_f95_par_decl {
    (my $Sf,my $var ) = @_;
    my $val=$Sf->{'Parameters'}{$var}{'Val'};
    my $Sv=$Sf->{'Vars'}{$var};
    if (not exists $Sv->{'Decl'}) {
        print "WARNING: VAR $var does not exist in format_f95_decl()!\n" if $W;croak $var;
    }
    my $spaces = $Sv->{'Decl'};
    $spaces=~s/\S.*$//;
    # FIXME: for multiple vars, we need to split this in multiple statements. 
    # So I guess as soon as the Shape is not empty, need to split.
    my $shape = $Sv->{'Shape'};
    die Dumper($shape) if join('',@{$shape})=~/;/;
    my $dim='';
    if (@{$shape}) {
        my @dims=();                
        for my $i (0..(@{$shape}/2-1) ){
            my $range = ($shape->[2*$i] eq '1') ? $shape->[2*$i+1] : $shape->[2*$i].':'.$shape->[2*$i+1];
            push @dims,$range;
        }
        $dim=', dimension('.join(',',@dims).') ';
    }
    my $decl_line = $spaces.$Sv->{'Type'}.$dim.', parameter ' .' :: '.$var. ' = '.$val;
#    die $decl_line  if $dim;
    return $decl_line   
} # format_f95_decl() 
