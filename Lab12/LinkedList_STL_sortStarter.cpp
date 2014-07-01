//=============================================================================
// (I) Link List, (II) STL vector and (III) Sort Algorithms


#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <time.h>

using namespace std;


//=============================================================================
// node for linked list
struct node {
	short n;
	struct node* next;
};

//=============================================================================
// makeLinkList -- build and fill link list (of nodes) with N random numbers
//
// [ 1 <=     rand() % MAX + 1     <= MAX ]
//
// RETURN: pointer to HEAD of new link list
//

node* makeLinkList(unsigned long N) {
	
	const short MAX = 4; // random numbers from 1 to MAX
	srand(time(NULL));
	
	// BUFFER NODE (not a real node on the link list)
	node* head = new node;
	head->n = rand() % MAX + 5;
	// head->n = N;
	head->next = new node;
	
	// fill link list with N random numbers from 1 to MAX
	node* iterNode = head;

	for (unsigned long i = 1; i < N; i++) {
		iterNode = iterNode->next;

		iterNode->n = rand() % MAX + 5;
		// iterNode->n = i;
		iterNode->next = new node;
	}
	
	iterNode->next = NULL;
	
	   
	return head;
}

void printLinkList(node* head) {
	cout << "LINK LIST: ";

	node* currentNode = head;
	while(currentNode) {
		cout << currentNode->n << ", ";
		currentNode = currentNode->next;
	}
	
	cout << "END." << endl;
}


// === Part II: Save only EVENs in STL vector
vector<short> keepOnlyEvensInVector(node* head) {
	vector<short> V;
	
	node* iterNode = head;

	while (iterNode) {
		if (iterNode->n % 2 == 0) {
			V.push_back(iterNode->n);
		}

		iterNode = iterNode->next;
	}
	
	return V;
}


//=============================================================================
// PrintVector
//

void PrintVector( vector<short>& V ) {
	unsigned long N = V.size();
	cout << "VECTOR of EVENs: ";

	for (vector<short>::iterator iter = V.begin(); iter != V.end(); iter++) {
		cout << *iter << ", ";
	}	

	
	
	
	cout << "END." << endl;
}

//=============================================================================
// TestSort
//

void TestSort( vector<short>& V ) {

	// (1) 
	// sort( V.begin(), V.end() );
	stable_sort( V.begin(), V.end() );
	

	
	

} // end TestSort


//=============================================================================
// cmp
bool cmp( short a, short b ) {
	return a > b;
}


//=============================================================================
// main

int main() {
	
	time_t start, end;
	double diff;
	
	unsigned long N;
	N = 200000000;  // 200 million (for testing, once it works)
	// N = 10;
	
	// === Part I: Link Lists ===========================================
	node* head;
	head = makeLinkList(N);  // make a link list of N nodes (holding random short ints)
	
	// printLinkList(head);
	
	
	// === Part II: Save only EVENs in STL vector =======================
	vector<short> V;
	 
	V = keepOnlyEvensInVector(head);

	// PrintVector( V );
	
	 
	// === Part III: SORT EVENs in STL vector =======================
	cout << endl << "Start sorting ...";
	start = clock();
	TestSort( V );
	end = clock();
	cout << endl << "Done sorting." << endl << endl;
	
	diff = (end - start) / CLOCKS_PER_SEC;
	
	// cout << "After: " << endl;
	// PrintVector( V );
	
	printf ("\nIt took you %.2lf seconds to sort ~%ld integers.\n", diff, N/2 );
	
	
	return 0;

} // end main