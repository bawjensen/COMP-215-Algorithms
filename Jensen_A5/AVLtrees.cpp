/* AVLtrees.cpp
 * 
 * Program implements a binary tree base class and a binary search tree
 * derived class. 
 *
 */


#include "AVLtrees.h"

/*********************************************************************/
/************************* binary  tree ******************************/
/********************** method definitions ***************************/

int binaryTree::nodecount(nodeType* p) const {
	// Counts the number of nodes in the subtree rooted at p.
	// Precondition: None
	// Postcondition: Number of nodes in subtree returned to caller
	if (p) {
		return 1 + nodecount(p->left) + nodecount(p->right);
	} 
	else {
		return 0;
	}
}


/*********************************************************************/

int binaryTree::height(nodeType* p) const {
	// Calculates the height of the subtree rooted at p.
	// Precondition: None
	// Postcondition: The height of the subtree is returned to the caller
	if (p) {
		return 1 + max( height(p->left), height(p->right) );
	} 
	else {
		return -1;
	}
}


/*********************************************************************/

void binaryTree::display(nodeType* p) const {
	// Graphically (and non-recursively) displays the binary tree with formatting and spacing
	// Precondition: operator<< must be overloaded for the type of data stored by the tree
	// Postcondition: Tree contents are output to stdio (console) with formatting and spacing
	// s.t. the output looks like a tree graph
	if (p == NULL) {
		cout << "EMPTY TREE" << endl; // Message for a null root
		return;
	}

	int totalHeight = height(p);
	int depth = 0;
	int displayWidth = pow( 2, height(root)+1 );
	int offsetShift = displayWidth / 2;

	// cout << "Displaying tree of height " << totalHeight << " which gives a width of " << displayWidth << endl;

	nodeType** currentLayer = NULL; // An array of node pointers to store the current layer of the tree (BFS searching)
	nodeType** tempLayer = NULL; // A temp array to store node pointers
	int layerWidth = 1; // Number of nodes in a layer (root's layer just has 1)

	// Initialize first layer
	currentLayer = new nodeType*[layerWidth];
	currentLayer[0] = p; // Start first layer with root

	// Print first layer
	cout << setw(displayWidth - offsetShift) << currentLayer[0]->data << endl;

	// Loop while not at the bottom
	while (depth < totalHeight) {
		if (tempLayer) { // Prevent memory leaks
			delete[] tempLayer;
		}

		// Create next layer: 
		layerWidth = pow( 2, depth+1 ); // root is 1 node, next is 2, then 4, etc.
		tempLayer = new nodeType*[layerWidth]; // The layer of nodes for nice printing

		for (int i = 0; i < layerWidth; i += 2) { // Create this layer from the last layer
			if (currentLayer[i/2] != NULL) {
				tempLayer[i]   = currentLayer[i/2]->left;
				tempLayer[i+1] = currentLayer[i/2]->right;
			}
			else {
				tempLayer[i]   = NULL;
				tempLayer[i+1] = NULL;
			}
		}

		delete[] currentLayer; // Free memory
		currentLayer = new nodeType*[layerWidth]; // Copy temp into current
		for (int i = 0; i < layerWidth; i++) {
			currentLayer[i] = tempLayer[i];
		}

		displayWidth /= 2; // Decrement the width
		offsetShift /= 2; // Decrement the offset

		cout << setw(displayWidth - offsetShift); // Initial piece is set at the width but shifted over
		for (int i = 0; i < layerWidth; i++) {
			if (currentLayer[i] != NULL) {
				cout << currentLayer[i]->data << setw(displayWidth); // Print out the piece and then the following spacing
			}
			else {
				cout << " " << setw(displayWidth); // Print out a blank space and the following spacing
			}
		}
		cout << endl;

		depth++; // Go down another layer
	}
}


/*********************************************************************/


