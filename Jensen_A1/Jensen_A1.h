/*
Jensen_A1.cpp
9/12/13
Bryan Jensen

Program to implement a string class using dynamic memory and overloading
various operators.

Description: This file contains a String class, made to mimic the functionality of the
			 built-in c++ string library by overloading many of the same operators with
			 the same functionality. 'String's can be made either with the default
			 constructor, which sets the contents to NULL, or with the parameter of a
			 character array.
			 Operators overloaded:
			 	+ (concatentation): Returns a String containing the contents of the first
			 						String with the contents of the second String appended
			 						to the end.

			 	+= (append concatenation): Modifies the first String, appending the contents
			 							   of the second String to the end, before returning
			 							   the first String.

			 	[] (access): Returns the value of the ('i'th + 1) character in the String.

			 	= (assignment): Assigns the right operand (character array) as the contents
			 					of the String.

			 	== (value comparison): Compares the String against another String or against
			 						   a character array (or string literal), returning a
			 						   boolean indicating the equality of the contents of
			 						   the two.

			 	>> (input overload [iostream]): Stores the entire contents of the input line
			 									(taken as a character array) in the contents
			 									of the String. Returns the istream object.

			 	<< (output overload [iostream]): Outputs to stdio the contents of the String,
			 									 returning the ostream object.

Input:       Inputs to the constructor can be either omitted in the case of the default
			 constructor, or passed as an array of characters (maximum length 10,000).
			 Alternative input can be done with the iostream cin, overwriting the contents
			 of an existing String.
Output:      Output is performed with the iostream cout, and outputs the contents of the
			 String as a group of characters. 

*/

#ifndef _STRING
#define _STRING

#include <iostream>
#include <vector>
#include <string.h>


using namespace std;

static const short MAX_LENGTH = 10000;

class String {
	char* contents;                  // Character array to store the characters
					                 // of the string.
  public:
  	String();                        // constructor
  	String(const char[]);            // copy constructor

	long length();                   // length of the contents

	String operator+(String);        // concatenate two strings
	String operator+=(String);       // append string onto first
	char operator[](short);          // index access operator
	void operator=(const char[]);    // assign char[] to string contents
	bool operator==(String);         // string contents equality operator

	friend ostream& operator<<(ostream&, const String&); // ostream overload
	friend istream& operator>>(istream&, String&);       // istream overload
};

#endif