// Jordan Chalupka 0928528
#ifndef __JCHALUPKA_DESTROYFUNCTIONS__
#define __JCHALUPKA_DESTROYFUNCTIONS__

#include "BinaryTree.h"
#include "avl.h"

/*Return the right most (highest ranking) node
 *Pre: Node is initialized and is the node you want to find the most of.
 *Post: The rightmost node is returned.
*/
BinNode* rightMost (BinNode * node);

/*Destroy the node containing data.
 *Pre:Root is tree->root of tree.
 *Post:Node is destroyed, and subtrees are rotated to preserve avl
*/
BinNode* destroyNode (BinTree* tree, BinNode* root, void * data);

/*Destroy the entire binary tree
 *Pre: Tree is passed in (void allows for generic function pointer)
 *Post: Entire tree is destroyed
*/
void * destroyBinTree (void *toDestroy);

#endif
