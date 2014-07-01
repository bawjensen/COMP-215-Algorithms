//
//  mainTweet.cpp
//  Xcode_Project
//
//  Created by Mark LeBlanc on 10/16/13.
//  Copyright (c) 2013 Mark LeBlanc. All rights reserved.
//

#include "tweet.h"

int main() {
	// (0) get this block to run
	Tweet T;
	
	cout << "Enter a Tweet: ";
	cin >> T;
	cout << T;
	
	// (1) comment out (0); get this block to run
	
	for (short i = 1; i < 4; i++) {
		cout << "Enter a Tweet: ";
		cin >> T;
		
		cout << T;
	
	} // end for
	
	
	// (2) comment out (1); uncomment this block and get to run
	
	char temp[] = "foobar or fubar?";
	Tweet R(temp);
	{	// make fake scope for object P
		Tweet P;
		P = R;
		cout << "Leaving scope of P now ..." << endl;
	} // end of scope of P
	
	
	
	// (3) comment out (2); uncomment this block and get to run
	
	{	// make fake scope for object H
		// call the COPY CTOR on (i) auto-initialization
		Tweet H(T); 
		cout << H;
		
		// other uses of COPY CTOR are (ii) pass-object-by-value (iii) return object by value
	}
	
	
	
	cout << endl << " Done." << endl
		 << "_____________________________" << endl << endl;

	
	return 0;
}