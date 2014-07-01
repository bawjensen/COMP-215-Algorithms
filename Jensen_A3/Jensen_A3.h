/*
Jensen_A3.cpp
10/02/13
Bryan Jensen

Two classes for DEM data analysis.

Description: Two classes (Reader and Holder) to retrieve and hold data from a DEM Geographic Dataset. 
			 Filenames for input are read in stdio with iostream cin upon calling getFileData, and the rest
			 of the analysis happens automatically thereafter. The output is gotten via the method tableOutput,
			 and is presented via the stdio.

			DEMData_Holder:
			Methods:
			 	getNumDataPoints(): A getter for the data member numDataPoints.
			 	getElevArray(): A getter for the data member elevArray.
			 	readFile(): Reads in the file described by the provided filename into the elevArray data
			 				member while performing minimal error-checking, and also stores the numDataPoints
			 				value as the number of dataPoints read in.
			 	analyzeDataArray(): Analyzes the internal data member elevArray, taking in the type of sorting
			 						to perform for finding the median of the array. Stores the results of the
			 						analysis (max, min, mean, etc.) into data members.
			 	tableOutput(): Performs a stdio output of the tabular data contained in the object, including
			 				   the max, min, mean, median. NOTE: The RMSE belongs to the Reader, not an individual
			 				   file / dataset, and so is not output in here.

			DEMData_Reader:
			Methods:
				analyzeData(): Analyzes the read data from the DEM file and stores all relevant data. 
				calcRMSE(): Calculates the Root Mean Square Error between the two stored data sets, and stores
							the value for later use.
				getFileData(): Reads in two file names from the user and uses that to find and store all the
							   necessary information about the DEM data file. Calls internally the analyzeData
							   and calcRMSE methods.
				tableOutput(): Outputs both data holders' tableOutputs to the stdio as well and the inter-RMSE.


Input:      Two filenames representing two DEM data files of the correct format (no error checking done)
					at this stage.

Output:     Various timing statistics for sorting algorithms as well as the relevant information for each
			dataset's table, including the highest elevation, the lowest, the mean and the median. 


*/

#ifndef _JENSENA3
#define _JENSENA3

#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <time.h>
#include <limits.h>
#include <stdio.h>

using namespace std;

class DEMData_Holder {
private:
	bool dataRead; // Test for whether or not the data has been read in - prevention of user abuse
	bool sorted; // Test for whether or not the array has been sorted - prevention of user abuse
	float* elevArray; // Original elevation array
	float* sortedElevArray; // Implemented so as to not overwrite original with sorting
	long numDataPoints; // Info for table output - total number of elevation data points
	float highestElev; // Info for table output - highest elevation value
	float lowestElev; // Info for table output - lowest elevation value
	float meanElev; // Info for table output - mean elevation value
	float medianElev; // Info for table output - median elevation value

public:
	DEMData_Holder(); // Default CTOR

	long getNumDataPoints() { return this->numDataPoints; }; // Getter
	float* getElevArray() { return this->elevArray; }; // Getter

	void readFile(string); // Reads filename's contents into data members
	void analyzeDataArray(string); // Analyzes data array, storing results in other data members
	void tableOutput(string); // Outputs the relevant data members as a table
};

class DEMData_Reader {
private:
	bool dataRead; // Test for whether or not the data has been read in - prevention of user abuse
	bool gotRMSE; // Test for whether or not the RMSE has been calculated - prevention of user abuse
	DEMData_Holder firstData; // First data holder (yes, this is hard-coded to have only two)
	DEMData_Holder secondData; // Second data holder (yes, this is hard-coded to have only two)
	float RMSE; // Info for table output - Root Mean Square Error value between two files

	void calcRMSE(); // Calculates the RMSE between the two data holder arrays

public:
	DEMData_Reader(); // Default CTOR

	void getFileData(); // Gets the filenames from the user, and calls holder methods to store file data
	void analyzeData(); // Analyzes both data holder's contents
	void tableOutput(); // Outputs both data holder's tables
};

#endif