/*
Jensen_A4.cpp
10/26/13
Bryan Jensen

This file contains three classes useful for finding the convex hull of a given set of points, and all the functionality
needed for that operation.

Description: This file contains the Point, Line and ConvexHull classes, the latter of which implements the first
			 two in finding the convex hull of a given set of points, read in from a file. Each class has the 
			 necessary functionality for its own behavior as well as extra behavior necessary for finding a convex
			 hull.

			Point:
			Methods:
			 	getX(): A getter for the private data member "x".
			 	getY(): A getter for the private data member "y".
			 	operator==(): An overloaded operator for comparison of the equality of two points. Returns true
			 				  if both points have the same x values and the same y values.
		 	Friend Functions:
		 		operator<<(): An overloaded friend function allowing for stdio output of the given point.

			Line:
			Methods:
			 	testPoint(): A method to test a given point, returning the relative location of the point
			 				 to the line (left, right or on the line) in integer-form.
		 	Friend Functions:
		 		operator<<(): An overloaded friend function allowing for stdio output of the given line.

			ConvexHull:
			Methods:
			 	testPoint(): A method to test a given point, returning the relative location of the point
			 				 to the line (left, right or on the line) in integer-form.
		 	Friend Functions:
		 		operator<<(): An overloaded friend function allowing for stdio output of the given line.


Input:      Two filenames representing two DEM data files of the correct format (no error checking done)
					at this stage.

Output:     Various timing statistics for sorting algorithms as well as the relevant information for each
			dataset's table, including the highest elevation, the lowest, the mean and the median. 


*/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <iomanip>

using namespace std;

// 
static const float INFINITY = (1 / 0.0);

class Analyzer {
protected:
	long basicOpCounter;
public:
	Analyzer() { this->basicOpCounter = 0; };

	long getOps() { return this->basicOpCounter; };
};

class Point {
private:
	// ------ Private Data Members
	short x, y; // x and y position of the point in 2D cartesian coordinate system
public:
	// ------ Class Constructors / Destructors
	Point() {}; // Default CTOR
	Point(short newX, short newY) { this->x = newX; this->y = newY; }; // Parameterized CTOR

	// ------ Class Getters
	short getX() const { return this->x; }; // Getter for "x"
	short getY() const { return this->y; }; // Getter for "y"

	// ------ Class Methods
	bool operator==(const Point& other) const { return ((this->x == other.x) and (this->y == other.y)); };
											// Equality operator

	// ------ Friend Functions
	friend ostream& operator<<(ostream&, const Point&); // Stdio output operator
};

// Sorting comparison function for use by sort() (from algorithm)
// Provides functionality for sorts by x-value, with priority for lower y-values in the case of a tie
bool pointSortByX(Point p1, Point p2) {
	if (p1.getX() == p2.getX()) { // If the points are on the same veritcal line, sort by lowest y first
		return p1.getY() < p2.getY();
	}
	else {
		return p1.getX() < p2.getX();
	}
}

// Function to test if a certain Point is already in a Point vector
// Returns a boolean based on presence, which is in turn based on the equality operator
bool pointNotInVector(Point point, vector<Point> vect) {
	bool present = false;
	for (vector<Point>::iterator it = vect.begin(); it < vect.end(); it++) {
		if (*it == point) {
			present = true;
		}
	}
	return !present;
}

// Friend function for stdio output of a Point
ostream& operator<<(ostream& co, const Point& point) {
	co << "(" << point.getX() << ", " << point.getY() << ")";
	return co;
}

class Line {
private:
	// ------ Private Data Members
	float slope, yintercept, xintercept; // slope, yintercept and x intercept of the line in a 
										 // 2D cartesian coordinate plane
	short type; // Type of line, for special case handling (i.e. a vertical line has slope = INFINITY)
public:
	// ------ Class Constants
	static const short NORMAL = 0; // Typical line with slope and dual-intercepts
	static const short VERTICAL = 1; // Line with only x-intercept, slope of infinity
	static const short HORIZONTAL = 2; // Line with only y-intercept, slope of 0

	static const short LEFT = 10; // Point is to the left of the line (as envisioned by
								  // looking "down" the path of the line)
	static const short RIGHT = 11; // Point is to the right of the line
	static const short ON_LINE = 12; // Point is on the line

	// ------ Class Constructors / Destructors
	Line() {}; // Default CTOR
	Line(const Point&, const Point&); // Parameterized CTOR

	// ------ Class Methods
	short testPoint(const Point&); // Tests relative location of point

