#include <stdio.h>

extern struct
{
   int ii, jj, kk;
} ijk_;

int doubleijk_(char *cc, int ll)
{
   printf("From doubleIJK: %s\n",cc);

   ijk_.ii *=2;
   ijk_.jj *=2;
   ijk_.kk *=2;

   return(1);
}

