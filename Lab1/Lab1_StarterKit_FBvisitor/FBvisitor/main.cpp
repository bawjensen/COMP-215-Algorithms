#include <iostream>

#include "FBvisitor.h"

using namespace std;

int main()
{
	
	// create an object with the default CTOR
	FBvisitor foo;
	
	// create another object with the semi-parametertized CTOR
	FBvisitor faa("DEFAULT_first", "DEFAULT_last");
	
	// create another object with the parametertized CTOR
	FBvisitor fee("chris", "fee", "democrat", "male", 20, 4.0);
	
	cout << endl;
	cout << "==== Testing operator<<() ===================================" << endl;
	// we can do the following since the class has a friend operator<<
	cout << foo << endl;
	cout << faa << endl;
	cout << fee << endl;
	cout << endl;

	cout << endl;
	cout << "==== Testing getFullName() ===================================" << endl;
	cout << faa.getFullName() << endl;
	cout << endl;

	cout << endl;
	cout << "==== Testing operator==() ===================================" << endl;
	cout << (foo == faa) << endl;    
	cout << endl;

	cout << endl;
	cout << "==== Testing SETTERS ===================================" << endl;
	cout << foo << endl;
	foo.setAge(77);
	cout << foo << endl;
	cout << endl;

	cout << endl;
	cout << "==== Testing GETTERS ===================================" << endl;
	cout << fee.getAge() << endl;
	cout << endl;

} // main()