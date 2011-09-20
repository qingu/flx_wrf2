#ifndef _PTGGEN_H
#define _PTGGEN_H

#include <stdio.h>
#include "eliproto.h"

/* Include-files specified in .ptg.phi-files */

#include "ptg.h"
/* Definition of Output-Macros */

#if !defined(PTG_OUTPUT_FILE)
#    define PTG_OUTPUT_FILE FILE *
#    define PTG_OUTPUT_DEFAULT 1
#else
#    define PTG_OUTPUT_DEFAULT 0
#endif
#if !defined(PTG_OUTPUT_STRING)
#    define PTG_OUTPUT_STRING(file,param) fputs(param, file)
#    if !defined(PTG_OUTPUT_INT)
#            define PTG_OUTPUT_INT(file,param)    fprintf(file,"%d",param)
#    endif
#    if !defined(PTG_OUTPUT_LONG)
#            define PTG_OUTPUT_LONG(file,param)   fprintf(file,"%ld",param)
#    endif
#    if !defined(PTG_OUTPUT_SHORT)
#            define PTG_OUTPUT_SHORT(file,param)  fprintf(file,"%d",(int) param)
#    endif
#    if !defined(PTG_OUTPUT_CHAR)
#            define PTG_OUTPUT_CHAR(file,param)   fputc(param, file)
#    endif
#    if !defined(PTG_OUTPUT_FLOAT)
#            define PTG_OUTPUT_FLOAT(file,param)  fprintf(file,"%g",(double)param)
#    endif
#    if !defined(PTG_OUTPUT_DOUBLE)
#            define PTG_OUTPUT_DOUBLE(file,param) fprintf(file,"%g",param)
#    endif

#else
     /* PTG_OUTPUT_STRING defined */
     extern void _PTGPrintInt ELI_ARG((PTG_OUTPUT_FILE,int));
     extern void _PTGPrintLong ELI_ARG((PTG_OUTPUT_FILE,long));
     extern void _PTGPrintChar ELI_ARG((PTG_OUTPUT_FILE,char));
     extern void _PTGPrintDouble ELI_ARG((PTG_OUTPUT_FILE,double));
#    if !defined(PTG_OUTPUT_INT)
#            define PTG_OUTPUT_INT(file,param)    _PTGPrintInt(file,param)
#    endif
#    if !defined(PTG_OUTPUT_LONG)
#            define PTG_OUTPUT_LONG(file,param)   _PTGPrintLong(file,param)
#    endif
#    if !defined(PTG_OUTPUT_SHORT)
#            define PTG_OUTPUT_SHORT(file,param)  _PTGPrintInt(file,(int)param)
#    endif
#    if !defined(PTG_OUTPUT_CHAR)
#            define PTG_OUTPUT_CHAR(file,param)   _PTGPrintChar(file,param)
#    endif
#    if !defined(PTG_OUTPUT_FLOAT)
#            define PTG_OUTPUT_FLOAT(file,param)  _PTGPrintDouble(file,(double)param)
#    endif
#    if !defined(PTG_OUTPUT_DOUBLE)
#            define PTG_OUTPUT_DOUBLE(file,param) _PTGPrintDouble(file,param)
#    endif
#endif

/* Define PTGNode Type */
#if defined(__cplusplus)
struct _SPTG0;
typedef void (* _PTGProc)(struct _SPTG0 *);
#else
typedef void (* _PTGProc)();
#endif

typedef struct _SPTG0
{
  _PTGProc _print;
} * _PPTG0;
typedef _PPTG0 PTGNode;                      /* the only exported type */

/* predefined static PTGNULL-Node */

extern struct _SPTG0 _PTGNULL;
#define PTGNULL (& _PTGNULL)
#define PTGNull() (& _PTGNULL)

/* output functions */

