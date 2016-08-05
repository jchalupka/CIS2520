#ifndef __JCHALUPK_AVL__
#define __JCHALUPK_AVL__

#include "BinaryTree.h"

/*Calculate the balancefactor
 *Pre: Tree is initialized and is the node you want to calculate bf
 *Post: Balance factor is returned
*/
int balanceFactor (BinNode * tree);

/*Rotate Left and the Left again
 *Pre: Tree is initialized
 *Post: Rotated twice left
*/
BinNode *avl_Left_Left(BinNode *node);

/*Rotate Left and Right
 *Pre: Tree is initialized
 *Post: Rotated left and then right
*/
BinNode *avl_Left_Right(BinNode *node);

/*Rotated right and left
 *Pre: Tree is initialized
 *Post: Rotated Right and then left
*/
BinNode *avl_Right_Left(BinNode *node);

/*Rotate right twice
 *Pre: Tree is initialized
 *Post: Rotated right twice
*/
BinNode *avl_Right_Right(BinNode *node);

/*Balance the tree (for this particular node)
 *Pre: Node is a node of tree
 *Post:Avl tree is balanced for this node
*/
BinNode* avlBalanceNode(BinNode *node);

/*Balance the entire tree
 *Pre:Tree is initialized
 *Post:Tree is balanced
*/
void avlBalance(BinTree * tree);


#endif
