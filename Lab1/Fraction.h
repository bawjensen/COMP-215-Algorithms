#ifndef _Fraction
#define _Fraction

#include <iostream>
#include <string>

using namespace std;

class Fraction {
	long numer;
	long denom;
  public:
  	Fraction();
  	Fraction(long, long);

  	Fraction flip();

	Fraction operator+(Fraction);
	Fraction operator-(Fraction);
	Fraction operator*(Fraction);
	Fraction operator/(Fraction);
	bool operator==(Fraction);
	friend ostream& operator<<(ostream&, Fraction);
	friend istream& operator>>(istream&, Fraction&);
};

#endif