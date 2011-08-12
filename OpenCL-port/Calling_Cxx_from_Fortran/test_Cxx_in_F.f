	program test
	
	integer x,y,retval
	integer*8 cp
	
	x=8
	y=9
	retval=43
	
	call createClass(cp,y)
	cp=cp-x
	cp=cp+y-1
	call readYval(cp,y)
	call callMult(cp,x,retval)
	write(6,50) retval
50	format(' retval= ',i8)
	
	stop
	end

