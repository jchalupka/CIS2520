#include "options.h"

void moveOption (void) {

}

void deleteOption (BinTree * tree, void * toDelete) {
	if ((tree->root = destroyNode(tree, tree->root, toDelete)) != NULL) {

		printf("Succesfully deleted: %s\n", toDelete);
	} else {
		printf("Nothing deleted.\n");
	}

	return;
}

void renameOption (BinTree * tree, void * oldName, void * newName) {
	BinNode * nodeToChange = searchTree(tree, oldName);
	if (nodeToChange != NULL) {
		printf("%s changed to %s\n", nodeToChange->data, newName);
		nodeToChange->data = newName;
	} 
	return;
}

void insertOption (BinTree * tree, void *toInsert, void * toInsertPath) {
	insertBinTree(tree, toInsert);

}

void cleanStding (void) {
	while (getchar() != '\n');
	return;
}

void viewTreeOption (BinTree * tree) {
	
	initNCurses();
	traverseInOrder(tree->root,0);
	getchar();
	exitNCurses();

	endwin();
	setvbuf(stdout, NULL, _IOLBF, 0);
 	setvbuf(stderr, NULL, _IONBF, 0);

	
	//cleanStding();
}