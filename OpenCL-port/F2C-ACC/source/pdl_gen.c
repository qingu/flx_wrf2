#include "pdl_gen.h"

#ifdef MONITOR
#include "pdl_dapto.h"
#endif

#define PRESENT find(key, _property, (Entry *)&_Item, 0)
#define VALUE (_Item->PropVal)

#define TYPE int

#define ACCESS find(key, _property, (Entry *)&_Item, sizeof(struct intElt))

typedef struct intElt {
	Entry next;
	int selector;
	TYPE PropVal;
} *intProperty;

#if defined(__STDC__) || defined(__cplusplus)
TYPE
Getint (int _property, DefTableKey key, TYPE deflt)
#else
TYPE
Getint (_property, key, deflt)
int _property;
DefTableKey key;
TYPE deflt;
#endif
{  intProperty _Item;
{ if (key == NoKey) return deflt;
  if (PRESENT) return VALUE;
  else return deflt;
}
}

#if defined(__STDC__) || defined(__cplusplus)
void
Setint (int _property, DefTableKey key, TYPE _add, TYPE _replace)
#else
void
Setint (_property, key, _add, _replace)
int _property;
DefTableKey key;
TYPE _add;
TYPE _replace;
#endif
{  intProperty _Item;
{ if (key == NoKey) return;
  if (ACCESS) VALUE = _replace;
  else VALUE = _add;
}
}

#if defined(__STDC__) || defined(__cplusplus)
void
Resetint (int _property, DefTableKey key, TYPE _val)
#else
void
Resetint (_property, key, _val)
int _property;
DefTableKey key;
TYPE _val;
#endif
{  intProperty _Item;
{ if (key == NoKey) return;
  ACCESS; VALUE = _val;
}
}

#undef ACCESS
#undef TYPE
#define TYPE IntSet

#define ACCESS find(key, _property, (Entry *)&_Item, sizeof(struct IntSetElt))

typedef struct IntSetElt {
	Entry next;
	int selector;
	TYPE PropVal;
} *IntSetProperty;

#if defined(__STDC__) || defined(__cplusplus)
TYPE
GetIntSet (int _property, DefTableKey key, TYPE deflt)
#else
TYPE
GetIntSet (_property, key, deflt)
int _property;
DefTableKey key;
TYPE deflt;
#endif
{  IntSetProperty _Item;
{ if (key == NoKey) return deflt;
  if (PRESENT) return VALUE;
  else return deflt;
}
}

#if defined(__STDC__) || defined(__cplusplus)
void
SetIntSet (int _property, DefTableKey key, TYPE _add, TYPE _replace)
#else
void
SetIntSet (_property, key, _add, _replace)
int _property;
DefTableKey key;
TYPE _add;
TYPE _replace;
#endif
{  IntSetProperty _Item;
{ if (key == NoKey) return;
  if (ACCESS) VALUE = _replace;
  else VALUE = _add;
}
}

#if defined(__STDC__) || defined(__cplusplus)
void
ResetIntSet (int _property, DefTableKey key, TYPE _val)
#else
void
ResetIntSet (_property, key, _val)
int _property;
DefTableKey key;
TYPE _val;
#endif
{  IntSetProperty _Item;
{ if (key == NoKey) return;
  ACCESS; VALUE = _val;
}
}

#if defined(__STDC__) || defined(__cplusplus)
TYPE
InsertIntSet (int _property, DefTableKey key, int val)
#else
TYPE
InsertIntSet (_property, key, val)
int _property;
DefTableKey key;
int val;
#endif
{  IntSetProperty _Item;
{ if (key == NoKey) return NULLIS;
  if (val < 0 || val > 8*sizeof(TYPE))
     message(DEADLY,"Invalid set element",0,NoPosition);
  if (!ACCESS) VALUE = NULLIS;
  VALUE |= (1<<val);
  return VALUE;
}
}

#if defined(__STDC__) || defined(__cplusplus)
TYPE
UnionIntSet (int _property, DefTableKey key, TYPE val)
#else
TYPE
UnionIntSet (_property, key, val)
int _property;
DefTableKey key;
TYPE val;
#endif
{  IntSetProperty _Item;
{ if (key == NoKey) return NULLIS;
  if (!ACCESS) VALUE = val;
  else VALUE |= val;
  return VALUE;
}
}

#if defined(__STDC__) || defined(__cplusplus)
TYPE
IntersectIntSet (int _property, DefTableKey key, TYPE val)
#else
TYPE
IntersectIntSet (_property, key, val)
int _property;
DefTableKey key;
TYPE val;
#endif
{  IntSetProperty _Item;
{ if (key == NoKey) return NULLIS;
  if (!ACCESS) VALUE = val;
  else VALUE &= val;
  return VALUE;
}
}

