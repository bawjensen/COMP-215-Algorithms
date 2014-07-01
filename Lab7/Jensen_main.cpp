#include <iostream>
#include <fstream>
#include <time.h>
#include <limits.h>

using namespace std;

bool isPrime(long num, ofstream& fout, const char delimiter, const char lineEnd) {
	bool numIsPrime;
	long numMods;

	clock_t start;
	clock_t end;

	start = clock();

	if (num == 1) { // Testing for special case of 1
		numIsPrime = false;
		numMods = 0;
	}
	else if (num == 2) { // Testing for special case of 2
		numIsPrime = true;
		numMods = 0;
	}
	else if (num % 2 == 0) { // Testing for even numbers
		numIsPrime = false;
		numMods = 0;
	}
	else {
		numIsPrime = true; // Assume number is prime
		numMods = 0;
		long possibleFactor = 3;

		while (numIsPrime and possibleFactor < num) {
			if (num % possibleFactor == 0) {
				numIsPrime = false;
			}
			numMods++;
			possibleFactor += 2;
		}
	}
	end = clock();

	double timeItTook = (start - end) / CLOCKS_PER_SEC;

	// cout << "Mod ran " << numMods << " times." << endl;
	fout << num << delimiter;
	fout << (numIsPrime ? "True" : "False") << delimiter;
	fout << numMods << delimiter;
	fout << timeItTook  << delimiter;
	fout << lineEnd;

	return numIsPrime;
}

int main() {

	long numToTest;
	ofstream fout;
	string filename;

	filename = "test.csv";

	fout.open(filename.c_str());

	const char delimiter = ',';
	const char lineEnd = '\n';
	long numColumns = 4;
	string headers[] = {"Number (X)", "Prime (T/F)", "Number of Mods Performed", "Time (sec)"};

	for (long i = 0; i < numColumns; i++) {
		fout << headers[i] << delimiter;
	}
	fout << lineEnd;

	do {
		cout << "Give me a num: ";
		cin >> numToTest;
		if (isPrime(numToTest, fout, delimiter, lineEnd)) {
			cout << "Yes prime" << endl;
		}
		else {
			cout << "Not prime" << endl;
		}

	} while (numToTest != 0);

	cout << endl << "Done" << endl << endl;
}