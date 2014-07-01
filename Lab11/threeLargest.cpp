#include <iostream>
#include <time.h>
#include <fstream>

using namespace std;

// function partition(list, left, right, pivotIndex)
//      pivotValue := list[pivotIndex]
//      swap list[pivotIndex] and list[right]  // Move pivot to end
//      storeIndex := left
//      for i from left to right-1
//          if list[i] < pivotValue
//              swap list[storeIndex] and list[i]
//              increment storeIndex
//      swap list[right] and list[storeIndex]  // Move pivot to its final place
//      return storeIndex

short partition(float* list, long left, long right, long pivotIndex) {
	float pivotValue = list[pivotIndex]
	float tempVal = list[pi]
}

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

	inFile >> nElements;
	float arr[nElements];
	for (long i = nElements-1; i >= 0; i--) {
		inFile >> arr[i];
	}


	

	stop = clock();

	cout << "Results 1: " << threeLargest[0] << endl;
	cout << "Results 2: " << threeLargest[1] << endl;
	cout << "Results 3: " << threeLargest[2] << endl;
	cout << "It took: " << (double)(stop-start) / CLOCKS_PER_SEC << " seconds" << endl;
}