#undef ACCESS
#undef TYPE
#define TYPE DefTableKey

#define ACCESS find(key, _property, (Entry *)&_Item, sizeof(struct DefTableKeyElt))

typedef struct DefTableKeyElt {
	Entry next;
	int selector;
	TYPE PropVal;
} *DefTableKeyProperty;

#if defined(__STDC__) || defined(__cplusplus)
TYPE
GetDefTableKey (int _property, DefTableKey key, TYPE deflt)
#else
TYPE
GetDefTableKey (_property, key, deflt)
int _property;
DefTableKey key;
TYPE deflt;
#endif
{  DefTableKeyProperty _Item;
{ if (key == NoKey) return deflt;
  if (PRESENT) return VALUE;
  else return deflt;
}
}

#if defined(__STDC__) || defined(__cplusplus)
void
SetDefTableKey (int _property, DefTableKey key, TYPE _add, TYPE _replace)
#else
void
SetDefTableKey (_property, key, _add, _replace)
int _property;
DefTableKey key;
TYPE _add;
TYPE _replace;
#endif
{  DefTableKeyProperty _Item;
{ if (key == NoKey) return;
  if (ACCESS) VALUE = _replace;
  else VALUE = _add;
}
}

#if defined(__STDC__) || defined(__cplusplus)
void
ResetDefTableKey (int _property, DefTableKey key, TYPE _val)
#else
void
ResetDefTableKey (_property, key, _val)
int _property;
DefTableKey key;
TYPE _val;
#endif
{  DefTableKeyProperty _Item;
{ if (key == NoKey) return;
  ACCESS; VALUE = _val;
}
}

#if defined(__STDC__) || defined(__cplusplus)
void
IsDefTableKey (int _property, DefTableKey key, TYPE _which, TYPE _error)
#else
void
IsDefTableKey (_property, key, _which, _error)
int _property;
DefTableKey key;
TYPE _which;
TYPE _error;
#endif
{  DefTableKeyProperty _Item;
{ if (key == NoKey) return;
  if (!ACCESS) VALUE = _which;
  else if (VALUE != _which) VALUE = _error;
}
}

#if defined(__STDC__) || defined(__cplusplus)
void
GuaranteeDefTableKey (int _property, DefTableKey key, TYPE val)
#else
void
GuaranteeDefTableKey (_property, key, val)
int _property;
DefTableKey key;
TYPE val;
#endif
{  DefTableKeyProperty _Item;
{ if (key == NoKey) return;
  if (!ACCESS) VALUE = val;
}
}

#undef ACCESS
#undef TYPE
#define TYPE BoundsList

#define ACCESS find(key, _property, (Entry *)&_Item, sizeof(struct BoundsListElt))

typedef struct BoundsListElt {
	Entry next;
	int selector;
	TYPE PropVal;
} *BoundsListProperty;

#if defined(__STDC__) || defined(__cplusplus)
TYPE
GetBoundsList (int _property, DefTableKey key, TYPE deflt)
#else
TYPE
GetBoundsList (_property, key, deflt)
int _property;
DefTableKey key;
TYPE deflt;
#endif
{  BoundsListProperty _Item;
{ if (key == NoKey) return deflt;
  if (PRESENT) return VALUE;
  else return deflt;
}
}

#if defined(__STDC__) || defined(__cplusplus)
void
SetBoundsList (int _property, DefTableKey key, TYPE _add, TYPE _replace)
#else
void
SetBoundsList (_property, key, _add, _replace)
int _property;
DefTableKey key;
TYPE _add;
TYPE _replace;
#endif
{  BoundsListProperty _Item;
{ if (key == NoKey) return;
  if (ACCESS) VALUE = _replace;
  else VALUE = _add;
}
}

#if defined(__STDC__) || defined(__cplusplus)
void
ResetBoundsList (int _property, DefTableKey key, TYPE _val)
#else
void
ResetBoundsList (_property, key, _val)
int _property;
DefTableKey key;
TYPE _val;
#endif
{  BoundsListProperty _Item;
{ if (key == NoKey) return;
  ACCESS; VALUE = _val;
}
}

#undef ACCESS
#undef TYPE
#define TYPE PTGNode

#define ACCESS find(key, _property, (Entry *)&_Item, sizeof(struct PTGNodeElt))

typedef struct PTGNodeElt {
	Entry next;
	int selector;
	TYPE PropVal;
} *PTGNodeProperty;

