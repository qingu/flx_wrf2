
#include "deftbl.h"
#include "ptg_gen.h"
#include "clp.h"
#include "csm.h"
#include "err.h"
#include "Bounds.h"
#include "ppp.h"
#include "CoordMap.h"

#define FALSE 0
#define TRUE 1

#define SPACES 2

#define SIZE 1
#define LBOUND 2
#define UBOUND 3
#define MAX_MODULE_LEN 100

PTGNode Pointer_Ref(int numDims) {
  PTGNode pointerRef = PTGNULL;
  int i;
  if (numDims>0) {
    pointerRef = PTGSequence(pointerRef,PTGAsIs("*"));
  }
  return(pointerRef);
}


PTGNode Convert_to_Ctype(int typelen, DefTableKey type) {
  PTGNode Ctype;

  Ctype = PTGAsIs("F2C-ACC: Type not recognized.");

  if (type == LogicalType) { Ctype = PTGAsIs("int"); }
  if (type == CharacterType) { Ctype = PTGAsIs("char"); }
  if (type == IntegerType) {
    if (strcmp(StringTable(typelen),"8") == 0)
      Ctype = PTGAsIs("long");
    else if (strcmp(StringTable(typelen),"4") == 0)
      Ctype = PTGAsIs("int");
    else
      if (GetClpValue(Integer8,0) == TRUE)
        Ctype = PTGAsIs("long");
      else
        Ctype = PTGAsIs("int");
  }
  if (type == RealType) {
    if (strcmp(StringTable(typelen),"8") == 0) {
      Ctype = PTGAsIs("double");
    } else if (strcmp(StringTable(typelen),"4") == 0) {
      Ctype = PTGAsIs("float");
    } else {
      if (GetClpValue(Real8,0) == TRUE) {
        Ctype = PTGAsIs("double");
      } else {
        Ctype = PTGAsIs("float");
      }
    }
  }

  if (type == DoublePrecisionType) {
    Ctype = PTGAsIs("double");
  }

  return(Ctype);
}

PTGNode Convert_to_CudaType(int typelen, DefTableKey type) {
  PTGNode Ctype;

  Ctype = PTGAsIs("here F2C-ACC: Type not recognized.");

  if (type == LogicalType) { Ctype = PTGAsIs("int"); }
  if (type == CharacterType) { Ctype = PTGAsIs("char"); }
  if (type == IntegerType) {
    if (strcmp(StringTable(typelen),"8") == 0)
      Ctype = PTGAsIs("long");
    else if (strcmp(StringTable(typelen),"4") == 0)
      Ctype = PTGAsIs("int");
    else
      if (GetClpValue(Integer8,0) == TRUE)
        Ctype = PTGAsIs("long");
      else
        Ctype = PTGAsIs("int");
  }
  if (type == RealType) {
    if (strcmp(StringTable(typelen),"8") == 0) {
      Ctype = PTGAsIs("double");
    } else if (strcmp(StringTable(typelen),"4") == 0) {
      Ctype = PTGAsIs("float");
    } else {
      if (GetClpValue(Real8,0) == TRUE) {
        Ctype = PTGAsIs("double");
      } else {
        Ctype = PTGAsIs("float");
      }
    }
  }

  return(Ctype);
}


PTGNode Convert_to_M4type(int typelen, DefTableKey type) {
  PTGNode Ctype;

  Ctype = PTGAsIs("F2C-ACC: Type not recognized.");

  if (type == LogicalType) { Ctype = PTGAsIs("FortranInt"); }
  if (type == CharacterType) { Ctype = PTGAsIs("char"); }
  if (type == IntegerType) {
    if (strcmp(StringTable(typelen),"8") == 0)
      Ctype = PTGAsIs("long");
    else if (strcmp(StringTable(typelen),"4") == 0)
      Ctype = PTGAsIs("FortranInt");
    else
      if (GetClpValue(Integer8,0) == TRUE)
        Ctype = PTGAsIs("long");
      else
        Ctype = PTGAsIs("FortranInt");
  }
  if (type == RealType) {
    if (strcmp(StringTable(typelen),"8") == 0) {
      Ctype = PTGAsIs("FortranDouble");
    } else if (strcmp(StringTable(typelen),"4") == 0) {
      Ctype = PTGAsIs("FortranReal");
    } else {
      if (GetClpValue(Real8,0) == TRUE) {
        Ctype = PTGAsIs("FortranDouble");
      } else {
        Ctype = PTGAsIs("FortranReal");
      }
    }
  }

  return(Ctype);
}

