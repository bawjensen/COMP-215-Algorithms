

#include <iostream>

#include "Faculty.h"
using namespace std;


//------------------------------------------------------------
Faculty::Faculty() {									// (1) Default CTOR
		// implicitely calls Employee() default CTOR
		cout << "[" << this->getName() << "]: Faculty Default CTOR ..." << endl;
		hasTenure  = false;
}
//------------------------------------------------------------
Faculty::Faculty(char* s, int a, bool b) 
		: Employee(s,a), hasTenure(b) {
            
        cout << "[" << this->getName() << "]: Faculty Parameterized CTOR ..." << endl;

}
//------------------------------------------------------------	
Faculty::Faculty(Faculty& f) {				 		// (2) Copy CTOR
		cout << "[" << f.getName() << "]: Faculty Copy CTOR ..." << endl;
		name = new char[strlen( f.getName() ) + 1];
		strcpy( name, f.getName() );
		age = f.getAge();
}
//------------------------------------------------------------
Faculty::~Faculty() {							// (3) DTOR
		cout << "[" << this->getName() << "]: Faculty DTOR" << endl;
}
//------------------------------------------------------------
Faculty& Faculty::operator=(Employee& other) {		// (4) operator=
		// this = rhs;
		cout << "Faculty operator=() ..." << endl;

		if (this != &other) {
			this->Employee::operator=(other);
			this->hasTenure = other.getTenure();
		}
		
		return *this;
}
//------------------------------------------------------------
// OVERRIDE
void Faculty::greeting(char* theirName) {
		cout << "[" << this->getName() << "]: Faculty says, 'Morning scholar' " << theirName << endl;
}
//------------------------------------------------------------
// MUST OVERRIDE
void Faculty::farewell() {
		cout << "[" << this->getName() << "]: Faculty says, 'See you NEXT class ...' " << endl;
}
//------------------------------------------------------------
// INHERIT: void setName(char* newName) 
//------------------------------------------------------------
// EXTEND
void Faculty::setTenure(bool b)
{
		hasTenure = b;
}
	
// inline bool getTenure(void) const { return hasTenure; }
//------------------------------------------------------------
	