#include "BinaryTree.h"

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
	if (root == NULL) return;
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
	else if (order > 0 && node->left != NULL) {
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



