PTGNode ComputeArraySize(DefTableKey unitKey, DefTableKey objectKey) {

  int i;
  PTGNode arraySize=PTGAsIs("1");
  BoundsList arrayList = GetArraySizeList(objectKey,NULLBoundsList);
  int numDims = GetNumberOfDims(unitKey,0);

  if (numDims >= 1) {
    arraySize = PTGParens(ArrayBoundsPTG(arrayList,1,SIZE));
  }
  for (i=2; i<=numDims; i++) {
    arraySize = PTGMulSequence(arraySize,ArrayBoundsPTG(arrayList,i,SIZE));
  }

  return (arraySize);
}
PTGNode FTNREFCPP(DefTableKey unitKey, DefTableKey objectKey, PTGNode Subscripts) {

  BoundsList arrayList = GetArraySizeList(objectKey,NULLBoundsList);

  PTGNode arrayRef=PTGNULL;
  int i;
  arrayRef = 
    PTGFTNFunction(
      PTGNumber(GetNumberOfDims(unitKey,0)),
      Subscripts
    );

  int numDims = GetNumberOfDims(unitKey,0);
  if (numDims == 0) {
    arrayRef = PTGAsIs("F2C-ACC ERROR: Array not defined");
    return(arrayRef);
  }

  /* we don't need to size for the final dimension */
  for (i=1; i<numDims; i++) {
    arrayRef = PTGCommaArgsC(arrayRef,ArrayBoundsPTG(arrayList,i,SIZE));
  }
  /* we need all the lower bounds to perform the index calculations     */
  for (i=1; i<=numDims; i++) {
    arrayRef = PTGCommaArgsC(arrayRef,ArrayBoundsPTG(arrayList,i,LBOUND));
  }
  arrayRef=PTGSequence(arrayRef,PTGAsIs(")"));
  return(arrayRef);
}

int MAX(int i1, int i2) {
  if (i1 > i2) return(i1);
    return(i2);
}

PTGNode GenerateLoops(DefTableKey objectKey, DefTableKey unitKey, int dims, 
int maxRank, int indent, PTGNode label, PTGNode name, PTGNode expr, 
int line, int lastNonExecLine) {

  int i;
  PTGNode output=PTGNULL;
  PTGNode arrayRef;
  PTGNode indices=PTGNULL;

  BoundsList arrayList = GetArraySizeList(objectKey,NULLBoundsList);
   
  for (i=1; i<=dims; i++) {
    PTGNode loopVar = PTGSequence(PTGAsIs("ii_"),PTGNumber(i));
    if (i > 1) {
      indices = PTGCommaArgs(indices,loopVar);
    } else {
      indices = loopVar;
    }

    PTGNode lbound = ArrayBoundsPTG(arrayList,1,LBOUND);
    PTGNode ubound = ArrayBoundsPTG(arrayList,1,UBOUND);
 
    if (i==1) {
      output = PTGSequence(output, PTGLoopGen(PTGNULL,loopVar,
        lbound,loopVar,ubound,loopVar));
      output = PTGSequence(output,PTGBeginAppend(PTGNumber(line)));
    } else {
      output = PTGSequence(output, PTGLoopGen(PTGIndent(indent),loopVar,
        lbound,loopVar,ubound,loopVar));
    }
    indent = indent+SPACES;
  }

  arrayRef = PTGArrayRef(name, FTNREFCPP(unitKey, objectKey, indices));
  output = PTGSequenceCR(output,PTGAssignStmt1(PTGIndent(indent),arrayRef,expr));

  for (i=0; i<dims; i++) {
    indent = indent-SPACES;
    output = PTGSequence(output,PTGLoopGenEnd(PTGIndent(indent)));
  }
  output = PTGSequence(output,PTGEndAppend());

  return(output);
}

