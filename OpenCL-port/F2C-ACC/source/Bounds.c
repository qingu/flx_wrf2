
#define SIZE 1
#define LBOUND 2
#define UBOUND 3
#define FALSE 0

#include "BoundsList.h"
#include "ptg_gen.h"    /* ptg specifications           */
#include "csm.h"        /* string table access          */
#include "deftbl.h"     /* definition table access      */
#include "pdl_gen.h"    /* property defn table access   */

Bounds bound;
Bounds PkgBounds(int size, int lower, int upper) {
  bound.size = size;
  bound.lower = lower;
  bound.upper = upper;
  return (bound);
}

        /* return the string table entry of the bound desired   */
int ArrayBounds(BoundsList blist, int dim, int type) {

int i;
int length=0;

  length = LengthBoundsList(blist);
  if ((length > 0) && (length >= dim) && (dim > 0)) {
    bound = IthElemBoundsList(blist,dim);
    if (type == SIZE) return(bound.size);
    if (type == LBOUND) return(bound.lower);
    if (type == UBOUND) return(bound.upper);
  } else {
    if ((dim <= 0 || dim > 7)) {
      fprintf(stderr,"FATAL ERROR: array dimension out of range.  Please contact the developers.\n");
      exit(1);
    }
    return(0);
  }
}

        /* return the PTG node of the bound desired     */
PTGNode ArrayBoundsPTG(BoundsList blist, int dim, int type) {

int i;
int length=0;

  length = LengthBoundsList(blist);
  if ((length > 0) && (length >= dim) && (dim > 0)) {
    bound = IthElemBoundsList(blist,dim);
    if (type == SIZE)   return(PTGString(StringTable(bound.size )));
    if (type == LBOUND) return(PTGString(StringTable(bound.lower)));
    if (type == UBOUND) return(PTGString(StringTable(bound.upper)));
  } else {
    if ((dim <= 0 || dim > 7)) {
      fprintf(stderr,"FATAL ERROR: array dimension out of range.  Please contact the developers.\n");
      exit(1);
    }
    return(PTGAsIs("1"));
  }
}
