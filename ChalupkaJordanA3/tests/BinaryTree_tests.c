// Jordan Chalupka 0928528
#include "BinaryTree_tests.h"


int compareStrings_test (void) {
	int num = compareStrings("AWord","BWord");
	if (num > 0) return 1;

	num = compareStrings("Thiz", "This");
	if (num < 1) return 1;

	num = compareStrings("Word", "Word");
	if (num != 0) return 1;

	return 0;
}


int createBinTree_test (void) {
	int (*compareFunction) (void *d1, void *d2) = compareStrings;
	void *(*destroyFunction) (void *tree) = destroyBinTree;
	if (createBinTree (compareFunction, destroyFunction) == NULL)
		return 1;
	
	printf("=>Correct\n");
	return 0;
}


int insert_test (void) {
	BinTree * tree = createBinTree(compareStrings, destroyBinTree);

	char * word = malloc(sizeof(char)*255);
	strcpy(word, "This");

	BinNode * node = malloc(sizeof(BinNode));
	node->data = word;
	node->left = NULL;
	node->right = NULL;

	insert(&(tree->root), node, compareStrings);

	if (strcmp(tree->root->data, "This") != 0) return 1;

	printf("=>Correct\n");
	return 0;
}


int getHeight_test (void) {
	BinTree * tree = createBinTree(compareStrings, destroyBinTree);
	if (getHeight(tree->root) != -1) return 1;
	
	char * word = malloc(sizeof(char)*255);
	word = "This";

	BinNode * node = malloc(sizeof(BinNode));
	node->data = word;
	node->left = NULL;
	node->right = NULL;

	tree->root = node;

	if (getHeight(tree->root) != 0) return 1;

	BinNode * node2 = malloc(sizeof(BinNode));
	node2->data = word;
	node2->left = NULL;
	node2->right = NULL;

	node->left = node2;

	if (getHeight(tree->root) != 1) return 1;

	printf("=>Correct\n");
	return 0;
}


int insertBinTree_test (void) {
	char * word = malloc(sizeof(char)*255);
	word = "This";

	BinTree * tree = createBinTree(compareStrings, destroyBinTree);
	insertBinTree(tree, word);

	if (strcmp(word, tree->root->data) != 0) return 1;

	printf("=>Correct\n");
	return 0;
}


int printNode_test (void) {
	char * word = malloc(sizeof(char)*255);
	word = "TestWord";

	BinNode * node = malloc(sizeof(BinNode));
	node->data = word;
	node->left = NULL;
	node->right = NULL;
	printf("Expected: TestWord\n");
	printf("Actual:   ");
	if (strcmp(printNode(node), word) != 0) return 1;

	printf("=>Correct\n");
	return 0;
}


int printTree_test (void) {
	BinTree * tree = createBinTree(compareStrings, destroyBinTree);
	char * word = malloc(sizeof(char)*255);
	strcpy(word,"A");

	char * word2 = malloc(sizeof(char)*255);
	strcpy(word2, "B");

	char * word3 = malloc(sizeof(char)*255);
	strcpy(word3, "C");

	insertBinTree(tree, word);
	insertBinTree(tree, word2);
	insertBinTree(tree, word3);

	printf("Expected:\nA\nB\nC\n");
	printf("Actual:\n");
	printTree(tree->root);

	printf("=>Correct\n");
	return 0;
}


int search_test (void) {
	BinTree * tree = createBinTree(compareStrings, destroyBinTree);
	char * word = malloc(sizeof(char)*255);
	strcpy(word,"A");

	char * word2 = malloc(sizeof(char)*255);
	strcpy(word2, "B");

	char * word3 = malloc(sizeof(char)*255);
	strcpy(word3, "C");

	insertBinTree(tree, word);
	insertBinTree(tree, word2);
	insertBinTree(tree, word3);

	BinNode * result = search(tree->root, word2, compareStrings);
	if (strcmp(result->data,word2) != 0) return 1;

	printf("=>Correct\n");
	return 0;
}


int searchTree_test (void) {
	BinTree * tree = createBinTree(compareStrings, destroyBinTree);
	char * word = malloc(sizeof(char)*255);
	strcpy(word,"A");

	char * word2 = malloc(sizeof(char)*255);
	strcpy(word2, "B");

	char * word3 = malloc(sizeof(char)*255);
	strcpy(word3, "C");

	insertBinTree(tree, word);
	insertBinTree(tree, word2);
	insertBinTree(tree, word3);

	BinNode * result = searchTree(tree, word2);
	if (strcmp(result->data,word2) != 0) return 1;

	BinNode * result2 = searchTree(tree, "D");
	if (result2->data == NULL) return 1;

	printf("=>Correct\n");
	return 0;
}


int getLeftSubtree_test (void) {
	BinTree * tree = createBinTree(compareStrings, destroyBinTree);
	

	char * word = malloc(sizeof(char)*255);
	strcpy(word,"This");

	char * word2 = malloc(sizeof(char)*255);
	strcpy(word2,"That");

	insertBinTree(tree, word);
	insertBinTree(tree, word2);

	if (strcmp(word2,getLeftSubtree(tree->root)->data) != 0) return 1;

	printf("=>Correct\n");
	return 0;
}


int getRightSubtree_test (void) {
	BinTree * tree = createBinTree(compareStrings, destroyBinTree);
	

	char * word = malloc(sizeof(char)*255);
	strcpy(word,"That");

	char * word2 = malloc(sizeof(char)*255);
	strcpy(word2,"This");

	insertBinTree(tree, word);
	insertBinTree(tree, word2);

	if (strcmp(word2,getRightSubtree(tree->root)->data) != 0) return 1;

	printf("=>Correct\n");
	return 0;
}


int main (void) {
	int numErrors = 0;

	printf("Testing compareStrings\n");
	numErrors += compareStrings_test();
	
	printf("Testing createBinTree\n");
	numErrors += createBinTree_test();
	
	printf("Testing insert\n");
	numErrors += insert_test();
	
	printf("Testing getHeight\n");
	numErrors += getHeight_test();
	
	printf("Testing insertBinTree\n");
	numErrors += insertBinTree_test();
	
	printf("Testing printNode\n");
	numErrors += printNode_test();
	
	printf("Testing printTree\n");
	numErrors += printTree_test();
	
	printf("Testing search\n");
	numErrors += search_test();
	
	printf("Testing searchTree\n");
	numErrors += searchTree_test();
	
	printf("Testing getLeftSubtree\n");
	numErrors += getLeftSubtree_test();
	
	printf("Testing getRightSubtree\n");
	numErrors += getRightSubtree_test();

	printf("%d Errors Found\n", numErrors);

	return 0;
}
