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

void destroyRestaurant (Restaurant * toDestroy) {
	free(toDestroy->name);
	free(toDestroy->type);
	free(toDestroy);
	toDestroy = NULL;

	return;
}

/* Compare functions

the compare function must have following signature (but can be called anything you like)

int compare (void * data1, void * data2);

The compare function must return a number greater than zero if data1  is 'larger' than 
data2,  a number less than zero of data2 is 'larger' than data1, and zero if the two are
equal.  'larger' can be interpreted any way you like

*/

int compareName (void * data1, void * data2) {
	int order = 1;

	return order;
}

int compareOrder (void * data1, void * data2) {
	int order = 1;

	return order;
}

void printData (void * data) {
	Restaurant * restPtr = (Restaurant*) data;

	//printf("%s %s %d", restPtr->name, restPtr->type, restPtr->rating);
	return;
}

int main (void) {
	FILE * file = openFile("data.txt");

	// Function pointers
	int (*compareName)(void *, void *) = compareName;
	int (*compareOrder)(void *, void *) = compareOrder;
	void (*destroyRestaurant)(void*) = destroyRestaurant;
	void (*printData)(void * data) = printData;

	Tree * tree = createBinTree(compareName, destroyRestaurant);
	collectFile(file, tree);
	printInOrder(tree, printData);



	return 0;
}
