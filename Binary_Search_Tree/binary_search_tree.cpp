/*
    A Binary Search Tree (BST) is a binary tree in which the value in every node is:
    greater than all values in the node's left subtree, and
    smaller than all values in the node's right subtree.

    The keys in binary search tree must be unique.
*/

#include <iostream>
#include "bst_class.h"
#include "bst_node.h"
#include <stdio.h>
using namespace std;

int main(){
	try {
//		BST1 bst;
		BST bst;

		bst.Add(75); cout << "Adding 75" << endl;
		bst.Add(14); cout << "Adding 14" << endl;
		bst.Add(10); cout << "Adding 10" << endl;
		bst.Add(108); cout << "Adding 108" << endl;
		bst.Add(77); cout << "Adding 77" << endl;
		bst.Add(76); cout << "Adding 76" << endl;
		bst.Add(97); cout << "Adding 97" << endl;
		bst.Add(280); cout << "Adding 280" << endl;
		bst.Add(100); cout << "Adding 100" << endl;
		bst.Print();

		cout << "------------------------------\n";
		cout << "min key: " << bst.Min() << endl;
		cout << "max key: " << bst.Max() << endl;
		cout << "Does 77 exist? " << (bst.Find(77) ? "Yes" : "No") << endl;
		cout << "Does 15 exist? " << (bst.Find(15) ? "Yes" : "No") << endl;

		cout << "------------------------------\n";
		cout << "Removing 108" << endl;
		bst.Remove(108);
		bst.Print();
		cout << "------------------------------\n";

		cout << "Removing 14" << endl;
		bst.Remove(14);
		bst.Print();
		cout << "------------------------------\n";

		cout << "Removing 10" << endl;
		bst.Remove(10);
		bst.Print();
		cout << "------------------------------\n";

		cout << "Removing 75" << endl;
		bst.Remove(75);
		bst.Print();
		cout << "------------------------------\n";

		cout << "Removing 33" << endl;
		bst.Remove(33);
		bst.Print();
		cout << "------------------------------\n";

		cout << "Removing 97" << endl;
		bst.Remove(97);
		bst.Print();
		cout << "------------------------------\n";

		cout << "Removing 100" << endl;
		bst.Remove(100);
		bst.Print();
		cout << "------------------------------\n";

		cout << "Removing 77" << endl;
		bst.Remove(77);
		bst.Print();
		cout << "------------------------------\n";

		cout << "Removing 76" << endl;
		bst.Remove(76);
		bst.Print();
		cout << "------------------------------\n";

		cout << "Removing 280" << endl;
		bst.Remove(280);
		bst.Print();
		cout << "------------------------------\n";
	}
	catch (std::exception& e) {
		cout << "Exception occurred: " << e.what() << endl;
	} //end-catch

	return 0;
} //end-main



