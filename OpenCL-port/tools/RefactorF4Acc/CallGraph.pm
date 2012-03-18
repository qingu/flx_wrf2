package RefactorF4Acc::CallGraph;

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

@RefactorF4Acc::CallGraph::ISA = qw(Exporter);

@RefactorF4Acc::CallGraph::EXPORT_OK = qw(
    &create_call_graph
    &add_to_call_tree
);

# -----------------------------------------------------------------------------
sub create_call_graph { ( my $stref, my $subname ) = @_;
    create_dot_call_graph($stref);
    print "\nCall tree for $subname:\n\n" if $main_tree;
    for my $entry ( @{ $stref->{'CallTree'} } ) {
        print $entry;
    }   
}
# -----------------------------------------------------------------------------
sub create_dot_call_graph {
    ( my $stref ) = @_;

    open my $DOT, '>', 'callgraph.dot';
    print $DOT 'digraph FlxWrf {
node [shape=box];
rankdir="LR";
ratio="fill";
';
    for my $pnid ( keys %{ $stref->{'Nodes'} } ) {
        my %seen = ();
        my $i    = 0;
        for my $cnid ( @{ $stref->{'Nodes'}{$pnid}{'Children'} } ) {

            # Repeated calls to subs without children are pruned
            if ( scalar( @{ $stref->{'Nodes'}{$cnid}{'Children'} } ) != 0
                or not exists $seen{ $stref->{'Nodes'}{$cnid}{'Subroutine'} } )
            {
                my $psub = $stref->{'Nodes'}{$pnid}{'Subroutine'};
                my $csub = $stref->{'Nodes'}{$cnid}{'Subroutine'};
                print $DOT "$cnid [label=\"$csub\"];\n";
                if ( $i == 0 ) {
                    print $DOT "$pnid [label=\"$psub\"];\n";
                }
                print $DOT "$pnid -> $cnid ;\n";
            }
            $seen{ $stref->{'Nodes'}{$cnid}{'Subroutine'} }++;
            $i++;
        }
#       my $sub = $stref->{'Nodes'}{$pnid}{'Subroutine'};
#
        #        print $DOT "$pnid [label=\"$sub\"];\n";
    }
    print $DOT "}\n";
    close $DOT;
}

# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
sub add_to_call_tree {
    ( my $f, my $stref, my $stubbed ) = @_;
    $stubbed ||= ' ';
    my $sub_or_func = sub_func_or_incl( $f, $stref );
    my $src         = $stref->{$sub_or_func}{$f}{'Source'};
    my $nspaces     = 64 - $stref->{'Indents'} - length($f); # -length($src) -2;
    my $incls = join( ',', keys %{ $stref->{$sub_or_func}{$f}{'Includes'} } );
    my $padding = ' ' x ( 32 - length($src) );
    my $src_padded = $src . $padding;
    my $tgt        = uc( substr( $sub_or_func, 0, 3 ) );
    my @strs       = (
        ' ' x $stref->{'Indents'},
        $f, $stubbed, ' ' x $nspaces,
        $tgt, ' ', $src_padded, "\t", $incls, "\n"
    );
    my $str = join( '', @strs );
    push @{ $stref->{'CallTree'} }, $str;
    return $stref;
}    # END of add_to_call_tree()