int SetRankDefineLoopVars(int dims, int maxRank, int lastNonExecLine, int indent) {
  int i;

  if (dims > maxRank) {
    for (i=maxRank; i<dims; i++) {
      PTGOut(PTGDeclareLoopVar(PTGNumber(lastNonExecLine),PTGIndent(indent),
        PTGNumber(i+1)));
    }
  }
  return(dims);
}

PTGNode GetArrayBounds(DefTableKey objectKey, int index, int dim) {
  BoundsList arrayList = GetArraySizeList(objectKey, NULLBoundsList);
  return(ArrayBoundsPTG(arrayList,index,dim));
}

PTGNode GetAllArrayBounds(DefTableKey objectId, BoundsList arrayList,int sym) {

  PTGNode arraySize = PTGNULL;
  int length = LengthBoundsList(arrayList);
  int i;

  if (length >= 0) {
        /* declarations are permitted where the variable type is        **
        ** defined in one statement, and its dimension is defined in    **
        ** another.  In this situation, the array bounds have already   **
        ** been attached to the object via the ArraySizeList property.  */
    if (length == 0) {
      arrayList = GetArraySizeList(objectId,NULLBoundsList);
      length = LengthBoundsList(arrayList);
      if (length == 0) {        /* the entity was a scalar      */
        return(arraySize);
      } 
        /* otherwise, the entity was an array whose dimenson was        **
        **  set via a dimension statement                               */      
    }
    arraySize = PTGParens(ArrayBoundsPTG(arrayList,1,SIZE));

    for (i=2; i<=length; i++) {
      arraySize = PTGMulSequence(arraySize,ArrayBoundsPTG(arrayList,i,SIZE));
    }
  }
  return(arraySize);
}

PTGNode PTGEndContinueLoops(int line, PTGNode comment, int indentLevel, int labelCount) {
 
int i;
indentLevel = indentLevel - 2;
PTGNode output = PTGEndLoop(PTGNumber(line),comment,PTGIndent(indentLevel),PTGNULL);

for(i=2; i<=labelCount; i++) {
  indentLevel = indentLevel - 2;
  output = PTGSequenceNL(output,
    PTGAppendEndLoop(PTGNumber(line),PTGIndent(indentLevel),comment));
}

return(output);
}

PTGNode GenerateMemCpyDeclaration(PTGNode var, DefTableKey unitKey, 
DefTableKey objectKey, int indentLevel) {

PTGNode output = PTGNULL;

BoundsList arrayList = GetArraySizeList(objectKey,NULLBoundsList);
int length = LengthBoundsList(arrayList);
int i;
PTGNode arraySize;

  PTGNode PTGtype = PTGAsIs("float");
  if (GetType(unitKey,IntegerType) == RealType) { PTGtype = PTGAsIs("float"); }
  if (GetType(unitKey,IntegerType) == IntegerType) { PTGtype = PTGAsIs("int"); }
  if (GetType(unitKey,IntegerType) == LogicalType) { PTGtype = PTGAsIs("int"); }

  if (length > 0) {
    arraySize = PTGParens(ArrayBoundsPTG(arrayList,1,SIZE));
    for (i=2; i<=length; i++) {
      arraySize = PTGMulSequence(arraySize,ArrayBoundsPTG(arrayList,i,SIZE));
    }
  } else {
    arraySize = PTGAsIs("1");
  }
  output = PTGMalloc(PTGIndent(indentLevel),var,PTGtype,arraySize,PTGtype);

  PTGNode testAlloc = PTGMallocTest(PTGIndent(indentLevel),var,
        PTGIndent(indentLevel),PTGIndent(indentLevel),PTGIndent(indentLevel));
  output = PTGSequence(output,testAlloc);

  return(output);
}
PTGNode GenerateMemFreeStmt(PTGNode var, int indentLevel) {

  PTGNode output;
  output = PTGFreeAlloc(PTGIndent(indentLevel),var);
  return(output);
}

