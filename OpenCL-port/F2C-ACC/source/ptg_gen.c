#include <stdio.h>
#include <stdlib.h>

#include "ptg_gen.h"
#include "obstack.h"

/* -------------------------------------------------------- */
/*                      Memory Management                   */
/* -------------------------------------------------------- */

static Obstack _PTGObstack;
static void *_PTGFirstObj = NULL;

static void _PTGInit()
{
       if (_PTGFirstObj)
               return;
       obstack_init(&_PTGObstack);
       _PTGFirstObj = obstack_alloc(&_PTGObstack, 0);
}

void PTGFree()
{
       obstack_free(&_PTGObstack, _PTGFirstObj);
       _PTGFirstObj = obstack_alloc(&_PTGObstack, 0);
}


#if defined(__STDC__) || defined(__cplusplus)
static void *MALLOC(int size)
#else
static void *MALLOC(size) int size;
#endif
{
       if (! _PTGFirstObj)
               _PTGInit();
       return (obstack_alloc(&_PTGObstack, size));
}

/* -------------------------------------------------------- */
/*                       Output-functions                   */
/* -------------------------------------------------------- */

static PTG_OUTPUT_FILE f;
static char buffer[40];

#if PTG_OUTPUT_DEFAULT
#if defined(__STDC__) || defined(__cplusplus)
PTGNode PTGOut (PTGNode r)
#else
PTGNode PTGOut (r)
       PTGNode r;
#endif
{
       f = stdout;
       if (r) {
               (* (r->_print)) (r);
       }
       return (r);
}

#if defined(__STDC__) || defined(__cplusplus)
PTGNode PTGOutFile (const char *fn, PTGNode r)
#else
PTGNode PTGOutFile (fn, r)
       char * fn; PTGNode r;
#endif
{
       if ((f = fopen(fn, "w"))  == (FILE *)NULL)
       {
               fprintf(stderr, "ERROR: PTGOutFile: output file '%s' can't be opened.\n",fn);
               exit(1);
       }
       if (r)
               (* (r->_print)) (r);
       fclose(f);
       return (r);
}

#if defined(__STDC__) || defined(__cplusplus)
PTGNode PTGOutFPtr(FILE *fptr, PTGNode r)
#else
PTGNode PTGOutFPtr(fptr, r)
       FILE *fptr; PTGNode r;
#endif
{
       if ((f = fptr) == (FILE *)NULL)
       {
               fprintf(stderr, "ERROR: PTGOutFPtr: output file not open.\n");
               exit(1);
       }
       if (r)
               (* (r->_print)) (r);
       return (r);
}

#endif

#if defined(__STDC__) || defined(__cplusplus)
PTGNode PTGProcess(PTG_OUTPUT_FILE file, PTGNode r)
#else
PTGNode PTGProcess(file, r)
       PTG_OUTPUT_FILE file; PTGNode r;
#endif
{
       f = file;
       if (r)
               (* (r->_print)) (r);
       return (r);
}
/* -------------------------------------------------------- */
/*                            PTGNULL                       */
/* -------------------------------------------------------- */

/* Define PTGNULL as a PTGNode that prints nothing. */

#if defined(__STDC__) || defined(__cplusplus)
static void _PrPTGNULL(_PPTG0 n)
#else
static void _PrPTGNULL(n)
_PPTG0 n;
#endif
{(void)n; /* function printing nothing */}

struct _SPTG0   _PTGNULL = { (_PTGProc) _PrPTGNULL };

/* -------------------------------------------------------- */
/*          Node-Construction and Print-functions           */
/* -------------------------------------------------------- */

/* ============================ */

/* Implementation of Pattern FArrayArgs */

typedef struct _SPTGFArrayArgs{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
} * _PPTGFArrayArgs;

#ifdef PROTO_OK
static void _PrPTGFArrayArgs(_PPTGFArrayArgs n)
#else
static void _PrPTGFArrayArgs(n)
	_PPTGFArrayArgs n;
#endif
{
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "(");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, ",");
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, ")");
}

#ifdef PROTO_OK
PTGNode PTGFArrayArgs(PTGNode p1, PTGNode p2, PTGNode p3)
#else
PTGNode PTGFArrayArgs(p1, p2, p3)

PTGNode p1;
PTGNode p2;
PTGNode p3;
#endif
{
	_PPTGFArrayArgs n;
	n = (_PPTGFArrayArgs)MALLOC(sizeof(struct _SPTGFArrayArgs));
	n->_print = (_PTGProc)_PrPTGFArrayArgs;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	return (PTGNode)n;
}


/* Implementation of Pattern GlobalSize */

typedef struct _SPTGGlobalSize{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
} * _PPTGGlobalSize;

#ifdef PROTO_OK
static void _PrPTGGlobalSize(_PPTGGlobalSize n)
#else
static void _PrPTGGlobalSize(n)
	_PPTGGlobalSize n;
#endif
{
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "__GlobalSize(");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, ",");
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, ")");
}

#ifdef PROTO_OK
PTGNode PTGGlobalSize(PTGNode p1, PTGNode p2, PTGNode p3)
#else
PTGNode PTGGlobalSize(p1, p2, p3)

PTGNode p1;
PTGNode p2;
PTGNode p3;
#endif
{
	_PPTGGlobalSize n;
	n = (_PPTGGlobalSize)MALLOC(sizeof(struct _SPTGGlobalSize));
	n->_print = (_PTGProc)_PrPTGGlobalSize;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	return (PTGNode)n;
}


/* Implementation of Pattern LowBounds */

typedef struct _SPTGLowBounds{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
} * _PPTGLowBounds;

#ifdef PROTO_OK
static void _PrPTGLowBounds(_PPTGLowBounds n)
#else
static void _PrPTGLowBounds(n)
	_PPTGLowBounds n;
#endif
{
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "__LowBounds(");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, ",");
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, ")");
}

#ifdef PROTO_OK
PTGNode PTGLowBounds(PTGNode p1, PTGNode p2, PTGNode p3)
#else
PTGNode PTGLowBounds(p1, p2, p3)

PTGNode p1;
PTGNode p2;
PTGNode p3;
#endif
{
	_PPTGLowBounds n;
	n = (_PPTGLowBounds)MALLOC(sizeof(struct _SPTGLowBounds));
	n->_print = (_PTGProc)_PrPTGLowBounds;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	return (PTGNode)n;
}


/* Implementation of Pattern UpperBounds */

typedef struct _SPTGUpperBounds{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
} * _PPTGUpperBounds;

#ifdef PROTO_OK
static void _PrPTGUpperBounds(_PPTGUpperBounds n)
#else
static void _PrPTGUpperBounds(n)
	_PPTGUpperBounds n;
#endif
{
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "__UpperBounds(");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, ",");
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, ")");
}

#ifdef PROTO_OK
PTGNode PTGUpperBounds(PTGNode p1, PTGNode p2, PTGNode p3)
#else
PTGNode PTGUpperBounds(p1, p2, p3)

PTGNode p1;
PTGNode p2;
PTGNode p3;
#endif
{
	_PPTGUpperBounds n;
	n = (_PPTGUpperBounds)MALLOC(sizeof(struct _SPTGUpperBounds));
	n->_print = (_PTGProc)_PrPTGUpperBounds;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	return (PTGNode)n;
}


/* Implementation of Pattern AccDefine */

typedef struct _SPTGAccDefine{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
	PTGNode p4;
	PTGNode p5;
	PTGNode p6;
	PTGNode p7;
	PTGNode p8;
} * _PPTGAccDefine;

#ifdef PROTO_OK
static void _PrPTGAccDefine(_PPTGAccDefine n)
#else
static void _PrPTGAccDefine(n)
	_PPTGAccDefine n;
#endif
{
	PTG_OUTPUT_STRING(f, "replace ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ");
	n->p2->_print(n->p2);
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, " = ");
	n->p4->_print(n->p4);
	PTG_OUTPUT_STRING(f, "+");
	n->p5->_print(n->p5);
	PTG_OUTPUT_STRING(f, ";");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "begin_append ");
	n->p6->_print(n->p6);
	PTG_OUTPUT_STRING(f, " ");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "//");
	n->p7->_print(n->p7);
	n->p8->_print(n->p8);
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "end_append");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGAccDefine(PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5, PTGNode p6, PTGNode p7, PTGNode p8)
#else
PTGNode PTGAccDefine(p1, p2, p3, p4, p5, p6, p7, p8)

PTGNode p1;
PTGNode p2;
PTGNode p3;
PTGNode p4;
PTGNode p5;
PTGNode p6;
PTGNode p7;
PTGNode p8;
#endif
{
	_PPTGAccDefine n;
	n = (_PPTGAccDefine)MALLOC(sizeof(struct _SPTGAccDefine));
	n->_print = (_PTGProc)_PrPTGAccDefine;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	n->p4 = p4;
	n->p5 = p5;
	n->p6 = p6;
	n->p7 = p7;
	n->p8 = p8;
	return (PTGNode)n;
}


/* Implementation of Pattern Append */

typedef struct _SPTGAppend{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGAppend;

#ifdef PROTO_OK
static void _PrPTGAppend(_PPTGAppend n)
#else
static void _PrPTGAppend(n)
	_PPTGAppend n;
#endif
{
	PTG_OUTPUT_STRING(f, "begin_append ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ");
	IndentNewLine(f);
	n->p2->_print(n->p2);
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "end_append");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGAppend(PTGNode p1, PTGNode p2)
#else
PTGNode PTGAppend(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGAppend n;
	n = (_PPTGAppend)MALLOC(sizeof(struct _SPTGAppend));
	n->_print = (_PTGProc)_PrPTGAppend;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern AppendEndLoop */

typedef struct _SPTGAppendEndLoop{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
} * _PPTGAppendEndLoop;

#ifdef PROTO_OK
static void _PrPTGAppendEndLoop(_PPTGAppendEndLoop n)
#else
static void _PrPTGAppendEndLoop(n)
	_PPTGAppendEndLoop n;
#endif
{
	PTG_OUTPUT_STRING(f, "begin_append ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ");
	IndentNewLine(f);
	n->p2->_print(n->p2);
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, "}");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "end_append");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGAppendEndLoop(PTGNode p1, PTGNode p2, PTGNode p3)
#else
PTGNode PTGAppendEndLoop(p1, p2, p3)

PTGNode p1;
PTGNode p2;
PTGNode p3;
#endif
{
	_PPTGAppendEndLoop n;
	n = (_PPTGAppendEndLoop)MALLOC(sizeof(struct _SPTGAppendEndLoop));
	n->_print = (_PTGProc)_PrPTGAppendEndLoop;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	return (PTGNode)n;
}


/* Implementation of Pattern ArgRef */

typedef struct _SPTGArgRef{
	_PTGProc _print;
	PTGNode p1;
} * _PPTGArgRef;

#ifdef PROTO_OK
static void _PrPTGArgRef(_PPTGArgRef n)
#else
static void _PrPTGArgRef(n)
	_PPTGArgRef n;
#endif
{
	PTG_OUTPUT_STRING(f, "&");
	n->p1->_print(n->p1);
}

#ifdef PROTO_OK
PTGNode PTGArgRef(PTGNode p1)
#else
PTGNode PTGArgRef(p1)

PTGNode p1;
#endif
{
	_PPTGArgRef n;
	n = (_PPTGArgRef)MALLOC(sizeof(struct _SPTGArgRef));
	n->_print = (_PTGProc)_PrPTGArgRef;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern ArrayDim */

typedef struct _SPTGArrayDim{
	_PTGProc _print;
	PTGNode p1;
} * _PPTGArrayDim;

#ifdef PROTO_OK
static void _PrPTGArrayDim(_PPTGArrayDim n)
#else
static void _PrPTGArrayDim(n)
	_PPTGArrayDim n;
#endif
{
	PTG_OUTPUT_STRING(f, "(");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, ")");
}

#ifdef PROTO_OK
PTGNode PTGArrayDim(PTGNode p1)
#else
PTGNode PTGArrayDim(p1)

PTGNode p1;
#endif
{
	_PPTGArrayDim n;
	n = (_PPTGArrayDim)MALLOC(sizeof(struct _SPTGArrayDim));
	n->_print = (_PTGProc)_PrPTGArrayDim;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern ArrayDimSize */

typedef struct _SPTGArrayDimSize{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGArrayDimSize;

#ifdef PROTO_OK
static void _PrPTGArrayDimSize(_PPTGArrayDimSize n)
#else
static void _PrPTGArrayDimSize(n)
	_PPTGArrayDimSize n;
#endif
{
	PTG_OUTPUT_STRING(f, "(");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "-");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, ")");
}

#ifdef PROTO_OK
PTGNode PTGArrayDimSize(PTGNode p1, PTGNode p2)
#else
PTGNode PTGArrayDimSize(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGArrayDimSize n;
	n = (_PPTGArrayDimSize)MALLOC(sizeof(struct _SPTGArrayDimSize));
	n->_print = (_PTGProc)_PrPTGArrayDimSize;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern ArrayRef */

typedef struct _SPTGArrayRef{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGArrayRef;

#ifdef PROTO_OK
static void _PrPTGArrayRef(_PPTGArrayRef n)
#else
static void _PrPTGArrayRef(n)
	_PPTGArrayRef n;
#endif
{
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "[");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, "]");
}

#ifdef PROTO_OK
PTGNode PTGArrayRef(PTGNode p1, PTGNode p2)
#else
PTGNode PTGArrayRef(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGArrayRef n;
	n = (_PPTGArrayRef)MALLOC(sizeof(struct _SPTGArrayRef));
	n->_print = (_PTGProc)_PrPTGArrayRef;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern ArrayRefArg */

typedef struct _SPTGArrayRefArg{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGArrayRefArg;

#ifdef PROTO_OK
static void _PrPTGArrayRefArg(_PPTGArrayRefArg n)
#else
static void _PrPTGArrayRefArg(n)
	_PPTGArrayRefArg n;
#endif
{
	PTG_OUTPUT_STRING(f, "&");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "[");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, "]");
}

#ifdef PROTO_OK
PTGNode PTGArrayRefArg(PTGNode p1, PTGNode p2)
#else
PTGNode PTGArrayRefArg(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGArrayRefArg n;
	n = (_PPTGArrayRefArg)MALLOC(sizeof(struct _SPTGArrayRefArg));
	n->_print = (_PTGProc)_PrPTGArrayRefArg;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern ArraySize */

typedef struct _SPTGArraySize{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGArraySize;

#ifdef PROTO_OK
static void _PrPTGArraySize(_PPTGArraySize n)
#else
static void _PrPTGArraySize(n)
	_PPTGArraySize n;
#endif
{
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "*");
	n->p2->_print(n->p2);
}

#ifdef PROTO_OK
PTGNode PTGArraySize(PTGNode p1, PTGNode p2)
#else
PTGNode PTGArraySize(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGArraySize n;
	n = (_PPTGArraySize)MALLOC(sizeof(struct _SPTGArraySize));
	n->_print = (_PTGProc)_PrPTGArraySize;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern ArraySpec */

typedef struct _SPTGArraySpec{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGArraySpec;

#ifdef PROTO_OK
static void _PrPTGArraySpec(_PPTGArraySpec n)
#else
static void _PrPTGArraySpec(n)
	_PPTGArraySpec n;
#endif
{
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "[");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, "]");
}

#ifdef PROTO_OK
PTGNode PTGArraySpec(PTGNode p1, PTGNode p2)
#else
PTGNode PTGArraySpec(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGArraySpec n;
	n = (_PPTGArraySpec)MALLOC(sizeof(struct _SPTGArraySpec));
	n->_print = (_PTGProc)_PrPTGArraySpec;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern AssignMaxStmt */

typedef struct _SPTGAssignMaxStmt{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
	PTGNode p4;
	PTGNode p5;
} * _PPTGAssignMaxStmt;

#ifdef PROTO_OK
static void _PrPTGAssignMaxStmt(_PPTGAssignMaxStmt n)
#else
static void _PrPTGAssignMaxStmt(n)
	_PPTGAssignMaxStmt n;
#endif
{
	n->p1->_print(n->p1);
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, " = ");
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, "(");
	n->p4->_print(n->p4);
	PTG_OUTPUT_STRING(f, ",");
	n->p5->_print(n->p5);
	PTG_OUTPUT_STRING(f, ");");
}

#ifdef PROTO_OK
PTGNode PTGAssignMaxStmt(PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5)
#else
PTGNode PTGAssignMaxStmt(p1, p2, p3, p4, p5)

PTGNode p1;
PTGNode p2;
PTGNode p3;
PTGNode p4;
PTGNode p5;
#endif
{
	_PPTGAssignMaxStmt n;
	n = (_PPTGAssignMaxStmt)MALLOC(sizeof(struct _SPTGAssignMaxStmt));
	n->_print = (_PTGProc)_PrPTGAssignMaxStmt;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	n->p4 = p4;
	n->p5 = p5;
	return (PTGNode)n;
}


/* Implementation of Pattern AssignStmt1 */

typedef struct _SPTGAssignStmt1{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
} * _PPTGAssignStmt1;

#ifdef PROTO_OK
static void _PrPTGAssignStmt1(_PPTGAssignStmt1 n)
#else
static void _PrPTGAssignStmt1(n)
	_PPTGAssignStmt1 n;
#endif
{
	n->p1->_print(n->p1);
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, " = ");
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, ";");
}