	// ------ Friend Functions
	friend ostream& operator<<(ostream&, const Line&); // Stdio output
};

// Constructs a line from two points, which includes the slope, x- and yintercepts and the type of the line
// (for special case handling)
Line::Line(const Point& point1, const Point& point2) {
	if (point1.getX() == point2.getX()) { // A line between two points with the same X
		this->type = Line::VERTICAL;
		this->slope = INFINITY;
		this->yintercept = INFINITY;
		this->xintercept = point1.getX();
	}
	else if (point1.getY() == point2.getY()) { // A line between two points with the same Y
		this->type = Line::HORIZONTAL;
		this->slope = 0;
		this->yintercept = point1.getY();
		this->xintercept = INFINITY;
	}
	else { // A normal line
		this->type = Line::NORMAL;
		this->slope = (float)(point2.getY() - point1.getY()) / (float)(point2.getX() - point1.getX());
		this->yintercept = point1.getY() - (this->slope * point1.getX());
		this->xintercept = point1.getX();
	}
}

// Tests to see where the point is relative to the line. Does this by pluggin the value into
// the line-equation form ax + by + c = 0, which can be derived from the y = mx + b slope-intercept
// form by equating m to a, b to c and -1 to b. The result is used to determine the return value,
// represented by an integer corresponding to a class constant.
short Line::testPoint(const Point& point) {
	float equationResult;
	short sideOfLine;

	if (this->type == Line::VERTICAL) {
		if (point.getX() < this->xintercept) {
			sideOfLine = Line::LEFT;
		}
		else if (point.getX() > this->xintercept) {
			sideOfLine = Line::RIGHT;
		}
		else {
			sideOfLine = Line::ON_LINE;
		}
	}
	else if (this->type == Line::NORMAL or this->type == Line::HORIZONTAL) {
		equationResult = this->slope * point.getX() - point.getY() + this->yintercept;

		if (equationResult < 0) {
			sideOfLine = Line::LEFT;
		}
		else if (equationResult > 0) {
			sideOfLine = Line::RIGHT;
		}
		else {
			sideOfLine = Line::ON_LINE;
		}
	}

	return sideOfLine;
}

// Friend function to allow for stdio output of a line
ostream& operator<<(ostream& co, const Line& line) {
	co << line.slope << " * x + " << line.yintercept << " = y";
}

class ConvexHull : public Analyzer {
private:
	// ------ Private Data Members
	Point* pointArray; // Array of points in point-cloud
	vector<Point> hullPoints; // Vector of all the points comprising the hull of the point-cloud
	long numPoints; // Number of points in the point-cloud

	// ------ Private Methods
	void sortHull(); // Sorts the hull in clockwise order
public:
	// ------ Class Constructors / Destructors
	ConvexHull() {}; // Default CTOR
	~ConvexHull() { delete[] pointArray; }; // DTOR

	// ------ Class Getters
	long getNumPoints() { return this->numPoints; }; // Getter for "numPoints"

	// ------ Class Methods
	void readFromFile(string); // Read the point-cloud data from a file given by filename
	void generateHull(); // Generates the hull from the point-cloud
	void displayHull(); // Displays the generated hull
};

// Reads the point-cloud data in from the file represented by filename, and stores it in the pointArray data member
void ConvexHull::readFromFile(string filename) {
	cout << "Starting data read from " << filename << "... ";

	ifstream inFile;
	long numElements;
	short x, y;

	inFile.open(filename.c_str());

	if (inFile.fail()) {
		cout << "Failed to open file (likely that file " << filename << " doesn't exist) ";
	}
	else {
		inFile >> numElements;
		this->numPoints = numElements;
		this->pointArray = new Point[numElements];

		for (long i = 0; i < numElements; i++) {
			inFile >> x >> y;
			this->pointArray[i]	= Point(x, y);		
		}
	}
	inFile.close();
	cout << "Done." << endl;
}

