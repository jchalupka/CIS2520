// Jordan Chalupka 0928258

#include "printTree.h"


int getNumRoots (BinNode * tree) {
	if (tree == NULL) {
		return 0;
	}
	return 1 + getNumRoots(getLeftSubtree(tree)) + getNumRoots(getRightSubtree(tree));
}

int numLinesDown (BinNode * tree) {
	BinNode * leftSub = getLeftSubtree(tree);
	if (leftSub == NULL) {
		return 0;
	}
	BinNode * rightSub = getRightSubtree(leftSub);
	int numRoots = getNumRoots(rightSub);

	return numRoots + 2;
}

int numLinesUp (BinNode * tree) {
	BinNode * rightSub = getRightSubtree(tree);
	if (rightSub == NULL) {
		return 0;
	}
	BinNode * leftSub = getLeftSubtree(rightSub);
	int numRoots = getNumRoots(leftSub);

	return numRoots + 2;
}

int wordStrlen (BinNode * tree) {
	if (!(tree && tree->data)) {
		fprintf(stderr,"Error\n");
		return 0;
	}
	char word[255];
	sprintf(word, "%s",tree->data);

	return strlen(word);
}


void drawConnectionPreOrder (BinNode * tree) {
	int cury,curx;
	getyx(stdscr,cury,curx);

	if (getRightSubtree(tree)) {
		vline('+',2);
	}
	if (getLeftSubtree(tree)) {
		vline('+', getNumRoots(getRightSubtree(tree))+2);
	}

	move(cury+1,0);
}

void drawConnectionInOrder (BinNode * tree) {
	int cury,curx;
	getyx(stdscr,cury,curx);

	if (getRightSubtree(tree)) {
		move(cury - (numLinesUp(tree)-1), curx);	
		vline('+', numLinesUp(tree));
		move(cury,curx);
	}
	if (getLeftSubtree(tree)) {
		vline('+', numLinesDown(tree));
	}

	move(cury+1,0);
}

int initNCurses (void) {
	initscr();
	noecho();
	cbreak();

	return 0;
}

int exitNCurses (void) {
	curs_set(1);
	clear();
	endwin();
	
	return 0;
}

void printData(BinNode * tree, int shift) {
	if (!(tree && tree->data)) fprintf(stderr, "Error\n"); 

	int cury,curx;
	getyx(stdscr, cury, curx);
	char word[255];
	//sprintf(word, "%d", balanceFactor(tree));
	sprintf(word, "%s",tree->data);
	move(cury,curx + shift);
	
	printw("%s", word);

	refresh();

	return;
}

// Traverse in order
void traverseInOrder (BinNode * tree, int shift) {
	if (tree == NULL) {
		return;
	}

	traverseInOrder(getRightSubtree(tree), shift + wordStrlen(tree) + 1);
		
	printData(tree, shift);
	
	drawConnectionInOrder(tree);

	traverseInOrder(getLeftSubtree(tree), shift + wordStrlen(tree) + 1);

	refresh();

	return;

}

// Traverse pre order
void traversePreOrder (BinNode * tree, int shift) {
	if (tree == NULL) {
		return;
	}
	printData(tree, shift);
	
	drawConnectionPreOrder(tree);

	traversePreOrder(getRightSubtree(tree), shift + wordStrlen(tree) + 1);

	traversePreOrder(getLeftSubtree(tree), shift + wordStrlen(tree) + 1);

	refresh();

	return;

}











