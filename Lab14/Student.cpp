

#include <iostream>

#include "Student.h"
using namespace std;


//------------------------------------------------------------
Student::Student() {									// (1) Default CTOR
		// implicitely calls Employee() default CTOR
		cout << "[" << this->getName() << "]: Student Default CTOR ..." << endl;
		hasTenure  = false;
}
//------------------------------------------------------------
Student::Student(char* s, int a, bool b) 
		: Employee(s,a), hasTenure(b) {
            
        cout << "[" << this->getName() << "]: Student Parameterized CTOR ..." << endl;

}
//------------------------------------------------------------	
Student::Student(Student& f) {				 		// (2) Copy CTOR
		cout << "[" << f.getName() << "]: Student Copy CTOR ..." << endl;
		name = new char[strlen( f.getName() ) + 1];
		strcpy( name, f.getName() );
		age = f.getAge();
}
//------------------------------------------------------------
Student::~Student() {							// (3) DTOR
		cout << "[" << this->getName() << "]: Student DTOR" << endl;
}
//------------------------------------------------------------
Student& Student::operator=(Employee& other) {		// (4) operator=
		// this = rhs;
		cout << "Student operator=() ..." << endl;

		if (this != &other) {
			this->Employee::operator=(other);
			this->hasTenure = other.getTenure();
		}
		
		return *this;
}
//------------------------------------------------------------
// OVERRIDE
void Student::greeting(char* theirName) {
		cout << "[" << this->getName() << "]: Student says, 'Verpisst dich bitte' " << theirName << endl;
}
//------------------------------------------------------------
// MUST OVERRIDE
void Student::farewell() {
		cout << "[" << this->getName() << "]: Student says, 'Tschau sucka! ...' " << endl;
}
//------------------------------------------------------------
// INHERIT: void setName(char* newName) 
//------------------------------------------------------------
// EXTEND
void Student::setTenure(bool b)
{
		hasTenure = b;
}
	
// inline bool getTenure(void) const { return hasTenure; }
//------------------------------------------------------------
	