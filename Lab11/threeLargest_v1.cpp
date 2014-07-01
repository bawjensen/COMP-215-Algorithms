#include <iostream>
#include <time.h>
#include <fstream>

using namespace std;

int main() {
	clock_t start, stop;
	long nElements;
	float threeLargest[3];
	string filename;
	ifstream inFile;

	cout << "Input a filename: ";
	cin >> filename;
	const char* cstrFilename = filename.c_str();

	start = clock();

	inFile.open(cstrFilename);
	// inFile.open("data3.txt");

	inFile >> nElements;

	float arr[nElements];
	for (long i = nElements-1; i >= 0; i--) {
		inFile >> arr[i];
	}

	long indexHighest = 0;
	for (short i = 0; i < 3; i++) {
		for (long j = nElements-1; j >= 0; j--) {
			if (arr[j] > arr[indexHighest]) {
				indexHighest = j;
			}
		}
		threeLargest[i] = arr[indexHighest];
		arr[indexHighest] = 0;
		indexHighest = 0;
	}

	stop = clock();

	cout << "Results 1: " << threeLargest[0] << endl;
	cout << "Results 2: " << threeLargest[1] << endl;
	cout << "Results 3: " << threeLargest[2] << endl;
	cout << "It took: " << (double)(stop-start) / CLOCKS_PER_SEC << " seconds" << endl;
}