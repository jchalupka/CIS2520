// Jordan Chalupka 0928528
#include "options.h"

void moveOption () {

}

void deleteOption (BinTree * tree, void * toDelete) {
	if ((tree->root = destroyNode(tree, tree->root, toDelete)) != NULL) {

		printf("Succesfully deleted: %s\n", (char*)toDelete);
	} else {
		printf("Nothing deleted.\n");
	}

	return;
}

void renameOption (BinTree * tree, void * oldName, void * newName) {
	BinNode * nodeToChange = searchTree(tree, oldName);
	if (nodeToChange != NULL) {
		printf("%s changed to %s\n", (char*)nodeToChange->data, (char*)newName);
		nodeToChange->data = newName;
	} 
	
	return;
}

void insertOption (BinTree * tree, void *toInsert, void * toInsertPath) {
	insertBinTree(tree, toInsert);

	return;
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


	// Fix buffer errors with ncurses => normal
	setvbuf(stdout, NULL, _IOLBF, 0);
 	setvbuf(stderr, NULL, _IONBF, 0);

 	return;
}
