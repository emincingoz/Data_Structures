#ifndef _BSTNode_
#define _BSTNode_

struct BSTNode
{
    int key;
    BSTNode *left;
    BSTNode *right;

    BSTNode(int key) { 
        this->key = key;
        left = right = NULL;
    }

    //BSTNode(int key) : key(key), left(NULL), right(NULL) {}
};


#endif