#ifdef PROTO_OK
PTGNode PTGAssignStmt1(PTGNode p1, PTGNode p2, PTGNode p3)
#else
PTGNode PTGAssignStmt1(p1, p2, p3)

PTGNode p1;
PTGNode p2;
PTGNode p3;
#endif
{
	_PPTGAssignStmt1 n;
	n = (_PPTGAssignStmt1)MALLOC(sizeof(struct _SPTGAssignStmt1));
	n->_print = (_PTGProc)_PrPTGAssignStmt1;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	return (PTGNode)n;
}


/* Implementation of Pattern AssignStmt2 */

typedef struct _SPTGAssignStmt2{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
	PTGNode p4;
} * _PPTGAssignStmt2;

#ifdef PROTO_OK
static void _PrPTGAssignStmt2(_PPTGAssignStmt2 n)
#else
static void _PrPTGAssignStmt2(n)
	_PPTGAssignStmt2 n;
#endif
{
	n->p1->_print(n->p1);
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, "[");
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, "] = ");
	n->p4->_print(n->p4);
	PTG_OUTPUT_STRING(f, ";");
}

#ifdef PROTO_OK
PTGNode PTGAssignStmt2(PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4)
#else
PTGNode PTGAssignStmt2(p1, p2, p3, p4)

PTGNode p1;
PTGNode p2;
PTGNode p3;
PTGNode p4;
#endif
{
	_PPTGAssignStmt2 n;
	n = (_PPTGAssignStmt2)MALLOC(sizeof(struct _SPTGAssignStmt2));
	n->_print = (_PTGProc)_PrPTGAssignStmt2;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	n->p4 = p4;
	return (PTGNode)n;
}


/* Implementation of Pattern AssignStmt3 */

typedef struct _SPTGAssignStmt3{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
	PTGNode p4;
} * _PPTGAssignStmt3;

#ifdef PROTO_OK
static void _PrPTGAssignStmt3(_PPTGAssignStmt3 n)
#else
static void _PrPTGAssignStmt3(n)
	_PPTGAssignStmt3 n;
#endif
{
	n->p1->_print(n->p1);
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, " = ");
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, "[ ");
	n->p4->_print(n->p4);
	PTG_OUTPUT_STRING(f, " ];");
}

#ifdef PROTO_OK
PTGNode PTGAssignStmt3(PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4)
#else
PTGNode PTGAssignStmt3(p1, p2, p3, p4)

PTGNode p1;
PTGNode p2;
PTGNode p3;
PTGNode p4;
#endif
{
	_PPTGAssignStmt3 n;
	n = (_PPTGAssignStmt3)MALLOC(sizeof(struct _SPTGAssignStmt3));
	n->_print = (_PTGProc)_PrPTGAssignStmt3;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	n->p4 = p4;
	return (PTGNode)n;
}


/* Implementation of Pattern CommaArg */

typedef struct _SPTGCommaArg{
	_PTGProc _print;
	PTGNode p1;
} * _PPTGCommaArg;

#ifdef PROTO_OK
static void _PrPTGCommaArg(_PPTGCommaArg n)
#else
static void _PrPTGCommaArg(n)
	_PPTGCommaArg n;
#endif
{
	n->p1->_print(n->p1);
}

#ifdef PROTO_OK
PTGNode PTGCommaArg(PTGNode p1)
#else
PTGNode PTGCommaArg(p1)

