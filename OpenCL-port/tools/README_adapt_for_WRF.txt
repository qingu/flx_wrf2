To adapt the refactoring tool to work for WRF, we need to do mainly 
- Support F90 type declarations (::), including TYPE and INTENT
- Support free-style line continuations
- Support MODULE, CONTAINS, USE, ONLY 
	This is useful I guess as extra information to attach to subroutines and functions 
	Main issue is, as this replaces common blocks, I need to change the common block
	analysis to deal with this.
- record types! This is a big deal, as they are used to squirrel away 
huge amounts of arguments. Basically, need to parse things like

  TYPE model_config_rec_type
      SEQUENCE
#include <namelist_defines.inc>
   END TYPE model_config_rec_type

and

   TYPE grid_config_rec_type
#include <namelist_defines2.inc>
   END TYPE grid_config_rec_type

and of course we parse this after cpp has run, so we need a small FSM parser here ...
