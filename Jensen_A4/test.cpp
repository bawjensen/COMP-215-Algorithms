#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <time.h>

using namespace std;

int main() {
	ofstream outFile;
	short xRange = 500;
	short yRange = 500;
	long numPoints;
	string filename;
	ostringstream converter;

	srand(time(NULL));

	for (short i = 1; i <= 50; i++) {
		converter << "tst" << i;
		filename = converter.str();
		converter.str(""); // Clear
		numPoints = 100 * i;

		outFile.open(filename.c_str());

		outFile << numPoints;
		for (long i = 0; i < numPoints; i++) {
			outFile << endl << rand() % xRange << " " << rand() % yRange;
		}
		outFile.close();
	}
}