PTGNode GenerateArray(PTGNode var, BoundsList arrayList) {
  int i;
  PTGNode arraySize;

  PTGNode output = var;

  int length = LengthBoundsList(arrayList);
  if (length > 0) {
    arraySize = PTGParens(ArrayBoundsPTG(arrayList,1,SIZE));
    for (i=2; i<=length; i++) {
      arraySize = PTGMulSequence(arraySize,ArrayBoundsPTG(arrayList,i,SIZE));
    }
    output = PTGArrayRef(output,arraySize);
  }
  return(output);
}

/* intrinsic support:
! F2C-ACC supports a limited number of intrinsics, either via a direct mapping
! between Fortran and C functions, or by referencing macros such as max and min
! that appear in the included file "ftocmacros.m4".  in the even a macro is used
! generated output will CAPITALIZE the function name (eg "max" becomes "MAX").
*/

#define KIND 2

typedef struct {
  char *FTNname;        /* Fortran intrinsic name */
  char *Cname;          /* C function name or macro */
  int nArgs;
} IntrinsicTable;

/* in the event, there is no mapping to an equivalent C function, an    **
** error message will be generated                                      */

#define MAX_INTRINSICS 15
IntrinsicTable intrinsics[] = {
  "abs","abs",1,
  "acos","acosf",1,
  "asin","asinf",1,
  "atan","atanf",1,
  "ccos","ccosf",1,
  "cos","cosf",1,
  "csin","csinf",1,
  "exp","exp",1,
  "max","MAX",2,
  "min","MIN",2,
  "pow","powf",2,
  "sign","SIGN",2,
  "sin","sinf",1,
  "size","",2,
  "tan","tanf",1
};

/* returns TRUE if the string and number of arguments to the function match **
** returns KIND if the string matches this special case                     **
** returns FALSE otherwise                                                  */
int isIntrinsic(char *name, int nArgs) {

int i;

  for (i=0; i<MAX_INTRINSICS; i++) {
    if ((strcmp(name,intrinsics[i].FTNname) == 0) && (intrinsics[i].nArgs == nArgs)) {
      return(TRUE);
    }

  /* Fortran supports any number of arguments for max and min functions */
    if (((strcmp("max",intrinsics[i].FTNname) == 0) || (strcmp("min",intrinsics[i].FTNname) == 0)) && (nArgs > 2)) {
      return(TRUE);
    }
  }
  if ((strcmp("kind",name)==0) && (nArgs == 1)) {
    return(KIND);
  }
return(FALSE);
}

char *getIntrinsicName(char *name, int nArgs, POSITION *COORDREF) {

int i;
for (i=0; i<MAX_INTRINSICS; i++) {
  if ((strcmp(name,intrinsics[i].FTNname) == 0) && (intrinsics[i].nArgs == nArgs)) {
    if (strlen(intrinsics[i].Cname)==0) {
      message(ERROR,"Fortran intrinsic not supported.",0,COORDREF);
    }   
    return(intrinsics[i].Cname);
  }

  /* Fortran supports any number of arguments for max and min functions */
  if (((strcmp("max",intrinsics[i].FTNname) == 0) || (strcmp("min",intrinsics[i].FTNname) == 0)) && (nArgs > 2)) {
    return(intrinsics[i].Cname);
  }
}

return(name);
}

PTGNode ConstantHandling(char *name) {

int i;
for (i=0; i<strlen(name); i++) {
  if ((*(name+i) == 'd') || (*(name+i) == 'e')) {
    *(name+i) = '\0'; /* terminate string */
    return(PTGString(name));
  }
} 

return(PTGString(name));
}
int Convert_to_int(char *name) {
  int value;
  (void) sscanf(name,"%d\n",&value);
  return(value);

}

int isModule(int line) {

  int i;
  char filename[MAX_MODULE_LEN];
  char *file;

  for (i=0; i< Num_ModuleFiles; i++) {
    strcpy(filename,Module_File[i].UseModuleRef);
    if (strcmp(MapFile(line),filename) == 0) {
      return(Module_File[i].Line);
    }
  }
  return(FALSE);
}