// Sorts the hull in clockwise order, given by algorithm below (called by generateHull())
void ConvexHull::sortHull() {
	// Clock-wise sorting of the hull consists of:
	// 1. Left-most point
	// 2. Upper hull, in order by x value
	// 3. Right-most point
	// 4. Lower hull, in reverse order by x value

	vector<Point>& hull = this->hullPoints; // Create refernce variable for clarity and brevity
	sort(hull.begin(), hull.end(), pointSortByX); // Sort the hull points by their x-values
	Line dividingLine(hull.front(), hull.back()); // Line that defines "upper" and "lower"

	vector<Point> upperHalf; // Going to be constructed in clockwise order
	vector<Point> lowerHalf; // Going to be constructed in counter-clockwise order

	// Push the points in ascending x order onto hull halves
	for (vector<Point>::iterator it = hull.begin() + 1; it != hull.end() - 1; it++) {
		if (dividingLine.testPoint(*it) == Line::RIGHT) {
			lowerHalf.push_back(*it);
		}
		else {
			upperHalf.push_back(*it);
		}
	}

	// Create the final hull
	long i = 0;
	hull[i++] = hull.front(); // First (left-most) point
	for (vector<Point>::iterator it = upperHalf.begin(); it != upperHalf.end(); it++) {
		hull[i++] = *it;
	}
	hull[i++] = hull.back(); // Last (right-most) point
	for (vector<Point>::iterator it = lowerHalf.end()-1; it != lowerHalf.begin()-1; it--) { // note: backwards
		hull[i++] = *it;
	}
}

// Generates the convex hull for the stored point-cloud. Uses a brute-force method to compare every pair of points to
// determine if the connecting line is part of the convex hull by testing every other point in the point-cloud.
void ConvexHull::generateHull() {
	bool firstRun; // For checking if the point is the first one tested 
	bool pointsOnHull; // For checking if the two points (aka a line) are on the hull
	short sideOfLine, oldSideOfLine; // Keeps track of which side of the line all points are supposed to be on
									 // -> if they aren't all on one side, then not in the convex hull
	Point point1, point2, point3; // First two make up line, third is being tested against that line
	vector<Point>& hull = this->hullPoints; // Reference copy of hullPoints, for clarity and brevity

	for (long i = 0; i < this->numPoints; i++) { // Iterate over all points
		point1 = this->pointArray[i];

		for (long j = 0; j < this->numPoints; j++) { // Iterate over all points again, create line
			point2 = this->pointArray[j];
			if (point1 == point2) {
				continue; // Can't create a line between two of the same point
			}

			Line line(point1, point2);

			pointsOnHull = true;
			firstRun = true;
			for (long k = 0; k < this->numPoints and pointsOnHull; k++) { // Iterate over all points again, test line
				point3 = this->pointArray[k];
				if (point1 == point3 or point2 == point3) {
					continue; // Don't need to compare a line against a point that made that line
				}

				sideOfLine = line.testPoint(point3); // Right, left or on the line
				this->basicOpCounter++;
				// printf("Using line from (%i, %i) and (%i, %i), testing (%i, %i): %s\n",
						// point1.getX(), point1.getY(), point2.getX(), point2.getY(), point3.getX(), point3.getY(), sideOfLine.c_str());
				
				if (firstRun) { // If it's the first run, just store into variable what the side SHOULD be
					oldSideOfLine = sideOfLine;
					firstRun = false;
				}
				else if (sideOfLine != oldSideOfLine) { // If the side isn't what it SHOULD be, stop
					pointsOnHull = false;
				}
			}

			if (pointsOnHull) { // If all point3's were on the same side -> 1 and 2 were convex hull points
				if (pointNotInVector(point1, hull)) {
					hull.push_back(point1);
				}
				if (pointNotInVector(point2, hull)) {
					hull.push_back(point2);
				}
			}
		}
	}

	this->sortHull();
}

// Outputs the hull to the stdio (aka console/terminal)
void ConvexHull::displayHull() {
	cout << "This convex hull is made up of: " << endl;
	for (vector<Point>::iterator it = this->hullPoints.begin(); it < this->hullPoints.end(); it++) {
		cout << *it << endl;
	}
	cout << endl;
}

int main() {
	string filename;
	ostringstream converter;

	// for (short i = 1; i <= 50; i++) {
	// 	ConvexHull ch;

	// 	converter << "tst" << i;
	// 	filename = converter.str();
	// 	converter.str(""); // Clear

	// 	ch.readFromFile(filename);
	// 	ch.generateHull();
	// 	// ch.displayHull();
	// 	cout << "N ops:           " << setw(10) << ch.getOps() << endl;
	// 	cout << "Ratio to O(n^3): " << setw(10) << ((float)ch.getOps()/(float)(ch.getNumPoints() * ch.getNumPoints() * ch.getNumPoints())) << endl;
	// }

	cout << "Input a filename: ";
	cin >> filename;

	ConvexHull ch;

	ch.readFromFile(filename.c_str());
	ch.generateHull();
	ch.displayHull();
}