void binaryTree::postorder(nodeType* p) const {
	// Traverses the subtree rooted at p and prints out the node contents in a postorder fashion
	// (first the left subtree, then the right subtree, then print the node)
	// Precondition: operator<< must be overloaded for the type of data stored by the tree
	// Postcondition: The contents of the tree have been output to stdio (the console) in postorder
	if (p) {
		postorder(p->left);
		postorder(p->right);
		cout << p->data << " ";
	}
}


/*********************************************************************/


void binaryTree::inorder(nodeType* p) const {
	// Traverses the subtree rooted at p and prints out the node contents in an inorder fashion
	// (first the left subtree, then print the node, then the right subtree)
	// Precondition: operator<< must be overloaded for the type of data stored by the tree
	// Postcondition: The contents of the tree have been output to stdio (the console) in inorder
	if (p) {
		inorder(p->left);
		cout << p->data << " ";
		inorder(p->right);
	}
}


/*********************************************************************/


void binaryTree::preorder(nodeType* p) const {
	// Traverses the subtree rooted at p and prints out the node contents in a preorder fashion
	// (first print the node, then the left subtree, then the right subtree)
	// Precondition: operator<< must be overloaded for the type of data stored by the tree
	// Postcondition: The contents of the tree have been output to stdio (the console) in preorder
	if (p) {
		cout << p->data << " ";
		preorder(p->left);
		preorder(p->right);
	}
}


/*********************************************************************/
/************************ binary search tree *************************/
/************************ method definitions *************************/


void binarySearchTree::insert(elemType item, nodeType*& p) {
	// Insert the item into the subtree in its correct location, creating a new node for the item
	// at the correct position. Prints an error message if the item is already present in the BST.
	// Precondition: None
	// Postcondition: The item has been stored as the data of a new node in the correct position
	// 				  in the subtree.
	if (p) {
		if (item < p->data) {
			insert(item, p->left);
		}
		else if (item > p->data) {
			insert(item, p->right);
		}
		else {
			cout << "Error: Item already in tree" << endl;
			return;
		}
	}
	else {
		p = new nodeType;
		p->data = item;
		p->left = NULL;
		p->right = NULL;
	}
}


/*********************************************************************/


bool binarySearchTree::search(const elemType key, const nodeType* p) const {
	// Searches for a key in the binary search tree, and returns whether the item has been found.
	// Precondition: None
	// Postcondition: Returns true if the key is present in the tree, false otherwise.
	bool leftside, rightside;

	if (p) { // != NULL
		if (p->data == key)
			return true;
		else {
			leftside = search(key, p->left);
			rightside = search(key, p->right);
			return (leftside || rightside);
  		}
	} 
	else {
		return false;
	}
}


/*********************************************************************/
/******************* balanced binary search tree *********************/
/************************ helpful functions **************************/


bool isUnbalanced(nodeType* p) {
	// Simple function to take a node and return true if the node is unbalanced according to AVL-tree
	// balancing rules, false otherwise.
	// Precondition: p must be point to a valid node.
	// Postcondition: Returns true if the balance factor is anything other than 0, -1 or 1. Returns false if it is.
	return (p->balanceFactor < -1 || p->balanceFactor > 1);
}


/*********************************************************************/


int balancedBST::calcBalanceFactor(nodeType* p) const {
	// Computes the balance factor for a certain node and returns that value.
	// Precondition: None
	// Postcondition: Returns the value of the balance factor for p if it is not NULL, 0 otherwise
	if (p) return (height(p->left) - height(p->right));
	else return 0;
}


/*********************************************************************/
/********************** method definitions ***************************/


