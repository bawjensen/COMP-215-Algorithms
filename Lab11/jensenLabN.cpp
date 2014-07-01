#include <iostream>
#include <time.h>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
	clock_t start, stop;
	long nElements;
	float threeLargest[3] = {0};
	float nextVal;
	string filename;
	FILE *inFile;

	cout << "Input a filename: ";
	cin >> filename;
	const char* cstrFilename = filename.c_str();

	start = clock();

	inFile = fopen(cstrFilename, "r");
	// inFile.open("data3.txt");

	fscanf (inFile, "%ld", &nElements);

	for (; nElements > 0; nElements--) {
		fscanf (inFile, "%f",  &nextVal);
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

	cout.setf(ios::fixed, ios::floatfield);
	cout.setf(ios::showpoint);

	cout << "Results 1:   " << setw(15) << setprecision(2) << threeLargest[2] << endl;
	cout << "Results 2:   " << setw(15) << setprecision(2) << threeLargest[1] << endl;
	cout << "Results 3:   " << setw(15) << setprecision(2) << threeLargest[0] << endl;
	cout << "Test:        " << setw(15) << setprecision(2) << 1.0f << endl;
	cout << "It took:     " << (double)(stop-start) / CLOCKS_PER_SEC << " seconds" << endl;
}
