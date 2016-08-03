#include "BinaryTree.h"

/*
typedef struct BinaryTreeNode {
	struct BinaryTreeNode *left;
	struct BinaryTreeNode *right;
	void *data;
} BinNode;

typedef struct BinaryTree {
	BinNode * root;
	int (*compareFunction) (void *d1, void *d2);
	void (*destroyFunction) (void *toDestroy);
} BinTree;

// User wrapper functions
void createBinTree (BinTree *toCreate, (*compareFunction) (void *d1, void *d2), (*destroyFunction) (void *toDestroy));
void destroyBinTree (BinTree *toDestroy);
void insertBinNode (BinTree *tree, void *data);
void removeBinNode (BinTree *tree, void *data);

// Internal helper functions
void insert (BinTree *root, void *data);
void delete (BinTree *root, void *data);
int isEmpty (BinTree *root);
// isFull

*/

// Stub compare function
int compareStrings (void *d1, void *d2) {
	char string1[255];
	char string2[255];

	strcpy(string1, (char*) d1);
	strcpy(string2, (char*) d2);

	int order = strcmp(string1, string2);

	return order;
}

// User functions
BinTree * createBinTree (int (*compareFunction) (void *d1, void *d2), void *(*destroyBinTree) (void *tree)) {
	BinTree *toCreate;
	toCreate = calloc(1, sizeof(BinTree));
	toCreate->compareFunction = compareFunction;
	toCreate->destroyFunction = destroyBinTree;

	return toCreate;
}

void * destroyBinTree (void *toDestroy) {
	BinTree * tree = toDestroy;
	if (toDestroy) {
		tree->root = removeBinNode(tree, tree->root);

		free(tree);

		tree = NULL;
	}

	return tree;
}


BinNode* removeBinNode (BinTree *tree, BinNode *toDestroy) {
	if (toDestroy) {
		removeBinNode(tree, toDestroy->left);
		printf("Destroying %s\n", toDestroy->data);

		removeBinNode(tree, toDestroy->right);

		free(toDestroy->data);
		free(toDestroy);
		toDestroy = NULL;
	}

	avlBalance(tree);

	return toDestroy;
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

void insert (BinNode ** root, BinNode *rootToAdd, int (*compareFunction) (void *d1, void *d2)) {
	if (!*root) {
		*root = rootToAdd;

		return;
	}
	int order = compareFunction((*root)->data, rootToAdd->data); 
	if (order >= 0) {
		insert(&((*root)->left), rootToAdd, compareFunction);
	}
	else {
		insert(&((*root)->right), rootToAdd, compareFunction);
	}
}

int max ( int a, int b ) { return a > b ? a : b; }

int getHeight (BinNode * tree) {
	if (tree == NULL) {
		return -1;
	}

	return max(getHeight(tree->left),getHeight(tree->right)) + 1;
}

void AVLInsert () {

}

int balanceFactor (BinNode * tree) {
	int bf = getHeight(tree->left) - getHeight(tree->right);

	return bf;
}

/* Left Left Rotate */
BinNode *avl_rotate_leftleft( BinNode *node ) {
 	BinNode *a = node;
	BinNode *b = a->left;
	
	a->left = b->right;
	b->right = a;

	return( b );
}

/* Left Right Rotate */
BinNode *avl_rotate_leftright( BinNode *node ) {
	BinNode *a = node;
	BinNode *b = a->left;
	BinNode *c = b->right;
	
	a->left = c->right;
	b->right = c->left; 
	c->left = b;
	c->right = a;

	return( c );
}

/* Right Left Rotate */
BinNode *avl_rotate_rightleft( BinNode *node ) {
	BinNode *a = node;
	BinNode *b = a->right;
	BinNode *c = b->left;
	
	a->right = c->left;
	b->left = c->right; 
	c->right = b;
	c->left = a;

	return( c );
}

/* Right Right Rotate */
BinNode *avl_rotate_rightright( BinNode *node ) {
	BinNode *a = node;
	BinNode *b = a->right;
	
	a->right = b->left;
	b->left = a; 

	return( b );
}

BinNode* avlBalanceNode( BinNode *node ) {
	BinNode *newroot = NULL;
	if (!node) return node;
	/* Balance our children, if they exist. */
	if( node->left )
		node->left  = avlBalanceNode( node->left  );
	if( node->right ) 
		node->right = avlBalanceNode( node->right );

	int bf = balanceFactor( node );

	if( bf >= 2 ) {
		/* Left Heavy */	

		if( balanceFactor( node->left ) <= -1 ) 
			newroot = avl_rotate_leftright( node );
		else 
			newroot = avl_rotate_leftleft( node );

	} else if( bf <= -2 ) {
		/* Right Heavy */

		if( balanceFactor( node->right ) >= 1 )
			newroot = avl_rotate_rightleft( node );
		else 
			newroot = avl_rotate_rightright( node );

	} else {
		/* This node is balanced -- no change. */

		newroot = node;
	}

	return( newroot );	
}

void avlBalance(BinTree * tree) {
	BinNode *newNode = NULL;
	newNode = avlBalanceNode(tree->root);

	if (newNode != tree->root) {
		tree->root = newNode;
	}
}

void insertBinTree (BinTree *tree, void *data) {
	if (!tree) {
		fprintf(stderr, "Error, Tree not created\n");

		return;
	}

	// Put in create root function
	BinNode * rootToAdd;
	rootToAdd = calloc(1, sizeof(BinNode));
	rootToAdd->left = NULL;
	rootToAdd->right = NULL;
	rootToAdd->data = data;


	// Fix here
	//tree->root = root;
	insert(&tree->root, rootToAdd, tree->compareFunction);

	avlBalance(tree);

	return;
}



void printNode (BinNode *node) {
	if (!(node  && node->data)){
		return;
	}
	fprintf(stdout, "%s\n",node->data);
	return;
}

void printTree (BinNode * root) {
	if (!root) {
		return;
	}
	// Traverse
	//traverseInOrder(printTree, printNode, root);
	printTree(root->left);
	printNode(root);
	printTree(root->right);
	
	
}

BinNode* search (BinNode * node, void * data, int (*compareFunction) (void *d1, void *d2)) {
	static BinNode *result = NULL;
	int order = compareFunction(node->data,data);
	if (order == 0) {
		result = node;
	}
	if (order > 0 && node->left != NULL) {
		search(node->left, data, compareFunction);
	} else if (node->right != NULL){
		search (node->right, data, compareFunction);
	}

	return result;
}

BinNode* searchTree (BinTree * tree, void * data) {
	if (!(tree && tree->root)) {
		fprintf(stderr, "Error, tree not created correctly\n");
		return NULL;
	}
	BinNode *result = search(tree->root, data, tree->compareFunction);

	if (result == NULL) {
		printf("Not found!\n");
	}

	return result;
}

BinNode* getLeftSubtree(BinNode *tree) {
	return tree->left;
}
BinNode* getRightSubtree(BinNode *tree) {
	return tree->right;
}


/*
int main (void) {
	
	insertBinTree(tree, "Data What is this");
	insertBinTree(tree, "That");
	insertBinTree(tree, "This");
	insertBinTree(tree, "Here");

	
	initNCurses();
	traverseInOrder(tree->root, 0);	
	getchar();
	exitNCurses();

	return 0;
}

*/



































