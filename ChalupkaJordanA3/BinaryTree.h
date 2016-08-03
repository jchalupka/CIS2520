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
	void *(*destroyFunction) (void *tree);
} BinTree;

#include "printTree.h"
#include "destroyFunctions.h"
#include "avl.h"

int compareStrings (void *d1, void *d2);


BinTree * createBinTree (int (*compareFunction) (void *d1, void *d2), void *(*destroyBinTree) (void *tree));


void insert (BinNode ** root, BinNode *rootToAdd, int (*compareFunction) (void *d1, void *d2));


int getHeight (BinNode * tree);


void insertBinTree (BinTree *tree, void *data);


void printNode (BinNode *node);


void printTree (BinNode * root);


int max ( int a, int b );


BinNode* search (BinNode * node, void * data, int (*compareFunction) (void *d1, void *d2));


BinNode* searchTree (BinTree * tree, void * data);


BinNode* getLeftSubtree(BinNode *tree);


BinNode* getRightSubtree(BinNode *tree);

#endif
