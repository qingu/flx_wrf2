SHELL   = /bin/sh

CC	= gcc

OBJS	= driver.o attrmain.o visitprocs.o envmod.o BitSet.o \
	obstack.o err.o CoordMap.o source.o deftbl.o obsave.o clp.o \
	VoidPtrList.o clpintf.o pdl_gen.o csm.o clplib.o \
	GPU_Directives.o ptg_gen.o PtgCommon.o F2Cindent.o Indent.o \
	AlgScope.o IntSet.o f77symbols.o CoordPtrList.o \
	UnitAlgScope.o visitmap.o visitprocs8.o Strings.o \
	get_type.o Bounds.o BoundsList.o MakeName.o idn.o \
	visitprocs1.o visitprocs2.o visitprocs3.o visitprocs4.o \
	visitprocs5.o visitprocs6.o ModuleFileName.o visitprocs7.o \
	visitprocs9.o treestack.o treecon.o nodecode.o PreDefMod.o \
	SrcFileStack.o parser.o scan.o Include.o CmdLineIncl.o \
	glahead.o dflteot.o tabsize.o auxEOF.o str.o pgs_gen.o

EXE	= F2C-ACC.exe

all:	$(EXE)

$(EXE):	$(OBJS)
	$(CC) -o $(EXE) $(CFLAGS) $(OBJS) $(LIBS)

objects: $(OBJS)

clean:
	rm -f a.out *.o *.a *~ core ERRS $(EXE)

tidy:
	rm -f core a.out *.o *~ *.a ERRS

driver.o:	driver.c err.h HEAD.h dapto.h dapto_dapto.h INIT.h FINL.h \
		eliproto.h clp.h f77symbols.h csm.h CmdLineIncl.h Bounds.h \
		get_type.h GPU_Directives.h Indent.h SrcFileStack.h \
		MakeName.h Strings.h PreDefMod.h UnitAlgScope.h AlgScope.h \
		IntSet.h CoordPtrList.h envmod.h CoordCmp.h BoundsList.h \
		ptg_gen.h pdl_gen.h treecon.h BitSet.h DefTableKeyList.h \
		VoidPtrList.h deftbl.h CoordMap.h PtgCommon.h clplib.h \
		f77expr.h strmath.h termcode.h myParams.h \
		BoundsFunctionTypes.h ptg.h obstack.h VoidPtr.h \
		VoidPtrFunctionTypes.h CoordPtrFunctionTypes.h nodeptr.h

attrmain.o:	attrmain.c treestack.h visitprocs.h nodeptr.h HEAD.h node.h \
		treecon.h eliproto.h clp.h f77symbols.h csm.h CmdLineIncl.h \
		Bounds.h get_type.h GPU_Directives.h Indent.h \
		SrcFileStack.h MakeName.h Strings.h PreDefMod.h \
		UnitAlgScope.h err.h AlgScope.h IntSet.h CoordPtrList.h \
		envmod.h CoordCmp.h BoundsList.h ptg_gen.h pdl_gen.h \
		BitSet.h DefTableKeyList.h VoidPtrList.h deftbl.h \
		CoordMap.h PtgCommon.h clplib.h f77expr.h strmath.h \
		termcode.h myParams.h BoundsFunctionTypes.h ptg.h obstack.h \
		VoidPtr.h VoidPtrFunctionTypes.h CoordPtrFunctionTypes.h

visitprocs.o:	visitprocs.c HEAD.h err.h node.h visitprocs.h attrpredef.h \
		visitmap.h clp.h f77symbols.h csm.h CmdLineIncl.h Bounds.h \
		get_type.h GPU_Directives.h Indent.h SrcFileStack.h \
		MakeName.h Strings.h PreDefMod.h UnitAlgScope.h AlgScope.h \
		IntSet.h CoordPtrList.h envmod.h CoordCmp.h BoundsList.h \
		ptg_gen.h pdl_gen.h treecon.h BitSet.h DefTableKeyList.h \
		VoidPtrList.h deftbl.h CoordMap.h PtgCommon.h clplib.h \
		eliproto.h f77expr.h strmath.h termcode.h myParams.h \
		BoundsFunctionTypes.h ptg.h obstack.h VoidPtr.h \
		VoidPtrFunctionTypes.h CoordPtrFunctionTypes.h nodeptr.h

