#ifndef __JCHALUPKA_BINARYTREE__
#define __JCHALUPKA_BINARYTREE__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct BinaryTreeNode {
	struct BinaryTreeNode *left, *right;
	void *data;
} BinNode;

typedef struct BinaryTree {
	BinNode * root;
	int (*compareFunction) (void *d1, void *d2);
	void (*destroyFunction) (void *toDestroy);
} BinTree;

#include "printTree.h"

// User wrapper functions
BinTree* createBinTree (int (*compareFunction) (void *d1, void *d2), void (*destroyFunction) (void *toDestroy));
BinTree* destroyBinTree (BinTree *toDestroy);
void insertBinTree (BinTree *tree, void *data);
BinNode* removeBinNode (BinNode *tree);
BinNode* getLeftSubtree(BinNode *tree);
BinNode* getRightSubtree(BinNode *tree);
void printTree (BinNode * root);

// Internal helper functions
void insert (BinNode **root, BinNode *rootToAdd, int (*compareFunction) (void *d1, void *d2));
void delete (BinTree *root, void *data);
int isEmpty (BinTree *root);

int compareStrings (void *d1, void *d2);
void destroyStub (void *toDestroy);
BinNode* searchTree (BinTree * tree, void * data);
BinNode* search (BinNode * node, void * data, int (*compareFunction) (void *d1, void *d2));
// isFull



#endif