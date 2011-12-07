#!/usr/bin/perl
use strict;
use warnings;

$ENV{AFS2}='/Users/wim/SoC_Research/FLEXPART/AFS2';
$ENV{NCARG_ROOT}='/usr/local';
$ENV{WRF}='/Users/wim/SoC_Research/FLEXPART/flx_wrf2/PlotLib_WRF/';
#export AFS2 NCARG_ROOT WRF
system 'ruby make_inlist.rb';
system 'scons';
system './flexpart2bin >/dev/null';
system './ddep2bin >/dev/null' ;
system './wdep2bin >/dev/null' ;
chdir 'ncl';
system 'ncl maxconc.ncl 2>&1 >/dev/null';
system 'ncl plot_conc.ncl 2>&1 >/dev/null';
