#include "destroyFunctions.h"

BinNode* rightMost (BinNode * node) {
	while (node->right != NULL)
		node = node->right;
	
	return node;	
}

BinNode* destroyNode (BinTree* tree, BinNode* root, void * data) {
	if (root == NULL) {
		printf("Not Found!\n");
		return root;
	}
	int (*compareFunction) (void *d1, void *d2) = tree->compareFunction;
	
	if (compareFunction(data, root->data) < 0) root->left = destroyNode(tree, root->left, data);
	else if (compareFunction(root->data, data) < 0) root->right = destroyNode(tree, root->right, data);

	// This is the node we want
	else {
		if (root->left && root->right) {
			// Left and Right Subroots
			BinNode *replacement = rightMost(root->left);

			root->data = replacement->data;

			root->left = destroyNode(tree, root->left, replacement->data);
		}
		else if (root->right) {
			// Right Subroot
			BinNode *replacement = root->right;
			free(root);
			return replacement;
		}
		else if (root->left){
			// Left Subroot
			BinNode *replacement = root->left;
			free(root);
			return replacement;
		}
		else {
			// No Subroots
			return NULL;
		}

	}
	avlBalance(tree);
	return root;
}


/*Consider replacing this*/
void * destroyBinTree (void *toDestroy) {
	BinTree * tree = toDestroy;
	if (tree && tree->root) {
		

		free(tree);

		tree = NULL;
	}

	return tree;
}


