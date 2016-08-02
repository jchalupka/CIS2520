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

// Stub delete function
void destroyStub (void *toDestroy) {

	return;
}

// User functions
BinTree * createBinTree (int (*compareFunction) (void *d1, void *d2), void (*destroyFunction) (void *toDestroy)) {
	BinTree *toCreate;
	toCreate = calloc(1, sizeof(BinTree));
	toCreate->compareFunction = compareFunction;
	toCreate->destroyFunction = destroyFunction;

	return toCreate;
}

BinTree * destroyBinTree (BinTree *toDestroy) {
	if (toDestroy) {
		toDestroy->root = removeBinNode(toDestroy->root);

		free(toDestroy);

		toDestroy = NULL;
	}

	return toDestroy;
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
	rootToAdd->data = calloc(1,sizeof(data));
	rootToAdd->data = data;


	// Fix here
	//tree->root = root;
	insert(&tree->root, rootToAdd, tree->compareFunction);

	return;
}

BinNode* removeBinNode (BinNode *toDestroy) {
	if (toDestroy) {
		toDestroy->left = removeBinNode(toDestroy->left);
		toDestroy->right = removeBinNode(toDestroy->right);

		free(toDestroy->data);
		free(toDestroy);
		toDestroy = NULL;
	}

	return toDestroy;
}




void printNode (BinNode *node) {
	if (!(node  && node->data)){
		return;
	}
	fprintf(stdout, "%s",node->data);
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



































