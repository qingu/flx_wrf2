
#include "ptg_gen.h"
#include "deftbl.h"
PTGNode FTNREFCPP(DefTableKey unitKey, DefTableKey objectKey, PTGNode Subscripts);
PTGNode Convert_to_Ctype(int typelen, DefTableKey type);
PTGNode Convert_to_CudaType(int typelen, DefTableKey type);
PTGNode Convert_to_M4type(int typelen, DefTableKey type);
PTGNode Pointer_Ref(int numDims);
PTGNode ComputeArraySize(DefTableKey unitKey, DefTableKey objectKey);

PTGNode GenerateLoops(DefTableKey objectKey, DefTableKey unitKey, int dims, 
int maxRank, int indent, PTGNode label, PTGNode name, PTGNode expr, 
int line, int lastNonExecLine);
int SetRankDefineLoopVars(int dims, int maxRank, int LastNonExecLine,int indent);
PTGNode GetArrayBounds(DefTableKey objectKey, int index, int dim);
PTGNode GetAllArrayBounds(DefTableKey objectId, BoundsList arrayList,int sym);
PTGNode PTGEndContinueLoops(int line, PTGNode comment, int indentLevel, int labelCount);
PTGNode GenerateMemCpyDeclaration(PTGNode var, DefTableKey unitKey, DefTableKey objectKey, int indentLevel);
PTGNode GenerateMemFreeDeclaration(PTGNode var, int indentLevel);
PTGNode GenerateArray(PTGNode var, BoundsList arrayList);
int isIntrinsic(char *name, int nArgs);
char * getIntrinsicName(char *,int, POSITION *);

PTGNode ConstantHandling(char *name);
int Convert_to_int(char *name);
int isModule(int line);
