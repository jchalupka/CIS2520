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
	for (int i = 0; i < shift-8; i++) printw(" ");
	for (int j = 0; j < 4; j++) printw("-");
	printw("%s %s %d\n", restPtr->name, restPtr->type, restPtr->rating);
	refresh();

	return;
}

// Traverse in order
void traverseInOrder (Tree * tree, int shift, int layer) {
	if (tree == NULL) {
		return;
	}

	if (getRightSubtree(tree)) {

		traverseInOrder(getRightSubtree(tree), shift + 8, layer + 1);
		printw("Right %d", layer);
	}
	printData(getRootData(tree), shift);
	printw("\n");

	if (getLeftSubtree(tree)) {
		printw("Left %d", layer);
		traverseInOrder(getLeftSubtree(tree), shift + 8, layer + 1);


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

	traverseInOrder(ratingTree, 0, 0);
	//printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	//traverseInOrder(ratingTree);
	refresh();
	getchar();
	clear();
	endwin();


	return 0;
}