envmod.o:	envmod.c err.h obstack.h envmod.h obsave.h envmod_dapto.h \
		eliproto.h deftbl.h BitSet.h dapto.h

BitSet.o:	BitSet.c obstack.h err.h BitSet.h eliproto.h

obstack.o:	obstack.c config.h obstack.h gettext.h

err.o:	err.c err.h source.h CoordMap.h dapto_dapto.h err_dapto.h \
		eliproto.h dapto.h

CoordMap.o:	CoordMap.c obstack.h source.h csm.h err.h CoordMap.h \
		eliproto.h

source.o:	source.c source.h dapto_dapto.h dapto.h eliproto.h

deftbl.o:	deftbl.c err.h deftbl.h obstack.h obsave.h eliproto.h

obsave.o:	obsave.c obsave.h obstack.h eliproto.h

clp.o:	clp.c clp.h clpintf.h pdl_gen.h csm.h eliproto.h clplib.h \
		DefTableKeyList.h deftbl.h f77expr.h strmath.h termcode.h \
		BoundsList.h ptg_gen.h envmod.h IntSet.h err.h CoordCmp.h \
		myParams.h BoundsFunctionTypes.h ptg.h obstack.h BitSet.h \
		VoidPtrList.h VoidPtr.h VoidPtrFunctionTypes.h

VoidPtrList.o:	VoidPtrList.c VoidPtrList.h err.h obstack.h VoidPtr.h \
		VoidPtrFunctionTypes.h eliproto.h

clpintf.o:	clpintf.c clp.h clpintf.h csm.h eliproto.h pdl_gen.h \
		source.h clplib.h DefTableKeyList.h deftbl.h f77expr.h \
		strmath.h termcode.h BoundsList.h ptg_gen.h envmod.h \
		IntSet.h err.h CoordCmp.h myParams.h BoundsFunctionTypes.h \
		ptg.h obstack.h BitSet.h VoidPtrList.h VoidPtr.h \
		VoidPtrFunctionTypes.h

pdl_gen.o:	pdl_gen.c pdl_gen.h deftbl.h f77expr.h strmath.h termcode.h \
		BoundsList.h ptg_gen.h envmod.h IntSet.h err.h CoordCmp.h \
		eliproto.h myParams.h BoundsFunctionTypes.h ptg.h obstack.h \
		BitSet.h

csm.o:	csm.c csm.h csmtbl.h dapto_dapto.h csm_dapto.h obsave.h \
		obstack.h eliproto.h dapto.h

clplib.o:	clplib.c csm.h clplib.h obstack.h eliproto.h

GPU_Directives.o:	GPU_Directives.c GPU_Directives.h pdl_gen.h csm.h clp.h \
		err.h deftbl.h eliproto.h f77expr.h strmath.h termcode.h \
		BoundsList.h ptg_gen.h envmod.h IntSet.h CoordCmp.h \
		myParams.h BoundsFunctionTypes.h ptg.h obstack.h BitSet.h \
		clplib.h DefTableKeyList.h VoidPtrList.h VoidPtr.h \
		VoidPtrFunctionTypes.h

ptg_gen.o:	ptg_gen.c ptg_gen.h obstack.h eliproto.h ptg.h

PtgCommon.o:	PtgCommon.c PtgCommon.h eliproto.h ptg_gen.h csm.h ptg.h \
		obstack.h

F2Cindent.o:	F2Cindent.c 

Indent.o:	Indent.c Indent.h ptg_gen.h eliproto.h ptg.h

AlgScope.o:	AlgScope.c AlgScope.h envmod.h deftbl.h obstack.h BitSet.h \
		eliproto.h

