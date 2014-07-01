#ifndef _MYEMPLOYEE
#define _MYEMPLOYEE

#include <iostream>
#include <stdlib.h>

using namespace std;

class Employee {
protected:
	string name;
	unsigned short age;	
public:
	Employee();
	Employee(string, short);
	Employee(Employee&);
	~Employee();
	
	void setName(string);
	void setAge(short);

	string getName();
	short getAge();

	void greeting(string);
	void farewell();

	friend ostream& operator<<(ostream&, Employee&);
};

#endif