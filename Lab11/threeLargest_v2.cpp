#include <iostream>
#include <time.h>
#include <fstream>

using namespace std;

int main() {
	clock_t start, stop;
	long nElements;
	float threeLargest[3] = {0};
	float nextVal;
	string filename;
	ifstream inFile;

	cout << "Input a filename: ";
	cin >> filename;
	const char* cstrFilename = filename.c_str();

	start = clock();

	inFile.open(cstrFilename);
	// inFile.open("data3.txt");

	inFile >> nElements;

	for (; nElements > 0; nElements--) {
		inFile >> nextVal;
		if (nextVal > threeLargest[2]) {
			threeLargest[0] = threeLargest[1];
			threeLargest[1] = threeLargest[2];
			threeLargest[2] = nextVal;
		}
		else if (nextVal > threeLargest[1]) {
			threeLargest[0] = threeLargest[1];
			threeLargest[1] = nextVal;
		}
		else if (nextVal > threeLargest[0]) {
			threeLargest[0] = nextVal;
		}
	}

	stop = clock();

	cout << "Results 1: " << threeLargest[2] << endl;
	cout << "Results 2: " << threeLargest[1] << endl;
	cout << "Results 3: " << threeLargest[0] << endl;
	cout << "It took: " << (double)(stop-start) / CLOCKS_PER_SEC << " seconds" << endl;
}