IntSet.o:	IntSet.c err.h IntSet.h eliproto.h

f77symbols.o:	f77symbols.c err.h csm.h pdl_gen.h f77symbols.h \
		CoordPtrList.h eliproto.h obstack.h deftbl.h f77expr.h \
		strmath.h termcode.h BoundsList.h ptg_gen.h envmod.h \
		IntSet.h CoordCmp.h myParams.h BoundsFunctionTypes.h ptg.h \
		BitSet.h CoordPtrFunctionTypes.h

CoordPtrList.o:	CoordPtrList.c CoordPtrList.h err.h obstack.h \
		CoordPtrFunctionTypes.h eliproto.h

UnitAlgScope.o:	UnitAlgScope.c UnitAlgScope.h envmod.h deftbl.h obstack.h \
		BitSet.h eliproto.h

visitmap.o:	visitmap.c visitprocs.h visitmap.h HEAD.h node.h treecon.h \
		eliproto.h clp.h f77symbols.h csm.h CmdLineIncl.h Bounds.h \
		get_type.h GPU_Directives.h Indent.h SrcFileStack.h \
		MakeName.h Strings.h PreDefMod.h UnitAlgScope.h err.h \
		AlgScope.h IntSet.h CoordPtrList.h envmod.h CoordCmp.h \
		BoundsList.h ptg_gen.h pdl_gen.h BitSet.h DefTableKeyList.h \
		VoidPtrList.h deftbl.h CoordMap.h PtgCommon.h clplib.h \
		f77expr.h strmath.h termcode.h myParams.h \
		BoundsFunctionTypes.h ptg.h obstack.h VoidPtr.h \
		VoidPtrFunctionTypes.h CoordPtrFunctionTypes.h nodeptr.h

visitprocs8.o:	visitprocs8.c HEAD.h err.h node.h visitprocs.h attrpredef.h \
		visitmap.h clp.h f77symbols.h csm.h CmdLineIncl.h Bounds.h \
		get_type.h GPU_Directives.h Indent.h SrcFileStack.h \
		MakeName.h Strings.h PreDefMod.h UnitAlgScope.h AlgScope.h \
		IntSet.h CoordPtrList.h envmod.h CoordCmp.h BoundsList.h \
		ptg_gen.h pdl_gen.h treecon.h BitSet.h DefTableKeyList.h \
		VoidPtrList.h deftbl.h CoordMap.h PtgCommon.h clplib.h \
		eliproto.h f77expr.h strmath.h termcode.h myParams.h \
		BoundsFunctionTypes.h ptg.h obstack.h VoidPtr.h \
		VoidPtrFunctionTypes.h CoordPtrFunctionTypes.h nodeptr.h

Strings.o:	Strings.c Strings.h csm.h obstack.h eliproto.h

get_type.o:	get_type.c deftbl.h ptg_gen.h clp.h csm.h err.h Bounds.h \
		ppp.h CoordMap.h eliproto.h ptg.h clplib.h pdl_gen.h \
		DefTableKeyList.h f77expr.h strmath.h termcode.h \
		BoundsList.h envmod.h IntSet.h CoordCmp.h myParams.h \
		BoundsFunctionTypes.h obstack.h BitSet.h VoidPtrList.h \
		VoidPtr.h VoidPtrFunctionTypes.h

Bounds.o:	Bounds.c BoundsList.h ptg_gen.h csm.h deftbl.h pdl_gen.h \
		myParams.h BoundsFunctionTypes.h eliproto.h ptg.h obstack.h \
		f77expr.h strmath.h termcode.h envmod.h IntSet.h err.h \
		CoordCmp.h BitSet.h

BoundsList.o:	BoundsList.c BoundsList.h err.h obstack.h myParams.h \
		BoundsFunctionTypes.h eliproto.h

MakeName.o:	MakeName.c err.h csm.h idn.h termcode.h MakeName.h \
		eliproto.h obstack.h

