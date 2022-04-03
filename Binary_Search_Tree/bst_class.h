#include "bst_node.h"
#include <cstddef>

class BST {
private:
    BSTNode *root;

    void printAux(BSTNode *node);
    void eraseTreeNodes(BSTNode *node);

public:
    BST() { root = NULL; }
    ~BST() { eraseTreeNodes(root); }
    void Add(int key);
    void Remove(int key);
    bool Find(int key);
    int Min();
    int Max();
    void Print();
};