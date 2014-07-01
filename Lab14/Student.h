#ifndef STUDENT
#define STUDENT

#include <iostream>
#include "Employee.h"
using namespace std;

class Student: public Employee
{
  public:

	Student();                          // (0) Default CTOR
	Student(char* s, int a, bool b);	// (1) Parameterized CTOR
	Student(Student& f);				// (2) Copy CTOR
			
	virtual ~Student(); 				// (3) DTOR
			
    Student& operator=(Employee& rhs);   // (4) operator=
		
	virtual void greeting(char* theirName);
		
	virtual void farewell();
		
	void setTenure(bool b);
	
	inline bool getTenure(void) const { return hasTenure; }
	
  protected:
		bool hasTenure;
		
}; // class Student

#endif