#if defined(__STDC__) || defined(__cplusplus)
TYPE
GetPTGNode (int _property, DefTableKey key, TYPE deflt)
#else
TYPE
GetPTGNode (_property, key, deflt)
int _property;
DefTableKey key;
TYPE deflt;
#endif
{  PTGNodeProperty _Item;
{ if (key == NoKey) return deflt;
  if (PRESENT) return VALUE;
  else return deflt;
}
}

#if defined(__STDC__) || defined(__cplusplus)
void
SetPTGNode (int _property, DefTableKey key, TYPE _add, TYPE _replace)
#else
void
SetPTGNode (_property, key, _add, _replace)
int _property;
DefTableKey key;
TYPE _add;
TYPE _replace;
#endif
{  PTGNodeProperty _Item;
{ if (key == NoKey) return;
  if (ACCESS) VALUE = _replace;
  else VALUE = _add;
}
}

#if defined(__STDC__) || defined(__cplusplus)
void
ResetPTGNode (int _property, DefTableKey key, TYPE _val)
#else
void
ResetPTGNode (_property, key, _val)
int _property;
DefTableKey key;
TYPE _val;
#endif
{  PTGNodeProperty _Item;
{ if (key == NoKey) return;
  ACCESS; VALUE = _val;
}
}

#undef ACCESS
#undef TYPE
#define TYPE Environment

#define ACCESS find(key, _property, (Entry *)&_Item, sizeof(struct EnvironmentElt))

typedef struct EnvironmentElt {
	Entry next;
	int selector;
	TYPE PropVal;
} *EnvironmentProperty;

#if defined(__STDC__) || defined(__cplusplus)
TYPE
GetEnvironment (int _property, DefTableKey key, TYPE deflt)
#else
TYPE
GetEnvironment (_property, key, deflt)
int _property;
DefTableKey key;
TYPE deflt;
#endif
{  EnvironmentProperty _Item;
{ if (key == NoKey) return deflt;
  if (PRESENT) return VALUE;
  else return deflt;
}
}

#if defined(__STDC__) || defined(__cplusplus)
void
SetEnvironment (int _property, DefTableKey key, TYPE _add, TYPE _replace)
#else
void
SetEnvironment (_property, key, _add, _replace)
int _property;
DefTableKey key;
TYPE _add;
TYPE _replace;
#endif
{  EnvironmentProperty _Item;
{ if (key == NoKey) return;
  if (ACCESS) VALUE = _replace;
  else VALUE = _add;
}
}

#if defined(__STDC__) || defined(__cplusplus)
void
ResetEnvironment (int _property, DefTableKey key, TYPE _val)
#else
void
ResetEnvironment (_property, key, _val)
int _property;
DefTableKey key;
TYPE _val;
#endif
{  EnvironmentProperty _Item;
{ if (key == NoKey) return;
  ACCESS; VALUE = _val;
}
}

#undef ACCESS
#undef TYPE

