#include "bst_class.h"
#include <iostream>
using namespace std;

///-----------------------------------------------
/// Erases all nodes in the tree
/// 
void BST::eraseTreeNodes(BSTNode* node) {
	if (node == NULL) return;
	eraseTreeNodes(root->left);
	eraseTreeNodes(root->right);
	delete root;
	root = NULL;
} //end-eraseTreeNodes

#if 0
void BST::Add(int key) {
    
    BSTNode *pp = NULL;         // pp is the parent of p
    BSTNode *p = root;          // start at the root and go down

    while (p != NULL) {
        pp = p;

        if (key == p->key)  return;     // Already exist
        else if (key < p->) p = p->left;
        else p = p->right;
    }

    BSTNode *node = new BSTNode(key);       // New node to store the key

    if (root == NULL)       root = node;
    else if (key < pp->key) pp->left = node;
    else                    pp->right = node;

}

#else

void BST::Add(int key) {

    // This is the improved BST insert operation based on Linus Torvalds's indirect pointer approach
    BSTNode **indirect = &root;

    while (*indirect != NULL)
    {
        if ((*indirect)->key == key)    return;
        else if (key < (*indirect)->key)    indirect = &(*indirect)->left;
        else                                indirect = &(*indirect)->right;
    }
    
    // Insert the new node at the correct place: No special cases
    // Handles all cases: Empty tree, left sub-tree insert and right sub-tree insert
    *indirect = new BSTNode(key);
}

#endif

#if 0
void BST::Remove(int key) {
    // This is the classical implementation of the remove code
    BSTNode *pp = NULL;
    BSTNode *p = root;

    while(p != NULL && p->key != key) {
        pp = p;

        if (key < p->key)   p = p->left;
        else                p = p->right;
    }

    if (p == NULL)  return;     // key not found

    // Case 3: The node to be deleted has 2 children
    if (p->left != NULL && p->right != NULL) {

        BSTNode *qp = p;        // pp is the parent of p
        BSTNode *q = p->right;

        // Find minimum of left sub-tree of the node
        while (q->left != NULL) {
            qp = p;
            q = q->left;
        }

        // Copy the minimum key of left sub-tree to the key of the node to be deleted 
        p->key = q->key;
        pp = qp;
        p = q;
    }

    // Special case: tree with a single root node
    if (p == root) {
        root = root->left ? root->left : root->right;
        delete p;
        return;
    }

    // Case 1: The node to be deleted has no children. p is a leaf node
    // Case 2: The node to be deleted has one child. p is an internal node with one child
    if (p == pp->left)  pp->left = p->left != NULL ? p->left : p->right;
    else                pp->right = p->left != NULL ? p->left : p->right;

    delete p;
}

#else

void BST::Remove(int key) {
    // This is the implementation of the remove operation using the 'indirect' pointer approach
    BSTNode **indirect = &root;

    while ((*indirect) != NULL && (*indirect)->key != key)
    {
        if (key < (*indirect)->key) indirect = &(*indirect)->left;
        else                        indirect = &(*indirect)->right;
    }

    if (*indirect == NULL)  return;     // key not found

    // Case 3: The node to be deleted has 2 children
    if ((*indirect)->left != NULL && (*indirect)->right) {
        BSTNode **indirectRST = &(*indirect)->right;

        while((*indirectRST)->left != NULL) {
            indirectRST = &(*indirectRST)->left;
        }

        (*indirect)->key = (*indirectRST)->key;
        indirect = indirectRST;
    }

    BSTNode *tmp = *indirect;

    // Special case: Deleting the root node
    // Case 1: The node to be deleted has no children. It is a leaf node
    // Case 2: The node to be deleted has one child. p is an internal node with one child
    *indirect = (*indirect)->left != NULL ? (*indirect)->left : (*indirect)->right;

    delete tmp;    
}

#endif

//BSTNode BST::Find(int key)
bool BST::Find(int key) {
    BSTNode *p = root;

    while(p != NULL) {
        if (key == p->key) return true;//p;
        else if (key < p->key) p = p->left
        else p = p->right;
    }

    return false;//NULL;
}

///
/// Returns the minimum key in the BST
///
int BST::Min() {
    //if (root == NULL) return NULL;
    if (root == NULL) throw exception("BST::min - Tree is empty")

    BSTNode *p = root;

    while(p->left != NULL) {
        p = p->left;
    }
    return p->key;
}

///
/// Returns the maximum key in the BST
///
int BST::Max() {
    //if (root == NULL) return NULL;
    if (root == NULL) throw exception("BST::max - Tree is empty")

    BSTNode *p = root;

    while(p->right != NULL) {
        p = p->right;
    }
    return p->key;
}

///-----------------------------------------------
/// Prints the keys in BST in sorted order
/// 
void BST::print() {
	printf("BST Keys: ");
	printAux(root);
	printf("\b\b \n");
} // end-print

void BST::printAux(BSTNode* node) {
	if (node == NULL) return;
	printAux(node->left);
	printf("%d, ", node->key);
	printAux(node->right);
} // end-printAux