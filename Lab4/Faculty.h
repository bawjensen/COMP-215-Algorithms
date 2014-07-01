#ifndef _MYFACULTY
#define _MYFACULTY

#include <iostream>
#include <stdlib.h>
#include "Employee.h"

using namespace std;

class Faculty : public Employee {
protected:
	bool tenure;
public:
	Faculty();
	Faculty(string, short, bool);
	Faculty(Faculty&);
	~Faculty();

	void setTenure(bool);

	bool getTenure();

	void greeting(string);
	void farewell();

	Faculty& operator=(Faculty&);
};

#endif