static struct PropElt PDLe0 = {(Entry)0, 0};
static struct intElt PDLe1 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe86 = {(Entry)&PDLe1, 5,     IntegerType};
static struct intElt PDLe2 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe87 = {(Entry)&PDLe2, 5,    IntegerType};
static struct intElt PDLe3 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe88 = {(Entry)&PDLe3, 5,   IntegerType};
static struct intElt PDLe4 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe89 = {(Entry)&PDLe4, 5,    RealType};
static struct intElt PDLe5 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe90 = {(Entry)&PDLe5, 5,   RealType};
static struct intElt PDLe6 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe91 = {(Entry)&PDLe6, 5,    RealType};
static struct intElt PDLe7 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe92 = {(Entry)&PDLe7, 5,    DoublePrecisionType};
static struct intElt PDLe8 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe93 = {(Entry)&PDLe8, 5,   ComplexType};
static struct intElt PDLe9 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe94 = {(Entry)&PDLe9, 5,   IntegerType};
static struct intElt PDLe10 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe95 = {(Entry)&PDLe10, 5,    CharacterType};
static struct intElt PDLe11 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe96 = {(Entry)&PDLe11, 5,    RealType};
static struct intElt PDLe12 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe97 = {(Entry)&PDLe12, 5,    DoublePrecisionType};
static struct intElt PDLe13 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe98 = {(Entry)&PDLe13, 5,   RealType};
static struct intElt PDLe14 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe99 = {(Entry)&PDLe14, 5,   DoublePrecisionType};
static struct intElt PDLe15 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe100 = {(Entry)&PDLe15, 5,    IntegerType};
static struct intElt PDLe16 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe101 = {(Entry)&PDLe16, 5,  IntegerType};
static struct intElt PDLe17 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe102 = {(Entry)&PDLe17, 5,     RealType};
static struct intElt PDLe18 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe103 = {(Entry)&PDLe18, 5,    IntegerType};
static struct intElt PDLe19 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe104 = {(Entry)&PDLe19, 5,    DoublePrecisionType};
static struct intElt PDLe20 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe105 = {(Entry)&PDLe20, 5,    RealType};
static struct intElt PDLe21 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe106 = {(Entry)&PDLe21, 5,     IntegerType};
static struct intElt PDLe22 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe107 = {(Entry)&PDLe22, 5,    RealType};
static struct intElt PDLe23 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe108 = {(Entry)&PDLe23, 5,    DoublePrecisionType};
static struct intElt PDLe24 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe109 = {(Entry)&PDLe24, 5,    RealType};
static struct intElt PDLe25 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe110 = {(Entry)&PDLe25, 5,   IntegerType};
static struct intElt PDLe26 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe111 = {(Entry)&PDLe26, 5,   DoublePrecisionType};
static struct intElt PDLe27 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe112 = {(Entry)&PDLe27, 5,     RealType};
static struct intElt PDLe28 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe113 = {(Entry)&PDLe28, 5,    IntegerType};
static struct intElt PDLe29 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe114 = {(Entry)&PDLe29, 5,    DoublePrecisionType};
static struct intElt PDLe30 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe115 = {(Entry)&PDLe30, 5,   DoublePrecisionType};
static struct intElt PDLe31 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe116 = {(Entry)&PDLe31, 5,     IntegerType};
static struct intElt PDLe32 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe117 = {(Entry)&PDLe32, 5,    IntegerType};
static struct intElt PDLe33 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe118 = {(Entry)&PDLe33, 5,   RealType};
static struct intElt PDLe34 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe119 = {(Entry)&PDLe34, 5,   DoublePrecisionType};
static struct intElt PDLe35 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe120 = {(Entry)&PDLe35, 5,   RealType};
static struct intElt PDLe36 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe121 = {(Entry)&PDLe36, 5,    IntegerType};
static struct intElt PDLe37 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe122 = {(Entry)&PDLe37, 5,     IntegerType};
static struct intElt PDLe38 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe123 = {(Entry)&PDLe38, 5,    IntegerType};
static struct intElt PDLe39 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe124 = {(Entry)&PDLe39, 5,   RealType};
static struct intElt PDLe40 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe125 = {(Entry)&PDLe40, 5,   DoublePrecisionType};
static struct intElt PDLe41 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe126 = {(Entry)&PDLe41, 5,   RealType};
static struct intElt PDLe42 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe127 = {(Entry)&PDLe42, 5,    IntegerType};
static struct intElt PDLe43 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe128 = {(Entry)&PDLe43, 5,     IntegerType};
static struct intElt PDLe44 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe129 = {(Entry)&PDLe44, 5,   IntegerType};
static struct intElt PDLe45 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe130 = {(Entry)&PDLe45, 5,   RealType};
static struct intElt PDLe46 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe131 = {(Entry)&PDLe46, 5,   ComplexType};
static struct intElt PDLe47 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe132 = {(Entry)&PDLe47, 5,    RealType};
static struct intElt PDLe48 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe133 = {(Entry)&PDLe48, 5,   DoublePrecisionType};
static struct intElt PDLe49 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe134 = {(Entry)&PDLe49, 5,   ComplexType};
static struct intElt PDLe50 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe135 = {(Entry)&PDLe50, 5,     RealType};
static struct intElt PDLe51 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe136 = {(Entry)&PDLe51, 5,    DoublePrecisionType};
static struct intElt PDLe52 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe137 = {(Entry)&PDLe52, 5,    ComplexType};
static struct intElt PDLe53 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe138 = {(Entry)&PDLe53, 5,     RealType};
static struct intElt PDLe54 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe139 = {(Entry)&PDLe54, 5,    RealType};
static struct intElt PDLe55 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe140 = {(Entry)&PDLe55, 5,    DoublePrecisionType};
static struct intElt PDLe56 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe141 = {(Entry)&PDLe56, 5,    ComplexType};
static struct intElt PDLe57 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe142 = {(Entry)&PDLe57, 5,   RealType};
static struct intElt PDLe58 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe143 = {(Entry)&PDLe58, 5,  RealType};
static struct intElt PDLe59 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe144 = {(Entry)&PDLe59, 5,  DoublePrecisionType};
static struct intElt PDLe60 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe145 = {(Entry)&PDLe60, 5,     RealType};
static struct intElt PDLe61 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe146 = {(Entry)&PDLe61, 5,    DoublePrecisionType};
static struct intElt PDLe62 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe147 = {(Entry)&PDLe62, 5,    ComplexType};
static struct intElt PDLe63 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe148 = {(Entry)&PDLe63, 5,     RealType};
static struct intElt PDLe64 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe149 = {(Entry)&PDLe64, 5,    DoublePrecisionType};
static struct intElt PDLe65 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe150 = {(Entry)&PDLe65, 5,    ComplexType};
static struct intElt PDLe66 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe151 = {(Entry)&PDLe66, 5,     RealType};
static struct intElt PDLe67 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe152 = {(Entry)&PDLe67, 5,    DoublePrecisionType};
static struct intElt PDLe68 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe153 = {(Entry)&PDLe68, 5,    RealType};
static struct intElt PDLe69 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe154 = {(Entry)&PDLe69, 5,   DoublePrecisionType};
static struct intElt PDLe70 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe155 = {(Entry)&PDLe70, 5,    RealType};
static struct intElt PDLe71 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe156 = {(Entry)&PDLe71, 5,   DoublePrecisionType};
static struct intElt PDLe72 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe157 = {(Entry)&PDLe72, 5,    RealType};
static struct intElt PDLe73 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe158 = {(Entry)&PDLe73, 5,   DoublePrecisionType};
static struct intElt PDLe74 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe159 = {(Entry)&PDLe74, 5,   RealType};
static struct intElt PDLe75 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe160 = {(Entry)&PDLe75, 5,  DoublePrecisionType};
static struct intElt PDLe76 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe161 = {(Entry)&PDLe76, 5,    RealType};
static struct intElt PDLe77 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe162 = {(Entry)&PDLe77, 5,   DoublePrecisionType};
static struct intElt PDLe78 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe163 = {(Entry)&PDLe78, 5,    RealType};
static struct intElt PDLe79 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe164 = {(Entry)&PDLe79, 5,   DoublePrecisionType};
static struct intElt PDLe80 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe165 = {(Entry)&PDLe80, 5,    RealType};
static struct intElt PDLe81 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe166 = {(Entry)&PDLe81, 5,   DoublePrecisionType};
static struct intElt PDLe82 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe167 = {(Entry)&PDLe82, 5,     LogicalType};
static struct intElt PDLe83 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe168 = {(Entry)&PDLe83, 5,     LogicalType};
static struct intElt PDLe84 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe169 = {(Entry)&PDLe84, 5,     LogicalType};
static struct intElt PDLe85 = {(Entry)&PDLe0, 3, 1};
static struct DefTableKeyElt PDLe170 = {(Entry)&PDLe85, 5,     LogicalType};

