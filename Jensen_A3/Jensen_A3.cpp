/*
Jensen_A3.cpp
10/02/13
Bryan Jensen

Contains the functionality for the DEMData_Holder and DEMData_Reader classes, as well as a few helpful
functions.

Description: This file contains various methods and functions for the functionality of the two classes.

*/

#include "Jensen_A3.h"

using namespace std;

// Comparison function for use in qsort - returns positive, negative or 0 based on relative size
// of the float-cast pointers
static int oldStyleCompare( const void* a_, const void* b_ ) {
	const float a = *(float*)a_;
	const float b = *(float*)b_;

	if( a < b )
		return -1;
	if( a > b )
		return 1;
	return 0;
}

// Debug function to check the sorted-ness of a float array.
void checkSort(float array[], long arrayLength) {
	for (int i = 0; i < arrayLength-1; i++) {
		if (array[i] > array[i+1]) {
			cout << endl << "Whoops, not sorted correctly!" << endl << endl;
			cout << array[i] << " is greater than " << array[i+1] << endl;
		}
	}
}

// Default constructor for the data holder
DEMData_Holder::DEMData_Holder() {
	this->dataRead = false;
	this->sorted = false;
	this->numDataPoints = 0;
	this->highestElev = 0;
	this->lowestElev = 0;
	this->meanElev = 0;
	this->medianElev = 0;
}

// Method to grab file contents from the file denoted by filename and store the data in
// a float array. 
void DEMData_Holder::readFile(string filename) {
	cout << "Opening: " << filename << endl;

	ifstream inFile;
	long numCols; // Number of columns of data
	long numRows; // Number of rows of data
	float xLLCorner; // X-position of the lower left corner
	float yLLCorner; // Y-position of the lower left corner
	float cellSize; // Size of a data cell

	float dataPoint; // Individual data points in array

	inFile.open(filename.c_str()); // Open file

	while (inFile.fail()) {
		cout << "Failed to open " << filename << endl;
		cout << "Try again: ";
		cin >> filename;
		inFile.open(filename.c_str());
	}

	string trash;
	inFile >> trash >> numCols; // Ditching the "ncols", grabbing the value
	inFile >> trash >> numRows; // Ditching the "nrows", grabbing the value
	inFile >> trash >> xLLCorner; // Ditching the "nrows", grabbing the value
	inFile >> trash >> yLLCorner; // Ditching the "nrows", grabbing the value
	inFile >> trash >> cellSize; // Ditching the "nrows", grabbing the value

	if (this->dataRead) {
		delete[] this->elevArray;
		cout << "Deleting old dataset" << endl;
	}

	long totalSize = numRows * numCols;
	this->numDataPoints = totalSize;
	this->elevArray = new float[totalSize];

	long currentSlot = 0;
	inFile >> dataPoint; // Grab initial dataPoint

	while (inFile) {
		this->elevArray[currentSlot] = dataPoint;
		inFile >> dataPoint;
		if (currentSlot >= totalSize) {
			cout << endl << endl << "Whoops, over-ran the size of the array (file input faulty)." << endl << endl << endl;
		}
		currentSlot++;
	}

	this->dataRead = true;
}

