#include "AVLtrees.h"
#include <iostream>

// test for A5 Fall 2013

using namespace std;

int main () {
   binarySearchTree tree;

   cout << "Showing easiest tree\n";
   tree.insertItem('5');
   tree.insertItem('3');
   cout << "Inorder traversal (3 5):" << endl;
   tree.inorderTraversal();
   cout << endl;

   cout << "Adding up to 7 in random order\n";
   tree.insertItem('7');
   tree.insertItem('2');
   tree.insertItem('4');
   tree.insertItem('1');
   tree.insertItem('6');

   cout << "Inorder traversal (1 2 3 4 5 6 7):" << endl;
   tree.inorderTraversal();
   cout << endl << "Tree height (3):"<< endl;
   cout << tree.treeHeight() << endl;

   cout << endl;

   binarySearchTree tree2;
   tree2.insertItem ('e');
   tree2.insertItem ('a');
   tree2.insertItem ('h');

   cout << "Now showing display() with two levels: " << endl;
   tree2.treeDisplay();
   cout << endl;
   cout << "Tree height (1):"<< endl;
   cout << tree2.treeHeight() << endl;
   cout << endl;
   cout << "Press return..." << endl;
   cin.get();

   cout << "Adding more values to tree (d, f, j)" << endl;
   tree2.insertItem ('d');
   tree2.insertItem ('f');
   tree2.insertItem ('j');

   cout << "Tree height (2):"<< endl;
   cout << tree2.treeHeight() << endl;

   cout << "Now showing display() with three levels: " << endl;
   tree2.treeDisplay();
   cout << endl << "Press return..." << endl;
   cin.get();

   cout << "Inorder traversal (a d e f h j):" << endl;
   tree2.inorderTraversal ();
   cout << endl << "Press return..." << endl;
   cin.get();

   tree2.insertItem ('b');
   tree2.insertItem ('c');
   cout << "Now showing display() with four levels: " << endl;
   tree2.treeDisplay();
   cout << endl << "Press return..." << endl;
   cin.get();

   cout << "Now making new tree s.t. single rotation is needed" << endl;
   balancedBST single;
   single.insertItem ('a');
   single.insertItem ('b');
   cout << "Inorder traversal (a b c):" << endl;
   single.inorderTraversal ();
   cout << endl << "Press return..." << endl;
   cin.get();
   cout << "Balance factors: " << endl;
   single.balanceFactors();
   cout << endl;
   single.insertItem ('c');
   cout << "After adding 'c', tree display s.t. it's rotated correctly: " << endl;
   single.treeDisplay();
   cout << endl;

   single.insertItem ('e');
   single.insertItem ('f');
   cout << "After adding 'e' and 'f', tree display s.t. it's doubly rotated correctly: " << endl;
   single.treeDisplay();
   single.balanceFactors();
   cout << endl;
   
   single.insertItem ('g');
   cout << "After adding 'g', tree display s.t. it's rotated correctly: " << endl;
   single.treeDisplay();
   cout << "Tree height (2):"<< endl;
   cout << single.treeHeight() << endl;
   
   cout << "DONE" << endl;

   return 0;
}