struct PropList PDLk[] = {
  {(Entry)&PDLe0},
  {(Entry)&PDLe0},
  {(Entry)&PDLe0},
  {(Entry)&PDLe0},
  {(Entry)&PDLe0},
  {(Entry)&PDLe0},
  {(Entry)&PDLe0},
  {(Entry)&PDLe0},
  {(Entry)&PDLe86},
  {(Entry)&PDLe87},
  {(Entry)&PDLe88},
  {(Entry)&PDLe89},
  {(Entry)&PDLe90},
  {(Entry)&PDLe91},
  {(Entry)&PDLe92},
  {(Entry)&PDLe93},
  {(Entry)&PDLe94},
  {(Entry)&PDLe95},
  {(Entry)&PDLe96},
  {(Entry)&PDLe97},
  {(Entry)&PDLe98},
  {(Entry)&PDLe99},
  {(Entry)&PDLe100},
  {(Entry)&PDLe101},
  {(Entry)&PDLe102},
  {(Entry)&PDLe103},
  {(Entry)&PDLe104},
  {(Entry)&PDLe105},
  {(Entry)&PDLe106},
  {(Entry)&PDLe107},
  {(Entry)&PDLe108},
  {(Entry)&PDLe109},
  {(Entry)&PDLe110},
  {(Entry)&PDLe111},
  {(Entry)&PDLe112},
  {(Entry)&PDLe113},
  {(Entry)&PDLe114},
  {(Entry)&PDLe115},
  {(Entry)&PDLe116},
  {(Entry)&PDLe117},
  {(Entry)&PDLe118},
  {(Entry)&PDLe119},
  {(Entry)&PDLe120},
  {(Entry)&PDLe121},
  {(Entry)&PDLe122},
  {(Entry)&PDLe123},
  {(Entry)&PDLe124},
  {(Entry)&PDLe125},
  {(Entry)&PDLe126},
  {(Entry)&PDLe127},
  {(Entry)&PDLe128},
  {(Entry)&PDLe129},
  {(Entry)&PDLe130},
  {(Entry)&PDLe131},
  {(Entry)&PDLe132},
  {(Entry)&PDLe133},
  {(Entry)&PDLe134},
  {(Entry)&PDLe135},
  {(Entry)&PDLe136},
  {(Entry)&PDLe137},
  {(Entry)&PDLe138},
  {(Entry)&PDLe139},
  {(Entry)&PDLe140},
  {(Entry)&PDLe141},
  {(Entry)&PDLe142},
  {(Entry)&PDLe143},
  {(Entry)&PDLe144},
  {(Entry)&PDLe145},
  {(Entry)&PDLe146},
  {(Entry)&PDLe147},
  {(Entry)&PDLe148},
  {(Entry)&PDLe149},
  {(Entry)&PDLe150},
  {(Entry)&PDLe151},
  {(Entry)&PDLe152},
  {(Entry)&PDLe153},
  {(Entry)&PDLe154},
  {(Entry)&PDLe155},
  {(Entry)&PDLe156},
  {(Entry)&PDLe157},
  {(Entry)&PDLe158},
  {(Entry)&PDLe159},
  {(Entry)&PDLe160},
  {(Entry)&PDLe161},
  {(Entry)&PDLe162},
  {(Entry)&PDLe163},
  {(Entry)&PDLe164},
  {(Entry)&PDLe165},
  {(Entry)&PDLe166},
  {(Entry)&PDLe167},
  {(Entry)&PDLe168},
  {(Entry)&PDLe169},
  {(Entry)&PDLe170}};

