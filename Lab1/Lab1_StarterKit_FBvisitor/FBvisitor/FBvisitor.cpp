#include <iostream>
#include <stdlib.h>
//#include <math.h>

#include "FBvisitor.h"

using namespace std;

// ---------------------------------------------------------
// Default CTOR
FBvisitor::FBvisitor()
{
	firstName     = "DEFAULT_first";
	lastName      = "DEFAULT_last";
	politicalView = "DEFAULT_politicalView";
	gender        = "DEFAULT_gender";
	age           = -1;
	GPA           = -1;
}

// ---------------------------------------------------------
// Parameterized CTOR (using initialization lists)
FBvisitor::FBvisitor(string f, string l)
	: firstName(f), lastName(l), politicalView("DEFAULT_politicalView"), gender("DEFAULT_gender"), age(-1), GPA(-1)
{
}

// ---------------------------------------------------------
// Parameterized CTOR (using initialization lists)
FBvisitor::FBvisitor(string f, string l, string political, string sex, short a, float g)
	 : firstName(f), lastName(l), politicalView(political), gender(sex), age(a), GPA(g)
{
}

// ---------------------------------------------------------
// Destructor - DTOR
FBvisitor::~FBvisitor() {
		// nothing to do since no dynamic memory was allocated
}


// GETters
// ---------------------------------------------------------
string FBvisitor::getFullName() const {
	 string full = firstName + " " + lastName + " "
			 	+ politicalView + " " + gender;
	 return full;
}

string FBvisitor::getFirstName() const {
	return firstName;
}

string FBvisitor::getLastName() const {
	return lastName;
}

string FBvisitor::getPoliticalView() const {
	return politicalView;
}

string FBvisitor::getGender() const {
	return gender;
}

short FBvisitor::getAge() const {
	return age;
}

float FBvisitor::getGPA() const {
	return GPA;
}


// SETters
// ---------------------------------------------------------
void FBvisitor::setFirstName(string f) {
	this->firstName = f;
}

void FBvisitor::setLastName(string l) {
	this->lastName = l;
}

void FBvisitor::setPoliticalView(string pV) {
	this->politicalView = pV;
}

void FBvisitor::setGender(string g) {
	this->gender = g;
}

void FBvisitor::setAge(short a) {
	this->age = a;
}

void FBvisitor::setGPA(float g) {
	this->GPA = g;
}



// OVERLOADED OPERATORS
// ---------------------------------------------------------
bool FBvisitor::operator==(const FBvisitor& F) {
		return ( (this->firstName == F.firstName) &&
						 (this->lastName  == F.lastName) &&
						 (this->politicalView  == F.politicalView) &&
						 (this->gender  == F.gender) &&
						 (this->age  == F.age) &&
						 (this->GPA  == F.GPA)
					 ); 
}


// ---------------------------------------------------------
// FRIEND
ostream& operator<<(ostream& fout, const FBvisitor& who) {
	fout << "---------------------------------------------" << endl;
	fout << " " << who.firstName << " " << who.lastName << " - " << who.age << endl;
	fout << " [" << who.gender << ", " << who.politicalView << ", " << who.GPA << "]" << endl;
	fout << "---------------------------------------------" << endl;   
				
	return fout;
}


// ---------------------------------------------------------
// OTHER
void FBvisitor::makeMeRandom() {
	static const short MAX_MEN = 2;
	static const short MAX_WOMEN = 2;
	static const string boom[] = {'boom'};
	static const string boom[] = {'boom'};
	static const string boom[] = {'boom'};
	static const string boom[] = {'boom'};
}