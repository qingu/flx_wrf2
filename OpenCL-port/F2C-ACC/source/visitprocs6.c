
#include "HEAD.h"
#include "err.h"
#include "node.h"
#include "visitprocs.h"
#include "attrpredef.h"

#include "visitmap.h"

#ifdef MONITOR
#include "attr_mon_dapto.h"
#include "liga_dapto.h"
#endif

#ifndef _VisitVarDecl
#define _VisitVarDecl()
#endif

#ifndef _VisitEntry
#define _VisitEntry()
#endif

#ifndef _VisitExit
#define _VisitExit()
#endif


#if defined(__STDC__) || defined(__cplusplus)
#define _CALL_VS_(args) (void (*)args)
#else
#define _CALL_VS_(args) 
#endif
extern int* _IG_incl42;
extern int* _IG_incl40;
extern PTGNode* _IG_incl37;
extern int* _IG_incl36;
extern int* _IG_incl35;
extern BoundsList* _IG_incl34;
extern int* _IG_incl33;
extern int* _IG_incl32;
extern DefTableKey* _IG_incl31;
extern int* _IG_incl29;
extern int* _IG_incl28;
extern int* _IG_incl27;
extern int* _IG_incl26;
extern int* _IG_incl23;
extern int* _IG_incl22;
extern KindSetElement* _IG_incl19;
extern Environment* _IG_incl10;
extern DefTableKey* _IG_incl14;
extern Environment* _IG_incl11;
extern PTGNode* _IG_incl6;
extern PTGNode* _IG_incl9;
extern PTGNode* _IG_incl8;
extern PTGNode* _IG_incl7;
extern PTGNode* _IG_incl5;
extern int* _IG_incl4;
extern int* _IG_incl3;
extern int* _IG_incl2;
extern int* _IG_incl0;

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_832(_TPPrule_832 _currn)
#else
void _VS1rule_832(_currn )
_TPPrule_832 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_AT_const42=ZERO();
/*SPC(3900)*/
_currn->_ATOrder_post=_currn->_ATOrder_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_832(_TPPrule_832 _currn)
#else
void _VS2rule_832(_currn )
_TPPrule_832 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATLastNonExecLine_post=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_ATArgCnt_pre;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_ATIsArray_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_832(_TPPrule_832 _currn)
#else
void _VS3rule_832(_currn )
_TPPrule_832 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_AT_const44=ZERO();
/*SPC(3900)*/
_currn->_AT_cBoundsListPtr_post=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_ATTypeLength_pre;
/*SPC(0)*/
_currn->_ATParameterAttr=1;
/*SPC(3901)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_832(_TPPrule_832 _currn)
#else
void _VS4rule_832(_currn )
_TPPrule_832 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_AT_const43=ZERO();
/*SPC(3900)*/
_currn->_ATDoAcc_post=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_ATArrayId_pre;
/*SPC(0)*/
_currn->_ATExternAttr=PTGNULL;
/*SPC(3889)*/
_currn->_ATPtg=PTGAsIs("F2C-ACC: xAttrSpec not supported.");
/*SPC(3886)*/
_currn->_ATAllocatableAttr=0;
/*SPC(3751)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_833(_TPPrule_833 _currn)
#else
void _VS1rule_833(_currn )
_TPPrule_833 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_AT_const42=ZERO();
/*SPC(3897)*/
_currn->_ATOrder_post=_currn->_ATOrder_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_833(_TPPrule_833 _currn)
#else
void _VS2rule_833(_currn )
_TPPrule_833 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATLastNonExecLine_post=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_ATArgCnt_pre;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_ATIsArray_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_833(_TPPrule_833 _currn)
#else
void _VS3rule_833(_currn )
_TPPrule_833 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_AT_const44=ZERO();
/*SPC(3897)*/
_currn->_AT_cBoundsListPtr_post=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_ATTypeLength_pre;
/*SPC(0)*/
_currn->_ATParameterAttr=0;
/*SPC(3695)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_833(_TPPrule_833 _currn)
#else
void _VS4rule_833(_currn )
_TPPrule_833 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_AT_const43=ZERO();
/*SPC(3897)*/
_currn->_ATDoAcc_post=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_ATArrayId_pre;
/*SPC(0)*/
_currn->_ATExternAttr=PTGNULL;
/*SPC(3889)*/
_currn->_ATPtg=PTGAsIs("F2C-ACC: xAttrSpec not supported.");
/*SPC(3886)*/
_currn->_ATAllocatableAttr=0;
/*SPC(3751)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_834(_TPPrule_834 _currn)
#else
void _VS1rule_834(_currn )
_TPPrule_834 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_AT_const42=ZERO();
/*SPC(3894)*/
_currn->_ATOrder_post=_currn->_ATOrder_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_834(_TPPrule_834 _currn)
#else
void _VS2rule_834(_currn )
_TPPrule_834 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATLastNonExecLine_post=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_ATArgCnt_pre;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_ATIsArray_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_834(_TPPrule_834 _currn)
#else
void _VS3rule_834(_currn )
_TPPrule_834 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_AT_const44=ZERO();
/*SPC(3894)*/
_currn->_AT_cBoundsListPtr_post=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_ATTypeLength_pre;
/*SPC(0)*/
_currn->_ATParameterAttr=0;
/*SPC(3695)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_834(_TPPrule_834 _currn)
#else
void _VS4rule_834(_currn )
_TPPrule_834 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_AT_const43=ZERO();
/*SPC(3894)*/
_currn->_ATDoAcc_post=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_ATArrayId_pre;
/*SPC(0)*/
_currn->_ATExternAttr=PTGNULL;
/*SPC(3889)*/
_currn->_ATPtg=PTGAsIs("F2C-ACC: xAttrSpec not supported.");
/*SPC(3886)*/
_currn->_ATAllocatableAttr=0;
/*SPC(3751)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_835(_TPPrule_835 _currn)
#else
void _VS1rule_835(_currn )
_TPPrule_835 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_AT_const42=ZERO();
/*SPC(3890)*/
_currn->_ATOrder_post=_currn->_ATOrder_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_835(_TPPrule_835 _currn)
#else
void _VS2rule_835(_currn )
_TPPrule_835 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATLastNonExecLine_post=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_ATArgCnt_pre;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_ATIsArray_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_835(_TPPrule_835 _currn)
#else
void _VS3rule_835(_currn )
_TPPrule_835 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_AT_const44=ZERO();
/*SPC(3890)*/
_currn->_AT_cBoundsListPtr_post=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_ATTypeLength_pre;
/*SPC(0)*/
_currn->_ATParameterAttr=0;
/*SPC(3695)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_835(_TPPrule_835 _currn)
#else
void _VS4rule_835(_currn )
_TPPrule_835 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_AT_const43=ZERO();
/*SPC(3890)*/
_currn->_ATDoAcc_post=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_ATArrayId_pre;
/*SPC(0)*/
_currn->_ATExternAttr=PTGAsIs("extern ");
/*SPC(3891)*/
_currn->_ATPtg=PTGAsIs("F2C-ACC: xAttrSpec not supported.");
/*SPC(3886)*/
_currn->_ATAllocatableAttr=0;
/*SPC(3751)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_836(_TPPrule_836 _currn)
#else
void _VS1rule_836(_currn )
_TPPrule_836 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATOrder_pre=_currn->_desc1->_ATOrder_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_AT_const42=ADD(_currn->_desc1->_AT_const42, _currn->_desc2->_AT_const42);
/*SPC(3883)*/
_currn->_ATOrder_post=_currn->_desc2->_ATOrder_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_836(_TPPrule_836 _currn)
#else
void _VS2rule_836(_currn )
_TPPrule_836 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
_currn->_desc1->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATLastNonExecLine_pre=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_desc2->_ATArgCnt_pre=_currn->_desc1->_ATArgCnt_post;
/*SPC(0)*/
_currn->_desc2->_ATIsArray_pre=_currn->_desc1->_ATIsArray_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATLastNonExecLine_post=_currn->_desc2->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc2->_ATArgCnt_post;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_desc2->_ATIsArray_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_836(_TPPrule_836 _currn)
#else
void _VS3rule_836(_currn )
_TPPrule_836 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_AT_cBoundsListPtr_pre=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_desc2->_ATTypeLength_pre=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_AT_const39=ADD(_currn->_desc1->_AT_const39, IDENTICAL(_currn->_desc2->_ATParameterAttr));
/*SPC(3883)*/
_currn->_AT_const44=MAX(_currn->_desc1->_AT_const44, _currn->_desc2->_AT_const44);
/*SPC(3883)*/
_currn->_AT_cBoundsListPtr_post=_currn->_desc2->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_desc2->_ATTypeLength_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_836(_TPPrule_836 _currn)
#else
void _VS4rule_836(_currn )
_TPPrule_836 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_desc1->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATDoAcc_pre=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_desc2->_ATStmtNumber_pre=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATUpdate_pre=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_desc2->_ATAccDoLoopDim_pre=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_desc2->_ATNestLevel_pre=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_desc2->_ATCPURegionNumber_pre=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATAccRegionNumber_pre=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATAcceleratorRegion_pre=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_desc2->_ATIndentLevel_pre=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_desc2->_ATLocalIndex_pre=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_desc2->_ATArrayId_pre=_currn->_desc1->_ATArrayId_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_AT_const40=ADD(_currn->_desc1->_AT_const40, IDENTICAL(_currn->_desc2->_ATAllocatableAttr));
/*SPC(3883)*/
_currn->_AT_const41=PTGSequence(_currn->_desc1->_AT_const41, IDENTICAL(_currn->_desc2->_ATExternAttr));
/*SPC(3883)*/
_currn->_AT_const43=ADD(_currn->_desc1->_AT_const43, _currn->_desc2->_AT_const43);
/*SPC(3883)*/
_currn->_ATDoAcc_post=_currn->_desc2->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc2->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc2->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc2->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc2->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc2->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc2->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc2->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc2->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc2->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc2->_ATArrayId_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_837(_TPPrule_837 _currn)
#else
void _VS1rule_837(_currn )
_TPPrule_837 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_const42=_currn->_desc1->_AT_const42;
/*SPC(3880)*/
_currn->_ATOrder_post=_currn->_desc1->_ATOrder_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_837(_TPPrule_837 _currn)
#else
void _VS2rule_837(_currn )
_TPPrule_837 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
_currn->_desc1->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATLastNonExecLine_post=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc1->_ATArgCnt_post;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_desc1->_ATIsArray_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_837(_TPPrule_837 _currn)
#else
void _VS3rule_837(_currn )
_TPPrule_837 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_const39=IDENTICAL(_currn->_desc1->_ATParameterAttr);
/*SPC(3880)*/
_currn->_AT_const44=_currn->_desc1->_AT_const44;
/*SPC(3880)*/
_currn->_AT_cBoundsListPtr_post=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_837(_TPPrule_837 _currn)
#else
void _VS4rule_837(_currn )
_TPPrule_837 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_desc1->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_const40=IDENTICAL(_currn->_desc1->_ATAllocatableAttr);
/*SPC(3880)*/
_currn->_AT_const41=IDENTICAL(_currn->_desc1->_ATExternAttr);
/*SPC(3880)*/
_currn->_AT_const43=_currn->_desc1->_AT_const43;
/*SPC(3880)*/
_currn->_ATDoAcc_post=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc1->_ATArrayId_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_838(_TPPrule_838 _currn)
#else
void _VS1rule_838(_currn )
_TPPrule_838 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATOrder_pre=_currn->_desc1->_ATOrder_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATOrder_post=_currn->_desc2->_ATOrder_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_838(_TPPrule_838 _currn)
#else
void _VS2rule_838(_currn )
_TPPrule_838 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATLastNonExecLine_pre=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_desc2->_ATArgCnt_pre=_currn->_desc1->_ATArgCnt_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATLastNonExecLine_post=_currn->_desc2->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc2->_ATArgCnt_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_838(_TPPrule_838 _currn)
#else
void _VS3rule_838(_currn )
_TPPrule_838 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_desc1->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
_currn->_desc1->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_desc2->_AT_cBoundsListPtr_pre=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_desc2->_ATDoAcc_pre=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_desc2->_ATStmtNumber_pre=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATUpdate_pre=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_desc2->_ATAccDoLoopDim_pre=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_desc2->_ATNestLevel_pre=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_desc2->_ATCPURegionNumber_pre=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATAccRegionNumber_pre=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATAcceleratorRegion_pre=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_desc2->_ATIndentLevel_pre=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_desc2->_ATLocalIndex_pre=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_desc2->_ATArrayId_pre=_currn->_desc1->_ATArrayId_post;
/*SPC(0)*/
_currn->_desc2->_ATIsArray_pre=_currn->_desc1->_ATIsArray_post;
/*SPC(0)*/
_currn->_desc2->_ATTypeLength_pre=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_AT_const46=PTGSequence(_currn->_desc1->_AT_const46, PTGSequence(_currn->_desc2->_AT_const46, IDENTICAL(_currn->_desc2->_ATPtg)));
/*SPC(3876)*/
_currn->_AT_cBoundsListPtr_post=_currn->_desc2->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_ATDoAcc_post=_currn->_desc2->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc2->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc2->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc2->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc2->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc2->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc2->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc2->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc2->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc2->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc2->_ATArrayId_post;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_desc2->_ATIsArray_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_desc2->_ATTypeLength_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_839(_TPPrule_839 _currn)
#else
void _VS1rule_839(_currn )
_TPPrule_839 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATOrder_post=_currn->_desc1->_ATOrder_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_839(_TPPrule_839 _currn)
#else
void _VS2rule_839(_currn )
_TPPrule_839 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATLastNonExecLine_post=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc1->_ATArgCnt_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_839(_TPPrule_839 _currn)
#else
void _VS3rule_839(_currn )
_TPPrule_839 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_desc1->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
_currn->_desc1->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_const46=PTGSequence(_currn->_desc1->_AT_const46, IDENTICAL(_currn->_desc1->_ATPtg));
/*SPC(3873)*/
_currn->_AT_cBoundsListPtr_post=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_ATDoAcc_post=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc1->_ATArrayId_post;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_desc1->_ATIsArray_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_840(_TPPrule_840 _currn)
#else
void _VS1rule_840(_currn )
_TPPrule_840 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATOrder_post=_currn->_desc1->_ATOrder_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_840(_TPPrule_840 _currn)
#else
void _VS2rule_840(_currn )
_TPPrule_840 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATLastNonExecLine_post=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc1->_ATArgCnt_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_840(_TPPrule_840 _currn)
#else
void _VS3rule_840(_currn )
_TPPrule_840 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_840(_TPPrule_840 _currn)
#else
void _VS4rule_840(_currn )
_TPPrule_840 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_desc1->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
_currn->_desc1->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_const46=PTGSequence(_currn->_desc1->_AT_const46, IDENTICAL(_currn->_desc1->_ATPtg));
/*SPC(3837)*/
_currn->_AT_cBoundsListPtr_post=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_ATDoAcc_post=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc1->_ATArrayId_post;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_desc1->_ATIsArray_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_841(_TPPrule_841 _currn)
#else
void _VS1rule_841(_currn )
_TPPrule_841 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATOrder_pre=_currn->_desc1->_ATOrder_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATOrder_post=_currn->_desc2->_ATOrder_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_841(_TPPrule_841 _currn)
#else
void _VS2rule_841(_currn )
_TPPrule_841 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATLastNonExecLine_pre=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_desc2->_ATArgCnt_pre=_currn->_desc1->_ATArgCnt_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATLastNonExecLine_post=_currn->_desc2->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc2->_ATArgCnt_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_841(_TPPrule_841 _currn)
#else
void _VS3rule_841(_currn )
_TPPrule_841 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_841(_TPPrule_841 _currn)
#else
void _VS4rule_841(_currn )
_TPPrule_841 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_desc1->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
_currn->_desc1->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_AT_cBoundsListPtr_pre=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_desc2->_ATDoAcc_pre=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_desc2->_ATStmtNumber_pre=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATUpdate_pre=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_desc2->_ATAccDoLoopDim_pre=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_desc2->_ATNestLevel_pre=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_desc2->_ATCPURegionNumber_pre=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATAccRegionNumber_pre=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATAcceleratorRegion_pre=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_desc2->_ATIndentLevel_pre=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_desc2->_ATLocalIndex_pre=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_desc2->_ATArrayId_pre=_currn->_desc1->_ATArrayId_post;
/*SPC(0)*/
_currn->_desc2->_ATIsArray_pre=_currn->_desc1->_ATIsArray_post;
/*SPC(0)*/
_currn->_desc2->_ATTypeLength_pre=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_AT_const46=PTGSequence(_currn->_desc1->_AT_const46, _currn->_desc2->_AT_const46);
/*SPC(3821)*/
_currn->_AT_cBoundsListPtr_post=_currn->_desc2->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_ATDoAcc_post=_currn->_desc2->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc2->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc2->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc2->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc2->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc2->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc2->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc2->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc2->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc2->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc2->_ATArrayId_post;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_desc2->_ATIsArray_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_desc2->_ATTypeLength_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_842(_TPPrule_842 _currn)
#else
void _VS1rule_842(_currn )
_TPPrule_842 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATOrder_post=_currn->_desc1->_ATOrder_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_842(_TPPrule_842 _currn)
#else
void _VS2rule_842(_currn )
_TPPrule_842 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATLastNonExecLine_post=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc1->_ATArgCnt_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_842(_TPPrule_842 _currn)
#else
void _VS3rule_842(_currn )
_TPPrule_842 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_842(_TPPrule_842 _currn)
#else
void _VS4rule_842(_currn )
_TPPrule_842 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_desc1->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
_currn->_desc1->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_const46=_currn->_desc1->_AT_const46;
/*SPC(3818)*/
_currn->_AT_cBoundsListPtr_post=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_ATDoAcc_post=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc1->_ATArrayId_post;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_desc1->_ATIsArray_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_843(_TPPrule_843 _currn)
#else
void _VS1rule_843(_currn )
_TPPrule_843 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATOrder_post=_currn->_ATOrder_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_843(_TPPrule_843 _currn)
#else
void _VS2rule_843(_currn )
_TPPrule_843 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATLastNonExecLine_post=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_ATArgCnt_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_843(_TPPrule_843 _currn)
#else
void _VS3rule_843(_currn )
_TPPrule_843 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATIsArray_post=_currn->_ATIsArray_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_843(_TPPrule_843 _currn)
#else
void _VS4rule_843(_currn )
_TPPrule_843 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATDoAcc_post=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_ATArrayId_pre;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_ATTypeLength_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_844(_TPPrule_844 _currn)
#else
void _VS1rule_844(_currn )
_TPPrule_844 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATOrder_pre=_currn->_desc1->_ATOrder_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATOrder_post=_currn->_desc2->_ATOrder_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_844(_TPPrule_844 _currn)
#else
void _VS2rule_844(_currn )
_TPPrule_844 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATLastNonExecLine_pre=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_desc2->_ATArgCnt_pre=_currn->_desc1->_ATArgCnt_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATLastNonExecLine_post=_currn->_desc2->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc2->_ATArgCnt_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_844(_TPPrule_844 _currn)
#else
void _VS3rule_844(_currn )
_TPPrule_844 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATIsArray_pre=_currn->_desc1->_ATIsArray_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATIsArray_post=_currn->_desc2->_ATIsArray_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_844(_TPPrule_844 _currn)
#else
void _VS4rule_844(_currn )
_TPPrule_844 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_desc1->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATDoAcc_pre=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_desc2->_ATStmtNumber_pre=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATUpdate_pre=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_desc2->_ATAccDoLoopDim_pre=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_desc2->_ATNestLevel_pre=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_desc2->_ATCPURegionNumber_pre=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATAccRegionNumber_pre=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATAcceleratorRegion_pre=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_desc2->_ATIndentLevel_pre=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_desc2->_ATLocalIndex_pre=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_desc2->_ATArrayId_pre=_currn->_desc1->_ATArrayId_post;
/*SPC(0)*/
_currn->_desc2->_ATTypeLength_pre=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_AT_cBoundsListPtr_post=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_ATDoAcc_post=_currn->_desc2->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc2->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc2->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc2->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc2->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc2->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc2->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc2->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc2->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc2->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc2->_ATArrayId_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_desc2->_ATTypeLength_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_845(_TPPrule_845 _currn)
#else
void _VS1rule_845(_currn )
_TPPrule_845 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATOrder_post=_currn->_desc1->_ATOrder_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_845(_TPPrule_845 _currn)
#else
void _VS2rule_845(_currn )
_TPPrule_845 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATLastNonExecLine_post=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc1->_ATArgCnt_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_845(_TPPrule_845 _currn)
#else
void _VS3rule_845(_currn )
_TPPrule_845 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATIsArray_post=_currn->_desc1->_ATIsArray_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_845(_TPPrule_845 _currn)
#else
void _VS4rule_845(_currn )
_TPPrule_845 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_desc1->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_cBoundsListPtr_post=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_ATDoAcc_post=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc1->_ATArrayId_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_846(_TPPrule_846 _currn)
#else
void _VS1rule_846(_currn )
_TPPrule_846 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATOrder_post=_currn->_desc2->_ATOrder_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_846(_TPPrule_846 _currn)
#else
void _VS2rule_846(_currn )
_TPPrule_846 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATExecutable=0;
/*SPC(998)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATTypeLength_pre=0;
/*SPC(3558)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATLastNonExecLine_pre=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_desc2->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATLastNonExecLine_post=_currn->_desc2->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc2->_ATArgCnt_post;
/*SPC(0)*/
_currn->_ATIsArray_post=0;
/*SPC(6291)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_846(_TPPrule_846 _currn)
#else
void _VS3rule_846(_currn )
_TPPrule_846 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc2->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5rule_846(_TPPrule_846 _currn)
#else
void _VS5rule_846(_currn )
_TPPrule_846 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_AT_BoundsauxList=NULLBoundsList;
/*SPC(11354)*/
_currn->_desc1->_AT_cBoundsListPtr_pre=_BoundsListADDROF(_currn->_AT_BoundsauxList);
/*SPC(11355)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATLocalIndex_pre=0;
/*SPC(6408)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_const19=PTGNull();
/*SPC(3787)*/
_currn->_AT_const20=PTGNull();
/*SPC(3787)*/
_currn->_AT_const21=PTGNull();
/*SPC(3787)*/
_currn->_AT_const26=ZERO();
/*SPC(3787)*/
_currn->_AT_const27=PTGNull();
/*SPC(3787)*/
_currn->_AT_const28=PTGNull();
/*SPC(3787)*/
_currn->_AT_const29=PTGNull();
/*SPC(3787)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS6rule_846(_TPPrule_846 _currn)
#else
void _VS6rule_846(_currn )
_TPPrule_846 _currn;

#endif
{
int* _IL_incl23;

_VisitVarDecl()
_VisitEntry();
_IL_incl23=_IG_incl23;_IG_incl23= &(_currn->_ATAllocateStmt);
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS6MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS7MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=0;
/*SPC(10694)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS8MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATAllocateStmt=0;
/*SPC(3800)*/
_currn->_desc2->_AT_cBoundsListPtr_pre=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_desc2->_ATDoAcc_pre=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_desc2->_ATStmtNumber_pre=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATUpdate_pre=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_desc2->_ATAccDoLoopDim_pre=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_desc2->_ATNestLevel_pre=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_desc2->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc2->_ATAccRegionNumber_pre=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc2->_ATIndentLevel_pre=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_desc2->_ATLocalIndex_pre=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_desc2->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
_currn->_desc2->_ATTypeLength_pre=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_AT_cBoundsListPtr_post=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_ATAccDoType_post=_currn->_ATAccDoType_pre;
/*SPC(0)*/
_currn->_ATAccDoStmt_post=_currn->_ATAccDoStmt_pre;
/*SPC(0)*/
_currn->_ATKernelNumber_post=_currn->_ATKernelNumber_pre;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc2->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATArrayId_post=NoKey;
/*SPC(6295)*/
_currn->_ATCount_post=_currn->_ATCount_pre;
/*SPC(0)*/
_currn->_ATPtg=PTGNULL;
/*SPC(9695)*/
_currn->_ATMaxRank_post=_currn->_ATMaxRank_pre;
/*SPC(0)*/
_currn->_ATBoundsList=_currn->_AT_BoundsauxList;
/*SPC(11356)*/
_currn->_ATDoAcc_post=_currn->_desc2->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=ADD(_currn->_desc2->_ATStmtNumber_post, 1);
/*SPC(10742)*/
_currn->_ATUpdate_post=_currn->_desc2->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=
((AND(EQ(ZERO(), 0), GE(GetAccNest(_currn->_desc2->_ATDoAcc_post, 2, _currn->_desc2->_ATNestLevel_post, 0), 1))
) ? (0
) : (_currn->_desc2->_ATAccDoLoopDim_post))
;
/*SPC(10553)*/
_currn->_ATNestLevel_post=_currn->_desc2->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc2->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc2->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc2->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc2->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_desc2->_ATTypeLength_post;
/*SPC(0)*/
_IG_incl23=_IL_incl23;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_847(_TPPrule_847 _currn)
#else
void _VS1rule_847(_currn )
_TPPrule_847 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATOrder_post=_currn->_desc2->_ATOrder_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_847(_TPPrule_847 _currn)
#else
void _VS2rule_847(_currn )
_TPPrule_847 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATExecutable=0;
/*SPC(998)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATTypeLength_pre=0;
/*SPC(3558)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATLastNonExecLine_pre=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_desc2->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATLastNonExecLine_post=_currn->_desc2->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc2->_ATArgCnt_post;
/*SPC(0)*/
_currn->_ATIsArray_post=0;
/*SPC(6291)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_847(_TPPrule_847 _currn)
#else
void _VS3rule_847(_currn )
_TPPrule_847 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc2->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5rule_847(_TPPrule_847 _currn)
#else
void _VS5rule_847(_currn )
_TPPrule_847 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_AT_BoundsauxList=NULLBoundsList;
/*SPC(11354)*/
_currn->_desc1->_AT_cBoundsListPtr_pre=_BoundsListADDROF(_currn->_AT_BoundsauxList);
/*SPC(11355)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATLocalIndex_pre=0;
/*SPC(6408)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_const19=PTGNull();
/*SPC(3785)*/
_currn->_AT_const20=PTGNull();
/*SPC(3785)*/
_currn->_AT_const21=PTGNull();
/*SPC(3785)*/
_currn->_AT_const26=ZERO();
/*SPC(3785)*/
_currn->_AT_const27=PTGNull();
/*SPC(3785)*/
_currn->_AT_const28=PTGNull();
/*SPC(3785)*/
_currn->_AT_const29=PTGNull();
/*SPC(3785)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS6rule_847(_TPPrule_847 _currn)
#else
void _VS6rule_847(_currn )
_TPPrule_847 _currn;

#endif
{
int* _IL_incl23;

_VisitVarDecl()
_VisitEntry();
_IL_incl23=_IG_incl23;_IG_incl23= &(_currn->_ATAllocateStmt);
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS6MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS7MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=0;
/*SPC(10694)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS8MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATAllocateStmt=0;
/*SPC(3800)*/
_currn->_desc2->_AT_cBoundsListPtr_pre=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_desc2->_ATDoAcc_pre=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_desc2->_ATStmtNumber_pre=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATUpdate_pre=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_desc2->_ATAccDoLoopDim_pre=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_desc2->_ATNestLevel_pre=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_desc2->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc2->_ATAccRegionNumber_pre=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc2->_ATIndentLevel_pre=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_desc2->_ATLocalIndex_pre=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_desc2->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
_currn->_desc2->_ATTypeLength_pre=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_AT_cBoundsListPtr_post=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_ATAccDoType_post=_currn->_ATAccDoType_pre;
/*SPC(0)*/
_currn->_ATAccDoStmt_post=_currn->_ATAccDoStmt_pre;
/*SPC(0)*/
_currn->_ATKernelNumber_post=_currn->_ATKernelNumber_pre;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc2->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATArrayId_post=NoKey;
/*SPC(6295)*/
_currn->_ATCount_post=_currn->_ATCount_pre;
/*SPC(0)*/
_currn->_ATPtg=PTGNULL;
/*SPC(9695)*/
_currn->_ATMaxRank_post=_currn->_ATMaxRank_pre;
/*SPC(0)*/
_currn->_ATBoundsList=_currn->_AT_BoundsauxList;
/*SPC(11356)*/
_currn->_ATDoAcc_post=_currn->_desc2->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=ADD(_currn->_desc2->_ATStmtNumber_post, 1);
/*SPC(10742)*/
_currn->_ATUpdate_post=_currn->_desc2->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=
((AND(EQ(ZERO(), 0), GE(GetAccNest(_currn->_desc2->_ATDoAcc_post, 2, _currn->_desc2->_ATNestLevel_post, 0), 1))
) ? (0
) : (_currn->_desc2->_ATAccDoLoopDim_post))
;
/*SPC(10553)*/
_currn->_ATNestLevel_post=_currn->_desc2->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc2->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc2->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc2->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc2->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_desc2->_ATTypeLength_post;
/*SPC(0)*/
_IG_incl23=_IL_incl23;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_848(_TPPrule_848 _currn)
#else
void _VS1rule_848(_currn )
_TPPrule_848 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_AT_const42=ZERO();
/*SPC(3752)*/
_currn->_ATOrder_post=_currn->_ATOrder_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_848(_TPPrule_848 _currn)
#else
void _VS2rule_848(_currn )
_TPPrule_848 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATLastNonExecLine_post=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_ATArgCnt_pre;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_ATIsArray_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_848(_TPPrule_848 _currn)
#else
void _VS3rule_848(_currn )
_TPPrule_848 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_AT_const44=ZERO();
/*SPC(3752)*/
_currn->_AT_cBoundsListPtr_post=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_ATTypeLength_pre;
/*SPC(0)*/
_currn->_ATParameterAttr=0;
/*SPC(3695)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_848(_TPPrule_848 _currn)
#else
void _VS4rule_848(_currn )
_TPPrule_848 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_AT_const43=ZERO();
/*SPC(3752)*/
_currn->_ATDoAcc_post=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_ATArrayId_pre;
/*SPC(0)*/
_currn->_ATExternAttr=PTGNULL;
/*SPC(3889)*/
_currn->_ATPtg=PTGAsIs("F2C-ACC: xAttrSpec not supported.");
/*SPC(3886)*/
_currn->_ATAllocatableAttr=1;
/*SPC(3753)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_849(_TPPrule_849 _currn)
#else
void _VS1rule_849(_currn )
_TPPrule_849 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATUnitBind=BindIdn((* _IG_incl11), _currn->_ATSym);
/*SPC(11047)*/
_currn->_ATUnitKey=KeyOf(_currn->_ATUnitBind);
/*SPC(11049)*/

if (EQ(GetType(_currn->_ATUnitKey, NoKey), NoKey)) {
ResetType(_currn->_ATUnitKey, ParameterType(_currn->_ATSym, (&( _currn->_AT_pos))));

} else {
}
;
/*SPC(2043)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_849(_TPPrule_849 _currn)
#else
void _VS2rule_849(_currn )
_TPPrule_849 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
GuaranteeType(_currn->_ATUnitKey, DefaultType(_currn->_ATSym));
/*SPC(873)*/
_currn->_ATBind=BindIdn((* _IG_incl10), _currn->_ATSym);
/*SPC(11183)*/
_currn->_ATKey=KeyOf(_currn->_ATBind);
/*SPC(11185)*/
_currn->_ATCoord=(&( _currn->_AT_pos));
/*SPC(2251)*/
_currn->_ATObjectKey=
((_currn->_ATKey
) ? (_currn->_ATKey
) : (_currn->_ATUnitKey))
;
/*SPC(2155)*/

if (EQ(strcmp(MapFile(((_currn->_AT_pos).line)), StringTable(GetClpValue(FileName, 0))), 0)) {
ResetVariableDeclared(_currn->_ATObjectKey, 1);

} else {

if (GE(isModule(((_currn->_AT_pos).line)), 1)) {
ResetVariableDeclared(_currn->_ATObjectKey, 3);

} else {
;
}
;
}
;
/*SPC(3945)*/
_currn->_ATPtg=PTGString(StringTable(_currn->_ATTERM_1));
/*SPC(3691)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_850(_TPPrule_850 _currn)
#else
void _VS1rule_850(_currn )
_TPPrule_850 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATOrder_post=_currn->_desc2->_ATOrder_post;
/*SPC(0)*/
InsertKindSet(_currn->_desc1->_ATUnitKey, Constant);
/*SPC(2612)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_850(_TPPrule_850 _currn)
#else
void _VS2rule_850(_currn )
_TPPrule_850 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc2->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATLastNonExecLine_post=_currn->_desc2->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc2->_ATArgCnt_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_850(_TPPrule_850 _currn)
#else
void _VS3rule_850(_currn )
_TPPrule_850 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc2->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_desc2->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_desc2->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS6MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_desc2->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS7MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
(*(_CALL_VS_((NODEPTR )) (VS8MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_AT_cBoundsListPtr_post=_currn->_desc2->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc2->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_desc2->_ATIsArray_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_desc2->_ATTypeLength_post;
/*SPC(0)*/
ResetVariableConstant(_currn->_desc1->_ATObjectKey, 1);
/*SPC(10911)*/
ResetVariableConstantValue(_currn->_desc1->_ATObjectKey, _currn->_desc2->_ATPtg);
/*SPC(10909)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_850(_TPPrule_850 _currn)
#else
void _VS4rule_850(_currn )
_TPPrule_850 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc2->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc2->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc2->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS9MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_desc2->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc2->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc2->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc2->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc2->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc2->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc2->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS10MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATDoAcc_post=_currn->_desc2->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc2->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc2->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc2->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc2->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc2->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc2->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc2->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc2->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc2->_ATArrayId_post;
/*SPC(0)*/
_currn->_ATIsConstant=1;
/*SPC(10908)*/
_currn->_ATDefinePtg=PTGDefineConstantCR(_currn->_desc1->_ATPtg, _currn->_desc2->_ATPtg);
/*SPC(3686)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_851(_TPPrule_851 _currn)
#else
void _VS1rule_851(_currn )
_TPPrule_851 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATOrder_pre=_currn->_desc1->_ATOrder_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATOrder_post=_currn->_desc2->_ATOrder_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_851(_TPPrule_851 _currn)
#else
void _VS2rule_851(_currn )
_TPPrule_851 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATLastNonExecLine_pre=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_desc2->_ATArgCnt_pre=_currn->_desc1->_ATArgCnt_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATLastNonExecLine_post=_currn->_desc2->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc2->_ATArgCnt_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_851(_TPPrule_851 _currn)
#else
void _VS3rule_851(_currn )
_TPPrule_851 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_desc1->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_AT_cBoundsListPtr_pre=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_desc2->_ATLocalIndex_pre=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_desc2->_ATIsArray_pre=_currn->_desc1->_ATIsArray_post;
/*SPC(0)*/
_currn->_desc2->_ATTypeLength_pre=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_AT_cBoundsListPtr_post=_currn->_desc2->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc2->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_desc2->_ATIsArray_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_desc2->_ATTypeLength_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_851(_TPPrule_851 _currn)
#else
void _VS4rule_851(_currn )
_TPPrule_851 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATDoAcc_pre=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_desc2->_ATStmtNumber_pre=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATUpdate_pre=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_desc2->_ATAccDoLoopDim_pre=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_desc2->_ATNestLevel_pre=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_desc2->_ATCPURegionNumber_pre=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATAccRegionNumber_pre=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATAcceleratorRegion_pre=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_desc2->_ATIndentLevel_pre=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_desc2->_ATArrayId_pre=_currn->_desc1->_ATArrayId_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_AT_const53=PTGSequence(_currn->_desc1->_AT_const53, IDENTICAL(_currn->_desc2->_ATDefinePtg));
/*SPC(3683)*/
_currn->_ATDoAcc_post=_currn->_desc2->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc2->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc2->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc2->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc2->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc2->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc2->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc2->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc2->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc2->_ATArrayId_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_852(_TPPrule_852 _currn)
#else
void _VS1rule_852(_currn )
_TPPrule_852 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATOrder_post=_currn->_desc1->_ATOrder_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_852(_TPPrule_852 _currn)
#else
void _VS2rule_852(_currn )
_TPPrule_852 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATLastNonExecLine_post=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc1->_ATArgCnt_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_852(_TPPrule_852 _currn)
#else
void _VS3rule_852(_currn )
_TPPrule_852 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_desc1->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_cBoundsListPtr_post=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_desc1->_ATIsArray_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_852(_TPPrule_852 _currn)
#else
void _VS4rule_852(_currn )
_TPPrule_852 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_const53=IDENTICAL(_currn->_desc1->_ATDefinePtg);
/*SPC(3681)*/
_currn->_ATDoAcc_post=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc1->_ATArrayId_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_853(_TPPrule_853 _currn)
#else
void _VS1rule_853(_currn )
_TPPrule_853 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATIntent=3;
/*SPC(3633)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_854(_TPPrule_854 _currn)
#else
void _VS1rule_854(_currn )
_TPPrule_854 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATIntent=2;
/*SPC(3629)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_855(_TPPrule_855 _currn)
#else
void _VS1rule_855(_currn )
_TPPrule_855 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATIntent=1;
/*SPC(3625)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_856(_TPPrule_856 _currn)
#else
void _VS1rule_856(_currn )
_TPPrule_856 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATIntent=2;
/*SPC(3621)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_857(_TPPrule_857 _currn)
#else
void _VS1rule_857(_currn )
_TPPrule_857 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_const42=ZERO();
/*SPC(3617)*/
_currn->_ATOrder_post=_currn->_ATOrder_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_857(_TPPrule_857 _currn)
#else
void _VS2rule_857(_currn )
_TPPrule_857 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATLastNonExecLine_post=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_ATArgCnt_pre;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_ATIsArray_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_857(_TPPrule_857 _currn)
#else
void _VS3rule_857(_currn )
_TPPrule_857 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_AT_const44=IDENTICAL(_currn->_desc1->_ATIntent);
/*SPC(3617)*/
_currn->_AT_cBoundsListPtr_post=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_ATTypeLength_pre;
/*SPC(0)*/
_currn->_ATParameterAttr=0;
/*SPC(3695)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_857(_TPPrule_857 _currn)
#else
void _VS4rule_857(_currn )
_TPPrule_857 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_AT_const43=ZERO();
/*SPC(3617)*/
_currn->_ATDoAcc_post=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_ATArrayId_pre;
/*SPC(0)*/
_currn->_ATExternAttr=PTGNULL;
/*SPC(3889)*/
_currn->_ATPtg=PTGAsIs("F2C-ACC: xAttrSpec not supported.");
/*SPC(3886)*/
_currn->_ATAllocatableAttr=0;
/*SPC(3751)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_858(_TPPrule_858 _currn)
#else
void _VS1rule_858(_currn )
_TPPrule_858 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/

if (EQ(strcmp(MapFile(_currn->_AT_line), StringTable(GetClpValue(FileName, 0))), 0)) {
message(WARNING, "Syntax not supported", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(3520)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATOrder_post=_currn->_desc1->_ATOrder_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_858(_TPPrule_858 _currn)
#else
void _VS2rule_858(_currn )
_TPPrule_858 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATLastNonExecLine_post=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc1->_ATArgCnt_post;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_desc1->_ATIsArray_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_858(_TPPrule_858 _currn)
#else
void _VS3rule_858(_currn )
_TPPrule_858 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_cBoundsListPtr_post=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_858(_TPPrule_858 _currn)
#else
void _VS4rule_858(_currn )
_TPPrule_858 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS6MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATTypeLength_post=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5rule_858(_TPPrule_858 _currn)
#else
void _VS5rule_858(_currn )
_TPPrule_858 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS7MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS8MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS9MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS10MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATDoAcc_post=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc1->_ATArrayId_post;
/*SPC(0)*/
_currn->_ATLength=0;
/*SPC(3511)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_859(_TPPrule_859 _currn)
#else
void _VS1rule_859(_currn )
_TPPrule_859 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATOrder_post=_currn->_ATOrder_pre;
/*SPC(0)*/

if (EQ(strcmp(MapFile(_currn->_AT_line), StringTable(GetClpValue(FileName, 0))), 0)) {
message(WARNING, "Syntax not supported", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(3514)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_859(_TPPrule_859 _currn)
#else
void _VS2rule_859(_currn )
_TPPrule_859 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATLastNonExecLine_post=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_ATArgCnt_pre;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_ATIsArray_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_859(_TPPrule_859 _currn)
#else
void _VS3rule_859(_currn )
_TPPrule_859 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_AT_cBoundsListPtr_post=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_859(_TPPrule_859 _currn)
#else
void _VS4rule_859(_currn )
_TPPrule_859 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATTypeLength_post=_currn->_ATTypeLength_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5rule_859(_TPPrule_859 _currn)
#else
void _VS5rule_859(_currn )
_TPPrule_859 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATDoAcc_post=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_ATArrayId_pre;
/*SPC(0)*/
_currn->_ATLength=0;
/*SPC(3511)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_860(_TPPrule_860 _currn)
#else
void _VS1rule_860(_currn )
_TPPrule_860 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATOrder_post=_currn->_desc1->_ATOrder_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_860(_TPPrule_860 _currn)
#else
void _VS2rule_860(_currn )
_TPPrule_860 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
_currn->_desc1->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATLastNonExecLine_post=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc1->_ATArgCnt_post;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_desc1->_ATIsArray_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_860(_TPPrule_860 _currn)
#else
void _VS3rule_860(_currn )
_TPPrule_860 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_cBoundsListPtr_post=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=IdnNumb(0, xIcon);
/*SPC(3604)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_860(_TPPrule_860 _currn)
#else
void _VS4rule_860(_currn )
_TPPrule_860 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_desc1->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATDoAcc_post=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc1->_ATArrayId_post;
/*SPC(0)*/
_currn->_ATLength=_currn->_desc1->_ATLength;
/*SPC(3508)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_861(_TPPrule_861 _currn)
#else
void _VS1rule_861(_currn )
_TPPrule_861 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATOrder_post=_currn->_ATOrder_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_861(_TPPrule_861 _currn)
#else
void _VS2rule_861(_currn )
_TPPrule_861 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATLastNonExecLine_post=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_ATArgCnt_pre;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_ATIsArray_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_861(_TPPrule_861 _currn)
#else
void _VS3rule_861(_currn )
_TPPrule_861 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_AT_cBoundsListPtr_post=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_ATTypeLength_post=IdnNumb(0, _currn->_ATTERM_1);
/*SPC(3600)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_861(_TPPrule_861 _currn)
#else
void _VS4rule_861(_currn )
_TPPrule_861 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATDoAcc_post=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_ATArrayId_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_862(_TPPrule_862 _currn)
#else
void _VS1rule_862(_currn )
_TPPrule_862 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATOrder_post=_currn->_desc1->_ATOrder_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_862(_TPPrule_862 _currn)
#else
void _VS2rule_862(_currn )
_TPPrule_862 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
_currn->_desc1->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATLastNonExecLine_post=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc1->_ATArgCnt_post;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_desc1->_ATIsArray_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_862(_TPPrule_862 _currn)
#else
void _VS3rule_862(_currn )
_TPPrule_862 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_cBoundsListPtr_post=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_862(_TPPrule_862 _currn)
#else
void _VS4rule_862(_currn )
_TPPrule_862 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_desc1->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATDoAcc_post=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc1->_ATArrayId_post;
/*SPC(0)*/
_currn->_ATPtg=PTGAsIs("F2C-ACC: xCharSelector not supported.");
/*SPC(3471)*/
_currn->_ATLength=_currn->_desc1->_ATLength;
/*SPC(3500)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_863(_TPPrule_863 _currn)
#else
void _VS1rule_863(_currn )
_TPPrule_863 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATOrder_pre=_currn->_desc1->_ATOrder_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATOrder_post=_currn->_desc2->_ATOrder_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_863(_TPPrule_863 _currn)
#else
void _VS2rule_863(_currn )
_TPPrule_863 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
_currn->_desc1->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATLastNonExecLine_pre=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_desc2->_ATArgCnt_pre=_currn->_desc1->_ATArgCnt_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_desc2->_ATIsArray_pre=_currn->_desc1->_ATIsArray_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATLastNonExecLine_post=_currn->_desc2->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc2->_ATArgCnt_post;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_desc2->_ATIsArray_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_863(_TPPrule_863 _currn)
#else
void _VS3rule_863(_currn )
_TPPrule_863 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_AT_cBoundsListPtr_pre=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_desc2->_ATTypeLength_pre=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS6MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_AT_cBoundsListPtr_post=_currn->_desc2->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_desc2->_ATTypeLength_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_863(_TPPrule_863 _currn)
#else
void _VS4rule_863(_currn )
_TPPrule_863 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_desc1->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATLocalIndex_pre=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS7MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
(*(_CALL_VS_((NODEPTR )) (VS8MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_desc2->_ATDoAcc_pre=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_desc2->_ATAccDoLoopDim_pre=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_desc2->_ATNestLevel_pre=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS9MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_desc2->_ATStmtNumber_pre=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATUpdate_pre=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_desc2->_ATCPURegionNumber_pre=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATAccRegionNumber_pre=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATAcceleratorRegion_pre=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_desc2->_ATIndentLevel_pre=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_desc2->_ATArrayId_pre=_currn->_desc1->_ATArrayId_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS10MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATDoAcc_post=_currn->_desc2->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc2->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc2->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc2->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc2->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc2->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc2->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc2->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc2->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc2->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc2->_ATArrayId_post;
/*SPC(0)*/
_currn->_ATPtg=PTGAsIs("F2C-ACC: xCharSelector not supported.");
/*SPC(3471)*/
_currn->_ATLength=_currn->_desc1->_ATLength;
/*SPC(3496)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_864(_TPPrule_864 _currn)
#else
void _VS1rule_864(_currn )
_TPPrule_864 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATOrder_pre=_currn->_desc1->_ATOrder_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATOrder_post=_currn->_desc2->_ATOrder_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_864(_TPPrule_864 _currn)
#else
void _VS2rule_864(_currn )
_TPPrule_864 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
_currn->_desc1->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATLastNonExecLine_pre=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_desc2->_ATArgCnt_pre=_currn->_desc1->_ATArgCnt_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_desc2->_ATIsArray_pre=_currn->_desc1->_ATIsArray_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATLastNonExecLine_post=_currn->_desc2->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc2->_ATArgCnt_post;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_desc2->_ATIsArray_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_864(_TPPrule_864 _currn)
#else
void _VS3rule_864(_currn )
_TPPrule_864 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_AT_cBoundsListPtr_pre=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_desc2->_ATTypeLength_pre=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS6MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_AT_cBoundsListPtr_post=_currn->_desc2->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_desc2->_ATTypeLength_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_864(_TPPrule_864 _currn)
#else
void _VS4rule_864(_currn )
_TPPrule_864 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_desc1->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATLocalIndex_pre=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS7MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
(*(_CALL_VS_((NODEPTR )) (VS8MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_desc2->_ATDoAcc_pre=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_desc2->_ATAccDoLoopDim_pre=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_desc2->_ATNestLevel_pre=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS9MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_desc2->_ATStmtNumber_pre=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATUpdate_pre=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_desc2->_ATCPURegionNumber_pre=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATAccRegionNumber_pre=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATAcceleratorRegion_pre=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_desc2->_ATIndentLevel_pre=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_desc2->_ATArrayId_pre=_currn->_desc1->_ATArrayId_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS10MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATDoAcc_post=_currn->_desc2->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc2->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc2->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc2->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc2->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc2->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc2->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc2->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc2->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc2->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc2->_ATArrayId_post;
/*SPC(0)*/
_currn->_ATPtg=PTGAsIs("F2C-ACC: xCharSelector not supported.");
/*SPC(3471)*/
_currn->_ATLength=_currn->_desc1->_ATLength;
/*SPC(3492)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_865(_TPPrule_865 _currn)
#else
void _VS1rule_865(_currn )
_TPPrule_865 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATOrder_post=_currn->_desc1->_ATOrder_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_865(_TPPrule_865 _currn)
#else
void _VS2rule_865(_currn )
_TPPrule_865 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
_currn->_desc1->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATLastNonExecLine_post=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc1->_ATArgCnt_post;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_desc1->_ATIsArray_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_865(_TPPrule_865 _currn)
#else
void _VS3rule_865(_currn )
_TPPrule_865 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_cBoundsListPtr_post=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_865(_TPPrule_865 _currn)
#else
void _VS4rule_865(_currn )
_TPPrule_865 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_desc1->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATDoAcc_post=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc1->_ATArrayId_post;
/*SPC(0)*/
_currn->_ATPtg=PTGAsIs("F2C-ACC: xCharSelector not supported.");
/*SPC(3471)*/
_currn->_ATLength=_currn->_desc1->_ATLength;
/*SPC(3488)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_866(_TPPrule_866 _currn)
#else
void _VS1rule_866(_currn )
_TPPrule_866 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/

if (EQ(strcmp(MapFile(_currn->_AT_line), StringTable(GetClpValue(FileName, 0))), 0)) {
message(WARNING, "Syntax not supported", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(3483)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATOrder_post=_currn->_desc1->_ATOrder_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_866(_TPPrule_866 _currn)
#else
void _VS2rule_866(_currn )
_TPPrule_866 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATLastNonExecLine_post=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc1->_ATArgCnt_post;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_desc1->_ATIsArray_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_866(_TPPrule_866 _currn)
#else
void _VS3rule_866(_currn )
_TPPrule_866 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS6MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_cBoundsListPtr_post=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_866(_TPPrule_866 _currn)
#else
void _VS4rule_866(_currn )
_TPPrule_866 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS7MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS8MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS9MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS10MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATDoAcc_post=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc1->_ATArrayId_post;
/*SPC(0)*/
_currn->_ATPtg=PTGAsIs("F2C-ACC: xCharSelector not supported.");
/*SPC(3471)*/
_currn->_ATLength=0;
/*SPC(3481)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_867(_TPPrule_867 _currn)
#else
void _VS1rule_867(_currn )
_TPPrule_867 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATOrder_post=_currn->_desc1->_ATOrder_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_867(_TPPrule_867 _currn)
#else
void _VS2rule_867(_currn )
_TPPrule_867 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
_currn->_desc1->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATLastNonExecLine_post=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc1->_ATArgCnt_post;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_desc1->_ATIsArray_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_867(_TPPrule_867 _currn)
#else
void _VS3rule_867(_currn )
_TPPrule_867 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_cBoundsListPtr_post=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_867(_TPPrule_867 _currn)
#else
void _VS4rule_867(_currn )
_TPPrule_867 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_desc1->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATDoAcc_post=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc1->_ATArrayId_post;
/*SPC(0)*/
_currn->_ATPtg=PTGAsIs("F2C-ACC: xCharSelector not supported.");
/*SPC(3471)*/
_currn->_ATLength=_currn->_desc1->_ATLength;
/*SPC(3476)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_868(_TPPrule_868 _currn)
#else
void _VS1rule_868(_currn )
_TPPrule_868 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATOrder_post=_currn->_ATOrder_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_868(_TPPrule_868 _currn)
#else
void _VS2rule_868(_currn )
_TPPrule_868 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATLastNonExecLine_post=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_ATArgCnt_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_868(_TPPrule_868 _currn)
#else
void _VS4rule_868(_currn )
_TPPrule_868 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATIsArray_post=_currn->_ATIsArray_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5rule_868(_TPPrule_868 _currn)
#else
void _VS5rule_868(_currn )
_TPPrule_868 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_cBoundsListPtr_post=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_ATValue=0;
/*SPC(116)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS6rule_868(_TPPrule_868 _currn)
#else
void _VS6rule_868(_currn )
_TPPrule_868 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATTypeLength_post=_currn->_ATTypeLength_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS7rule_868(_TPPrule_868 _currn)
#else
void _VS7rule_868(_currn )
_TPPrule_868 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATLocalIndex_post=_currn->_ATLocalIndex_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS8rule_868(_TPPrule_868 _currn)
#else
void _VS8rule_868(_currn )
_TPPrule_868 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATExpValue=0;
/*SPC(6827)*/
_currn->_ATFunctionName=PTGNULL;
/*SPC(6639)*/
_currn->_ATPtg=_currn->_desc1->_ATPtg;
/*SPC(3384)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS9rule_868(_TPPrule_868 _currn)
#else
void _VS9rule_868(_currn )
_TPPrule_868 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATDoAcc_post=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_ATLoopIncrNeg=
((EQ(MOD(ZERO(), 2), 1)
) ? (1
) : (0))
;
/*SPC(5862)*/
_currn->_AT_const47=ZERO();
/*SPC(3383)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS10rule_868(_TPPrule_868 _currn)
#else
void _VS10rule_868(_currn )
_TPPrule_868 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_AT_const49=ZERO();
/*SPC(3383)*/
_currn->_AT_const52=ZERO();
/*SPC(3383)*/
_currn->_ATStmtNumber_post=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_ATArrayId_pre;
/*SPC(0)*/
_currn->_ATDynamicSize=0;
/*SPC(10950)*/
_currn->_ATArgType=
((EQ((* _IG_incl26), 1)
) ? (Convert_to_Ctype(_currn->_ATTypeLength_pre, LogicalType)
) : (PTGNULL))
;
/*SPC(4725)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_869(_TPPrule_869 _currn)
#else
void _VS1rule_869(_currn )
_TPPrule_869 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATOrder_post=_currn->_ATOrder_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_869(_TPPrule_869 _currn)
#else
void _VS2rule_869(_currn )
_TPPrule_869 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATLastNonExecLine_post=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_ATArgCnt_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_869(_TPPrule_869 _currn)
#else
void _VS3rule_869(_currn )
_TPPrule_869 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATIsArray_post=_currn->_ATIsArray_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_869(_TPPrule_869 _currn)
#else
void _VS4rule_869(_currn )
_TPPrule_869 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_cBoundsListPtr_post=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_ATDoAcc_post=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_ATArrayId_pre;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_ATTypeLength_pre;
/*SPC(0)*/
_currn->_ATPtg=_currn->_desc1->_ATPtg;
/*SPC(3380)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_870(_TPPrule_870 _currn)
#else
void _VS1rule_870(_currn )
_TPPrule_870 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATOrder_post=_currn->_desc1->_ATOrder_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_870(_TPPrule_870 _currn)
#else
void _VS2rule_870(_currn )
_TPPrule_870 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATLastNonExecLine_post=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc1->_ATArgCnt_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_870(_TPPrule_870 _currn)
#else
void _VS3rule_870(_currn )
_TPPrule_870 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATIsArray_post=_currn->_desc1->_ATIsArray_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_870(_TPPrule_870 _currn)
#else
void _VS4rule_870(_currn )
_TPPrule_870 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS6MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS7MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS8MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS9MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_cBoundsListPtr_post=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_ATDoAcc_post=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc1->_ATArrayId_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/
_currn->_ATPtg=_currn->_desc1->_ATPtg;
/*SPC(3376)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_871(_TPPrule_871 _currn)
#else
void _VS1rule_871(_currn )
_TPPrule_871 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATOrder_post=_currn->_desc1->_ATOrder_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_871(_TPPrule_871 _currn)
#else
void _VS2rule_871(_currn )
_TPPrule_871 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATLastNonExecLine_post=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc1->_ATArgCnt_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_871(_TPPrule_871 _currn)
#else
void _VS3rule_871(_currn )
_TPPrule_871 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATIsArray_post=_currn->_desc1->_ATIsArray_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_871(_TPPrule_871 _currn)
#else
void _VS4rule_871(_currn )
_TPPrule_871 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_desc1->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_cBoundsListPtr_post=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_ATDoAcc_post=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc1->_ATArrayId_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/
_currn->_ATPtg=PTGNULL;
/*SPC(3352)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_872(_TPPrule_872 _currn)
#else
void _VS1rule_872(_currn )
_TPPrule_872 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATOrder_post=_currn->_ATOrder_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_872(_TPPrule_872 _currn)
#else
void _VS2rule_872(_currn )
_TPPrule_872 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATLastNonExecLine_post=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_ATArgCnt_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_872(_TPPrule_872 _currn)
#else
void _VS3rule_872(_currn )
_TPPrule_872 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATIsArray_post=_currn->_ATIsArray_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_872(_TPPrule_872 _currn)
#else
void _VS4rule_872(_currn )
_TPPrule_872 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_AT_cBoundsListPtr_post=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_ATDoAcc_post=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_ATArrayId_pre;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_ATTypeLength_pre;
/*SPC(0)*/
_currn->_ATPtg=PTGQuotedString(PTGString(StringTable(_currn->_ATTERM_1)));
/*SPC(3369)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_873(_TPPrule_873 _currn)
#else
void _VS1rule_873(_currn )
_TPPrule_873 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATOrder_post=_currn->_ATOrder_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_873(_TPPrule_873 _currn)
#else
void _VS2rule_873(_currn )
_TPPrule_873 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATLastNonExecLine_post=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_ATArgCnt_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_873(_TPPrule_873 _currn)
#else
void _VS3rule_873(_currn )
_TPPrule_873 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATIsArray_post=_currn->_ATIsArray_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_873(_TPPrule_873 _currn)
#else
void _VS4rule_873(_currn )
_TPPrule_873 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_cBoundsListPtr_post=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_ATDoAcc_post=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_ATArrayId_pre;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_ATTypeLength_pre;
/*SPC(0)*/
_currn->_ATPtg=PTGNULL;
/*SPC(3352)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_874(_TPPrule_874 _currn)
#else
void _VS1rule_874(_currn )
_TPPrule_874 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATOrder_post=_currn->_ATOrder_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_874(_TPPrule_874 _currn)
#else
void _VS2rule_874(_currn )
_TPPrule_874 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATLastNonExecLine_post=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_ATArgCnt_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_874(_TPPrule_874 _currn)
#else
void _VS3rule_874(_currn )
_TPPrule_874 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATIsArray_post=_currn->_ATIsArray_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_874(_TPPrule_874 _currn)
#else
void _VS4rule_874(_currn )
_TPPrule_874 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_cBoundsListPtr_post=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_ATDoAcc_post=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_ATArrayId_pre;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_ATTypeLength_pre;
/*SPC(0)*/
_currn->_ATPtg=PTGNULL;
/*SPC(3352)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_875(_TPPrule_875 _currn)
#else
void _VS1rule_875(_currn )
_TPPrule_875 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATOrder_post=_currn->_ATOrder_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_875(_TPPrule_875 _currn)
#else
void _VS2rule_875(_currn )
_TPPrule_875 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATLastNonExecLine_post=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_ATArgCnt_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_875(_TPPrule_875 _currn)
#else
void _VS3rule_875(_currn )
_TPPrule_875 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATIsArray_post=_currn->_ATIsArray_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_875(_TPPrule_875 _currn)
#else
void _VS4rule_875(_currn )
_TPPrule_875 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_AT_cBoundsListPtr_post=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_ATDoAcc_post=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_ATArrayId_pre;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_ATTypeLength_pre;
/*SPC(0)*/
_currn->_ATPtg=PTGNULL;
/*SPC(3352)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_876(_TPPrule_876 _currn)
#else
void _VS1rule_876(_currn )
_TPPrule_876 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATOrder_post=_currn->_ATOrder_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_876(_TPPrule_876 _currn)
#else
void _VS2rule_876(_currn )
_TPPrule_876 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATLastNonExecLine_post=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_ATArgCnt_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_876(_TPPrule_876 _currn)
#else
void _VS3rule_876(_currn )
_TPPrule_876 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATIsArray_post=_currn->_ATIsArray_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_876(_TPPrule_876 _currn)
#else
void _VS4rule_876(_currn )
_TPPrule_876 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_AT_cBoundsListPtr_post=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_ATDoAcc_post=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_ATArrayId_pre;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_ATTypeLength_pre;
/*SPC(0)*/
_currn->_ATPtg=PTGNULL;
/*SPC(3352)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_877(_TPPrule_877 _currn)
#else
void _VS1rule_877(_currn )
_TPPrule_877 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATOrder_post=_currn->_ATOrder_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_877(_TPPrule_877 _currn)
#else
void _VS2rule_877(_currn )
_TPPrule_877 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATLastNonExecLine_post=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_ATArgCnt_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_877(_TPPrule_877 _currn)
#else
void _VS3rule_877(_currn )
_TPPrule_877 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATIsArray_post=_currn->_ATIsArray_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_877(_TPPrule_877 _currn)
#else
void _VS4rule_877(_currn )
_TPPrule_877 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_AT_cBoundsListPtr_post=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_ATDoAcc_post=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_ATArrayId_pre;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_ATTypeLength_pre;
/*SPC(0)*/
_currn->_ATPtg=PTGNULL;
/*SPC(3352)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_878(_TPPrule_878 _currn)
#else
void _VS1rule_878(_currn )
_TPPrule_878 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATOrder_post=_currn->_desc1->_ATOrder_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_878(_TPPrule_878 _currn)
#else
void _VS2rule_878(_currn )
_TPPrule_878 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATLastNonExecLine_post=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc1->_ATArgCnt_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_878(_TPPrule_878 _currn)
#else
void _VS3rule_878(_currn )
_TPPrule_878 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATIsArray_post=_currn->_desc1->_ATIsArray_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_878(_TPPrule_878 _currn)
#else
void _VS4rule_878(_currn )
_TPPrule_878 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS6MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS7MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS8MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS9MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_cBoundsListPtr_post=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_ATDoAcc_post=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc1->_ATArrayId_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/
_currn->_ATPtg=PTGSequence(PTGAsIs("-"), _currn->_desc1->_ATPtg);
/*SPC(3349)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_879(_TPPrule_879 _currn)
#else
void _VS1rule_879(_currn )
_TPPrule_879 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATOrder_post=_currn->_desc1->_ATOrder_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_879(_TPPrule_879 _currn)
#else
void _VS2rule_879(_currn )
_TPPrule_879 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATLastNonExecLine_post=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc1->_ATArgCnt_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_879(_TPPrule_879 _currn)
#else
void _VS3rule_879(_currn )
_TPPrule_879 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATIsArray_post=_currn->_desc1->_ATIsArray_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_879(_TPPrule_879 _currn)
#else
void _VS4rule_879(_currn )
_TPPrule_879 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS6MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS7MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS8MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS9MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_cBoundsListPtr_post=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_ATDoAcc_post=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc1->_ATArrayId_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/
_currn->_ATPtg=PTGSequence(PTGAsIs("+"), _currn->_desc1->_ATPtg);
/*SPC(3345)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_880(_TPPrule_880 _currn)
#else
void _VS1rule_880(_currn )
_TPPrule_880 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATUnitBind=BindIdn((* _IG_incl11), _currn->_ATSym);
/*SPC(11047)*/
_currn->_ATUnitKey=KeyOf(_currn->_ATUnitBind);
/*SPC(11049)*/
GuaranteeType(_currn->_ATUnitKey, DefaultType(_currn->_ATSym));
/*SPC(873)*/
_currn->_ATUnitCnt=ADD(1, GetUnitCnt(_currn->_ATUnitKey, 0));
/*SPC(11286)*/
ResetUnitCnt(_currn->_ATUnitKey, _currn->_ATUnitCnt);
/*SPC(11289)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_880(_TPPrule_880 _currn)
#else
void _VS2rule_880(_currn )
_TPPrule_880 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();

if (DisjIS(ConsIS(Constant, ConsIS(IntrinsicFunction, ConsIS(InExternalStmt, ConsIS(Array, ConsIS(Subroutine, ConsIS(MainProgram, ConsIS(BlockDataSubprogram, ConsIS(ExternalFunction, ConsIS(StatementFunction, NullIS()))))))))), GetKindSet(_currn->_ATUnitKey, NullIS()))) {
InsertKindSet(_currn->_ATUnitKey, Variable);

} else {
}
;
/*SPC(2506)*/
_currn->_ATPtg=PTGString(StringTable(_currn->_ATTERM_1));
/*SPC(3286)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_880(_TPPrule_880 _currn)
#else
void _VS3rule_880(_currn )
_TPPrule_880 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATBind=BindingInEnv((* _IG_incl10), _currn->_ATSym);
/*SPC(11195)*/
_currn->_ATUnitTotalCnt=GetUnitCnt(_currn->_ATUnitKey, 0);
/*SPC(11293)*/
_currn->_ATKey=KeyOf(_currn->_ATBind);
/*SPC(11199)*/
_currn->_ATCoord=(&( _currn->_AT_pos));
/*SPC(2251)*/
_currn->_ATObjectKey=
((_currn->_ATKey
) ? (_currn->_ATKey
) : (_currn->_ATUnitKey))
;
/*SPC(2155)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_881(_TPPrule_881 _currn)
#else
void _VS1rule_881(_currn )
_TPPrule_881 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATUnitBind=BindIdn((* _IG_incl11), _currn->_ATSym);
/*SPC(11047)*/
_currn->_ATUnitKey=KeyOf(_currn->_ATUnitBind);
/*SPC(11049)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_881(_TPPrule_881 _currn)
#else
void _VS2rule_881(_currn )
_TPPrule_881 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
GuaranteeType(_currn->_ATUnitKey, DefaultType(_currn->_ATSym));
/*SPC(873)*/
_currn->_ATBind=BindIdn((* _IG_incl10), _currn->_ATSym);
/*SPC(11183)*/
_currn->_ATKey=KeyOf(_currn->_ATBind);
/*SPC(11185)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_881(_TPPrule_881 _currn)
#else
void _VS3rule_881(_currn )
_TPPrule_881 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();

if (DisjIS(ConsIS(Constant, ConsIS(IntrinsicFunction, ConsIS(InExternalStmt, ConsIS(Array, ConsIS(Subroutine, ConsIS(MainProgram, ConsIS(BlockDataSubprogram, ConsIS(ExternalFunction, ConsIS(StatementFunction, NullIS()))))))))), GetKindSet(_currn->_ATUnitKey, NullIS()))) {
InsertKindSet(_currn->_ATUnitKey, Variable);

} else {
}
;
/*SPC(2506)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_881(_TPPrule_881 _currn)
#else
void _VS4rule_881(_currn )
_TPPrule_881 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATLocalIndex_post=_currn->_ATLocalIndex_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5rule_881(_TPPrule_881 _currn)
#else
void _VS5rule_881(_currn )
_TPPrule_881 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATObjectKey=
((_currn->_ATKey
) ? (_currn->_ATKey
) : (_currn->_ATUnitKey))
;
/*SPC(2155)*/
_currn->_ATPtg=PTGString(StringTable(_currn->_ATTERM_1));
/*SPC(3270)*/
_currn->_ATCoord=(&( _currn->_AT_pos));
/*SPC(2251)*/

if ((* _IG_incl22)) {

if (AND(EQ(strcmp(MapFile(((_currn->_AT_pos).line)), StringTable(GetClpValue(FileName, 0))), 0), GT(GetClpValue(WarnLevel, 0), 0))) {

if (InIS(Subroutine, GetKindSet(_currn->_ATUnitKey, NullIS()))) {
message(NOTE, "Unable to classify this identifier.", 0, _currn->_ATCoord);

} else {
}
;

} else {
}
;

if (AND(EQ(strcmp(MapFile(((_currn->_AT_pos).line)), StringTable(GetClpValue(FileName, 0))), 0), GT(GetClpValue(WarnLevel, 0), 0))) {

if (InIS(MainProgram, GetKindSet(_currn->_ATUnitKey, NullIS()))) {
message(NOTE, "Unable to classify this identifier.", 0, _currn->_ATCoord);

} else {
}
;

} else {
}
;

if (AND(EQ(strcmp(MapFile(((_currn->_AT_pos).line)), StringTable(GetClpValue(FileName, 0))), 0), GT(GetClpValue(WarnLevel, 0), 0))) {

if (InIS(BlockDataSubprogram, GetKindSet(_currn->_ATUnitKey, NullIS()))) {
message(NOTE, "Unable to classify this identifier.", 0, _currn->_ATCoord);

} else {
}
;

} else {
}
;

if (AND(EQ(strcmp(MapFile(((_currn->_AT_pos).line)), StringTable(GetClpValue(FileName, 0))), 0), GT(GetClpValue(WarnLevel, 0), 0))) {

if (InIS(Array, GetKindSet(_currn->_ATUnitKey, NullIS()))) {
message(NOTE, "Unable to classify this identifier.", 0, _currn->_ATCoord);

} else {
}
;

} else {
}
;

if (AND(EQ(strcmp(MapFile(((_currn->_AT_pos).line)), StringTable(GetClpValue(FileName, 0))), 0), GT(GetClpValue(WarnLevel, 0), 0))) {

if (InIS(Subroutine, GetKindSet(_currn->_ATUnitKey, NullIS()))) {
message(NOTE, "Unable to classify this identifier.", 0, _currn->_ATCoord);

} else {
}
;

} else {
}
;

if (AND(EQ(strcmp(MapFile(((_currn->_AT_pos).line)), StringTable(GetClpValue(FileName, 0))), 0), GT(GetClpValue(WarnLevel, 0), 0))) {

if (InIS(MainProgram, GetKindSet(_currn->_ATUnitKey, NullIS()))) {
message(NOTE, "Unable to classify this identifier.", 0, _currn->_ATCoord);

} else {
}
;

} else {
}
;

if (AND(EQ(strcmp(MapFile(((_currn->_AT_pos).line)), StringTable(GetClpValue(FileName, 0))), 0), GT(GetClpValue(WarnLevel, 0), 0))) {

if (InIS(BlockDataSubprogram, GetKindSet(_currn->_ATUnitKey, NullIS()))) {
message(NOTE, "Unable to classify this identifier.", 0, _currn->_ATCoord);

} else {
}
;

} else {
}
;

if (AND(EQ(strcmp(MapFile(((_currn->_AT_pos).line)), StringTable(GetClpValue(FileName, 0))), 0), GT(GetClpValue(WarnLevel, 0), 0))) {

if (InIS(StatementFunction, GetKindSet(_currn->_ATUnitKey, NullIS()))) {
message(NOTE, "Unable to classify this identifier.", 0, _currn->_ATCoord);

} else {
}
;

} else {
}
;

if (AND(EQ(strcmp(MapFile(((_currn->_AT_pos).line)), StringTable(GetClpValue(FileName, 0))), 0), GT(GetClpValue(WarnLevel, 0), 0))) {

if (InIS(DummyProcedure, GetKindSet(_currn->_ATUnitKey, NullIS()))) {
message(NOTE, "Unable to classify this identifier.", 0, _currn->_ATCoord);

} else {
}
;

} else {
}
;
;

} else {
}
;
/*SPC(2603)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_882(_TPPrule_882 _currn)
#else
void _VS1rule_882(_currn )
_TPPrule_882 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATOrder_post=_currn->_ATOrder_pre;
/*SPC(0)*/
_currn->_ATUnitBind=BindIdn((* _IG_incl11), _currn->_ATSym);
/*SPC(11047)*/
_currn->_ATUnitKey=KeyOf(_currn->_ATUnitBind);
/*SPC(11049)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_882(_TPPrule_882 _currn)
#else
void _VS2rule_882(_currn )
_TPPrule_882 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
GuaranteeType(_currn->_ATUnitKey, DefaultType(_currn->_ATSym));
/*SPC(873)*/
_currn->_ATBind=BindIdn((* _IG_incl10), _currn->_ATSym);
/*SPC(11183)*/

if (DisjIS(ConsIS(Constant, ConsIS(IntrinsicFunction, ConsIS(InExternalStmt, ConsIS(Array, ConsIS(Subroutine, ConsIS(MainProgram, ConsIS(BlockDataSubprogram, ConsIS(ExternalFunction, ConsIS(StatementFunction, NullIS()))))))))), GetKindSet(_currn->_ATUnitKey, NullIS()))) {
InsertKindSet(_currn->_ATUnitKey, Variable);

} else {
}
;
/*SPC(2506)*/
_currn->_ATKey=KeyOf(_currn->_ATBind);
/*SPC(11185)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_882(_TPPrule_882 _currn)
#else
void _VS3rule_882(_currn )
_TPPrule_882 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATObjectKey=
((_currn->_ATKey
) ? (_currn->_ATKey
) : (_currn->_ATUnitKey))
;
/*SPC(2155)*/
_currn->_ATPtg=PTGString(StringTable(_currn->_ATTERM_1));
/*SPC(3266)*/
_currn->_ATCoord=(&( _currn->_AT_pos));
/*SPC(2251)*/

if (AND(EQ(strcmp(MapFile(((_currn->_AT_pos).line)), StringTable(GetClpValue(FileName, 0))), 0), GT(GetClpValue(WarnLevel, 0), 0))) {

if (InIS(Subroutine, GetKindSet(_currn->_ATUnitKey, NullIS()))) {
message(NOTE, "Unable to classify this identifier.", 0, _currn->_ATCoord);

} else {
}
;

} else {
}
;
/*SPC(2831)*/

if (AND(EQ(strcmp(MapFile(((_currn->_AT_pos).line)), StringTable(GetClpValue(FileName, 0))), 0), GT(GetClpValue(WarnLevel, 0), 0))) {

if (InIS(MainProgram, GetKindSet(_currn->_ATUnitKey, NullIS()))) {
message(NOTE, "Unable to classify this identifier.", 0, _currn->_ATCoord);

} else {
}
;

} else {
}
;
/*SPC(2838)*/

if (AND(EQ(strcmp(MapFile(((_currn->_AT_pos).line)), StringTable(GetClpValue(FileName, 0))), 0), GT(GetClpValue(WarnLevel, 0), 0))) {

if (InIS(BlockDataSubprogram, GetKindSet(_currn->_ATUnitKey, NullIS()))) {
message(NOTE, "Unable to classify this identifier.", 0, _currn->_ATCoord);

} else {
}
;

} else {
}
;
/*SPC(2845)*/

if (AND(EQ(strcmp(MapFile(((_currn->_AT_pos).line)), StringTable(GetClpValue(FileName, 0))), 0), GT(GetClpValue(WarnLevel, 0), 0))) {

if (InIS(ExternalFunction, GetKindSet(_currn->_ATUnitKey, NullIS()))) {
message(NOTE, "Unable to classify this identifier.", 0, _currn->_ATCoord);

} else {
}
;

} else {
}
;
/*SPC(2853)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_883(_TPPrule_883 _currn)
#else
void _VS1rule_883(_currn )
_TPPrule_883 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATUnitBind=BindIdn((* _IG_incl11), _currn->_ATSym);
/*SPC(11047)*/
_currn->_ATUnitKey=KeyOf(_currn->_ATUnitBind);
/*SPC(11049)*/
IsType(_currn->_ATUnitKey, (* _IG_incl31), ErrorType);
/*SPC(1818)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_883(_TPPrule_883 _currn)
#else
void _VS2rule_883(_currn )
_TPPrule_883 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
GuaranteeType(_currn->_ATUnitKey, DefaultType(_currn->_ATSym));
/*SPC(873)*/
_currn->_ATUnitCnt=ADD(1, GetUnitCnt(_currn->_ATUnitKey, 0));
/*SPC(11286)*/
ResetUnitCnt(_currn->_ATUnitKey, _currn->_ATUnitCnt);
/*SPC(11289)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_883(_TPPrule_883 _currn)
#else
void _VS3rule_883(_currn )
_TPPrule_883 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATBind=BindingInEnv((* _IG_incl10), _currn->_ATSym);
/*SPC(11195)*/

if (DisjIS(ConsIS(Constant, ConsIS(IntrinsicFunction, ConsIS(InExternalStmt, ConsIS(Array, ConsIS(Subroutine, ConsIS(MainProgram, ConsIS(BlockDataSubprogram, ConsIS(ExternalFunction, ConsIS(StatementFunction, NullIS()))))))))), GetKindSet(_currn->_ATUnitKey, NullIS()))) {
InsertKindSet(_currn->_ATUnitKey, Variable);

} else {
}
;
/*SPC(2506)*/
_currn->_ATKey=KeyOf(_currn->_ATBind);
/*SPC(11199)*/
_currn->_ATObjectKey=
((_currn->_ATKey
) ? (_currn->_ATKey
) : (_currn->_ATUnitKey))
;
/*SPC(2155)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_883(_TPPrule_883 _currn)
#else
void _VS4rule_883(_currn )
_TPPrule_883 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();

if (AND(EQ(strcmp(MapFile(_currn->_AT_line), StringTable(GetClpValue(FileName, 0))), 0), GT(GetClpValue(WarnLevel, 32767), 0))) {

if (AND(GetIntrinsic(_currn->_ATObjectKey, 0), NE(GetType(_currn->_ATUnitKey, NoKey), GetType(_currn->_ATObjectKey, NoKey)))) {
message(ERROR, "Cannot change the type of an intrinsic function", 0, (&( _currn->_AT_pos)));

} else {
}
;

} else {
}
;
/*SPC(1898)*/

if (AND(GT(GetClpValue(WarnLevel, 32767), 0), EQ(GetType(_currn->_ATUnitKey, NoKey), ErrorType))) {
message(ERROR, "Defined with different types", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(1824)*/
_currn->_ATUnitTotalCnt=GetUnitCnt(_currn->_ATUnitKey, 0);
/*SPC(11293)*/
_currn->_ATPtg=PTGString(StringTable(_currn->_ATTERM_1));
/*SPC(3262)*/
_currn->_ATCoord=(&( _currn->_AT_pos));
/*SPC(2251)*/

if (AND(EQ(strcmp(MapFile(((_currn->_AT_pos).line)), StringTable(GetClpValue(FileName, 0))), 0), GT(GetClpValue(WarnLevel, 32767), 0))) {

if (DisjIS(GetKindSet(_currn->_ATUnitKey, SingleIS(Variable)), ConsIS(Constant, ConsIS(Variable, ConsIS(Array, ConsIS(ExternalFunction, ConsIS(IntrinsicFunction, ConsIS(InExternalStmt, ConsIS(StatementFunction, NullIS()))))))))) {
message(ERROR, "This class of symbolic name cannot be typed", 0, (&( _currn->_AT_pos)));

} else {
}
;

} else {
}
;
/*SPC(1855)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_884(_TPPrule_884 _currn)
#else
void _VS1rule_884(_currn )
_TPPrule_884 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATUnitBind=BindIdn((* _IG_incl11), _currn->_ATSym);
/*SPC(11047)*/
_currn->_ATUnitKey=KeyOf(_currn->_ATUnitBind);
/*SPC(11049)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_884(_TPPrule_884 _currn)
#else
void _VS2rule_884(_currn )
_TPPrule_884 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATLastNonExecLine_post=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
GuaranteeType(_currn->_ATUnitKey, DefaultType(_currn->_ATSym));
/*SPC(873)*/
_currn->_ATUnitCnt=ADD(1, GetUnitCnt(_currn->_ATUnitKey, 0));
/*SPC(11286)*/
ResetUnitCnt(_currn->_ATUnitKey, _currn->_ATUnitCnt);
/*SPC(11289)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_884(_TPPrule_884 _currn)
#else
void _VS3rule_884(_currn )
_TPPrule_884 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();

if (DisjIS(ConsIS(Constant, ConsIS(IntrinsicFunction, ConsIS(InExternalStmt, ConsIS(Array, ConsIS(Subroutine, ConsIS(MainProgram, ConsIS(BlockDataSubprogram, ConsIS(ExternalFunction, ConsIS(StatementFunction, NullIS()))))))))), GetKindSet(_currn->_ATUnitKey, NullIS()))) {
InsertKindSet(_currn->_ATUnitKey, Variable);

} else {
}
;
/*SPC(2506)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_884(_TPPrule_884 _currn)
#else
void _VS4rule_884(_currn )
_TPPrule_884 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATBind=BindingInEnv((* _IG_incl10), _currn->_ATSym);
/*SPC(11195)*/
_currn->_ATKey=KeyOf(_currn->_ATBind);
/*SPC(11199)*/
_currn->_ATObjectKey=
((_currn->_ATKey
) ? (_currn->_ATKey
) : (_currn->_ATUnitKey))
;
/*SPC(2155)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5rule_884(_TPPrule_884 _currn)
#else
void _VS5rule_884(_currn )
_TPPrule_884 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_AT_cBoundsListPtr_post=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS6rule_884(_TPPrule_884 _currn)
#else
void _VS6rule_884(_currn )
_TPPrule_884 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATLocalIndex_post=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_ATPtg=PTGString(StringTable(_currn->_ATTERM_1));
/*SPC(3258)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS7rule_884(_TPPrule_884 _currn)
#else
void _VS7rule_884(_currn )
_TPPrule_884 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATDoAcc_post=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_ATNestLevel_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS8rule_884(_TPPrule_884 _currn)
#else
void _VS8rule_884(_currn )
_TPPrule_884 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATStmtNumber_post=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_ATUnitTotalCnt=GetUnitCnt(_currn->_ATUnitKey, 0);
/*SPC(11293)*/
_currn->_ATdefineVarCPU=
((AND(EQ(_currn->_ATAcceleratorRegion_pre, 0), AND(OR(AND(InIS(Variable, GetKindSet(_currn->_ATUnitKey, NullIS())), EQ(isIntrinsic(StringTable(_currn->_ATSym), _currn->_ATNumArgs), 0)), OR(InIS(Array, GetKindSet(_currn->_ATUnitKey, NullIS())), InIS(Constant, GetKindSet(_currn->_ATUnitKey, NullIS())))), EQ(GetVariableCPU(_currn->_ATObjectKey, 0), 0)))
) ? (1
) : (0))
;
/*SPC(9963)*/
_currn->_ATdefineVarGPU=
((AND(GE(_currn->_ATAcceleratorRegion_pre, 1), OR(AND(InIS(Array, GetKindSet(_currn->_ATUnitKey, NullIS())), EQ(MOD(GetVariableGPU(_currn->_ATObjectKey, 0), 1000), 0)), OR(AND(InIS(Constant, GetKindSet(_currn->_ATUnitKey, NullIS())), EQ(GetVariableGPU(_currn->_ATObjectKey, 0), 0)), AND(InIS(Variable, GetKindSet(_currn->_ATUnitKey, NullIS())), AND(EQ(isIntrinsic(StringTable(_currn->_ATSym), _currn->_ATNumArgs), 0), NE(MOD(GetVariableGPU(_currn->_ATObjectKey, 0), 1000), MOD(_currn->_ATAccRegionNumber_pre, 1000)))))))
) ? (1
) : (0))
;
/*SPC(9950)*/
_currn->_ATGPUtype=
((AND(EQ(GetClpValue(Generate, 1), 1), AND(GE(_currn->_ATAcceleratorRegion_pre, 1), OR(InIS(Array, GetKindSet(_currn->_ATUnitKey, NullIS())), EQ(GetVariableDeclared(_currn->_ATObjectKey, 0), 3))))
) ? (PTGAsIs("__device__")
) : (PTGNULL))
;
/*SPC(9933)*/
_currn->_ATextern=
((EQ(GetVariableDeclared(_currn->_ATObjectKey, 0), 3)
) ? (PTGAsIs("extern ")
) : (PTGNULL))
;
/*SPC(9927)*/

if (AND(EQ(strcmp(MapFile(_currn->_AT_line), StringTable(GetClpValue(FileName, 0))), 0), AND(EQ(isIntrinsic(StringTable(_currn->_ATSym), _currn->_ATNumArgs), 0), AND(EQ(_currn->_ATignoreVar, 0), AND(NE(GetClpValue(Generate, 1), 1), EQ(GetVariableDeclared(_currn->_ATObjectKey, 0), 0)))))) {
PTGOut(PTGDeclareVar(PTGNumber(_currn->_ATLastNonExecLine_pre), PTGNULL, PTGNULL, Convert_to_Ctype(GetTypeLength(_currn->_ATUnitKey, 0), GetType(_currn->_ATUnitKey, ErrorType)), GenerateArray(_currn->_ATPtg, GetArraySizeList(_currn->_ATObjectKey, NULLBoundsList))));

} else {
}
;
/*SPC(4435)*/
_currn->_ATCoord=(&( _currn->_AT_pos));
/*SPC(2251)*/
_currn->_ATDeclLine=
((AND(EQ(GetClpValue(Generate, 1), 1), AND(GE(_currn->_ATAcceleratorRegion_pre, 1), NOT(InIS(Array, GetKindSet(_currn->_ATUnitKey, NullIS())))))
) ? (_currn->_ATAcceleratorRegion_pre
) : (_currn->_ATLastNonExecLine_pre))
;
/*SPC(9942)*/

if (AND(EQ(strcmp(MapFile(((_currn->_AT_pos).line)), StringTable(GetClpValue(FileName, 0))), 0), AND(EQ(isIntrinsic(StringTable(_currn->_ATSym), _currn->_ATNumArgs), 0), AND(EQ(_currn->_ATignoreVar, 0), AND(NE(GetClpValue(Generate, 1), 1), EQ(GetVariableDeclared(_currn->_ATObjectKey, 0), 0)))))) {
message(NOTE, "Undefined variable declared.", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(4450)*/

if (AND(EQ(strcmp(MapFile(((_currn->_AT_pos).line)), StringTable(GetClpValue(FileName, 0))), 0), AND(EQ(GetClpValue(Generate, 1), 1), AND(NE(GetVariableDeclared(_currn->_ATObjectKey, 0), 1), AND(EQ(_currn->_ATignoreVar, 0), AND(NOT(InIS(Constant, GetKindSet(_currn->_ATUnitKey, NullIS()))), OR(EQ(_currn->_ATdefineVarGPU, 1), EQ(_currn->_ATdefineVarCPU, 1)))))))) {
PTGOut(PTGDeclareVar(PTGNumber(_currn->_ATDeclLine), _currn->_ATextern, _currn->_ATGPUtype, Convert_to_Ctype(GetTypeLength(_currn->_ATUnitKey, 0), GetType(_currn->_ATUnitKey, ErrorType)), GenerateArray(_currn->_ATPtg, GetArraySizeList(_currn->_ATObjectKey, NULLBoundsList))));

} else {
}
;
/*SPC(9977)*/

if (AND(EQ(strcmp(MapFile(((_currn->_AT_pos).line)), StringTable(GetClpValue(FileName, 0))), 0), AND(EQ(GetClpValue(Generate, 1), 1), AND(GT(MapLine(((_currn->_AT_pos).line)), _currn->_ATLastNonExecLine_pre), AND(EQ(_currn->_ATAcceleratorRegion_pre, 0), AND(NE(GetVariableDeclared(_currn->_ATObjectKey, 0), 1), AND(EQ(GetVariableUse(_currn->_ATObjectKey, 2, 2000, _currn->_ATSym, _currn->_ATAccRegionNumber_pre, MapLine(((_currn->_AT_pos).line))), 1), AND(EQ(GetVariableUse(_currn->_ATObjectKey, 1, 1000, _currn->_ATSym, _currn->_ATCPURegionNumber_pre, MapLine(((_currn->_AT_pos).line))), 0), EQ(_currn->_ATUpdate_pre, 0))))))))) {
message(WARNING, "GPU-to-CPU communication needed for the referenced variable.", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(10097)*/

if (AND(EQ(strcmp(MapFile(((_currn->_AT_pos).line)), StringTable(GetClpValue(FileName, 0))), 0), AND(EQ(GetClpValue(Generate, 1), 1), AND(GT(MapLine(((_currn->_AT_pos).line)), _currn->_ATLastNonExecLine_pre), AND(GT(_currn->_ATAcceleratorRegion_pre, MapLine(((_currn->_AT_pos).line))), AND(NE(GetVariableDeclared(_currn->_ATObjectKey, 0), 1), AND(EQ(GetVariableUse(_currn->_ATObjectKey, 1, 2000, _currn->_ATSym, _currn->_ATCPURegionNumber_pre, MapLine(((_currn->_AT_pos).line))), 1), AND(EQ(GetVariableUse(_currn->_ATObjectKey, 2, 1000, _currn->_ATSym, _currn->_ATAccRegionNumber_pre, MapLine(((_currn->_AT_pos).line))), 0), EQ(_currn->_ATUpdate_pre, 0))))))))) {
message(WARNING, "CPU-to-GPU communication needed for the referenced variable.", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(10114)*/

if (AND(EQ(GetClpValue(Generate, 1), 1), AND(OR(InIS(Constant, GetKindSet(_currn->_ATUnitKey, NullIS())), EQ(GetVariableConstant(_currn->_ATObjectKey, 0), 1)), OR(EQ(_currn->_ATdefineVarGPU, 1), EQ(_currn->_ATdefineVarCPU, 1))))) {
PTGOut(PTGAppend(PTGNumber(MapLine(((_currn->_AT_pos).line))), PTGDefineConstant(_currn->_ATPtg, GetVariableConstantValue(_currn->_ATObjectKey, PTGNULL))));

} else {
}
;
/*SPC(10007)*/

if (AND(OR(EQ(strcmp(MapFile(((_currn->_AT_pos).line)), StringTable(GetClpValue(FileName, 0))), 0), GE(isModule(((_currn->_AT_pos).line)), 1)), EQ(_currn->_ATignoreVar, 0))) {

if (GE(_currn->_ATAcceleratorRegion_pre, 1)) {
SetVariable(_currn->_ATObjectKey, _currn->_ATAccRegionNumber_pre, _currn->_ATUpdate_pre, 2, _currn->_ATSym, ((_currn->_AT_pos).line));

} else {
SetVariable(_currn->_ATObjectKey, _currn->_ATCPURegionNumber_pre, _currn->_ATUpdate_pre, 1, _currn->_ATSym, ((_currn->_AT_pos).line));
}
;

} else {
}
;
/*SPC(9995)*/
_currn->_ATAcceleratorRegion_post=_currn->_ATAcceleratorRegion_pre;
/*SPC(9974)*/

if (AND(EQ(strcmp(MapFile(((_currn->_AT_pos).line)), StringTable(GetClpValue(FileName, 0))), 0), AND(EQ(_currn->_ATignoreVar, 0), EQ(GetVariableDeclared(_currn->_ATObjectKey, 0), 0)))) {
ResetVariableDeclared(_currn->_ATObjectKey, 2);

} else {
}
;
/*SPC(4463)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_885(_TPPrule_885 _currn)
#else
void _VS1rule_885(_currn )
_TPPrule_885 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATUnitBind=BindIdn((* _IG_incl11), _currn->_ATSym);
/*SPC(11047)*/
_currn->_ATUnitKey=KeyOf(_currn->_ATUnitBind);
/*SPC(11049)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_885(_TPPrule_885 _currn)
#else
void _VS2rule_885(_currn )
_TPPrule_885 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATLastNonExecLine_post=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
GuaranteeType(_currn->_ATUnitKey, DefaultType(_currn->_ATSym));
/*SPC(873)*/
_currn->_ATUnitCnt=ADD(1, GetUnitCnt(_currn->_ATUnitKey, 0));
/*SPC(11286)*/
ResetUnitCnt(_currn->_ATUnitKey, _currn->_ATUnitCnt);
/*SPC(11289)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_885(_TPPrule_885 _currn)
#else
void _VS3rule_885(_currn )
_TPPrule_885 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();

if (DisjIS(ConsIS(Constant, ConsIS(IntrinsicFunction, ConsIS(InExternalStmt, ConsIS(Array, ConsIS(Subroutine, ConsIS(MainProgram, ConsIS(BlockDataSubprogram, ConsIS(ExternalFunction, ConsIS(StatementFunction, NullIS()))))))))), GetKindSet(_currn->_ATUnitKey, NullIS()))) {
InsertKindSet(_currn->_ATUnitKey, Variable);

} else {
}
;
/*SPC(2506)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_885(_TPPrule_885 _currn)
#else
void _VS4rule_885(_currn )
_TPPrule_885 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATBind=BindingInEnv((* _IG_incl10), _currn->_ATSym);
/*SPC(11195)*/
_currn->_ATKey=KeyOf(_currn->_ATBind);
/*SPC(11199)*/
_currn->_ATPtg=PTGString(StringTable(_currn->_ATTERM_1));
/*SPC(3254)*/
_currn->_ATObjectKey=
((_currn->_ATKey
) ? (_currn->_ATKey
) : (_currn->_ATUnitKey))
;
/*SPC(2155)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5rule_885(_TPPrule_885 _currn)
#else
void _VS5rule_885(_currn )
_TPPrule_885 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_AT_cBoundsListPtr_post=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_ATDoAcc_post=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_ATNestLevel_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS6rule_885(_TPPrule_885 _currn)
#else
void _VS6rule_885(_currn )
_TPPrule_885 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATStmtNumber_post=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_ATUnitTotalCnt=GetUnitCnt(_currn->_ATUnitKey, 0);
/*SPC(11293)*/
_currn->_ATdefineVarCPU=
((AND(EQ(_currn->_ATAcceleratorRegion_pre, 0), AND(OR(InIS(Variable, GetKindSet(_currn->_ATUnitKey, NullIS())), InIS(Array, GetKindSet(_currn->_ATUnitKey, NullIS()))), EQ(GetVariableCPU(_currn->_ATObjectKey, 0), 0)))
) ? (1
) : (0))
;
/*SPC(10057)*/
_currn->_ATdefineVarGPU=
((AND(GE(_currn->_ATAcceleratorRegion_pre, 1), OR(AND(InIS(Array, GetKindSet(_currn->_ATUnitKey, NullIS())), EQ(MOD(GetVariableGPU(_currn->_ATObjectKey, 0), 1000), 0)), AND(InIS(Variable, GetKindSet(_currn->_ATUnitKey, NullIS())), NE(MOD(GetVariableGPU(_currn->_ATObjectKey, 0), 1000), MOD(_currn->_ATAccRegionNumber_pre, 1000)))))
) ? (1
) : (0))
;
/*SPC(10047)*/
_currn->_ATDeclLine=
((AND(EQ(GetClpValue(Generate, 1), 1), AND(GE(_currn->_ATAcceleratorRegion_pre, 1), NOT(InIS(Array, GetKindSet(_currn->_ATUnitKey, NullIS())))))
) ? (
((EQ(GetVariableDeclared(_currn->_ATObjectKey, 0), 3)
) ? (0
) : (_currn->_ATAcceleratorRegion_pre))

) : (_currn->_ATLastNonExecLine_pre))
;
/*SPC(10036)*/
_currn->_ATGPUtype=
((AND(EQ(GetClpValue(Generate, 1), 1), AND(GE(_currn->_ATAcceleratorRegion_pre, 1), InIS(Array, GetKindSet(_currn->_ATUnitKey, NullIS()))))
) ? (PTGAsIs("__device__")
) : (PTGNULL))
;
/*SPC(10028)*/
_currn->_ATextern=
((EQ(GetVariableDeclared(_currn->_ATObjectKey, 0), 3)
) ? (PTGAsIs("extern ")
) : (PTGNULL))
;
/*SPC(10022)*/
_currn->_ATCoord=(&( _currn->_AT_pos));
/*SPC(2251)*/

if (AND(EQ(strcmp(MapFile(((_currn->_AT_pos).line)), StringTable(GetClpValue(FileName, 0))), 0), AND(EQ(GetClpValue(Generate, 1), 1), AND(NE(GetVariableDeclared(_currn->_ATObjectKey, 0), 1), OR(EQ(_currn->_ATdefineVarGPU, 1), EQ(_currn->_ATdefineVarCPU, 1)))))) {
PTGOut(PTGDeclareVar(PTGNumber(_currn->_ATDeclLine), _currn->_ATGPUtype, _currn->_ATextern, Convert_to_Ctype(GetTypeLength(_currn->_ATUnitKey, 0), GetType(_currn->_ATUnitKey, ErrorType)), GenerateArray(_currn->_ATPtg, GetArraySizeList(_currn->_ATObjectKey, NULLBoundsList))));

} else {
}
;
/*SPC(10067)*/

if (AND(EQ(strcmp(MapFile(((_currn->_AT_pos).line)), StringTable(GetClpValue(FileName, 0))), 0), AND(EQ(GetClpValue(Generate, 1), 1), AND(GT(MapLine(((_currn->_AT_pos).line)), _currn->_ATLastNonExecLine_pre), AND(EQ(_currn->_ATAcceleratorRegion_pre, 0), AND(NE(GetVariableDeclared(_currn->_ATObjectKey, 0), 1), AND(EQ(GetVariableUse(_currn->_ATObjectKey, 2, 2000, _currn->_ATSym, _currn->_ATAccRegionNumber_pre, MapLine(((_currn->_AT_pos).line))), 1), AND(EQ(GetVariableUse(_currn->_ATObjectKey, 1, 1000, _currn->_ATSym, _currn->_ATCPURegionNumber_pre, MapLine(((_currn->_AT_pos).line))), 0), EQ(_currn->_ATUpdate_pre, 0))))))))) {
message(WARNING, "GPU-to-CPU communication needed for the referenced variable.", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(10134)*/

if (AND(EQ(strcmp(MapFile(((_currn->_AT_pos).line)), StringTable(GetClpValue(FileName, 0))), 0), AND(EQ(GetClpValue(Generate, 1), 1), AND(GT(MapLine(((_currn->_AT_pos).line)), _currn->_ATLastNonExecLine_pre), AND(GE(_currn->_ATAcceleratorRegion_pre, 1), AND(NE(GetVariableDeclared(_currn->_ATObjectKey, 0), 1), AND(EQ(GetVariableUse(_currn->_ATObjectKey, 1, 2000, _currn->_ATSym, _currn->_ATCPURegionNumber_pre, MapLine(((_currn->_AT_pos).line))), 1), AND(EQ(GetVariableUse(_currn->_ATObjectKey, 2, 1000, _currn->_ATSym, _currn->_ATAccRegionNumber_pre, MapLine(((_currn->_AT_pos).line))), 0), EQ(_currn->_ATUpdate_pre, 0))))))))) {
message(WARNING, "CPU-to-GPU communication needed for the referenced variable.", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(10146)*/

if (EQ(strcmp(MapFile(((_currn->_AT_pos).line)), StringTable(GetClpValue(FileName, 0))), 0)) {

if (GE(_currn->_ATAcceleratorRegion_pre, 1)) {
SetVariable(_currn->_ATObjectKey, _currn->_ATAccRegionNumber_pre, _currn->_ATUpdate_pre, 2, _currn->_ATSym, ((_currn->_AT_pos).line));

} else {
SetVariable(_currn->_ATObjectKey, _currn->_ATCPURegionNumber_pre, _currn->_ATUpdate_pre, 1, _currn->_ATSym, ((_currn->_AT_pos).line));
}
;

} else {
}
;
/*SPC(10082)*/
_currn->_ATAcceleratorRegion_post=_currn->_ATAcceleratorRegion_pre;
/*SPC(10066)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_886(_TPPrule_886 _currn)
#else
void _VS1rule_886(_currn )
_TPPrule_886 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATOrder_pre=_currn->_desc1->_ATOrder_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATOrder_post=_currn->_desc2->_ATOrder_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_886(_TPPrule_886 _currn)
#else
void _VS2rule_886(_currn )
_TPPrule_886 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATLastNonExecLine_pre=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_desc2->_ATArgCnt_pre=_currn->_desc1->_ATArgCnt_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATLastNonExecLine_post=_currn->_desc2->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc2->_ATArgCnt_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_886(_TPPrule_886 _currn)
#else
void _VS3rule_886(_currn )
_TPPrule_886 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_886(_TPPrule_886 _currn)
#else
void _VS4rule_886(_currn )
_TPPrule_886 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATIsArray_pre=_currn->_desc1->_ATIsArray_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATIsArray_post=_currn->_desc2->_ATIsArray_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5rule_886(_TPPrule_886 _currn)
#else
void _VS5rule_886(_currn )
_TPPrule_886 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_AT_cBoundsListPtr_pre=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_AT_cBoundsListPtr_post=_currn->_desc2->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_ATUpperValue=_currn->_desc2->_ATValue;
/*SPC(3179)*/
_currn->_ATLowerValue=_currn->_desc1->_ATValue;
/*SPC(3178)*/
_currn->_ATSizeValue=MakeName(CatStrStr(CatStrStr(CatStrStr(StringTable(_currn->_desc2->_ATValue), "-("), StringTable(_currn->_desc1->_ATValue)), ")+1"));
/*SPC(3180)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS6rule_886(_TPPrule_886 _currn)
#else
void _VS6rule_886(_currn )
_TPPrule_886 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS6MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATTypeLength_pre=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS6MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATTypeLength_post=_currn->_desc2->_ATTypeLength_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS7rule_886(_TPPrule_886 _currn)
#else
void _VS7rule_886(_currn )
_TPPrule_886 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS7MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATLocalIndex_pre=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS7MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATLocalIndex_post=_currn->_desc2->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATvariableName_RuleAttr_1361=PTGSequence(PTGAsIs("ii_"), PTGNumber(_currn->_ATLocalIndex_pre));
/*SPC(6071)*/
_currn->_ATPtg=_currn->_ATvariableName_RuleAttr_1361;
/*SPC(6072)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS8rule_886(_TPPrule_886 _currn)
#else
void _VS8rule_886(_currn )
_TPPrule_886 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS8MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS9MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS8MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_desc2->_ATDoAcc_pre=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_desc2->_ATAccDoLoopDim_pre=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_desc2->_ATNestLevel_pre=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS9MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_AT_const47=ADD(_currn->_desc1->_AT_const47, _currn->_desc2->_AT_const47);
/*SPC(3177)*/
_currn->_ATDoAcc_post=_currn->_desc2->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc2->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc2->_ATNestLevel_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS9rule_886(_TPPrule_886 _currn)
#else
void _VS9rule_886(_currn )
_TPPrule_886 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();

if (EQ(strcmp(MapFile(_currn->_AT_line), StringTable(GetClpValue(FileName, 0))), 0)) {

if (AND(EQ(_currn->_ATUpdate_pre, 1), NE((* _IG_incl23), 1))) {
PTGOut(PTGSequence(PTGAppend(PTGNumber(SUB(MapLine(_currn->_AT_line), 1)), PTGGenerateForLoop(PTGIndent(_currn->_ATIndentLevel_pre), _currn->_ATvariableName_RuleAttr_1361, _currn->_desc1->_ATPtg, _currn->_ATvariableName_RuleAttr_1361, _currn->_desc2->_ATPtg, _currn->_ATvariableName_RuleAttr_1361)), PTGAppend(PTGNumber(MapLine(_currn->_AT_line)), PTGGenerateEndLoop(PTGIndent(_currn->_ATIndentLevel_pre)))));

} else {
}
;

} else {
}
;
/*SPC(6089)*/
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS10MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATStmtNumber_pre=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATUpdate_pre=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_desc2->_ATCPURegionNumber_pre=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATAccRegionNumber_pre=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATAcceleratorRegion_pre=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_desc2->_ATIndentLevel_pre=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_desc2->_ATArrayId_pre=_currn->_desc1->_ATArrayId_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS10MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_AT_const49=ADD(ADD(_currn->_desc1->_AT_const49, IDENTICAL(_currn->_desc1->_ATDynamicSize)), ADD(_currn->_desc2->_AT_const49, IDENTICAL(_currn->_desc2->_ATDynamicSize)));
/*SPC(3177)*/
_currn->_AT_const52=ADD(_currn->_desc1->_AT_const52, _currn->_desc2->_AT_const52);
/*SPC(3177)*/
_currn->_ATStmtNumber_post=_currn->_desc2->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc2->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc2->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc2->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc2->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc2->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc2->_ATArrayId_post;
/*SPC(0)*/
_currn->_ATF90Syntax=1;
/*SPC(6069)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_887(_TPPrule_887 _currn)
#else
void _VS1rule_887(_currn )
_TPPrule_887 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATOrder_post=_currn->_desc1->_ATOrder_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_887(_TPPrule_887 _currn)
#else
void _VS2rule_887(_currn )
_TPPrule_887 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATLastNonExecLine_post=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc1->_ATArgCnt_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_887(_TPPrule_887 _currn)
#else
void _VS3rule_887(_currn )
_TPPrule_887 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_887(_TPPrule_887 _currn)
#else
void _VS4rule_887(_currn )
_TPPrule_887 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATIsArray_post=_currn->_desc1->_ATIsArray_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5rule_887(_TPPrule_887 _currn)
#else
void _VS5rule_887(_currn )
_TPPrule_887 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATBoundsTakeIt=1;
/*SPC(11376)*/
_currn->_ATBoundsElem=PkgBounds(_currn->_desc1->_ATValue, MakeName("1"), _currn->_desc1->_ATValue);
/*SPC(3165)*/
_currn->_AT_cBoundsListPtr_post=
((_currn->_ATBoundsTakeIt
) ? (RefEndConsBoundsList(_currn->_desc1->_AT_cBoundsListPtr_post, _currn->_ATBoundsElem)
) : (_currn->_desc1->_AT_cBoundsListPtr_post))
;
/*SPC(11377)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS6rule_887(_TPPrule_887 _currn)
#else
void _VS6rule_887(_currn )
_TPPrule_887 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS6MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATTypeLength_post=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS7rule_887(_TPPrule_887 _currn)
#else
void _VS7rule_887(_currn )
_TPPrule_887 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS7MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATLocalIndex_post=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS8rule_887(_TPPrule_887 _currn)
#else
void _VS8rule_887(_currn )
_TPPrule_887 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS8MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATPtg=_currn->_desc1->_ATPtg;
/*SPC(6059)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS9rule_887(_TPPrule_887 _currn)
#else
void _VS9rule_887(_currn )
_TPPrule_887 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS9MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_const47=_currn->_desc1->_AT_const47;
/*SPC(3164)*/
_currn->_ATDoAcc_post=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS10rule_887(_TPPrule_887 _currn)
#else
void _VS10rule_887(_currn )
_TPPrule_887 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS10MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_const49=ADD(_currn->_desc1->_AT_const49, IDENTICAL(_currn->_desc1->_ATDynamicSize));
/*SPC(3164)*/
_currn->_AT_const51=ZERO();
/*SPC(3164)*/
_currn->_AT_const52=_currn->_desc1->_AT_const52;
/*SPC(3164)*/
_currn->_ATStmtNumber_post=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc1->_ATArrayId_post;
/*SPC(0)*/
_currn->_ATNotCharacterIndex=1;
/*SPC(2296)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_888(_TPPrule_888 _currn)
#else
void _VS1rule_888(_currn )
_TPPrule_888 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATOrder_pre=_currn->_desc1->_ATOrder_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATOrder_post=_currn->_desc2->_ATOrder_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_888(_TPPrule_888 _currn)
#else
void _VS2rule_888(_currn )
_TPPrule_888 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATLastNonExecLine_pre=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_desc2->_ATArgCnt_pre=_currn->_desc1->_ATArgCnt_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATLastNonExecLine_post=_currn->_desc2->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc2->_ATArgCnt_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_888(_TPPrule_888 _currn)
#else
void _VS3rule_888(_currn )
_TPPrule_888 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATObjectId=_currn->_desc1->_ATObjectId;
/*SPC(3160)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_888(_TPPrule_888 _currn)
#else
void _VS4rule_888(_currn )
_TPPrule_888 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_desc1->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
_currn->_desc1->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATDoAcc_pre=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_desc2->_ATStmtNumber_pre=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATUpdate_pre=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_desc2->_ATAccDoLoopDim_pre=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_desc2->_ATNestLevel_pre=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_desc2->_ATCPURegionNumber_pre=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATAccRegionNumber_pre=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATAcceleratorRegion_pre=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_desc2->_ATIndentLevel_pre=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_desc2->_ATLocalIndex_pre=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_desc2->_ATArrayId_pre=_currn->_desc1->_ATArrayId_post;
/*SPC(0)*/
_currn->_desc2->_ATIsArray_pre=_currn->_desc1->_ATIsArray_post;
/*SPC(0)*/
_currn->_desc2->_ATTypeLength_pre=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_AT_const46=PTGSequence(_currn->_desc1->_AT_const46, IDENTICAL(_currn->_desc1->_ATPtg));
/*SPC(3159)*/
_currn->_AT_cBoundsListPtr_post=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_ATDoAcc_post=_currn->_desc2->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc2->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc2->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc2->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc2->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc2->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc2->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc2->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc2->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc2->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc2->_ATArrayId_post;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_desc2->_ATIsArray_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_desc2->_ATTypeLength_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_889(_TPPrule_889 _currn)
#else
void _VS1rule_889(_currn )
_TPPrule_889 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATOrder_post=_currn->_desc1->_ATOrder_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_889(_TPPrule_889 _currn)
#else
void _VS2rule_889(_currn )
_TPPrule_889 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATLastNonExecLine_post=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc1->_ATArgCnt_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_889(_TPPrule_889 _currn)
#else
void _VS3rule_889(_currn )
_TPPrule_889 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATIsArray_pre=1;
/*SPC(6369)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
ResetArraySizeList(_currn->_ATObjectId, _currn->_desc1->_ATBoundsList);
/*SPC(3155)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_889(_TPPrule_889 _currn)
#else
void _VS4rule_889(_currn )
_TPPrule_889 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATLocalIndex_pre=1;
/*SPC(6448)*/
_currn->_desc1->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATDoAcc_post=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=0;
/*SPC(6449)*/
_currn->_ATArrayId_post=_currn->_desc1->_ATArrayId_post;
/*SPC(0)*/
_currn->_ATIsArray_post=0;
/*SPC(6370)*/
_currn->_ATTypeLength_post=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_890(_TPPrule_890 _currn)
#else
void _VS1rule_890(_currn )
_TPPrule_890 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATOrder_post=_currn->_desc1->_ATOrder_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_890(_TPPrule_890 _currn)
#else
void _VS2rule_890(_currn )
_TPPrule_890 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATLastNonExecLine_post=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc1->_ATArgCnt_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_890(_TPPrule_890 _currn)
#else
void _VS3rule_890(_currn )
_TPPrule_890 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_BoundsauxList=NULLBoundsList;
/*SPC(11354)*/
_currn->_desc1->_AT_cBoundsListPtr_pre=_BoundsListADDROF(_currn->_AT_BoundsauxList);
/*SPC(11355)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATBoundsList=_currn->_AT_BoundsauxList;
/*SPC(11356)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_890(_TPPrule_890 _currn)
#else
void _VS4rule_890(_currn )
_TPPrule_890 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS6MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS7MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATMaxMinFunct=0;
/*SPC(6549)*/
(*(_CALL_VS_((NODEPTR )) (VS8MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS9MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS10MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATDoAcc_post=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc1->_ATArrayId_post;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_desc1->_ATIsArray_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_891(_TPPrule_891 _currn)
#else
void _VS1rule_891(_currn )
_TPPrule_891 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATOrder_post=_currn->_desc1->_ATOrder_post;
/*SPC(0)*/
_currn->_ATDims=_currn->_desc1->_ATDims;
/*SPC(3140)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_891(_TPPrule_891 _currn)
#else
void _VS2rule_891(_currn )
_TPPrule_891 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATLastNonExecLine_post=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc1->_ATArgCnt_post;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_desc1->_ATIsArray_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_891(_TPPrule_891 _currn)
#else
void _VS3rule_891(_currn )
_TPPrule_891 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS6MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_cBoundsListPtr_post=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_891(_TPPrule_891 _currn)
#else
void _VS4rule_891(_currn )
_TPPrule_891 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_desc1->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS7MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATDoAcc_post=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc1->_ATArrayId_post;
/*SPC(0)*/
_currn->_ATSizeValue=_currn->_desc1->_ATSizeValue;
/*SPC(3141)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_892(_TPPrule_892 _currn)
#else
void _VS1rule_892(_currn )
_TPPrule_892 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATOrder_post=_currn->_desc2->_ATOrder_post;
/*SPC(0)*/

if (GE((* _IG_incl32), 1)) {
InsertKindSet(_currn->_desc1->_ATUnitKey, Array);

} else {
}
;
/*SPC(3107)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_892(_TPPrule_892 _currn)
#else
void _VS2rule_892(_currn )
_TPPrule_892 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc2->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
_currn->_desc2->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATLastNonExecLine_post=_currn->_desc2->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc2->_ATArgCnt_post;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_desc2->_ATIsArray_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_892(_TPPrule_892 _currn)
#else
void _VS3rule_892(_currn )
_TPPrule_892 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_892(_TPPrule_892 _currn)
#else
void _VS4rule_892(_currn )
_TPPrule_892 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc2->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_desc2->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_AT_cBoundsListPtr_post=_currn->_desc2->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_desc2->_ATTypeLength_post;
/*SPC(0)*/

if (GE(isModule(_currn->_AT_line), 1)) {
ResetVariableDeclared(_currn->_desc1->_ATObjectKey, 3);

} else {

if (EQ((* _IG_incl28), 1)) {
ResetVariableDeclared(_currn->_desc1->_ATObjectKey, 1);

} else {

if (EQ(GetVariableDeclared(_currn->_desc1->_ATObjectKey, 0), 0)) {
ResetVariableDeclared(_currn->_desc1->_ATObjectKey, 2);

} else {
;
}
;
}
;
}
;
/*SPC(3979)*/

if (EQ((* _IG_incl33), 1)) {
ResetNumberOfDims(_currn->_desc1->_ATUnitKey, (* _IG_incl32));

} else {
;
}
;
/*SPC(3117)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5rule_892(_TPPrule_892 _currn)
#else
void _VS5rule_892(_currn )
_TPPrule_892 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc2->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc2->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc2->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc2->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_desc2->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc2->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc2->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc2->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc2->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_desc2->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATDoAcc_post=_currn->_desc2->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc2->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc2->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc2->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc2->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc2->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc2->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc2->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc2->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc2->_ATArrayId_post;
/*SPC(0)*/

if (EQ((* _IG_incl28), 1)) {
ResetVariableConstantValue(_currn->_desc1->_ATObjectKey, _currn->_desc2->_ATPtg);

} else {
PTGNULL;
}
;
/*SPC(10935)*/

if (EQ((* _IG_incl28), 1)) {
ResetVariableConstant(_currn->_desc1->_ATObjectKey, 1);

} else {
;
}
;
/*SPC(10929)*/
_currn->_ATOutput=
((EQ(GetVariableDeclared(_currn->_desc1->_ATObjectKey, 0), 1)
) ? (0
) : (1))
;
/*SPC(4047)*/
_currn->_ATDefinePtg=PTGDefineConstantCR(_currn->_desc1->_ATPtg, _currn->_desc2->_ATPtg);
/*SPC(3741)*/

if (EQ((* _IG_incl33), 1)) {
ResetArraySizeList(_currn->_desc1->_ATObjectKey, (* _IG_incl34));

} else {
;
}
;
/*SPC(3111)*/
_currn->_ATAcceleratorRegion_post=_currn->_ATAcceleratorRegion_pre;
/*SPC(10926)*/
_currn->_ATPtg=
((EQ(_currn->_ATOutput, 1)
) ? (
((GE((* _IG_incl29), 1)
) ? (PTGPointer(_currn->_desc1->_ATPtg)
) : (PTGSequence(_currn->_desc1->_ATPtg, _currn->_desc2->_ATPtg)))

) : (PTGNULL))
;
/*SPC(4253)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_893(_TPPrule_893 _currn)
#else
void _VS1rule_893(_currn )
_TPPrule_893 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();

if (EQ(strcmp(MapFile(_currn->_AT_line), StringTable(GetClpValue(FileName, 0))), 0)) {
message(WARNING, " This language construct not supported at this time.", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(4317)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_desc3->_ATOrder_pre=_currn->_desc2->_ATOrder_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);
_currn->_ATOrder_post=_currn->_desc3->_ATOrder_post;
/*SPC(0)*/

if (GE((* _IG_incl32), 1)) {
InsertKindSet(_currn->_desc1->_ATUnitKey, Array);

} else {
}
;
/*SPC(3088)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_893(_TPPrule_893 _currn)
#else
void _VS2rule_893(_currn )
_TPPrule_893 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc2->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
_currn->_desc2->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_desc3->_ATLastNonExecLine_pre=_currn->_desc2->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_desc3->_ATArgCnt_pre=_currn->_desc2->_ATArgCnt_post;
/*SPC(0)*/
_currn->_desc3->_ATIsArray_pre=_currn->_desc2->_ATIsArray_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);
_currn->_ATLastNonExecLine_post=_currn->_desc3->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc3->_ATArgCnt_post;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_desc3->_ATIsArray_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_893(_TPPrule_893 _currn)
#else
void _VS3rule_893(_currn )
_TPPrule_893 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_893(_TPPrule_893 _currn)
#else
void _VS4rule_893(_currn )
_TPPrule_893 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc2->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_desc3->_AT_cBoundsListPtr_pre=_currn->_desc2->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_desc3->_ATTypeLength_pre=_currn->_desc2->_ATTypeLength_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);
_currn->_AT_cBoundsListPtr_post=_currn->_desc3->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_desc3->_ATTypeLength_post;
/*SPC(0)*/

if (EQ((* _IG_incl33), 1)) {
ResetNumberOfDims(_currn->_desc1->_ATUnitKey, (* _IG_incl32));

} else {
;
}
;
/*SPC(3098)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5rule_893(_TPPrule_893 _currn)
#else
void _VS5rule_893(_currn )
_TPPrule_893 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc2->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc2->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc2->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc2->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_desc2->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc2->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc2->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc2->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc2->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_desc2->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
_currn->_desc2->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_desc3->_ATDoAcc_pre=_currn->_desc2->_ATDoAcc_post;
/*SPC(0)*/
_currn->_desc3->_ATStmtNumber_pre=_currn->_desc2->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_desc3->_ATUpdate_pre=_currn->_desc2->_ATUpdate_post;
/*SPC(0)*/
_currn->_desc3->_ATAccDoLoopDim_pre=_currn->_desc2->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_desc3->_ATNestLevel_pre=_currn->_desc2->_ATNestLevel_post;
/*SPC(0)*/
_currn->_desc3->_ATCPURegionNumber_pre=_currn->_desc2->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_desc3->_ATAccRegionNumber_pre=_currn->_desc2->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_desc3->_ATAcceleratorRegion_pre=_currn->_desc2->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_desc3->_ATIndentLevel_pre=_currn->_desc2->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_desc3->_ATLocalIndex_pre=_currn->_desc2->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_desc3->_ATArrayId_pre=_currn->_desc2->_ATArrayId_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);
_currn->_ATDoAcc_post=_currn->_desc3->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc3->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc3->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc3->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc3->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc3->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc3->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc3->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc3->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc3->_ATArrayId_post;
/*SPC(0)*/
_currn->_ATOutput=0;
/*SPC(4037)*/
_currn->_ATDefinePtg=PTGNULL;
/*SPC(3739)*/

if (EQ((* _IG_incl33), 1)) {
ResetArraySizeList(_currn->_desc1->_ATObjectKey, (* _IG_incl34));

} else {
;
}
;
/*SPC(3092)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc3->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATPtg=PTGAsIs("F2C-ACC: xEntityDecl not supported.");
/*SPC(4216)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_894(_TPPrule_894 _currn)
#else
void _VS1rule_894(_currn )
_TPPrule_894 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();

if (EQ(strcmp(MapFile(_currn->_AT_line), StringTable(GetClpValue(FileName, 0))), 0)) {
message(WARNING, " This language construct not supported at this time.", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(4307)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATOrder_post=_currn->_desc2->_ATOrder_post;
/*SPC(0)*/

if (GE((* _IG_incl32), 1)) {
InsertKindSet(_currn->_desc1->_ATUnitKey, Array);

} else {
}
;
/*SPC(3069)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_894(_TPPrule_894 _currn)
#else
void _VS2rule_894(_currn )
_TPPrule_894 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc2->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
_currn->_desc2->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATLastNonExecLine_post=_currn->_desc2->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc2->_ATArgCnt_post;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_desc2->_ATIsArray_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_894(_TPPrule_894 _currn)
#else
void _VS3rule_894(_currn )
_TPPrule_894 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_894(_TPPrule_894 _currn)
#else
void _VS4rule_894(_currn )
_TPPrule_894 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc2->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_AT_cBoundsListPtr_post=_currn->_desc2->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_desc2->_ATTypeLength_post;
/*SPC(0)*/

if (EQ((* _IG_incl33), 1)) {
ResetNumberOfDims(_currn->_desc1->_ATUnitKey, (* _IG_incl32));

} else {
;
}
;
/*SPC(3079)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5rule_894(_TPPrule_894 _currn)
#else
void _VS5rule_894(_currn )
_TPPrule_894 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc2->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc2->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc2->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc2->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_desc2->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc2->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc2->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc2->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc2->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_desc2->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
_currn->_desc2->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATDoAcc_post=_currn->_desc2->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc2->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc2->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc2->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc2->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc2->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc2->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc2->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc2->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc2->_ATArrayId_post;
/*SPC(0)*/
_currn->_ATOutput=0;
/*SPC(4037)*/
_currn->_ATDefinePtg=PTGNULL;
/*SPC(3739)*/

if (EQ((* _IG_incl33), 1)) {
ResetArraySizeList(_currn->_desc1->_ATObjectKey, (* _IG_incl34));

} else {
;
}
;
/*SPC(3073)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc2->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATPtg=PTGAsIs("F2C-ACC: xEntityDecl not supported.");
/*SPC(4216)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_895(_TPPrule_895 _currn)
#else
void _VS1rule_895(_currn )
_TPPrule_895 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATOrder_post=_currn->_ATOrder_pre;
/*SPC(0)*/

if (GE((* _IG_incl32), 1)) {
InsertKindSet(_currn->_desc1->_ATUnitKey, Array);

} else {
}
;
/*SPC(3050)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_895(_TPPrule_895 _currn)
#else
void _VS2rule_895(_currn )
_TPPrule_895 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATLastNonExecLine_post=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_ATArgCnt_pre;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_ATIsArray_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_895(_TPPrule_895 _currn)
#else
void _VS3rule_895(_currn )
_TPPrule_895 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_895(_TPPrule_895 _currn)
#else
void _VS4rule_895(_currn )
_TPPrule_895 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_AT_cBoundsListPtr_post=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_ATTypeLength_pre;
/*SPC(0)*/

if (AND(EQ(GetVariableDeclared(_currn->_desc1->_ATObjectKey, 0), 3), EQ(isModule(_currn->_AT_line), 0))) {
message(ERROR, "Variable is defined both locally and externally via a module.", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(3971)*/

if (GE(isModule(((_currn->_AT_pos).line)), 1)) {
ResetVariableDeclared(_currn->_desc1->_ATObjectKey, 3);

} else {

if (EQ((* _IG_incl28), 1)) {
ResetVariableDeclared(_currn->_desc1->_ATObjectKey, 1);

} else {

if (EQ(GetVariableDeclared(_currn->_desc1->_ATObjectKey, 0), 0)) {
ResetVariableDeclared(_currn->_desc1->_ATObjectKey, 2);

} else {
;
}
;
}
;
}
;
/*SPC(3958)*/
ResetIntent(_currn->_desc1->_ATObjectKey, (* _IG_incl35));
/*SPC(3640)*/
ResetTypeLength(_currn->_desc1->_ATUnitKey, _currn->_ATTypeLength_pre);
/*SPC(3568)*/

if (EQ((* _IG_incl33), 1)) {
ResetNumberOfDims(_currn->_desc1->_ATUnitKey, (* _IG_incl32));

} else {
;
}
;
/*SPC(3060)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5rule_895(_TPPrule_895 _currn)
#else
void _VS5rule_895(_currn )
_TPPrule_895 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATDoAcc_post=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_ATArrayId_pre;
/*SPC(0)*/
_currn->_ATbounds_RuleAttr_1370=GetAllArrayBounds(_currn->_desc1->_ATObjectKey, (* _IG_incl34), _currn->_desc1->_ATSym);
/*SPC(4225)*/
_currn->_ATOutput=
((EQ(GetVariableDeclared(_currn->_desc1->_ATObjectKey, 0), 1)
) ? (0
) : (1))
;
/*SPC(4039)*/
_currn->_ATDefinePtg=PTGNULL;
/*SPC(3739)*/

if (EQ((* _IG_incl33), 1)) {
ResetArraySizeList(_currn->_desc1->_ATObjectKey, (* _IG_incl34));

} else {
;
}
;
/*SPC(3054)*/
_currn->_ATAcceleratorRegion_post=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_ATPtg=
((EQ(_currn->_ATOutput, 1)
) ? (
((OR(AND(InIS(Variable, GetKindSet(_currn->_desc1->_ATUnitKey, NullIS())), GE(GetNumberOfDims(_currn->_desc1->_ATObjectKey, 0), 1)), AND(InIS(Array, GetKindSet(_currn->_desc1->_ATUnitKey, NullIS())), AND(EQ((* _IG_incl29), 0), EQ((* _IG_incl33), 1))))
) ? (PTGArraySpec(_currn->_desc1->_ATPtg, _currn->_ATbounds_RuleAttr_1370)
) : (_currn->_desc1->_ATPtg))

) : (PTGNULL))
;
/*SPC(4227)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_896(_TPPrule_896 _currn)
#else
void _VS1rule_896(_currn )
_TPPrule_896 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATOrder_post=_currn->_desc1->_ATOrder_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_896(_TPPrule_896 _currn)
#else
void _VS2rule_896(_currn )
_TPPrule_896 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATLastNonExecLine_post=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc1->_ATArgCnt_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_896(_TPPrule_896 _currn)
#else
void _VS3rule_896(_currn )
_TPPrule_896 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_896(_TPPrule_896 _currn)
#else
void _VS4rule_896(_currn )
_TPPrule_896 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATIsArray_post=_currn->_desc1->_ATIsArray_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5rule_896(_TPPrule_896 _currn)
#else
void _VS5rule_896(_currn )
_TPPrule_896 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_cBoundsListPtr_post=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_ATUpperValue=_currn->_desc1->_ATValue;
/*SPC(3041)*/
_currn->_ATLowerValue=MakeName("1");
/*SPC(3040)*/
_currn->_ATSizeValue=_currn->_desc1->_ATValue;
/*SPC(3039)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS6rule_896(_TPPrule_896 _currn)
#else
void _VS6rule_896(_currn )
_TPPrule_896 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS6MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATTypeLength_post=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS7rule_896(_TPPrule_896 _currn)
#else
void _VS7rule_896(_currn )
_TPPrule_896 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_desc1->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS7MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_const49=_currn->_desc1->_AT_const49;
/*SPC(3038)*/
_currn->_ATDoAcc_post=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc1->_ATArrayId_post;
/*SPC(0)*/
_currn->_ATPtg=PTGArrayDim(_currn->_desc1->_ATPtg);
/*SPC(4361)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_897(_TPPrule_897 _currn)
#else
void _VS1rule_897(_currn )
_TPPrule_897 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATOrder_pre=_currn->_desc1->_ATOrder_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATOrder_post=_currn->_desc2->_ATOrder_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_897(_TPPrule_897 _currn)
#else
void _VS2rule_897(_currn )
_TPPrule_897 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATLastNonExecLine_pre=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_desc2->_ATArgCnt_pre=_currn->_desc1->_ATArgCnt_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATLastNonExecLine_post=_currn->_desc2->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc2->_ATArgCnt_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_897(_TPPrule_897 _currn)
#else
void _VS3rule_897(_currn )
_TPPrule_897 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_897(_TPPrule_897 _currn)
#else
void _VS4rule_897(_currn )
_TPPrule_897 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATIsArray_pre=_currn->_desc1->_ATIsArray_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATIsArray_post=_currn->_desc2->_ATIsArray_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5rule_897(_TPPrule_897 _currn)
#else
void _VS5rule_897(_currn )
_TPPrule_897 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_AT_cBoundsListPtr_pre=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_AT_cBoundsListPtr_post=_currn->_desc2->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_ATUpperValue=_currn->_desc2->_ATValue;
/*SPC(3022)*/
_currn->_ATLowerValue=_currn->_desc1->_ATValue;
/*SPC(3021)*/
_currn->_ATSizeValue=MakeName(CatStrStr(CatStrStr(CatStrStr(StringTable(_currn->_desc2->_ATValue), "-("), StringTable(_currn->_desc1->_ATValue)), ")+1"));
/*SPC(3023)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS6rule_897(_TPPrule_897 _currn)
#else
void _VS6rule_897(_currn )
_TPPrule_897 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS6MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATTypeLength_pre=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS6MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATTypeLength_post=_currn->_desc2->_ATTypeLength_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS7rule_897(_TPPrule_897 _currn)
#else
void _VS7rule_897(_currn )
_TPPrule_897 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_desc1->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS7MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATDoAcc_pre=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_desc2->_ATStmtNumber_pre=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATUpdate_pre=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_desc2->_ATAccDoLoopDim_pre=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_desc2->_ATNestLevel_pre=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_desc2->_ATCPURegionNumber_pre=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATAccRegionNumber_pre=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATAcceleratorRegion_pre=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_desc2->_ATIndentLevel_pre=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_desc2->_ATLocalIndex_pre=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_desc2->_ATArrayId_pre=_currn->_desc1->_ATArrayId_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS7MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_AT_const49=ADD(_currn->_desc1->_AT_const49, _currn->_desc2->_AT_const49);
/*SPC(3020)*/
_currn->_ATDoAcc_post=_currn->_desc2->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc2->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc2->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc2->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc2->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc2->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc2->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc2->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc2->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc2->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc2->_ATArrayId_post;
/*SPC(0)*/
_currn->_ATPtg=PTGArrayDimSize(_currn->_desc2->_ATPtg, _currn->_desc1->_ATPtg);
/*SPC(4365)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_898(_TPPrule_898 _currn)
#else
void _VS1rule_898(_currn )
_TPPrule_898 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATOrder_post=_currn->_ATOrder_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_898(_TPPrule_898 _currn)
#else
void _VS2rule_898(_currn )
_TPPrule_898 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATLastNonExecLine_post=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_ATArgCnt_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_898(_TPPrule_898 _currn)
#else
void _VS4rule_898(_currn )
_TPPrule_898 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATIsArray_post=_currn->_ATIsArray_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5rule_898(_TPPrule_898 _currn)
#else
void _VS5rule_898(_currn )
_TPPrule_898 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_AT_cBoundsListPtr_post=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_ATLowerValue=MakeName("1");
/*SPC(3014)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS6rule_898(_TPPrule_898 _currn)
#else
void _VS6rule_898(_currn )
_TPPrule_898 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATTypeLength_post=_currn->_ATTypeLength_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS7rule_898(_TPPrule_898 _currn)
#else
void _VS7rule_898(_currn )
_TPPrule_898 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_AT_const49=ZERO();
/*SPC(3013)*/
_currn->_ATDoAcc_post=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_ATArrayId_pre;
/*SPC(0)*/
_currn->_ATDynamicSize=1;
/*SPC(10948)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_899(_TPPrule_899 _currn)
#else
void _VS1rule_899(_currn )
_TPPrule_899 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATOrder_post=_currn->_desc1->_ATOrder_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_899(_TPPrule_899 _currn)
#else
void _VS2rule_899(_currn )
_TPPrule_899 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATLastNonExecLine_post=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc1->_ATArgCnt_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_899(_TPPrule_899 _currn)
#else
void _VS3rule_899(_currn )
_TPPrule_899 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_899(_TPPrule_899 _currn)
#else
void _VS4rule_899(_currn )
_TPPrule_899 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATIsArray_post=_currn->_desc1->_ATIsArray_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5rule_899(_TPPrule_899 _currn)
#else
void _VS5rule_899(_currn )
_TPPrule_899 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_cBoundsListPtr_post=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_ATLowerValue=_currn->_desc1->_ATValue;
/*SPC(3011)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS6rule_899(_TPPrule_899 _currn)
#else
void _VS6rule_899(_currn )
_TPPrule_899 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS6MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATTypeLength_post=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS7rule_899(_TPPrule_899 _currn)
#else
void _VS7rule_899(_currn )
_TPPrule_899 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_desc1->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS7MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_const49=_currn->_desc1->_AT_const49;
/*SPC(3010)*/
_currn->_ATDoAcc_post=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc1->_ATArrayId_post;
/*SPC(0)*/
_currn->_ATDynamicSize=1;
/*SPC(10948)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_900(_TPPrule_900 _currn)
#else
void _VS1rule_900(_currn )
_TPPrule_900 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc2->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATOrder_post=_currn->_desc2->_ATOrder_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_900(_TPPrule_900 _currn)
#else
void _VS2rule_900(_currn )
_TPPrule_900 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc2->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATLastNonExecLine_post=_currn->_desc2->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc2->_ATArgCnt_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_900(_TPPrule_900 _currn)
#else
void _VS3rule_900(_currn )
_TPPrule_900 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_desc2->_ATObjectId=_currn->_desc1->_ATObjectKey;
/*SPC(2948)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATIsArray_post=_currn->_desc2->_ATIsArray_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_900(_TPPrule_900 _currn)
#else
void _VS4rule_900(_currn )
_TPPrule_900 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_desc2->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc2->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc2->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc2->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc2->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_desc2->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc2->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc2->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc2->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc2->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_desc2->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS6MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATDoAcc_post=_currn->_desc2->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc2->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc2->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc2->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc2->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc2->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc2->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc2->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc2->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc2->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc2->_ATArrayId_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_desc2->_ATTypeLength_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_901(_TPPrule_901 _currn)
#else
void _VS1rule_901(_currn )
_TPPrule_901 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
AddLookupEntry(StringTable(_currn->_ATTERM_1), StringTable(GetClpValue(FileName, 0)));
/*SPC(2918)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_902(_TPPrule_902 _currn)
#else
void _VS1rule_902(_currn )
_TPPrule_902 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATUnitBind=BindIdn((* _IG_incl11), _currn->_ATSym);
/*SPC(11047)*/
_currn->_ATUnitKey=KeyOf(_currn->_ATUnitBind);
/*SPC(11049)*/
GuaranteeType(_currn->_ATUnitKey, DefaultType(_currn->_ATSym));
/*SPC(873)*/
message(WARNING, "Language construct not currently supported at this time.", 0, (&( _currn->_AT_pos)));
/*SPC(2913)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_902(_TPPrule_902 _currn)
#else
void _VS2rule_902(_currn )
_TPPrule_902 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATBind=BindingInEnv((* _IG_incl10), _currn->_ATSym);
/*SPC(11195)*/

if (DisjIS(ConsIS(Constant, ConsIS(IntrinsicFunction, ConsIS(InExternalStmt, ConsIS(Array, ConsIS(Subroutine, ConsIS(MainProgram, ConsIS(BlockDataSubprogram, ConsIS(ExternalFunction, ConsIS(StatementFunction, NullIS()))))))))), GetKindSet(_currn->_ATUnitKey, NullIS()))) {
InsertKindSet(_currn->_ATUnitKey, Variable);

} else {
}
;
/*SPC(2506)*/
_currn->_ATKey=KeyOf(_currn->_ATBind);
/*SPC(11199)*/
_currn->_ATCoord=(&( _currn->_AT_pos));
/*SPC(2251)*/
_currn->_ATObjectKey=
((_currn->_ATKey
) ? (_currn->_ATKey
) : (_currn->_ATUnitKey))
;
/*SPC(2155)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_903(_TPPrule_903 _currn)
#else
void _VS1rule_903(_currn )
_TPPrule_903 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
message(WARNING, "Language construct not currently supported at this time.", 0, (&( _currn->_AT_pos)));
/*SPC(2910)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_903(_TPPrule_903 _currn)
#else
void _VS2rule_903(_currn )
_TPPrule_903 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_903(_TPPrule_903 _currn)
#else
void _VS3rule_903(_currn )
_TPPrule_903 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_904(_TPPrule_904 _currn)
#else
void _VS1rule_904(_currn )
_TPPrule_904 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
message(WARNING, "Language construct not currently supported at this time.", 0, (&( _currn->_AT_pos)));
/*SPC(2907)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_905(_TPPrule_905 _currn)
#else
void _VS2rule_905(_currn )
_TPPrule_905 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_905(_TPPrule_905 _currn)
#else
void _VS3rule_905(_currn )
_TPPrule_905 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_906(_TPPrule_906 _currn)
#else
void _VS1rule_906(_currn )
_TPPrule_906 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_906(_TPPrule_906 _currn)
#else
void _VS2rule_906(_currn )
_TPPrule_906 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_906(_TPPrule_906 _currn)
#else
void _VS3rule_906(_currn )
_TPPrule_906 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_906(_TPPrule_906 _currn)
#else
void _VS4rule_906(_currn )
_TPPrule_906 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_cBoundsListPtr_post=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_ATDoAcc_post=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_907(_TPPrule_907 _currn)
#else
void _VS1rule_907(_currn )
_TPPrule_907 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_907(_TPPrule_907 _currn)
#else
void _VS2rule_907(_currn )
_TPPrule_907 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_907(_TPPrule_907 _currn)
#else
void _VS3rule_907(_currn )
_TPPrule_907 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_907(_TPPrule_907 _currn)
#else
void _VS4rule_907(_currn )
_TPPrule_907 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_AT_cBoundsListPtr_post=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_ATDoAcc_post=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_ATNestLevel_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_908(_TPPrule_908 _currn)
#else
void _VS1rule_908(_currn )
_TPPrule_908 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();

if (EQ(strcmp(MapFile(_currn->_AT_line), StringTable(GetClpValue(FileName, 0))), 0)) {
PTGOut(PTGRemove(PTGNumb(MapLine(_currn->_AT_line))));

} else {
}
;
/*SPC(6885)*/

if (EQ(strcmp(MapFile(_currn->_AT_line), StringTable(GetClpValue(FileName, 0))), 0)) {
message(NOTE, "Use construct ONLY clause is not supported and was ignored.", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(6879)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);
_currn->_ATOrder_post=_currn->_ATOrder_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_908(_TPPrule_908 _currn)
#else
void _VS2rule_908(_currn )
_TPPrule_908 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATExecutable=0;
/*SPC(998)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATTypeLength_pre=0;
/*SPC(3558)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATLastNonExecLine_pre=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);
_currn->_ATLastNonExecLine_post=_currn->_desc2->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_ATArgCnt_pre;
/*SPC(0)*/
_currn->_ATIsArray_post=0;
/*SPC(6291)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_908(_TPPrule_908 _currn)
#else
void _VS3rule_908(_currn )
_TPPrule_908 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5rule_908(_TPPrule_908 _currn)
#else
void _VS5rule_908(_currn )
_TPPrule_908 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_AT_BoundsauxList=NULLBoundsList;
/*SPC(11354)*/
_currn->_desc1->_AT_cBoundsListPtr_pre=_BoundsListADDROF(_currn->_AT_BoundsauxList);
/*SPC(11355)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATLocalIndex_pre=0;
/*SPC(6408)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_AT_cBoundsListPtr_pre=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_desc2->_ATLocalIndex_pre=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS6MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

if (EQ(strcmp(MapFile(((_currn->_AT_pos).line)), StringTable(GetClpValue(FileName, 0))), 0)) {
PTGOut(PTGInclude(_currn->_desc2->_ATPtg));

} else {
}
;
/*SPC(6882)*/
_currn->_AT_const19=PTGNull();
/*SPC(2896)*/
_currn->_AT_const20=PTGNull();
/*SPC(2896)*/
_currn->_AT_const21=PTGNull();
/*SPC(2896)*/
_currn->_AT_const26=ZERO();
/*SPC(2896)*/
_currn->_AT_const27=PTGNull();
/*SPC(2896)*/
_currn->_AT_const28=PTGNull();
/*SPC(2896)*/
_currn->_AT_const29=PTGNull();
/*SPC(2896)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS6rule_908(_TPPrule_908 _currn)
#else
void _VS6rule_908(_currn )
_TPPrule_908 _currn;

#endif
{
int* _IL_incl23;

_VisitVarDecl()
_VisitEntry();
_IL_incl23=_IG_incl23;_IG_incl23= &(_currn->_ATAllocateStmt);
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS6MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS7MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=0;
/*SPC(10694)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS8MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATNumArgs=0;
/*SPC(9886)*/
_currn->_desc2->_ATDoAcc_pre=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_desc2->_ATAccDoLoopDim_pre=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_desc2->_ATNestLevel_pre=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS7MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_desc2->_ATLoopBoundDim=0;
/*SPC(10605)*/
_currn->_desc2->_ATignoreVar=1;
/*SPC(4504)*/
_currn->_desc2->_ATStmtNumber_pre=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATUpdate_pre=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_desc2->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc2->_ATAccRegionNumber_pre=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc2->_ATIndentLevel_pre=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS8MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_desc3->_AT_cBoundsListPtr_pre=_currn->_desc2->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_desc3->_ATDoAcc_pre=_currn->_desc2->_ATDoAcc_post;
/*SPC(0)*/
_currn->_desc3->_ATStmtNumber_pre=_currn->_desc2->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_desc3->_ATAccDoLoopDim_pre=_currn->_desc2->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_desc3->_ATNestLevel_pre=_currn->_desc2->_ATNestLevel_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);
_currn->_AT_cBoundsListPtr_post=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_ATArrayId_post=NoKey;
/*SPC(6295)*/
_currn->_ATAllocateStmt=0;
/*SPC(3800)*/
_currn->_ATAccDoType_post=_currn->_ATAccDoType_pre;
/*SPC(0)*/
_currn->_ATAccDoStmt_post=_currn->_ATAccDoStmt_pre;
/*SPC(0)*/
_currn->_ATKernelNumber_post=_currn->_ATKernelNumber_pre;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc2->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATMaxRank_post=_currn->_ATMaxRank_pre;
/*SPC(0)*/
_currn->_ATCount_post=_currn->_ATCount_pre;
/*SPC(0)*/
_currn->_ATPtg=PTGNULL;
/*SPC(9695)*/
_currn->_ATBoundsList=_currn->_AT_BoundsauxList;
/*SPC(11356)*/
_currn->_ATDoAcc_post=_currn->_desc3->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=ADD(_currn->_desc3->_ATStmtNumber_post, 1);
/*SPC(10742)*/
_currn->_ATUpdate_post=_currn->_desc2->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=
((AND(EQ(ZERO(), 0), GE(GetAccNest(_currn->_desc3->_ATDoAcc_post, 2, _currn->_desc3->_ATNestLevel_post, 0), 1))
) ? (0
) : (_currn->_desc3->_ATAccDoLoopDim_post))
;
/*SPC(10553)*/
_currn->_ATNestLevel_post=_currn->_desc3->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc2->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc2->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc2->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc2->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/
_IG_incl23=_IL_incl23;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_909(_TPPrule_909 _currn)
#else
void _VS1rule_909(_currn )
_TPPrule_909 _currn;

#endif
{
int* _IL_incl42;
int* _IL_incl40;
int* _IL_incl33;
int* _IL_incl32;
int* _IL_incl27;
int* _IL_incl26;
int* _IL_incl23;
int* _IL_incl22;
KindSetElement* _IL_incl19;
Environment* _IL_incl10;
Environment* _IL_incl11;
int* _IL_incl3;
int* _IL_incl2;
int* _IL_incl0;

_VisitVarDecl()
_VisitEntry();
_IL_incl42=_IG_incl42;_IG_incl42= &(_currn->_ATFalse);
_IL_incl40=_IG_incl40;_IG_incl40= &(_currn->_ATFalse);
_IL_incl33=_IG_incl33;_IG_incl33= &(_currn->_ATFalse);
_IL_incl32=_IG_incl32;_IG_incl32= &(_currn->_ATFalse);
_IL_incl27=_IG_incl27;_IG_incl27= &(_currn->_ATFalse);
_IL_incl26=_IG_incl26;_IG_incl26= &(_currn->_ATFalse);
_IL_incl23=_IG_incl23;_IG_incl23= &(_currn->_ATFalse);
_IL_incl22=_IG_incl22;_IG_incl22= &(_currn->_ATFalse);
_IL_incl19=_IG_incl19;_IG_incl19= &(_currn->_ATKind);
_IL_incl10=_IG_incl10;_IG_incl10= &(_currn->_ATEnv);
_IL_incl11=_IG_incl11;_IG_incl11= &(_currn->_ATUnitEnv);
_IL_incl3=_IG_incl3;_IG_incl3= &(_currn->_ATFalse);
_IL_incl2=_IG_incl2;_IG_incl2= &(_currn->_ATFalse);
_IL_incl0=_IG_incl0;_IG_incl0= &(_currn->_ATFalse);
DefaultImplicitTypes();
/*SPC(864)*/
_currn->_desc1->_ATOrder_pre=0;
/*SPC(461)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_desc1->_ATLastNonExecLine_pre=MapLine(_currn->_AT_line);
/*SPC(9808)*/
_currn->_desc1->_ATArgCnt_pre=0;
/*SPC(6553)*/
_currn->_desc1->_ATIsArray_pre=0;
/*SPC(6290)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATFalse=0;
/*SPC(2608)*/
_currn->_ATKind=BlockDataSubprogram;
/*SPC(2398)*/
_IG_incl42=_IL_incl42;
_IG_incl40=_IL_incl40;
_IG_incl33=_IL_incl33;
_IG_incl32=_IL_incl32;
_IG_incl27=_IL_incl27;
_IG_incl26=_IL_incl26;
_IG_incl23=_IL_incl23;
_IG_incl22=_IL_incl22;
_IG_incl19=_IL_incl19;
_IG_incl10=_IL_incl10;
_IG_incl11=_IL_incl11;
_IG_incl3=_IL_incl3;
_IG_incl2=_IL_incl2;
_IG_incl0=_IL_incl0;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_909(_TPPrule_909 _currn)
#else
void _VS2rule_909(_currn )
_TPPrule_909 _currn;

#endif
{
int* _IL_incl42;
int* _IL_incl40;
int* _IL_incl33;
int* _IL_incl32;
int* _IL_incl27;
int* _IL_incl26;
int* _IL_incl23;
int* _IL_incl22;
KindSetElement* _IL_incl19;
Environment* _IL_incl10;
Environment* _IL_incl11;
int* _IL_incl3;
int* _IL_incl2;
int* _IL_incl0;

_VisitVarDecl()
_VisitEntry();
_IL_incl42=_IG_incl42;_IG_incl42= &(_currn->_ATFalse);
_IL_incl40=_IG_incl40;_IG_incl40= &(_currn->_ATFalse);
_IL_incl33=_IG_incl33;_IG_incl33= &(_currn->_ATFalse);
_IL_incl32=_IG_incl32;_IG_incl32= &(_currn->_ATFalse);
_IL_incl27=_IG_incl27;_IG_incl27= &(_currn->_ATFalse);
_IL_incl26=_IG_incl26;_IG_incl26= &(_currn->_ATFalse);
_IL_incl23=_IG_incl23;_IG_incl23= &(_currn->_ATFalse);
_IL_incl22=_IG_incl22;_IG_incl22= &(_currn->_ATFalse);
_IL_incl19=_IG_incl19;_IG_incl19= &(_currn->_ATKind);
_IL_incl10=_IG_incl10;_IG_incl10= &(_currn->_ATEnv);
_IL_incl11=_IG_incl11;_IG_incl11= &(_currn->_ATUnitEnv);
_IL_incl3=_IG_incl3;_IG_incl3= &(_currn->_ATFalse);
_IL_incl2=_IG_incl2;_IG_incl2= &(_currn->_ATFalse);
_IL_incl0=_IG_incl0;_IG_incl0= &(_currn->_ATFalse);
_IG_incl42=_IL_incl42;
_IG_incl40=_IL_incl40;
_IG_incl33=_IL_incl33;
_IG_incl32=_IL_incl32;
_IG_incl27=_IL_incl27;
_IG_incl26=_IL_incl26;
_IG_incl23=_IL_incl23;
_IG_incl22=_IL_incl22;
_IG_incl19=_IL_incl19;
_IG_incl10=_IL_incl10;
_IG_incl11=_IL_incl11;
_IG_incl3=_IL_incl3;
_IG_incl2=_IL_incl2;
_IG_incl0=_IL_incl0;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_909(_TPPrule_909 _currn)
#else
void _VS3rule_909(_currn )
_TPPrule_909 _currn;

#endif
{
int* _IL_incl42;
int* _IL_incl40;
int* _IL_incl33;
int* _IL_incl32;
int* _IL_incl27;
int* _IL_incl26;
int* _IL_incl23;
int* _IL_incl22;
KindSetElement* _IL_incl19;
Environment* _IL_incl10;
Environment* _IL_incl11;
int* _IL_incl3;
int* _IL_incl2;
int* _IL_incl0;

_VisitVarDecl()
_VisitEntry();
_IL_incl42=_IG_incl42;_IG_incl42= &(_currn->_ATFalse);
_IL_incl40=_IG_incl40;_IG_incl40= &(_currn->_ATFalse);
_IL_incl33=_IG_incl33;_IG_incl33= &(_currn->_ATFalse);
_IL_incl32=_IG_incl32;_IG_incl32= &(_currn->_ATFalse);
_IL_incl27=_IG_incl27;_IG_incl27= &(_currn->_ATFalse);
_IL_incl26=_IG_incl26;_IG_incl26= &(_currn->_ATFalse);
_IL_incl23=_IG_incl23;_IG_incl23= &(_currn->_ATFalse);
_IL_incl22=_IG_incl22;_IG_incl22= &(_currn->_ATFalse);
_IL_incl19=_IG_incl19;_IG_incl19= &(_currn->_ATKind);
_IL_incl10=_IG_incl10;_IG_incl10= &(_currn->_ATEnv);
_IL_incl11=_IG_incl11;_IG_incl11= &(_currn->_ATUnitEnv);
_IL_incl3=_IG_incl3;_IG_incl3= &(_currn->_ATFalse);
_IL_incl2=_IG_incl2;_IG_incl2= &(_currn->_ATFalse);
_IL_incl0=_IG_incl0;_IG_incl0= &(_currn->_ATFalse);
_currn->_AT_const19=PTGNull();
/*SPC(2397)*/
_currn->_AT_const20=PTGNull();
/*SPC(2397)*/
_currn->_AT_const21=PTGNull();
/*SPC(2397)*/
_currn->_AT_const27=PTGNull();
/*SPC(2397)*/
_currn->_AT_const28=PTGNull();
/*SPC(2397)*/
_currn->_AT_const29=PTGNull();
/*SPC(2397)*/
_IG_incl42=_IL_incl42;
_IG_incl40=_IL_incl40;
_IG_incl33=_IL_incl33;
_IG_incl32=_IL_incl32;
_IG_incl27=_IL_incl27;
_IG_incl26=_IL_incl26;
_IG_incl23=_IL_incl23;
_IG_incl22=_IL_incl22;
_IG_incl19=_IL_incl19;
_IG_incl10=_IL_incl10;
_IG_incl11=_IL_incl11;
_IG_incl3=_IL_incl3;
_IG_incl2=_IL_incl2;
_IG_incl0=_IL_incl0;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_909(_TPPrule_909 _currn)
#else
void _VS4rule_909(_currn )
_TPPrule_909 _currn;

#endif
{
int* _IL_incl42;
int* _IL_incl40;
PTGNode* _IL_incl37;
int* _IL_incl36;
int* _IL_incl35;
BoundsList* _IL_incl34;
int* _IL_incl33;
int* _IL_incl32;
int* _IL_incl27;
int* _IL_incl26;
int* _IL_incl23;
int* _IL_incl22;
KindSetElement* _IL_incl19;
Environment* _IL_incl10;
Environment* _IL_incl11;
PTGNode* _IL_incl6;
PTGNode* _IL_incl9;
PTGNode* _IL_incl8;
PTGNode* _IL_incl7;
PTGNode* _IL_incl5;
int* _IL_incl4;
int* _IL_incl3;
int* _IL_incl2;
int* _IL_incl0;

_VisitVarDecl()
_VisitEntry();
_IL_incl42=_IG_incl42;_IG_incl42= &(_currn->_ATFalse);
_IL_incl40=_IG_incl40;_IG_incl40= &(_currn->_ATFalse);
_IL_incl37=_IG_incl37;_IG_incl37= &(_currn->_ATProgramScalarDeRef);
_IL_incl36=_IG_incl36;_IG_incl36= &(_currn->_ATProgramLineNum);
_IL_incl35=_IG_incl35;_IG_incl35= &(_currn->_ATIntent);
_IL_incl34=_IG_incl34;_IG_incl34= &(_currn->_ATBoundsList);
_IL_incl33=_IG_incl33;_IG_incl33= &(_currn->_ATFalse);
_IL_incl32=_IG_incl32;_IG_incl32= &(_currn->_ATFalse);
_IL_incl27=_IG_incl27;_IG_incl27= &(_currn->_ATFalse);
_IL_incl26=_IG_incl26;_IG_incl26= &(_currn->_ATFalse);
_IL_incl23=_IG_incl23;_IG_incl23= &(_currn->_ATFalse);
_IL_incl22=_IG_incl22;_IG_incl22= &(_currn->_ATFalse);
_IL_incl19=_IG_incl19;_IG_incl19= &(_currn->_ATKind);
_IL_incl10=_IG_incl10;_IG_incl10= &(_currn->_ATEnv);
_IL_incl11=_IG_incl11;_IG_incl11= &(_currn->_ATUnitEnv);
_IL_incl6=_IG_incl6;_IG_incl6= &(_currn->_ATProgramArgs);
_IL_incl9=_IG_incl9;_IG_incl9= &(_currn->_ATProgramArgsPtg);
_IL_incl8=_IG_incl8;_IG_incl8= &(_currn->_ATProgramArgsIn);
_IL_incl7=_IG_incl7;_IG_incl7= &(_currn->_ATProgramName);
_IL_incl5=_IG_incl5;_IG_incl5= &(_currn->_ATProgramArgsOut);
_IL_incl4=_IG_incl4;_IG_incl4= &(_currn->_ATNumKernels);
_IL_incl3=_IG_incl3;_IG_incl3= &(_currn->_ATFalse);
_IL_incl2=_IG_incl2;_IG_incl2= &(_currn->_ATFalse);
_IL_incl0=_IG_incl0;_IG_incl0= &(_currn->_ATFalse);
_currn->_AT_BoundsauxList=NULLBoundsList;
/*SPC(11354)*/
_currn->_desc1->_AT_cBoundsListPtr_pre=_BoundsListADDROF(_currn->_AT_BoundsauxList);
/*SPC(11355)*/
_currn->_desc1->_ATDoAcc_pre=InitAccDo();
/*SPC(10765)*/
_currn->_desc1->_ATAccDoType_pre=0;
/*SPC(10749)*/
_currn->_desc1->_ATAccDoStmt_pre=0;
/*SPC(10745)*/
_currn->_desc1->_ATStmtNumber_pre=0;
/*SPC(10741)*/
_currn->_desc1->_ATUpdate_pre=0;
/*SPC(10691)*/
_currn->_desc1->_ATAccDoLoopDim_pre=0;
/*SPC(10551)*/
_currn->_desc1->_ATKernelNumber_pre=0;
/*SPC(10396)*/
_currn->_desc1->_ATNestLevel_pre=0;
/*SPC(10197)*/
_currn->_desc1->_ATCPURegionNumber_pre=0;
/*SPC(9863)*/
_currn->_desc1->_ATAccRegionNumber_pre=0;
/*SPC(9861)*/
_currn->_desc1->_ATAcceleratorRegion_pre=0;
/*SPC(9859)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATLocalIndex_pre=0;
/*SPC(6407)*/
_currn->_desc1->_ATArrayId_pre=NoKey;
/*SPC(6294)*/
_currn->_desc1->_ATMaxRank_pre=0;
/*SPC(5930)*/
_currn->_desc1->_ATCount_pre=0;
/*SPC(4221)*/
_currn->_desc1->_ATTypeLength_pre=0;
/*SPC(3557)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_AT_cBoundsListPtr_pre=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_desc2->_ATDoAcc_pre=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_desc2->_ATStmtNumber_pre=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATUpdate_pre=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_desc2->_ATAccDoLoopDim_pre=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_desc2->_ATNestLevel_pre=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_desc2->_ATAccRegionNumber_pre=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATLastNonExecLine_pre=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_desc2->_ATIndentLevel_pre=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_desc2->_ATLocalIndex_pre=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_desc2->_ATTypeLength_pre=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATNumKernels=ZERO();
/*SPC(10383)*/
_currn->_ATProgramArgsIn=PTGKernelCopyArgs(PTGNull());
/*SPC(10269)*/
_currn->_ATProgramArgsPtg=PTGNull();
/*SPC(10266)*/
_currn->_ATProgramArgs=PTGNull();
/*SPC(10263)*/
_currn->_ATProgramName=PTGNull();
/*SPC(10260)*/
_currn->_ATProgramScalarDeRef=PTGNull();
/*SPC(10281)*/
_currn->_ATProgramArgsOut=PTGKernelFreeArgs(PTGNull());
/*SPC(10275)*/
_currn->_ATProgramLineNum=0;
/*SPC(3661)*/
_currn->_ATIntent=2;
/*SPC(3610)*/
_currn->_ATBoundsList=NULLBoundsList;
/*SPC(2952)*/
_currn->_ATIndentLevel_post=_currn->_desc2->_ATIndentLevel_post;
/*SPC(0)*/
_IG_incl42=_IL_incl42;
_IG_incl40=_IL_incl40;
_IG_incl37=_IL_incl37;
_IG_incl36=_IL_incl36;
_IG_incl35=_IL_incl35;
_IG_incl34=_IL_incl34;
_IG_incl33=_IL_incl33;
_IG_incl32=_IL_incl32;
_IG_incl27=_IL_incl27;
_IG_incl26=_IL_incl26;
_IG_incl23=_IL_incl23;
_IG_incl22=_IL_incl22;
_IG_incl19=_IL_incl19;
_IG_incl10=_IL_incl10;
_IG_incl11=_IL_incl11;
_IG_incl6=_IL_incl6;
_IG_incl9=_IL_incl9;
_IG_incl8=_IL_incl8;
_IG_incl7=_IL_incl7;
_IG_incl5=_IL_incl5;
_IG_incl4=_IL_incl4;
_IG_incl3=_IL_incl3;
_IG_incl2=_IL_incl2;
_IG_incl0=_IL_incl0;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_910(_TPPrule_910 _currn)
#else
void _VS1rule_910(_currn )
_TPPrule_910 _currn;

#endif
{
int* _IL_incl42;
int* _IL_incl40;
int* _IL_incl33;
int* _IL_incl32;
int* _IL_incl27;
int* _IL_incl26;
int* _IL_incl23;
int* _IL_incl22;
KindSetElement* _IL_incl19;
Environment* _IL_incl10;
Environment* _IL_incl11;
int* _IL_incl3;
int* _IL_incl2;
int* _IL_incl0;

_VisitVarDecl()
_VisitEntry();
_IL_incl42=_IG_incl42;_IG_incl42= &(_currn->_ATFalse);
_IL_incl40=_IG_incl40;_IG_incl40= &(_currn->_ATFalse);
_IL_incl33=_IG_incl33;_IG_incl33= &(_currn->_ATFalse);
_IL_incl32=_IG_incl32;_IG_incl32= &(_currn->_ATFalse);
_IL_incl27=_IG_incl27;_IG_incl27= &(_currn->_ATFalse);
_IL_incl26=_IG_incl26;_IG_incl26= &(_currn->_ATFalse);
_IL_incl23=_IG_incl23;_IG_incl23= &(_currn->_ATFalse);
_IL_incl22=_IG_incl22;_IG_incl22= &(_currn->_ATFalse);
_IL_incl19=_IG_incl19;_IG_incl19= &(_currn->_ATKind);
_IL_incl10=_IG_incl10;_IG_incl10= &(_currn->_ATEnv);
_IL_incl11=_IG_incl11;_IG_incl11= &(_currn->_ATUnitEnv);
_IL_incl3=_IG_incl3;_IG_incl3= &(_currn->_ATFalse);
_IL_incl2=_IG_incl2;_IG_incl2= &(_currn->_ATFalse);
_IL_incl0=_IG_incl0;_IG_incl0= &(_currn->_ATFalse);
DefaultImplicitTypes();
/*SPC(864)*/
_currn->_desc1->_ATOrder_pre=0;
/*SPC(461)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATFalse=0;
/*SPC(2608)*/
_currn->_ATKind=BlockDataSubprogram;
/*SPC(2394)*/
_currn->_desc2->_ATOrder_pre=_currn->_desc1->_ATOrder_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);
_currn->_desc1->_ATLastNonExecLine_pre=MapLine(_currn->_AT_line);
/*SPC(9808)*/
_currn->_desc1->_ATArgCnt_pre=0;
/*SPC(6553)*/
_currn->_desc1->_ATIsArray_pre=0;
/*SPC(6290)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATLastNonExecLine_pre=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_desc2->_ATArgCnt_pre=_currn->_desc1->_ATArgCnt_post;
/*SPC(0)*/
_currn->_desc2->_ATIsArray_pre=_currn->_desc1->_ATIsArray_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);
_IG_incl42=_IL_incl42;
_IG_incl40=_IL_incl40;
_IG_incl33=_IL_incl33;
_IG_incl32=_IL_incl32;
_IG_incl27=_IL_incl27;
_IG_incl26=_IL_incl26;
_IG_incl23=_IL_incl23;
_IG_incl22=_IL_incl22;
_IG_incl19=_IL_incl19;
_IG_incl10=_IL_incl10;
_IG_incl11=_IL_incl11;
_IG_incl3=_IL_incl3;
_IG_incl2=_IL_incl2;
_IG_incl0=_IL_incl0;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_910(_TPPrule_910 _currn)
#else
void _VS2rule_910(_currn )
_TPPrule_910 _currn;

#endif
{
int* _IL_incl42;
int* _IL_incl40;
int* _IL_incl33;
int* _IL_incl32;
int* _IL_incl27;
int* _IL_incl26;
int* _IL_incl23;
int* _IL_incl22;
KindSetElement* _IL_incl19;
Environment* _IL_incl10;
Environment* _IL_incl11;
int* _IL_incl3;
int* _IL_incl2;
int* _IL_incl0;

_VisitVarDecl()
_VisitEntry();
_IL_incl42=_IG_incl42;_IG_incl42= &(_currn->_ATFalse);
_IL_incl40=_IG_incl40;_IG_incl40= &(_currn->_ATFalse);
_IL_incl33=_IG_incl33;_IG_incl33= &(_currn->_ATFalse);
_IL_incl32=_IG_incl32;_IG_incl32= &(_currn->_ATFalse);
_IL_incl27=_IG_incl27;_IG_incl27= &(_currn->_ATFalse);
_IL_incl26=_IG_incl26;_IG_incl26= &(_currn->_ATFalse);
_IL_incl23=_IG_incl23;_IG_incl23= &(_currn->_ATFalse);
_IL_incl22=_IG_incl22;_IG_incl22= &(_currn->_ATFalse);
_IL_incl19=_IG_incl19;_IG_incl19= &(_currn->_ATKind);
_IL_incl10=_IG_incl10;_IG_incl10= &(_currn->_ATEnv);
_IL_incl11=_IG_incl11;_IG_incl11= &(_currn->_ATUnitEnv);
_IL_incl3=_IG_incl3;_IG_incl3= &(_currn->_ATFalse);
_IL_incl2=_IG_incl2;_IG_incl2= &(_currn->_ATFalse);
_IL_incl0=_IG_incl0;_IG_incl0= &(_currn->_ATFalse);
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_IG_incl42=_IL_incl42;
_IG_incl40=_IL_incl40;
_IG_incl33=_IL_incl33;
_IG_incl32=_IL_incl32;
_IG_incl27=_IL_incl27;
_IG_incl26=_IL_incl26;
_IG_incl23=_IL_incl23;
_IG_incl22=_IL_incl22;
_IG_incl19=_IL_incl19;
_IG_incl10=_IL_incl10;
_IG_incl11=_IL_incl11;
_IG_incl3=_IL_incl3;
_IG_incl2=_IL_incl2;
_IG_incl0=_IL_incl0;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_910(_TPPrule_910 _currn)
#else
void _VS3rule_910(_currn )
_TPPrule_910 _currn;

#endif
{
int* _IL_incl42;
int* _IL_incl40;
int* _IL_incl33;
int* _IL_incl32;
int* _IL_incl27;
int* _IL_incl26;
int* _IL_incl23;
int* _IL_incl22;
KindSetElement* _IL_incl19;
Environment* _IL_incl10;
Environment* _IL_incl11;
int* _IL_incl3;
int* _IL_incl2;
int* _IL_incl0;

_VisitVarDecl()
_VisitEntry();
_IL_incl42=_IG_incl42;_IG_incl42= &(_currn->_ATFalse);
_IL_incl40=_IG_incl40;_IG_incl40= &(_currn->_ATFalse);
_IL_incl33=_IG_incl33;_IG_incl33= &(_currn->_ATFalse);
_IL_incl32=_IG_incl32;_IG_incl32= &(_currn->_ATFalse);
_IL_incl27=_IG_incl27;_IG_incl27= &(_currn->_ATFalse);
_IL_incl26=_IG_incl26;_IG_incl26= &(_currn->_ATFalse);
_IL_incl23=_IG_incl23;_IG_incl23= &(_currn->_ATFalse);
_IL_incl22=_IG_incl22;_IG_incl22= &(_currn->_ATFalse);
_IL_incl19=_IG_incl19;_IG_incl19= &(_currn->_ATKind);
_IL_incl10=_IG_incl10;_IG_incl10= &(_currn->_ATEnv);
_IL_incl11=_IG_incl11;_IG_incl11= &(_currn->_ATUnitEnv);
_IL_incl3=_IG_incl3;_IG_incl3= &(_currn->_ATFalse);
_IL_incl2=_IG_incl2;_IG_incl2= &(_currn->_ATFalse);
_IL_incl0=_IG_incl0;_IG_incl0= &(_currn->_ATFalse);
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_AT_const19=_currn->_desc2->_AT_const19;
/*SPC(2393)*/
_currn->_AT_const20=_currn->_desc2->_AT_const20;
/*SPC(2393)*/
_currn->_AT_const21=_currn->_desc2->_AT_const21;
/*SPC(2393)*/
_currn->_AT_const27=_currn->_desc2->_AT_const27;
/*SPC(2393)*/
_currn->_AT_const28=_currn->_desc2->_AT_const28;
/*SPC(2393)*/
_currn->_AT_const29=_currn->_desc2->_AT_const29;
/*SPC(2393)*/
_IG_incl42=_IL_incl42;
_IG_incl40=_IL_incl40;
_IG_incl33=_IL_incl33;
_IG_incl32=_IL_incl32;
_IG_incl27=_IL_incl27;
_IG_incl26=_IL_incl26;
_IG_incl23=_IL_incl23;
_IG_incl22=_IL_incl22;
_IG_incl19=_IL_incl19;
_IG_incl10=_IL_incl10;
_IG_incl11=_IL_incl11;
_IG_incl3=_IL_incl3;
_IG_incl2=_IL_incl2;
_IG_incl0=_IL_incl0;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_910(_TPPrule_910 _currn)
#else
void _VS4rule_910(_currn )
_TPPrule_910 _currn;

#endif
{
int* _IL_incl42;
int* _IL_incl40;
PTGNode* _IL_incl37;
int* _IL_incl36;
int* _IL_incl35;
BoundsList* _IL_incl34;
int* _IL_incl33;
int* _IL_incl32;
int* _IL_incl27;
int* _IL_incl26;
int* _IL_incl23;
int* _IL_incl22;
KindSetElement* _IL_incl19;
Environment* _IL_incl10;
Environment* _IL_incl11;
PTGNode* _IL_incl6;
PTGNode* _IL_incl9;
PTGNode* _IL_incl8;
PTGNode* _IL_incl7;
PTGNode* _IL_incl5;
int* _IL_incl4;
int* _IL_incl3;
int* _IL_incl2;
int* _IL_incl0;

_VisitVarDecl()
_VisitEntry();
_IL_incl42=_IG_incl42;_IG_incl42= &(_currn->_ATFalse);
_IL_incl40=_IG_incl40;_IG_incl40= &(_currn->_ATFalse);
_IL_incl37=_IG_incl37;_IG_incl37= &(_currn->_ATProgramScalarDeRef);
_IL_incl36=_IG_incl36;_IG_incl36= &(_currn->_ATProgramLineNum);
_IL_incl35=_IG_incl35;_IG_incl35= &(_currn->_ATIntent);
_IL_incl34=_IG_incl34;_IG_incl34= &(_currn->_ATBoundsList);
_IL_incl33=_IG_incl33;_IG_incl33= &(_currn->_ATFalse);
_IL_incl32=_IG_incl32;_IG_incl32= &(_currn->_ATFalse);
_IL_incl27=_IG_incl27;_IG_incl27= &(_currn->_ATFalse);
_IL_incl26=_IG_incl26;_IG_incl26= &(_currn->_ATFalse);
_IL_incl23=_IG_incl23;_IG_incl23= &(_currn->_ATFalse);
_IL_incl22=_IG_incl22;_IG_incl22= &(_currn->_ATFalse);
_IL_incl19=_IG_incl19;_IG_incl19= &(_currn->_ATKind);
_IL_incl10=_IG_incl10;_IG_incl10= &(_currn->_ATEnv);
_IL_incl11=_IG_incl11;_IG_incl11= &(_currn->_ATUnitEnv);
_IL_incl6=_IG_incl6;_IG_incl6= &(_currn->_ATProgramArgs);
_IL_incl9=_IG_incl9;_IG_incl9= &(_currn->_ATProgramArgsPtg);
_IL_incl8=_IG_incl8;_IG_incl8= &(_currn->_ATProgramArgsIn);
_IL_incl7=_IG_incl7;_IG_incl7= &(_currn->_ATProgramName);
_IL_incl5=_IG_incl5;_IG_incl5= &(_currn->_ATProgramArgsOut);
_IL_incl4=_IG_incl4;_IG_incl4= &(_currn->_ATNumKernels);
_IL_incl3=_IG_incl3;_IG_incl3= &(_currn->_ATFalse);
_IL_incl2=_IG_incl2;_IG_incl2= &(_currn->_ATFalse);
_IL_incl0=_IG_incl0;_IG_incl0= &(_currn->_ATFalse);
_currn->_AT_BoundsauxList=NULLBoundsList;
/*SPC(11354)*/
_currn->_desc1->_AT_cBoundsListPtr_pre=_BoundsListADDROF(_currn->_AT_BoundsauxList);
/*SPC(11355)*/
_currn->_desc1->_ATDoAcc_pre=InitAccDo();
/*SPC(10765)*/
_currn->_desc1->_ATAccDoType_pre=0;
/*SPC(10749)*/
_currn->_desc1->_ATAccDoStmt_pre=0;
/*SPC(10745)*/
_currn->_desc1->_ATStmtNumber_pre=0;
/*SPC(10741)*/
_currn->_desc1->_ATUpdate_pre=0;
/*SPC(10691)*/
_currn->_desc1->_ATAccDoLoopDim_pre=0;
/*SPC(10551)*/
_currn->_desc1->_ATKernelNumber_pre=0;
/*SPC(10396)*/
_currn->_desc1->_ATNestLevel_pre=0;
/*SPC(10197)*/
_currn->_desc1->_ATCPURegionNumber_pre=0;
/*SPC(9863)*/
_currn->_desc1->_ATAccRegionNumber_pre=0;
/*SPC(9861)*/
_currn->_desc1->_ATAcceleratorRegion_pre=0;
/*SPC(9859)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATLocalIndex_pre=0;
/*SPC(6407)*/
_currn->_desc1->_ATArrayId_pre=NoKey;
/*SPC(6294)*/
_currn->_desc1->_ATMaxRank_pre=0;
/*SPC(5930)*/
_currn->_desc1->_ATCount_pre=0;
/*SPC(4221)*/
_currn->_desc1->_ATTypeLength_pre=0;
/*SPC(3557)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATNumKernels=_currn->_desc2->_AT_const26;
/*SPC(10383)*/
_currn->_ATProgramArgsIn=PTGKernelCopyArgs(_currn->_desc2->_AT_const19);
/*SPC(10269)*/
_currn->_ATProgramArgsPtg=_currn->_desc2->_AT_const27;
/*SPC(10266)*/
_currn->_ATProgramArgs=_currn->_desc2->_AT_const28;
/*SPC(10263)*/
_currn->_ATProgramName=_currn->_desc2->_AT_const29;
/*SPC(10260)*/
_currn->_ATProgramScalarDeRef=_currn->_desc2->_AT_const21;
/*SPC(10281)*/
_currn->_ATProgramArgsOut=PTGKernelFreeArgs(_currn->_desc2->_AT_const20);
/*SPC(10275)*/
_currn->_ATProgramLineNum=0;
/*SPC(3661)*/
_currn->_desc2->_AT_cBoundsListPtr_pre=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_desc2->_ATDoAcc_pre=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_desc2->_ATAccDoType_pre=_currn->_desc1->_ATAccDoType_post;
/*SPC(0)*/
_currn->_desc2->_ATAccDoStmt_pre=_currn->_desc1->_ATAccDoStmt_post;
/*SPC(0)*/
_currn->_desc2->_ATStmtNumber_pre=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATUpdate_pre=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_desc2->_ATAccDoLoopDim_pre=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_desc2->_ATKernelNumber_pre=_currn->_desc1->_ATKernelNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATNestLevel_pre=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_desc2->_ATCPURegionNumber_pre=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATAccRegionNumber_pre=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATAcceleratorRegion_pre=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_desc2->_ATIndentLevel_pre=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_desc2->_ATLocalIndex_pre=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_desc2->_ATArrayId_pre=_currn->_desc1->_ATArrayId_post;
/*SPC(0)*/
_currn->_desc2->_ATMaxRank_pre=_currn->_desc1->_ATMaxRank_post;
/*SPC(0)*/
_currn->_desc2->_ATCount_pre=_currn->_desc1->_ATCount_post;
/*SPC(0)*/
_currn->_desc2->_ATTypeLength_pre=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS6MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_desc3->_AT_cBoundsListPtr_pre=_currn->_desc2->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_desc3->_ATDoAcc_pre=_currn->_desc2->_ATDoAcc_post;
/*SPC(0)*/
_currn->_desc3->_ATStmtNumber_pre=_currn->_desc2->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_desc3->_ATUpdate_pre=_currn->_desc2->_ATUpdate_post;
/*SPC(0)*/
_currn->_desc3->_ATAccDoLoopDim_pre=_currn->_desc2->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_desc3->_ATNestLevel_pre=_currn->_desc2->_ATNestLevel_post;
/*SPC(0)*/
_currn->_desc3->_ATAccRegionNumber_pre=_currn->_desc2->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_desc3->_ATLastNonExecLine_pre=_currn->_desc2->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_desc3->_ATIndentLevel_pre=_currn->_desc2->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_desc3->_ATLocalIndex_pre=_currn->_desc2->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_desc3->_ATTypeLength_pre=_currn->_desc2->_ATTypeLength_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);
_currn->_ATIndentLevel_post=_currn->_desc3->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATIntent=2;
/*SPC(3610)*/
_currn->_ATBoundsList=NULLBoundsList;
/*SPC(2952)*/
_IG_incl42=_IL_incl42;
_IG_incl40=_IL_incl40;
_IG_incl37=_IL_incl37;
_IG_incl36=_IL_incl36;
_IG_incl35=_IL_incl35;
_IG_incl34=_IL_incl34;
_IG_incl33=_IL_incl33;
_IG_incl32=_IL_incl32;
_IG_incl27=_IL_incl27;
_IG_incl26=_IL_incl26;
_IG_incl23=_IL_incl23;
_IG_incl22=_IL_incl22;
_IG_incl19=_IL_incl19;
_IG_incl10=_IL_incl10;
_IG_incl11=_IL_incl11;
_IG_incl6=_IL_incl6;
_IG_incl9=_IL_incl9;
_IG_incl8=_IL_incl8;
_IG_incl7=_IL_incl7;
_IG_incl5=_IL_incl5;
_IG_incl4=_IL_incl4;
_IG_incl3=_IL_incl3;
_IG_incl2=_IL_incl2;
_IG_incl0=_IL_incl0;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_911(_TPPrule_911 _currn)
#else
void _VS1rule_911(_currn )
_TPPrule_911 _currn;

#endif
{
int* _IL_incl42;
int* _IL_incl40;
int* _IL_incl33;
int* _IL_incl32;
int* _IL_incl27;
int* _IL_incl26;
int* _IL_incl23;
int* _IL_incl22;
KindSetElement* _IL_incl19;
Environment* _IL_incl10;
Environment* _IL_incl11;
int* _IL_incl3;
int* _IL_incl2;
int* _IL_incl0;

_VisitVarDecl()
_VisitEntry();
_IL_incl42=_IG_incl42;_IG_incl42= &(_currn->_ATFalse);
_IL_incl40=_IG_incl40;_IG_incl40= &(_currn->_ATFalse);
_IL_incl33=_IG_incl33;_IG_incl33= &(_currn->_ATFalse);
_IL_incl32=_IG_incl32;_IG_incl32= &(_currn->_ATFalse);
_IL_incl27=_IG_incl27;_IG_incl27= &(_currn->_ATFalse);
_IL_incl26=_IG_incl26;_IG_incl26= &(_currn->_ATFalse);
_IL_incl23=_IG_incl23;_IG_incl23= &(_currn->_ATFalse);
_IL_incl22=_IG_incl22;_IG_incl22= &(_currn->_ATFalse);
_IL_incl19=_IG_incl19;_IG_incl19= &(_currn->_ATKind);
_IL_incl10=_IG_incl10;_IG_incl10= &(_currn->_ATEnv);
_IL_incl11=_IG_incl11;_IG_incl11= &(_currn->_ATUnitEnv);
_IL_incl3=_IG_incl3;_IG_incl3= &(_currn->_ATFalse);
_IL_incl2=_IG_incl2;_IG_incl2= &(_currn->_ATFalse);
_IL_incl0=_IG_incl0;_IG_incl0= &(_currn->_ATFalse);
_currn->_ATFalse=0;
/*SPC(2608)*/
_currn->_ATKind=MainProgram;
/*SPC(2385)*/
DefaultImplicitTypes();
/*SPC(864)*/
_currn->_desc1->_ATOrder_pre=0;
/*SPC(461)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATLastNonExecLine_pre=MapLine(_currn->_AT_line);
/*SPC(9808)*/
_currn->_desc1->_ATArgCnt_pre=0;
/*SPC(6553)*/
_currn->_desc1->_ATIsArray_pre=0;
/*SPC(6290)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_IG_incl42=_IL_incl42;
_IG_incl40=_IL_incl40;
_IG_incl33=_IL_incl33;
_IG_incl32=_IL_incl32;
_IG_incl27=_IL_incl27;
_IG_incl26=_IL_incl26;
_IG_incl23=_IL_incl23;
_IG_incl22=_IL_incl22;
_IG_incl19=_IL_incl19;
_IG_incl10=_IL_incl10;
_IG_incl11=_IL_incl11;
_IG_incl3=_IL_incl3;
_IG_incl2=_IL_incl2;
_IG_incl0=_IL_incl0;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_911(_TPPrule_911 _currn)
#else
void _VS2rule_911(_currn )
_TPPrule_911 _currn;

#endif
{
int* _IL_incl42;
int* _IL_incl40;
int* _IL_incl33;
int* _IL_incl32;
int* _IL_incl27;
int* _IL_incl26;
int* _IL_incl23;
int* _IL_incl22;
KindSetElement* _IL_incl19;
Environment* _IL_incl10;
Environment* _IL_incl11;
int* _IL_incl3;
int* _IL_incl2;
int* _IL_incl0;

_VisitVarDecl()
_VisitEntry();
_IL_incl42=_IG_incl42;_IG_incl42= &(_currn->_ATFalse);
_IL_incl40=_IG_incl40;_IG_incl40= &(_currn->_ATFalse);
_IL_incl33=_IG_incl33;_IG_incl33= &(_currn->_ATFalse);
_IL_incl32=_IG_incl32;_IG_incl32= &(_currn->_ATFalse);
_IL_incl27=_IG_incl27;_IG_incl27= &(_currn->_ATFalse);
_IL_incl26=_IG_incl26;_IG_incl26= &(_currn->_ATFalse);
_IL_incl23=_IG_incl23;_IG_incl23= &(_currn->_ATFalse);
_IL_incl22=_IG_incl22;_IG_incl22= &(_currn->_ATFalse);
_IL_incl19=_IG_incl19;_IG_incl19= &(_currn->_ATKind);
_IL_incl10=_IG_incl10;_IG_incl10= &(_currn->_ATEnv);
_IL_incl11=_IG_incl11;_IG_incl11= &(_currn->_ATUnitEnv);
_IL_incl3=_IG_incl3;_IG_incl3= &(_currn->_ATFalse);
_IL_incl2=_IG_incl2;_IG_incl2= &(_currn->_ATFalse);
_IL_incl0=_IG_incl0;_IG_incl0= &(_currn->_ATFalse);
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_IG_incl42=_IL_incl42;
_IG_incl40=_IL_incl40;
_IG_incl33=_IL_incl33;
_IG_incl32=_IL_incl32;
_IG_incl27=_IL_incl27;
_IG_incl26=_IL_incl26;
_IG_incl23=_IL_incl23;
_IG_incl22=_IL_incl22;
_IG_incl19=_IL_incl19;
_IG_incl10=_IL_incl10;
_IG_incl11=_IL_incl11;
_IG_incl3=_IL_incl3;
_IG_incl2=_IL_incl2;
_IG_incl0=_IL_incl0;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_911(_TPPrule_911 _currn)
#else
void _VS3rule_911(_currn )
_TPPrule_911 _currn;

#endif
{
int* _IL_incl42;
int* _IL_incl40;
int* _IL_incl33;
int* _IL_incl32;
int* _IL_incl27;
int* _IL_incl26;
int* _IL_incl23;
int* _IL_incl22;
KindSetElement* _IL_incl19;
Environment* _IL_incl10;
Environment* _IL_incl11;
int* _IL_incl3;
int* _IL_incl2;
int* _IL_incl0;

_VisitVarDecl()
_VisitEntry();
_IL_incl42=_IG_incl42;_IG_incl42= &(_currn->_ATFalse);
_IL_incl40=_IG_incl40;_IG_incl40= &(_currn->_ATFalse);
_IL_incl33=_IG_incl33;_IG_incl33= &(_currn->_ATFalse);
_IL_incl32=_IG_incl32;_IG_incl32= &(_currn->_ATFalse);
_IL_incl27=_IG_incl27;_IG_incl27= &(_currn->_ATFalse);
_IL_incl26=_IG_incl26;_IG_incl26= &(_currn->_ATFalse);
_IL_incl23=_IG_incl23;_IG_incl23= &(_currn->_ATFalse);
_IL_incl22=_IG_incl22;_IG_incl22= &(_currn->_ATFalse);
_IL_incl19=_IG_incl19;_IG_incl19= &(_currn->_ATKind);
_IL_incl10=_IG_incl10;_IG_incl10= &(_currn->_ATEnv);
_IL_incl11=_IG_incl11;_IG_incl11= &(_currn->_ATUnitEnv);
_IL_incl3=_IG_incl3;_IG_incl3= &(_currn->_ATFalse);
_IL_incl2=_IG_incl2;_IG_incl2= &(_currn->_ATFalse);
_IL_incl0=_IG_incl0;_IG_incl0= &(_currn->_ATFalse);
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_const19=_currn->_desc1->_AT_const19;
/*SPC(2384)*/
_currn->_AT_const20=_currn->_desc1->_AT_const20;
/*SPC(2384)*/
_currn->_AT_const21=_currn->_desc1->_AT_const21;
/*SPC(2384)*/
_currn->_AT_const27=_currn->_desc1->_AT_const27;
/*SPC(2384)*/
_currn->_AT_const28=_currn->_desc1->_AT_const28;
/*SPC(2384)*/
_currn->_AT_const29=_currn->_desc1->_AT_const29;
/*SPC(2384)*/
_IG_incl42=_IL_incl42;
_IG_incl40=_IL_incl40;
_IG_incl33=_IL_incl33;
_IG_incl32=_IL_incl32;
_IG_incl27=_IL_incl27;
_IG_incl26=_IL_incl26;
_IG_incl23=_IL_incl23;
_IG_incl22=_IL_incl22;
_IG_incl19=_IL_incl19;
_IG_incl10=_IL_incl10;
_IG_incl11=_IL_incl11;
_IG_incl3=_IL_incl3;
_IG_incl2=_IL_incl2;
_IG_incl0=_IL_incl0;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_911(_TPPrule_911 _currn)
#else
void _VS4rule_911(_currn )
_TPPrule_911 _currn;

#endif
{
int* _IL_incl42;
int* _IL_incl40;
PTGNode* _IL_incl37;
int* _IL_incl36;
int* _IL_incl35;
BoundsList* _IL_incl34;
int* _IL_incl33;
int* _IL_incl32;
int* _IL_incl27;
int* _IL_incl26;
int* _IL_incl23;
int* _IL_incl22;
KindSetElement* _IL_incl19;
Environment* _IL_incl10;
Environment* _IL_incl11;
PTGNode* _IL_incl6;
PTGNode* _IL_incl9;
PTGNode* _IL_incl8;
PTGNode* _IL_incl7;
PTGNode* _IL_incl5;
int* _IL_incl4;
int* _IL_incl3;
int* _IL_incl2;
int* _IL_incl0;

_VisitVarDecl()
_VisitEntry();
_IL_incl42=_IG_incl42;_IG_incl42= &(_currn->_ATFalse);
_IL_incl40=_IG_incl40;_IG_incl40= &(_currn->_ATFalse);
_IL_incl37=_IG_incl37;_IG_incl37= &(_currn->_ATProgramScalarDeRef);
_IL_incl36=_IG_incl36;_IG_incl36= &(_currn->_ATProgramLineNum);
_IL_incl35=_IG_incl35;_IG_incl35= &(_currn->_ATIntent);
_IL_incl34=_IG_incl34;_IG_incl34= &(_currn->_ATBoundsList);
_IL_incl33=_IG_incl33;_IG_incl33= &(_currn->_ATFalse);
_IL_incl32=_IG_incl32;_IG_incl32= &(_currn->_ATFalse);
_IL_incl27=_IG_incl27;_IG_incl27= &(_currn->_ATFalse);
_IL_incl26=_IG_incl26;_IG_incl26= &(_currn->_ATFalse);
_IL_incl23=_IG_incl23;_IG_incl23= &(_currn->_ATFalse);
_IL_incl22=_IG_incl22;_IG_incl22= &(_currn->_ATFalse);
_IL_incl19=_IG_incl19;_IG_incl19= &(_currn->_ATKind);
_IL_incl10=_IG_incl10;_IG_incl10= &(_currn->_ATEnv);
_IL_incl11=_IG_incl11;_IG_incl11= &(_currn->_ATUnitEnv);
_IL_incl6=_IG_incl6;_IG_incl6= &(_currn->_ATProgramArgs);
_IL_incl9=_IG_incl9;_IG_incl9= &(_currn->_ATProgramArgsPtg);
_IL_incl8=_IG_incl8;_IG_incl8= &(_currn->_ATProgramArgsIn);
_IL_incl7=_IG_incl7;_IG_incl7= &(_currn->_ATProgramName);
_IL_incl5=_IG_incl5;_IG_incl5= &(_currn->_ATProgramArgsOut);
_IL_incl4=_IG_incl4;_IG_incl4= &(_currn->_ATNumKernels);
_IL_incl3=_IG_incl3;_IG_incl3= &(_currn->_ATFalse);
_IL_incl2=_IG_incl2;_IG_incl2= &(_currn->_ATFalse);
_IL_incl0=_IG_incl0;_IG_incl0= &(_currn->_ATFalse);
_currn->_AT_BoundsauxList=NULLBoundsList;
/*SPC(11354)*/
_currn->_ATNumKernels=_currn->_desc1->_AT_const26;
/*SPC(10383)*/
_currn->_ATProgramArgsIn=PTGKernelCopyArgs(_currn->_desc1->_AT_const19);
/*SPC(10269)*/
_currn->_ATProgramArgsPtg=_currn->_desc1->_AT_const27;
/*SPC(10266)*/
_currn->_ATProgramArgs=_currn->_desc1->_AT_const28;
/*SPC(10263)*/
_currn->_ATProgramName=_currn->_desc1->_AT_const29;
/*SPC(10260)*/
_currn->_ATProgramScalarDeRef=_currn->_desc1->_AT_const21;
/*SPC(10281)*/
_currn->_ATProgramArgsOut=PTGKernelFreeArgs(_currn->_desc1->_AT_const20);
/*SPC(10275)*/
_currn->_ATProgramLineNum=0;
/*SPC(3661)*/
_currn->_desc1->_AT_cBoundsListPtr_pre=_BoundsListADDROF(_currn->_AT_BoundsauxList);
/*SPC(11355)*/
_currn->_desc1->_ATDoAcc_pre=InitAccDo();
/*SPC(10765)*/
_currn->_desc1->_ATAccDoType_pre=0;
/*SPC(10749)*/
_currn->_desc1->_ATAccDoStmt_pre=0;
/*SPC(10745)*/
_currn->_desc1->_ATStmtNumber_pre=0;
/*SPC(10741)*/
_currn->_desc1->_ATUpdate_pre=0;
/*SPC(10691)*/
_currn->_desc1->_ATAccDoLoopDim_pre=0;
/*SPC(10551)*/
_currn->_desc1->_ATKernelNumber_pre=0;
/*SPC(10396)*/
_currn->_desc1->_ATNestLevel_pre=0;
/*SPC(10197)*/
_currn->_desc1->_ATCPURegionNumber_pre=0;
/*SPC(9863)*/
_currn->_desc1->_ATAccRegionNumber_pre=0;
/*SPC(9861)*/
_currn->_desc1->_ATAcceleratorRegion_pre=0;
/*SPC(9859)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATLocalIndex_pre=0;
/*SPC(6407)*/
_currn->_desc1->_ATArrayId_pre=NoKey;
/*SPC(6294)*/
_currn->_desc1->_ATMaxRank_pre=0;
/*SPC(5930)*/
_currn->_desc1->_ATCount_pre=0;
/*SPC(4221)*/
_currn->_desc1->_ATTypeLength_pre=0;
/*SPC(3557)*/
(*(_CALL_VS_((NODEPTR )) (VS6MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATIndentLevel_post=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATIntent=2;
/*SPC(3610)*/
_currn->_ATBoundsList=NULLBoundsList;
/*SPC(2952)*/
_IG_incl42=_IL_incl42;
_IG_incl40=_IL_incl40;
_IG_incl37=_IL_incl37;
_IG_incl36=_IL_incl36;
_IG_incl35=_IL_incl35;
_IG_incl34=_IL_incl34;
_IG_incl33=_IL_incl33;
_IG_incl32=_IL_incl32;
_IG_incl27=_IL_incl27;
_IG_incl26=_IL_incl26;
_IG_incl23=_IL_incl23;
_IG_incl22=_IL_incl22;
_IG_incl19=_IL_incl19;
_IG_incl10=_IL_incl10;
_IG_incl11=_IL_incl11;
_IG_incl6=_IL_incl6;
_IG_incl9=_IL_incl9;
_IG_incl8=_IL_incl8;
_IG_incl7=_IL_incl7;
_IG_incl5=_IL_incl5;
_IG_incl4=_IL_incl4;
_IG_incl3=_IL_incl3;
_IG_incl2=_IL_incl2;
_IG_incl0=_IL_incl0;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_912(_TPPrule_912 _currn)
#else
void _VS1rule_912(_currn )
_TPPrule_912 _currn;

#endif
{
int* _IL_incl42;
int* _IL_incl40;
int* _IL_incl33;
int* _IL_incl32;
int* _IL_incl27;
int* _IL_incl26;
int* _IL_incl23;
int* _IL_incl22;
KindSetElement* _IL_incl19;
Environment* _IL_incl10;
Environment* _IL_incl11;
int* _IL_incl3;
int* _IL_incl2;
int* _IL_incl0;

_VisitVarDecl()
_VisitEntry();
_IL_incl42=_IG_incl42;_IG_incl42= &(_currn->_ATFalse);
_IL_incl40=_IG_incl40;_IG_incl40= &(_currn->_ATFalse);
_IL_incl33=_IG_incl33;_IG_incl33= &(_currn->_ATFalse);
_IL_incl32=_IG_incl32;_IG_incl32= &(_currn->_ATFalse);
_IL_incl27=_IG_incl27;_IG_incl27= &(_currn->_ATFalse);
_IL_incl26=_IG_incl26;_IG_incl26= &(_currn->_ATFalse);
_IL_incl23=_IG_incl23;_IG_incl23= &(_currn->_ATFalse);
_IL_incl22=_IG_incl22;_IG_incl22= &(_currn->_ATFalse);
_IL_incl19=_IG_incl19;_IG_incl19= &(_currn->_ATKind);
_IL_incl10=_IG_incl10;_IG_incl10= &(_currn->_ATEnv);
_IL_incl11=_IG_incl11;_IG_incl11= &(_currn->_ATUnitEnv);
_IL_incl3=_IG_incl3;_IG_incl3= &(_currn->_ATFalse);
_IL_incl2=_IG_incl2;_IG_incl2= &(_currn->_ATFalse);
_IL_incl0=_IG_incl0;_IG_incl0= &(_currn->_ATFalse);
DefaultImplicitTypes();
/*SPC(864)*/
_currn->_desc1->_ATOrder_pre=0;
/*SPC(461)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATFalse=0;
/*SPC(2608)*/
_currn->_ATKind=MainProgram;
/*SPC(2381)*/
_currn->_desc2->_ATOrder_pre=_currn->_desc1->_ATOrder_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_desc1->_ATLastNonExecLine_pre=MapLine(_currn->_AT_line);
/*SPC(9808)*/
_currn->_desc1->_ATArgCnt_pre=0;
/*SPC(6553)*/
_currn->_desc1->_ATIsArray_pre=0;
/*SPC(6290)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATLastNonExecLine_pre=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_desc2->_ATArgCnt_pre=_currn->_desc1->_ATArgCnt_post;
/*SPC(0)*/
_currn->_desc2->_ATIsArray_pre=_currn->_desc1->_ATIsArray_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_IG_incl42=_IL_incl42;
_IG_incl40=_IL_incl40;
_IG_incl33=_IL_incl33;
_IG_incl32=_IL_incl32;
_IG_incl27=_IL_incl27;
_IG_incl26=_IL_incl26;
_IG_incl23=_IL_incl23;
_IG_incl22=_IL_incl22;
_IG_incl19=_IL_incl19;
_IG_incl10=_IL_incl10;
_IG_incl11=_IL_incl11;
_IG_incl3=_IL_incl3;
_IG_incl2=_IL_incl2;
_IG_incl0=_IL_incl0;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_912(_TPPrule_912 _currn)
#else
void _VS2rule_912(_currn )
_TPPrule_912 _currn;

#endif
{
int* _IL_incl42;
int* _IL_incl40;
int* _IL_incl33;
int* _IL_incl32;
int* _IL_incl27;
int* _IL_incl26;
int* _IL_incl23;
int* _IL_incl22;
KindSetElement* _IL_incl19;
Environment* _IL_incl10;
Environment* _IL_incl11;
int* _IL_incl3;
int* _IL_incl2;
int* _IL_incl0;

_VisitVarDecl()
_VisitEntry();
_IL_incl42=_IG_incl42;_IG_incl42= &(_currn->_ATFalse);
_IL_incl40=_IG_incl40;_IG_incl40= &(_currn->_ATFalse);
_IL_incl33=_IG_incl33;_IG_incl33= &(_currn->_ATFalse);
_IL_incl32=_IG_incl32;_IG_incl32= &(_currn->_ATFalse);
_IL_incl27=_IG_incl27;_IG_incl27= &(_currn->_ATFalse);
_IL_incl26=_IG_incl26;_IG_incl26= &(_currn->_ATFalse);
_IL_incl23=_IG_incl23;_IG_incl23= &(_currn->_ATFalse);
_IL_incl22=_IG_incl22;_IG_incl22= &(_currn->_ATFalse);
_IL_incl19=_IG_incl19;_IG_incl19= &(_currn->_ATKind);
_IL_incl10=_IG_incl10;_IG_incl10= &(_currn->_ATEnv);
_IL_incl11=_IG_incl11;_IG_incl11= &(_currn->_ATUnitEnv);
_IL_incl3=_IG_incl3;_IG_incl3= &(_currn->_ATFalse);
_IL_incl2=_IG_incl2;_IG_incl2= &(_currn->_ATFalse);
_IL_incl0=_IG_incl0;_IG_incl0= &(_currn->_ATFalse);
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_IG_incl42=_IL_incl42;
_IG_incl40=_IL_incl40;
_IG_incl33=_IL_incl33;
_IG_incl32=_IL_incl32;
_IG_incl27=_IL_incl27;
_IG_incl26=_IL_incl26;
_IG_incl23=_IL_incl23;
_IG_incl22=_IL_incl22;
_IG_incl19=_IL_incl19;
_IG_incl10=_IL_incl10;
_IG_incl11=_IL_incl11;
_IG_incl3=_IL_incl3;
_IG_incl2=_IL_incl2;
_IG_incl0=_IL_incl0;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_912(_TPPrule_912 _currn)
#else
void _VS3rule_912(_currn )
_TPPrule_912 _currn;

#endif
{
int* _IL_incl42;
int* _IL_incl40;
int* _IL_incl33;
int* _IL_incl32;
int* _IL_incl27;
int* _IL_incl26;
int* _IL_incl23;
int* _IL_incl22;
KindSetElement* _IL_incl19;
Environment* _IL_incl10;
Environment* _IL_incl11;
int* _IL_incl3;
int* _IL_incl2;
int* _IL_incl0;

_VisitVarDecl()
_VisitEntry();
_IL_incl42=_IG_incl42;_IG_incl42= &(_currn->_ATFalse);
_IL_incl40=_IG_incl40;_IG_incl40= &(_currn->_ATFalse);
_IL_incl33=_IG_incl33;_IG_incl33= &(_currn->_ATFalse);
_IL_incl32=_IG_incl32;_IG_incl32= &(_currn->_ATFalse);
_IL_incl27=_IG_incl27;_IG_incl27= &(_currn->_ATFalse);
_IL_incl26=_IG_incl26;_IG_incl26= &(_currn->_ATFalse);
_IL_incl23=_IG_incl23;_IG_incl23= &(_currn->_ATFalse);
_IL_incl22=_IG_incl22;_IG_incl22= &(_currn->_ATFalse);
_IL_incl19=_IG_incl19;_IG_incl19= &(_currn->_ATKind);
_IL_incl10=_IG_incl10;_IG_incl10= &(_currn->_ATEnv);
_IL_incl11=_IG_incl11;_IG_incl11= &(_currn->_ATUnitEnv);
_IL_incl3=_IG_incl3;_IG_incl3= &(_currn->_ATFalse);
_IL_incl2=_IG_incl2;_IG_incl2= &(_currn->_ATFalse);
_IL_incl0=_IG_incl0;_IG_incl0= &(_currn->_ATFalse);
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_AT_const19=_currn->_desc2->_AT_const19;
/*SPC(2380)*/
_currn->_AT_const20=_currn->_desc2->_AT_const20;
/*SPC(2380)*/
_currn->_AT_const21=_currn->_desc2->_AT_const21;
/*SPC(2380)*/
_currn->_AT_const27=_currn->_desc2->_AT_const27;
/*SPC(2380)*/
_currn->_AT_const28=_currn->_desc2->_AT_const28;
/*SPC(2380)*/
_currn->_AT_const29=_currn->_desc2->_AT_const29;
/*SPC(2380)*/
_IG_incl42=_IL_incl42;
_IG_incl40=_IL_incl40;
_IG_incl33=_IL_incl33;
_IG_incl32=_IL_incl32;
_IG_incl27=_IL_incl27;
_IG_incl26=_IL_incl26;
_IG_incl23=_IL_incl23;
_IG_incl22=_IL_incl22;
_IG_incl19=_IL_incl19;
_IG_incl10=_IL_incl10;
_IG_incl11=_IL_incl11;
_IG_incl3=_IL_incl3;
_IG_incl2=_IL_incl2;
_IG_incl0=_IL_incl0;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_912(_TPPrule_912 _currn)
#else
void _VS4rule_912(_currn )
_TPPrule_912 _currn;

#endif
{
int* _IL_incl42;
int* _IL_incl40;
PTGNode* _IL_incl37;
int* _IL_incl36;
int* _IL_incl35;
BoundsList* _IL_incl34;
int* _IL_incl33;
int* _IL_incl32;
int* _IL_incl27;
int* _IL_incl26;
int* _IL_incl23;
int* _IL_incl22;
KindSetElement* _IL_incl19;
Environment* _IL_incl10;
Environment* _IL_incl11;
PTGNode* _IL_incl6;
PTGNode* _IL_incl9;
PTGNode* _IL_incl8;
PTGNode* _IL_incl7;
PTGNode* _IL_incl5;
int* _IL_incl4;
int* _IL_incl3;
int* _IL_incl2;
int* _IL_incl0;

_VisitVarDecl()
_VisitEntry();
_IL_incl42=_IG_incl42;_IG_incl42= &(_currn->_ATFalse);
_IL_incl40=_IG_incl40;_IG_incl40= &(_currn->_ATFalse);
_IL_incl37=_IG_incl37;_IG_incl37= &(_currn->_ATProgramScalarDeRef);
_IL_incl36=_IG_incl36;_IG_incl36= &(_currn->_ATProgramLineNum);
_IL_incl35=_IG_incl35;_IG_incl35= &(_currn->_ATIntent);
_IL_incl34=_IG_incl34;_IG_incl34= &(_currn->_ATBoundsList);
_IL_incl33=_IG_incl33;_IG_incl33= &(_currn->_ATFalse);
_IL_incl32=_IG_incl32;_IG_incl32= &(_currn->_ATFalse);
_IL_incl27=_IG_incl27;_IG_incl27= &(_currn->_ATFalse);
_IL_incl26=_IG_incl26;_IG_incl26= &(_currn->_ATFalse);
_IL_incl23=_IG_incl23;_IG_incl23= &(_currn->_ATFalse);
_IL_incl22=_IG_incl22;_IG_incl22= &(_currn->_ATFalse);
_IL_incl19=_IG_incl19;_IG_incl19= &(_currn->_ATKind);
_IL_incl10=_IG_incl10;_IG_incl10= &(_currn->_ATEnv);
_IL_incl11=_IG_incl11;_IG_incl11= &(_currn->_ATUnitEnv);
_IL_incl6=_IG_incl6;_IG_incl6= &(_currn->_ATProgramArgs);
_IL_incl9=_IG_incl9;_IG_incl9= &(_currn->_ATProgramArgsPtg);
_IL_incl8=_IG_incl8;_IG_incl8= &(_currn->_ATProgramArgsIn);
_IL_incl7=_IG_incl7;_IG_incl7= &(_currn->_ATProgramName);
_IL_incl5=_IG_incl5;_IG_incl5= &(_currn->_ATProgramArgsOut);
_IL_incl4=_IG_incl4;_IG_incl4= &(_currn->_ATNumKernels);
_IL_incl3=_IG_incl3;_IG_incl3= &(_currn->_ATFalse);
_IL_incl2=_IG_incl2;_IG_incl2= &(_currn->_ATFalse);
_IL_incl0=_IG_incl0;_IG_incl0= &(_currn->_ATFalse);
_currn->_AT_BoundsauxList=NULLBoundsList;
/*SPC(11354)*/
_currn->_desc1->_AT_cBoundsListPtr_pre=_BoundsListADDROF(_currn->_AT_BoundsauxList);
/*SPC(11355)*/
_currn->_desc1->_ATDoAcc_pre=InitAccDo();
/*SPC(10765)*/
_currn->_desc1->_ATAccDoType_pre=0;
/*SPC(10749)*/
_currn->_desc1->_ATAccDoStmt_pre=0;
/*SPC(10745)*/
_currn->_desc1->_ATStmtNumber_pre=0;
/*SPC(10741)*/
_currn->_desc1->_ATUpdate_pre=0;
/*SPC(10691)*/
_currn->_desc1->_ATAccDoLoopDim_pre=0;
/*SPC(10551)*/
_currn->_desc1->_ATKernelNumber_pre=0;
/*SPC(10396)*/
_currn->_desc1->_ATNestLevel_pre=0;
/*SPC(10197)*/
_currn->_desc1->_ATCPURegionNumber_pre=0;
/*SPC(9863)*/
_currn->_desc1->_ATAccRegionNumber_pre=0;
/*SPC(9861)*/
_currn->_desc1->_ATAcceleratorRegion_pre=0;
/*SPC(9859)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATLocalIndex_pre=0;
/*SPC(6407)*/
_currn->_desc1->_ATArrayId_pre=NoKey;
/*SPC(6294)*/
_currn->_desc1->_ATMaxRank_pre=0;
/*SPC(5930)*/
_currn->_desc1->_ATCount_pre=0;
/*SPC(4221)*/
_currn->_desc1->_ATTypeLength_pre=0;
/*SPC(3557)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATNumKernels=_currn->_desc2->_AT_const26;
/*SPC(10383)*/
_currn->_ATProgramArgsIn=PTGKernelCopyArgs(_currn->_desc2->_AT_const19);
/*SPC(10269)*/
_currn->_ATProgramArgsPtg=_currn->_desc2->_AT_const27;
/*SPC(10266)*/
_currn->_ATProgramArgs=_currn->_desc2->_AT_const28;
/*SPC(10263)*/
_currn->_ATProgramName=_currn->_desc2->_AT_const29;
/*SPC(10260)*/
_currn->_ATProgramScalarDeRef=_currn->_desc2->_AT_const21;
/*SPC(10281)*/
_currn->_ATProgramArgsOut=PTGKernelFreeArgs(_currn->_desc2->_AT_const20);
/*SPC(10275)*/
_currn->_ATProgramLineNum=0;
/*SPC(3661)*/
_currn->_desc2->_AT_cBoundsListPtr_pre=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_desc2->_ATDoAcc_pre=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_desc2->_ATAccDoType_pre=_currn->_desc1->_ATAccDoType_post;
/*SPC(0)*/
_currn->_desc2->_ATAccDoStmt_pre=_currn->_desc1->_ATAccDoStmt_post;
/*SPC(0)*/
_currn->_desc2->_ATStmtNumber_pre=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATUpdate_pre=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_desc2->_ATAccDoLoopDim_pre=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_desc2->_ATKernelNumber_pre=_currn->_desc1->_ATKernelNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATNestLevel_pre=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_desc2->_ATCPURegionNumber_pre=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATAccRegionNumber_pre=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATAcceleratorRegion_pre=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_desc2->_ATIndentLevel_pre=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_desc2->_ATLocalIndex_pre=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_desc2->_ATArrayId_pre=_currn->_desc1->_ATArrayId_post;
/*SPC(0)*/
_currn->_desc2->_ATMaxRank_pre=_currn->_desc1->_ATMaxRank_post;
/*SPC(0)*/
_currn->_desc2->_ATCount_pre=_currn->_desc1->_ATCount_post;
/*SPC(0)*/
_currn->_desc2->_ATTypeLength_pre=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS6MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATIndentLevel_post=_currn->_desc2->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATIntent=2;
/*SPC(3610)*/
_currn->_ATBoundsList=NULLBoundsList;
/*SPC(2952)*/
_IG_incl42=_IL_incl42;
_IG_incl40=_IL_incl40;
_IG_incl37=_IL_incl37;
_IG_incl36=_IL_incl36;
_IG_incl35=_IL_incl35;
_IG_incl34=_IL_incl34;
_IG_incl33=_IL_incl33;
_IG_incl32=_IL_incl32;
_IG_incl27=_IL_incl27;
_IG_incl26=_IL_incl26;
_IG_incl23=_IL_incl23;
_IG_incl22=_IL_incl22;
_IG_incl19=_IL_incl19;
_IG_incl10=_IL_incl10;
_IG_incl11=_IL_incl11;
_IG_incl6=_IL_incl6;
_IG_incl9=_IL_incl9;
_IG_incl8=_IL_incl8;
_IG_incl7=_IL_incl7;
_IG_incl5=_IL_incl5;
_IG_incl4=_IL_incl4;
_IG_incl3=_IL_incl3;
_IG_incl2=_IL_incl2;
_IG_incl0=_IL_incl0;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_913(_TPPrule_913 _currn)
#else
void _VS1rule_913(_currn )
_TPPrule_913 _currn;

#endif
{
int* _IL_incl42;
int* _IL_incl40;
int* _IL_incl33;
int* _IL_incl32;
int* _IL_incl27;
int* _IL_incl26;
int* _IL_incl23;
int* _IL_incl22;
KindSetElement* _IL_incl19;
Environment* _IL_incl10;
Environment* _IL_incl11;
int* _IL_incl3;
int* _IL_incl2;
int* _IL_incl0;

_VisitVarDecl()
_VisitEntry();
_IL_incl42=_IG_incl42;_IG_incl42= &(_currn->_ATFalse);
_IL_incl40=_IG_incl40;_IG_incl40= &(_currn->_ATFalse);
_IL_incl33=_IG_incl33;_IG_incl33= &(_currn->_ATFalse);
_IL_incl32=_IG_incl32;_IG_incl32= &(_currn->_ATFalse);
_IL_incl27=_IG_incl27;_IG_incl27= &(_currn->_ATFalse);
_IL_incl26=_IG_incl26;_IG_incl26= &(_currn->_ATFalse);
_IL_incl23=_IG_incl23;_IG_incl23= &(_currn->_ATFalse);
_IL_incl22=_IG_incl22;_IG_incl22= &(_currn->_ATFalse);
_IL_incl19=_IG_incl19;_IG_incl19= &(_currn->_ATKind);
_IL_incl10=_IG_incl10;_IG_incl10= &(_currn->_ATEnv);
_IL_incl11=_IG_incl11;_IG_incl11= &(_currn->_ATUnitEnv);
_IL_incl3=_IG_incl3;_IG_incl3= &(_currn->_ATFalse);
_IL_incl2=_IG_incl2;_IG_incl2= &(_currn->_ATFalse);
_IL_incl0=_IG_incl0;_IG_incl0= &(_currn->_ATFalse);
DefaultImplicitTypes();
/*SPC(864)*/
_currn->_desc1->_ATOrder_pre=0;
/*SPC(461)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATFalse=0;
/*SPC(2608)*/
_currn->_ATKind=Subroutine;
/*SPC(2353)*/
_currn->_desc2->_ATOrder_pre=_currn->_desc1->_ATOrder_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_desc1->_ATLastNonExecLine_pre=MapLine(_currn->_AT_line);
/*SPC(9808)*/
_currn->_desc1->_ATArgCnt_pre=0;
/*SPC(6553)*/
_currn->_desc1->_ATIsArray_pre=0;
/*SPC(6290)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATLastNonExecLine_pre=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_desc2->_ATArgCnt_pre=_currn->_desc1->_ATArgCnt_post;
/*SPC(0)*/
_currn->_desc2->_ATIsArray_pre=_currn->_desc1->_ATIsArray_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_IG_incl42=_IL_incl42;
_IG_incl40=_IL_incl40;
_IG_incl33=_IL_incl33;
_IG_incl32=_IL_incl32;
_IG_incl27=_IL_incl27;
_IG_incl26=_IL_incl26;
_IG_incl23=_IL_incl23;
_IG_incl22=_IL_incl22;
_IG_incl19=_IL_incl19;
_IG_incl10=_IL_incl10;
_IG_incl11=_IL_incl11;
_IG_incl3=_IL_incl3;
_IG_incl2=_IL_incl2;
_IG_incl0=_IL_incl0;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_913(_TPPrule_913 _currn)
#else
void _VS2rule_913(_currn )
_TPPrule_913 _currn;

#endif
{
int* _IL_incl42;
int* _IL_incl40;
int* _IL_incl33;
int* _IL_incl32;
int* _IL_incl27;
int* _IL_incl26;
int* _IL_incl23;
int* _IL_incl22;
KindSetElement* _IL_incl19;
Environment* _IL_incl10;
Environment* _IL_incl11;
int* _IL_incl3;
int* _IL_incl2;
int* _IL_incl0;

_VisitVarDecl()
_VisitEntry();
_IL_incl42=_IG_incl42;_IG_incl42= &(_currn->_ATFalse);
_IL_incl40=_IG_incl40;_IG_incl40= &(_currn->_ATFalse);
_IL_incl33=_IG_incl33;_IG_incl33= &(_currn->_ATFalse);
_IL_incl32=_IG_incl32;_IG_incl32= &(_currn->_ATFalse);
_IL_incl27=_IG_incl27;_IG_incl27= &(_currn->_ATFalse);
_IL_incl26=_IG_incl26;_IG_incl26= &(_currn->_ATFalse);
_IL_incl23=_IG_incl23;_IG_incl23= &(_currn->_ATFalse);
_IL_incl22=_IG_incl22;_IG_incl22= &(_currn->_ATFalse);
_IL_incl19=_IG_incl19;_IG_incl19= &(_currn->_ATKind);
_IL_incl10=_IG_incl10;_IG_incl10= &(_currn->_ATEnv);
_IL_incl11=_IG_incl11;_IG_incl11= &(_currn->_ATUnitEnv);
_IL_incl3=_IG_incl3;_IG_incl3= &(_currn->_ATFalse);
_IL_incl2=_IG_incl2;_IG_incl2= &(_currn->_ATFalse);
_IL_incl0=_IG_incl0;_IG_incl0= &(_currn->_ATFalse);
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_IG_incl42=_IL_incl42;
_IG_incl40=_IL_incl40;
_IG_incl33=_IL_incl33;
_IG_incl32=_IL_incl32;
_IG_incl27=_IL_incl27;
_IG_incl26=_IL_incl26;
_IG_incl23=_IL_incl23;
_IG_incl22=_IL_incl22;
_IG_incl19=_IL_incl19;
_IG_incl10=_IL_incl10;
_IG_incl11=_IL_incl11;
_IG_incl3=_IL_incl3;
_IG_incl2=_IL_incl2;
_IG_incl0=_IL_incl0;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_913(_TPPrule_913 _currn)
#else
void _VS3rule_913(_currn )
_TPPrule_913 _currn;

#endif
{
int* _IL_incl42;
int* _IL_incl40;
int* _IL_incl33;
int* _IL_incl32;
int* _IL_incl27;
int* _IL_incl26;
int* _IL_incl23;
int* _IL_incl22;
KindSetElement* _IL_incl19;
Environment* _IL_incl10;
Environment* _IL_incl11;
int* _IL_incl3;
int* _IL_incl2;
int* _IL_incl0;

_VisitVarDecl()
_VisitEntry();
_IL_incl42=_IG_incl42;_IG_incl42= &(_currn->_ATFalse);
_IL_incl40=_IG_incl40;_IG_incl40= &(_currn->_ATFalse);
_IL_incl33=_IG_incl33;_IG_incl33= &(_currn->_ATFalse);
_IL_incl32=_IG_incl32;_IG_incl32= &(_currn->_ATFalse);
_IL_incl27=_IG_incl27;_IG_incl27= &(_currn->_ATFalse);
_IL_incl26=_IG_incl26;_IG_incl26= &(_currn->_ATFalse);
_IL_incl23=_IG_incl23;_IG_incl23= &(_currn->_ATFalse);
_IL_incl22=_IG_incl22;_IG_incl22= &(_currn->_ATFalse);
_IL_incl19=_IG_incl19;_IG_incl19= &(_currn->_ATKind);
_IL_incl10=_IG_incl10;_IG_incl10= &(_currn->_ATEnv);
_IL_incl11=_IG_incl11;_IG_incl11= &(_currn->_ATUnitEnv);
_IL_incl3=_IG_incl3;_IG_incl3= &(_currn->_ATFalse);
_IL_incl2=_IG_incl2;_IG_incl2= &(_currn->_ATFalse);
_IL_incl0=_IG_incl0;_IG_incl0= &(_currn->_ATFalse);
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_AT_const19=PTGSequence(_currn->_desc1->_AT_const19, _currn->_desc2->_AT_const19);
/*SPC(2352)*/
_currn->_AT_const20=PTGSequence(_currn->_desc1->_AT_const20, _currn->_desc2->_AT_const20);
/*SPC(2352)*/
_currn->_AT_const21=PTGSequence(_currn->_desc1->_AT_const21, _currn->_desc2->_AT_const21);
/*SPC(2352)*/
_currn->_AT_const27=PTGSequence(IDENTICAL(_currn->_desc1->_ATProgramArgsPtg), _currn->_desc2->_AT_const27);
/*SPC(2352)*/
_currn->_AT_const28=PTGSequence(IDENTICAL(_currn->_desc1->_ATProgramArgs), _currn->_desc2->_AT_const28);
/*SPC(2352)*/
_currn->_AT_const29=PTGSequence(IDENTICAL(_currn->_desc1->_ATProgramName), _currn->_desc2->_AT_const29);
/*SPC(2352)*/
_IG_incl42=_IL_incl42;
_IG_incl40=_IL_incl40;
_IG_incl33=_IL_incl33;
_IG_incl32=_IL_incl32;
_IG_incl27=_IL_incl27;
_IG_incl26=_IL_incl26;
_IG_incl23=_IL_incl23;
_IG_incl22=_IL_incl22;
_IG_incl19=_IL_incl19;
_IG_incl10=_IL_incl10;
_IG_incl11=_IL_incl11;
_IG_incl3=_IL_incl3;
_IG_incl2=_IL_incl2;
_IG_incl0=_IL_incl0;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_913(_TPPrule_913 _currn)
#else
void _VS4rule_913(_currn )
_TPPrule_913 _currn;

#endif
{
int* _IL_incl42;
int* _IL_incl40;
PTGNode* _IL_incl37;
int* _IL_incl36;
int* _IL_incl35;
BoundsList* _IL_incl34;
int* _IL_incl33;
int* _IL_incl32;
int* _IL_incl27;
int* _IL_incl26;
int* _IL_incl23;
int* _IL_incl22;
KindSetElement* _IL_incl19;
Environment* _IL_incl10;
Environment* _IL_incl11;
PTGNode* _IL_incl6;
PTGNode* _IL_incl9;
PTGNode* _IL_incl8;
PTGNode* _IL_incl7;
PTGNode* _IL_incl5;
int* _IL_incl4;
int* _IL_incl3;
int* _IL_incl2;
int* _IL_incl0;

_VisitVarDecl()
_VisitEntry();
_IL_incl42=_IG_incl42;_IG_incl42= &(_currn->_ATFalse);
_IL_incl40=_IG_incl40;_IG_incl40= &(_currn->_ATFalse);
_IL_incl37=_IG_incl37;_IG_incl37= &(_currn->_ATProgramScalarDeRef);
_IL_incl36=_IG_incl36;_IG_incl36= &(_currn->_ATProgramLineNum);
_IL_incl35=_IG_incl35;_IG_incl35= &(_currn->_ATIntent);
_IL_incl34=_IG_incl34;_IG_incl34= &(_currn->_ATBoundsList);
_IL_incl33=_IG_incl33;_IG_incl33= &(_currn->_ATFalse);
_IL_incl32=_IG_incl32;_IG_incl32= &(_currn->_ATFalse);
_IL_incl27=_IG_incl27;_IG_incl27= &(_currn->_ATFalse);
_IL_incl26=_IG_incl26;_IG_incl26= &(_currn->_ATFalse);
_IL_incl23=_IG_incl23;_IG_incl23= &(_currn->_ATFalse);
_IL_incl22=_IG_incl22;_IG_incl22= &(_currn->_ATFalse);
_IL_incl19=_IG_incl19;_IG_incl19= &(_currn->_ATKind);
_IL_incl10=_IG_incl10;_IG_incl10= &(_currn->_ATEnv);
_IL_incl11=_IG_incl11;_IG_incl11= &(_currn->_ATUnitEnv);
_IL_incl6=_IG_incl6;_IG_incl6= &(_currn->_ATProgramArgs);
_IL_incl9=_IG_incl9;_IG_incl9= &(_currn->_ATProgramArgsPtg);
_IL_incl8=_IG_incl8;_IG_incl8= &(_currn->_ATProgramArgsIn);
_IL_incl7=_IG_incl7;_IG_incl7= &(_currn->_ATProgramName);
_IL_incl5=_IG_incl5;_IG_incl5= &(_currn->_ATProgramArgsOut);
_IL_incl4=_IG_incl4;_IG_incl4= &(_currn->_ATNumKernels);
_IL_incl3=_IG_incl3;_IG_incl3= &(_currn->_ATFalse);
_IL_incl2=_IG_incl2;_IG_incl2= &(_currn->_ATFalse);
_IL_incl0=_IG_incl0;_IG_incl0= &(_currn->_ATFalse);
_currn->_AT_BoundsauxList=NULLBoundsList;
/*SPC(11354)*/
_currn->_desc1->_AT_cBoundsListPtr_pre=_BoundsListADDROF(_currn->_AT_BoundsauxList);
/*SPC(11355)*/
_currn->_desc1->_ATDoAcc_pre=InitAccDo();
/*SPC(10765)*/
_currn->_desc1->_ATAccDoType_pre=0;
/*SPC(10749)*/
_currn->_desc1->_ATAccDoStmt_pre=0;
/*SPC(10745)*/
_currn->_desc1->_ATStmtNumber_pre=0;
/*SPC(10741)*/
_currn->_desc1->_ATUpdate_pre=0;
/*SPC(10691)*/
_currn->_desc1->_ATAccDoLoopDim_pre=0;
/*SPC(10551)*/
_currn->_desc1->_ATKernelNumber_pre=0;
/*SPC(10396)*/
_currn->_desc1->_ATNestLevel_pre=0;
/*SPC(10197)*/
_currn->_desc1->_ATCPURegionNumber_pre=0;
/*SPC(9863)*/
_currn->_desc1->_ATAccRegionNumber_pre=0;
/*SPC(9861)*/
_currn->_desc1->_ATAcceleratorRegion_pre=0;
/*SPC(9859)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATLocalIndex_pre=0;
/*SPC(6407)*/
_currn->_desc1->_ATArrayId_pre=NoKey;
/*SPC(6294)*/
_currn->_desc1->_ATMaxRank_pre=0;
/*SPC(5930)*/
_currn->_desc1->_ATCount_pre=0;
/*SPC(4221)*/
_currn->_desc1->_ATTypeLength_pre=0;
/*SPC(3557)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATNumKernels=_currn->_desc2->_AT_const26;
/*SPC(10383)*/
_currn->_ATProgramArgsIn=PTGKernelCopyArgs(PTGSequence(_currn->_desc1->_AT_const19, _currn->_desc2->_AT_const19));
/*SPC(10269)*/
_currn->_ATProgramArgsPtg=PTGSequence(IDENTICAL(_currn->_desc1->_ATProgramArgsPtg), _currn->_desc2->_AT_const27);
/*SPC(10266)*/
_currn->_ATProgramArgs=PTGSequence(IDENTICAL(_currn->_desc1->_ATProgramArgs), _currn->_desc2->_AT_const28);
/*SPC(10263)*/
_currn->_ATProgramName=PTGSequence(IDENTICAL(_currn->_desc1->_ATProgramName), _currn->_desc2->_AT_const29);
/*SPC(10260)*/
_currn->_ATProgramScalarDeRef=PTGSequence(_currn->_desc1->_AT_const21, _currn->_desc2->_AT_const21);
/*SPC(10281)*/
_currn->_ATProgramArgsOut=PTGKernelFreeArgs(PTGSequence(_currn->_desc1->_AT_const20, _currn->_desc2->_AT_const20));
/*SPC(10275)*/
_currn->_ATProgramLineNum=0;
/*SPC(3661)*/
_currn->_desc2->_AT_cBoundsListPtr_pre=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_desc2->_ATDoAcc_pre=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_desc2->_ATAccDoType_pre=_currn->_desc1->_ATAccDoType_post;
/*SPC(0)*/
_currn->_desc2->_ATAccDoStmt_pre=_currn->_desc1->_ATAccDoStmt_post;
/*SPC(0)*/
_currn->_desc2->_ATStmtNumber_pre=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATUpdate_pre=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_desc2->_ATAccDoLoopDim_pre=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_desc2->_ATKernelNumber_pre=_currn->_desc1->_ATKernelNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATNestLevel_pre=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_desc2->_ATCPURegionNumber_pre=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATAccRegionNumber_pre=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATAcceleratorRegion_pre=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_desc2->_ATIndentLevel_pre=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_desc2->_ATLocalIndex_pre=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_desc2->_ATArrayId_pre=_currn->_desc1->_ATArrayId_post;
/*SPC(0)*/
_currn->_desc2->_ATMaxRank_pre=_currn->_desc1->_ATMaxRank_post;
/*SPC(0)*/
_currn->_desc2->_ATCount_pre=_currn->_desc1->_ATCount_post;
/*SPC(0)*/
_currn->_desc2->_ATTypeLength_pre=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS6MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATIndentLevel_post=_currn->_desc2->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATIntent=2;
/*SPC(3610)*/
_currn->_ATBoundsList=NULLBoundsList;
/*SPC(2952)*/
_IG_incl42=_IL_incl42;
_IG_incl40=_IL_incl40;
_IG_incl37=_IL_incl37;
_IG_incl36=_IL_incl36;
_IG_incl35=_IL_incl35;
_IG_incl34=_IL_incl34;
_IG_incl33=_IL_incl33;
_IG_incl32=_IL_incl32;
_IG_incl27=_IL_incl27;
_IG_incl26=_IL_incl26;
_IG_incl23=_IL_incl23;
_IG_incl22=_IL_incl22;
_IG_incl19=_IL_incl19;
_IG_incl10=_IL_incl10;
_IG_incl11=_IL_incl11;
_IG_incl6=_IL_incl6;
_IG_incl9=_IL_incl9;
_IG_incl8=_IL_incl8;
_IG_incl7=_IL_incl7;
_IG_incl5=_IL_incl5;
_IG_incl4=_IL_incl4;
_IG_incl3=_IL_incl3;
_IG_incl2=_IL_incl2;
_IG_incl0=_IL_incl0;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_914(_TPPrule_914 _currn)
#else
void _VS1rule_914(_currn )
_TPPrule_914 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATOrder_post=_currn->_ATOrder_pre;
/*SPC(0)*/

if (EmptyIS(InterIS(ConsIS(Array, ConsIS(StatementFunction, ConsIS(IntrinsicFunction, ConsIS(Subroutine, NullIS())))), GetKindSet(_currn->_desc1->_ATUnitKey, NullIS())))) {

if (InIS(DummyArgument, GetKindSet(_currn->_desc1->_ATUnitKey, NullIS()))) {
InsertKindSet(_currn->_desc1->_ATUnitKey, DummyProcedure);

} else {
InsertKindSet(_currn->_desc1->_ATUnitKey, ExternalFunction);
}
;

} else {
}
;
/*SPC(2304)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_914(_TPPrule_914 _currn)
#else
void _VS2rule_914(_currn )
_TPPrule_914 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATLastNonExecLine_post=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_ATArgCnt_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_914(_TPPrule_914 _currn)
#else
void _VS3rule_914(_currn )
_TPPrule_914 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_914(_TPPrule_914 _currn)
#else
void _VS4rule_914(_currn )
_TPPrule_914 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATIsArray_post=_currn->_ATIsArray_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5rule_914(_TPPrule_914 _currn)
#else
void _VS5rule_914(_currn )
_TPPrule_914 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_cBoundsListPtr_post=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_ATValue=0;
/*SPC(116)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS6rule_914(_TPPrule_914 _currn)
#else
void _VS6rule_914(_currn )
_TPPrule_914 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATTypeLength_post=_currn->_ATTypeLength_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS7rule_914(_TPPrule_914 _currn)
#else
void _VS7rule_914(_currn )
_TPPrule_914 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS6MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATLocalIndex_post=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS8rule_914(_TPPrule_914 _currn)
#else
void _VS8rule_914(_currn )
_TPPrule_914 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATExpValue=0;
/*SPC(6827)*/
_currn->_ATFunctionName=PTGNULL;
/*SPC(6639)*/
_currn->_ATPtg=PTGAsIs("F2C-ACC: xExpr not supported.");
/*SPC(6600)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS9rule_914(_TPPrule_914 _currn)
#else
void _VS9rule_914(_currn )
_TPPrule_914 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATNumArgs=0;
/*SPC(9886)*/
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS7MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATDoAcc_post=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATLoopIncrNeg=
((EQ(MOD(ZERO(), 2), 1)
) ? (1
) : (0))
;
/*SPC(5862)*/
_currn->_desc1->_ATLoopBoundDim=0;
/*SPC(10605)*/
_currn->_AT_const47=IDENTICAL(_currn->_desc1->_ATLoopBoundDim);
/*SPC(2302)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS10rule_914(_TPPrule_914 _currn)
#else
void _VS10rule_914(_currn )
_TPPrule_914 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATignoreVar=0;
/*SPC(4467)*/
(*(_CALL_VS_((NODEPTR )) (VS8MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_const49=ZERO();
/*SPC(2302)*/
_currn->_AT_const52=ZERO();
/*SPC(2302)*/
_currn->_ATStmtNumber_post=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_ATArrayId_pre;
/*SPC(0)*/
_currn->_ATDynamicSize=0;
/*SPC(10950)*/
_currn->_ATArgType=PTGNULL;
/*SPC(4605)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_915(_TPPrule_915 _currn)
#else
void _VS1rule_915(_currn )
_TPPrule_915 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATOrder_post=_currn->_desc1->_ATOrder_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_915(_TPPrule_915 _currn)
#else
void _VS2rule_915(_currn )
_TPPrule_915 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATLastNonExecLine_post=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc1->_ATArgCnt_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_915(_TPPrule_915 _currn)
#else
void _VS3rule_915(_currn )
_TPPrule_915 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_915(_TPPrule_915 _currn)
#else
void _VS4rule_915(_currn )
_TPPrule_915 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATIsArray_post=_currn->_desc1->_ATIsArray_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5rule_915(_TPPrule_915 _currn)
#else
void _VS5rule_915(_currn )
_TPPrule_915 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATBoundsTakeIt=1;
/*SPC(11376)*/
_currn->_ATBoundsElem=PkgBounds(_currn->_desc1->_ATSizeValue, _currn->_desc1->_ATLowerValue, _currn->_desc1->_ATUpperValue);
/*SPC(3170)*/
_currn->_AT_cBoundsListPtr_post=
((_currn->_ATBoundsTakeIt
) ? (RefEndConsBoundsList(_currn->_desc1->_AT_cBoundsListPtr_post, _currn->_ATBoundsElem)
) : (_currn->_desc1->_AT_cBoundsListPtr_post))
;
/*SPC(11377)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS6rule_915(_TPPrule_915 _currn)
#else
void _VS6rule_915(_currn )
_TPPrule_915 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS6MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATTypeLength_post=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS7rule_915(_TPPrule_915 _currn)
#else
void _VS7rule_915(_currn )
_TPPrule_915 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS7MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATLocalIndex_post=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS8rule_915(_TPPrule_915 _currn)
#else
void _VS8rule_915(_currn )
_TPPrule_915 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATPtg=_currn->_desc1->_ATPtg;
/*SPC(6063)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS9rule_915(_TPPrule_915 _currn)
#else
void _VS9rule_915(_currn )
_TPPrule_915 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS8MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_const47=_currn->_desc1->_AT_const47;
/*SPC(2290)*/
_currn->_ATDoAcc_post=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS10rule_915(_TPPrule_915 _currn)
#else
void _VS10rule_915(_currn )
_TPPrule_915 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS9MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_const49=_currn->_desc1->_AT_const49;
/*SPC(2290)*/
_currn->_AT_const51=IDENTICAL(_currn->_desc1->_ATF90Syntax);
/*SPC(2290)*/
_currn->_AT_const52=ADD(_currn->_desc1->_AT_const52, IDENTICAL(_currn->_desc1->_ATF90Syntax));
/*SPC(2290)*/
_currn->_ATStmtNumber_post=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc1->_ATArrayId_post;
/*SPC(0)*/
_currn->_ATNotCharacterIndex=0;
/*SPC(2292)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_916(_TPPrule_916 _currn)
#else
void _VS1rule_916(_currn )
_TPPrule_916 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATOrder_post=_currn->_desc1->_ATOrder_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_916(_TPPrule_916 _currn)
#else
void _VS2rule_916(_currn )
_TPPrule_916 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATLastNonExecLine_post=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc1->_ATArgCnt_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_916(_TPPrule_916 _currn)
#else
void _VS3rule_916(_currn )
_TPPrule_916 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_916(_TPPrule_916 _currn)
#else
void _VS4rule_916(_currn )
_TPPrule_916 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATIsArray_post=_currn->_desc1->_ATIsArray_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5rule_916(_TPPrule_916 _currn)
#else
void _VS5rule_916(_currn )
_TPPrule_916 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_cBoundsListPtr_post=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS6rule_916(_TPPrule_916 _currn)
#else
void _VS6rule_916(_currn )
_TPPrule_916 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS6MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATTypeLength_post=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS7rule_916(_TPPrule_916 _currn)
#else
void _VS7rule_916(_currn )
_TPPrule_916 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS7MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATLocalIndex_post=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS8rule_916(_TPPrule_916 _currn)
#else
void _VS8rule_916(_currn )
_TPPrule_916 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS8MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_const24=IDENTICAL(_currn->_desc1->_ATPtg);
/*SPC(2285)*/
_currn->_ATPtg=_currn->_desc1->_ATPtg;
/*SPC(6677)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS9rule_916(_TPPrule_916 _currn)
#else
void _VS9rule_916(_currn )
_TPPrule_916 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS9MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_const47=_currn->_desc1->_AT_const47;
/*SPC(2285)*/
_currn->_ATDoAcc_post=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS10rule_916(_TPPrule_916 _currn)
#else
void _VS10rule_916(_currn )
_TPPrule_916 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS10MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_const49=_currn->_desc1->_AT_const49;
/*SPC(2285)*/
_currn->_AT_const52=_currn->_desc1->_AT_const52;
/*SPC(2285)*/
_currn->_ATStmtNumber_post=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc1->_ATArrayId_post;
/*SPC(0)*/
_currn->_ATNotCharacterIndex=_currn->_desc1->_ATNotCharacterIndex;
/*SPC(2287)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_917(_TPPrule_917 _currn)
#else
void _VS1rule_917(_currn )
_TPPrule_917 _currn;

#endif
{
int* _IL_incl42;
int* _IL_incl40;
int* _IL_incl33;
int* _IL_incl32;
int* _IL_incl27;
int* _IL_incl26;
int* _IL_incl23;
int* _IL_incl22;
KindSetElement* _IL_incl19;
Environment* _IL_incl10;
Environment* _IL_incl11;
int* _IL_incl3;
int* _IL_incl2;
int* _IL_incl0;

_VisitVarDecl()
_VisitEntry();
_IL_incl42=_IG_incl42;_IG_incl42= &(_currn->_ATFalse);
_IL_incl40=_IG_incl40;_IG_incl40= &(_currn->_ATFalse);
_IL_incl33=_IG_incl33;_IG_incl33= &(_currn->_ATFalse);
_IL_incl32=_IG_incl32;_IG_incl32= &(_currn->_ATFalse);
_IL_incl27=_IG_incl27;_IG_incl27= &(_currn->_ATFalse);
_IL_incl26=_IG_incl26;_IG_incl26= &(_currn->_ATFalse);
_IL_incl23=_IG_incl23;_IG_incl23= &(_currn->_ATFalse);
_IL_incl22=_IG_incl22;_IG_incl22= &(_currn->_ATFalse);
_IL_incl19=_IG_incl19;_IG_incl19= &(_currn->_ATKind);
_IL_incl10=_IG_incl10;_IG_incl10= &(_currn->_ATEnv);
_IL_incl11=_IG_incl11;_IG_incl11= &(_currn->_ATUnitEnv);
_IL_incl3=_IG_incl3;_IG_incl3= &(_currn->_ATFalse);
_IL_incl2=_IG_incl2;_IG_incl2= &(_currn->_ATFalse);
_IL_incl0=_IG_incl0;_IG_incl0= &(_currn->_ATFalse);
_currn->_ATFalse=0;
/*SPC(2608)*/
_currn->_ATKind=Module;
/*SPC(2280)*/
DefaultImplicitTypes();
/*SPC(864)*/
_currn->_desc1->_ATOrder_pre=0;
/*SPC(461)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATLastNonExecLine_pre=MapLine(_currn->_AT_line);
/*SPC(9808)*/
_currn->_desc1->_ATArgCnt_pre=0;
/*SPC(6553)*/
_currn->_desc1->_ATIsArray_pre=0;
/*SPC(6290)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_IG_incl42=_IL_incl42;
_IG_incl40=_IL_incl40;
_IG_incl33=_IL_incl33;
_IG_incl32=_IL_incl32;
_IG_incl27=_IL_incl27;
_IG_incl26=_IL_incl26;
_IG_incl23=_IL_incl23;
_IG_incl22=_IL_incl22;
_IG_incl19=_IL_incl19;
_IG_incl10=_IL_incl10;
_IG_incl11=_IL_incl11;
_IG_incl3=_IL_incl3;
_IG_incl2=_IL_incl2;
_IG_incl0=_IL_incl0;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_917(_TPPrule_917 _currn)
#else
void _VS2rule_917(_currn )
_TPPrule_917 _currn;

#endif
{
int* _IL_incl42;
int* _IL_incl40;
int* _IL_incl33;
int* _IL_incl32;
int* _IL_incl27;
int* _IL_incl26;
int* _IL_incl23;
int* _IL_incl22;
KindSetElement* _IL_incl19;
Environment* _IL_incl10;
Environment* _IL_incl11;
int* _IL_incl3;
int* _IL_incl2;
int* _IL_incl0;

_VisitVarDecl()
_VisitEntry();
_IL_incl42=_IG_incl42;_IG_incl42= &(_currn->_ATFalse);
_IL_incl40=_IG_incl40;_IG_incl40= &(_currn->_ATFalse);
_IL_incl33=_IG_incl33;_IG_incl33= &(_currn->_ATFalse);
_IL_incl32=_IG_incl32;_IG_incl32= &(_currn->_ATFalse);
_IL_incl27=_IG_incl27;_IG_incl27= &(_currn->_ATFalse);
_IL_incl26=_IG_incl26;_IG_incl26= &(_currn->_ATFalse);
_IL_incl23=_IG_incl23;_IG_incl23= &(_currn->_ATFalse);
_IL_incl22=_IG_incl22;_IG_incl22= &(_currn->_ATFalse);
_IL_incl19=_IG_incl19;_IG_incl19= &(_currn->_ATKind);
_IL_incl10=_IG_incl10;_IG_incl10= &(_currn->_ATEnv);
_IL_incl11=_IG_incl11;_IG_incl11= &(_currn->_ATUnitEnv);
_IL_incl3=_IG_incl3;_IG_incl3= &(_currn->_ATFalse);
_IL_incl2=_IG_incl2;_IG_incl2= &(_currn->_ATFalse);
_IL_incl0=_IG_incl0;_IG_incl0= &(_currn->_ATFalse);
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_IG_incl42=_IL_incl42;
_IG_incl40=_IL_incl40;
_IG_incl33=_IL_incl33;
_IG_incl32=_IL_incl32;
_IG_incl27=_IL_incl27;
_IG_incl26=_IL_incl26;
_IG_incl23=_IL_incl23;
_IG_incl22=_IL_incl22;
_IG_incl19=_IL_incl19;
_IG_incl10=_IL_incl10;
_IG_incl11=_IL_incl11;
_IG_incl3=_IL_incl3;
_IG_incl2=_IL_incl2;
_IG_incl0=_IL_incl0;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_917(_TPPrule_917 _currn)
#else
void _VS3rule_917(_currn )
_TPPrule_917 _currn;

#endif
{
int* _IL_incl42;
int* _IL_incl40;
int* _IL_incl33;
int* _IL_incl32;
int* _IL_incl27;
int* _IL_incl26;
int* _IL_incl23;
int* _IL_incl22;
KindSetElement* _IL_incl19;
Environment* _IL_incl10;
Environment* _IL_incl11;
int* _IL_incl3;
int* _IL_incl2;
int* _IL_incl0;

_VisitVarDecl()
_VisitEntry();
_IL_incl42=_IG_incl42;_IG_incl42= &(_currn->_ATFalse);
_IL_incl40=_IG_incl40;_IG_incl40= &(_currn->_ATFalse);
_IL_incl33=_IG_incl33;_IG_incl33= &(_currn->_ATFalse);
_IL_incl32=_IG_incl32;_IG_incl32= &(_currn->_ATFalse);
_IL_incl27=_IG_incl27;_IG_incl27= &(_currn->_ATFalse);
_IL_incl26=_IG_incl26;_IG_incl26= &(_currn->_ATFalse);
_IL_incl23=_IG_incl23;_IG_incl23= &(_currn->_ATFalse);
_IL_incl22=_IG_incl22;_IG_incl22= &(_currn->_ATFalse);
_IL_incl19=_IG_incl19;_IG_incl19= &(_currn->_ATKind);
_IL_incl10=_IG_incl10;_IG_incl10= &(_currn->_ATEnv);
_IL_incl11=_IG_incl11;_IG_incl11= &(_currn->_ATUnitEnv);
_IL_incl3=_IG_incl3;_IG_incl3= &(_currn->_ATFalse);
_IL_incl2=_IG_incl2;_IG_incl2= &(_currn->_ATFalse);
_IL_incl0=_IG_incl0;_IG_incl0= &(_currn->_ATFalse);
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_const19=_currn->_desc1->_AT_const19;
/*SPC(2279)*/
_currn->_AT_const20=_currn->_desc1->_AT_const20;
/*SPC(2279)*/
_currn->_AT_const21=_currn->_desc1->_AT_const21;
/*SPC(2279)*/
_currn->_AT_const27=_currn->_desc1->_AT_const27;
/*SPC(2279)*/
_currn->_AT_const28=_currn->_desc1->_AT_const28;
/*SPC(2279)*/
_currn->_AT_const29=_currn->_desc1->_AT_const29;
/*SPC(2279)*/
_IG_incl42=_IL_incl42;
_IG_incl40=_IL_incl40;
_IG_incl33=_IL_incl33;
_IG_incl32=_IL_incl32;
_IG_incl27=_IL_incl27;
_IG_incl26=_IL_incl26;
_IG_incl23=_IL_incl23;
_IG_incl22=_IL_incl22;
_IG_incl19=_IL_incl19;
_IG_incl10=_IL_incl10;
_IG_incl11=_IL_incl11;
_IG_incl3=_IL_incl3;
_IG_incl2=_IL_incl2;
_IG_incl0=_IL_incl0;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_917(_TPPrule_917 _currn)
#else
void _VS4rule_917(_currn )
_TPPrule_917 _currn;

#endif
{
int* _IL_incl42;
int* _IL_incl40;
PTGNode* _IL_incl37;
int* _IL_incl36;
int* _IL_incl35;
BoundsList* _IL_incl34;
int* _IL_incl33;
int* _IL_incl32;
int* _IL_incl27;
int* _IL_incl26;
int* _IL_incl23;
int* _IL_incl22;
KindSetElement* _IL_incl19;
Environment* _IL_incl10;
Environment* _IL_incl11;
PTGNode* _IL_incl6;
PTGNode* _IL_incl9;
PTGNode* _IL_incl8;
PTGNode* _IL_incl7;
PTGNode* _IL_incl5;
int* _IL_incl4;
int* _IL_incl3;
int* _IL_incl2;
int* _IL_incl0;

_VisitVarDecl()
_VisitEntry();
_IL_incl42=_IG_incl42;_IG_incl42= &(_currn->_ATFalse);
_IL_incl40=_IG_incl40;_IG_incl40= &(_currn->_ATFalse);
_IL_incl37=_IG_incl37;_IG_incl37= &(_currn->_ATProgramScalarDeRef);
_IL_incl36=_IG_incl36;_IG_incl36= &(_currn->_ATProgramLineNum);
_IL_incl35=_IG_incl35;_IG_incl35= &(_currn->_ATIntent);
_IL_incl34=_IG_incl34;_IG_incl34= &(_currn->_ATBoundsList);
_IL_incl33=_IG_incl33;_IG_incl33= &(_currn->_ATFalse);
_IL_incl32=_IG_incl32;_IG_incl32= &(_currn->_ATFalse);
_IL_incl27=_IG_incl27;_IG_incl27= &(_currn->_ATFalse);
_IL_incl26=_IG_incl26;_IG_incl26= &(_currn->_ATFalse);
_IL_incl23=_IG_incl23;_IG_incl23= &(_currn->_ATFalse);
_IL_incl22=_IG_incl22;_IG_incl22= &(_currn->_ATFalse);
_IL_incl19=_IG_incl19;_IG_incl19= &(_currn->_ATKind);
_IL_incl10=_IG_incl10;_IG_incl10= &(_currn->_ATEnv);
_IL_incl11=_IG_incl11;_IG_incl11= &(_currn->_ATUnitEnv);
_IL_incl6=_IG_incl6;_IG_incl6= &(_currn->_ATProgramArgs);
_IL_incl9=_IG_incl9;_IG_incl9= &(_currn->_ATProgramArgsPtg);
_IL_incl8=_IG_incl8;_IG_incl8= &(_currn->_ATProgramArgsIn);
_IL_incl7=_IG_incl7;_IG_incl7= &(_currn->_ATProgramName);
_IL_incl5=_IG_incl5;_IG_incl5= &(_currn->_ATProgramArgsOut);
_IL_incl4=_IG_incl4;_IG_incl4= &(_currn->_ATNumKernels);
_IL_incl3=_IG_incl3;_IG_incl3= &(_currn->_ATFalse);
_IL_incl2=_IG_incl2;_IG_incl2= &(_currn->_ATFalse);
_IL_incl0=_IG_incl0;_IG_incl0= &(_currn->_ATFalse);
_currn->_AT_BoundsauxList=NULLBoundsList;
/*SPC(11354)*/
_currn->_ATNumKernels=_currn->_desc1->_AT_const26;
/*SPC(10383)*/
_currn->_ATProgramArgsIn=PTGKernelCopyArgs(_currn->_desc1->_AT_const19);
/*SPC(10269)*/
_currn->_ATProgramArgsPtg=_currn->_desc1->_AT_const27;
/*SPC(10266)*/
_currn->_ATProgramArgs=_currn->_desc1->_AT_const28;
/*SPC(10263)*/
_currn->_ATProgramName=_currn->_desc1->_AT_const29;
/*SPC(10260)*/
_currn->_ATProgramScalarDeRef=_currn->_desc1->_AT_const21;
/*SPC(10281)*/
_currn->_ATProgramArgsOut=PTGKernelFreeArgs(_currn->_desc1->_AT_const20);
/*SPC(10275)*/
_currn->_ATProgramLineNum=0;
/*SPC(3661)*/
_currn->_desc1->_AT_cBoundsListPtr_pre=_BoundsListADDROF(_currn->_AT_BoundsauxList);
/*SPC(11355)*/
_currn->_desc1->_ATDoAcc_pre=InitAccDo();
/*SPC(10765)*/
_currn->_desc1->_ATAccDoType_pre=0;
/*SPC(10749)*/
_currn->_desc1->_ATAccDoStmt_pre=0;
/*SPC(10745)*/
_currn->_desc1->_ATStmtNumber_pre=0;
/*SPC(10741)*/
_currn->_desc1->_ATUpdate_pre=0;
/*SPC(10691)*/
_currn->_desc1->_ATAccDoLoopDim_pre=0;
/*SPC(10551)*/
_currn->_desc1->_ATKernelNumber_pre=0;
/*SPC(10396)*/
_currn->_desc1->_ATNestLevel_pre=0;
/*SPC(10197)*/
_currn->_desc1->_ATCPURegionNumber_pre=0;
/*SPC(9863)*/
_currn->_desc1->_ATAccRegionNumber_pre=0;
/*SPC(9861)*/
_currn->_desc1->_ATAcceleratorRegion_pre=0;
/*SPC(9859)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATLocalIndex_pre=0;
/*SPC(6407)*/
_currn->_desc1->_ATArrayId_pre=NoKey;
/*SPC(6294)*/
_currn->_desc1->_ATMaxRank_pre=0;
/*SPC(5930)*/
_currn->_desc1->_ATCount_pre=0;
/*SPC(4221)*/
_currn->_desc1->_ATTypeLength_pre=0;
/*SPC(3557)*/
(*(_CALL_VS_((NODEPTR )) (VS6MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATIndentLevel_post=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATIntent=2;
/*SPC(3610)*/
_currn->_ATBoundsList=NULLBoundsList;
/*SPC(2952)*/
_IG_incl42=_IL_incl42;
_IG_incl40=_IL_incl40;
_IG_incl37=_IL_incl37;
_IG_incl36=_IL_incl36;
_IG_incl35=_IL_incl35;
_IG_incl34=_IL_incl34;
_IG_incl33=_IL_incl33;
_IG_incl32=_IL_incl32;
_IG_incl27=_IL_incl27;
_IG_incl26=_IL_incl26;
_IG_incl23=_IL_incl23;
_IG_incl22=_IL_incl22;
_IG_incl19=_IL_incl19;
_IG_incl10=_IL_incl10;
_IG_incl11=_IL_incl11;
_IG_incl6=_IL_incl6;
_IG_incl9=_IL_incl9;
_IG_incl8=_IL_incl8;
_IG_incl7=_IL_incl7;
_IG_incl5=_IL_incl5;
_IG_incl4=_IL_incl4;
_IG_incl3=_IL_incl3;
_IG_incl2=_IL_incl2;
_IG_incl0=_IL_incl0;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_918(_TPPrule_918 _currn)
#else
void _VS1rule_918(_currn )
_TPPrule_918 _currn;

#endif
{
int* _IL_incl42;
int* _IL_incl40;
int* _IL_incl33;
int* _IL_incl32;
int* _IL_incl27;
int* _IL_incl26;
int* _IL_incl23;
int* _IL_incl22;
KindSetElement* _IL_incl19;
Environment* _IL_incl10;
Environment* _IL_incl11;
int* _IL_incl3;
int* _IL_incl2;
int* _IL_incl0;

_VisitVarDecl()
_VisitEntry();
_IL_incl42=_IG_incl42;_IG_incl42= &(_currn->_ATFalse);
_IL_incl40=_IG_incl40;_IG_incl40= &(_currn->_ATFalse);
_IL_incl33=_IG_incl33;_IG_incl33= &(_currn->_ATFalse);
_IL_incl32=_IG_incl32;_IG_incl32= &(_currn->_ATFalse);
_IL_incl27=_IG_incl27;_IG_incl27= &(_currn->_ATFalse);
_IL_incl26=_IG_incl26;_IG_incl26= &(_currn->_ATFalse);
_IL_incl23=_IG_incl23;_IG_incl23= &(_currn->_ATFalse);
_IL_incl22=_IG_incl22;_IG_incl22= &(_currn->_ATFalse);
_IL_incl19=_IG_incl19;_IG_incl19= &(_currn->_ATKind);
_IL_incl10=_IG_incl10;_IG_incl10= &(_currn->_ATEnv);
_IL_incl11=_IG_incl11;_IG_incl11= &(_currn->_ATUnitEnv);
_IL_incl3=_IG_incl3;_IG_incl3= &(_currn->_ATFalse);
_IL_incl2=_IG_incl2;_IG_incl2= &(_currn->_ATFalse);
_IL_incl0=_IG_incl0;_IG_incl0= &(_currn->_ATFalse);
DefaultImplicitTypes();
/*SPC(864)*/
_currn->_desc1->_ATOrder_pre=0;
/*SPC(461)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATFalse=0;
/*SPC(2608)*/
_currn->_ATKind=ExternalFunction;
/*SPC(2276)*/
_currn->_desc2->_ATOrder_pre=_currn->_desc1->_ATOrder_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_desc1->_ATLastNonExecLine_pre=MapLine(_currn->_AT_line);
/*SPC(9808)*/
_currn->_desc1->_ATArgCnt_pre=0;
/*SPC(6553)*/
_currn->_desc1->_ATIsArray_pre=0;
/*SPC(6290)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATLastNonExecLine_pre=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_desc2->_ATArgCnt_pre=_currn->_desc1->_ATArgCnt_post;
/*SPC(0)*/
_currn->_desc2->_ATIsArray_pre=_currn->_desc1->_ATIsArray_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_IG_incl42=_IL_incl42;
_IG_incl40=_IL_incl40;
_IG_incl33=_IL_incl33;
_IG_incl32=_IL_incl32;
_IG_incl27=_IL_incl27;
_IG_incl26=_IL_incl26;
_IG_incl23=_IL_incl23;
_IG_incl22=_IL_incl22;
_IG_incl19=_IL_incl19;
_IG_incl10=_IL_incl10;
_IG_incl11=_IL_incl11;
_IG_incl3=_IL_incl3;
_IG_incl2=_IL_incl2;
_IG_incl0=_IL_incl0;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_918(_TPPrule_918 _currn)
#else
void _VS2rule_918(_currn )
_TPPrule_918 _currn;

#endif
{
int* _IL_incl42;
int* _IL_incl40;
int* _IL_incl33;
int* _IL_incl32;
int* _IL_incl27;
int* _IL_incl26;
int* _IL_incl23;
int* _IL_incl22;
KindSetElement* _IL_incl19;
Environment* _IL_incl10;
Environment* _IL_incl11;
int* _IL_incl3;
int* _IL_incl2;
int* _IL_incl0;

_VisitVarDecl()
_VisitEntry();
_IL_incl42=_IG_incl42;_IG_incl42= &(_currn->_ATFalse);
_IL_incl40=_IG_incl40;_IG_incl40= &(_currn->_ATFalse);
_IL_incl33=_IG_incl33;_IG_incl33= &(_currn->_ATFalse);
_IL_incl32=_IG_incl32;_IG_incl32= &(_currn->_ATFalse);
_IL_incl27=_IG_incl27;_IG_incl27= &(_currn->_ATFalse);
_IL_incl26=_IG_incl26;_IG_incl26= &(_currn->_ATFalse);
_IL_incl23=_IG_incl23;_IG_incl23= &(_currn->_ATFalse);
_IL_incl22=_IG_incl22;_IG_incl22= &(_currn->_ATFalse);
_IL_incl19=_IG_incl19;_IG_incl19= &(_currn->_ATKind);
_IL_incl10=_IG_incl10;_IG_incl10= &(_currn->_ATEnv);
_IL_incl11=_IG_incl11;_IG_incl11= &(_currn->_ATUnitEnv);
_IL_incl3=_IG_incl3;_IG_incl3= &(_currn->_ATFalse);
_IL_incl2=_IG_incl2;_IG_incl2= &(_currn->_ATFalse);
_IL_incl0=_IG_incl0;_IG_incl0= &(_currn->_ATFalse);
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_IG_incl42=_IL_incl42;
_IG_incl40=_IL_incl40;
_IG_incl33=_IL_incl33;
_IG_incl32=_IL_incl32;
_IG_incl27=_IL_incl27;
_IG_incl26=_IL_incl26;
_IG_incl23=_IL_incl23;
_IG_incl22=_IL_incl22;
_IG_incl19=_IL_incl19;
_IG_incl10=_IL_incl10;
_IG_incl11=_IL_incl11;
_IG_incl3=_IL_incl3;
_IG_incl2=_IL_incl2;
_IG_incl0=_IL_incl0;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_918(_TPPrule_918 _currn)
#else
void _VS3rule_918(_currn )
_TPPrule_918 _currn;

#endif
{
int* _IL_incl42;
int* _IL_incl40;
int* _IL_incl33;
int* _IL_incl32;
int* _IL_incl27;
int* _IL_incl26;
int* _IL_incl23;
int* _IL_incl22;
KindSetElement* _IL_incl19;
Environment* _IL_incl10;
Environment* _IL_incl11;
int* _IL_incl3;
int* _IL_incl2;
int* _IL_incl0;

_VisitVarDecl()
_VisitEntry();
_IL_incl42=_IG_incl42;_IG_incl42= &(_currn->_ATFalse);
_IL_incl40=_IG_incl40;_IG_incl40= &(_currn->_ATFalse);
_IL_incl33=_IG_incl33;_IG_incl33= &(_currn->_ATFalse);
_IL_incl32=_IG_incl32;_IG_incl32= &(_currn->_ATFalse);
_IL_incl27=_IG_incl27;_IG_incl27= &(_currn->_ATFalse);
_IL_incl26=_IG_incl26;_IG_incl26= &(_currn->_ATFalse);
_IL_incl23=_IG_incl23;_IG_incl23= &(_currn->_ATFalse);
_IL_incl22=_IG_incl22;_IG_incl22= &(_currn->_ATFalse);
_IL_incl19=_IG_incl19;_IG_incl19= &(_currn->_ATKind);
_IL_incl10=_IG_incl10;_IG_incl10= &(_currn->_ATEnv);
_IL_incl11=_IG_incl11;_IG_incl11= &(_currn->_ATUnitEnv);
_IL_incl3=_IG_incl3;_IG_incl3= &(_currn->_ATFalse);
_IL_incl2=_IG_incl2;_IG_incl2= &(_currn->_ATFalse);
_IL_incl0=_IG_incl0;_IG_incl0= &(_currn->_ATFalse);
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_AT_const19=PTGSequence(_currn->_desc1->_AT_const19, _currn->_desc2->_AT_const19);
/*SPC(2274)*/
_currn->_AT_const20=PTGSequence(_currn->_desc1->_AT_const20, _currn->_desc2->_AT_const20);
/*SPC(2274)*/
_currn->_AT_const21=PTGSequence(_currn->_desc1->_AT_const21, _currn->_desc2->_AT_const21);
/*SPC(2274)*/
_currn->_AT_const27=PTGSequence(IDENTICAL(_currn->_desc1->_ATProgramArgsPtg), _currn->_desc2->_AT_const27);
/*SPC(2274)*/
_currn->_AT_const28=PTGSequence(IDENTICAL(_currn->_desc1->_ATProgramArgs), _currn->_desc2->_AT_const28);
/*SPC(2274)*/
_currn->_AT_const29=PTGSequence(IDENTICAL(_currn->_desc1->_ATProgramName), _currn->_desc2->_AT_const29);
/*SPC(2274)*/
_IG_incl42=_IL_incl42;
_IG_incl40=_IL_incl40;
_IG_incl33=_IL_incl33;
_IG_incl32=_IL_incl32;
_IG_incl27=_IL_incl27;
_IG_incl26=_IL_incl26;
_IG_incl23=_IL_incl23;
_IG_incl22=_IL_incl22;
_IG_incl19=_IL_incl19;
_IG_incl10=_IL_incl10;
_IG_incl11=_IL_incl11;
_IG_incl3=_IL_incl3;
_IG_incl2=_IL_incl2;
_IG_incl0=_IL_incl0;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_918(_TPPrule_918 _currn)
#else
void _VS4rule_918(_currn )
_TPPrule_918 _currn;

#endif
{
int* _IL_incl42;
int* _IL_incl40;
PTGNode* _IL_incl37;
int* _IL_incl36;
int* _IL_incl35;
BoundsList* _IL_incl34;
int* _IL_incl33;
int* _IL_incl32;
int* _IL_incl27;
int* _IL_incl26;
int* _IL_incl23;
int* _IL_incl22;
KindSetElement* _IL_incl19;
Environment* _IL_incl10;
Environment* _IL_incl11;
PTGNode* _IL_incl6;
PTGNode* _IL_incl9;
PTGNode* _IL_incl8;
PTGNode* _IL_incl7;
PTGNode* _IL_incl5;
int* _IL_incl4;
int* _IL_incl3;
int* _IL_incl2;
int* _IL_incl0;

_VisitVarDecl()
_VisitEntry();
_IL_incl42=_IG_incl42;_IG_incl42= &(_currn->_ATFalse);
_IL_incl40=_IG_incl40;_IG_incl40= &(_currn->_ATFalse);
_IL_incl37=_IG_incl37;_IG_incl37= &(_currn->_ATProgramScalarDeRef);
_IL_incl36=_IG_incl36;_IG_incl36= &(_currn->_ATProgramLineNum);
_IL_incl35=_IG_incl35;_IG_incl35= &(_currn->_ATIntent);
_IL_incl34=_IG_incl34;_IG_incl34= &(_currn->_ATBoundsList);
_IL_incl33=_IG_incl33;_IG_incl33= &(_currn->_ATFalse);
_IL_incl32=_IG_incl32;_IG_incl32= &(_currn->_ATFalse);
_IL_incl27=_IG_incl27;_IG_incl27= &(_currn->_ATFalse);
_IL_incl26=_IG_incl26;_IG_incl26= &(_currn->_ATFalse);
_IL_incl23=_IG_incl23;_IG_incl23= &(_currn->_ATFalse);
_IL_incl22=_IG_incl22;_IG_incl22= &(_currn->_ATFalse);
_IL_incl19=_IG_incl19;_IG_incl19= &(_currn->_ATKind);
_IL_incl10=_IG_incl10;_IG_incl10= &(_currn->_ATEnv);
_IL_incl11=_IG_incl11;_IG_incl11= &(_currn->_ATUnitEnv);
_IL_incl6=_IG_incl6;_IG_incl6= &(_currn->_ATProgramArgs);
_IL_incl9=_IG_incl9;_IG_incl9= &(_currn->_ATProgramArgsPtg);
_IL_incl8=_IG_incl8;_IG_incl8= &(_currn->_ATProgramArgsIn);
_IL_incl7=_IG_incl7;_IG_incl7= &(_currn->_ATProgramName);
_IL_incl5=_IG_incl5;_IG_incl5= &(_currn->_ATProgramArgsOut);
_IL_incl4=_IG_incl4;_IG_incl4= &(_currn->_ATNumKernels);
_IL_incl3=_IG_incl3;_IG_incl3= &(_currn->_ATFalse);
_IL_incl2=_IG_incl2;_IG_incl2= &(_currn->_ATFalse);
_IL_incl0=_IG_incl0;_IG_incl0= &(_currn->_ATFalse);
_currn->_AT_BoundsauxList=NULLBoundsList;
/*SPC(11354)*/
_currn->_desc1->_AT_cBoundsListPtr_pre=_BoundsListADDROF(_currn->_AT_BoundsauxList);
/*SPC(11355)*/
_currn->_desc1->_ATDoAcc_pre=InitAccDo();
/*SPC(10765)*/
_currn->_desc1->_ATAccDoType_pre=0;
/*SPC(10749)*/
_currn->_desc1->_ATAccDoStmt_pre=0;
/*SPC(10745)*/
_currn->_desc1->_ATStmtNumber_pre=0;
/*SPC(10741)*/
_currn->_desc1->_ATUpdate_pre=0;
/*SPC(10691)*/
_currn->_desc1->_ATAccDoLoopDim_pre=0;
/*SPC(10551)*/
_currn->_desc1->_ATKernelNumber_pre=0;
/*SPC(10396)*/
_currn->_desc1->_ATNestLevel_pre=0;
/*SPC(10197)*/
_currn->_desc1->_ATCPURegionNumber_pre=0;
/*SPC(9863)*/
_currn->_desc1->_ATAccRegionNumber_pre=0;
/*SPC(9861)*/
_currn->_desc1->_ATAcceleratorRegion_pre=0;
/*SPC(9859)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATLocalIndex_pre=0;
/*SPC(6407)*/
_currn->_desc1->_ATArrayId_pre=NoKey;
/*SPC(6294)*/
_currn->_desc1->_ATMaxRank_pre=0;
/*SPC(5930)*/
_currn->_desc1->_ATCount_pre=0;
/*SPC(4221)*/
_currn->_desc1->_ATTypeLength_pre=0;
/*SPC(3557)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATNumKernels=_currn->_desc2->_AT_const26;
/*SPC(10383)*/
_currn->_ATProgramArgsIn=PTGKernelCopyArgs(PTGSequence(_currn->_desc1->_AT_const19, _currn->_desc2->_AT_const19));
/*SPC(10269)*/
_currn->_ATProgramArgsPtg=PTGSequence(IDENTICAL(_currn->_desc1->_ATProgramArgsPtg), _currn->_desc2->_AT_const27);
/*SPC(10266)*/
_currn->_ATProgramArgs=PTGSequence(IDENTICAL(_currn->_desc1->_ATProgramArgs), _currn->_desc2->_AT_const28);
/*SPC(10263)*/
_currn->_ATProgramName=PTGSequence(IDENTICAL(_currn->_desc1->_ATProgramName), _currn->_desc2->_AT_const29);
/*SPC(10260)*/
_currn->_ATProgramScalarDeRef=PTGSequence(_currn->_desc1->_AT_const21, _currn->_desc2->_AT_const21);
/*SPC(10281)*/
_currn->_ATProgramArgsOut=PTGKernelFreeArgs(PTGSequence(_currn->_desc1->_AT_const20, _currn->_desc2->_AT_const20));
/*SPC(10275)*/
_currn->_ATProgramLineNum=0;
/*SPC(3661)*/
_currn->_desc2->_AT_cBoundsListPtr_pre=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_desc2->_ATDoAcc_pre=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_desc2->_ATAccDoType_pre=_currn->_desc1->_ATAccDoType_post;
/*SPC(0)*/
_currn->_desc2->_ATAccDoStmt_pre=_currn->_desc1->_ATAccDoStmt_post;
/*SPC(0)*/
_currn->_desc2->_ATStmtNumber_pre=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATUpdate_pre=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_desc2->_ATAccDoLoopDim_pre=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_desc2->_ATKernelNumber_pre=_currn->_desc1->_ATKernelNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATNestLevel_pre=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_desc2->_ATCPURegionNumber_pre=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATAccRegionNumber_pre=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATAcceleratorRegion_pre=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_desc2->_ATIndentLevel_pre=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_desc2->_ATLocalIndex_pre=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_desc2->_ATArrayId_pre=_currn->_desc1->_ATArrayId_post;
/*SPC(0)*/
_currn->_desc2->_ATMaxRank_pre=_currn->_desc1->_ATMaxRank_post;
/*SPC(0)*/
_currn->_desc2->_ATCount_pre=_currn->_desc1->_ATCount_post;
/*SPC(0)*/
_currn->_desc2->_ATTypeLength_pre=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS6MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATIndentLevel_post=_currn->_desc2->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATIntent=2;
/*SPC(3610)*/
_currn->_ATBoundsList=NULLBoundsList;
/*SPC(2952)*/
_IG_incl42=_IL_incl42;
_IG_incl40=_IL_incl40;
_IG_incl37=_IL_incl37;
_IG_incl36=_IL_incl36;
_IG_incl35=_IL_incl35;
_IG_incl34=_IL_incl34;
_IG_incl33=_IL_incl33;
_IG_incl32=_IL_incl32;
_IG_incl27=_IL_incl27;
_IG_incl26=_IL_incl26;
_IG_incl23=_IL_incl23;
_IG_incl22=_IL_incl22;
_IG_incl19=_IL_incl19;
_IG_incl10=_IL_incl10;
_IG_incl11=_IL_incl11;
_IG_incl6=_IL_incl6;
_IG_incl9=_IL_incl9;
_IG_incl8=_IL_incl8;
_IG_incl7=_IL_incl7;
_IG_incl5=_IL_incl5;
_IG_incl4=_IL_incl4;
_IG_incl3=_IL_incl3;
_IG_incl2=_IL_incl2;
_IG_incl0=_IL_incl0;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_919(_TPPrule_919 _currn)
#else
void _VS1rule_919(_currn )
_TPPrule_919 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
InsertKindSet(_currn->_desc1->_ATUnitKey, CommonBlock);
/*SPC(2258)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_919(_TPPrule_919 _currn)
#else
void _VS3rule_919(_currn )
_TPPrule_919 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_920(_TPPrule_920 _currn)
#else
void _VS1rule_920(_currn )
_TPPrule_920 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
ImplicitType(_currn->_desc1->_ATType, _currn->_ATTERM_1, (&( _currn->_AT_pos)));
/*SPC(2035)*/
_currn->_ATOrder_post=_currn->_desc1->_ATOrder_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_920(_TPPrule_920 _currn)
#else
void _VS2rule_920(_currn )
_TPPrule_920 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
_currn->_desc1->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATLastNonExecLine_post=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc1->_ATArgCnt_post;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_desc1->_ATIsArray_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_920(_TPPrule_920 _currn)
#else
void _VS3rule_920(_currn )
_TPPrule_920 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_desc1->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_cBoundsListPtr_post=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_ATDoAcc_post=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc1->_ATArrayId_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_921(_TPPrule_921 _currn)
#else
void _VS1rule_921(_currn )
_TPPrule_921 _currn;

#endif
{
int* _IL_incl32;

_VisitVarDecl()
_VisitEntry();
_IL_incl32=_IG_incl32;_IG_incl32= &(_currn->_ATDims);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATDims=0;
/*SPC(3128)*/
_currn->_desc3->_ATOrder_pre=_currn->_desc2->_ATOrder_post;
/*SPC(0)*/
_currn->_desc3->_ATType=_currn->_desc2->_ATType;
/*SPC(2011)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);
_currn->_ATOrder_post=_currn->_desc3->_ATOrder_post;
/*SPC(0)*/
_IG_incl32=_IL_incl32;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_921(_TPPrule_921 _currn)
#else
void _VS2rule_921(_currn )
_TPPrule_921 _currn;

#endif
{
int* _IL_incl32;

_VisitVarDecl()
_VisitEntry();
_IL_incl32=_IG_incl32;_IG_incl32= &(_currn->_ATDims);
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATExecutable=0;
/*SPC(998)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATLastNonExecLine_pre=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_desc2->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
_currn->_desc2->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_desc3->_ATLastNonExecLine_pre=_currn->_desc2->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_desc3->_ATArgCnt_pre=_currn->_desc2->_ATArgCnt_post;
/*SPC(0)*/
_currn->_desc3->_ATIsArray_pre=_currn->_desc2->_ATIsArray_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);
_currn->_ATLastNonExecLine_post=_currn->_desc3->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc3->_ATArgCnt_post;
/*SPC(0)*/
_IG_incl32=_IL_incl32;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_921(_TPPrule_921 _currn)
#else
void _VS3rule_921(_currn )
_TPPrule_921 _currn;

#endif
{
int* _IL_incl32;

_VisitVarDecl()
_VisitEntry();
_IL_incl32=_IG_incl32;_IG_incl32= &(_currn->_ATDims);
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);
_IG_incl32=_IL_incl32;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_921(_TPPrule_921 _currn)
#else
void _VS4rule_921(_currn )
_TPPrule_921 _currn;

#endif
{
int* _IL_incl40;
int* _IL_incl35;
int* _IL_incl33;
int* _IL_incl32;
int* _IL_incl28;

_VisitVarDecl()
_VisitEntry();
_IL_incl40=_IG_incl40;_IG_incl40= &(_currn->_ATParameterAttr);
_IL_incl35=_IG_incl35;_IG_incl35= &(_currn->_ATIntent);
_IL_incl33=_IG_incl33;_IG_incl33= &(_currn->_ATAttrDecl);
_IL_incl32=_IG_incl32;_IG_incl32= &(_currn->_ATDims);
_IL_incl28=_IG_incl28;_IG_incl28= &(_currn->_ATParameterAttr);
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_BoundsauxList=NULLBoundsList;
/*SPC(11354)*/
_currn->_desc1->_AT_cBoundsListPtr_pre=_BoundsListADDROF(_currn->_AT_BoundsauxList);
/*SPC(11355)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_AT_cBoundsListPtr_pre=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_desc2->_ATTypeLength_pre=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATParameterAttr=
((EQ(ZERO(), 1)
) ? (1
) : (0))
;
/*SPC(3707)*/
_currn->_ATIntent=2;
/*SPC(3611)*/
_currn->_ATAttrDecl=1;
/*SPC(3046)*/
_currn->_desc3->_AT_cBoundsListPtr_pre=_currn->_desc2->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_desc3->_ATTypeLength_pre=_currn->_desc2->_ATTypeLength_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);
_IG_incl40=_IL_incl40;
_IG_incl35=_IL_incl35;
_IG_incl33=_IL_incl33;
_IG_incl32=_IL_incl32;
_IG_incl28=_IL_incl28;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5rule_921(_TPPrule_921 _currn)
#else
void _VS5rule_921(_currn )
_TPPrule_921 _currn;

#endif
{
int* _IL_incl40;
int* _IL_incl35;
BoundsList* _IL_incl34;
int* _IL_incl33;
int* _IL_incl32;
int* _IL_incl29;
int* _IL_incl28;

_VisitVarDecl()
_VisitEntry();
_IL_incl40=_IG_incl40;_IG_incl40= &(_currn->_ATParameterAttr);
_IL_incl35=_IG_incl35;_IG_incl35= &(_currn->_ATIntent);
_IL_incl34=_IG_incl34;_IG_incl34= &(_currn->_ATBoundsList);
_IL_incl33=_IG_incl33;_IG_incl33= &(_currn->_ATAttrDecl);
_IL_incl32=_IG_incl32;_IG_incl32= &(_currn->_ATDims);
_IL_incl29=_IG_incl29;_IG_incl29= &(_currn->_ATAllocatableAttr);
_IL_incl28=_IG_incl28;_IG_incl28= &(_currn->_ATParameterAttr);
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS6MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS7MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS8MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATDoAcc_pre=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_desc2->_ATStmtNumber_pre=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATUpdate_pre=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_desc2->_ATAccDoLoopDim_pre=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_desc2->_ATNestLevel_pre=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_desc2->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc2->_ATAccRegionNumber_pre=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc2->_ATIndentLevel_pre=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_desc2->_ATLocalIndex_pre=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_desc2->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATAllocatableAttr=
((EQ(ZERO(), 1)
) ? (1
) : (0))
;
/*SPC(3766)*/
_currn->_ATBoundsList=_currn->_AT_BoundsauxList;
/*SPC(11356)*/
_currn->_desc3->_ATDoAcc_pre=_currn->_desc2->_ATDoAcc_post;
/*SPC(0)*/
_currn->_desc3->_ATStmtNumber_pre=_currn->_desc2->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_desc3->_ATUpdate_pre=_currn->_desc2->_ATUpdate_post;
/*SPC(0)*/
_currn->_desc3->_ATAccDoLoopDim_pre=_currn->_desc2->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_desc3->_ATNestLevel_pre=_currn->_desc2->_ATNestLevel_post;
/*SPC(0)*/
_currn->_desc3->_ATCPURegionNumber_pre=_currn->_desc2->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_desc3->_ATAccRegionNumber_pre=_currn->_desc2->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_desc3->_ATAcceleratorRegion_pre=_currn->_desc2->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_desc3->_ATIndentLevel_pre=_currn->_desc2->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_desc3->_ATLocalIndex_pre=_currn->_desc2->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_desc3->_ATArrayId_pre=_currn->_desc2->_ATArrayId_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);
_currn->_AT_cBoundsListPtr_post=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_ATDoAcc_post=_currn->_desc3->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc3->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc3->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc3->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc3->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc3->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc3->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc3->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc3->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc3->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc3->_ATArrayId_post;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_desc3->_ATIsArray_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_desc3->_ATTypeLength_post;
/*SPC(0)*/
_currn->_ATPtg=
((GE(_currn->_desc3->_ATOutput, 1)
) ? (PTGVariableDecls(PTGNull(), _currn->_desc2->_ATPtg, _currn->_desc3->_ATPtg)
) : (PTGNULL))
;
/*SPC(4117)*/
_currn->_ATSizeValue=0;
/*SPC(3129)*/

if (OR(EQ(strcmp(MapFile(_currn->_AT_line), StringTable(GetClpValue(FileName, 0))), 0), AND(EQ(GetClpValue(ModuleUse, 1), 1), GE(isModule(_currn->_AT_line), 1)))) {

if (AND(EQ(GetClpValue(Generate, 1), 0), GE(_currn->_desc3->_ATOutput, 1))) {

if (EQ(isModule(_currn->_AT_line), 0)) {
PTGOut(PTGReplace(PTGNumb(MapLine(_currn->_AT_line)), PTGIndent(_currn->_desc1->_ATIndentLevel_post), _currn->_ATPtg));

} else {
PTGOut(PTGExtern(PTGNumb(isModule(_currn->_AT_line)), PTGIndent(_currn->_desc1->_ATIndentLevel_post), _currn->_ATPtg));
}
;

} else {

if (EQ(strcmp(MapFile(_currn->_AT_line), StringTable(GetClpValue(FileName, 0))), 0)) {
PTGOut(PTGRemove(PTGNumb(MapLine(_currn->_AT_line))));

} else {
}
;
}
;

} else {
}
;
/*SPC(4146)*/
_IG_incl40=_IL_incl40;
_IG_incl35=_IL_incl35;
_IG_incl34=_IL_incl34;
_IG_incl33=_IL_incl33;
_IG_incl32=_IL_incl32;
_IG_incl29=_IL_incl29;
_IG_incl28=_IL_incl28;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_922(_TPPrule_922 _currn)
#else
void _VS1rule_922(_currn )
_TPPrule_922 _currn;

#endif
{
int* _IL_incl32;

_VisitVarDecl()
_VisitEntry();
_IL_incl32=_IG_incl32;_IG_incl32= &(_currn->_ATDims);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATDims=0;
/*SPC(3128)*/
_currn->_desc3->_ATOrder_pre=_currn->_desc2->_ATOrder_post;
/*SPC(0)*/
_currn->_desc3->_ATType=_currn->_desc2->_ATType;
/*SPC(2006)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);
_currn->_ATOrder_post=_currn->_desc3->_ATOrder_post;
/*SPC(0)*/
_IG_incl32=_IL_incl32;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_922(_TPPrule_922 _currn)
#else
void _VS2rule_922(_currn )
_TPPrule_922 _currn;

#endif
{
int* _IL_incl32;

_VisitVarDecl()
_VisitEntry();
_IL_incl32=_IG_incl32;_IG_incl32= &(_currn->_ATDims);
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATExecutable=0;
/*SPC(998)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATLastNonExecLine_pre=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_desc2->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
_currn->_desc2->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_desc3->_ATLastNonExecLine_pre=_currn->_desc2->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_desc3->_ATArgCnt_pre=_currn->_desc2->_ATArgCnt_post;
/*SPC(0)*/
_currn->_desc3->_ATIsArray_pre=_currn->_desc2->_ATIsArray_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);
_currn->_ATLastNonExecLine_post=_currn->_desc3->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc3->_ATArgCnt_post;
/*SPC(0)*/
_IG_incl32=_IL_incl32;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_922(_TPPrule_922 _currn)
#else
void _VS3rule_922(_currn )
_TPPrule_922 _currn;

#endif
{
int* _IL_incl32;

_VisitVarDecl()
_VisitEntry();
_IL_incl32=_IG_incl32;_IG_incl32= &(_currn->_ATDims);
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);
_IG_incl32=_IL_incl32;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_922(_TPPrule_922 _currn)
#else
void _VS4rule_922(_currn )
_TPPrule_922 _currn;

#endif
{
int* _IL_incl40;
int* _IL_incl35;
int* _IL_incl33;
int* _IL_incl32;
int* _IL_incl28;

_VisitVarDecl()
_VisitEntry();
_IL_incl40=_IG_incl40;_IG_incl40= &(_currn->_ATParameterAttr);
_IL_incl35=_IG_incl35;_IG_incl35= &(_currn->_ATIntent);
_IL_incl33=_IG_incl33;_IG_incl33= &(_currn->_ATAttrDecl);
_IL_incl32=_IG_incl32;_IG_incl32= &(_currn->_ATDims);
_IL_incl28=_IG_incl28;_IG_incl28= &(_currn->_ATParameterAttr);
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_BoundsauxList=NULLBoundsList;
/*SPC(11354)*/
_currn->_desc1->_AT_cBoundsListPtr_pre=_BoundsListADDROF(_currn->_AT_BoundsauxList);
/*SPC(11355)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_AT_cBoundsListPtr_pre=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_desc2->_ATTypeLength_pre=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATParameterAttr=0;
/*SPC(3696)*/
_currn->_ATIntent=2;
/*SPC(3611)*/
_currn->_ATAttrDecl=1;
/*SPC(3046)*/
_currn->_desc3->_AT_cBoundsListPtr_pre=_currn->_desc2->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_desc3->_ATTypeLength_pre=_currn->_desc2->_ATTypeLength_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);
_IG_incl40=_IL_incl40;
_IG_incl35=_IL_incl35;
_IG_incl33=_IL_incl33;
_IG_incl32=_IL_incl32;
_IG_incl28=_IL_incl28;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5rule_922(_TPPrule_922 _currn)
#else
void _VS5rule_922(_currn )
_TPPrule_922 _currn;

#endif
{
int* _IL_incl40;
int* _IL_incl35;
BoundsList* _IL_incl34;
int* _IL_incl33;
int* _IL_incl32;
int* _IL_incl29;
int* _IL_incl28;

_VisitVarDecl()
_VisitEntry();
_IL_incl40=_IG_incl40;_IG_incl40= &(_currn->_ATParameterAttr);
_IL_incl35=_IG_incl35;_IG_incl35= &(_currn->_ATIntent);
_IL_incl34=_IG_incl34;_IG_incl34= &(_currn->_ATBoundsList);
_IL_incl33=_IG_incl33;_IG_incl33= &(_currn->_ATAttrDecl);
_IL_incl32=_IG_incl32;_IG_incl32= &(_currn->_ATDims);
_IL_incl29=_IG_incl29;_IG_incl29= &(_currn->_ATAllocatableAttr);
_IL_incl28=_IG_incl28;_IG_incl28= &(_currn->_ATParameterAttr);
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS6MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS7MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS8MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATDoAcc_pre=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_desc2->_ATStmtNumber_pre=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATUpdate_pre=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_desc2->_ATAccDoLoopDim_pre=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_desc2->_ATNestLevel_pre=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_desc2->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc2->_ATAccRegionNumber_pre=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc2->_ATIndentLevel_pre=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_desc2->_ATLocalIndex_pre=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_desc2->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATAllocatableAttr=
((EQ(ZERO(), 1)
) ? (1
) : (0))
;
/*SPC(3776)*/
_currn->_ATBoundsList=_currn->_AT_BoundsauxList;
/*SPC(11356)*/
_currn->_desc3->_ATDoAcc_pre=_currn->_desc2->_ATDoAcc_post;
/*SPC(0)*/
_currn->_desc3->_ATStmtNumber_pre=_currn->_desc2->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_desc3->_ATUpdate_pre=_currn->_desc2->_ATUpdate_post;
/*SPC(0)*/
_currn->_desc3->_ATAccDoLoopDim_pre=_currn->_desc2->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_desc3->_ATNestLevel_pre=_currn->_desc2->_ATNestLevel_post;
/*SPC(0)*/
_currn->_desc3->_ATCPURegionNumber_pre=_currn->_desc2->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_desc3->_ATAccRegionNumber_pre=_currn->_desc2->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_desc3->_ATAcceleratorRegion_pre=_currn->_desc2->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_desc3->_ATIndentLevel_pre=_currn->_desc2->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_desc3->_ATLocalIndex_pre=_currn->_desc2->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_desc3->_ATArrayId_pre=_currn->_desc2->_ATArrayId_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);
_currn->_AT_cBoundsListPtr_post=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_ATDoAcc_post=_currn->_desc3->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc3->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc3->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc3->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc3->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc3->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc3->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc3->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc3->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc3->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc3->_ATArrayId_post;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_desc3->_ATIsArray_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_desc3->_ATTypeLength_post;
/*SPC(0)*/
_currn->_ATPtg=
((GE(_currn->_desc3->_ATOutput, 1)
) ? (PTGVariableDecls(PTGNull(), _currn->_desc2->_ATPtg, _currn->_desc3->_ATPtg)
) : (PTGNULL))
;
/*SPC(4081)*/
_currn->_ATSizeValue=0;
/*SPC(3129)*/

if (OR(EQ(strcmp(MapFile(_currn->_AT_line), StringTable(GetClpValue(FileName, 0))), 0), AND(EQ(GetClpValue(ModuleUse, 1), 1), GE(isModule(_currn->_AT_line), 1)))) {

if (AND(EQ(GetClpValue(Generate, 1), 0), GE(_currn->_desc3->_ATOutput, 1))) {

if (EQ(isModule(_currn->_AT_line), 0)) {
PTGOut(PTGReplace(PTGNumb(MapLine(_currn->_AT_line)), PTGIndent(_currn->_desc1->_ATIndentLevel_post), _currn->_ATPtg));

} else {
PTGOut(PTGExtern(PTGNumb(isModule(_currn->_AT_line)), PTGIndent(_currn->_desc1->_ATIndentLevel_post), _currn->_ATPtg));
}
;

} else {

if (EQ(strcmp(MapFile(_currn->_AT_line), StringTable(GetClpValue(FileName, 0))), 0)) {
PTGOut(PTGRemove(PTGNumb(MapLine(_currn->_AT_line))));

} else {
}
;
}
;

} else {
}
;
/*SPC(4110)*/
_IG_incl40=_IL_incl40;
_IG_incl35=_IL_incl35;
_IG_incl34=_IL_incl34;
_IG_incl33=_IL_incl33;
_IG_incl32=_IL_incl32;
_IG_incl29=_IL_incl29;
_IG_incl28=_IL_incl28;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_923(_TPPrule_923 _currn)
#else
void _VS1rule_923(_currn )
_TPPrule_923 _currn;

#endif
{
int* _IL_incl32;

_VisitVarDecl()
_VisitEntry();
_IL_incl32=_IG_incl32;_IG_incl32= &(_currn->_ATDims);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_desc3->_ATOrder_pre=_currn->_desc2->_ATOrder_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);
_currn->_ATDims=_currn->_desc3->_AT_const42;
/*SPC(3132)*/
_currn->_desc4->_ATOrder_pre=_currn->_desc3->_ATOrder_post;
/*SPC(0)*/
_currn->_desc4->_ATType=_currn->_desc2->_ATType;
/*SPC(2001)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc4->_prod])))((NODEPTR) _currn->_desc4);
_currn->_ATOrder_post=_currn->_desc4->_ATOrder_post;
/*SPC(0)*/
_IG_incl32=_IL_incl32;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_923(_TPPrule_923 _currn)
#else
void _VS2rule_923(_currn )
_TPPrule_923 _currn;

#endif
{
int* _IL_incl32;

_VisitVarDecl()
_VisitEntry();
_IL_incl32=_IG_incl32;_IG_incl32= &(_currn->_ATDims);
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATExecutable=0;
/*SPC(998)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATLastNonExecLine_pre=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_desc2->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
_currn->_desc2->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_desc3->_ATLastNonExecLine_pre=_currn->_desc2->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_desc3->_ATArgCnt_pre=_currn->_desc2->_ATArgCnt_post;
/*SPC(0)*/
_currn->_desc3->_ATIsArray_pre=_currn->_desc2->_ATIsArray_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);
_currn->_desc4->_ATLastNonExecLine_pre=_currn->_desc3->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_desc4->_ATArgCnt_pre=_currn->_desc3->_ATArgCnt_post;
/*SPC(0)*/
_currn->_desc4->_ATIsArray_pre=_currn->_desc3->_ATIsArray_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc4->_prod])))((NODEPTR) _currn->_desc4);
_currn->_ATLastNonExecLine_post=_currn->_desc4->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc4->_ATArgCnt_post;
/*SPC(0)*/
_IG_incl32=_IL_incl32;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_923(_TPPrule_923 _currn)
#else
void _VS3rule_923(_currn )
_TPPrule_923 _currn;

#endif
{
int* _IL_incl32;

_VisitVarDecl()
_VisitEntry();
_IL_incl32=_IG_incl32;_IG_incl32= &(_currn->_ATDims);
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc4->_prod])))((NODEPTR) _currn->_desc4);
_IG_incl32=_IL_incl32;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_923(_TPPrule_923 _currn)
#else
void _VS4rule_923(_currn )
_TPPrule_923 _currn;

#endif
{
int* _IL_incl40;
int* _IL_incl35;
int* _IL_incl33;
int* _IL_incl32;
int* _IL_incl28;

_VisitVarDecl()
_VisitEntry();
_IL_incl40=_IG_incl40;_IG_incl40= &(_currn->_ATParameterAttr);
_IL_incl35=_IG_incl35;_IG_incl35= &(_currn->_ATIntent);
_IL_incl33=_IG_incl33;_IG_incl33= &(_currn->_ATAttrDecl);
_IL_incl32=_IG_incl32;_IG_incl32= &(_currn->_ATDims);
_IL_incl28=_IG_incl28;_IG_incl28= &(_currn->_ATParameterAttr);
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_BoundsauxList=NULLBoundsList;
/*SPC(11354)*/
_currn->_desc1->_AT_cBoundsListPtr_pre=_BoundsListADDROF(_currn->_AT_BoundsauxList);
/*SPC(11355)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_AT_cBoundsListPtr_pre=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_desc2->_ATTypeLength_pre=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_desc3->_AT_cBoundsListPtr_pre=_currn->_desc2->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_desc3->_ATTypeLength_pre=_currn->_desc2->_ATTypeLength_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);
_currn->_ATParameterAttr=
((EQ(_currn->_desc3->_AT_const39, 1)
) ? (1
) : (0))
;
/*SPC(3698)*/
_currn->_ATIntent=_currn->_desc3->_AT_const44;
/*SPC(3614)*/
_currn->_ATAttrDecl=1;
/*SPC(3046)*/
_currn->_desc4->_AT_cBoundsListPtr_pre=_currn->_desc3->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_desc4->_ATTypeLength_pre=_currn->_desc3->_ATTypeLength_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc4->_prod])))((NODEPTR) _currn->_desc4);
_IG_incl40=_IL_incl40;
_IG_incl35=_IL_incl35;
_IG_incl33=_IL_incl33;
_IG_incl32=_IL_incl32;
_IG_incl28=_IL_incl28;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5rule_923(_TPPrule_923 _currn)
#else
void _VS5rule_923(_currn )
_TPPrule_923 _currn;

#endif
{
int* _IL_incl40;
int* _IL_incl35;
BoundsList* _IL_incl34;
int* _IL_incl33;
int* _IL_incl32;
int* _IL_incl29;
int* _IL_incl28;

_VisitVarDecl()
_VisitEntry();
_IL_incl40=_IG_incl40;_IG_incl40= &(_currn->_ATParameterAttr);
_IL_incl35=_IG_incl35;_IG_incl35= &(_currn->_ATIntent);
_IL_incl34=_IG_incl34;_IG_incl34= &(_currn->_ATBoundsList);
_IL_incl33=_IG_incl33;_IG_incl33= &(_currn->_ATAttrDecl);
_IL_incl32=_IG_incl32;_IG_incl32= &(_currn->_ATDims);
_IL_incl29=_IG_incl29;_IG_incl29= &(_currn->_ATAllocatableAttr);
_IL_incl28=_IG_incl28;_IG_incl28= &(_currn->_ATParameterAttr);
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS6MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS7MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS8MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATDoAcc_pre=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_desc2->_ATStmtNumber_pre=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATUpdate_pre=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_desc2->_ATAccDoLoopDim_pre=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_desc2->_ATNestLevel_pre=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_desc2->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc2->_ATAccRegionNumber_pre=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc2->_ATIndentLevel_pre=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_desc2->_ATLocalIndex_pre=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_desc2->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_desc3->_ATDoAcc_pre=_currn->_desc2->_ATDoAcc_post;
/*SPC(0)*/
_currn->_desc3->_ATStmtNumber_pre=_currn->_desc2->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_desc3->_ATUpdate_pre=_currn->_desc2->_ATUpdate_post;
/*SPC(0)*/
_currn->_desc3->_ATAccDoLoopDim_pre=_currn->_desc2->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_desc3->_ATNestLevel_pre=_currn->_desc2->_ATNestLevel_post;
/*SPC(0)*/
_currn->_desc3->_ATCPURegionNumber_pre=_currn->_desc2->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_desc3->_ATAccRegionNumber_pre=_currn->_desc2->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_desc3->_ATAcceleratorRegion_pre=_currn->_desc2->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_desc3->_ATIndentLevel_pre=_currn->_desc2->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_desc3->_ATLocalIndex_pre=_currn->_desc2->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_desc3->_ATArrayId_pre=_currn->_desc2->_ATArrayId_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);
_currn->_ATAllocatableAttr=
((EQ(_currn->_desc3->_AT_const40, 1)
) ? (1
) : (0))
;
/*SPC(3757)*/
_currn->_ATBoundsList=_currn->_AT_BoundsauxList;
/*SPC(11356)*/
_currn->_desc4->_ATDoAcc_pre=_currn->_desc3->_ATDoAcc_post;
/*SPC(0)*/
_currn->_desc4->_ATStmtNumber_pre=_currn->_desc3->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_desc4->_ATUpdate_pre=_currn->_desc3->_ATUpdate_post;
/*SPC(0)*/
_currn->_desc4->_ATAccDoLoopDim_pre=_currn->_desc3->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_desc4->_ATNestLevel_pre=_currn->_desc3->_ATNestLevel_post;
/*SPC(0)*/
_currn->_desc4->_ATCPURegionNumber_pre=_currn->_desc3->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_desc4->_ATAccRegionNumber_pre=_currn->_desc3->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_desc4->_ATAcceleratorRegion_pre=_currn->_desc3->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_desc4->_ATIndentLevel_pre=_currn->_desc3->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_desc4->_ATLocalIndex_pre=_currn->_desc3->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_desc4->_ATArrayId_pre=_currn->_desc3->_ATArrayId_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc4->_prod])))((NODEPTR) _currn->_desc4);

if (OR(EQ(strcmp(MapFile(_currn->_AT_line), StringTable(GetClpValue(FileName, 0))), 0), AND(EQ(GetClpValue(ModuleUse, 1), 1), GE(isModule(_currn->_AT_line), 1)))) {

if (AND(EQ(GetClpValue(Generate, 1), 0), GE(_currn->_desc3->_AT_const39, 1))) {
PTGOut(PTGDefAppend(PTGNumber(MapLine(_currn->_AT_line)), PTGNumber((* _IG_incl36)), _currn->_desc4->_AT_const45));

} else {

if (EQ(strcmp(MapFile(_currn->_AT_line), StringTable(GetClpValue(FileName, 0))), 0)) {
PTGOut(PTGRemove(PTGNumber(MapLine(_currn->_AT_line))));

} else {
}
;
}
;

} else {
}
;
/*SPC(3732)*/
_currn->_AT_cBoundsListPtr_post=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_ATDoAcc_post=_currn->_desc4->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc4->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc4->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc4->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc4->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc4->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc4->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc4->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc4->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc4->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc4->_ATArrayId_post;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_desc4->_ATIsArray_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_desc4->_ATTypeLength_post;
/*SPC(0)*/
_currn->_ATPtg=
((GE(_currn->_desc4->_ATOutput, 1)
) ? (PTGVariableDecls(_currn->_desc3->_AT_const41, _currn->_desc2->_ATPtg, _currn->_desc4->_ATPtg)
) : (PTGNULL))
;
/*SPC(4153)*/
_currn->_ATSizeValue=_currn->_desc3->_AT_const43;
/*SPC(3134)*/

if (OR(EQ(strcmp(MapFile(_currn->_AT_line), StringTable(GetClpValue(FileName, 0))), 0), AND(EQ(GetClpValue(ModuleUse, 1), 1), GE(isModule(_currn->_AT_line), 1)))) {

if (EQ(_currn->_desc3->_AT_const39, 0)) {

if (AND(EQ(GetClpValue(Generate, 1), 0), GE(_currn->_desc4->_ATOutput, 1))) {

if (EQ(isModule(_currn->_AT_line), 0)) {
PTGOut(PTGReplace(PTGNumb(MapLine(_currn->_AT_line)), PTGIndent(_currn->_desc1->_ATIndentLevel_post), _currn->_ATPtg));

} else {
PTGOut(PTGExtern(PTGNumb(isModule(_currn->_AT_line)), PTGIndent(_currn->_desc1->_ATIndentLevel_post), _currn->_ATPtg));
}
;

} else {

if (EQ(strcmp(MapFile(_currn->_AT_line), StringTable(GetClpValue(FileName, 0))), 0)) {
PTGOut(PTGRemove(PTGNumb(MapLine(_currn->_AT_line))));

} else {
}
;
}
;

} else {
}
;

} else {
}
;
/*SPC(4185)*/
_IG_incl40=_IL_incl40;
_IG_incl35=_IL_incl35;
_IG_incl34=_IL_incl34;
_IG_incl33=_IL_incl33;
_IG_incl32=_IL_incl32;
_IG_incl29=_IL_incl29;
_IG_incl28=_IL_incl28;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_924(_TPPrule_924 _currn)
#else
void _VS1rule_924(_currn )
_TPPrule_924 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATOrder_post=_currn->_desc1->_ATOrder_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_924(_TPPrule_924 _currn)
#else
void _VS2rule_924(_currn )
_TPPrule_924 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATLastNonExecLine_post=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc1->_ATArgCnt_post;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_desc1->_ATIsArray_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_924(_TPPrule_924 _currn)
#else
void _VS3rule_924(_currn )
_TPPrule_924 _currn;

#endif
{
int* _IL_incl42;

_VisitVarDecl()
_VisitEntry();
_IL_incl42=_IG_incl42;_IG_incl42= &(_currn->_ATKindLen);
_currn->_desc1->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATKindLen=1;
/*SPC(3588)*/
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS6MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_cBoundsListPtr_post=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/
_IG_incl42=_IL_incl42;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_924(_TPPrule_924 _currn)
#else
void _VS4rule_924(_currn )
_TPPrule_924 _currn;

#endif
{
int* _IL_incl42;

_VisitVarDecl()
_VisitEntry();
_IL_incl42=_IG_incl42;_IG_incl42= &(_currn->_ATKindLen);
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS7MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS8MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS9MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS10MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATDoAcc_post=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc1->_ATArrayId_post;
/*SPC(0)*/
_IG_incl42=_IL_incl42;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_925(_TPPrule_925 _currn)
#else
void _VS1rule_925(_currn )
_TPPrule_925 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATOrder_post=_currn->_desc1->_ATOrder_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_925(_TPPrule_925 _currn)
#else
void _VS2rule_925(_currn )
_TPPrule_925 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATLastNonExecLine_post=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc1->_ATArgCnt_post;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_desc1->_ATIsArray_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_925(_TPPrule_925 _currn)
#else
void _VS3rule_925(_currn )
_TPPrule_925 _currn;

#endif
{
int* _IL_incl42;

_VisitVarDecl()
_VisitEntry();
_IL_incl42=_IG_incl42;_IG_incl42= &(_currn->_ATKindLen);
_currn->_desc1->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATKindLen=1;
/*SPC(3584)*/
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS6MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_cBoundsListPtr_post=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/
_IG_incl42=_IL_incl42;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_925(_TPPrule_925 _currn)
#else
void _VS4rule_925(_currn )
_TPPrule_925 _currn;

#endif
{
int* _IL_incl42;

_VisitVarDecl()
_VisitEntry();
_IL_incl42=_IG_incl42;_IG_incl42= &(_currn->_ATKindLen);
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS7MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS8MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS9MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS10MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATDoAcc_post=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc1->_ATArrayId_post;
/*SPC(0)*/
_IG_incl42=_IL_incl42;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_926(_TPPrule_926 _currn)
#else
void _VS1rule_926(_currn )
_TPPrule_926 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATOrder_post=_currn->_ATOrder_pre;
/*SPC(0)*/
_currn->_ATType=DoublePrecisionType;
/*SPC(1990)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_926(_TPPrule_926 _currn)
#else
void _VS2rule_926(_currn )
_TPPrule_926 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATLastNonExecLine_post=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_ATArgCnt_pre;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_ATIsArray_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_926(_TPPrule_926 _currn)
#else
void _VS3rule_926(_currn )
_TPPrule_926 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_AT_cBoundsListPtr_post=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_ATTypeLength_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_926(_TPPrule_926 _currn)
#else
void _VS4rule_926(_currn )
_TPPrule_926 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATDoAcc_post=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_ATArrayId_pre;
/*SPC(0)*/
_currn->_ATPtg=PTGAsIs("double");
/*SPC(3418)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_927(_TPPrule_927 _currn)
#else
void _VS1rule_927(_currn )
_TPPrule_927 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATOrder_post=_currn->_ATOrder_pre;
/*SPC(0)*/
_currn->_ATType=DoublePrecisionType;
/*SPC(1986)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_927(_TPPrule_927 _currn)
#else
void _VS2rule_927(_currn )
_TPPrule_927 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATLastNonExecLine_post=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_ATArgCnt_pre;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_ATIsArray_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_927(_TPPrule_927 _currn)
#else
void _VS3rule_927(_currn )
_TPPrule_927 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_AT_cBoundsListPtr_post=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_ATTypeLength_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_927(_TPPrule_927 _currn)
#else
void _VS4rule_927(_currn )
_TPPrule_927 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATDoAcc_post=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_ATArrayId_pre;
/*SPC(0)*/
_currn->_ATPtg=PTGAsIs("double");
/*SPC(3414)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_928(_TPPrule_928 _currn)
#else
void _VS1rule_928(_currn )
_TPPrule_928 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/

if (EQ(strcmp(MapFile(_currn->_AT_line), StringTable(GetClpValue(FileName, 0))), 0)) {
message(WARNING, "F2C-ACC ERROR: Type not supported", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(3467)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATOrder_post=_currn->_desc1->_ATOrder_post;
/*SPC(0)*/
_currn->_ATType=ComplexType;
/*SPC(1982)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_928(_TPPrule_928 _currn)
#else
void _VS2rule_928(_currn )
_TPPrule_928 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
_currn->_desc1->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATLastNonExecLine_post=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc1->_ATArgCnt_post;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_desc1->_ATIsArray_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_928(_TPPrule_928 _currn)
#else
void _VS3rule_928(_currn )
_TPPrule_928 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_cBoundsListPtr_post=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_928(_TPPrule_928 _currn)
#else
void _VS4rule_928(_currn )
_TPPrule_928 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_desc1->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATDoAcc_post=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc1->_ATArrayId_post;
/*SPC(0)*/
_currn->_ATPtg=PTGNULL;
/*SPC(3305)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_929(_TPPrule_929 _currn)
#else
void _VS1rule_929(_currn )
_TPPrule_929 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATOrder_post=_currn->_ATOrder_pre;
/*SPC(0)*/
_currn->_ATType=LogicalType;
/*SPC(1976)*/

if (EQ(strcmp(MapFile(_currn->_AT_line), StringTable(GetClpValue(FileName, 0))), 0)) {
message(WARNING, "F2C-ACC ERROR: Type not supported", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(3409)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_929(_TPPrule_929 _currn)
#else
void _VS2rule_929(_currn )
_TPPrule_929 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATLastNonExecLine_post=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_ATArgCnt_pre;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_ATIsArray_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_929(_TPPrule_929 _currn)
#else
void _VS3rule_929(_currn )
_TPPrule_929 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_AT_cBoundsListPtr_post=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_ATTypeLength_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_929(_TPPrule_929 _currn)
#else
void _VS4rule_929(_currn )
_TPPrule_929 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATDoAcc_post=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_ATArrayId_pre;
/*SPC(0)*/
_currn->_ATPtg=PTGNULL;
/*SPC(3305)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_930(_TPPrule_930 _currn)
#else
void _VS1rule_930(_currn )
_TPPrule_930 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/

if (EQ(strcmp(MapFile(_currn->_AT_line), StringTable(GetClpValue(FileName, 0))), 0)) {
message(WARNING, "F2C-ACC WARNING: Type length not supported", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(3327)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATOrder_post=_currn->_desc1->_ATOrder_post;
/*SPC(0)*/
_currn->_ATType=LogicalType;
/*SPC(1972)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_930(_TPPrule_930 _currn)
#else
void _VS2rule_930(_currn )
_TPPrule_930 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
_currn->_desc1->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATLastNonExecLine_post=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc1->_ATArgCnt_post;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_desc1->_ATIsArray_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_930(_TPPrule_930 _currn)
#else
void _VS3rule_930(_currn )
_TPPrule_930 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_cBoundsListPtr_post=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_930(_TPPrule_930 _currn)
#else
void _VS4rule_930(_currn )
_TPPrule_930 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_desc1->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATDoAcc_post=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc1->_ATArrayId_post;
/*SPC(0)*/
_currn->_ATPtg=PTGAsIs("static int");
/*SPC(3325)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_931(_TPPrule_931 _currn)
#else
void _VS1rule_931(_currn )
_TPPrule_931 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATOrder_post=_currn->_desc1->_ATOrder_post;
/*SPC(0)*/
_currn->_ATType=RealType;
/*SPC(1967)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_931(_TPPrule_931 _currn)
#else
void _VS2rule_931(_currn )
_TPPrule_931 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
_currn->_desc1->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATLastNonExecLine_post=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc1->_ATArgCnt_post;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_desc1->_ATIsArray_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_931(_TPPrule_931 _currn)
#else
void _VS3rule_931(_currn )
_TPPrule_931 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_cBoundsListPtr_post=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_931(_TPPrule_931 _currn)
#else
void _VS4rule_931(_currn )
_TPPrule_931 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_desc1->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

if (EQ(strcmp(MapFile(_currn->_AT_line), StringTable(GetClpValue(FileName, 0))), 0)) {

if (AND(NE(_currn->_desc1->_ATLength, 4), NE(_currn->_desc1->_ATLength, 8))) {
message(WARNING, "F2C-ACC ERROR: Length not supported", 0, (&( _currn->_AT_pos)));

} else {
}
;

} else {
}
;
/*SPC(3460)*/
_currn->_ATDoAcc_post=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc1->_ATArrayId_post;
/*SPC(0)*/
_currn->_ATPtg=
((OR(EQ(_currn->_desc1->_ATLength, 4), EQ(_currn->_desc1->_ATLength, 8))
) ? (
((EQ(_currn->_desc1->_ATLength, 4)
) ? (PTGAsIs("float")
) : (PTGAsIs("double")))

) : (PTGAsIs("**float**")))
;
/*SPC(3447)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_932(_TPPrule_932 _currn)
#else
void _VS1rule_932(_currn )
_TPPrule_932 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATOrder_post=_currn->_desc1->_ATOrder_post;
/*SPC(0)*/
_currn->_ATType=IntegerType;
/*SPC(1962)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_932(_TPPrule_932 _currn)
#else
void _VS2rule_932(_currn )
_TPPrule_932 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
_currn->_desc1->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATLastNonExecLine_post=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc1->_ATArgCnt_post;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_desc1->_ATIsArray_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_932(_TPPrule_932 _currn)
#else
void _VS3rule_932(_currn )
_TPPrule_932 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_cBoundsListPtr_post=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_932(_TPPrule_932 _currn)
#else
void _VS4rule_932(_currn )
_TPPrule_932 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_desc1->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

if (EQ(strcmp(MapFile(_currn->_AT_line), StringTable(GetClpValue(FileName, 0))), 0)) {

if (AND(NE(_currn->_desc1->_ATLength, 4), NE(_currn->_desc1->_ATLength, 8))) {
message(WARNING, "F2C-ACC ERROR: Length not supported", 0, (&( _currn->_AT_pos)));

} else {
}
;

} else {
}
;
/*SPC(3441)*/
_currn->_ATDoAcc_post=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc1->_ATArrayId_post;
/*SPC(0)*/
_currn->_ATPtg=
((OR(EQ(_currn->_desc1->_ATLength, 4), EQ(_currn->_desc1->_ATLength, 8))
) ? (
((EQ(_currn->_desc1->_ATLength, 4)
) ? (PTGAsIs("int")
) : (PTGAsIs("long")))

) : (PTGAsIs("**int**")))
;
/*SPC(3428)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_933(_TPPrule_933 _currn)
#else
void _VS1rule_933(_currn )
_TPPrule_933 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/

if (EQ(strcmp(MapFile(_currn->_AT_line), StringTable(GetClpValue(FileName, 0))), 0)) {
message(WARNING, "F2C-ACC ERROR: Type not supported", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(3423)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATOrder_post=_currn->_desc1->_ATOrder_post;
/*SPC(0)*/
_currn->_ATType=CharacterType;
/*SPC(1957)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_933(_TPPrule_933 _currn)
#else
void _VS2rule_933(_currn )
_TPPrule_933 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
_currn->_desc1->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATLastNonExecLine_post=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc1->_ATArgCnt_post;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_desc1->_ATIsArray_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_933(_TPPrule_933 _currn)
#else
void _VS3rule_933(_currn )
_TPPrule_933 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_cBoundsListPtr_post=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_933(_TPPrule_933 _currn)
#else
void _VS4rule_933(_currn )
_TPPrule_933 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_desc1->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATDoAcc_post=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc1->_ATArrayId_post;
/*SPC(0)*/
_currn->_ATPtg=PTGNULL;
/*SPC(3305)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_934(_TPPrule_934 _currn)
#else
void _VS1rule_934(_currn )
_TPPrule_934 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATOrder_post=_currn->_ATOrder_pre;
/*SPC(0)*/
_currn->_ATType=CharacterType;
/*SPC(1952)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_934(_TPPrule_934 _currn)
#else
void _VS2rule_934(_currn )
_TPPrule_934 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATLastNonExecLine_post=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_ATArgCnt_pre;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_ATIsArray_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_934(_TPPrule_934 _currn)
#else
void _VS3rule_934(_currn )
_TPPrule_934 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_AT_cBoundsListPtr_post=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_ATTypeLength_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_934(_TPPrule_934 _currn)
#else
void _VS4rule_934(_currn )
_TPPrule_934 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATDoAcc_post=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_ATArrayId_pre;
/*SPC(0)*/
_currn->_ATPtg=PTGAsIs("char");
/*SPC(3404)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_935(_TPPrule_935 _currn)
#else
void _VS1rule_935(_currn )
_TPPrule_935 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/

if (EQ(strcmp(MapFile(_currn->_AT_line), StringTable(GetClpValue(FileName, 0))), 0)) {
message(WARNING, "F2C-ACC WARNING: Type length not supported", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(3334)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATOrder_post=_currn->_desc1->_ATOrder_post;
/*SPC(0)*/
_currn->_ATType=LogicalType;
/*SPC(1946)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_935(_TPPrule_935 _currn)
#else
void _VS2rule_935(_currn )
_TPPrule_935 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
_currn->_desc1->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATLastNonExecLine_post=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc1->_ATArgCnt_post;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_desc1->_ATIsArray_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_935(_TPPrule_935 _currn)
#else
void _VS3rule_935(_currn )
_TPPrule_935 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_cBoundsListPtr_post=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_935(_TPPrule_935 _currn)
#else
void _VS4rule_935(_currn )
_TPPrule_935 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_desc1->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATDoAcc_post=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc1->_ATArrayId_post;
/*SPC(0)*/
_currn->_ATPtg=PTGAsIs("static int");
/*SPC(3332)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_936(_TPPrule_936 _currn)
#else
void _VS1rule_936(_currn )
_TPPrule_936 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATOrder_post=_currn->_ATOrder_pre;
/*SPC(0)*/
_currn->_ATType=LogicalType;
/*SPC(1941)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_936(_TPPrule_936 _currn)
#else
void _VS2rule_936(_currn )
_TPPrule_936 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATLastNonExecLine_post=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_ATArgCnt_pre;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_ATIsArray_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_936(_TPPrule_936 _currn)
#else
void _VS3rule_936(_currn )
_TPPrule_936 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_AT_cBoundsListPtr_post=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_ATTypeLength_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_936(_TPPrule_936 _currn)
#else
void _VS4rule_936(_currn )
_TPPrule_936 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATDoAcc_post=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_ATArrayId_pre;
/*SPC(0)*/
_currn->_ATPtg=PTGAsIs("static int");
/*SPC(3321)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_937(_TPPrule_937 _currn)
#else
void _VS1rule_937(_currn )
_TPPrule_937 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/

if (EQ(strcmp(MapFile(_currn->_AT_line), StringTable(GetClpValue(FileName, 0))), 0)) {
message(WARNING, "F2C-ACC ERROR: Type not supported", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(3340)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATOrder_post=_currn->_desc1->_ATOrder_post;
/*SPC(0)*/
_currn->_ATType=ComplexType;
/*SPC(1935)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_937(_TPPrule_937 _currn)
#else
void _VS2rule_937(_currn )
_TPPrule_937 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
_currn->_desc1->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATLastNonExecLine_post=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc1->_ATArgCnt_post;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_desc1->_ATIsArray_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_937(_TPPrule_937 _currn)
#else
void _VS3rule_937(_currn )
_TPPrule_937 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_AT_cBoundsListPtr_post=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_937(_TPPrule_937 _currn)
#else
void _VS4rule_937(_currn )
_TPPrule_937 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_desc1->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATDoAcc_post=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc1->_ATArrayId_post;
/*SPC(0)*/
_currn->_ATPtg=PTGNULL;
/*SPC(3305)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_938(_TPPrule_938 _currn)
#else
void _VS1rule_938(_currn )
_TPPrule_938 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATOrder_post=_currn->_ATOrder_pre;
/*SPC(0)*/
_currn->_ATType=ComplexType;
/*SPC(1930)*/

if (EQ(strcmp(MapFile(_currn->_AT_line), StringTable(GetClpValue(FileName, 0))), 0)) {
message(WARNING, "F2C-ACC ERROR: Type not supported", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(3316)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_938(_TPPrule_938 _currn)
#else
void _VS2rule_938(_currn )
_TPPrule_938 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATLastNonExecLine_post=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_ATArgCnt_pre;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_ATIsArray_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_938(_TPPrule_938 _currn)
#else
void _VS3rule_938(_currn )
_TPPrule_938 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_AT_cBoundsListPtr_post=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_ATTypeLength_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_938(_TPPrule_938 _currn)
#else
void _VS4rule_938(_currn )
_TPPrule_938 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATDoAcc_post=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_ATArrayId_pre;
/*SPC(0)*/
_currn->_ATPtg=PTGNULL;
/*SPC(3305)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_939(_TPPrule_939 _currn)
#else
void _VS1rule_939(_currn )
_TPPrule_939 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATOrder_post=_currn->_desc1->_ATOrder_post;
/*SPC(0)*/
_currn->_ATType=RealType;
/*SPC(1924)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_939(_TPPrule_939 _currn)
#else
void _VS2rule_939(_currn )
_TPPrule_939 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
_currn->_desc1->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATLastNonExecLine_post=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc1->_ATArgCnt_post;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_desc1->_ATIsArray_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_939(_TPPrule_939 _currn)
#else
void _VS3rule_939(_currn )
_TPPrule_939 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

if (AND(NE(_currn->_desc1->_ATTypeLength_post, 4), NE(_currn->_desc1->_ATTypeLength_post, 8))) {
message(ERROR, "Kind not supported.", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(3551)*/
_currn->_AT_cBoundsListPtr_post=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_939(_TPPrule_939 _currn)
#else
void _VS4rule_939(_currn )
_TPPrule_939 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_desc1->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATDoAcc_post=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc1->_ATArrayId_post;
/*SPC(0)*/
_currn->_ATPtg=
((EQ(_currn->_desc1->_ATTypeLength_post, 4)
) ? (PTGAsIs("float")
) : (PTGAsIs("double")))
;
/*SPC(3544)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_940(_TPPrule_940 _currn)
#else
void _VS1rule_940(_currn )
_TPPrule_940 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATOrder_post=_currn->_ATOrder_pre;
/*SPC(0)*/
_currn->_ATType=RealType;
/*SPC(1919)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_940(_TPPrule_940 _currn)
#else
void _VS2rule_940(_currn )
_TPPrule_940 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATLastNonExecLine_post=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_ATArgCnt_pre;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_ATIsArray_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_940(_TPPrule_940 _currn)
#else
void _VS3rule_940(_currn )
_TPPrule_940 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_AT_cBoundsListPtr_post=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_ATTypeLength_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_940(_TPPrule_940 _currn)
#else
void _VS4rule_940(_currn )
_TPPrule_940 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATDoAcc_post=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_ATArrayId_pre;
/*SPC(0)*/
_currn->_ATPtg=PTGAsIs("float");
/*SPC(3311)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_941(_TPPrule_941 _currn)
#else
void _VS1rule_941(_currn )
_TPPrule_941 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATOrder_post=_currn->_desc1->_ATOrder_post;
/*SPC(0)*/
_currn->_ATType=IntegerType;
/*SPC(1913)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_941(_TPPrule_941 _currn)
#else
void _VS2rule_941(_currn )
_TPPrule_941 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
_currn->_desc1->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATLastNonExecLine_post=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc1->_ATArgCnt_post;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_desc1->_ATIsArray_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_941(_TPPrule_941 _currn)
#else
void _VS3rule_941(_currn )
_TPPrule_941 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

if (AND(NE(_currn->_desc1->_ATTypeLength_post, 2), AND(NE(_currn->_desc1->_ATTypeLength_post, 4), NE(_currn->_desc1->_ATTypeLength_post, 8)))) {
message(ERROR, "Kind not supported.", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(3539)*/
_currn->_AT_cBoundsListPtr_post=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_941(_TPPrule_941 _currn)
#else
void _VS4rule_941(_currn )
_TPPrule_941 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_desc1->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATDoAcc_post=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc1->_ATArrayId_post;
/*SPC(0)*/
_currn->_ATPtg=
((EQ(_currn->_desc1->_ATTypeLength_post, 2)
) ? (PTGAsIs("short")
) : (
((EQ(_currn->_desc1->_ATTypeLength_post, 4)
) ? (PTGAsIs("int")
) : (
((EQ(_currn->_desc1->_ATTypeLength_post, 8)
) ? (PTGAsIs("long")
) : (PTGAsIs("")))
))
))
;
/*SPC(3525)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_942(_TPPrule_942 _currn)
#else
void _VS1rule_942(_currn )
_TPPrule_942 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATOrder_post=_currn->_ATOrder_pre;
/*SPC(0)*/
_currn->_ATType=IntegerType;
/*SPC(1908)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_942(_TPPrule_942 _currn)
#else
void _VS2rule_942(_currn )
_TPPrule_942 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATLastNonExecLine_post=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_ATArgCnt_pre;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_ATIsArray_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_942(_TPPrule_942 _currn)
#else
void _VS3rule_942(_currn )
_TPPrule_942 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_AT_cBoundsListPtr_post=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_ATTypeLength_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_942(_TPPrule_942 _currn)
#else
void _VS4rule_942(_currn )
_TPPrule_942 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATDoAcc_post=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_ATArrayId_pre;
/*SPC(0)*/
_currn->_ATPtg=PTGAsIs("int");
/*SPC(3307)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_943(_TPPrule_943 _currn)
#else
void _VS1rule_943(_currn )
_TPPrule_943 _currn;

#endif
{
DefTableKey* _IL_incl31;
DefTableKey* _IL_incl14;

_VisitVarDecl()
_VisitEntry();
_IL_incl31=_IG_incl31;_IG_incl31= &(_currn->_ATType);
_IL_incl14=_IG_incl14;_IG_incl14= &(_currn->_ATType);
_currn->_desc1->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
_currn->_desc1->_ATType=_currn->_ATType;
/*SPC(1902)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATOrder_pre=_currn->_desc1->_ATOrder_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATOrder_post=_currn->_desc2->_ATOrder_post;
/*SPC(0)*/
_IG_incl31=_IL_incl31;
_IG_incl14=_IL_incl14;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_943(_TPPrule_943 _currn)
#else
void _VS2rule_943(_currn )
_TPPrule_943 _currn;

#endif
{
DefTableKey* _IL_incl31;
DefTableKey* _IL_incl14;

_VisitVarDecl()
_VisitEntry();
_IL_incl31=_IG_incl31;_IG_incl31= &(_currn->_ATType);
_IL_incl14=_IG_incl14;_IG_incl14= &(_currn->_ATType);
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
_currn->_desc1->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATLastNonExecLine_pre=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_desc2->_ATArgCnt_pre=_currn->_desc1->_ATArgCnt_post;
/*SPC(0)*/
_currn->_desc2->_ATIsArray_pre=_currn->_desc1->_ATIsArray_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATLastNonExecLine_post=_currn->_desc2->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc2->_ATArgCnt_post;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_desc2->_ATIsArray_post;
/*SPC(0)*/
_IG_incl31=_IL_incl31;
_IG_incl14=_IL_incl14;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_943(_TPPrule_943 _currn)
#else
void _VS3rule_943(_currn )
_TPPrule_943 _currn;

#endif
{
DefTableKey* _IL_incl31;
DefTableKey* _IL_incl14;

_VisitVarDecl()
_VisitEntry();
_IL_incl31=_IG_incl31;_IG_incl31= &(_currn->_ATType);
_IL_incl14=_IG_incl14;_IG_incl14= &(_currn->_ATType);
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_IG_incl31=_IL_incl31;
_IG_incl14=_IL_incl14;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_943(_TPPrule_943 _currn)
#else
void _VS4rule_943(_currn )
_TPPrule_943 _currn;

#endif
{
DefTableKey* _IL_incl31;
DefTableKey* _IL_incl14;

_VisitVarDecl()
_VisitEntry();
_IL_incl31=_IG_incl31;_IG_incl31= &(_currn->_ATType);
_IL_incl14=_IG_incl14;_IG_incl14= &(_currn->_ATType);
_currn->_desc1->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_AT_cBoundsListPtr_pre=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_desc2->_ATTypeLength_pre=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_AT_cBoundsListPtr_post=_currn->_desc2->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_desc2->_ATTypeLength_post;
/*SPC(0)*/
_IG_incl31=_IL_incl31;
_IG_incl14=_IL_incl14;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5rule_943(_TPPrule_943 _currn)
#else
void _VS5rule_943(_currn )
_TPPrule_943 _currn;

#endif
{
DefTableKey* _IL_incl31;
DefTableKey* _IL_incl14;

_VisitVarDecl()
_VisitEntry();
_IL_incl31=_IG_incl31;_IG_incl31= &(_currn->_ATType);
_IL_incl14=_IG_incl14;_IG_incl14= &(_currn->_ATType);
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
_currn->_desc1->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATDoAcc_pre=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_desc2->_ATStmtNumber_pre=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATUpdate_pre=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_desc2->_ATAccDoLoopDim_pre=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_desc2->_ATNestLevel_pre=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_desc2->_ATCPURegionNumber_pre=_currn->_desc1->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATAccRegionNumber_pre=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATAcceleratorRegion_pre=_currn->_desc1->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_desc2->_ATIndentLevel_pre=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_desc2->_ATLocalIndex_pre=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_desc2->_ATArrayId_pre=_currn->_desc1->_ATArrayId_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_AT_const45=PTGSequence(_currn->_desc1->_AT_const45, IDENTICAL(_currn->_desc2->_ATDefinePtg));
/*SPC(1901)*/
_currn->_ATDoAcc_post=_currn->_desc2->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc2->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc2->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc2->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc2->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc2->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc2->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc2->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc2->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc2->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc2->_ATArrayId_post;
/*SPC(0)*/
_currn->_ATPtg=
((AND(GE(_currn->_desc1->_ATOutput, 1), EQ(_currn->_desc2->_ATOutput, 1))
) ? (PTGCommaArgs(_currn->_desc1->_ATPtg, _currn->_desc2->_ATPtg)
) : (
((OR(GE(_currn->_desc1->_ATOutput, 1), EQ(_currn->_desc2->_ATOutput, 1))
) ? (
((EQ(_currn->_desc2->_ATOutput, 1)
) ? (_currn->_desc2->_ATPtg
) : (_currn->_desc1->_ATPtg))

) : (PTGNULL))
))
;
/*SPC(4200)*/
_currn->_ATOutput=ADD(_currn->_desc1->_ATOutput, _currn->_desc2->_ATOutput);
/*SPC(4075)*/
_IG_incl31=_IL_incl31;
_IG_incl14=_IL_incl14;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_944(_TPPrule_944 _currn)
#else
void _VS1rule_944(_currn )
_TPPrule_944 _currn;

#endif
{
DefTableKey* _IL_incl14;

_VisitVarDecl()
_VisitEntry();
_IL_incl14=_IG_incl14;_IG_incl14= &(_currn->_ATType);

if (EQ(strcmp(MapFile(_currn->_AT_line), StringTable(GetClpValue(FileName, 0))), 0)) {
message(WARNING, "Language construct not currently supported at this time.", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(9491)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATType=_currn->_desc2->_ATType;
/*SPC(1851)*/
_currn->_desc3->_ATOrder_pre=_currn->_desc2->_ATOrder_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);
_currn->_ATOrder_post=_currn->_desc3->_ATOrder_post;
/*SPC(0)*/
_IG_incl14=_IL_incl14;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_944(_TPPrule_944 _currn)
#else
void _VS2rule_944(_currn )
_TPPrule_944 _currn;

#endif
{
DefTableKey* _IL_incl14;

_VisitVarDecl()
_VisitEntry();
_IL_incl14=_IG_incl14;_IG_incl14= &(_currn->_ATType);
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATExecutable=0;
/*SPC(998)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATLastNonExecLine_pre=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_desc2->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
_currn->_desc2->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_desc3->_ATLastNonExecLine_pre=_currn->_desc2->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_desc3->_ATArgCnt_pre=_currn->_desc2->_ATArgCnt_post;
/*SPC(0)*/
_currn->_desc3->_ATIsArray_pre=_currn->_desc2->_ATIsArray_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);
_currn->_ATLastNonExecLine_post=_currn->_desc3->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc3->_ATArgCnt_post;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_desc3->_ATIsArray_post;
/*SPC(0)*/
_IG_incl14=_IL_incl14;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_944(_TPPrule_944 _currn)
#else
void _VS3rule_944(_currn )
_TPPrule_944 _currn;

#endif
{
DefTableKey* _IL_incl14;

_VisitVarDecl()
_VisitEntry();
_IL_incl14=_IG_incl14;_IG_incl14= &(_currn->_ATType);
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);
_IG_incl14=_IL_incl14;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_944(_TPPrule_944 _currn)
#else
void _VS4rule_944(_currn )
_TPPrule_944 _currn;

#endif
{
DefTableKey* _IL_incl14;

_VisitVarDecl()
_VisitEntry();
_IL_incl14=_IG_incl14;_IG_incl14= &(_currn->_ATType);
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS6MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS7MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS8MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_AT_cBoundsListPtr_pre=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_desc2->_ATTypeLength_pre=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_desc2->_ATDoAcc_pre=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_desc2->_ATStmtNumber_pre=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATUpdate_pre=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_desc2->_ATAccDoLoopDim_pre=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_desc2->_ATNestLevel_pre=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_desc2->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc2->_ATAccRegionNumber_pre=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc2->_ATIndentLevel_pre=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_desc2->_ATLocalIndex_pre=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_desc2->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_desc3->_AT_cBoundsListPtr_pre=_currn->_desc2->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_desc3->_ATDoAcc_pre=_currn->_desc2->_ATDoAcc_post;
/*SPC(0)*/
_currn->_desc3->_ATStmtNumber_pre=_currn->_desc2->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_desc3->_ATUpdate_pre=_currn->_desc2->_ATUpdate_post;
/*SPC(0)*/
_currn->_desc3->_ATAccDoLoopDim_pre=_currn->_desc2->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_desc3->_ATNestLevel_pre=_currn->_desc2->_ATNestLevel_post;
/*SPC(0)*/
_currn->_desc3->_ATCPURegionNumber_pre=_currn->_desc2->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_desc3->_ATAccRegionNumber_pre=_currn->_desc2->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_desc3->_ATAcceleratorRegion_pre=_currn->_desc2->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_desc3->_ATIndentLevel_pre=_currn->_desc2->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_desc3->_ATLocalIndex_pre=_currn->_desc2->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_desc3->_ATArrayId_pre=_currn->_desc2->_ATArrayId_post;
/*SPC(0)*/
_currn->_desc3->_ATTypeLength_pre=_currn->_desc2->_ATTypeLength_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);
_currn->_AT_cBoundsListPtr_post=_currn->_desc3->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_ATDoAcc_post=_currn->_desc3->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc3->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc3->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc3->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc3->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc3->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc3->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc3->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc3->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc3->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc3->_ATArrayId_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_desc3->_ATTypeLength_post;
/*SPC(0)*/
_IG_incl14=_IL_incl14;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_945(_TPPrule_945 _currn)
#else
void _VS1rule_945(_currn )
_TPPrule_945 _currn;

#endif
{
DefTableKey* _IL_incl14;

_VisitVarDecl()
_VisitEntry();
_IL_incl14=_IG_incl14;_IG_incl14= &(_currn->_ATType);

if (EQ(strcmp(MapFile(_currn->_AT_line), StringTable(GetClpValue(FileName, 0))), 0)) {
message(WARNING, "Language construct not currently supported at this time.", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(9485)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATType=_currn->_desc2->_ATType;
/*SPC(1847)*/
_currn->_desc3->_ATOrder_pre=_currn->_desc2->_ATOrder_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);
_currn->_ATOrder_post=_currn->_desc3->_ATOrder_post;
/*SPC(0)*/
_IG_incl14=_IL_incl14;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_945(_TPPrule_945 _currn)
#else
void _VS2rule_945(_currn )
_TPPrule_945 _currn;

#endif
{
DefTableKey* _IL_incl14;

_VisitVarDecl()
_VisitEntry();
_IL_incl14=_IG_incl14;_IG_incl14= &(_currn->_ATType);
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATExecutable=0;
/*SPC(998)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATLastNonExecLine_pre=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_desc2->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
_currn->_desc2->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_desc3->_ATLastNonExecLine_pre=_currn->_desc2->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_desc3->_ATArgCnt_pre=_currn->_desc2->_ATArgCnt_post;
/*SPC(0)*/
_currn->_desc3->_ATIsArray_pre=_currn->_desc2->_ATIsArray_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);
_currn->_ATLastNonExecLine_post=_currn->_desc3->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc3->_ATArgCnt_post;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_desc3->_ATIsArray_post;
/*SPC(0)*/
_IG_incl14=_IL_incl14;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_945(_TPPrule_945 _currn)
#else
void _VS3rule_945(_currn )
_TPPrule_945 _currn;

#endif
{
DefTableKey* _IL_incl14;

_VisitVarDecl()
_VisitEntry();
_IL_incl14=_IG_incl14;_IG_incl14= &(_currn->_ATType);
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);
_IG_incl14=_IL_incl14;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_945(_TPPrule_945 _currn)
#else
void _VS4rule_945(_currn )
_TPPrule_945 _currn;

#endif
{
DefTableKey* _IL_incl14;

_VisitVarDecl()
_VisitEntry();
_IL_incl14=_IG_incl14;_IG_incl14= &(_currn->_ATType);
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS6MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS7MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS8MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_AT_cBoundsListPtr_pre=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_desc2->_ATTypeLength_pre=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_desc2->_ATDoAcc_pre=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_desc2->_ATStmtNumber_pre=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATUpdate_pre=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_desc2->_ATAccDoLoopDim_pre=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_desc2->_ATNestLevel_pre=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_desc2->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc2->_ATAccRegionNumber_pre=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc2->_ATIndentLevel_pre=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_desc2->_ATLocalIndex_pre=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_desc2->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_desc3->_AT_cBoundsListPtr_pre=_currn->_desc2->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_desc3->_ATDoAcc_pre=_currn->_desc2->_ATDoAcc_post;
/*SPC(0)*/
_currn->_desc3->_ATStmtNumber_pre=_currn->_desc2->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_desc3->_ATUpdate_pre=_currn->_desc2->_ATUpdate_post;
/*SPC(0)*/
_currn->_desc3->_ATAccDoLoopDim_pre=_currn->_desc2->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_desc3->_ATNestLevel_pre=_currn->_desc2->_ATNestLevel_post;
/*SPC(0)*/
_currn->_desc3->_ATCPURegionNumber_pre=_currn->_desc2->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_desc3->_ATAccRegionNumber_pre=_currn->_desc2->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_desc3->_ATAcceleratorRegion_pre=_currn->_desc2->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_desc3->_ATIndentLevel_pre=_currn->_desc2->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_desc3->_ATLocalIndex_pre=_currn->_desc2->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_desc3->_ATArrayId_pre=_currn->_desc2->_ATArrayId_post;
/*SPC(0)*/
_currn->_desc3->_ATTypeLength_pre=_currn->_desc2->_ATTypeLength_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);
_currn->_AT_cBoundsListPtr_post=_currn->_desc3->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_ATDoAcc_post=_currn->_desc3->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc3->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc3->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc3->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc3->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc3->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc3->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc3->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc3->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc3->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc3->_ATArrayId_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_desc3->_ATTypeLength_post;
/*SPC(0)*/
_IG_incl14=_IL_incl14;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_946(_TPPrule_946 _currn)
#else
void _VS1rule_946(_currn )
_TPPrule_946 _currn;

#endif
{
DefTableKey* _IL_incl14;

_VisitVarDecl()
_VisitEntry();
_IL_incl14=_IG_incl14;_IG_incl14= &(_currn->_ATType);

if (EQ(strcmp(MapFile(_currn->_AT_line), StringTable(GetClpValue(FileName, 0))), 0)) {
message(WARNING, "Language construct not currently supported at this time.", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(9479)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATOrder_pre=_currn->_ATOrder_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_desc3->_ATOrder_pre=_currn->_desc2->_ATOrder_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);
_currn->_ATType=_currn->_desc2->_ATType;
/*SPC(1842)*/
_currn->_desc4->_ATOrder_pre=_currn->_desc3->_ATOrder_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc4->_prod])))((NODEPTR) _currn->_desc4);
_currn->_ATOrder_post=_currn->_desc4->_ATOrder_post;
/*SPC(0)*/
_IG_incl14=_IL_incl14;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_946(_TPPrule_946 _currn)
#else
void _VS2rule_946(_currn )
_TPPrule_946 _currn;

#endif
{
DefTableKey* _IL_incl14;

_VisitVarDecl()
_VisitEntry();
_IL_incl14=_IG_incl14;_IG_incl14= &(_currn->_ATType);
_currn->_desc1->_ATLastNonExecLine_pre=_currn->_ATLastNonExecLine_pre;
/*SPC(0)*/
_currn->_desc1->_ATExecutable=0;
/*SPC(998)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATLastNonExecLine_pre=_currn->_desc1->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_desc2->_ATArgCnt_pre=_currn->_ATArgCnt_pre;
/*SPC(0)*/
_currn->_desc2->_ATIsArray_pre=_currn->_ATIsArray_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_desc3->_ATLastNonExecLine_pre=_currn->_desc2->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_desc3->_ATArgCnt_pre=_currn->_desc2->_ATArgCnt_post;
/*SPC(0)*/
_currn->_desc3->_ATIsArray_pre=_currn->_desc2->_ATIsArray_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);
_currn->_desc4->_ATLastNonExecLine_pre=_currn->_desc3->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_desc4->_ATArgCnt_pre=_currn->_desc3->_ATArgCnt_post;
/*SPC(0)*/
_currn->_desc4->_ATIsArray_pre=_currn->_desc3->_ATIsArray_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc4->_prod])))((NODEPTR) _currn->_desc4);
_currn->_ATLastNonExecLine_post=_currn->_desc4->_ATLastNonExecLine_post;
/*SPC(0)*/
_currn->_ATArgCnt_post=_currn->_desc4->_ATArgCnt_post;
/*SPC(0)*/
_currn->_ATIsArray_post=_currn->_desc4->_ATIsArray_post;
/*SPC(0)*/
_IG_incl14=_IL_incl14;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_946(_TPPrule_946 _currn)
#else
void _VS3rule_946(_currn )
_TPPrule_946 _currn;

#endif
{
DefTableKey* _IL_incl14;

_VisitVarDecl()
_VisitEntry();
_IL_incl14=_IG_incl14;_IG_incl14= &(_currn->_ATType);
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc4->_prod])))((NODEPTR) _currn->_desc4);
_IG_incl14=_IL_incl14;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_946(_TPPrule_946 _currn)
#else
void _VS4rule_946(_currn )
_TPPrule_946 _currn;

#endif
{
DefTableKey* _IL_incl14;

_VisitVarDecl()
_VisitEntry();
_IL_incl14=_IG_incl14;_IG_incl14= &(_currn->_ATType);
_currn->_desc1->_ATTypeLength_pre=_currn->_ATTypeLength_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_AT_cBoundsListPtr_pre=_currn->_AT_cBoundsListPtr_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATLocalIndex_pre=_currn->_ATLocalIndex_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATNestLevel_pre=_currn->_ATNestLevel_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS6MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATDoAcc_pre=_currn->_ATDoAcc_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccDoLoopDim_pre=_currn->_ATAccDoLoopDim_pre;
/*SPC(0)*/
_currn->_desc1->_ATIndentLevel_pre=_currn->_ATIndentLevel_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS7MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATStmtNumber_pre=_currn->_ATStmtNumber_pre;
/*SPC(0)*/
_currn->_desc1->_ATUpdate_pre=_currn->_ATUpdate_pre;
/*SPC(0)*/
_currn->_desc1->_ATAccRegionNumber_pre=_currn->_ATAccRegionNumber_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS8MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_AT_cBoundsListPtr_pre=_currn->_desc1->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_desc2->_ATTypeLength_pre=_currn->_desc1->_ATTypeLength_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_desc2->_ATDoAcc_pre=_currn->_desc1->_ATDoAcc_post;
/*SPC(0)*/
_currn->_desc2->_ATStmtNumber_pre=_currn->_desc1->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATUpdate_pre=_currn->_desc1->_ATUpdate_post;
/*SPC(0)*/
_currn->_desc2->_ATAccDoLoopDim_pre=_currn->_desc1->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_desc2->_ATNestLevel_pre=_currn->_desc1->_ATNestLevel_post;
/*SPC(0)*/
_currn->_desc2->_ATCPURegionNumber_pre=_currn->_ATCPURegionNumber_pre;
/*SPC(0)*/
_currn->_desc2->_ATAccRegionNumber_pre=_currn->_desc1->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_desc2->_ATAcceleratorRegion_pre=_currn->_ATAcceleratorRegion_pre;
/*SPC(0)*/
_currn->_desc2->_ATIndentLevel_pre=_currn->_desc1->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_desc2->_ATLocalIndex_pre=_currn->_desc1->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_desc2->_ATArrayId_pre=_currn->_ATArrayId_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_desc3->_AT_cBoundsListPtr_pre=_currn->_desc2->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_desc3->_ATDoAcc_pre=_currn->_desc2->_ATDoAcc_post;
/*SPC(0)*/
_currn->_desc3->_ATStmtNumber_pre=_currn->_desc2->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_desc3->_ATUpdate_pre=_currn->_desc2->_ATUpdate_post;
/*SPC(0)*/
_currn->_desc3->_ATAccDoLoopDim_pre=_currn->_desc2->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_desc3->_ATNestLevel_pre=_currn->_desc2->_ATNestLevel_post;
/*SPC(0)*/
_currn->_desc3->_ATCPURegionNumber_pre=_currn->_desc2->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_desc3->_ATAccRegionNumber_pre=_currn->_desc2->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_desc3->_ATAcceleratorRegion_pre=_currn->_desc2->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_desc3->_ATIndentLevel_pre=_currn->_desc2->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_desc3->_ATLocalIndex_pre=_currn->_desc2->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_desc3->_ATArrayId_pre=_currn->_desc2->_ATArrayId_post;
/*SPC(0)*/
_currn->_desc3->_ATTypeLength_pre=_currn->_desc2->_ATTypeLength_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);
_currn->_desc4->_AT_cBoundsListPtr_pre=_currn->_desc3->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_desc4->_ATDoAcc_pre=_currn->_desc3->_ATDoAcc_post;
/*SPC(0)*/
_currn->_desc4->_ATStmtNumber_pre=_currn->_desc3->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_desc4->_ATUpdate_pre=_currn->_desc3->_ATUpdate_post;
/*SPC(0)*/
_currn->_desc4->_ATAccDoLoopDim_pre=_currn->_desc3->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_desc4->_ATNestLevel_pre=_currn->_desc3->_ATNestLevel_post;
/*SPC(0)*/
_currn->_desc4->_ATCPURegionNumber_pre=_currn->_desc3->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_desc4->_ATAccRegionNumber_pre=_currn->_desc3->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_desc4->_ATAcceleratorRegion_pre=_currn->_desc3->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_desc4->_ATIndentLevel_pre=_currn->_desc3->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_desc4->_ATLocalIndex_pre=_currn->_desc3->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_desc4->_ATArrayId_pre=_currn->_desc3->_ATArrayId_post;
/*SPC(0)*/
_currn->_desc4->_ATTypeLength_pre=_currn->_desc3->_ATTypeLength_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc4->_prod])))((NODEPTR) _currn->_desc4);
_currn->_AT_cBoundsListPtr_post=_currn->_desc4->_AT_cBoundsListPtr_post;
/*SPC(0)*/
_currn->_ATDoAcc_post=_currn->_desc4->_ATDoAcc_post;
/*SPC(0)*/
_currn->_ATStmtNumber_post=_currn->_desc4->_ATStmtNumber_post;
/*SPC(0)*/
_currn->_ATUpdate_post=_currn->_desc4->_ATUpdate_post;
/*SPC(0)*/
_currn->_ATAccDoLoopDim_post=_currn->_desc4->_ATAccDoLoopDim_post;
/*SPC(0)*/
_currn->_ATNestLevel_post=_currn->_desc4->_ATNestLevel_post;
/*SPC(0)*/
_currn->_ATCPURegionNumber_post=_currn->_desc4->_ATCPURegionNumber_post;
/*SPC(0)*/
_currn->_ATAccRegionNumber_post=_currn->_desc4->_ATAccRegionNumber_post;
/*SPC(0)*/
_currn->_ATAcceleratorRegion_post=_currn->_desc4->_ATAcceleratorRegion_post;
/*SPC(0)*/
_currn->_ATIndentLevel_post=_currn->_desc4->_ATIndentLevel_post;
/*SPC(0)*/
_currn->_ATLocalIndex_post=_currn->_desc4->_ATLocalIndex_post;
/*SPC(0)*/
_currn->_ATArrayId_post=_currn->_desc4->_ATArrayId_post;
/*SPC(0)*/
_currn->_ATTypeLength_post=_currn->_desc4->_ATTypeLength_post;
/*SPC(0)*/
_IG_incl14=_IL_incl14;

_VisitExit();
}