DefTableKey
#if defined(__STDC__) || defined(__cplusplus)
CloneKey (DefTableKey key)
#else
CloneKey (key)
    DefTableKey key;
#endif
{
  DefTableKey k;
  Entry e;

  if (key == NoKey) return NoKey;
  k = NewKey ();
  for (e = key->List; (e != (Entry)0) && (e->selector != 0);
       e = e->next) {
    switch (e->selector) {
      case 1:
         ResetClpValue (k, ((intProperty)e)->PropVal);
         break;
      case 2:
         ResetValue (k, ((intProperty)e)->PropVal);
         break;
      case 3:
         ResetIntrinsic (k, ((intProperty)e)->PropVal);
         break;
      case 4:
         ResetKindSet (k, ((IntSetProperty)e)->PropVal);
         break;
      case 5:
         ResetType (k, ((DefTableKeyProperty)e)->PropVal);
         break;
      case 6:
         ResetNumberOfDims (k, ((intProperty)e)->PropVal);
         break;
      case 7:
         ResetarrayApp (k, ((intProperty)e)->PropVal);
         break;
      case 8:
         ResettypeApp (k, ((intProperty)e)->PropVal);
         break;
      case 9:
         ResetconstantApp (k, ((intProperty)e)->PropVal);
         break;
      case 10:
         ResetexternalApp (k, ((intProperty)e)->PropVal);
         break;
      case 11:
         ResetintrinsicApp (k, ((intProperty)e)->PropVal);
         break;
      case 12:
         ResetArraySizeList (k, ((BoundsListProperty)e)->PropVal);
         break;
      case 13:
         ResetTypeLength (k, ((intProperty)e)->PropVal);
         break;
      case 14:
         ResetVariableDeclared (k, ((intProperty)e)->PropVal);
         break;
      case 15:
         ResetIntent (k, ((intProperty)e)->PropVal);
         break;
      case 16:
         ResetRoutineDefined (k, ((intProperty)e)->PropVal);
         break;
      case 17:
         ResetVariableGPU (k, ((intProperty)e)->PropVal);
         break;
      case 18:
         ResetVariableCPU (k, ((intProperty)e)->PropVal);
         break;
      case 19:
         ResetVariableRoutine (k, ((intProperty)e)->PropVal);
         break;
      case 20:
         ResetDoLabelCount (k, ((intProperty)e)->PropVal);
         break;
      case 21:
         ResetThreadDim (k, ((intProperty)e)->PropVal);
         break;
      case 22:
         ResetBlockDim (k, ((intProperty)e)->PropVal);
         break;
      case 23:
         ResetRegionNumber (k, ((intProperty)e)->PropVal);
         break;
      case 24:
         ResetVariableConstant (k, ((intProperty)e)->PropVal);
         break;
      case 25:
         ResetVariableConstantValue (k, ((PTGNodeProperty)e)->PropVal);
         break;
      case 26:
         ResetUnitScope (k, ((EnvironmentProperty)e)->PropVal);
         break;
      case 27:
         ResetUnique (k, ((intProperty)e)->PropVal);
         break;
      case 28:
         ResetUnitCnt (k, ((intProperty)e)->PropVal);
         break;
      }
  }
  return k;
}

