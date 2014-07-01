/* mainWEB.cpp
 * 
 * Sample main() for A5
 *
 */

#include "AVLtrees.h"
#include <fstream>
#include <iostream>

// Silly little main() that lets user type in characters, and store
// them in a binary search tree.
// Tests out various binary (search) tree functions.
int main () {
	balancedBST mytree;
	char newch;

	cout << "Enter char: ";
	cin.get(newch);
	cin.get();
	while (newch != '0') {
		mytree.insertItem(newch);
		mytree.treeDisplay();
		cout << "Enter char: ";
		cin.get(newch);
		cin.get();
	}
	cout << endl;


	// ifstream inFile;
	// string filename = "nodes";

	// inFile.open(filename.c_str());
	// inFile >> newch;

	// while (inFile) {
	// 	cout << "\n\n\nInserting: " << newch << endl;
	// 	mytree.insertItem(newch);
	// 	mytree.treeDisplay();
	// 	inFile >> newch;
	// }

	cout << "Inorder traversal: ";
	mytree.inorderTraversal ();
	cout << endl << "Preorder traversal: ";
	mytree.preorderTraversal ();
	cout << endl << "Postorder traversal: ";
	mytree.postorderTraversal ();
	cout << endl << endl;
	

	
	// cout << "Tree height: " << mytree.treeHeight() << endl;

	cout << "\n\nAll Done Display: " << endl;
	mytree.treeDisplay();
	cout << endl << endl;
	

	
	// cout << "Enter search key: ";
	// cin.get (newch);
	// if (mytree.searchItem(newch))
	// 	cout << newch << " found in tree" << endl;
	// else
	// 	cout << newch << " not found in tree" << endl;

	mytree.balanceFactors();
	cout << endl;
	

	return 0;
}
