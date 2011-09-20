
#define DEBUG 3
#define ENDDO 0

#define ACCDO 2
#define PARALLEL 3
#define UNROLL 4
#define VECTOR 5

#define READ 1000
#define WRITE 2000
#define READWRITE 3000
#define REGION 1000

#define ROUTINE 0
#define CPU 1
#define GPU 2

#define TRUE 1
#define FALSE 0

#include "GPU_Directives.h"
#include "pdl_gen.h"    /* access defined properties    */
#include "csm.h"        /* string table handling        */
#include "clp.h"        /* command line interpreter     */

/* Routine to initialize the accDo structure */

DoAcc InitAccDo() {
  DoAcc accDo;
  int i;

  for (i=0; i<3; i++) {
    accDo.DoParallel[i] = 0;
    accDo.DoVector[i] = 0;
  }
  return(accDo);
}

/* Routine to set nest level values for ACC$DO 
** Three options are provided:
**   PARALLEL:   set the nest level (nestLevel field) for block parallelism
**     VECTOR:   set the nest level (nestLevel field) for thread parallelism
**     ENDDO:    reset nest level field to zero (a closing do loop statement)
**
** Two addtional arguments are added: dim and sym that will be used for error
** checking and handling cases where the ACC$REGION may contain different
** arguments than those used in the ACC$DO VECTOR and PARALLEL fields.  This
** is expected fr example, when there may be more data points than threads
** (eg. number of threads is "nz" but the loop goes from 0 to nz.
*/

DoAcc ResetAccDo(DoAcc accDo,int type, int nestLevel, int dim, int sym,POSITION *COORDREF) {

int i;

  for (i=0; i<3; i++) {
    if (type == PARALLEL) {
      if (accDo.DoParallel[i]==0) {
        accDo.DoParallel[i] = nestLevel;
        return(accDo);
      }
    }
    if (type == VECTOR) {
      if (accDo.DoVector[i]==0) {
        accDo.DoVector[i] = nestLevel;
        return(accDo);
      }
    }
    if (type == ENDDO) {        /* end the loop parallelism */
      if (accDo.DoParallel[i] == nestLevel) { accDo.DoParallel[i] = 0; }        
      if (accDo.DoVector[i] == nestLevel) { accDo.DoVector[i] = 0; }    
    }
  }
  return(accDo);
}
  
/* returns the loop nest level of PARALLEL, VECTOR or ACCDO (either one) */
int GetAccNest(DoAcc accDo, int type, int nestLevel,int sym) {

int i;
  for (i=0; i<3; i++) {
    if ((type == PARALLEL) || (type == ACCDO)) {
      if (accDo.DoParallel[i] == nestLevel) {
        return (accDo.DoParallel[i]);
      }
    }
    if ((type == VECTOR) || (type == ACCDO)) {
      if (accDo.DoVector[i] == nestLevel) {
        return (accDo.DoVector[i]);
      }
    }
  } 
  return(0);
}

void SetVariable(DefTableKey objectKey, int region, int update, int type,
  int sym, int line) {

  int value;
  int valueRoutine;

        /* get the value        */
  if (type == GPU) {
    value = GetVariableGPU(objectKey,FALSE);
  } else {
    value = GetVariableCPU(objectKey,FALSE);
  }
  valueRoutine = value;

  if (region != value%REGION) { 
     value = 0;         /* reset the value */
  }

        /* update it with the new region number */
  if (value < READ) {
    value = region;
  } else if (value < WRITE) {
    value = READ + region;
  } else if (value < READWRITE) {
    value = WRITE + region;
  } else {
    value = READWRITE + region;
  }

        /* update it with the variable usage type */
  if (value < READWRITE) {      /* it's READ or WRITE */
    if ((value >= WRITE) && (update == FALSE)) {
      value = value + READ;     // change the status to READWRITE
      valueRoutine = valueRoutine + READ;
    }
    if ((value >= READ) && (value < WRITE) && (update == TRUE)) {
      value = value + WRITE;    // CHANGE THE STATUS TO READWRITE
      valueRoutine = valueRoutine + WRITE;
    }
    if (value < READ) {
      if (update == FALSE) { 
        value = value + READ; 
        valueRoutine = valueRoutine + READ;
      }
      if (update == TRUE) { 
        value = value + WRITE; 
        valueRoutine = valueRoutine + WRITE;
      }
    }
  }

        /* set the appropriate property */
  if (GetVariableConstant(objectKey,FALSE) == TRUE)  {
    ResetVariableGPU(objectKey,value);
    ResetVariableCPU(objectKey,value);
  } else {
    if (type == GPU) {
      ResetVariableGPU(objectKey,value);
    } else {
      ResetVariableCPU(objectKey,value);
    }
  }

  ResetVariableRoutine(objectKey,valueRoutine);

  if (GetClpValue(WarnLevel,0) == DEBUG) {
    printf("%d SetVariable: %s VariableRoutine: %d update = %d returning value: %d device: %d getVariableDeclared: %d\n",MapLine(line),StringTable(sym),valueRoutine,update,value,type,GetVariableDeclared(objectKey,0));
  }

  return;
}

int GetVariableUse(DefTableKey objectKey, int type, int update,int sym,int region,int line) {

  int value;
  int valueRoutine;
  int objectRegion;
  int returnVal = FALSE;

  if (type == GPU) {
    value = GetVariableGPU(objectKey,FALSE);
  } else if (type == CPU) {
    value = GetVariableCPU(objectKey,FALSE);
  } else {
    valueRoutine = GetVariableRoutine(objectKey,FALSE);
  }

        /* obtains the routine READ or WRITE status for the variable */
  if (type == ROUTINE) {
    if (update == READ) {
      if ((valueRoutine >= READ) && (valueRoutine < WRITE) || (valueRoutine >= READWRITE)) { 
        returnVal = TRUE;
      }
    }
    if (update == WRITE) {
      if (valueRoutine >= WRITE) {
        returnVal = TRUE;
      }
    }
  }

  objectRegion = value%REGION;
  if (objectRegion != region) {
    value = 0;  /* reset */
  }

  if (update == READ) {
    if ((value >= READ) && (value < WRITE) || (value >= READWRITE)) { /* variable has been read */
      returnVal = TRUE;
    }
  } else if (update == WRITE) {
    if (value >= WRITE) {
      returnVal = TRUE;
    }
  } else {
    printf("FATAL: unknown value for GetVariableUse update mode\n");
    exit(1);
  }

  if (GetClpValue(WarnLevel,0) == DEBUG) {
    if (type == ROUTINE) {
      printf("%d Variable Use: %s update: %d valueRoutine: %d returnVal: %d\n",line,StringTable(sym),update,valueRoutine,returnVal);
    } else {
      printf("%d Variable Use: %s update: %d value %d chip: %d returnVal: %d\n",line,StringTable(sym),update,value,type,returnVal);
    }
  }
  return(returnVal);  
}
