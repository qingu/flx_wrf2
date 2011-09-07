#!/usr/bin/perl
use strict;
use warnings;

system 'ruby make_inlist.rb';
system 'scons';
system './flexpart2bin >/dev/null';
system './ddep2bin >/dev/null' ;
system './wdep2bin >/dev/null' ;
chdir 'ncl';
system 'ncl maxconc.ncl 2>&1 >/dev/null';
system 'ncl plot_conc.ncl 2>&1 >/dev/null';
