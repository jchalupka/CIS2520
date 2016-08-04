#ifndef __JCHALUPKA_DESTROYFUNCTIONS__
#define __JCHALUPKA_DESTROYFUNCTIONS__

#include "BinaryTree.h"
#include "avl.h"

void * destroyBinTree (void *toDestroy);


BinNode* destroyNode (BinTree * tree, BinNode * root, void * data);


BinNode* searchAndDestroy (BinNode * node, void * data, int (*compareFunction) (void *d1, void *d2));


BinNode* rightMost (BinNode * node);


BinNode* removeRightMost (BinNode * node);


BinNode* removeBinNode (BinTree *tree, BinNode *toDestroy);

#endif
