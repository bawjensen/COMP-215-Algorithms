// testing CANONICAL Object classes

#include <iostream>

#include "Employee.h"
#include "Faculty.h"
#include "Student.h"

void testCopyCTOR(Faculty e);

int main(void)
{
	cout << endl;

	Faculty F("Pete", 22, false);

	F.greeting("Mary");
	F.farewell();

	Employee* pE = new Faculty("Mark", 44, true);
	pE->greeting("Sal");
	pE->farewell();

	testCopyCTOR(F);

	Faculty G(F);

	delete pE;

	Faculty J("Jane", 23, false);
	Faculty T("Tarzan", 24, false);

	Student S1("Drew", 24, false);
	Student S2("Barry", 24, false);
	Student S3("Moore", 24, false);

	Faculty H;

	H = S3;

	Employee* array[7] = {
		&J,
		&T,
		&F,
		pE,
		&S1,
		&S2,
		&S3
	};

	for (int i = 0; i < 7; i++) {
		array[i]->greeting("Billy");
	}


	cout << endl;
		
	cout << endl << "END of main()." << endl;
	cout << "===========================================" << endl;

} // end main() ... DTORs called


//------------------------------------------------------------
void testCopyCTOR(Faculty f)
{
	cout << "Inside testCopyCTOR: we made a LOCAL copy of object for: " << f.getName() << endl;
		
		cout << "Now leaving scope of testCopyCTOR()" << endl;
}
