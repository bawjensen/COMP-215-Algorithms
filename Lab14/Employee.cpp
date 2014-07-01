
#include <iostream>

#include "Employee.h"

using namespace std;

//------------------------------------------------------------
Employee::Employee() {								// (1) Default CTOR
		name = "DefaultName";
        cout << "[" << this->name << "]: Employee Default CTOR ..." << endl;
}
//------------------------------------------------------------
Employee::Employee(char* s, int a) {					
		name = new char[strlen(s)+1];
		strcpy(name, s);
		age = a;
    
        cout << "[" << this->getName() << "]: Employee Parameterized CTOR ..." << endl;
    
}
//------------------------------------------------------------
Employee::Employee(const Employee& e) {				// (2) Copy CTOR
		cout << "[" << e.getName() << "]: Employee COPY CTOR ..." << endl;
		this->name = new char[strlen( e.getName() ) + 1];
		strcpy( this->name, e.getName() );
		this->age = e.getAge();
}
//------------------------------------------------------------
Employee::~Employee() {						// (3) DTOR
		cout << "[" << this->getName() << "]: Employee DTOR ..." << endl;
		if (name)
			delete name;
}
//------------------------------------------------------------
Employee& Employee::operator=(const Employee& other) {		// (3) Operator=
	if (this != &other) {
		cout << "[" << other.getName() << "]: Employee Operator= ..." << endl;
		this->name = new char[strlen( other.getName() ) + 1];
		strcpy( this->name, other.getName() );
		this->age = other.getAge();
	}

	return *this;
}
//------------------------------------------------------------
void Employee::greeting(char* theirName) {
		cout << "[" << this->getName() << "]: Employee WELCOME " << theirName << endl;
}
//------------------------------------------------------------
// inline char* getName(void) const { return name; }
//------------------------------------------------------------	
void Employee::setName(char* newName) {
		if (name != 0) 
			delete[] name;
		name = new char[strlen(newName)+1];
		strcpy(name, newName);
}
//------------------------------------------------------------
// inline int getAge(void) const { return age; }
//------------------------------------------------------------

//============================================================