idn.o:	idn.c err.h idn.h csm.h obstack.h obsave.h idntbl.h \
		eliproto.h

visitprocs1.o:	visitprocs1.c HEAD.h err.h node.h visitprocs.h attrpredef.h \
		visitmap.h clp.h f77symbols.h csm.h CmdLineIncl.h Bounds.h \
		get_type.h GPU_Directives.h Indent.h SrcFileStack.h \
		MakeName.h Strings.h PreDefMod.h UnitAlgScope.h AlgScope.h \
		IntSet.h CoordPtrList.h envmod.h CoordCmp.h BoundsList.h \
		ptg_gen.h pdl_gen.h treecon.h BitSet.h DefTableKeyList.h \
		VoidPtrList.h deftbl.h CoordMap.h PtgCommon.h clplib.h \
		eliproto.h f77expr.h strmath.h termcode.h myParams.h \
		BoundsFunctionTypes.h ptg.h obstack.h VoidPtr.h \
		VoidPtrFunctionTypes.h CoordPtrFunctionTypes.h nodeptr.h

visitprocs2.o:	visitprocs2.c HEAD.h err.h node.h visitprocs.h attrpredef.h \
		visitmap.h clp.h f77symbols.h csm.h CmdLineIncl.h Bounds.h \
		get_type.h GPU_Directives.h Indent.h SrcFileStack.h \
		MakeName.h Strings.h PreDefMod.h UnitAlgScope.h AlgScope.h \
		IntSet.h CoordPtrList.h envmod.h CoordCmp.h BoundsList.h \
		ptg_gen.h pdl_gen.h treecon.h BitSet.h DefTableKeyList.h \
		VoidPtrList.h deftbl.h CoordMap.h PtgCommon.h clplib.h \
		eliproto.h f77expr.h strmath.h termcode.h myParams.h \
		BoundsFunctionTypes.h ptg.h obstack.h VoidPtr.h \
		VoidPtrFunctionTypes.h CoordPtrFunctionTypes.h nodeptr.h

visitprocs3.o:	visitprocs3.c HEAD.h err.h node.h visitprocs.h attrpredef.h \
		visitmap.h clp.h f77symbols.h csm.h CmdLineIncl.h Bounds.h \
		get_type.h GPU_Directives.h Indent.h SrcFileStack.h \
		MakeName.h Strings.h PreDefMod.h UnitAlgScope.h AlgScope.h \
		IntSet.h CoordPtrList.h envmod.h CoordCmp.h BoundsList.h \
		ptg_gen.h pdl_gen.h treecon.h BitSet.h DefTableKeyList.h \
		VoidPtrList.h deftbl.h CoordMap.h PtgCommon.h clplib.h \
		eliproto.h f77expr.h strmath.h termcode.h myParams.h \
		BoundsFunctionTypes.h ptg.h obstack.h VoidPtr.h \
		VoidPtrFunctionTypes.h CoordPtrFunctionTypes.h nodeptr.h

visitprocs4.o:	visitprocs4.c HEAD.h err.h node.h visitprocs.h attrpredef.h \
		visitmap.h clp.h f77symbols.h csm.h CmdLineIncl.h Bounds.h \
		get_type.h GPU_Directives.h Indent.h SrcFileStack.h \
		MakeName.h Strings.h PreDefMod.h UnitAlgScope.h AlgScope.h \
		IntSet.h CoordPtrList.h envmod.h CoordCmp.h BoundsList.h \
		ptg_gen.h pdl_gen.h treecon.h BitSet.h DefTableKeyList.h \
		VoidPtrList.h deftbl.h CoordMap.h PtgCommon.h clplib.h \
		eliproto.h f77expr.h strmath.h termcode.h myParams.h \
		BoundsFunctionTypes.h ptg.h obstack.h VoidPtr.h \
		VoidPtrFunctionTypes.h CoordPtrFunctionTypes.h nodeptr.h

