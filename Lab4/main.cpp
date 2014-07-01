#include <iostream>

#include "Employee.h"
#include "Faculty.h"

int main(void)
{
	// PART 1
	cout << endl << endl << "----- starting main()'s scope ----------" << endl;
	
	Employee E;

	Employee Jane("Jane", 21);
	
	Faculty F;
	
	Faculty Pete("Pete", 44, false);

	// ------ end Part 1 --------------------
	
	

	// PART 2
	 
	cout << endl << endl << "------ Start PART 2 --------------------" << endl;
	 
	Jane.greeting("Foobar");
	 
	Pete.greeting("Mary");
	
	Jane.farewell();
	
	Pete.farewell();
	
   // ------ end Part 2 --------------------
	
	
	
	// PART 3
	cout << endl << endl << "------ Start PART 3 --------------------" << endl;

	Jane.setName("Janey");
	Jane.setAge(22);
	cout << Jane.getName() << " is this old: " << Jane.getAge() << endl;
	 
	Pete.setName("Petey");
	Pete.setAge(45);
	Pete.setTenure(true);
	cout << Pete.getName() << " is this old: " << Pete.getAge() << " and he does";
	if ( !Pete.getTenure() )
	    cout << " NOT ";
	cout << " have tenure." << endl;
	
	// ------ end Part 3 --------------------
	
	
	
	
	// PART 4
	cout << endl << endl << "------ Start PART 4 --------------------" << endl;
	
	// uncomment one line at a time and implement the necessary additional behaviors
	
	Faculty DrWho( Pete );     // ahh, you'll need your copy CTOR at this point, right?
	DrWho.setTenure( false );
	cout << DrWho << endl;     // hmmm, you need what in order to do this in main() ?
	 
	//Jane.setTenure( true );    // is this legal?
	
	{   // make a new (bogus) SCOPE
		Faculty DrBriefly("Dr. Briefly", 99, true);
		cout << DrBriefly << endl;
	}
	
	// note what happens when the object leaves scope (see your output)
	 
	Faculty JoeSmo;
	
	JoeSmo = Pete;               // what do you need to do this?  or do you?
	 
	JoeSmo.setName("JoeSmo");
	JoeSmo.setTenure( true );
	cout << JoeSmo << endl;
  
	// ------ end Part 4 --------------------
	
	
	
	cout << endl << endl << "----- leaving main()'s scope ----------" << endl;
	return 0;
}
