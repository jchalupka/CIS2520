#include "avl.h"

int balanceFactor (BinNode * tree) {
	int bf = getHeight(tree->left) - getHeight(tree->right);

	return bf;
}

/* Left Left Rotate */
BinNode *avl_rotate_leftleft(BinNode *node) {
 	BinNode *a = node;
	BinNode *b = a->left;
	
	a->left = b->right;
	b->right = a;

	return(b);
}

/* Left Right Rotate */
BinNode *avl_rotate_leftright(BinNode *node) {
	BinNode *a = node;
	BinNode *b = a->left;
	BinNode *c = b->right;
	
	a->left = c->right;
	b->right = c->left; 
	c->left = b;
	c->right = a;

	return(c);
}

/* Right Left Rotate */
BinNode *avl_rotate_rightleft(BinNode *node) {
	BinNode *a = node;
	BinNode *b = a->right;
	BinNode *c = b->left;
	
	a->right = c->left;
	b->left = c->right; 
	c->right = b;
	c->left = a;

	return(c);
}

/* Right Right Rotate */
BinNode *avl_rotate_rightright(BinNode *node) {
	BinNode *a = node;
	BinNode *b = a->right;
	
	a->right = b->left;
	b->left = a; 

	return(b);
}

BinNode* avlBalanceNode(BinNode *node) {
	BinNode *newroot = NULL;

	if(node->left) node->left = avlBalanceNode(node->left );
	if(node->right) node->right = avlBalanceNode(node->right);

	int bf = balanceFactor(node);

	if(bf >= 2) {
		/* Left Side is Overloaded */	
		if( balanceFactor(node->left) <= -1 ) 
			newroot = avl_rotate_leftright(node);
		else 
			newroot = avl_rotate_leftleft(node);

	} else if( bf <= -2 ) {
		/* Right Side is Overloaded */
		if( balanceFactor(node->right) >= 1 )
			newroot = avl_rotate_rightleft(node);
		else 
			newroot = avl_rotate_rightright(node);

	} else {
		/* Balanced */

		newroot = node;
	}

	return(newroot);	
}

void avlBalance(BinTree * tree) {
	BinNode *newNode = NULL;
	//printf("Here  %s\n", tree->root->data);
	newNode = avlBalanceNode(tree->root);

	if (newNode != tree->root) {		
		tree->root = newNode;
	}
}


BinNode * rotateRight (BinNode * tree) {
	BinNode * node = tree->left;
	BinNode * node2 = node->right;

	// Rotation
	node->right = tree;
	tree->left = node2;

	return node;
}

BinNode * rotateLeft (BinNode * tree) {
	BinNode * node = tree->right;
	BinNode * node2 = node->left;

	// Rotation
	node->left = tree;
	tree->right = node2;

	return node;
}

