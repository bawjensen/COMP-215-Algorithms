#include <iostream>

using namespace std;

const int MAX = 20;

// Display the array of integers
void display (int array[])
{
	int i;
	 
	for (i = 0; i < MAX; i++)
		cout << array [i] << "  ";
	cout << endl;
}

// Interchange the values of two given arguments
void Swap (int &one, int &two)
{
	int temp;
	temp = one;
	one = two;
	two = temp;
}

// Quicksort: sort first N items in array A
static const int Cutoff = 1;

void QuickSort( int A[], int Low, int High ) { // low/high are indexes
	if( Low + Cutoff > High )
		// ShellSort (&A [Low], High - Low + 1);					// line A
	;
	else {
		// Place pivot at Position High
		// this is done because it's easier to deal with a contiguous array
		int Pivot;
		int PivotPos;
		int MidPos = (Low + High) / 2;

		if (A[MidPos] >= A[High] && A[MidPos] <= A[Low]) {
			Pivot = A[MidPos];
			PivotPos = MidPos;
		}
		else if (A[High] >= A[Low] && A[High] <= A[MidPos]) {
			Pivot = A[High];
			PivotPos = High;
		}
		else if (A[Low] >= A[High] && A[Low] <= A[MidPos]) {
			Pivot = A[Low];
			PivotPos = Low;
		}

		// int Pivot = A[ Low ];
		cout << "Dealing with " << Low << " to " << High << endl;
		display(A);
		cout << "Took pivot out: " << endl;
		Swap( A[ Low ], A[ High ] );
		display(A);

		// Begin partitioning
		int i, j;
		for( i = Low - 1, j = High ; ; ) {
			while( A[ ++i ] < Pivot );   // note not <= (see below)
			cout << "Next above Pivot element to the left: " << A[i] << endl;

			while( A[ --j ] > Pivot );   // note not <=
			cout << "Next below Pivot element to the right: " << A[j] << endl;

			if( i < j ) {
				cout << "swapping " << A[i] << " with " << A[j] << endl;
				Swap( A[ i ], A[ j ] );
				display(A);
			}
			else
				break;
		}

		// Restore pivot
		// stick pivot back to position where it really belongs
		cout << "swapping " << A[i] << " with " << A[j] << " back into place" << endl;
		Swap( A[ i ], A[ High ] );
		display(A);
		cout << "^ List should be split correctly around " << Pivot << endl;

		QuickSort( A, Low, i - 1 );   // Sort small elements
		QuickSort( A, i + 1, High );  // Sort large elements
	}
}


int main () {
	// int myList [MAX] = {4, 7, 1, 2, 8, 5, 3, 6};
	int myList [MAX];
	int i;

	for (i = 0; i < MAX; i++) myList[i] = MAX-i;

	cout << "Unsorted list:" << endl;
	display (myList);
	QuickSort (myList, 0, MAX-1);
	cout << "Sorted list:" << endl;
	display (myList);

	return 0;
}