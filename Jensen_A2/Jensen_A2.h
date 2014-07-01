/*
Jensen_A2.cpp
9/16/13
Bryan Jensen

Program to implement various numbers of different bases, namely decimal (10), binary (2) and hexadecimal (16)
with istream input, assignment operation and copy construction possible between any of the base classes
of the superclass "number".

Description: This file contains the prototypes for the number superclass and various subclasses, such as decimal,
			 binary and hexadecimal. Each subclass inherits various useful methods from the number class,
			 with all of the overridden methods explicitly calling back to their superclass counterpart.

			 Methods:
			 	copy: Effectively a dual-get method, this returns a pair of string and long
			 		  representing the value and decimalValue contents of the number object.
			 	test: A method to return a boolean value representing the equality of the
			 		  value member in the number's base to the decimalValue member, in base 10.
			 		  Used extensively in testing and debugging.
				getDecimalValue: A getter for the decimalValue of the number object.

			 Operators overloaded:
			 	= (assignment): Assigns the values of the right operand (an object of some subclass of 
			 					the number superclass) to the values of the left operand. Note: decimalValue
			 					is assigned directly, but conversion must be done for the value string
			 					(the appearance of the string in its own base).

			 	>> (input overload [iostream]): Assigns the input of the istream to the value member of the
			 									object, and converts the value to a decimal (base 10)
			 									long for internal representation as the member
			 									decimalValue. Returns the istream object.

			 	<< (output overload [iostream]): Returns the contents of the member string value in an
			 									 ostream object.

Input:       The input inside the driver program must be the representation of the number in its own base,
			 and the input must be of only valid characters for the input to be assigned (otherwise an
			 error is shown in the ostream and the value is left untouched). 
Output:      The driver program can output any number object, showing the representation of that number in
			 its own base. In the example driver program given, various numbers are created and manipulated
			 in all three bases, and the results from various operations are shown.

*/

#ifndef _NUMBASES
#define _NUMBASES

#include <iostream>
#include <stdlib.h>
#include <string>
#include <algorithm>

using namespace std;

static const string CHARS_AVAILABLE = "0123456789abcdefghijklmnopqrstuvwxyz"; 
									                      // Available characters for use in based numbers (useful above base 10)
const bool DEBUG_MODE = false;                            // Set to false when done w/ program

class number {
protected:
	string  value;                                        // Internal representation of the number in its own base
	long    base;                                         // The value of the base of this specific number
	long    decimalValue;                                 // Internal representation of the actual value of this number (aka in base 10)
public:
	number() { decimalValue = 0; value = "0"; };          // Default constructor
	number(const number& n) { this->value = n.value; this->decimalValue = n.decimalValue; }; // Superclass copy constructor
	number(const number&, long);                          // Copy constructor used in subclasses

	pair<string,long> copy() const;                       // Dual-getter for value and decimalValue
	bool test() const;                                    // Test to see if the value is indeed equal to the decimalValue (after conversion)

	long getDecimalValue() const { return this->decimalValue; }; // Getter for decimalValue

	number& operator= (const number&);                       // Assignment operator
	friend ostream& operator<< (ostream&, const number&); // Inserts user input into number object
	friend istream& operator>> (istream&, number&);       // Displays number in its own base
};

class decimal : public number {
public:
	decimal() { this->base = 10; };                       // Default constructor - implicitly calls number's as well
	decimal(const number& n) : number(n, 10) {};          // Copy constructor - takes any subclass of number, redirects the call
														  // to number's second copy constructor
	number& operator= (const number& n) { return this->number::operator=(n); }; // Assignment operator - takes any subclass, redirects to
																	  // number's operator=
};

class binary : public number {
public:
	binary() { this->base = 2; };                         // Default constructor - implicitly calls number's as well
	binary(const number& n) : number(n, 2) {};            // Copy constructor - takes any subclass of number, redirects the call
														  // to number's second copy constructor
	number& operator= (const number& n) { return this->number::operator=(n); }; // Assignment operator - takes any subclass, redirects to
																	  // number's operator=
};

class hexadecimal : public number {
public:
	hexadecimal() { this->base = 16; };                   // Default constructor - implicitly calls number's as well
	hexadecimal(const number& n) : number(n, 16) {};      // Copy constructor - takes any subclass of number, redirects the call
														  // to number's second copy constructor
	number& operator= (const number& n) { return this->number::operator=(n); }; // Assignment operator - takes any subclass, redirects to
																	  // number's operator=
};

#endif