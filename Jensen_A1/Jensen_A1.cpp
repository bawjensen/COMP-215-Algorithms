#include "Jensen_A1.h"

using namespace std;

String::String() {
	// Default constructor - sets contents of String object to the empty character array of length 1.
	// Precondition: No String object created.
	// Postcondition: String object created with contents of an empty character array
	//                of length 1.
	contents = new char[1]; // Not set to null becuase cout'ing a character array
							// implicitly attempts dereferencing - bad news for the 0
							// memory location.
}

String::String(const char c[]) {
	// Copy constructor - sets contents of String object to the contents of the passed
	// character array.
	// Precondition: No String object created.
	// Postcondition: String object created with the contents set to the passed char array.
	short lenC = strlen(c);
	contents = new char[lenC];

	strcpy(contents, c);
}

long String::length() {
	// Method to return the length of the String.
	// Precondition: String has contents initialized.
	// Postcondition: Returned long with length of String object.
	return strlen(contents);
}

String String::operator+(String other) {
	// Concatenation operator - concatenates two strings together and returns a new
	// String object with the new contents.
	// Precondition: Two separate string objects with contents arrays.
	// Postcondition: A new string created with the copy constructor, returned to caller.
	short lenThis = strlen(contents);
	short lenOther = strlen(other.contents);

	char* buffContents = new char[lenThis + lenOther]; // char array buffer to store result
	strcpy(buffContents, contents);
	strcpy(buffContents+lenThis, other.contents);

	String buff(buffContents); // String buffer variable
	delete[] buffContents; // preventing (some) memory leaks

	return buff;
}

String String::operator+=(String other) {
	// Append operator - appends the contents of other onto the first String.
	// Precondition: Two separate string objects with distinct contents.
	// Postcondition: First String object contents are expanded and include the contents
	//				  of the "other" String appended at the end.
	short lenThis = strlen(contents);
	short lenOther = strlen(other.contents);

	char* newContents = new char[lenThis + lenOther];
	strcpy(newContents, contents);
	strcpy(newContents+lenThis, other.contents);

	delete[] contents; // preventing (some) memory leaks
	contents = newContents;

	return (*this);
}

char String::operator[](short i) {
	// Index access - accepts a short, i, and returns the value of the 'i'th + 1 element.
	// Precondition: String has contents array. Does error checking.
	// Postcondition: Returns a character to the caller.
	if (i >= strlen(contents)) {
		cout << "Error: Bad index" << endl; // Note: Doesn't raise an exception
		return contents[strlen(contents)-1];
	}
	return contents[i];
}

void String::operator=(const char c[]) {
	// Assignment operator - assigns the right operand of type char array to
	// the contents of the String object.
	// Precondition: A String object with or without a filled contents array.
	// Postcondition: Old contents memory freed up, with new char array stored in contents.
	short lenC = strlen(c);
	delete[] contents; // preventing (some) memory leaks
	contents = new char[lenC];

	strcpy(contents, c);
}

bool String::operator==(String other) {
	// Boolean equality operator - evaluates whether or not the two strings have
	// identical contents in terms of chars.
	// Precondition: Two String objects with contents arrays.
	// Postcondition: A returned value with the evaluation of the equality of the two Strings.
	if (strlen(contents) == strlen(other.contents)) { // If length isn't the same, fails right away
		for (short i = 1; contents[i] != '\0'; i++) { // loops until termination character '\0'
			if (contents[i] != other.contents[i]) { // Once two elements aren't the same, fails
				return false;
			}
		}
		return true; // Made it through all elements
	}
	else {
		return false;
	}
}

ostream& operator<<(ostream& co, const String& s) {
	// Overloading ostream operator output - prints out the contents of the String
	// object to stdout.
	// Precondition: String object with contents array, full or empty.
	// Postcondition: Std output to user of contents's characters.
	for (short i = 0; s.contents[i] != '\0'; i++) { // Iterates through till termination character
		co << s.contents[i];
	}
	return co;
}

istream& operator>>(istream& ci, String& s) {
	// Overloading istream operator input - takes in user input from stdin
	// and stores it in the String's contents.
	// Precondition: String object with contents array, full or empty.
	// Postcondition: String object with filled contents array, and the istream object
	//				  returned to the caller.
	short guess_length = 5; // guessed length of input - adjusted later if wrong
	short count = 0; // counter variable for index
	char* buffContents; // character array buffer variable
	char* temp; // temp character array storage for creating new (larger) arrays if needed
	char c[2]; // small array to take input from cin - Note: length is 2 due to quirks of cin

	buffContents = new char[guess_length]; // Create initial guessed array

	for (int i = 0; ci; i++) { // Iterate until ci evaluates as false (aka out-of-input)
		if (ci.get(c, 2)) { // checks to see that the get operation works - Note: length 2
							// actually grabs the first character off of the array
			buffContents[i] = *c; // Store the contents
		}

		if (i > guess_length) {
			guess_length *= 2; // Step-up the guessed size of input
			temp = new char[guess_length]; // Create new guess buffer
			strcpy(temp, buffContents);
			delete[] buffContents; // delete old - preventing (some) memory leaks

			buffContents = temp; // Store old into new and continue
		}
	}

	delete[] s.contents; // preventing (some) memory leaks
	s.contents = buffContents;

	return ci;
}