visitprocs5.o:	visitprocs5.c HEAD.h err.h node.h visitprocs.h attrpredef.h \
		visitmap.h clp.h f77symbols.h csm.h CmdLineIncl.h Bounds.h \
		get_type.h GPU_Directives.h Indent.h SrcFileStack.h \
		MakeName.h Strings.h PreDefMod.h UnitAlgScope.h AlgScope.h \
		IntSet.h CoordPtrList.h envmod.h CoordCmp.h BoundsList.h \
		ptg_gen.h pdl_gen.h treecon.h BitSet.h DefTableKeyList.h \
		VoidPtrList.h deftbl.h CoordMap.h PtgCommon.h clplib.h \
		eliproto.h f77expr.h strmath.h termcode.h myParams.h \
		BoundsFunctionTypes.h ptg.h obstack.h VoidPtr.h \
		VoidPtrFunctionTypes.h CoordPtrFunctionTypes.h nodeptr.h

visitprocs6.o:	visitprocs6.c HEAD.h err.h node.h visitprocs.h attrpredef.h \
		visitmap.h clp.h f77symbols.h csm.h CmdLineIncl.h Bounds.h \
		get_type.h GPU_Directives.h Indent.h SrcFileStack.h \
		MakeName.h Strings.h PreDefMod.h UnitAlgScope.h AlgScope.h \
		IntSet.h CoordPtrList.h envmod.h CoordCmp.h BoundsList.h \
		ptg_gen.h pdl_gen.h treecon.h BitSet.h DefTableKeyList.h \
		VoidPtrList.h deftbl.h CoordMap.h PtgCommon.h clplib.h \
		eliproto.h f77expr.h strmath.h termcode.h myParams.h \
		BoundsFunctionTypes.h ptg.h obstack.h VoidPtr.h \
		VoidPtrFunctionTypes.h CoordPtrFunctionTypes.h nodeptr.h

ModuleFileName.o:	ModuleFileName.c 

visitprocs7.o:	visitprocs7.c HEAD.h err.h node.h visitprocs.h attrpredef.h \
		visitmap.h clp.h f77symbols.h csm.h CmdLineIncl.h Bounds.h \
		get_type.h GPU_Directives.h Indent.h SrcFileStack.h \
		MakeName.h Strings.h PreDefMod.h UnitAlgScope.h AlgScope.h \
		IntSet.h CoordPtrList.h envmod.h CoordCmp.h BoundsList.h \
		ptg_gen.h pdl_gen.h treecon.h BitSet.h DefTableKeyList.h \
		VoidPtrList.h deftbl.h CoordMap.h PtgCommon.h clplib.h \
		eliproto.h f77expr.h strmath.h termcode.h myParams.h \
		BoundsFunctionTypes.h ptg.h obstack.h VoidPtr.h \
		VoidPtrFunctionTypes.h CoordPtrFunctionTypes.h nodeptr.h

visitprocs9.o:	visitprocs9.c HEAD.h err.h node.h visitprocs.h attrpredef.h \
		visitmap.h clp.h f77symbols.h csm.h CmdLineIncl.h Bounds.h \
		get_type.h GPU_Directives.h Indent.h SrcFileStack.h \
		MakeName.h Strings.h PreDefMod.h UnitAlgScope.h AlgScope.h \
		IntSet.h CoordPtrList.h envmod.h CoordCmp.h BoundsList.h \
		ptg_gen.h pdl_gen.h treecon.h BitSet.h DefTableKeyList.h \
		VoidPtrList.h deftbl.h CoordMap.h PtgCommon.h clplib.h \
		eliproto.h f77expr.h strmath.h termcode.h myParams.h \
		BoundsFunctionTypes.h ptg.h obstack.h VoidPtr.h \
		VoidPtrFunctionTypes.h CoordPtrFunctionTypes.h nodeptr.h

treestack.o:	treestack.c err.h treestack.h eliproto.h nodeptr.h