PTGNode p1;
#endif
{
	_PPTGCommaArg n;
	if(p1 == PTGNULL)
		return PTGNULL;
	n = (_PPTGCommaArg)MALLOC(sizeof(struct _SPTGCommaArg));
	n->_print = (_PTGProc)_PrPTGCommaArg;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern CommaArgs */

typedef struct _SPTGCommaArgs{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGCommaArgs;

#ifdef PROTO_OK
static void _PrPTGCommaArgs(_PPTGCommaArgs n)
#else
static void _PrPTGCommaArgs(n)
	_PPTGCommaArgs n;
#endif
{
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, ",");
	n->p2->_print(n->p2);
}

#ifdef PROTO_OK
PTGNode PTGCommaArgs(PTGNode p1, PTGNode p2)
#else
PTGNode PTGCommaArgs(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGCommaArgs n;
	n = (_PPTGCommaArgs)MALLOC(sizeof(struct _SPTGCommaArgs));
	n->_print = (_PTGProc)_PrPTGCommaArgs;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern CommaArgsC */

typedef struct _SPTGCommaArgsC{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGCommaArgsC;

#ifdef PROTO_OK
static void _PrPTGCommaArgsC(_PPTGCommaArgsC n)
#else
static void _PrPTGCommaArgsC(n)
	_PPTGCommaArgsC n;
#endif
{
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, ",");
	n->p2->_print(n->p2);
}

#ifdef PROTO_OK
PTGNode PTGCommaArgsC(PTGNode p1, PTGNode p2)
#else
PTGNode PTGCommaArgsC(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGCommaArgsC n;
	n = (_PPTGCommaArgsC)MALLOC(sizeof(struct _SPTGCommaArgsC));
	n->_print = (_PTGProc)_PrPTGCommaArgsC;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern ComplexConst */

typedef struct _SPTGComplexConst{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGComplexConst;

#ifdef PROTO_OK
static void _PrPTGComplexConst(_PPTGComplexConst n)
#else
static void _PrPTGComplexConst(n)
	_PPTGComplexConst n;
#endif
{
	PTG_OUTPUT_STRING(f, "(");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, ",");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, ")");
}

#ifdef PROTO_OK
PTGNode PTGComplexConst(PTGNode p1, PTGNode p2)
#else
PTGNode PTGComplexConst(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGComplexConst n;
	n = (_PPTGComplexConst)MALLOC(sizeof(struct _SPTGComplexConst));
	n->_print = (_PTGProc)_PrPTGComplexConst;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern C_Decl */

typedef struct _SPTGC_Decl{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
} * _PPTGC_Decl;

#ifdef PROTO_OK
static void _PrPTGC_Decl(_PPTGC_Decl n)
#else
static void _PrPTGC_Decl(n)
	_PPTGC_Decl n;
#endif
{
	PTG_OUTPUT_STRING(f, "  ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, "=*");
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, ";");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGC_Decl(PTGNode p1, PTGNode p2, PTGNode p3)
#else
PTGNode PTGC_Decl(p1, p2, p3)

PTGNode p1;
PTGNode p2;
PTGNode p3;
#endif
{
	_PPTGC_Decl n;
	n = (_PPTGC_Decl)MALLOC(sizeof(struct _SPTGC_Decl));
	n->_print = (_PTGProc)_PrPTGC_Decl;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	return (PTGNode)n;
}


/* Implementation of Pattern C_DeRef */

typedef struct _SPTGC_DeRef{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGC_DeRef;

#ifdef PROTO_OK
static void _PrPTGC_DeRef(_PPTGC_DeRef n)
#else
static void _PrPTGC_DeRef(n)
	_PPTGC_DeRef n;
#endif
{
	PTG_OUTPUT_STRING(f, "  *");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "=");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, ";");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGC_DeRef(PTGNode p1, PTGNode p2)
#else
PTGNode PTGC_DeRef(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGC_DeRef n;
	n = (_PPTGC_DeRef)MALLOC(sizeof(struct _SPTGC_DeRef));
	n->_print = (_PTGProc)_PrPTGC_DeRef;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern CudaArrayName */

typedef struct _SPTGCudaArrayName{
	_PTGProc _print;
	PTGNode p1;
} * _PPTGCudaArrayName;

#ifdef PROTO_OK
static void _PrPTGCudaArrayName(_PPTGCudaArrayName n)
#else
static void _PrPTGCudaArrayName(n)
	_PPTGCudaArrayName n;
#endif
{
	PTG_OUTPUT_STRING(f, "d_");
	n->p1->_print(n->p1);
}

#ifdef PROTO_OK
PTGNode PTGCudaArrayName(PTGNode p1)
#else
PTGNode PTGCudaArrayName(p1)

PTGNode p1;
#endif
{
	_PPTGCudaArrayName n;
	n = (_PPTGCudaArrayName)MALLOC(sizeof(struct _SPTGCudaArrayName));
	n->_print = (_PTGProc)_PrPTGCudaArrayName;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern CudaDecl */

typedef struct _SPTGCudaDecl{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGCudaDecl;

#ifdef PROTO_OK
static void _PrPTGCudaDecl(_PPTGCudaDecl n)
#else
static void _PrPTGCudaDecl(n)
	_PPTGCudaDecl n;
#endif
{
	PTG_OUTPUT_STRING(f, "  ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " *");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, ";");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGCudaDecl(PTGNode p1, PTGNode p2)
#else
PTGNode PTGCudaDecl(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGCudaDecl n;
	n = (_PPTGCudaDecl)MALLOC(sizeof(struct _SPTGCudaDecl));
	n->_print = (_PTGProc)_PrPTGCudaDecl;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern CudaDecl_and_Malloc */

typedef struct _SPTGCudaDecl_and_Malloc{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
	PTGNode p4;
	PTGNode p5;
	PTGNode p6;
	PTGNode p7;
	PTGNode p8;
	PTGNode p9;
} * _PPTGCudaDecl_and_Malloc;

#ifdef PROTO_OK
static void _PrPTGCudaDecl_and_Malloc(_PPTGCudaDecl_and_Malloc n)
#else
static void _PrPTGCudaDecl_and_Malloc(n)
	_PPTGCudaDecl_and_Malloc n;
#endif
{
	PTG_OUTPUT_STRING(f, "  ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " *");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, ";");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "  cudaMalloc((void **) &");
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, ",(");
	n->p4->_print(n->p4);
	PTG_OUTPUT_STRING(f, ")*sizeof(");
	n->p5->_print(n->p5);
	PTG_OUTPUT_STRING(f, "));");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "  cudaMemcpy(");
	n->p6->_print(n->p6);
	PTG_OUTPUT_STRING(f, ",");
	n->p7->_print(n->p7);
	PTG_OUTPUT_STRING(f, ",(");
	n->p8->_print(n->p8);
	PTG_OUTPUT_STRING(f, ")*sizeof(");
	n->p9->_print(n->p9);
	PTG_OUTPUT_STRING(f, "),");
	PTG_OUTPUT_STRING(f, "cudaMemcpyHostToDevice);");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGCudaDecl_and_Malloc(PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5, PTGNode p6, PTGNode p7, PTGNode p8, PTGNode p9)
#else
PTGNode PTGCudaDecl_and_Malloc(p1, p2, p3, p4, p5, p6, p7, p8, p9)

PTGNode p1;
PTGNode p2;
PTGNode p3;
PTGNode p4;
PTGNode p5;
PTGNode p6;
PTGNode p7;
PTGNode p8;
PTGNode p9;
#endif
{
	_PPTGCudaDecl_and_Malloc n;
	n = (_PPTGCudaDecl_and_Malloc)MALLOC(sizeof(struct _SPTGCudaDecl_and_Malloc));
	n->_print = (_PTGProc)_PrPTGCudaDecl_and_Malloc;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	n->p4 = p4;
	n->p5 = p5;
	n->p6 = p6;
	n->p7 = p7;
	n->p8 = p8;
	n->p9 = p9;
	return (PTGNode)n;
}


/* Implementation of Pattern CudaMemCpy */

typedef struct _SPTGCudaMemCpy{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
	PTGNode p4;
} * _PPTGCudaMemCpy;

#ifdef PROTO_OK
static void _PrPTGCudaMemCpy(_PPTGCudaMemCpy n)
#else
static void _PrPTGCudaMemCpy(n)
	_PPTGCudaMemCpy n;
#endif
{
	PTG_OUTPUT_STRING(f, "  cudaMemcpy(");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, ",");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, ",(");
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, ")*sizeof(");
	n->p4->_print(n->p4);
	PTG_OUTPUT_STRING(f, "),");
	PTG_OUTPUT_STRING(f, "cudaMemcpyDeviceToHost);");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGCudaMemCpy(PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4)
#else
PTGNode PTGCudaMemCpy(p1, p2, p3, p4)

PTGNode p1;
PTGNode p2;
PTGNode p3;
PTGNode p4;
#endif
{
	_PPTGCudaMemCpy n;
	n = (_PPTGCudaMemCpy)MALLOC(sizeof(struct _SPTGCudaMemCpy));
	n->_print = (_PTGProc)_PrPTGCudaMemCpy;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	n->p4 = p4;
	return (PTGNode)n;
}


/* Implementation of Pattern CudaFree */

typedef struct _SPTGCudaFree{
	_PTGProc _print;
	PTGNode p1;
} * _PPTGCudaFree;

#ifdef PROTO_OK
static void _PrPTGCudaFree(_PPTGCudaFree n)
#else
static void _PrPTGCudaFree(n)
	_PPTGCudaFree n;
#endif
{
	PTG_OUTPUT_STRING(f, "  cudaFree(");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, ");");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGCudaFree(PTGNode p1)
#else
PTGNode PTGCudaFree(p1)

PTGNode p1;
#endif
{
	_PPTGCudaFree n;
	n = (_PPTGCudaFree)MALLOC(sizeof(struct _SPTGCudaFree));
	n->_print = (_PTGProc)_PrPTGCudaFree;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern DataStmt */

typedef struct _SPTGDataStmt{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
	PTGNode p4;
	PTGNode p5;
	PTGNode p6;
} * _PPTGDataStmt;

#ifdef PROTO_OK
static void _PrPTGDataStmt(_PPTGDataStmt n)
#else
static void _PrPTGDataStmt(n)
	_PPTGDataStmt n;
#endif
{
	PTG_OUTPUT_STRING(f, "replace ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, "static ");
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, " ");
	n->p4->_print(n->p4);
	PTG_OUTPUT_STRING(f, "[");
	n->p5->_print(n->p5);
	PTG_OUTPUT_STRING(f, "] = {");
	n->p6->_print(n->p6);
	PTG_OUTPUT_STRING(f, "};");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGDataStmt(PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5, PTGNode p6)
#else
PTGNode PTGDataStmt(p1, p2, p3, p4, p5, p6)

PTGNode p1;
PTGNode p2;
PTGNode p3;
PTGNode p4;
PTGNode p5;
PTGNode p6;
#endif
{
	_PPTGDataStmt n;
	n = (_PPTGDataStmt)MALLOC(sizeof(struct _SPTGDataStmt));
	n->_print = (_PTGProc)_PrPTGDataStmt;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	n->p4 = p4;
	n->p5 = p5;
	n->p6 = p6;
	return (PTGNode)n;
}


/* Implementation of Pattern DeclareLoopVar */

typedef struct _SPTGDeclareLoopVar{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
} * _PPTGDeclareLoopVar;

#ifdef PROTO_OK
static void _PrPTGDeclareLoopVar(_PPTGDeclareLoopVar n)
#else
static void _PrPTGDeclareLoopVar(n)
	_PPTGDeclareLoopVar n;
#endif
{
	PTG_OUTPUT_STRING(f, "begin_append ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ");
	IndentNewLine(f);
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, "int ii_");
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, ";");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "end_append");
	IndentNewLine(f);
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGDeclareLoopVar(PTGNode p1, PTGNode p2, PTGNode p3)
#else
PTGNode PTGDeclareLoopVar(p1, p2, p3)

PTGNode p1;
PTGNode p2;
PTGNode p3;
#endif
{
	_PPTGDeclareLoopVar n;
	n = (_PPTGDeclareLoopVar)MALLOC(sizeof(struct _SPTGDeclareLoopVar));
	n->_print = (_PTGProc)_PrPTGDeclareLoopVar;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	return (PTGNode)n;
}


/* Implementation of Pattern DeclareIntVar */

typedef struct _SPTGDeclareIntVar{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGDeclareIntVar;

#ifdef PROTO_OK
static void _PrPTGDeclareIntVar(_PPTGDeclareIntVar n)
#else
static void _PrPTGDeclareIntVar(n)
	_PPTGDeclareIntVar n;
#endif
{
	PTG_OUTPUT_STRING(f, "begin_append ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "int ");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, ";");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "end_append");
	IndentNewLine(f);
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGDeclareIntVar(PTGNode p1, PTGNode p2)
#else
PTGNode PTGDeclareIntVar(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGDeclareIntVar n;
	n = (_PPTGDeclareIntVar)MALLOC(sizeof(struct _SPTGDeclareIntVar));
	n->_print = (_PTGProc)_PrPTGDeclareIntVar;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern DeclareRealVar */

typedef struct _SPTGDeclareRealVar{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGDeclareRealVar;

#ifdef PROTO_OK
static void _PrPTGDeclareRealVar(_PPTGDeclareRealVar n)
#else
static void _PrPTGDeclareRealVar(n)
	_PPTGDeclareRealVar n;
#endif
{
	PTG_OUTPUT_STRING(f, "begin_append ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "float ");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, ";");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "end_append");
	IndentNewLine(f);
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGDeclareRealVar(PTGNode p1, PTGNode p2)
#else
PTGNode PTGDeclareRealVar(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGDeclareRealVar n;
	n = (_PPTGDeclareRealVar)MALLOC(sizeof(struct _SPTGDeclareRealVar));
	n->_print = (_PTGProc)_PrPTGDeclareRealVar;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern DefAppend */

typedef struct _SPTGDefAppend{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
} * _PPTGDefAppend;

#ifdef PROTO_OK
static void _PrPTGDefAppend(_PPTGDefAppend n)
#else
static void _PrPTGDefAppend(n)
	_PPTGDefAppend n;
#endif
{
	PTG_OUTPUT_STRING(f, "remove ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ");
	IndentNewLine(f);
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "begin_append ");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, " ");
	IndentNewLine(f);
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, "end_append");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGDefAppend(PTGNode p1, PTGNode p2, PTGNode p3)
#else
PTGNode PTGDefAppend(p1, p2, p3)

PTGNode p1;
PTGNode p2;
PTGNode p3;
#endif
{
	_PPTGDefAppend n;
	n = (_PPTGDefAppend)MALLOC(sizeof(struct _SPTGDefAppend));
	n->_print = (_PTGProc)_PrPTGDefAppend;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	return (PTGNode)n;
}


/* Implementation of Pattern BeginAppend */

typedef struct _SPTGBeginAppend{
	_PTGProc _print;
	PTGNode p1;
} * _PPTGBeginAppend;

#ifdef PROTO_OK
static void _PrPTGBeginAppend(_PPTGBeginAppend n)
#else
static void _PrPTGBeginAppend(n)
	_PPTGBeginAppend n;
#endif
{
	PTG_OUTPUT_STRING(f, "begin_append ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGBeginAppend(PTGNode p1)
#else
PTGNode PTGBeginAppend(p1)

PTGNode p1;
#endif
{
	_PPTGBeginAppend n;
	n = (_PPTGBeginAppend)MALLOC(sizeof(struct _SPTGBeginAppend));
	n->_print = (_PTGProc)_PrPTGBeginAppend;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern EndAppend */

typedef struct _SPTGEndAppend{
	_PTGProc _print;
} * _PPTGEndAppend;

#ifdef PROTO_OK
static void _PrPTGEndAppend(_PPTGEndAppend n)
#else
static void _PrPTGEndAppend(n)
	_PPTGEndAppend n;
#endif
{
	PTG_OUTPUT_STRING(f, "end_append");
	IndentNewLine(f);
}

static struct _SPTGEndAppend _sptgEndAppend = { (_PTGProc) _PrPTGEndAppend };

#ifdef PROTO_OK
PTGNode PTGEndAppend(void)
#else
PTGNode PTGEndAppend()
#endif
{
	return (PTGNode)(&_sptgEndAppend);
}


/* Implementation of Pattern DefineConstant */

typedef struct _SPTGDefineConstant{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGDefineConstant;

#ifdef PROTO_OK
static void _PrPTGDefineConstant(_PPTGDefineConstant n)
#else
static void _PrPTGDefineConstant(n)
	_PPTGDefineConstant n;
#endif
{
	PTG_OUTPUT_STRING(f, "#define ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ");
	n->p2->_print(n->p2);
}

#ifdef PROTO_OK
PTGNode PTGDefineConstant(PTGNode p1, PTGNode p2)
#else
PTGNode PTGDefineConstant(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGDefineConstant n;
	n = (_PPTGDefineConstant)MALLOC(sizeof(struct _SPTGDefineConstant));
	n->_print = (_PTGProc)_PrPTGDefineConstant;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern DefineConstantCR */

typedef struct _SPTGDefineConstantCR{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGDefineConstantCR;

#ifdef PROTO_OK
static void _PrPTGDefineConstantCR(_PPTGDefineConstantCR n)
#else
static void _PrPTGDefineConstantCR(n)
	_PPTGDefineConstantCR n;
#endif
{
	PTG_OUTPUT_STRING(f, "#define ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ");
	n->p2->_print(n->p2);
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGDefineConstantCR(PTGNode p1, PTGNode p2)
#else
PTGNode PTGDefineConstantCR(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGDefineConstantCR n;
	n = (_PPTGDefineConstantCR)MALLOC(sizeof(struct _SPTGDefineConstantCR));
	n->_print = (_PTGProc)_PrPTGDefineConstantCR;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern Else */

typedef struct _SPTGElse{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
} * _PPTGElse;

#ifdef PROTO_OK
static void _PrPTGElse(_PPTGElse n)
#else
static void _PrPTGElse(n)
	_PPTGElse n;
#endif
{
	PTG_OUTPUT_STRING(f, "replace ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ");
	n->p2->_print(n->p2);
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, "} else {");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGElse(PTGNode p1, PTGNode p2, PTGNode p3)
#else
PTGNode PTGElse(p1, p2, p3)

PTGNode p1;
PTGNode p2;
PTGNode p3;
#endif
{
	_PPTGElse n;
	n = (_PPTGElse)MALLOC(sizeof(struct _SPTGElse));
	n->_print = (_PTGProc)_PrPTGElse;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	return (PTGNode)n;
}


/* Implementation of Pattern ElseIf */

typedef struct _SPTGElseIf{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
	PTGNode p4;
} * _PPTGElseIf;

#ifdef PROTO_OK
static void _PrPTGElseIf(_PPTGElseIf n)
#else
static void _PrPTGElseIf(n)
	_PPTGElseIf n;
#endif
{
	PTG_OUTPUT_STRING(f, "replace ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ");
	n->p2->_print(n->p2);
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, "} else if ( ");
	n->p4->_print(n->p4);
	PTG_OUTPUT_STRING(f, " ) {");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGElseIf(PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4)
#else
PTGNode PTGElseIf(p1, p2, p3, p4)

PTGNode p1;
PTGNode p2;
PTGNode p3;
PTGNode p4;
#endif
{
	_PPTGElseIf n;
	n = (_PPTGElseIf)MALLOC(sizeof(struct _SPTGElseIf));
	n->_print = (_PTGProc)_PrPTGElseIf;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	n->p4 = p4;
	return (PTGNode)n;
}


/* Implementation of Pattern EndifStmt */

typedef struct _SPTGEndifStmt{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGEndifStmt;

#ifdef PROTO_OK
static void _PrPTGEndifStmt(_PPTGEndifStmt n)
#else
static void _PrPTGEndifStmt(n)
	_PPTGEndifStmt n;
#endif
{
	PTG_OUTPUT_STRING(f, "replace ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, "}");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGEndifStmt(PTGNode p1, PTGNode p2)
#else
PTGNode PTGEndifStmt(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGEndifStmt n;
	n = (_PPTGEndifStmt)MALLOC(sizeof(struct _SPTGEndifStmt));
	n->_print = (_PTGProc)_PrPTGEndifStmt;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern EndifStmtNamed */

typedef struct _SPTGEndifStmtNamed{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
} * _PPTGEndifStmtNamed;

#ifdef PROTO_OK
static void _PrPTGEndifStmtNamed(_PPTGEndifStmtNamed n)
#else
static void _PrPTGEndifStmtNamed(n)
	_PPTGEndifStmtNamed n;
#endif
{
	PTG_OUTPUT_STRING(f, "replace ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, ":");
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, "}");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGEndifStmtNamed(PTGNode p1, PTGNode p2, PTGNode p3)
#else
PTGNode PTGEndifStmtNamed(p1, p2, p3)

PTGNode p1;
PTGNode p2;
PTGNode p3;
#endif
{
	_PPTGEndifStmtNamed n;
	n = (_PPTGEndifStmtNamed)MALLOC(sizeof(struct _SPTGEndifStmtNamed));
	n->_print = (_PTGProc)_PrPTGEndifStmtNamed;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	return (PTGNode)n;
}


/* Implementation of Pattern EndLoop */

typedef struct _SPTGEndLoop{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
	PTGNode p4;
} * _PPTGEndLoop;

#ifdef PROTO_OK
static void _PrPTGEndLoop(_PPTGEndLoop n)
#else
static void _PrPTGEndLoop(n)
	_PPTGEndLoop n;
#endif
{
	PTG_OUTPUT_STRING(f, "replace ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ");
	n->p2->_print(n->p2);
	n->p3->_print(n->p3);
	n->p4->_print(n->p4);
	PTG_OUTPUT_STRING(f, "}");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGEndLoop(PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4)
#else
PTGNode PTGEndLoop(p1, p2, p3, p4)

PTGNode p1;
PTGNode p2;
PTGNode p3;
PTGNode p4;
#endif
{
	_PPTGEndLoop n;
	n = (_PPTGEndLoop)MALLOC(sizeof(struct _SPTGEndLoop));
	n->_print = (_PTGProc)_PrPTGEndLoop;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	n->p4 = p4;
	return (PTGNode)n;
}


/* Implementation of Pattern Exit */

typedef struct _SPTGExit{
	_PTGProc _print;
} * _PPTGExit;

#ifdef PROTO_OK
static void _PrPTGExit(_PPTGExit n)
#else
static void _PrPTGExit(n)
	_PPTGExit n;
#endif
{
	PTG_OUTPUT_STRING(f, "exit(0);");
}

static struct _SPTGExit _sptgExit = { (_PTGProc) _PrPTGExit };

#ifdef PROTO_OK
PTGNode PTGExit(void)
#else
PTGNode PTGExit()
#endif
{
	return (PTGNode)(&_sptgExit);
}


/* Implementation of Pattern Extern */

typedef struct _SPTGExtern{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
} * _PPTGExtern;

#ifdef PROTO_OK
static void _PrPTGExtern(_PPTGExtern n)
#else
static void _PrPTGExtern(n)
	_PPTGExtern n;
#endif
{
	PTG_OUTPUT_STRING(f, "begin_append ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ");
	IndentNewLine(f);
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, "extern ");
	n->p3->_print(n->p3);
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "end_append");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGExtern(PTGNode p1, PTGNode p2, PTGNode p3)
#else
PTGNode PTGExtern(p1, p2, p3)

PTGNode p1;
PTGNode p2;
PTGNode p3;
#endif
{
	_PPTGExtern n;
	n = (_PPTGExtern)MALLOC(sizeof(struct _SPTGExtern));
	n->_print = (_PTGProc)_PrPTGExtern;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	return (PTGNode)n;
}


/* Implementation of Pattern EndFunction */

typedef struct _SPTGEndFunction{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
	PTGNode p4;
	PTGNode p5;
} * _PPTGEndFunction;

#ifdef PROTO_OK
static void _PrPTGEndFunction(_PPTGEndFunction n)
#else
static void _PrPTGEndFunction(n)
	_PPTGEndFunction n;
#endif
{
	PTG_OUTPUT_STRING(f, "remove ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "begin_append ");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, " ");
	n->p3->_print(n->p3);
	IndentNewLine(f);
	n->p4->_print(n->p4);
	PTG_OUTPUT_STRING(f, "return(");
	n->p5->_print(n->p5);
	PTG_OUTPUT_STRING(f, ")");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "}");
	IndentNewLine(f);
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "end_append");
}

#ifdef PROTO_OK
PTGNode PTGEndFunction(PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5)
#else
PTGNode PTGEndFunction(p1, p2, p3, p4, p5)

PTGNode p1;
PTGNode p2;
PTGNode p3;
PTGNode p4;
PTGNode p5;
#endif
{
	_PPTGEndFunction n;
	n = (_PPTGEndFunction)MALLOC(sizeof(struct _SPTGEndFunction));
	n->_print = (_PTGProc)_PrPTGEndFunction;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	n->p4 = p4;
	n->p5 = p5;
	return (PTGNode)n;
}


/* Implementation of Pattern EndProgram */

typedef struct _SPTGEndProgram{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGEndProgram;

#ifdef PROTO_OK
static void _PrPTGEndProgram(_PPTGEndProgram n)
#else
static void _PrPTGEndProgram(n)
	_PPTGEndProgram n;
#endif
{
	PTG_OUTPUT_STRING(f, "replace ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "   return(0);");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "begin_append ");
	n->p2->_print(n->p2);
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "}");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "end_append");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGEndProgram(PTGNode p1, PTGNode p2)
#else
PTGNode PTGEndProgram(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGEndProgram n;
	n = (_PPTGEndProgram)MALLOC(sizeof(struct _SPTGEndProgram));
	n->_print = (_PTGProc)_PrPTGEndProgram;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern EndProgramGPU */

typedef struct _SPTGEndProgramGPU{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
	PTGNode p4;
} * _PPTGEndProgramGPU;

#ifdef PROTO_OK
static void _PrPTGEndProgramGPU(_PPTGEndProgramGPU n)
#else
static void _PrPTGEndProgramGPU(n)
	_PPTGEndProgramGPU n;
#endif
{
	PTG_OUTPUT_STRING(f, "remove ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "begin_append ");
	n->p2->_print(n->p2);
	IndentNewLine(f);
	n->p3->_print(n->p3);
	IndentNewLine(f);
	n->p4->_print(n->p4);
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "}");
	PTG_OUTPUT_STRING(f, "end_append");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGEndProgramGPU(PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4)
#else
PTGNode PTGEndProgramGPU(p1, p2, p3, p4)

PTGNode p1;
PTGNode p2;
PTGNode p3;
PTGNode p4;
#endif
{
	_PPTGEndProgramGPU n;
	n = (_PPTGEndProgramGPU)MALLOC(sizeof(struct _SPTGEndProgramGPU));
	n->_print = (_PTGProc)_PrPTGEndProgramGPU;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	n->p4 = p4;
	return (PTGNode)n;
}


/* Implementation of Pattern EndRoutine */

typedef struct _SPTGEndRoutine{
	_PTGProc _print;
	PTGNode p1;
} * _PPTGEndRoutine;

#ifdef PROTO_OK
static void _PrPTGEndRoutine(_PPTGEndRoutine n)
#else
static void _PrPTGEndRoutine(n)
	_PPTGEndRoutine n;
#endif
{
	PTG_OUTPUT_STRING(f, "replace ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " }");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGEndRoutine(PTGNode p1)
#else
PTGNode PTGEndRoutine(p1)

PTGNode p1;
#endif
{
	_PPTGEndRoutine n;
	n = (_PPTGEndRoutine)MALLOC(sizeof(struct _SPTGEndRoutine));
	n->_print = (_PTGProc)_PrPTGEndRoutine;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern Expr */

typedef struct _SPTGExpr{
	_PTGProc _print;
	PTGNode p1;
} * _PPTGExpr;

#ifdef PROTO_OK
static void _PrPTGExpr(_PPTGExpr n)
#else
static void _PrPTGExpr(n)
	_PPTGExpr n;
#endif
{
	PTG_OUTPUT_STRING(f, "(");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, ")");
}

#ifdef PROTO_OK
PTGNode PTGExpr(PTGNode p1)
#else
PTGNode PTGExpr(p1)

PTGNode p1;
#endif
{
	_PPTGExpr n;
	n = (_PPTGExpr)MALLOC(sizeof(struct _SPTGExpr));
	n->_print = (_PTGProc)_PrPTGExpr;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern ExprArgs */

typedef struct _SPTGExprArgs{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
} * _PPTGExprArgs;

#ifdef PROTO_OK
static void _PrPTGExprArgs(_PPTGExprArgs n)
#else
static void _PrPTGExprArgs(n)
	_PPTGExprArgs n;
#endif
{
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, " ");
	n->p3->_print(n->p3);
}

#ifdef PROTO_OK
PTGNode PTGExprArgs(PTGNode p1, PTGNode p2, PTGNode p3)
#else
PTGNode PTGExprArgs(p1, p2, p3)

PTGNode p1;
PTGNode p2;
PTGNode p3;
#endif
{
	_PPTGExprArgs n;
	n = (_PPTGExprArgs)MALLOC(sizeof(struct _SPTGExprArgs));
	n->_print = (_PTGProc)_PrPTGExprArgs;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	return (PTGNode)n;
}


/* Implementation of Pattern ExternDecl */

typedef struct _SPTGExternDecl{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
} * _PPTGExternDecl;

#ifdef PROTO_OK
static void _PrPTGExternDecl(_PPTGExternDecl n)
#else
static void _PrPTGExternDecl(n)
	_PPTGExternDecl n;
#endif
{
	PTG_OUTPUT_STRING(f, "begin_append ");
	n->p1->_print(n->p1);
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "extern void ");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, "( ");
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, ");");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "end_append");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGExternDecl(PTGNode p1, PTGNode p2, PTGNode p3)
#else
PTGNode PTGExternDecl(p1, p2, p3)

PTGNode p1;
PTGNode p2;
PTGNode p3;
#endif
{
	_PPTGExternDecl n;
	n = (_PPTGExternDecl)MALLOC(sizeof(struct _SPTGExternDecl));
	n->_print = (_PTGProc)_PrPTGExternDecl;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	return (PTGNode)n;
}


/* Implementation of Pattern FreeAlloc */

typedef struct _SPTGFreeAlloc{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGFreeAlloc;

#ifdef PROTO_OK
static void _PrPTGFreeAlloc(_PPTGFreeAlloc n)
#else
static void _PrPTGFreeAlloc(n)
	_PPTGFreeAlloc n;
#endif
{
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "free(");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, ");");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGFreeAlloc(PTGNode p1, PTGNode p2)
#else
PTGNode PTGFreeAlloc(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGFreeAlloc n;
	n = (_PPTGFreeAlloc)MALLOC(sizeof(struct _SPTGFreeAlloc));
	n->_print = (_PTGProc)_PrPTGFreeAlloc;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern ForLoop */

typedef struct _SPTGForLoop{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGForLoop;

#ifdef PROTO_OK
static void _PrPTGForLoop(_PPTGForLoop n)
#else
static void _PrPTGForLoop(n)
	_PPTGForLoop n;
#endif
{
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "for ");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, " {");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGForLoop(PTGNode p1, PTGNode p2)
#else
PTGNode PTGForLoop(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGForLoop n;
	n = (_PPTGForLoop)MALLOC(sizeof(struct _SPTGForLoop));
	n->_print = (_PTGProc)_PrPTGForLoop;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern ForLoopReplace */

typedef struct _SPTGForLoopReplace{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
	PTGNode p4;
	PTGNode p5;
} * _PPTGForLoopReplace;

#ifdef PROTO_OK
static void _PrPTGForLoopReplace(_PPTGForLoopReplace n)
#else
static void _PrPTGForLoopReplace(n)
	_PPTGForLoopReplace n;
#endif
{
	PTG_OUTPUT_STRING(f, "replace ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ");
	n->p2->_print(n->p2);
	n->p3->_print(n->p3);
	n->p4->_print(n->p4);
	PTG_OUTPUT_STRING(f, "for ");
	n->p5->_print(n->p5);
	PTG_OUTPUT_STRING(f, " {");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGForLoopReplace(PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5)
#else
PTGNode PTGForLoopReplace(p1, p2, p3, p4, p5)

PTGNode p1;
PTGNode p2;
PTGNode p3;
PTGNode p4;
PTGNode p5;
#endif
{
	_PPTGForLoopReplace n;
	n = (_PPTGForLoopReplace)MALLOC(sizeof(struct _SPTGForLoopReplace));
	n->_print = (_PTGProc)_PrPTGForLoopReplace;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	n->p4 = p4;
	n->p5 = p5;
	return (PTGNode)n;
}


/* Implementation of Pattern FTNFunction */

typedef struct _SPTGFTNFunction{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGFTNFunction;

#ifdef PROTO_OK
static void _PrPTGFTNFunction(_PPTGFTNFunction n)
#else
static void _PrPTGFTNFunction(n)
	_PPTGFTNFunction n;
#endif
{
	PTG_OUTPUT_STRING(f, "FTNREF");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "D(");
	n->p2->_print(n->p2);
}

#ifdef PROTO_OK
PTGNode PTGFTNFunction(PTGNode p1, PTGNode p2)
#else
PTGNode PTGFTNFunction(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGFTNFunction n;
	n = (_PPTGFTNFunction)MALLOC(sizeof(struct _SPTGFTNFunction));
	n->_print = (_PTGProc)_PrPTGFTNFunction;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern FunctionCall */

typedef struct _SPTGFunctionCall{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGFunctionCall;

#ifdef PROTO_OK
static void _PrPTGFunctionCall(_PPTGFunctionCall n)
#else
static void _PrPTGFunctionCall(n)
	_PPTGFunctionCall n;
#endif
{
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, " = ");
}

#ifdef PROTO_OK
PTGNode PTGFunctionCall(PTGNode p1, PTGNode p2)
#else
PTGNode PTGFunctionCall(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGFunctionCall n;
	n = (_PPTGFunctionCall)MALLOC(sizeof(struct _SPTGFunctionCall));
	n->_print = (_PTGProc)_PrPTGFunctionCall;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern FunctionRef */

typedef struct _SPTGFunctionRef{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGFunctionRef;

#ifdef PROTO_OK
static void _PrPTGFunctionRef(_PPTGFunctionRef n)
#else
static void _PrPTGFunctionRef(n)
	_PPTGFunctionRef n;
#endif
{
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "(");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, ")");
}

#ifdef PROTO_OK
PTGNode PTGFunctionRef(PTGNode p1, PTGNode p2)
#else
PTGNode PTGFunctionRef(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGFunctionRef n;
	n = (_PPTGFunctionRef)MALLOC(sizeof(struct _SPTGFunctionRef));
	n->_print = (_PTGProc)_PrPTGFunctionRef;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern GenerateForLoop */

typedef struct _SPTGGenerateForLoop{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
	PTGNode p4;
	PTGNode p5;
	PTGNode p6;
} * _PPTGGenerateForLoop;

#ifdef PROTO_OK
static void _PrPTGGenerateForLoop(_PPTGGenerateForLoop n)
#else
static void _PrPTGGenerateForLoop(n)
	_PPTGGenerateForLoop n;
#endif
{
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "for(");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, "=");
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, ";");
	n->p4->_print(n->p4);
	PTG_OUTPUT_STRING(f, "<=");
	n->p5->_print(n->p5);
	PTG_OUTPUT_STRING(f, ";");
	n->p6->_print(n->p6);
	PTG_OUTPUT_STRING(f, "++) {");
}

#ifdef PROTO_OK
PTGNode PTGGenerateForLoop(PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5, PTGNode p6)
#else
PTGNode PTGGenerateForLoop(p1, p2, p3, p4, p5, p6)

PTGNode p1;
PTGNode p2;
PTGNode p3;
PTGNode p4;
PTGNode p5;
PTGNode p6;
#endif
{
	_PPTGGenerateForLoop n;
	n = (_PPTGGenerateForLoop)MALLOC(sizeof(struct _SPTGGenerateForLoop));
	n->_print = (_PTGProc)_PrPTGGenerateForLoop;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	n->p4 = p4;
	n->p5 = p5;
	n->p6 = p6;
	return (PTGNode)n;
}


/* Implementation of Pattern GenerateEndLoop */

typedef struct _SPTGGenerateEndLoop{
	_PTGProc _print;
	PTGNode p1;
} * _PPTGGenerateEndLoop;

#ifdef PROTO_OK
static void _PrPTGGenerateEndLoop(_PPTGGenerateEndLoop n)
#else
static void _PrPTGGenerateEndLoop(n)
	_PPTGGenerateEndLoop n;
#endif
{
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "}");
}

#ifdef PROTO_OK
PTGNode PTGGenerateEndLoop(PTGNode p1)
#else
PTGNode PTGGenerateEndLoop(p1)

PTGNode p1;
#endif
{
	_PPTGGenerateEndLoop n;
	n = (_PPTGGenerateEndLoop)MALLOC(sizeof(struct _SPTGGenerateEndLoop));
	n->_print = (_PTGProc)_PrPTGGenerateEndLoop;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern GoTo */

typedef struct _SPTGGoTo{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGGoTo;

#ifdef PROTO_OK
static void _PrPTGGoTo(_PPTGGoTo n)
#else
static void _PrPTGGoTo(n)
	_PPTGGoTo n;
#endif
{
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "goto ");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, ";");
}

#ifdef PROTO_OK
PTGNode PTGGoTo(PTGNode p1, PTGNode p2)
#else
PTGNode PTGGoTo(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGGoTo n;
	n = (_PPTGGoTo)MALLOC(sizeof(struct _SPTGGoTo));
	n->_print = (_PTGProc)_PrPTGGoTo;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern IfStmt */

typedef struct _SPTGIfStmt{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
	PTGNode p4;
} * _PPTGIfStmt;

#ifdef PROTO_OK
static void _PrPTGIfStmt(_PPTGIfStmt n)
#else
static void _PrPTGIfStmt(n)
	_PPTGIfStmt n;
#endif
{
	PTG_OUTPUT_STRING(f, "replace ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ");
	n->p2->_print(n->p2);
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, "if ( ");
	n->p4->_print(n->p4);
	PTG_OUTPUT_STRING(f, " ) {");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGIfStmt(PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4)
#else
PTGNode PTGIfStmt(p1, p2, p3, p4)

PTGNode p1;
PTGNode p2;
PTGNode p3;
PTGNode p4;
#endif
{
	_PPTGIfStmt n;
	n = (_PPTGIfStmt)MALLOC(sizeof(struct _SPTGIfStmt));
	n->_print = (_PTGProc)_PrPTGIfStmt;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	n->p4 = p4;
	return (PTGNode)n;
}


/* Implementation of Pattern IfStmtSingle */

typedef struct _SPTGIfStmtSingle{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
	PTGNode p4;
	PTGNode p5;
} * _PPTGIfStmtSingle;

#ifdef PROTO_OK
static void _PrPTGIfStmtSingle(_PPTGIfStmtSingle n)
#else
static void _PrPTGIfStmtSingle(n)
	_PPTGIfStmtSingle n;
#endif
{
	PTG_OUTPUT_STRING(f, "replace ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ");
	n->p2->_print(n->p2);
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, "if ( ");
	n->p4->_print(n->p4);
	PTG_OUTPUT_STRING(f, " ) { ");
	n->p5->_print(n->p5);
	PTG_OUTPUT_STRING(f, " }");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGIfStmtSingle(PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5)
#else
PTGNode PTGIfStmtSingle(p1, p2, p3, p4, p5)

PTGNode p1;
PTGNode p2;
PTGNode p3;
PTGNode p4;
PTGNode p5;
#endif
{
	_PPTGIfStmtSingle n;
	n = (_PPTGIfStmtSingle)MALLOC(sizeof(struct _SPTGIfStmtSingle));
	n->_print = (_PTGProc)_PrPTGIfStmtSingle;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	n->p4 = p4;
	n->p5 = p5;
	return (PTGNode)n;
}


/* Implementation of Pattern IfStmtLabel */

typedef struct _SPTGIfStmtLabel{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
	PTGNode p4;
	PTGNode p5;
} * _PPTGIfStmtLabel;

#ifdef PROTO_OK
static void _PrPTGIfStmtLabel(_PPTGIfStmtLabel n)
#else
static void _PrPTGIfStmtLabel(n)
	_PPTGIfStmtLabel n;
#endif
{
	PTG_OUTPUT_STRING(f, "replace ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ");
	n->p2->_print(n->p2);
	n->p3->_print(n->p3);
	n->p4->_print(n->p4);
	PTG_OUTPUT_STRING(f, "if ( ");
	n->p5->_print(n->p5);
	PTG_OUTPUT_STRING(f, " ) {");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGIfStmtLabel(PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5)
#else
PTGNode PTGIfStmtLabel(p1, p2, p3, p4, p5)

PTGNode p1;
PTGNode p2;
PTGNode p3;
PTGNode p4;
PTGNode p5;
#endif
{
	_PPTGIfStmtLabel n;
	n = (_PPTGIfStmtLabel)MALLOC(sizeof(struct _SPTGIfStmtLabel));
	n->_print = (_PTGProc)_PrPTGIfStmtLabel;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	n->p4 = p4;
	n->p5 = p5;
	return (PTGNode)n;
}


/* Implementation of Pattern Include */

typedef struct _SPTGInclude{
	_PTGProc _print;
	PTGNode p1;
} * _PPTGInclude;

#ifdef PROTO_OK
static void _PrPTGInclude(_PPTGInclude n)
#else
static void _PrPTGInclude(n)
	_PPTGInclude n;
#endif
{
	PTG_OUTPUT_STRING(f, "begin_append 0 ");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "#include \"");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, ".h\"");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "end_append");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGInclude(PTGNode p1)
#else
PTGNode PTGInclude(p1)

PTGNode p1;
#endif
{
	_PPTGInclude n;
	n = (_PPTGInclude)MALLOC(sizeof(struct _SPTGInclude));
	n->_print = (_PTGProc)_PrPTGInclude;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern IncludeFilesGPU */

typedef struct _SPTGIncludeFilesGPU{
	_PTGProc _print;
} * _PPTGIncludeFilesGPU;

#ifdef PROTO_OK
static void _PrPTGIncludeFilesGPU(_PPTGIncludeFilesGPU n)
#else
static void _PrPTGIncludeFilesGPU(n)
	_PPTGIncludeFilesGPU n;
#endif
{
	PTG_OUTPUT_STRING(f, "begin_append 0 ");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "#include <stdio.h>");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "#include <stdlib.h>");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "#include <math.h>");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "#include <cutil.h>");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "#include \"ftocmacros.h\"");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "#define TRUE 1");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "#define FALSE 0");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "end_append");
	IndentNewLine(f);
}

static struct _SPTGIncludeFilesGPU _sptgIncludeFilesGPU = { (_PTGProc) _PrPTGIncludeFilesGPU };

#ifdef PROTO_OK
PTGNode PTGIncludeFilesGPU(void)
#else
PTGNode PTGIncludeFilesGPU()
#endif
{
	return (PTGNode)(&_sptgIncludeFilesGPU);
}


/* Implementation of Pattern IncludeFilesCPU */

typedef struct _SPTGIncludeFilesCPU{
	_PTGProc _print;
} * _PPTGIncludeFilesCPU;

#ifdef PROTO_OK
static void _PrPTGIncludeFilesCPU(_PPTGIncludeFilesCPU n)
#else
static void _PrPTGIncludeFilesCPU(n)
	_PPTGIncludeFilesCPU n;
#endif
{
	PTG_OUTPUT_STRING(f, "begin_append 0 ");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "#include <stdio.h>");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "#include <stdlib.h>");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "#include <math.h>");
	IndentNewLine(f);
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "#include \"ftocmacros.h\"");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "#define TRUE 1");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "#define FALSE 0");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "end_append");
	IndentNewLine(f);
}

static struct _SPTGIncludeFilesCPU _sptgIncludeFilesCPU = { (_PTGProc) _PrPTGIncludeFilesCPU };

#ifdef PROTO_OK
PTGNode PTGIncludeFilesCPU(void)
#else
PTGNode PTGIncludeFilesCPU()
#endif
{
	return (PTGNode)(&_sptgIncludeFilesCPU);
}


/* Implementation of Pattern Indent */

typedef struct _SPTGIndent{
	_PTGProc _print;
	int p1;
} * _PPTGIndent;

#ifdef PROTO_OK
static void _PrPTGIndent(_PPTGIndent n)
#else
static void _PrPTGIndent(n)
	_PPTGIndent n;
#endif
{
	IndentLabl(f, n->p1);
}

#ifdef PROTO_OK
PTGNode PTGIndent(int p1)
#else
PTGNode PTGIndent(p1)

int p1;
#endif
{
	_PPTGIndent n;
	n = (_PPTGIndent)MALLOC(sizeof(struct _SPTGIndent));
	n->_print = (_PTGProc)_PrPTGIndent;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern IntrinsicRef */

typedef struct _SPTGIntrinsicRef{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGIntrinsicRef;

#ifdef PROTO_OK
static void _PrPTGIntrinsicRef(_PPTGIntrinsicRef n)
#else
static void _PrPTGIntrinsicRef(n)
	_PPTGIntrinsicRef n;
#endif
{
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "(");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, ")");
}

#ifdef PROTO_OK
PTGNode PTGIntrinsicRef(PTGNode p1, PTGNode p2)
#else
PTGNode PTGIntrinsicRef(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGIntrinsicRef n;
	n = (_PPTGIntrinsicRef)MALLOC(sizeof(struct _SPTGIntrinsicRef));
	n->_print = (_PTGProc)_PrPTGIntrinsicRef;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern KernelFunctionFirst */

typedef struct _SPTGKernelFunctionFirst{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
	PTGNode p4;
	PTGNode p5;
	PTGNode p6;
} * _PPTGKernelFunctionFirst;

#ifdef PROTO_OK
static void _PrPTGKernelFunctionFirst(_PPTGKernelFunctionFirst n)
#else
static void _PrPTGKernelFunctionFirst(n)
	_PPTGKernelFunctionFirst n;
#endif
{
	PTG_OUTPUT_STRING(f, "replace ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, " ");
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, " ");
	n->p4->_print(n->p4);
	PTG_OUTPUT_STRING(f, "(");
	n->p5->_print(n->p5);
	PTG_OUTPUT_STRING(f, ") {");
	IndentNewLine(f);
	n->p6->_print(n->p6);
}

#ifdef PROTO_OK
PTGNode PTGKernelFunctionFirst(PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5, PTGNode p6)
#else
PTGNode PTGKernelFunctionFirst(p1, p2, p3, p4, p5, p6)

PTGNode p1;
PTGNode p2;
PTGNode p3;
PTGNode p4;
PTGNode p5;
PTGNode p6;
#endif
{
	_PPTGKernelFunctionFirst n;
	n = (_PPTGKernelFunctionFirst)MALLOC(sizeof(struct _SPTGKernelFunctionFirst));
	n->_print = (_PTGProc)_PrPTGKernelFunctionFirst;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	n->p4 = p4;
	n->p5 = p5;
	n->p6 = p6;
	return (PTGNode)n;
}


/* Implementation of Pattern KernelRoutineFirst */

typedef struct _SPTGKernelRoutineFirst{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
	PTGNode p4;
} * _PPTGKernelRoutineFirst;

#ifdef PROTO_OK
static void _PrPTGKernelRoutineFirst(_PPTGKernelRoutineFirst n)
#else
static void _PrPTGKernelRoutineFirst(n)
	_PPTGKernelRoutineFirst n;
#endif
{
	PTG_OUTPUT_STRING(f, "replace ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, " void ");
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, "(");
	n->p4->_print(n->p4);
	PTG_OUTPUT_STRING(f, ") {");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGKernelRoutineFirst(PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4)
#else
PTGNode PTGKernelRoutineFirst(p1, p2, p3, p4)

PTGNode p1;
PTGNode p2;
PTGNode p3;
PTGNode p4;
#endif
{
	_PPTGKernelRoutineFirst n;
	n = (_PPTGKernelRoutineFirst)MALLOC(sizeof(struct _SPTGKernelRoutineFirst));
	n->_print = (_PTGProc)_PrPTGKernelRoutineFirst;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	n->p4 = p4;
	return (PTGNode)n;
}


/* Implementation of Pattern Label */

typedef struct _SPTGLabel{
	_PTGProc _print;
	PTGNode p1;
} * _PPTGLabel;

#ifdef PROTO_OK
static void _PrPTGLabel(_PPTGLabel n)
#else
static void _PrPTGLabel(n)
	_PPTGLabel n;
#endif
{
	PTG_OUTPUT_STRING(f, "C__");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, ": ");
}

#ifdef PROTO_OK
PTGNode PTGLabel(PTGNode p1)
#else
PTGNode PTGLabel(p1)

PTGNode p1;
#endif
{
	_PPTGLabel n;
	n = (_PPTGLabel)MALLOC(sizeof(struct _SPTGLabel));
	n->_print = (_PTGProc)_PrPTGLabel;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern LoopBounds */

typedef struct _SPTGLoopBounds{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
	PTGNode p4;
	PTGNode p5;
} * _PPTGLoopBounds;

#ifdef PROTO_OK
static void _PrPTGLoopBounds(_PPTGLoopBounds n)
#else
static void _PrPTGLoopBounds(n)
	_PPTGLoopBounds n;
#endif
{
	PTG_OUTPUT_STRING(f, "(");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "=");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, ";");
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, "<=");
	n->p4->_print(n->p4);
	PTG_OUTPUT_STRING(f, ";");
	n->p5->_print(n->p5);
	PTG_OUTPUT_STRING(f, "++)");
}

#ifdef PROTO_OK
PTGNode PTGLoopBounds(PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5)
#else
PTGNode PTGLoopBounds(p1, p2, p3, p4, p5)

PTGNode p1;
PTGNode p2;
PTGNode p3;
PTGNode p4;
PTGNode p5;
#endif
{
	_PPTGLoopBounds n;
	n = (_PPTGLoopBounds)MALLOC(sizeof(struct _SPTGLoopBounds));
	n->_print = (_PTGProc)_PrPTGLoopBounds;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	n->p4 = p4;
	n->p5 = p5;
	return (PTGNode)n;
}


/* Implementation of Pattern LoopGen */

typedef struct _SPTGLoopGen{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
	PTGNode p4;
	PTGNode p5;
	PTGNode p6;
} * _PPTGLoopGen;

#ifdef PROTO_OK
static void _PrPTGLoopGen(_PPTGLoopGen n)
#else
static void _PrPTGLoopGen(n)
	_PPTGLoopGen n;
#endif
{
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "for (");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, "=");
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, ";");
	n->p4->_print(n->p4);
	PTG_OUTPUT_STRING(f, "<=");
	n->p5->_print(n->p5);
	PTG_OUTPUT_STRING(f, ";");
	n->p6->_print(n->p6);
	PTG_OUTPUT_STRING(f, "++) {");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGLoopGen(PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5, PTGNode p6)
#else
PTGNode PTGLoopGen(p1, p2, p3, p4, p5, p6)

PTGNode p1;
PTGNode p2;
PTGNode p3;
PTGNode p4;
PTGNode p5;
PTGNode p6;
#endif
{
	_PPTGLoopGen n;
	n = (_PPTGLoopGen)MALLOC(sizeof(struct _SPTGLoopGen));
	n->_print = (_PTGProc)_PrPTGLoopGen;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	n->p4 = p4;
	n->p5 = p5;
	n->p6 = p6;
	return (PTGNode)n;
}


/* Implementation of Pattern LoopGenEnd */

typedef struct _SPTGLoopGenEnd{
	_PTGProc _print;
	PTGNode p1;
} * _PPTGLoopGenEnd;

#ifdef PROTO_OK
static void _PrPTGLoopGenEnd(_PPTGLoopGenEnd n)
#else
static void _PrPTGLoopGenEnd(n)
	_PPTGLoopGenEnd n;
#endif
{
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "}");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGLoopGenEnd(PTGNode p1)
#else
PTGNode PTGLoopGenEnd(p1)

PTGNode p1;
#endif
{
	_PPTGLoopGenEnd n;
	n = (_PPTGLoopGenEnd)MALLOC(sizeof(struct _SPTGLoopGenEnd));
	n->_print = (_PTGProc)_PrPTGLoopGenEnd;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern Malloc */

typedef struct _SPTGMalloc{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
	PTGNode p4;
	PTGNode p5;
} * _PPTGMalloc;

#ifdef PROTO_OK
static void _PrPTGMalloc(_PPTGMalloc n)
#else
static void _PrPTGMalloc(n)
	_PPTGMalloc n;
#endif
{
	n->p1->_print(n->p1);
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, " = (");
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, "*) malloc(");
	n->p4->_print(n->p4);
	PTG_OUTPUT_STRING(f, "*sizeof(");
	n->p5->_print(n->p5);
	PTG_OUTPUT_STRING(f, "));");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGMalloc(PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5)
#else
PTGNode PTGMalloc(p1, p2, p3, p4, p5)

PTGNode p1;
PTGNode p2;
PTGNode p3;
PTGNode p4;
PTGNode p5;
#endif
{
	_PPTGMalloc n;
	n = (_PPTGMalloc)MALLOC(sizeof(struct _SPTGMalloc));
	n->_print = (_PTGProc)_PrPTGMalloc;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	n->p4 = p4;
	n->p5 = p5;
	return (PTGNode)n;
}


/* Implementation of Pattern MallocTest */

typedef struct _SPTGMallocTest{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
	PTGNode p4;
	PTGNode p5;
} * _PPTGMallocTest;

#ifdef PROTO_OK
static void _PrPTGMallocTest(_PPTGMallocTest n)
#else
static void _PrPTGMallocTest(n)
	_PPTGMallocTest n;
#endif
{
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " if (");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, "== NULL) {");
	IndentNewLine(f);
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, "   printf(\"ERROR: memory allocation error\");");
	IndentNewLine(f);
	n->p4->_print(n->p4);
	PTG_OUTPUT_STRING(f, "   exit(1);");
	IndentNewLine(f);
	n->p5->_print(n->p5);
	PTG_OUTPUT_STRING(f, " }");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGMallocTest(PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5)
#else
PTGNode PTGMallocTest(p1, p2, p3, p4, p5)

PTGNode p1;
PTGNode p2;
PTGNode p3;
PTGNode p4;
PTGNode p5;
#endif
{
	_PPTGMallocTest n;
	n = (_PPTGMallocTest)MALLOC(sizeof(struct _SPTGMallocTest));
	n->_print = (_PTGProc)_PrPTGMallocTest;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	n->p4 = p4;
	n->p5 = p5;
	return (PTGNode)n;
}


/* Implementation of Pattern Max */

typedef struct _SPTGMax{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGMax;

#ifdef PROTO_OK
static void _PrPTGMax(_PPTGMax n)
#else
static void _PrPTGMax(n)
	_PPTGMax n;
#endif
{
	PTG_OUTPUT_STRING(f, "MAX(");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, ",");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, ")");
}

#ifdef PROTO_OK
PTGNode PTGMax(PTGNode p1, PTGNode p2)
#else
PTGNode PTGMax(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGMax n;
	n = (_PPTGMax)MALLOC(sizeof(struct _SPTGMax));
	n->_print = (_PTGProc)_PrPTGMax;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern Min */

typedef struct _SPTGMin{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGMin;

#ifdef PROTO_OK
static void _PrPTGMin(_PPTGMin n)
#else
static void _PrPTGMin(n)
	_PPTGMin n;
#endif
{
	PTG_OUTPUT_STRING(f, "MIN(");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, ",");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, ")");
}

#ifdef PROTO_OK
PTGNode PTGMin(PTGNode p1, PTGNode p2)
#else
PTGNode PTGMin(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGMin n;
	n = (_PPTGMin)MALLOC(sizeof(struct _SPTGMin));
	n->_print = (_PTGProc)_PrPTGMin;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern Mod */

typedef struct _SPTGMod{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGMod;

#ifdef PROTO_OK
static void _PrPTGMod(_PPTGMod n)
#else
static void _PrPTGMod(n)
	_PPTGMod n;
#endif
{
	PTG_OUTPUT_STRING(f, "(");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, ") % (");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, ")");
}

#ifdef PROTO_OK
PTGNode PTGMod(PTGNode p1, PTGNode p2)
#else
PTGNode PTGMod(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGMod n;
	n = (_PPTGMod)MALLOC(sizeof(struct _SPTGMod));
	n->_print = (_PTGProc)_PrPTGMod;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern MulSequence */

typedef struct _SPTGMulSequence{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGMulSequence;

#ifdef PROTO_OK
static void _PrPTGMulSequence(_PPTGMulSequence n)
#else
static void _PrPTGMulSequence(n)
	_PPTGMulSequence n;
#endif
{
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "*(");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, ")");
}

#ifdef PROTO_OK
PTGNode PTGMulSequence(PTGNode p1, PTGNode p2)
#else
PTGNode PTGMulSequence(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGMulSequence n;
	n = (_PPTGMulSequence)MALLOC(sizeof(struct _SPTGMulSequence));
	n->_print = (_PTGProc)_PrPTGMulSequence;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern Number */

typedef struct _SPTGNumber{
	_PTGProc _print;
	int p1;
} * _PPTGNumber;

#ifdef PROTO_OK
static void _PrPTGNumber(_PPTGNumber n)
#else
static void _PrPTGNumber(n)
	_PPTGNumber n;
#endif
{
	PTG_OUTPUT_INT(f, n->p1);
}

#ifdef PROTO_OK
PTGNode PTGNumber(int p1)
#else
PTGNode PTGNumber(p1)

int p1;
#endif
{
	_PPTGNumber n;
	n = (_PPTGNumber)MALLOC(sizeof(struct _SPTGNumber));
	n->_print = (_PTGProc)_PrPTGNumber;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern Parens */

typedef struct _SPTGParens{
	_PTGProc _print;
	PTGNode p1;
} * _PPTGParens;

#ifdef PROTO_OK
static void _PrPTGParens(_PPTGParens n)
#else
static void _PrPTGParens(n)
	_PPTGParens n;
#endif
{
	PTG_OUTPUT_STRING(f, "(");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, ")");
}

#ifdef PROTO_OK
PTGNode PTGParens(PTGNode p1)
#else
PTGNode PTGParens(p1)

PTGNode p1;
#endif
{
	_PPTGParens n;
	n = (_PPTGParens)MALLOC(sizeof(struct _SPTGParens));
	n->_print = (_PTGProc)_PrPTGParens;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern Pointer */

typedef struct _SPTGPointer{
	_PTGProc _print;
	PTGNode p1;
} * _PPTGPointer;

#ifdef PROTO_OK
static void _PrPTGPointer(_PPTGPointer n)
#else
static void _PrPTGPointer(n)
	_PPTGPointer n;
#endif
{
	PTG_OUTPUT_STRING(f, "*");
	n->p1->_print(n->p1);
}

#ifdef PROTO_OK
PTGNode PTGPointer(PTGNode p1)
#else
PTGNode PTGPointer(p1)

PTGNode p1;
#endif
{
	_PPTGPointer n;
	n = (_PPTGPointer)MALLOC(sizeof(struct _SPTGPointer));
	n->_print = (_PTGProc)_PrPTGPointer;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern PowerExpr */

typedef struct _SPTGPowerExpr{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGPowerExpr;

#ifdef PROTO_OK
static void _PrPTGPowerExpr(_PPTGPowerExpr n)
#else
static void _PrPTGPowerExpr(n)
	_PPTGPowerExpr n;
#endif
{
	PTG_OUTPUT_STRING(f, "powf(");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, ",");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, ")");
}

#ifdef PROTO_OK
PTGNode PTGPowerExpr(PTGNode p1, PTGNode p2)
#else
PTGNode PTGPowerExpr(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGPowerExpr n;
	n = (_PPTGPowerExpr)MALLOC(sizeof(struct _SPTGPowerExpr));
	n->_print = (_PTGProc)_PrPTGPowerExpr;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern ProgramStmt */

typedef struct _SPTGProgramStmt{
	_PTGProc _print;
	PTGNode p1;
} * _PPTGProgramStmt;

#ifdef PROTO_OK
static void _PrPTGProgramStmt(_PPTGProgramStmt n)
#else
static void _PrPTGProgramStmt(n)
	_PPTGProgramStmt n;
#endif
{
	PTG_OUTPUT_STRING(f, "replace ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ");
	PTG_OUTPUT_STRING(f, "int main() {");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGProgramStmt(PTGNode p1)
#else
PTGNode PTGProgramStmt(p1)

PTGNode p1;
#endif
{
	_PPTGProgramStmt n;
	n = (_PPTGProgramStmt)MALLOC(sizeof(struct _SPTGProgramStmt));
	n->_print = (_PTGProc)_PrPTGProgramStmt;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern QuotedString */

typedef struct _SPTGQuotedString{
	_PTGProc _print;
	PTGNode p1;
} * _PPTGQuotedString;

#ifdef PROTO_OK
static void _PrPTGQuotedString(_PPTGQuotedString n)
#else
static void _PrPTGQuotedString(n)
	_PPTGQuotedString n;
#endif
{
	PTG_OUTPUT_STRING(f, "'");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "'");
}

#ifdef PROTO_OK
PTGNode PTGQuotedString(PTGNode p1)
#else
PTGNode PTGQuotedString(p1)

PTGNode p1;
#endif
{
	_PPTGQuotedString n;
	n = (_PPTGQuotedString)MALLOC(sizeof(struct _SPTGQuotedString));
	n->_print = (_PTGProc)_PrPTGQuotedString;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern Remove */

typedef struct _SPTGRemove{
	_PTGProc _print;
	PTGNode p1;
} * _PPTGRemove;

#ifdef PROTO_OK
static void _PrPTGRemove(_PPTGRemove n)
#else
static void _PrPTGRemove(n)
	_PPTGRemove n;
#endif
{
	PTG_OUTPUT_STRING(f, "remove ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGRemove(PTGNode p1)
#else
PTGNode PTGRemove(p1)

PTGNode p1;
#endif
{
	_PPTGRemove n;
	n = (_PPTGRemove)MALLOC(sizeof(struct _SPTGRemove));
	n->_print = (_PTGProc)_PrPTGRemove;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern Replace */

typedef struct _SPTGReplace{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
} * _PPTGReplace;

#ifdef PROTO_OK
static void _PrPTGReplace(_PPTGReplace n)
#else
static void _PrPTGReplace(n)
	_PPTGReplace n;
#endif
{
	PTG_OUTPUT_STRING(f, "replace ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ");
	n->p2->_print(n->p2);
	n->p3->_print(n->p3);
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGReplace(PTGNode p1, PTGNode p2, PTGNode p3)
#else
PTGNode PTGReplace(p1, p2, p3)

PTGNode p1;
PTGNode p2;
PTGNode p3;
#endif
{
	_PPTGReplace n;
	n = (_PPTGReplace)MALLOC(sizeof(struct _SPTGReplace));
	n->_print = (_PTGProc)_PrPTGReplace;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	return (PTGNode)n;
}


/* Implementation of Pattern ReplaceNull */

typedef struct _SPTGReplaceNull{
	_PTGProc _print;
	PTGNode p1;
} * _PPTGReplaceNull;

#ifdef PROTO_OK
static void _PrPTGReplaceNull(_PPTGReplaceNull n)
#else
static void _PrPTGReplaceNull(n)
	_PPTGReplaceNull n;
#endif
{
	PTG_OUTPUT_STRING(f, "replace ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGReplaceNull(PTGNode p1)
#else
PTGNode PTGReplaceNull(p1)

PTGNode p1;
#endif
{
	_PPTGReplaceNull n;
	n = (_PPTGReplaceNull)MALLOC(sizeof(struct _SPTGReplaceNull));
	n->_print = (_PTGProc)_PrPTGReplaceNull;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern ReplaceMaxMin */

typedef struct _SPTGReplaceMaxMin{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
	PTGNode p4;
} * _PPTGReplaceMaxMin;

#ifdef PROTO_OK
static void _PrPTGReplaceMaxMin(_PPTGReplaceMaxMin n)
#else
static void _PrPTGReplaceMaxMin(n)
	_PPTGReplaceMaxMin n;
#endif
{
	PTG_OUTPUT_STRING(f, "replace ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "begin_append ");
	n->p2->_print(n->p2);
	IndentNewLine(f);
	n->p3->_print(n->p3);
	n->p4->_print(n->p4);
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "end_append");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGReplaceMaxMin(PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4)
#else
PTGNode PTGReplaceMaxMin(p1, p2, p3, p4)

PTGNode p1;
PTGNode p2;
PTGNode p3;
PTGNode p4;
#endif
{
	_PPTGReplaceMaxMin n;
	n = (_PPTGReplaceMaxMin)MALLOC(sizeof(struct _SPTGReplaceMaxMin));
	n->_print = (_PTGProc)_PrPTGReplaceMaxMin;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	n->p4 = p4;
	return (PTGNode)n;
}


/* Implementation of Pattern AppendMaxMinStmt */

typedef struct _SPTGAppendMaxMinStmt{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
} * _PPTGAppendMaxMinStmt;

#ifdef PROTO_OK
static void _PrPTGAppendMaxMinStmt(_PPTGAppendMaxMinStmt n)
#else
static void _PrPTGAppendMaxMinStmt(n)
	_PPTGAppendMaxMinStmt n;
#endif
{
	PTG_OUTPUT_STRING(f, "begin_append ");
	n->p1->_print(n->p1);
	IndentNewLine(f);
	n->p2->_print(n->p2);
	IndentNewLine(f);
	n->p3->_print(n->p3);
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "end_append");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGAppendMaxMinStmt(PTGNode p1, PTGNode p2, PTGNode p3)
#else
PTGNode PTGAppendMaxMinStmt(p1, p2, p3)

PTGNode p1;
PTGNode p2;
PTGNode p3;
#endif
{
	_PPTGAppendMaxMinStmt n;
	n = (_PPTGAppendMaxMinStmt)MALLOC(sizeof(struct _SPTGAppendMaxMinStmt));
	n->_print = (_PTGProc)_PrPTGAppendMaxMinStmt;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	return (PTGNode)n;
}


/* Implementation of Pattern GPUReturn */

typedef struct _SPTGGPUReturn{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
	PTGNode p4;
	PTGNode p5;
	PTGNode p6;
} * _PPTGGPUReturn;

#ifdef PROTO_OK
static void _PrPTGGPUReturn(_PPTGGPUReturn n)
#else
static void _PrPTGGPUReturn(n)
	_PPTGGPUReturn n;
#endif
{
	PTG_OUTPUT_STRING(f, "remove ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "begin_append ");
	n->p2->_print(n->p2);
	IndentNewLine(f);
	n->p3->_print(n->p3);
	IndentNewLine(f);
	n->p4->_print(n->p4);
	IndentNewLine(f);
	n->p5->_print(n->p5);
	n->p6->_print(n->p6);
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "end_append");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGGPUReturn(PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5, PTGNode p6)
#else
PTGNode PTGGPUReturn(p1, p2, p3, p4, p5, p6)

PTGNode p1;
PTGNode p2;
PTGNode p3;
PTGNode p4;
PTGNode p5;
PTGNode p6;
#endif
{
	_PPTGGPUReturn n;
	n = (_PPTGGPUReturn)MALLOC(sizeof(struct _SPTGGPUReturn));
	n->_print = (_PTGProc)_PrPTGGPUReturn;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	n->p4 = p4;
	n->p5 = p5;
	n->p6 = p6;
	return (PTGNode)n;
}


/* Implementation of Pattern Return */

typedef struct _SPTGReturn{
	_PTGProc _print;
	PTGNode p1;
} * _PPTGReturn;

#ifdef PROTO_OK
static void _PrPTGReturn(_PPTGReturn n)
#else
static void _PrPTGReturn(n)
	_PPTGReturn n;
#endif
{
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "return;");
}

#ifdef PROTO_OK
PTGNode PTGReturn(PTGNode p1)
#else
PTGNode PTGReturn(p1)

PTGNode p1;
#endif
{
	_PPTGReturn n;
	n = (_PPTGReturn)MALLOC(sizeof(struct _SPTGReturn));
	n->_print = (_PTGProc)_PrPTGReturn;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern ReturnExpr */

typedef struct _SPTGReturnExpr{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGReturnExpr;

#ifdef PROTO_OK
static void _PrPTGReturnExpr(_PPTGReturnExpr n)
#else
static void _PrPTGReturnExpr(n)
	_PPTGReturnExpr n;
#endif
{
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "return(");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, ");");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGReturnExpr(PTGNode p1, PTGNode p2)
#else
PTGNode PTGReturnExpr(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGReturnExpr n;
	n = (_PPTGReturnExpr)MALLOC(sizeof(struct _SPTGReturnExpr));
	n->_print = (_PTGProc)_PrPTGReturnExpr;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern Sequence */

typedef struct _SPTGSequence{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGSequence;

#ifdef PROTO_OK
static void _PrPTGSequence(_PPTGSequence n)
#else
static void _PrPTGSequence(n)
	_PPTGSequence n;
#endif
{
	n->p1->_print(n->p1);
	n->p2->_print(n->p2);
}

#ifdef PROTO_OK
PTGNode PTGSequence(PTGNode p1, PTGNode p2)
#else
PTGNode PTGSequence(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGSequence n;
	if(p1 == PTGNULL && p2 == PTGNULL)
		return PTGNULL;
	n = (_PPTGSequence)MALLOC(sizeof(struct _SPTGSequence));
	n->_print = (_PTGProc)_PrPTGSequence;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern SequenceCR */

typedef struct _SPTGSequenceCR{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGSequenceCR;

#ifdef PROTO_OK
static void _PrPTGSequenceCR(_PPTGSequenceCR n)
#else
static void _PrPTGSequenceCR(n)
	_PPTGSequenceCR n;
#endif
{
	n->p1->_print(n->p1);
	n->p2->_print(n->p2);
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGSequenceCR(PTGNode p1, PTGNode p2)
#else
PTGNode PTGSequenceCR(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGSequenceCR n;
	n = (_PPTGSequenceCR)MALLOC(sizeof(struct _SPTGSequenceCR));
	n->_print = (_PTGProc)_PrPTGSequenceCR;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern SQRmacro */

typedef struct _SPTGSQRmacro{
	_PTGProc _print;
	PTGNode p1;
} * _PPTGSQRmacro;

#ifdef PROTO_OK
static void _PrPTGSQRmacro(_PPTGSQRmacro n)
#else
static void _PrPTGSQRmacro(n)
	_PPTGSQRmacro n;
#endif
{
	PTG_OUTPUT_STRING(f, "SQR(");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, ")");
}

#ifdef PROTO_OK
PTGNode PTGSQRmacro(PTGNode p1)
#else
PTGNode PTGSQRmacro(p1)

PTGNode p1;
#endif
{
	_PPTGSQRmacro n;
	n = (_PPTGSQRmacro)MALLOC(sizeof(struct _SPTGSQRmacro));
	n->_print = (_PTGProc)_PrPTGSQRmacro;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern StmtFunction */

typedef struct _SPTGStmtFunction{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGStmtFunction;

#ifdef PROTO_OK
static void _PrPTGStmtFunction(_PPTGStmtFunction n)
#else
static void _PrPTGStmtFunction(n)
	_PPTGStmtFunction n;
#endif
{
	PTG_OUTPUT_STRING(f, "[");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "]");
	PTG_OUTPUT_STRING(f, " = ");
	n->p2->_print(n->p2);
}

#ifdef PROTO_OK
PTGNode PTGStmtFunction(PTGNode p1, PTGNode p2)
#else
PTGNode PTGStmtFunction(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGStmtFunction n;
	n = (_PPTGStmtFunction)MALLOC(sizeof(struct _SPTGStmtFunction));
	n->_print = (_PTGProc)_PrPTGStmtFunction;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern StrideLoopBounds */

typedef struct _SPTGStrideLoopBounds{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
	PTGNode p4;
	PTGNode p5;
	PTGNode p6;
} * _PPTGStrideLoopBounds;

#ifdef PROTO_OK
static void _PrPTGStrideLoopBounds(_PPTGStrideLoopBounds n)
#else
static void _PrPTGStrideLoopBounds(n)
	_PPTGStrideLoopBounds n;
#endif
{
	PTG_OUTPUT_STRING(f, "(");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "=");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, ";");
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, "<=");
	n->p4->_print(n->p4);
	PTG_OUTPUT_STRING(f, ";");
	n->p5->_print(n->p5);
	PTG_OUTPUT_STRING(f, "+=");
	n->p6->_print(n->p6);
	PTG_OUTPUT_STRING(f, ")");
}

#ifdef PROTO_OK
PTGNode PTGStrideLoopBounds(PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5, PTGNode p6)
#else
PTGNode PTGStrideLoopBounds(p1, p2, p3, p4, p5, p6)

PTGNode p1;
PTGNode p2;
PTGNode p3;
PTGNode p4;
PTGNode p5;
PTGNode p6;
#endif
{
	_PPTGStrideLoopBounds n;
	n = (_PPTGStrideLoopBounds)MALLOC(sizeof(struct _SPTGStrideLoopBounds));
	n->_print = (_PTGProc)_PrPTGStrideLoopBounds;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	n->p4 = p4;
	n->p5 = p5;
	n->p6 = p6;
	return (PTGNode)n;
}


/* Implementation of Pattern StrideNegLoopBounds */

typedef struct _SPTGStrideNegLoopBounds{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
	PTGNode p4;
	PTGNode p5;
	PTGNode p6;
} * _PPTGStrideNegLoopBounds;

#ifdef PROTO_OK
static void _PrPTGStrideNegLoopBounds(_PPTGStrideNegLoopBounds n)
#else
static void _PrPTGStrideNegLoopBounds(n)
	_PPTGStrideNegLoopBounds n;
#endif
{
	PTG_OUTPUT_STRING(f, "(");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "=");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, ";");
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, ">=");
	n->p4->_print(n->p4);
	PTG_OUTPUT_STRING(f, ";");
	n->p5->_print(n->p5);
	PTG_OUTPUT_STRING(f, "+=");
	n->p6->_print(n->p6);
	PTG_OUTPUT_STRING(f, ")");
}

#ifdef PROTO_OK
PTGNode PTGStrideNegLoopBounds(PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5, PTGNode p6)
#else
PTGNode PTGStrideNegLoopBounds(p1, p2, p3, p4, p5, p6)

PTGNode p1;
PTGNode p2;
PTGNode p3;
PTGNode p4;
PTGNode p5;
PTGNode p6;
#endif
{
	_PPTGStrideNegLoopBounds n;
	n = (_PPTGStrideNegLoopBounds)MALLOC(sizeof(struct _SPTGStrideNegLoopBounds));
	n->_print = (_PTGProc)_PrPTGStrideNegLoopBounds;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	n->p4 = p4;
	n->p5 = p5;
	n->p6 = p6;
	return (PTGNode)n;
}


/* Implementation of Pattern String */

typedef struct _SPTGString{
	_PTGProc _print;
	CONST char* p1;
} * _PPTGString;

#ifdef PROTO_OK
static void _PrPTGString(_PPTGString n)
#else
static void _PrPTGString(n)
	_PPTGString n;
#endif
{
	PTG_OUTPUT_STRING(f, n->p1);
}

#ifdef PROTO_OK
PTGNode PTGString(CONST char* p1)
#else
PTGNode PTGString(p1)

CONST char* p1;
#endif
{
	_PPTGString n;
	n = (_PPTGString)MALLOC(sizeof(struct _SPTGString));
	n->_print = (_PTGProc)_PrPTGString;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern SubroutineArg */

typedef struct _SPTGSubroutineArg{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
} * _PPTGSubroutineArg;

#ifdef PROTO_OK
static void _PrPTGSubroutineArg(_PPTGSubroutineArg n)
#else
static void _PrPTGSubroutineArg(n)
	_PPTGSubroutineArg n;
#endif
{
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ");
	n->p2->_print(n->p2);
	n->p3->_print(n->p3);
}

#ifdef PROTO_OK
PTGNode PTGSubroutineArg(PTGNode p1, PTGNode p2, PTGNode p3)
#else
PTGNode PTGSubroutineArg(p1, p2, p3)

PTGNode p1;
PTGNode p2;
PTGNode p3;
#endif
{
	_PPTGSubroutineArg n;
	n = (_PPTGSubroutineArg)MALLOC(sizeof(struct _SPTGSubroutineArg));
	n->_print = (_PTGProc)_PrPTGSubroutineArg;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	return (PTGNode)n;
}


/* Implementation of Pattern SubroutineArgs */

typedef struct _SPTGSubroutineArgs{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
	PTGNode p4;
	PTGNode p5;
	PTGNode p6;
} * _PPTGSubroutineArgs;

#ifdef PROTO_OK
static void _PrPTGSubroutineArgs(_PPTGSubroutineArgs n)
#else
static void _PrPTGSubroutineArgs(n)
	_PPTGSubroutineArgs n;
#endif
{
	PTG_OUTPUT_STRING(f, "replace ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ");
	n->p2->_print(n->p2);
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, " ");
	n->p4->_print(n->p4);
	PTG_OUTPUT_STRING(f, "_Kernel(");
	n->p5->_print(n->p5);
	PTG_OUTPUT_STRING(f, ") {");
	IndentNewLine(f);
	n->p6->_print(n->p6);
}

#ifdef PROTO_OK
PTGNode PTGSubroutineArgs(PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5, PTGNode p6)
#else
PTGNode PTGSubroutineArgs(p1, p2, p3, p4, p5, p6)

PTGNode p1;
PTGNode p2;
PTGNode p3;
PTGNode p4;
PTGNode p5;
PTGNode p6;
#endif
{
	_PPTGSubroutineArgs n;
	n = (_PPTGSubroutineArgs)MALLOC(sizeof(struct _SPTGSubroutineArgs));
	n->_print = (_PTGProc)_PrPTGSubroutineArgs;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	n->p4 = p4;
	n->p5 = p5;
	n->p6 = p6;
	return (PTGNode)n;
}


/* Implementation of Pattern FunctionDecl */

typedef struct _SPTGFunctionDecl{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
} * _PPTGFunctionDecl;

#ifdef PROTO_OK
static void _PrPTGFunctionDecl(_PPTGFunctionDecl n)
#else
static void _PrPTGFunctionDecl(n)
	_PPTGFunctionDecl n;
#endif
{
	PTG_OUTPUT_STRING(f, "begin_append ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "  ");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, " ");
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, ";");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "end_append");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGFunctionDecl(PTGNode p1, PTGNode p2, PTGNode p3)
#else
PTGNode PTGFunctionDecl(p1, p2, p3)

PTGNode p1;
PTGNode p2;
PTGNode p3;
#endif
{
	_PPTGFunctionDecl n;
	n = (_PPTGFunctionDecl)MALLOC(sizeof(struct _SPTGFunctionDecl));
	n->_print = (_PTGProc)_PrPTGFunctionDecl;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	return (PTGNode)n;
}


/* Implementation of Pattern Subroutine_forGPU */

typedef struct _SPTGSubroutine_forGPU{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
	PTGNode p4;
	PTGNode p5;
	PTGNode p6;
} * _PPTGSubroutine_forGPU;

#ifdef PROTO_OK
static void _PrPTGSubroutine_forGPU(_PPTGSubroutine_forGPU n)
#else
static void _PrPTGSubroutine_forGPU(n)
	_PPTGSubroutine_forGPU n;
#endif
{
	PTG_OUTPUT_STRING(f, "begin_append ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ");
	IndentNewLine(f);
	IndentNewLine(f);
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, "extern \"C\" ");
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, " FUNCTION(");
	n->p4->_print(n->p4);
	PTG_OUTPUT_STRING(f, ") ARGS(`");
	n->p5->_print(n->p5);
	PTG_OUTPUT_STRING(f, "') {");
	IndentNewLine(f);
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "  int argc=2;");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "  char *argv[]= {\"\",\"-device=0\"};");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "  CUT_DEVICE_INIT(argc, argv);");
	IndentNewLine(f);
	IndentNewLine(f);
	n->p6->_print(n->p6);
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "end_append");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGSubroutine_forGPU(PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5, PTGNode p6)
#else
PTGNode PTGSubroutine_forGPU(p1, p2, p3, p4, p5, p6)

PTGNode p1;
PTGNode p2;
PTGNode p3;
PTGNode p4;
PTGNode p5;
PTGNode p6;
#endif
{
	_PPTGSubroutine_forGPU n;
	n = (_PPTGSubroutine_forGPU)MALLOC(sizeof(struct _SPTGSubroutine_forGPU));
	n->_print = (_PTGProc)_PrPTGSubroutine_forGPU;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	n->p4 = p4;
	n->p5 = p5;
	n->p6 = p6;
	return (PTGNode)n;
}


/* Implementation of Pattern SubroutineEnd_forGPU */

typedef struct _SPTGSubroutineEnd_forGPU{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGSubroutineEnd_forGPU;

#ifdef PROTO_OK
static void _PrPTGSubroutineEnd_forGPU(_PPTGSubroutineEnd_forGPU n)
#else
static void _PrPTGSubroutineEnd_forGPU(n)
	_PPTGSubroutineEnd_forGPU n;
#endif
{
	PTG_OUTPUT_STRING(f, "begin_append ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "  return");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, ";");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "}");
	IndentNewLine(f);
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "end_append");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGSubroutineEnd_forGPU(PTGNode p1, PTGNode p2)
#else
PTGNode PTGSubroutineEnd_forGPU(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGSubroutineEnd_forGPU n;
	n = (_PPTGSubroutineEnd_forGPU)MALLOC(sizeof(struct _SPTGSubroutineEnd_forGPU));
	n->_print = (_PTGProc)_PrPTGSubroutineEnd_forGPU;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern Subroutine_forCPU */

typedef struct _SPTGSubroutine_forCPU{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
	PTGNode p4;
	PTGNode p5;
	PTGNode p6;
	PTGNode p7;
} * _PPTGSubroutine_forCPU;

#ifdef PROTO_OK
static void _PrPTGSubroutine_forCPU(_PPTGSubroutine_forCPU n)
#else
static void _PrPTGSubroutine_forCPU(n)
	_PPTGSubroutine_forCPU n;
#endif
{
	PTG_OUTPUT_STRING(f, "replace ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ");
	n->p2->_print(n->p2);
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, " FUNCTION(");
	n->p4->_print(n->p4);
	PTG_OUTPUT_STRING(f, ") ARGS(`");
	n->p5->_print(n->p5);
	PTG_OUTPUT_STRING(f, "') {");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "begin_append ");
	n->p6->_print(n->p6);
	PTG_OUTPUT_STRING(f, " ");
	IndentNewLine(f);
	n->p7->_print(n->p7);
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "end_append");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGSubroutine_forCPU(PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5, PTGNode p6, PTGNode p7)
#else
PTGNode PTGSubroutine_forCPU(p1, p2, p3, p4, p5, p6, p7)

PTGNode p1;
PTGNode p2;
PTGNode p3;
PTGNode p4;
PTGNode p5;
PTGNode p6;
PTGNode p7;
#endif
{
	_PPTGSubroutine_forCPU n;
	n = (_PPTGSubroutine_forCPU)MALLOC(sizeof(struct _SPTGSubroutine_forCPU));
	n->_print = (_PTGProc)_PrPTGSubroutine_forCPU;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	n->p4 = p4;
	n->p5 = p5;
	n->p6 = p6;
	n->p7 = p7;
	return (PTGNode)n;
}


/* Implementation of Pattern SubroutineNoArgs_forCPU */

typedef struct _SPTGSubroutineNoArgs_forCPU{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
	PTGNode p4;
	PTGNode p5;
} * _PPTGSubroutineNoArgs_forCPU;

#ifdef PROTO_OK
static void _PrPTGSubroutineNoArgs_forCPU(_PPTGSubroutineNoArgs_forCPU n)
#else
static void _PrPTGSubroutineNoArgs_forCPU(n)
	_PPTGSubroutineNoArgs_forCPU n;
#endif
{
	PTG_OUTPUT_STRING(f, "replace ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ");
	n->p2->_print(n->p2);
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, " FUNCTION(");
	n->p4->_print(n->p4);
	PTG_OUTPUT_STRING(f, ") ARGS(`");
	n->p5->_print(n->p5);
	PTG_OUTPUT_STRING(f, "') {");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGSubroutineNoArgs_forCPU(PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5)
#else
PTGNode PTGSubroutineNoArgs_forCPU(p1, p2, p3, p4, p5)

PTGNode p1;
PTGNode p2;
PTGNode p3;
PTGNode p4;
PTGNode p5;
#endif
{
	_PPTGSubroutineNoArgs_forCPU n;
	n = (_PPTGSubroutineNoArgs_forCPU)MALLOC(sizeof(struct _SPTGSubroutineNoArgs_forCPU));
	n->_print = (_PTGProc)_PrPTGSubroutineNoArgs_forCPU;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	n->p4 = p4;
	n->p5 = p5;
	return (PTGNode)n;
}


/* Implementation of Pattern SubroutineCallNoArgs */

typedef struct _SPTGSubroutineCallNoArgs{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGSubroutineCallNoArgs;

#ifdef PROTO_OK
static void _PrPTGSubroutineCallNoArgs(_PPTGSubroutineCallNoArgs n)
#else
static void _PrPTGSubroutineCallNoArgs(n)
	_PPTGSubroutineCallNoArgs n;
#endif
{
	n->p1->_print(n->p1);
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, "_(");
	PTG_OUTPUT_STRING(f, ");");
}

#ifdef PROTO_OK
PTGNode PTGSubroutineCallNoArgs(PTGNode p1, PTGNode p2)
#else
PTGNode PTGSubroutineCallNoArgs(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGSubroutineCallNoArgs n;
	n = (_PPTGSubroutineCallNoArgs)MALLOC(sizeof(struct _SPTGSubroutineCallNoArgs));
	n->_print = (_PTGProc)_PrPTGSubroutineCallNoArgs;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern SubroutineCall */

typedef struct _SPTGSubroutineCall{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
} * _PPTGSubroutineCall;

#ifdef PROTO_OK
static void _PrPTGSubroutineCall(_PPTGSubroutineCall n)
#else
static void _PrPTGSubroutineCall(n)
	_PPTGSubroutineCall n;
#endif
{
	n->p1->_print(n->p1);
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, "_( ");
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, " );");
}

#ifdef PROTO_OK
PTGNode PTGSubroutineCall(PTGNode p1, PTGNode p2, PTGNode p3)
#else
PTGNode PTGSubroutineCall(p1, p2, p3)

PTGNode p1;
PTGNode p2;
PTGNode p3;
#endif
{
	_PPTGSubroutineCall n;
	n = (_PPTGSubroutineCall)MALLOC(sizeof(struct _SPTGSubroutineCall));
	n->_print = (_PTGProc)_PrPTGSubroutineCall;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	return (PTGNode)n;
}


/* Implementation of Pattern SubroutineDecl */

typedef struct _SPTGSubroutineDecl{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
} * _PPTGSubroutineDecl;

#ifdef PROTO_OK
static void _PrPTGSubroutineDecl(_PPTGSubroutineDecl n)
#else
static void _PrPTGSubroutineDecl(n)
	_PPTGSubroutineDecl n;
#endif
{
	PTG_OUTPUT_STRING(f, "begin_append ");
	n->p1->_print(n->p1);
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "  extern void ");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, "_(");
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, ");");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "end_append");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGSubroutineDecl(PTGNode p1, PTGNode p2, PTGNode p3)
#else
PTGNode PTGSubroutineDecl(p1, p2, p3)

PTGNode p1;
PTGNode p2;
PTGNode p3;
#endif
{
	_PPTGSubroutineDecl n;
	n = (_PPTGSubroutineDecl)MALLOC(sizeof(struct _SPTGSubroutineDecl));
	n->_print = (_PTGProc)_PrPTGSubroutineDecl;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	return (PTGNode)n;
}


/* Implementation of Pattern SubroutineNoArgs_forGPU */

typedef struct _SPTGSubroutineNoArgs_forGPU{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
} * _PPTGSubroutineNoArgs_forGPU;

#ifdef PROTO_OK
static void _PrPTGSubroutineNoArgs_forGPU(_PPTGSubroutineNoArgs_forGPU n)
#else
static void _PrPTGSubroutineNoArgs_forGPU(n)
	_PPTGSubroutineNoArgs_forGPU n;
#endif
{
	PTG_OUTPUT_STRING(f, "replace ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, "void ");
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, "_GPU(");
	PTG_OUTPUT_STRING(f, ") {");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGSubroutineNoArgs_forGPU(PTGNode p1, PTGNode p2, PTGNode p3)
#else
PTGNode PTGSubroutineNoArgs_forGPU(p1, p2, p3)

PTGNode p1;
PTGNode p2;
PTGNode p3;
#endif
{
	_PPTGSubroutineNoArgs_forGPU n;
	n = (_PPTGSubroutineNoArgs_forGPU)MALLOC(sizeof(struct _SPTGSubroutineNoArgs_forGPU));
	n->_print = (_PTGProc)_PrPTGSubroutineNoArgs_forGPU;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	return (PTGNode)n;
}


/* Implementation of Pattern TwoArgs */

typedef struct _SPTGTwoArgs{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGTwoArgs;

#ifdef PROTO_OK
static void _PrPTGTwoArgs(_PPTGTwoArgs n)
#else
static void _PrPTGTwoArgs(n)
	_PPTGTwoArgs n;
#endif
{
	n->p1->_print(n->p1);
	n->p2->_print(n->p2);
}

#ifdef PROTO_OK
PTGNode PTGTwoArgs(PTGNode p1, PTGNode p2)
#else
PTGNode PTGTwoArgs(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGTwoArgs n;
	if(p1 == PTGNULL && p2 == PTGNULL)
		return PTGNULL;
	n = (_PPTGTwoArgs)MALLOC(sizeof(struct _SPTGTwoArgs));
	n->_print = (_PTGProc)_PrPTGTwoArgs;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern ThreeArgs */

typedef struct _SPTGThreeArgs{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
} * _PPTGThreeArgs;

#ifdef PROTO_OK
static void _PrPTGThreeArgs(_PPTGThreeArgs n)
#else
static void _PrPTGThreeArgs(n)
	_PPTGThreeArgs n;
#endif
{
	n->p1->_print(n->p1);
	n->p2->_print(n->p2);
	n->p3->_print(n->p3);
}

#ifdef PROTO_OK
PTGNode PTGThreeArgs(PTGNode p1, PTGNode p2, PTGNode p3)
#else
PTGNode PTGThreeArgs(p1, p2, p3)

PTGNode p1;
PTGNode p2;
PTGNode p3;
#endif
{
	_PPTGThreeArgs n;
	if(p1 == PTGNULL && p2 == PTGNULL && p3 == PTGNULL)
		return PTGNULL;
	n = (_PPTGThreeArgs)MALLOC(sizeof(struct _SPTGThreeArgs));
	n->_print = (_PTGProc)_PrPTGThreeArgs;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	return (PTGNode)n;
}


/* Implementation of Pattern ThreeArgsCR */

typedef struct _SPTGThreeArgsCR{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
} * _PPTGThreeArgsCR;

#ifdef PROTO_OK
static void _PrPTGThreeArgsCR(_PPTGThreeArgsCR n)
#else
static void _PrPTGThreeArgsCR(n)
	_PPTGThreeArgsCR n;
#endif
{
	n->p1->_print(n->p1);
	IndentNewLine(f);
	n->p2->_print(n->p2);
	IndentNewLine(f);
	n->p3->_print(n->p3);
}

#ifdef PROTO_OK
PTGNode PTGThreeArgsCR(PTGNode p1, PTGNode p2, PTGNode p3)
#else
PTGNode PTGThreeArgsCR(p1, p2, p3)

PTGNode p1;
PTGNode p2;
PTGNode p3;
#endif
{
	_PPTGThreeArgsCR n;
	n = (_PPTGThreeArgsCR)MALLOC(sizeof(struct _SPTGThreeArgsCR));
	n->_print = (_PTGProc)_PrPTGThreeArgsCR;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	return (PTGNode)n;
}


/* Implementation of Pattern VariableDecls */

typedef struct _SPTGVariableDecls{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
} * _PPTGVariableDecls;

#ifdef PROTO_OK
static void _PrPTGVariableDecls(_PPTGVariableDecls n)
#else
static void _PrPTGVariableDecls(n)
	_PPTGVariableDecls n;
#endif
{
	n->p1->_print(n->p1);
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, " ");
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, ";");
}

#ifdef PROTO_OK
PTGNode PTGVariableDecls(PTGNode p1, PTGNode p2, PTGNode p3)
#else
PTGNode PTGVariableDecls(p1, p2, p3)

PTGNode p1;
PTGNode p2;
PTGNode p3;
#endif
{
	_PPTGVariableDecls n;
	n = (_PPTGVariableDecls)MALLOC(sizeof(struct _SPTGVariableDecls));
	n->_print = (_PTGProc)_PrPTGVariableDecls;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	return (PTGNode)n;
}


/* Implementation of Pattern Void */

typedef struct _SPTGVoid{
	_PTGProc _print;
} * _PPTGVoid;

#ifdef PROTO_OK
static void _PrPTGVoid(_PPTGVoid n)
#else
static void _PrPTGVoid(n)
	_PPTGVoid n;
#endif
{
	PTG_OUTPUT_STRING(f, "void");
}

static struct _SPTGVoid _sptgVoid = { (_PTGProc) _PrPTGVoid };

#ifdef PROTO_OK
PTGNode PTGVoid(void)
#else
PTGNode PTGVoid()
#endif
{
	return (PTGNode)(&_sptgVoid);
}


/* Implementation of Pattern CommaArgs3 */

typedef struct _SPTGCommaArgs3{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
} * _PPTGCommaArgs3;

#ifdef PROTO_OK
static void _PrPTGCommaArgs3(_PPTGCommaArgs3 n)
#else
static void _PrPTGCommaArgs3(n)
	_PPTGCommaArgs3 n;
#endif
{
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, ",");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, ",");
	n->p3->_print(n->p3);
}

#ifdef PROTO_OK
PTGNode PTGCommaArgs3(PTGNode p1, PTGNode p2, PTGNode p3)
#else
PTGNode PTGCommaArgs3(p1, p2, p3)

PTGNode p1;
PTGNode p2;
PTGNode p3;
#endif
{
	_PPTGCommaArgs3 n;
	n = (_PPTGCommaArgs3)MALLOC(sizeof(struct _SPTGCommaArgs3));
	n->_print = (_PTGProc)_PrPTGCommaArgs3;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	return (PTGNode)n;
}


/* Implementation of Pattern CommaArgs2 */

typedef struct _SPTGCommaArgs2{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGCommaArgs2;

#ifdef PROTO_OK
static void _PrPTGCommaArgs2(_PPTGCommaArgs2 n)
#else
static void _PrPTGCommaArgs2(n)
	_PPTGCommaArgs2 n;
#endif
{
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, ",");
	n->p2->_print(n->p2);
}

#ifdef PROTO_OK
PTGNode PTGCommaArgs2(PTGNode p1, PTGNode p2)
#else
PTGNode PTGCommaArgs2(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGCommaArgs2 n;
	n = (_PPTGCommaArgs2)MALLOC(sizeof(struct _SPTGCommaArgs2));
	n->_print = (_PTGProc)_PrPTGCommaArgs2;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern DeclareVar */

typedef struct _SPTGDeclareVar{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
	PTGNode p4;
	PTGNode p5;
} * _PPTGDeclareVar;

#ifdef PROTO_OK
static void _PrPTGDeclareVar(_PPTGDeclareVar n)
#else
static void _PrPTGDeclareVar(n)
	_PPTGDeclareVar n;
#endif
{
	PTG_OUTPUT_STRING(f, "begin_append ");
	n->p1->_print(n->p1);
	IndentNewLine(f);
	n->p2->_print(n->p2);
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, " ");
	n->p4->_print(n->p4);
	PTG_OUTPUT_STRING(f, " ");
	n->p5->_print(n->p5);
	PTG_OUTPUT_STRING(f, ";");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "end_append");
	IndentNewLine(f);
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGDeclareVar(PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5)
#else
PTGNode PTGDeclareVar(p1, p2, p3, p4, p5)

PTGNode p1;
PTGNode p2;
PTGNode p3;
PTGNode p4;
PTGNode p5;
#endif
{
	_PPTGDeclareVar n;
	n = (_PPTGDeclareVar)MALLOC(sizeof(struct _SPTGDeclareVar));
	n->_print = (_PTGProc)_PrPTGDeclareVar;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	n->p4 = p4;
	n->p5 = p5;
	return (PTGNode)n;
}


/* Implementation of Pattern KernelProgramName */

typedef struct _SPTGKernelProgramName{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGKernelProgramName;

#ifdef PROTO_OK
static void _PrPTGKernelProgramName(_PPTGKernelProgramName n)
#else
static void _PrPTGKernelProgramName(n)
	_PPTGKernelProgramName n;
#endif
{
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "_Kernel");
	n->p2->_print(n->p2);
}

#ifdef PROTO_OK
PTGNode PTGKernelProgramName(PTGNode p1, PTGNode p2)
#else
PTGNode PTGKernelProgramName(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGKernelProgramName n;
	n = (_PPTGKernelProgramName)MALLOC(sizeof(struct _SPTGKernelProgramName));
	n->_print = (_PTGProc)_PrPTGKernelProgramName;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern KernelRoutineCopyEnd */

typedef struct _SPTGKernelRoutineCopyEnd{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGKernelRoutineCopyEnd;

#ifdef PROTO_OK
static void _PrPTGKernelRoutineCopyEnd(_PPTGKernelRoutineCopyEnd n)
#else
static void _PrPTGKernelRoutineCopyEnd(n)
	_PPTGKernelRoutineCopyEnd n;
#endif
{
	PTG_OUTPUT_STRING(f, "begin_append ");
	n->p1->_print(n->p1);
	n->p2->_print(n->p2);
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "end_append");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGKernelRoutineCopyEnd(PTGNode p1, PTGNode p2)
#else
PTGNode PTGKernelRoutineCopyEnd(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGKernelRoutineCopyEnd n;
	n = (_PPTGKernelRoutineCopyEnd)MALLOC(sizeof(struct _SPTGKernelRoutineCopyEnd));
	n->_print = (_PTGProc)_PrPTGKernelRoutineCopyEnd;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern KernelRoutineEnd */

typedef struct _SPTGKernelRoutineEnd{
	_PTGProc _print;
	PTGNode p1;
} * _PPTGKernelRoutineEnd;

#ifdef PROTO_OK
static void _PrPTGKernelRoutineEnd(_PPTGKernelRoutineEnd n)
#else
static void _PrPTGKernelRoutineEnd(n)
	_PPTGKernelRoutineEnd n;
#endif
{
	PTG_OUTPUT_STRING(f, "begin_append ");
	n->p1->_print(n->p1);
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "  return;");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "}");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "end_append");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGKernelRoutineEnd(PTGNode p1)
#else
PTGNode PTGKernelRoutineEnd(p1)

PTGNode p1;
#endif
{
	_PPTGKernelRoutineEnd n;
	n = (_PPTGKernelRoutineEnd)MALLOC(sizeof(struct _SPTGKernelRoutineEnd));
	n->_print = (_PTGProc)_PrPTGKernelRoutineEnd;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern KernelRoutineStart */

typedef struct _SPTGKernelRoutineStart{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
	PTGNode p4;
} * _PPTGKernelRoutineStart;

#ifdef PROTO_OK
static void _PrPTGKernelRoutineStart(_PPTGKernelRoutineStart n)
#else
static void _PrPTGKernelRoutineStart(n)
	_PPTGKernelRoutineStart n;
#endif
{
	PTG_OUTPUT_STRING(f, "begin_append ");
	n->p1->_print(n->p1);
	IndentNewLine(f);
	n->p2->_print(n->p2);
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, "(");
	n->p4->_print(n->p4);
	PTG_OUTPUT_STRING(f, ") {");
	IndentNewLine(f);
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "end_append");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGKernelRoutineStart(PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4)
#else
PTGNode PTGKernelRoutineStart(p1, p2, p3, p4)

PTGNode p1;
PTGNode p2;
PTGNode p3;
PTGNode p4;
#endif
{
	_PPTGKernelRoutineStart n;
	n = (_PPTGKernelRoutineStart)MALLOC(sizeof(struct _SPTGKernelRoutineStart));
	n->_print = (_PTGProc)_PrPTGKernelRoutineStart;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	n->p4 = p4;
	return (PTGNode)n;
}


/* Implementation of Pattern ParensArg */

typedef struct _SPTGParensArg{
	_PTGProc _print;
	PTGNode p1;
} * _PPTGParensArg;

#ifdef PROTO_OK
static void _PrPTGParensArg(_PPTGParensArg n)
#else
static void _PrPTGParensArg(n)
	_PPTGParensArg n;
#endif
{
	PTG_OUTPUT_STRING(f, "(");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, ")");
}

#ifdef PROTO_OK
PTGNode PTGParensArg(PTGNode p1)
#else
PTGNode PTGParensArg(p1)

PTGNode p1;
#endif
{
	_PPTGParensArg n;
	n = (_PPTGParensArg)MALLOC(sizeof(struct _SPTGParensArg));
	n->_print = (_PTGProc)_PrPTGParensArg;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern KernelCall */

typedef struct _SPTGKernelCall{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
	PTGNode p4;
	PTGNode p5;
	PTGNode p6;
	PTGNode p7;
	PTGNode p8;
	PTGNode p9;
	PTGNode p10;
	PTGNode p11;
} * _PPTGKernelCall;

#ifdef PROTO_OK
static void _PrPTGKernelCall(_PPTGKernelCall n)
#else
static void _PrPTGKernelCall(n)
	_PPTGKernelCall n;
#endif
{
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "  dim3 cuda_threads");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "(");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, ");");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "  dim3 cuda_grids");
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, "(");
	n->p4->_print(n->p4);
	PTG_OUTPUT_STRING(f, ");");
	IndentNewLine(f);
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "// create and start timer");
	IndentNewLine(f);
	n->p5->_print(n->p5);
	PTG_OUTPUT_STRING(f, "  cutCreateTimer(&timer);");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "  cutStartTimer(timer);");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "  // setup execution parameters ");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "  // execute the kernel ");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "  ");
	n->p6->_print(n->p6);
	PTG_OUTPUT_STRING(f, "<<< cuda_grids");
	n->p7->_print(n->p7);
	PTG_OUTPUT_STRING(f, ", cuda_threads");
	n->p8->_print(n->p8);
	PTG_OUTPUT_STRING(f, " >>>(");
	n->p9->_print(n->p9);
	PTG_OUTPUT_STRING(f, ");");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "  cudaThreadSynchronize();");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "  // check if kernel execution generated an error");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "  CUT_CHECK_ERROR(\"Kernel execution failed\");");
	IndentNewLine(f);
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "  cutStopTimer(timer);");
	IndentNewLine(f);
	n->p10->_print(n->p10);
	PTG_OUTPUT_STRING(f, "timer__G = cutGetTimerValue(timer);");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "  cutDeleteTimer(timer);");
	IndentNewLine(f);
	PTG_OUTPUT_STRING(f, "  printf(\"");
	n->p11->_print(n->p11);
	PTG_OUTPUT_STRING(f, " execution time: %f \\n\",timer__G);");
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGKernelCall(PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5, PTGNode p6, PTGNode p7, PTGNode p8, PTGNode p9, PTGNode p10, PTGNode p11)
#else
PTGNode PTGKernelCall(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11)

