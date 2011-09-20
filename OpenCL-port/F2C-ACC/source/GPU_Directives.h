
#ifndef ACCDO_H
#define ACCDO_H
#include "err.h"        /* error reporting support      */
#include "deftbl.h"     /* definition table support     */

typedef struct {
  int DoVector[3];
  int DoParallel[3];
} DoAcc;

DoAcc ResetAccDo(DoAcc accDo, int type, int nestLevel, int dim, int sym,POSITION *COORDREF);
int GetAccNest(DoAcc doAcc, int type, int nestLevel,int sym);
DoAcc InitAccDo();
void SetVariable(DefTableKey objectKey, int region, int update, int type,
  int sym, int line);
int GetVariableUse(DefTableKey objectKey, int type, int update,int sym,int region,int line);
#endif