treecon.o:	treecon.c node.h nodecode.h attrpredef.h visitmap.h \
		treeact.h obstack.h err.h nodeptr.h HEAD.h eliproto.h clp.h \
		f77symbols.h csm.h CmdLineIncl.h Bounds.h get_type.h \
		GPU_Directives.h Indent.h SrcFileStack.h MakeName.h \
		Strings.h PreDefMod.h UnitAlgScope.h AlgScope.h IntSet.h \
		CoordPtrList.h envmod.h CoordCmp.h BoundsList.h ptg_gen.h \
		pdl_gen.h treecon.h BitSet.h DefTableKeyList.h \
		VoidPtrList.h deftbl.h CoordMap.h PtgCommon.h clplib.h \
		f77expr.h strmath.h termcode.h myParams.h \
		BoundsFunctionTypes.h ptg.h VoidPtr.h \
		VoidPtrFunctionTypes.h CoordPtrFunctionTypes.h

nodecode.o:	nodecode.c nodecode.h

PreDefMod.o:	PreDefMod.c idn.h PreDefMod.h eliproto.h envmod.h deftbl.h \
		obstack.h BitSet.h

SrcFileStack.o:	SrcFileStack.c obstack.h

parser.o:	parser.c err.h gla.h gsdescr.h reparatur.h dapto_dapto.h \
		pgs_gen.h eliproto.h parsops.h dapto.h

scan.o:	scan.c eliproto.h Include.h clp.h CmdLineIncl.h err.h \
		source.h obstack.h csm.h idn.h gla.h termcode.h litcode.h \
		tabsize.h ppp.h CoordMap.h keywds.h clplib.h pdl_gen.h \
		DefTableKeyList.h deftbl.h f77expr.h strmath.h BoundsList.h \
		ptg_gen.h envmod.h IntSet.h CoordCmp.h myParams.h \
		BoundsFunctionTypes.h ptg.h BitSet.h VoidPtrList.h \
		VoidPtr.h VoidPtrFunctionTypes.h

Include.o:	Include.c err.h SrcFileStack.h CoordMap.h Include.h \
		eliproto.h obstack.h source.h

CmdLineIncl.o:	CmdLineIncl.c csm.h obstack.h clp.h CmdLineIncl.h \
		eliproto.h clplib.h pdl_gen.h DefTableKeyList.h deftbl.h \
		f77expr.h strmath.h termcode.h BoundsList.h ptg_gen.h \
		envmod.h IntSet.h err.h CoordCmp.h myParams.h \
		BoundsFunctionTypes.h ptg.h BitSet.h VoidPtrList.h \
		VoidPtr.h VoidPtrFunctionTypes.h

glahead.o:	glahead.c err.h csm.h source.h obstack.h scanops.h \
		tabsize.h ScanProc.h gla.h dapto_dapto.h xtables.h xcode.h \
		eliproto.h dapto.h

dflteot.o:	dflteot.c 

tabsize.o:	tabsize.c 

auxEOF.o:	auxEOF.c 

str.o:	str.c csm.h obstack.h eliproto.h

pgs_gen.o:	pgs_gen.c gsdescr.h treestack.h HEAD.h err.h parsops.h \
		eliproto.h nodeptr.h clp.h f77symbols.h csm.h CmdLineIncl.h \
		Bounds.h get_type.h GPU_Directives.h Indent.h \
		SrcFileStack.h MakeName.h Strings.h PreDefMod.h \
		UnitAlgScope.h AlgScope.h IntSet.h CoordPtrList.h envmod.h \
		CoordCmp.h BoundsList.h ptg_gen.h pdl_gen.h treecon.h \
		BitSet.h DefTableKeyList.h VoidPtrList.h deftbl.h \
		CoordMap.h PtgCommon.h clplib.h f77expr.h strmath.h \
		termcode.h myParams.h BoundsFunctionTypes.h ptg.h obstack.h \
		VoidPtr.h VoidPtrFunctionTypes.h CoordPtrFunctionTypes.h

