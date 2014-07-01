/*
Jensen_A2.cpp
9/16/13
Bryan Jensen

Functionality for the number, decimal, binary and hexadecimal classes, as well as a few
helpful functions.

Description: This file contains the methods for the number class and all defined subclasses,
			 as well as a few functions to be called by the methods.
*/

#include "Jensen_A2.h"

using namespace std;

char numToChar(long i) {
	// Converts a number into the character equivalent - note, only supports numbers with
	// bases under 37.
	// Precondition: Passing in an int, 0 <= i <= 36
	// Postcondition: Returns the ith character from the global available-characters array.
	return CHARS_AVAILABLE[i];
}

string convertBasedLong(long num, long base) {
	// Converts a long into a string, representing that number in the given base.
	// Precondition: num is the base-10 equivalent of the number to be returned in
	//               string form, and base must be between 1 and 36, inclusive
	// Postcondition: A string with the number, as a string, in its base returned to caller
	long highestMultiple = 1; // The highest multiple that goes into num while leaving a remainder

	while (num / (highestMultiple*base) != 0) {
		highestMultiple *= base;
	}

	string rebasedNumStr; // The string to be returned
	long leftMostNum; // A number for the leftmost in the altered num
	long baseMultiple = highestMultiple; // The multiple to divide by

	while (baseMultiple > 1) { // While baseMultiple is still a multiple of base
		leftMostNum = num / baseMultiple; // Take the left most digit in the base
		num = num % baseMultiple; // Store the remainder back into num
		baseMultiple /= base; // Change baseMultiple accordingly

		rebasedNumStr.push_back(numToChar(leftMostNum)); // Add the char version of the number onto the string

	}

	rebasedNumStr.push_back(numToChar(num)); // Add the final digit onto the string
	return rebasedNumStr;
}

number::number(const number& n, long newBase) {
	// Copy constructor for number superclass - called only by subclass copy constructors
	// Creates a new number object while doing the proper conversions for the data members.
	// Precondition: n is some subclass object of the superclass number, and newBase is the base
	//               for the new subclass object.
	// Postcondition: A new number (or some subclass thereof) object is created with the same
	//                decimalValue as that of the parameter, with the correct corresponding
	//				  value, derived from the base.
	this->base = newBase;
	pair<string,long> values = n.copy();
	this->decimalValue = values.second; // decimalValue can be copied directly
	this->value = convertBasedLong(this->decimalValue, this->base); // value must be derived from decimalValue  
																	// based on the new base.
}

pair<string,long> number::copy() const {
	// Returns the important data members from the object.
	// Precondition: number is an object with a value and a decimalValue.
	// Postcondition: A pair object is returned, containing the value string and decimalValue long.
	return make_pair(value, decimalValue);
}

bool number::test() const {
	// A simple boolean tester to output whether any previous construction resulting in the correct
	// values for value and decimalValue (uses strtol to test this)
	// Precondition: <string> has been included, number object has value and decimalValue
	// Postcondition: Boolean returned based on equality of the conversion and stored value.
	return (strtol(this->value.c_str(), NULL, this->base) == this->decimalValue);
}

number& number::operator=(const number& n) {
	// Assignment operator for number class, which accounts for the base when assigning the value
	// into the new object.
	// Precondition: n is some object of number or a subclass of number, with value and decimalValue
	// Postcondition: This object has its value and decimalValue overwritten by the new contents, determined
	// 				  by the value and decimalValue of the passed number.
	this->decimalValue = n.getDecimalValue();

	this->value = convertBasedLong(this->decimalValue, this->base); // Calls helpful function for conversion

	return (*this);
}

ostream& operator<<(ostream& co, const number& n) {
	// ostream operator overload (for use with cout <<)
	// Precondition: <iostream> and <algorithm> have been included
	// Postcondition: The ostream object now contains the information contained in the value variable,
	// 				  converted to all uppercase for presentation.
	if (DEBUG_MODE) { // DEBUG_MODE should always be false
		co << n.value << "(" << n.decimalValue << " base 10)";
	}
	else {
		string temp = n.value; // Stores the value in a temp variable, as to not alter the original
		transform(temp.begin(), temp.end(), temp.begin(), ::toupper); // Converts string to uppercase
		co << temp; // Insert data into ostream object
	}

	return co;
}

istream& operator>>(istream& ci, number& n) {
	// istream operator overload (for use with cin >>)
	// Precondition: <iostream> and <algorithm> have been included, and data has been entered into the
	//				 istream object via user input (aka the terminal)
	// Postcondition: The data from the istream is stored in the number object's data members value and
	// 				  decimalValue, with the proper conversions having taken place

	string temp; // Temp string to grab data from istream
	ci >> temp;

	transform(temp.begin(), temp.end(), temp.begin(), ::tolower); // Convert temp to lowercase

	bool validInput = true; // Flag for validity of input

	for (unsigned long i = 0; i < temp.length(); i++) {
		bool flag = false; // Flag for validity of a certain character

		for (unsigned long j = 0; j < n.base; j++) {
			if (temp[i] == CHARS_AVAILABLE[j]) { // Iterate over all allowed characters
				flag = true; // If any match, then the char is valid input
			}
		}
		if (!flag) { // If none of the allowed characters matched temp[i], then the character is invalid
			validInput = false; // If any character is invalid, the whole thing is invalid
			cout << "Unallowed char in cin assignment: " << temp[i] << endl; // Error message
		}
	}

	if (validInput) { // If the input was valid
		n.value = temp; // Store it
		n.decimalValue = strtol(n.value.c_str(), NULL, n.base); // Store the converted to long form
	}
	else {
		cout << "Value was not assigned due to invalid characters present." << endl; // Error message
	}

	return ci;
}