// Method to analyze data after it has been fetched with readFile - stored all results in data members
// for later displaying and use
void DEMData_Holder::analyzeDataArray(string sortType) {
	this->highestElev = *(max_element(this->elevArray, this->elevArray + this->numDataPoints));
	this->lowestElev = *(min_element(this->elevArray, this->elevArray + this->numDataPoints));

	float sum = 0;
	for (float* iterator = this->elevArray; iterator != this->elevArray+this->numDataPoints; iterator++) {
		sum += *iterator;
	}
	this->meanElev = sum / this->numDataPoints;

	this->sortedElevArray = this->elevArray;
	clock_t start, stop;
	if (this->sorted) {
		cout << "Array already sorted, not re-sorting" << endl;
		return;
	}
	else if (sortType == "sort") {
		start = clock();
		sort(this->sortedElevArray, this->sortedElevArray + this->numDataPoints);
		stop = clock();
		double duration = (double)(stop - start) / CLOCKS_PER_SEC;
		cout << "sort took: " << duration << " seconds" << endl;
		// checkSort(this->sortedElevArray, this->numDataPoints);
	}
	else if (sortType == "qsort") {
		start = clock();
		qsort(this->sortedElevArray, this->numDataPoints, sizeof(float), oldStyleCompare);
		stop = clock();
		double duration = (double)(stop - start) / CLOCKS_PER_SEC;
		cout << "qsort took: " << duration << " seconds" << endl;
		// checkSort(this->sortedElevArray, this->numDataPoints);
	}

	this->sorted = true;

	if (this->numDataPoints % 2 == 0) {
		float firstMid = this->sortedElevArray[this->numDataPoints/2-1];
		float secondMid = this->sortedElevArray[this->numDataPoints/2];
		
		this->medianElev = (firstMid + secondMid) / 2;
	}
	else {
		this->medianElev = this->sortedElevArray[this->numDataPoints/2];
	}
}

// Method to print to stdout a table of all data in the data holder.
void DEMData_Holder::tableOutput(string title) {
	short columnWidths[] = {15, 15, 15, 15, 15};
	cout << "Table #" << title << ": " << endl;
	cout << setw(columnWidths[0]) << "numDataPoints" <<
			setw(columnWidths[1]) << "highestElev" <<
			setw(columnWidths[2]) << "lowestElev" <<
			setw(columnWidths[3]) << "meanElev" <<
			setw(columnWidths[4]) << "medianElev" <<
			endl;
	cout << setw(columnWidths[0]) << this->numDataPoints <<
			setw(columnWidths[1]) << this->highestElev <<
			setw(columnWidths[2]) << this->lowestElev <<
			setw(columnWidths[3]) << this->meanElev <<
			setw(columnWidths[4]) << this->medianElev <<
			endl;
}

// Default constructor for the data reader, which contains two data holders
DEMData_Reader::DEMData_Reader() {
	this->dataRead = false;
	this->gotRMSE = false;
	this->RMSE = 0;
}

// Method for reading data in from files denoted by user-input filenames
// Once data has been read, then it is analyzed with the analyzer and calcRMSE.
void DEMData_Reader::getFileData() {
	string firstFilename;
	string secondFilename;

	cout << "Input first filename: ";
	cin >> firstFilename;
	// firstFilename = "testFile18.grd";
	// firstFilename = "MtWashington1.grd";

	cout << "Input second filename: ";
	cin >> secondFilename;
	// secondFilename = "testFile19.grd";
	// secondFilename = "MtWashington2.grd";

	cout << endl;

	firstData.readFile(firstFilename);
	secondData.readFile(secondFilename);

	this->dataRead = true;

	this->analyzeData();
	this->calcRMSE();
}

// Method to analyze data on both data holders
void DEMData_Reader::analyzeData() {
	if (!this->dataRead) {
		cout << "No data has been read in..." << endl;
	}
	else {
		firstData.analyzeDataArray("sort");
		secondData.analyzeDataArray("qsort");
	}
}

// Method to output the table of data for both holders
void DEMData_Reader::tableOutput() {
	this->firstData.tableOutput("1");
	this->secondData.tableOutput("2");

	cout << "Inter-Table Data: " << endl;
	cout << "\tRMSE between the two arrays: " << this->RMSE << endl;
}

// Method to calculate RMSE between the two data holder's arrays
void DEMData_Reader::calcRMSE() {
	if (!this->dataRead) {
		cout << "No data has been read in..." << endl;
	}
	else {
		float* arrayOne = this->firstData.getElevArray();
		float* arrayTwo = this->secondData.getElevArray();

		long shorterArrayLength = min(this->firstData.getNumDataPoints(), this->secondData.getNumDataPoints());

		float tempValue = 0;
		float sumSquare = 0;
		for (int i = 0; i < shorterArrayLength; i++) {
			tempValue = arrayOne[i] - arrayTwo[i];
			sumSquare += (tempValue * tempValue);
		}

		float innerValue = (float)sumSquare / (float)shorterArrayLength;

		this->RMSE = sqrt(innerValue);
	}
}