PTGNode p1;
PTGNode p2;
PTGNode p3;
PTGNode p4;
PTGNode p5;
PTGNode p6;
PTGNode p7;
PTGNode p8;
PTGNode p9;
PTGNode p10;
PTGNode p11;
#endif
{
	_PPTGKernelCall n;
	n = (_PPTGKernelCall)MALLOC(sizeof(struct _SPTGKernelCall));
	n->_print = (_PTGProc)_PrPTGKernelCall;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	n->p4 = p4;
	n->p5 = p5;
	n->p6 = p6;
	n->p7 = p7;
	n->p8 = p8;
	n->p9 = p9;
	n->p10 = p10;
	n->p11 = p11;
	return (PTGNode)n;
}


/* Implementation of Pattern KernelCopyArgs */

typedef struct _SPTGKernelCopyArgs{
	_PTGProc _print;
	PTGNode p1;
} * _PPTGKernelCopyArgs;

#ifdef PROTO_OK
static void _PrPTGKernelCopyArgs(_PPTGKernelCopyArgs n)
#else
static void _PrPTGKernelCopyArgs(n)
	_PPTGKernelCopyArgs n;
#endif
{
	n->p1->_print(n->p1);
}

#ifdef PROTO_OK
PTGNode PTGKernelCopyArgs(PTGNode p1)
#else
PTGNode PTGKernelCopyArgs(p1)

