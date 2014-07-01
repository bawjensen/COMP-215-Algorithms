#include <iostream>
#include "Jensen_A1.h"

using namespace std;

int main() {
	cout << endl;

	String s0;
	String s1("Hey");

	cout << "-1: " << s0 << endl;
	cout << "0: " << s1.length() << endl;

	cout << "1: " << s1 << endl;
	cin >> s1;
	cout << "2: " << s1 << endl;

	String s2(s1); // Note: this works (why? built-in?)
	String s3("Hello");

	cout << "3: " << s2 << endl;
	cout << "4: " << (s1 + s2) << endl;

	cout << "5: " << (s3 == s2) << endl;
	s2 = "Hello";
	cout << "5.5: " << (s3 == s2) << endl;

	cout << "6: " << s3[2] << endl;
	cout << "7: " << s3 << endl;

	s3 += s1;
	cout << "8: " << s3 << endl;
	cout << "9: " << s3.length() << endl;

	s3 = "France";
	cout << "10: " << s3 << endl;

	cout << endl << "Done" << endl << endl << endl;



	String s ("this "); // sets s to "this "
	String t; // sets t to a null string
	cin >> t;
	s += t;
	cout << s << endl;
	s += " that";
	cout << s << endl;
	cout << s[0] << endl;
	s = "Overloaded operators sure are fun!";
	cout << s << endl;
	cout << s.length() << endl;

	return 0;
}