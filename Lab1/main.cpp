#include <iostream>
#include "Fraction.h"

using namespace std;

int main() {
	Fraction test;

	cin >> test;
	cout << test << endl;

	Fraction newbie = test / test;

	cout << newbie << endl;
	cout << (newbie == newbie) << endl;

	cout << endl << "Done" << endl;
}