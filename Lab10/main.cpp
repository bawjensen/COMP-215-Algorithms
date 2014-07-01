//
//  main.cpp
//  Xcode_Project
//
//  Created by Mark LeBlanc on 10/28/13.
//  Copyright (c) 2013 Mark LeBlanc. All rights reserved.
//

#include "bTree.h"
#include <iostream>

using namespace std;

int main () {

	bTree T;  // make an empty Tree
	
	string newWord;
	cout << "Enter word: ";
	cin >> newWord;

	while (newWord != "STOP")
	{
		// #3 INSERT
		T.InsertItem(newWord);
		
		cout << "Enter word: ";
		cin >> newWord;
		
	} // while more words (not STOP)
	
	
	// cout << endl << "====================" << endl;
	// // #4 IN-ORDER
	// cout << "Inorder traversal: ";
	// T.printInorder( T.GetRoot() );

	// cout << endl << "====================" << endl;
	// // #5 PRE-ORDER and POST-ORDER
	// cout << "Preorder traversal: ";
	// T.printPreorder( T.GetRoot() );
	// T.printPostorder( T.GetRoot() );
	
	// cout << endl << "====================" << endl;
	// // #6 Tree HEIGHT
	// cout << "Tree Height: " << T.treeHeight( T.GetRoot() ) << endl;
	
	// cout << endl << "====================" << endl;
	// // #7 Count LEAVES
	// cout << "Number of Leaves: " << T.leafCount( T.GetRoot() ) << endl;

	// cout << endl << "====================" << endl;
	// // #8 SEARCH for an ITEM
	// string key;
	
	// cout << "Enter word to search for (EXIT to stop): ";
	// cin >> key;
	// while (key != "EXIT")
	// {
	// 	cout << "Search for: " << key << " was ";
	// 	if ( ! T.search4Item( key, T.GetRoot() ) )
	// 		cout << "not ";
	// 	cout << "found." << endl << endl;
		
	// 	cout << "Enter word to search for (EXIT to stop): ";
	// 	cin >> key;
	// } // while not EXIT
	 
	
	
	cout << endl << endl << "Done." << endl;

	
	// #9 bTree::~bTree DTOR
} // main()
