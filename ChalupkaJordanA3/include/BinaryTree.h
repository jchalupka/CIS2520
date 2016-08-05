// Jordan Chalupka 0928528
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


/*Compare two strings, using strcmp (see strcmp)
 *Pre: Two strings passed in
 *Post: Integer returned conveying order
*/
int compareStrings (void *d1, void *d2);

/*Create a tree structure
 *Pre:Compare, and destroy are function pointers for the tree
 *Post:Tree is created
*/
BinTree * createBinTree (int (*compareFunction) (void *d1, void *d2), void *(*destroyBinTree) (void *tree));

/*Insert a node into the tree
 *Pre: Information passed in is initialized
 *Post:Node is inserted into tree
*/
void insert (BinNode ** root, BinNode *rootToAdd, int (*compareFunction) (void *d1, void *d2));

/*Get the Max value
 *Pre: None
 *Post: None
*/
int max ( int a, int b );

/*Get the height of a node in the tree
 *Pre: Node is initialized properly
 *Post: Height is returned
*/
int getHeight (BinNode * tree);

/*Insert data into the tree
 *Pre: Tree is initialized
 *Post: Data is inserted into tree, and tree is rotated if necessary
*/
void insertBinTree (BinTree *tree, void *data);

/*Print out a node of the tree
 *Pre: Node is a node of the tree
 *Post: Node->data is printed
*/
char* printNode (BinNode *node);

/*Print an entire tree
 *Pre:Root is the root of the tree (if you would like to print the entire tree)
 *Post:Tree is printed
*/
void printTree (BinNode * root);

/*Search throught the tree, return the node if found, NULL if not found
 *Pre: Data is initialized, compare function is same function used for storing
 *Post: BinNode for found node is returned, else NULL
*/
BinNode* search (BinNode * node, void * data, int (*compareFunction) (void *d1, void *d2));

/*Seacrch through the tree for data, calls search
 *Pre: Data is the data you want to search for
 *Post: Node containing data is returned, else NULL is returned
*/
BinNode* searchTree (BinTree * tree, void * data);

/*Retrieve the left subtree of node
 *Pre:Node is node of tree.
 *Post:Left subtree or NULL is returned.
*/
BinNode* getLeftSubtree(BinNode *tree);

/*Retrieve the right subtree of node
 *Pre: Node is node of tree
 *Post:Right subtree or NULL is returned
*/
BinNode* getRightSubtree(BinNode *tree);

#endif
