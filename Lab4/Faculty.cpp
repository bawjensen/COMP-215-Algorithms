#include "Faculty.h"

using namespace std;

Faculty::Faculty() {
	cout << "[Faculty] Creating default" << endl;
	this->age = -1;
	this->name = "NO NAME GIVEN";
}

Faculty::Faculty(string n, short a, bool t) {
	cout << "[Faculty] Creating new instance with name " << n << endl;
	this->name = n;
	this->age = a;
	this->tenure = t;
}

Faculty::Faculty(Faculty& other) {
	cout << "[Faculty] Copying " << other.name << " into new object" << endl;
	this->age = other.age;
	this->name = other.name;
	this->tenure = other.tenure;
}

Faculty::~Faculty() {
	cout << "[Faculty] Destroying " << this->name << endl;
}

void Faculty::setTenure(bool t) {
	this->tenure = t;
}

bool Faculty::getTenure() {
	return this->tenure;
}

void Faculty::greeting(string recipient) {
	this->Employee::greeting(recipient);
	cout << "[Faculty] " << this->name << " says: Welcome to class, " << recipient  << "." << endl;
}

void Faculty::farewell() {
	cout << "[Faculty] " << this->name << " says: Arrivaderci!" << endl;
}

Faculty& Faculty::operator=(Faculty& f) {
	this->age = f.age;
	this->name = f.name;
	this->tenure = f.tenure;
}