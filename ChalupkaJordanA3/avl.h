#ifndef __JCHALUPK_AVL__
#define __JCHALUPK_AVL__

#include "BinaryTree.h"

int balanceFactor (BinNode * tree);


BinNode *avl_Left_Left(BinNode *node);


BinNode *avl_Left_Right(BinNode *node);


BinNode *avl_Right_Left(BinNode *node);


BinNode *avl_Right_Right(BinNode *node);


BinNode* avlBalanceNode(BinNode *node);


void avlBalance(BinTree * tree);


BinNode * rotateRight (BinNode * tree);


BinNode * rotateLeft (BinNode * tree);

#endif