PTGNode p1;
#endif
{
	_PPTGKernelCopyArgs n;
	if(p1 == PTGNULL)
		return PTGNULL;
	n = (_PPTGKernelCopyArgs)MALLOC(sizeof(struct _SPTGKernelCopyArgs));
	n->_print = (_PTGProc)_PrPTGKernelCopyArgs;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern KernelCopyArgsIn */

typedef struct _SPTGKernelCopyArgsIn{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGKernelCopyArgsIn;

#ifdef PROTO_OK
static void _PrPTGKernelCopyArgsIn(_PPTGKernelCopyArgsIn n)
#else
static void _PrPTGKernelCopyArgsIn(n)
	_PPTGKernelCopyArgsIn n;
#endif
{
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "timer = 0;");
	IndentNewLine(f);
	n->p2->_print(n->p2);
	IndentNewLine(f);
}

#ifdef PROTO_OK
PTGNode PTGKernelCopyArgsIn(PTGNode p1, PTGNode p2)
#else
PTGNode PTGKernelCopyArgsIn(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGKernelCopyArgsIn n;
	n = (_PPTGKernelCopyArgsIn)MALLOC(sizeof(struct _SPTGKernelCopyArgsIn));
	n->_print = (_PTGProc)_PrPTGKernelCopyArgsIn;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern KernelFreeArgs */

typedef struct _SPTGKernelFreeArgs{
	_PTGProc _print;
	PTGNode p1;
} * _PPTGKernelFreeArgs;

#ifdef PROTO_OK
static void _PrPTGKernelFreeArgs(_PPTGKernelFreeArgs n)
#else
static void _PrPTGKernelFreeArgs(n)
	_PPTGKernelFreeArgs n;
#endif
{
	IndentNewLine(f);
	n->p1->_print(n->p1);
}

#ifdef PROTO_OK
PTGNode PTGKernelFreeArgs(PTGNode p1)
#else
PTGNode PTGKernelFreeArgs(p1)

PTGNode p1;
#endif
{
	_PPTGKernelFreeArgs n;
	n = (_PPTGKernelFreeArgs)MALLOC(sizeof(struct _SPTGKernelFreeArgs));
	n->_print = (_PTGProc)_PrPTGKernelFreeArgs;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern SequenceNL */

typedef struct _SPTGSequenceNL{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGSequenceNL;

#ifdef PROTO_OK
static void _PrPTGSequenceNL(_PPTGSequenceNL n)
#else
static void _PrPTGSequenceNL(n)
	_PPTGSequenceNL n;
#endif
{
	n->p1->_print(n->p1);
	IndentNewLine(f);
	n->p2->_print(n->p2);
}

#ifdef PROTO_OK
PTGNode PTGSequenceNL(PTGNode p1, PTGNode p2)
#else
PTGNode PTGSequenceNL(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGSequenceNL n;
	n = (_PPTGSequenceNL)MALLOC(sizeof(struct _SPTGSequenceNL));
	n->_print = (_PTGProc)_PrPTGSequenceNL;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern TimerDecl */

typedef struct _SPTGTimerDecl{
	_PTGProc _print;
} * _PPTGTimerDecl;

#ifdef PROTO_OK
static void _PrPTGTimerDecl(_PPTGTimerDecl n)
#else
static void _PrPTGTimerDecl(n)
	_PPTGTimerDecl n;
#endif
{
	PTG_OUTPUT_STRING(f, "  unsigned int timer = 0;");
	IndentNewLine(f);
}

static struct _SPTGTimerDecl _sptgTimerDecl = { (_PTGProc) _PrPTGTimerDecl };

#ifdef PROTO_OK
PTGNode PTGTimerDecl(void)
#else
PTGNode PTGTimerDecl()
#endif
{
	return (PTGNode)(&_sptgTimerDecl);
}


/* Implementation of Pattern Id */

typedef struct _SPTGId{
	_PTGProc _print;
	int p1;
} * _PPTGId;

#ifdef PROTO_OK
static void _PrPTGId(_PPTGId n)
#else
static void _PrPTGId(n)
	_PPTGId n;
#endif
{
	PtgOutId(f, n->p1);
}

#ifdef PROTO_OK
PTGNode PTGId(int p1)
#else
PTGNode PTGId(p1)

int p1;
#endif
{
	_PPTGId n;
	n = (_PPTGId)MALLOC(sizeof(struct _SPTGId));
	n->_print = (_PTGProc)_PrPTGId;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern AsIs */

typedef struct _SPTGAsIs{
	_PTGProc _print;
	CONST char* p1;
} * _PPTGAsIs;

#ifdef PROTO_OK
static void _PrPTGAsIs(_PPTGAsIs n)
#else
static void _PrPTGAsIs(n)
	_PPTGAsIs n;
#endif
{
	PTG_OUTPUT_STRING(f, n->p1);
}

#ifdef PROTO_OK
PTGNode PTGAsIs(CONST char* p1)
#else
PTGNode PTGAsIs(p1)

CONST char* p1;
#endif
{
	_PPTGAsIs n;
	n = (_PPTGAsIs)MALLOC(sizeof(struct _SPTGAsIs));
	n->_print = (_PTGProc)_PrPTGAsIs;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern Numb */

typedef struct _SPTGNumb{
	_PTGProc _print;
	int p1;
} * _PPTGNumb;

#ifdef PROTO_OK
static void _PrPTGNumb(_PPTGNumb n)
#else
static void _PrPTGNumb(n)
	_PPTGNumb n;
#endif
{
	PTG_OUTPUT_INT(f, n->p1);
}

#ifdef PROTO_OK
PTGNode PTGNumb(int p1)
#else
PTGNode PTGNumb(p1)

int p1;
#endif
{
	_PPTGNumb n;
	n = (_PPTGNumb)MALLOC(sizeof(struct _SPTGNumb));
	n->_print = (_PTGProc)_PrPTGNumb;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern CString */

typedef struct _SPTGCString{
	_PTGProc _print;
	CONST char* p1;
} * _PPTGCString;

#ifdef PROTO_OK
static void _PrPTGCString(_PPTGCString n)
#else
static void _PrPTGCString(n)
	_PPTGCString n;
#endif
{
	CPtgOutstr(f, n->p1);
}

#ifdef PROTO_OK
PTGNode PTGCString(CONST char* p1)
#else
PTGNode PTGCString(p1)

CONST char* p1;
#endif
{
	_PPTGCString n;
	n = (_PPTGCString)MALLOC(sizeof(struct _SPTGCString));
	n->_print = (_PTGProc)_PrPTGCString;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern CChar */

typedef struct _SPTGCChar{
	_PTGProc _print;
	int p1;
} * _PPTGCChar;

#ifdef PROTO_OK
static void _PrPTGCChar(_PPTGCChar n)
#else
static void _PrPTGCChar(n)
	_PPTGCChar n;
#endif
{
	CPtgOutchar(f, n->p1);
}

#ifdef PROTO_OK
PTGNode PTGCChar(int p1)
#else
PTGNode PTGCChar(p1)

int p1;
#endif
{
	_PPTGCChar n;
	n = (_PPTGCChar)MALLOC(sizeof(struct _SPTGCChar));
	n->_print = (_PTGProc)_PrPTGCChar;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern PString */

typedef struct _SPTGPString{
	_PTGProc _print;
	CONST char* p1;
} * _PPTGPString;

#ifdef PROTO_OK
static void _PrPTGPString(_PPTGPString n)
#else
static void _PrPTGPString(n)
	_PPTGPString n;
#endif
{
	PPtgOutstr(f, n->p1);
}

#ifdef PROTO_OK
PTGNode PTGPString(CONST char* p1)
#else
PTGNode PTGPString(p1)

CONST char* p1;
#endif
{
	_PPTGPString n;
	n = (_PPTGPString)MALLOC(sizeof(struct _SPTGPString));
	n->_print = (_PTGProc)_PrPTGPString;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern Seq */

typedef struct _SPTGSeq{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGSeq;

#ifdef PROTO_OK
static void _PrPTGSeq(_PPTGSeq n)
#else
static void _PrPTGSeq(n)
	_PPTGSeq n;
#endif
{
	n->p1->_print(n->p1);
	n->p2->_print(n->p2);
}

#ifdef PROTO_OK
PTGNode PTGSeq(PTGNode p1, PTGNode p2)
#else
PTGNode PTGSeq(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGSeq n;
	if(p1 == PTGNULL && p2 == PTGNULL)
		return PTGNULL;
	n = (_PPTGSeq)MALLOC(sizeof(struct _SPTGSeq));
	n->_print = (_PTGProc)_PrPTGSeq;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern CommaSeq */

typedef struct _SPTGCommaSeq{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGCommaSeq;

#ifdef PROTO_OK
static void _PrPTGCommaSeq(_PPTGCommaSeq n)
#else
static void _PrPTGCommaSeq(n)
	_PPTGCommaSeq n;
#endif
{
	n->p1->_print(n->p1);
	if (n->p1 != PTGNULL && n->p2 != PTGNULL)
	{
		PTG_OUTPUT_STRING(f, ", ");
	}
	n->p2->_print(n->p2);
}

#ifdef PROTO_OK
PTGNode PTGCommaSeq(PTGNode p1, PTGNode p2)
#else
PTGNode PTGCommaSeq(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGCommaSeq n;
	if(p1 == PTGNULL && p2 == PTGNULL)
		return PTGNULL;
	n = (_PPTGCommaSeq)MALLOC(sizeof(struct _SPTGCommaSeq));
	n->_print = (_PTGProc)_PrPTGCommaSeq;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern Eol */

typedef struct _SPTGEol{
	_PTGProc _print;
	PTGNode p1;
} * _PPTGEol;

#ifdef PROTO_OK
static void _PrPTGEol(_PPTGEol n)
#else
static void _PrPTGEol(n)
	_PPTGEol n;
#endif
{
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "\n");
}

#ifdef PROTO_OK
PTGNode PTGEol(PTGNode p1)
#else
PTGNode PTGEol(p1)

PTGNode p1;
#endif
{
	_PPTGEol n;
	n = (_PPTGEol)MALLOC(sizeof(struct _SPTGEol));
	n->_print = (_PTGProc)_PrPTGEol;
	n->p1 = p1;
	return (PTGNode)n;
}

/* ============================ */

/* -------------------------------------------------------- */
/*                  Default Output Functions                */
/* -------------------------------------------------------- */


#ifdef PROTO_OK
void _PTGPrintInt(PTG_OUTPUT_FILE file, int param)
#else
void _PTGPrintInt(file, param)
       PTG_OUTPUT_FILE file; int param;
#endif
{    /* used for short and int */
       sprintf(buffer,"%d",param);
       PTG_OUTPUT_STRING(file,buffer);
}

#ifdef PROTO_OK
void _PTGPrintLong(PTG_OUTPUT_FILE file, long param)
#else
void _PTGPrintLong(file, param)
       PTG_OUTPUT_FILE file; long param;
#endif
{
       sprintf(buffer,"%ld",param);
       PTG_OUTPUT_STRING(file,buffer);
}

#ifdef PROTO_OK
void _PTGPrintDouble(PTG_OUTPUT_FILE file, double param)
#else
void _PTGPrintDouble(file, param)
       PTG_OUTPUT_FILE file; double param;
#endif
{    /* used for float and double */
       sprintf(buffer,"%g",param);
       PTG_OUTPUT_STRING(file,buffer);
}

#ifdef PROTO_OK
void _PTGPrintChar(PTG_OUTPUT_FILE file, char param)
#else
void _PTGPrintChar(file, param)
       PTG_OUTPUT_FILE file; char param;
#endif
{
       buffer[0] = param;
       buffer[1] = 0;
       PTG_OUTPUT_STRING(file,buffer);
}

