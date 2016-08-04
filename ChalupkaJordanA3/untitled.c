/*destroyBinTree
 *  Destroy an entire tree.
 *
 */
void * destroyBinTree (void *toDestroy) {
	BinTree * tree = toDestroy;
	if (tree && tree->root) {
		tree->root = removeBinNode(tree, tree->root);

		free(tree);

		tree = NULL;
	}

	return tree;
}


/*Destroy Node
 *  Destroy a single node.  Called by User.
 *  
 *
 */
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


/* rightMost
 *   Returns the right most node.
 *
 */
BinNode* rightMost (BinNode * node) {
	
	if (node->right == NULL) return node;
	
	
	node = node->right;
	rightMost(node);
	return node;	
}


/* rightMost
 *   Returns the right most node.
 *
 */
BinNode* removeRightMost (BinNode * node) {	
	if (node->right == NULL) {
		node = NULL;
		return node;
	}
	node = node->right;
	// Continue moving right through the nodes
	node = rightMost(node);

	return node;
}



/* removeBinNode
 *   Remove a single binary node.  This function is called by detroyBinTree,
 *   and destroyNode.
 *
 */
BinNode* removeBinNode (BinTree *tree, BinNode *toDestroy) {
	if (!toDestroy) return NULL;
	
	printf("Destroying %s\n", toDestroy->data);

	BinNode * replacement;
	if (toDestroy->right && toDestroy->left) { // Left and Right Children
		replacement = rightMost(toDestroy->left); // This will replace toDestroy
		removeRightMost(toDestroy->left);// Destroy the old replacement node

	printf("Here\n");
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

	
	
	free(toDestroy->data);
	free(toDestroy);
	toDestroy = replacement;
	// toDestroy = replacement;
	// toDestroy->left = NULL;
	// toDestroy->right = NULL;
	

	//avlBalance(tree);

	return toDestroy;
}

BinNode* searchAndDestroy (BinNode * node, void * data, int (*compareFunction) (void *d1, void *d2)) {
	static BinNode *result = NULL;
	
	/*  Three order variables will be used to search for the correct node.
		order: Used to search with the current Node.
		orderLeft, orderRight: Used to search for the left and right nodes of the current Node.
	 */
	int order = compareFunction(node->data,data);
	int orderLeft = -1;
	int orderRight = -1;

	if (node->left) orderLeft = compareFunction(node->left->data, data);
	if (node->right) orderRight = compareFunction(node->right->data, data);
	
	printf("Data: %s\nNodeData: %s\n\n", data, node->data);
	printf("Order: %d\nOrderRight: %d\nOrderLeft: %d\n\n", order, orderRight, orderLeft);

	if (order == 0) {
		printf("returning Root\n");
		return node;
	}

	if (orderRight == 0  || orderLeft == 0) {
		result = node;
	}
	else if (order > 0 && node->left != NULL) {
		searchAndDestroy(node->left, data, compareFunction);
	} else if (node->right != NULL){
		searchAndDestroy (node->right, data, compareFunction);
	}

	return result;
}
