#include "options.h"

void moveOption (void) {

}

void deleteOption (void) {

}

void renameOption (BinTree * tree, void * oldName, void * newName) {
	BinNode * nodeToChange = searchTree(tree, oldName);
	if (nodeToChange != NULL) {
		printf("%s changed to %s", nodeToChange->data, newName);
		nodeToChange->data = newName;
	} 
	return;
}

void insertOption (void) {


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
	cleanStding();
}