void balancedBST::rotateLeft(nodeType*& p) {
	// Performs a left rotation on a subtree to balance it.
	// Precondition: p is the root of a subtree which is unbalanced to the right, and which
	//				 has a right node and a right node on the right node.
	// Postcondition: The subtree has been balanced so that the right node is the new root
	//				  and the old root is to the right.

	// Creating references for sake of clarity (aka: renaming the variables)
	nodeType*& node1 = p;
	nodeType*& node2 = p->right;
	// nodeType*& node3 = p->right->right; Extra - Left in for sake of clarity

	// nodeType* subtreeA = node1->left; Extra - Left in for sake of clarity
	nodeType* subtreeB = node2->left;
	// nodeType* subtreeC = node3->left; Extra - Left in for sake of clarity
	// nodeType* subtreeD = node3->right; Extra - Left in for sake of clarity

	node2->left = node1; // Shift node down to be left of soon-to-be-replacement
	node1 = node2; // Replace node with rotated-up one (used to be the right)
	node1->left->right = subtreeB; // Reinsert subtreeB where it belongs (was overwritten before)
	node1->left->balanceFactor = calcBalanceFactor(node1->left); // Recalculate balance factor
}


/*********************************************************************/


void balancedBST::rotateRight(nodeType*& p) {
	// Performs a right rotation on a subtree to balance it.
	// Precondition: p is the root of a subtree which is unbalanced to the left, and which
	//				 has a left node and a left node on the left node.
	// Postcondition: The subtree has been balanced so that the left node is the new root
	//				  and the old root is to the left.

	// Creating references for sake of clarity (aka renaming the variables)
	nodeType*& node1 = p;
	nodeType*& node2 = p->left;
	// nodeType*& node3 = p->left->left; Extra - Left in for sake of clarity

	// nodeType* subtreeA = node3->left; Extra - Left in for sake of clarity
	// nodeType* subtreeB = node3->right; Extra - Left in for sake of clarity
	nodeType* subtreeC = node2->right;
	// nodeType* subtreeD = node1->right; Extra - Left in for sake of clarity

	node2->right = node1; // Shift node down to be right of soon-to-be-replacement
	node1 = node2; // Replace node with rotated-up one (used to be the left)
	node1->right->left = subtreeC; // Reinsert subtreeC where it belongs (was overwritten before)
	node1->right->balanceFactor = calcBalanceFactor(node1->right); // Recalculate balance factor
}


/*********************************************************************/


void balancedBST::rotateSubtree(nodeType*& p) {
	// Performs a rotation on the subtree based on which side of the node is unbalanced.
	// Precondition: p is the root of a subtree which is unbalanced, and has valid left and right node pointers.
	// Postcondition: The subtree has been balanced according to which sides were unbalanced, optionally performing
	//				  double rotations.

	if (p->balanceFactor > 1) { // Unbalanced: heavy on the left
		if (p->left->balanceFactor < 0) { // heavy on left -> right
			rotateLeft(p->left);
		}
		rotateRight(p);
	}
	else { // Unbalanced: heavy on right
		if (p->right->balanceFactor > 0) { // heavy on right -> left
			rotateRight(p->right);
		}
		rotateLeft(p);
	}
}


/*********************************************************************/


void balancedBST::insert(const elemType item, nodeType*& p) {
	// Insert an item into the balanced binary search tree, calculate the balance factors for the tree
	// and if unbalanced, performs the correct rotation.
	// Precondition: None
	// Postcondition: The item has been inserted into the tree, and the tree is still balanced according to
	// 				  AVL-tree balancing rules.
	if (p) {
		if (item < p->data) {
			insert(item, p->left);
		}
		else if (item > p->data) {
			insert(item, p->right);
		}
		else {
			cout << "Error: Item already in tree" << endl;
		}
	}
	else {
		p = new nodeType;
		p->data = item;
		p->left = NULL;
		p->right = NULL;
	}

	p->balanceFactor = calcBalanceFactor(p);

	if (p) {
		if (isUnbalanced(p)) {
			rotateSubtree(p);
		}

		p->balanceFactor = calcBalanceFactor(p);
	}
}


/*********************************************************************/


void balancedBST::bFactors(const nodeType* p) const {
	// Print out the balance factors of the subtree following the preorder traversal rules.
	// Precondition: p is the root of a subtree.
	// Postcondition: The subtree has been output to stdio (the console) along with the corresponding balance factors.
	if (p) {
		cout << p->data << ": " << p->balanceFactor << " ";
		bFactors(p->left);
		bFactors(p->right);
	}
}


/*********************************************************************/
