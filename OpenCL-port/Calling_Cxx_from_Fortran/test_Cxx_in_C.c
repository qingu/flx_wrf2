#include <stdio.h>

int main() {
	
	int x,y,retval;
	long long int cp;
	
	x=8;
	y=9;
	retval=43;
	
	createclass_(&cp,&y);
	cp=cp-x;
	cp=cp+y-1;
	readyval_(&cp,&y);
	callmult_(&cp,&x,&retval);
	printf("retval= %d\n", retval);
	
    return 1;	
    }

