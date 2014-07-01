#ifndef FACULTY
#define FACULTY

#include <iostream>
#include "Employee.h"
using namespace std;

class Faculty: public Employee
{
  public:

	Faculty();                          // (0) Default CTOR
	Faculty(char* s, int a, bool b);	// (1) Parameterized CTOR
	Faculty(Faculty& f);				// (2) Copy CTOR
			
	virtual ~Faculty(); 				// (3) DTOR
			
    Faculty& operator=(Employee& rhs);   // (4) operator=
		
	virtual void greeting(char* theirName);
		
	virtual void farewell();
		
	void setTenure(bool b);
	
	inline bool getTenure(void) const { return hasTenure; }
	
  protected:
		bool hasTenure;
		
}; // class Faculty

#endif
