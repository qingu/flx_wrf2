
#ifndef BOUNDS_H
#define BOUNDS_H
#include "BoundsList.h"
#include "ptg_gen.h"
#include "deftbl.h"

Bounds PkgBounds(int size, int lower, int upper);

int ArrayBounds(BoundsList blist, int dim, int type);
PTGNode ArrayBoundsPTG(BoundsList blist, int dim, int type);

#endif
