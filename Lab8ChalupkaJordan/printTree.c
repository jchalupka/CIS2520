// Jordan Chalupka 0928258

#include "printTree.h"

int getNumRoots (Tree * tree) {
	if (tree == NULL) {
		return 0;
	}
	return 1 + getNumRoots(getLeftSubtree(tree)) + getNumRoots(getRightSubtree(tree));
}

int numLinesDown (Tree * tree) {
	Tree * leftSub = getLeftSubtree(tree);
	if (leftSub == NULL) {
		return 0;
	}
	Tree * rightSub = getRightSubtree(leftSub);
	int numRoots = getNumRoots(rightSub);

	return numRoots + 2;
}

int numLinesUp (Tree * tree) {
	Tree * rightSub = getRightSubtree(tree);
	if (rightSub == NULL) {
		return 0;
	}
	Tree * leftSub = getLeftSubtree(rightSub);
	int numRoots = getNumRoots(leftSub);

	return numRoots + 2;
}

int wordStrlen (Tree * tree) {
	Restaurant * restPtr = (Restaurant*) getRootData(tree);
	char word[255];
	sprintf(word, "%s %d",restPtr->name, restPtr->rating);

	return strlen(word);
}


void drawConnection (Tree * tree) {
	int cury,curx;
	getyx(stdscr,cury,curx);

	if (getRightSubtree(tree)) {
		move(cury - (numLinesUp(tree)-1), curx);
		vline('+',numLinesUp(tree));
		move(cury,curx);
	}
	if (getLeftSubtree(tree)) {
		vline('+', numLinesDown(tree));
	}
}
// Traverse in order
void traverseInOrder (Tree * tree, int shift) {

	if (tree == NULL) {
		return;
	}

	traverseInOrder(getRightSubtree(tree), shift + wordStrlen(tree) + 1);
		
	printData(getRootData(tree), shift);


	traverseInOrder(getLeftSubtree(tree), shift + wordStrlen(tree) + 1);

	return;
}

