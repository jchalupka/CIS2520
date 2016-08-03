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

void * destroyBinTree (void *toDestroy) {
	BinTree * tree = toDestroy;
	if (tree && tree->root) {
		tree->root = removeBinNode(tree, tree->root);

		free(tree);

		tree = NULL;
	}

	return tree;
}

BinNode* rightMost (BinNode * node) {
	node = node->right;
	if (node == NULL) return node;
		printf("This is Here\n");
	
	if (node->right) {
		node = rightMost(node);
	}

	return node;

	
}

BinNode* removeRightMost (BinNode * node, BinNode * remove) {
	if (node == remove) {
		return node->right;
	}
	else {
		node->right = removeRightMost(node->right, remove);
		return node;
	}
}

BinNode* removeBinNode (BinTree *tree, BinNode *toDestroy) {
	if (!toDestroy) return NULL;
	//removeBinNode(tree, toDestroy->left);
	printf("Destroying %s\n", toDestroy->data);

	//removeBinNode(tree, toDestroy->right);
	BinNode * replacement;
	if (toDestroy->right && toDestroy->left) { // Left and Right Children
		
		replacement = rightMost(toDestroy->left);
		replacement->left = removeRightMost(toDestroy->left, replacement);
		if (replacement == NULL) {
			printf("Made it here\n");
			replacement = toDestroy->left;
		}
		//printf("This is the data: %s\n", replacement->data);
		//replacement->left = removeLeftMost(replacement->right, replacement);
		printf("This is the replacement: %s\n", replacement->data);
		replacement->left = toDestroy->left;
		replacement->right = toDestroy->right;

	} else if (toDestroy->left) { // Left Child
		printf("Left Child\n");
		replacement = toDestroy->left;
	} else if (toDestroy->right) { // Right Children
		printf("Right Child\n");
		replacement = toDestroy->right;
	} else { // No Children
		printf("No Child");
		replacement = NULL;

	}

	
	toDestroy = replacement;
	free(toDestroy->data);
	free(toDestroy);
	// toDestroy = replacement;
	// toDestroy->left = NULL;
	// toDestroy->right = NULL;
	

	//avlBalance(tree);

	return toDestroy;
}

BinNode* destroyNode (BinTree * tree, void * data) {
	if (!(tree && tree->root)) {
		fprintf(stderr, "Error, tree not created correctly\n");
		return NULL;
	}
	BinNode *result = searchAndDestroy(tree->root, data, tree->compareFunction);
	if (result == NULL) {
		printf("Not found!\n");
		return result;
	}

	int (*compareFunction) (void *, void *) = tree->compareFunction;
	if (!compareFunction(data, result->data)) {
	/*

		Destroy the entire directory for now
	*/
		
		destroyBinTree(tree);
		return NULL;
	}
	else if (!compareFunction(data, result->left->data )) {
		printf("Removed %s\n", result->left->data);
		
		result->left = removeBinNode(tree, result->left);
	}
	else {
		
		printf("Removed %s\n", result->right->data);
		result->right = removeBinNode(tree, result->right);
	}

	avlBalance(tree);

	return result;
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

BinNode* searchAndDestroy (BinNode * node, void * data, int (*compareFunction) (void *d1, void *d2)) {
	static BinNode *result = NULL;
	int order = compareFunction(node->data,data);

	int orderLeft = -1;
	int orderRight = -1;

	if (node->left) orderLeft = compareFunction(node->left->data, data);
	if (node->right) orderRight = compareFunction(node->right->data, data);
	
	if (order == 0) {
		printf("returning Root\n");
		return node;
	}

	if (orderRight == 0  || orderLeft == 0) {
		result = node;
	}
	if (order > 0 && node->left != NULL) {
		searchAndDestroy(node->left, data, compareFunction);
	} else if (node->right != NULL){
		searchAndDestroy (node->right, data, compareFunction);
	}

	return result;
}

BinNode* getLeftSubtree(BinNode *tree) {
	return tree->left;
}
BinNode* getRightSubtree(BinNode *tree) {
	return tree->right;
}



































