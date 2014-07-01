#include "Fraction.h"

using namespace std;

Fraction::Fraction() { numer = 0; denom = 1; }

Fraction::Fraction(long n, long d) {
	numer = n;
	denom = d;
}

Fraction Fraction::flip() {
	return Fraction(denom, numer);
}

Fraction Fraction::operator+(Fraction other) {
	long newNumer = numer*other.denom + other.numer*denom;
	long newDenom = denom*other.denom;

	return Fraction(newNumer, newDenom);
}

Fraction Fraction::operator-(Fraction other) {
	long newNumer = numer*other.denom - other.numer*denom;
	long newDenom = denom*other.denom;

	return Fraction(newNumer, newDenom);
}

Fraction Fraction::operator*(Fraction other) {
	long newNumer = numer * other.numer;
	long newDenom = denom * other.denom;

	return Fraction(newNumer, newDenom);
}

Fraction Fraction::operator/(Fraction other) {
	Fraction otherFlipped = other.flip();

	return (*this) * otherFlipped;
}

bool Fraction::operator==(Fraction other) {
	return (numer == other.numer) and (denom == other.denom);
}

ostream& operator<<(ostream& co, Fraction f) {
	co << f.numer << "/" << f.denom;
	return co;
}

istream& operator>>(istream& ci, Fraction& f) {
	char trash;
	ci >> f.numer >> trash >> f.denom;
	return ci;
}