#if PTG_OUTPUT_DEFAULT
extern PTGNode PTGOut ELI_ARG((PTGNode root));
extern PTGNode PTGOutFile ELI_ARG((const char *filename, PTGNode root));
extern PTGNode PTGOutFPtr ELI_ARG((FILE *output, PTGNode root));
#endif
extern PTGNode PTGProcess ELI_ARG((PTG_OUTPUT_FILE file, PTGNode root));

/* Memory Management functions. */

extern void PTGFree ELI_ARG((void));

/* ============================ */
/* functions for making PTG nodes */
PTGNode PTGFArrayArgs ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3));
PTGNode PTGGlobalSize ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3));
PTGNode PTGLowBounds ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3));
PTGNode PTGUpperBounds ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3));
PTGNode PTGAccDefine ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5, PTGNode p6, PTGNode p7, PTGNode p8));
PTGNode PTGAppend ELI_ARG((PTGNode p1, PTGNode p2));
PTGNode PTGAppendEndLoop ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3));
PTGNode PTGArgRef ELI_ARG((PTGNode p1));
PTGNode PTGArrayDim ELI_ARG((PTGNode p1));
PTGNode PTGArrayDimSize ELI_ARG((PTGNode p1, PTGNode p2));
PTGNode PTGArrayRef ELI_ARG((PTGNode p1, PTGNode p2));
PTGNode PTGArrayRefArg ELI_ARG((PTGNode p1, PTGNode p2));
PTGNode PTGArraySize ELI_ARG((PTGNode p1, PTGNode p2));
PTGNode PTGArraySpec ELI_ARG((PTGNode p1, PTGNode p2));
PTGNode PTGAssignMaxStmt ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5));
PTGNode PTGAssignStmt1 ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3));
PTGNode PTGAssignStmt2 ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4));
PTGNode PTGAssignStmt3 ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4));
PTGNode PTGCommaArg ELI_ARG((PTGNode p1));
PTGNode PTGCommaArgs ELI_ARG((PTGNode p1, PTGNode p2));
PTGNode PTGCommaArgsC ELI_ARG((PTGNode p1, PTGNode p2));
PTGNode PTGComplexConst ELI_ARG((PTGNode p1, PTGNode p2));
PTGNode PTGC_Decl ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3));
PTGNode PTGC_DeRef ELI_ARG((PTGNode p1, PTGNode p2));
PTGNode PTGCudaArrayName ELI_ARG((PTGNode p1));
PTGNode PTGCudaDecl ELI_ARG((PTGNode p1, PTGNode p2));
PTGNode PTGCudaDecl_and_Malloc ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5, PTGNode p6, PTGNode p7, PTGNode p8, PTGNode p9));
PTGNode PTGCudaMemCpy ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4));
PTGNode PTGCudaFree ELI_ARG((PTGNode p1));
PTGNode PTGDataStmt ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5, PTGNode p6));
PTGNode PTGDeclareLoopVar ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3));
PTGNode PTGDeclareIntVar ELI_ARG((PTGNode p1, PTGNode p2));
PTGNode PTGDeclareRealVar ELI_ARG((PTGNode p1, PTGNode p2));
PTGNode PTGDefAppend ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3));
PTGNode PTGBeginAppend ELI_ARG((PTGNode p1));
PTGNode PTGEndAppend ELI_ARG((void));
PTGNode PTGDefineConstant ELI_ARG((PTGNode p1, PTGNode p2));
PTGNode PTGDefineConstantCR ELI_ARG((PTGNode p1, PTGNode p2));
PTGNode PTGElse ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3));
PTGNode PTGElseIf ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4));
PTGNode PTGEndifStmt ELI_ARG((PTGNode p1, PTGNode p2));
PTGNode PTGEndifStmtNamed ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3));
PTGNode PTGEndLoop ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4));
PTGNode PTGExit ELI_ARG((void));
PTGNode PTGExtern ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3));
PTGNode PTGEndFunction ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5));
PTGNode PTGEndProgram ELI_ARG((PTGNode p1, PTGNode p2));
PTGNode PTGEndProgramGPU ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4));
PTGNode PTGEndRoutine ELI_ARG((PTGNode p1));
PTGNode PTGExpr ELI_ARG((PTGNode p1));
PTGNode PTGExprArgs ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3));
PTGNode PTGExternDecl ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3));
PTGNode PTGFreeAlloc ELI_ARG((PTGNode p1, PTGNode p2));
PTGNode PTGForLoop ELI_ARG((PTGNode p1, PTGNode p2));
PTGNode PTGForLoopReplace ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5));
PTGNode PTGFTNFunction ELI_ARG((PTGNode p1, PTGNode p2));
PTGNode PTGFunctionCall ELI_ARG((PTGNode p1, PTGNode p2));
PTGNode PTGFunctionRef ELI_ARG((PTGNode p1, PTGNode p2));
PTGNode PTGGenerateForLoop ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5, PTGNode p6));
PTGNode PTGGenerateEndLoop ELI_ARG((PTGNode p1));
PTGNode PTGGoTo ELI_ARG((PTGNode p1, PTGNode p2));
PTGNode PTGIfStmt ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4));
PTGNode PTGIfStmtSingle ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5));
PTGNode PTGIfStmtLabel ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5));
PTGNode PTGInclude ELI_ARG((PTGNode p1));
PTGNode PTGIncludeFilesGPU ELI_ARG((void));
PTGNode PTGIncludeFilesCPU ELI_ARG((void));
PTGNode PTGIndent ELI_ARG((int p1));
PTGNode PTGIntrinsicRef ELI_ARG((PTGNode p1, PTGNode p2));
PTGNode PTGKernelFunctionFirst ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5, PTGNode p6));
PTGNode PTGKernelRoutineFirst ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4));
PTGNode PTGLabel ELI_ARG((PTGNode p1));
PTGNode PTGLoopBounds ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5));
PTGNode PTGLoopGen ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5, PTGNode p6));
PTGNode PTGLoopGenEnd ELI_ARG((PTGNode p1));
PTGNode PTGMalloc ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5));
PTGNode PTGMallocTest ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5));
PTGNode PTGMax ELI_ARG((PTGNode p1, PTGNode p2));
PTGNode PTGMin ELI_ARG((PTGNode p1, PTGNode p2));
PTGNode PTGMod ELI_ARG((PTGNode p1, PTGNode p2));
PTGNode PTGMulSequence ELI_ARG((PTGNode p1, PTGNode p2));
PTGNode PTGNumber ELI_ARG((int p1));
PTGNode PTGParens ELI_ARG((PTGNode p1));
PTGNode PTGPointer ELI_ARG((PTGNode p1));
PTGNode PTGPowerExpr ELI_ARG((PTGNode p1, PTGNode p2));
PTGNode PTGProgramStmt ELI_ARG((PTGNode p1));
PTGNode PTGQuotedString ELI_ARG((PTGNode p1));
PTGNode PTGRemove ELI_ARG((PTGNode p1));
PTGNode PTGReplace ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3));
PTGNode PTGReplaceNull ELI_ARG((PTGNode p1));
PTGNode PTGReplaceMaxMin ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4));
PTGNode PTGAppendMaxMinStmt ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3));
PTGNode PTGGPUReturn ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5, PTGNode p6));
PTGNode PTGReturn ELI_ARG((PTGNode p1));
PTGNode PTGReturnExpr ELI_ARG((PTGNode p1, PTGNode p2));
PTGNode PTGSequence ELI_ARG((PTGNode p1, PTGNode p2));
PTGNode PTGSequenceCR ELI_ARG((PTGNode p1, PTGNode p2));
PTGNode PTGSQRmacro ELI_ARG((PTGNode p1));
PTGNode PTGStmtFunction ELI_ARG((PTGNode p1, PTGNode p2));
PTGNode PTGStrideLoopBounds ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5, PTGNode p6));
PTGNode PTGStrideNegLoopBounds ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5, PTGNode p6));
PTGNode PTGString ELI_ARG((CONST char* p1));
PTGNode PTGSubroutineArg ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3));
PTGNode PTGSubroutineArgs ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5, PTGNode p6));
PTGNode PTGFunctionDecl ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3));
PTGNode PTGSubroutine_forGPU ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5, PTGNode p6));
PTGNode PTGSubroutineEnd_forGPU ELI_ARG((PTGNode p1, PTGNode p2));
PTGNode PTGSubroutine_forCPU ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5, PTGNode p6, PTGNode p7));
PTGNode PTGSubroutineNoArgs_forCPU ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5));
PTGNode PTGSubroutineCallNoArgs ELI_ARG((PTGNode p1, PTGNode p2));
PTGNode PTGSubroutineCall ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3));
PTGNode PTGSubroutineDecl ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3));
PTGNode PTGSubroutineNoArgs_forGPU ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3));
PTGNode PTGTwoArgs ELI_ARG((PTGNode p1, PTGNode p2));
PTGNode PTGThreeArgs ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3));
PTGNode PTGThreeArgsCR ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3));
PTGNode PTGVariableDecls ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3));
PTGNode PTGVoid ELI_ARG((void));
PTGNode PTGCommaArgs3 ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3));
PTGNode PTGCommaArgs2 ELI_ARG((PTGNode p1, PTGNode p2));
PTGNode PTGDeclareVar ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5));
PTGNode PTGKernelProgramName ELI_ARG((PTGNode p1, PTGNode p2));
PTGNode PTGKernelRoutineCopyEnd ELI_ARG((PTGNode p1, PTGNode p2));
PTGNode PTGKernelRoutineEnd ELI_ARG((PTGNode p1));
PTGNode PTGKernelRoutineStart ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4));
PTGNode PTGParensArg ELI_ARG((PTGNode p1));
PTGNode PTGKernelCall ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5, PTGNode p6, PTGNode p7, PTGNode p8, PTGNode p9, PTGNode p10, PTGNode p11));
PTGNode PTGKernelCopyArgs ELI_ARG((PTGNode p1));
PTGNode PTGKernelCopyArgsIn ELI_ARG((PTGNode p1, PTGNode p2));
PTGNode PTGKernelFreeArgs ELI_ARG((PTGNode p1));
PTGNode PTGSequenceNL ELI_ARG((PTGNode p1, PTGNode p2));
PTGNode PTGTimerDecl ELI_ARG((void));
PTGNode PTGId ELI_ARG((int p1));
PTGNode PTGAsIs ELI_ARG((CONST char* p1));
PTGNode PTGNumb ELI_ARG((int p1));
PTGNode PTGCString ELI_ARG((CONST char* p1));
PTGNode PTGCChar ELI_ARG((int p1));
PTGNode PTGPString ELI_ARG((CONST char* p1));
PTGNode PTGSeq ELI_ARG((PTGNode p1, PTGNode p2));
PTGNode PTGCommaSeq ELI_ARG((PTGNode p1, PTGNode p2));
PTGNode PTGEol ELI_ARG((PTGNode p1));

/* prototypes for used function call insertions */

void IndentNewLine ELI_ARG((PTG_OUTPUT_FILE));
void IndentLabl ELI_ARG((PTG_OUTPUT_FILE, int));
void PtgOutId ELI_ARG((PTG_OUTPUT_FILE, int));
void CPtgOutstr ELI_ARG((PTG_OUTPUT_FILE, CONST char*));
void CPtgOutchar ELI_ARG((PTG_OUTPUT_FILE, int));
void PPtgOutstr ELI_ARG((PTG_OUTPUT_FILE, CONST char*));
/* ============================ */

#ifdef MONITOR
/* Monitoring support for structured values */
#define DAPTO_RESULTPTGNode(n) DAPTO_RESULT_PTR(n)
#define DAPTO_ARGPTGNode(n) DAPTO_ARG_PTR(n, PTGNode)
#endif

#endif
