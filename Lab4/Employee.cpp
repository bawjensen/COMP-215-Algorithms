#include "Employee.h"

using namespace std;

Employee::Employee() {
	cout << "[Employee] Creating default" << endl;
	this->age = -1;
	this->name = "NO NAME GIVEN";
}

Employee::Employee(string n, short a) {
	cout << "[Employee] Creating new instance with name " << n << endl;
	this->name = n;
	this->age = a;
}

Employee::Employee(Employee& other) {
	cout << "[Employee] Copying " << other.name << " into new object" << endl;
	this->age = other.age;
	this->name = other.name;
}

Employee::~Employee() {
	cout << "[Employee] Destroying " << this->name << endl;
}

void Employee::setName(string newName) {
	this->name = newName;
}

void Employee::setAge(short newAge) {
	this->age = newAge;
}

string Employee::getName() {
	return this->name;
}

short Employee::getAge() {
	return this->age;
}

void Employee::greeting(string recipient) {
	cout << "[Employee] " << this->name << " says: Hello there, " << recipient  << "." << endl;
}

void Employee::farewell() {
	cout << "[Employee] " << this->name << " says: Ciao!" << endl;
}

ostream& operator<<(ostream& os, Employee& e) {
	os << e.name << " - " << e.age;
}