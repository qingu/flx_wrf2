


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ftocmacros.h"
#define TRUE 1
#define FALSE 0
extern void noop_( );





//C instead of continue, use a subroutine to do nothing. Purely for translation: in the C code we drop them!
int main() {

  int ii,jj,kk;
      common/ijk/ ii, jj, kk
  double ff;
   cc;

  ii = 2;
  jj = 3;
  kk = 4;
  ff = 9.0567;
  cc = 'Example of a character string...';

  goto C__41: ;
  C__41: noop_();
  exit(0);
      end

void noop_ () {
  return;
}
