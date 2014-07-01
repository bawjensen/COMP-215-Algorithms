#ifndef EMPLOYEE
#define EMPLOYEE

#include <iostream>
using namespace std;

class Employee
{
  public:
	//------------------------------------------------------------
	Employee();                               // (0) Default CTOR
    Employee(char* s, int a);                 // (1) Parameterized CTOR	
	Employee(const Employee& e);              // (2) Copy CTOR
		
	virtual ~Employee();                      // (3) DTOR
		
	Employee& operator=(const Employee& rhs); // (4) operator=
		
	virtual void greeting(char* theirName);
	
    virtual void farewell() = 0;
	
	inline char* getName(void) const { return name; }
	void setName(char* newName);
    
	inline int getAge(void) const { return age; }

   protected:
		char* name;
		int   age;
		
}; // class Employee

#endif
