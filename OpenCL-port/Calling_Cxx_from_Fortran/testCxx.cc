#include <iostream>
extern "C" {

class Test {
	public:
	int y,z;
	Test(int y_=7188) : y(y_) {
		z=-1;
	}
	int mult(int x);
};

int Test::mult(int x) {
	// somehow, I can call this from FORTRAN but y is set to 0 ...
	std::cout << "Calling Test::mult("<<x<<") with y="<<this->y<<"\n";
	z=x*y;
	return z;
}

// names must be all lower case to get the right name "createClass" in FORTRAN
void createclass_(long long int * cp, int* y) {
	std::cout << "Test::Test("<<*y<<")\n";
	Test* t = new Test(*y);
	std::cout <<"Test::z="<<t->z<<", Test::y="<<t->y<<"\n\n";
	void* vp=(void*)t;
	long long int ci = (long long int)vp;
	*cp = ci;
}

void callmult_(long long int * cp, int* x, int* z) {
	std::cout << "callMult(cp,x="<<*x<<",z="<<*z<<")\n";	
	long long int ci=*cp;
	void* vp = (void*)ci;
	Test* t = (Test*)vp;
	int rz=t->mult(*x);
	std::cout << "Result:"<<rz<<"<>"<<t->z<<"\n\n";	
	*z=t->z;
}

void readyval_(long long int * cp, int* y) {	
	std::cout << "Reading Test::y:\n";	
	long long int ci=*cp;
	void* vp = (void*)ci;
	Test* t = (Test*)vp;
	std::cout << "Test::y="<<t->y<<"\n";
	*y=t->y;
}

} // extern "C"
