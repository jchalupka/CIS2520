#include "destroyFunctions.h"

BinNode* rightMost (BinNode * node) {
	node = node->right;
	if (node->right == NULL) return node;
	
	node = rightMost(node);
	return node;	
}

BinNode* destroyNode (BinTree* tree, BinNode* root, void * data) {
	if (!(tree && root)) {
		return root;
	}

	int (*compareFunction) (void *d1, void *d2) = tree->compareFunction;
	
	if (compareFunction(data, root->data) > 0) destroyNode(tree, root->left, data);
	else if (compareFunction(data,root) < 0) destroyNode(tree, root->right, data);

	// This is the node we want
	else {
		if (root->left && root->right) {
			// Left and Right Subroots
			printf("L&R\n");
			BinNode *replacement = rightMost(root->left);

			root->data = replacement->data;

			root->left = destroyNode(tree, root->left, data);
		}
		else if (root->right) {
			// Right Subroot
			printf("R\n");
			BinNode *replacement = root->left;
			free(root);
			return replacement;
		}
		else if (root->left){
			// Left Subroot
			printf("L\n");
			BinNode *replacement = root->right;
			free(root);
			return replacement;
		}
		else {
			// No Subroots
			printf("None\n");
			return NULL;
		}

	}

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


