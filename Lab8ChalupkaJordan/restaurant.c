// Jordan Chalupka 0928258

#include "restaurant.h"

Restaurant * createRestaurant (char * name, char * type, int rating) {
	Restaurant * restPtr = malloc(sizeof(Restaurant));
	restPtr->name = malloc(sizeof(char)*255);
	restPtr->type = malloc(sizeof(char)*255);

	strcpy(restPtr->name, name);
	strcpy(restPtr->type, type);
	restPtr->rating = rating;

	return restPtr;
}

void destroyRestaurant (void * toDestroy) {
	Restaurant * restPtr = toDestroy;
	free(restPtr->name);
	free(restPtr->type);
	free(restPtr);
	restPtr = NULL;

	return;
}

int compareName (void * data1, void * data2) {
	Restaurant * restPtr1 = (Restaurant*) data1;
	Restaurant * restPtr2 = (Restaurant*) data2;

	char * name1 = restPtr1->name;
	char * name2 = restPtr2->name;

	int order = strcmp(name1,name2);
	// If the names are not equal we are done.
	if (order) {
		return order;
	}

	int rating1 = restPtr1->rating;
	int rating2 = restPtr2->rating;

	order = rating2 - rating1;
	if (order) {
		return order;
	}

	return compareType(data1, data2);
}

int compareRating (void * data1, void * data2) {
	Restaurant * restPtr1 = (Restaurant*) data1;
	Restaurant * restPtr2 = (Restaurant*) data2;

	int rating1 = restPtr1->rating;
	int rating2 = restPtr2->rating;

	int order = rating2 - rating1;
	// If the ratings are not equal we are done
	if (order) {
		return order;
	}
	char * name1 = restPtr1->name;
	char * name2 = restPtr2->name;

	order = strcmp(name1,name2);
	// If the names are not equal we are done.
	if (order) {
		return order;
	}

	return compareType(data1, data2);
}

int compareType (void * data1, void * data2) {
	Restaurant * restPtr1 = (Restaurant*) data1;
	Restaurant * restPtr2 = (Restaurant*) data2;

	char * type1 = restPtr1->type;
	char * type2 = restPtr2->type;

	int order = strcmp(type1,type2);
	// At this point, it is known that the names, and ratings are the same.
	// So we can simply return the order (If the order is zero, they are the same restaurants)
	
	return order;	
}

void printData (void * data, int shift) {
	Restaurant * restPtr = (Restaurant*) data;

	if (data == NULL) {
		printf("ERROR\n");
	}

	//printf("%s\n%s\n%d\n\n", restPtr->name, restPtr->type, restPtr->rating);
	int cury,curx;
	getyx(stdscr, cury, curx);
	move(cury,curx + shift);
	
	//for (int j = 0; j < 4; j++) printw("-");
	printw("%s %d", restPtr->name, restPtr->rating);
	refresh();

	return;
}

int height (Tree * tree) {
	if (tree == NULL) {
		return 0;
	}
	// Get the height of the tree
	int leftTree = height (getLeftSubtree(tree));
	int rightTree = height (getRightSubtree(tree));

	if (leftTree > rightTree) {
		return leftTree + 1;
	} else {
		return rightTree + 1;
	}

}

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

	return numRoots;
}

int numLinesUp (Tree * tree) {
	Tree * rightSub = getRightSubtree(tree);
	if (rightSub == NULL) {
		return 0;
	}
	Tree * leftSub = getLeftSubtree(rightSub);
	int numRoots = getNumRoots(leftSub);

	return numRoots;
}


// Traverse in order
void traverseInOrder (Tree * tree, int shift, int layer) {
	if (tree == NULL) {
		return;
	}

	


	if (getRightSubtree(tree)) {
		// Draw the connection

		traverseInOrder(getRightSubtree(tree), shift + 8, layer + 1);
		
	}

	printData(getRootData(tree), shift);
	int cury,curx;
	getyx(stdscr,cury,curx);
	if (getRightSubtree) {
		move(cury - numLinesUp(tree), curx);
		vline('$',numLinesUp(tree));
		move(cury,curx);
	}
	if (getLeftSubtree(tree)) {
		vline('$', numLinesDown(tree) + 2);
	}
	
	move(cury+1,0);
	getchar();


	

	


	if (getLeftSubtree(tree)) {

		traverseInOrder(getLeftSubtree(tree), shift + 8, layer + 1);
		

	}
	

	return;
}



void printLevel(Tree * tree, int height, int shift) {
	if (tree == NULL) return;
	if (height == 1) printData(getRootData(tree), shift);
	else if (height > 1) {
		printLevel(getRightSubtree(tree), height - 1, shift + 1);
		printLevel(getLeftSubtree(tree), height - 1, shift + 1);
	}

}

void BFT (Tree * tree) {
	int h = height(tree);
	for (int i = 0; i <= h; i++) {
		printLevel(tree, i, 0);
	}


	return;
}





int main (void) {
	FILE * file = openFile("data.txt");

	Tree * nameTree = createBinTree(compareName, destroyRestaurant);
	Tree * ratingTree = createBinTree(compareRating, destroyRestaurant);
	if (!(nameTree && ratingTree)) {
		printf("ERROR CREATING TREE\n");

	}
	collectFile(file, nameTree, ratingTree);

	initscr();
	noecho();
	cbreak();

	static int layer = 0;
	traverseInOrder(ratingTree, 0, layer);
	//BFT(ratingTree);
	printw("This is the height: %d",height(ratingTree));
	//printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	//traverseInOrder(ratingTree);
	refresh();
	getchar();
	clear();
	endwin();


	return 0;
}