#ifdef MONITOR
static CONST char *pdl_names[] = {
    (char *)0,
    "ClpValue",
    "Value",
    "Intrinsic",
    "KindSet",
    "Type",
    "NumberOfDims",
    "arrayApp",
    "typeApp",
    "constantApp",
    "externalApp",
    "intrinsicApp",
    "ArraySizeList",
    "TypeLength",
    "VariableDeclared",
    "Intent",
    "RoutineDefined",
    "VariableGPU",
    "VariableCPU",
    "VariableRoutine",
    "DoLabelCount",
    "ThreadDim",
    "BlockDim",
    "RegionNumber",
    "VariableConstant",
    "VariableConstantValue",
    "UnitScope",
    "Unique",
    "UnitCnt",
};
static CONST char *pdl_types[] = {
    (char *)0,
    "int",
    "int",
    "int",
    "IntSet",
    "DefTableKey",
    "int",
    "int",
    "int",
    "int",
    "int",
    "int",
    "BoundsList",
    "int",
    "int",
    "int",
    "int",
    "int",
    "int",
    "int",
    "int",
    "int",
    "int",
    "int",
    "int",
    "PTGNode",
    "Environment",
    "int",
    "int",
};

void
#if defined(__STDC__) || defined(__cplusplus)
pdl_mon_properties(DefTableKey k)
#else
pdl_mon_properties(k) DefTableKey k;
#endif
{
    Entry e;
    if (k == NoKey) return;
    for (e = k->List; (e != (Entry)0) && (e->selector != 0);
         e = e->next) {
        DAPTO_RESULT_STR (pdl_names[e->selector]);
        DAPTO_RESULT_STR (pdl_types[e->selector]);
        switch (e->selector) {
            case 1:
#ifdef DAPTO_RESULTint
                DAPTO_RESULTint (((intProperty)e)->PropVal);
#else
                DAPTO_RESULT_OTHER (((intProperty)e)->PropVal);
#endif
                break;
            case 2:
#ifdef DAPTO_RESULTint
                DAPTO_RESULTint (((intProperty)e)->PropVal);
#else
                DAPTO_RESULT_OTHER (((intProperty)e)->PropVal);
#endif
                break;
            case 3:
#ifdef DAPTO_RESULTint
                DAPTO_RESULTint (((intProperty)e)->PropVal);
#else
                DAPTO_RESULT_OTHER (((intProperty)e)->PropVal);
#endif
                break;
            case 4:
#ifdef DAPTO_RESULTIntSet
                DAPTO_RESULTIntSet (((IntSetProperty)e)->PropVal);
#else
                DAPTO_RESULT_OTHER (((IntSetProperty)e)->PropVal);
#endif
                break;
            case 5:
#ifdef DAPTO_RESULTDefTableKey
                DAPTO_RESULTDefTableKey (((DefTableKeyProperty)e)->PropVal);
#else
                DAPTO_RESULT_OTHER (((DefTableKeyProperty)e)->PropVal);
#endif
                break;
            case 6:
#ifdef DAPTO_RESULTint
                DAPTO_RESULTint (((intProperty)e)->PropVal);
#else
                DAPTO_RESULT_OTHER (((intProperty)e)->PropVal);
#endif
                break;
            case 7:
#ifdef DAPTO_RESULTint
                DAPTO_RESULTint (((intProperty)e)->PropVal);
#else
                DAPTO_RESULT_OTHER (((intProperty)e)->PropVal);
#endif
                break;
            case 8:
#ifdef DAPTO_RESULTint
                DAPTO_RESULTint (((intProperty)e)->PropVal);
#else
                DAPTO_RESULT_OTHER (((intProperty)e)->PropVal);
#endif
                break;
            case 9:
#ifdef DAPTO_RESULTint
                DAPTO_RESULTint (((intProperty)e)->PropVal);
#else
                DAPTO_RESULT_OTHER (((intProperty)e)->PropVal);
#endif
                break;
            case 10:
#ifdef DAPTO_RESULTint
                DAPTO_RESULTint (((intProperty)e)->PropVal);
#else
                DAPTO_RESULT_OTHER (((intProperty)e)->PropVal);
#endif
                break;
            case 11:
#ifdef DAPTO_RESULTint
                DAPTO_RESULTint (((intProperty)e)->PropVal);
#else
                DAPTO_RESULT_OTHER (((intProperty)e)->PropVal);
#endif
                break;
            case 12:
#ifdef DAPTO_RESULTBoundsList
                DAPTO_RESULTBoundsList (((BoundsListProperty)e)->PropVal);
#else
                DAPTO_RESULT_OTHER (((BoundsListProperty)e)->PropVal);
#endif
                break;
            case 13:
#ifdef DAPTO_RESULTint
                DAPTO_RESULTint (((intProperty)e)->PropVal);
#else
                DAPTO_RESULT_OTHER (((intProperty)e)->PropVal);
#endif
                break;
            case 14:
#ifdef DAPTO_RESULTint
                DAPTO_RESULTint (((intProperty)e)->PropVal);
#else
                DAPTO_RESULT_OTHER (((intProperty)e)->PropVal);
#endif
                break;
            case 15:
#ifdef DAPTO_RESULTint
                DAPTO_RESULTint (((intProperty)e)->PropVal);
#else
                DAPTO_RESULT_OTHER (((intProperty)e)->PropVal);
#endif
                break;
            case 16:
#ifdef DAPTO_RESULTint
                DAPTO_RESULTint (((intProperty)e)->PropVal);
#else
                DAPTO_RESULT_OTHER (((intProperty)e)->PropVal);
#endif
                break;
            case 17:
#ifdef DAPTO_RESULTint
                DAPTO_RESULTint (((intProperty)e)->PropVal);
#else
                DAPTO_RESULT_OTHER (((intProperty)e)->PropVal);
#endif
                break;
            case 18:
#ifdef DAPTO_RESULTint
                DAPTO_RESULTint (((intProperty)e)->PropVal);
#else
                DAPTO_RESULT_OTHER (((intProperty)e)->PropVal);
#endif
                break;
            case 19:
#ifdef DAPTO_RESULTint
                DAPTO_RESULTint (((intProperty)e)->PropVal);
#else
                DAPTO_RESULT_OTHER (((intProperty)e)->PropVal);
#endif
                break;
            case 20:
#ifdef DAPTO_RESULTint
                DAPTO_RESULTint (((intProperty)e)->PropVal);
#else
                DAPTO_RESULT_OTHER (((intProperty)e)->PropVal);
#endif
                break;
            case 21:
#ifdef DAPTO_RESULTint
                DAPTO_RESULTint (((intProperty)e)->PropVal);
#else
                DAPTO_RESULT_OTHER (((intProperty)e)->PropVal);
#endif
                break;
            case 22:
#ifdef DAPTO_RESULTint
                DAPTO_RESULTint (((intProperty)e)->PropVal);
#else
                DAPTO_RESULT_OTHER (((intProperty)e)->PropVal);
#endif
                break;
            case 23:
#ifdef DAPTO_RESULTint
                DAPTO_RESULTint (((intProperty)e)->PropVal);
#else
                DAPTO_RESULT_OTHER (((intProperty)e)->PropVal);
#endif
                break;
            case 24:
#ifdef DAPTO_RESULTint
                DAPTO_RESULTint (((intProperty)e)->PropVal);
#else
                DAPTO_RESULT_OTHER (((intProperty)e)->PropVal);
#endif
                break;
            case 25:
#ifdef DAPTO_RESULTPTGNode
                DAPTO_RESULTPTGNode (((PTGNodeProperty)e)->PropVal);
#else
                DAPTO_RESULT_OTHER (((PTGNodeProperty)e)->PropVal);
#endif
                break;
            case 26:
#ifdef DAPTO_RESULTEnvironment
                DAPTO_RESULTEnvironment (((EnvironmentProperty)e)->PropVal);
#else
                DAPTO_RESULT_OTHER (((EnvironmentProperty)e)->PropVal);
#endif
                break;
            case 27:
#ifdef DAPTO_RESULTint
                DAPTO_RESULTint (((intProperty)e)->PropVal);
#else
                DAPTO_RESULT_OTHER (((intProperty)e)->PropVal);
#endif
                break;
            case 28:
#ifdef DAPTO_RESULTint
                DAPTO_RESULTint (((intProperty)e)->PropVal);
#else
                DAPTO_RESULT_OTHER (((intProperty)e)->PropVal);
#endif
                break;
            default: DAPTO_RESULT_STR ("unknown property");
        }
    }
}
#endif
