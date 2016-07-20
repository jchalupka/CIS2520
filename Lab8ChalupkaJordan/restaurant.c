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

/* Compare functions

the compare function must have following signature (but can be called anything you like)

int compare (void * data1, void * data2);

The compare function must return a number greater than zero if data1  is 'larger' than 
data2,  a number less than zero of data2 is 'larger' than data1, and zero if the two are
equal.  'larger' can be interpreted any way you like

*/

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
	order = compareRating (data1, data2);
	if (order) {
		return order;
	}
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
	order = compareName (data1, data2);
	if (order) {
		return order;
	}
}

void printData (void * data) {
	Restaurant * restPtr = (Restaurant*) data;

	if (data == NULL) {
		printf("ERROR\n");
	}

	printf("%s %s %d\n", restPtr->name, restPtr->type, restPtr->rating);
	
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

	printf("In order for name:\n");
	printInOrder(nameTree, printData);
	printf("\n");
	printf("In order for rating:\n");
	printInOrder(ratingTree, printData);



	return 0;
}
