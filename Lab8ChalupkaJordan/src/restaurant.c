// Jordan Chalupka 0928258

#include "restaurant.h"

Restaurant * createRestaurant (char * name, char * type, int rating) {
	if (name == NULL || type == NULL) {
		printf("Incorrect name and or type pointer\n");

		return NULL;
	}

	Restaurant * restPtr = malloc(sizeof(Restaurant));
	restPtr->name = malloc(sizeof(char)*255);
	restPtr->type = malloc(sizeof(char)*255);

	strcpy(restPtr->name, name);
	strcpy(restPtr->type, type);
	restPtr->rating = rating;

	return restPtr;
}

void destroyRestaurant (void * toDestroy) {
	Restaurant * restPtr = (Restaurant *)toDestroy;
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

void printData(void * tree, int shift) {
	Restaurant * restPtr = (Restaurant*) getRootData((Tree*)tree);

	if (restPtr == NULL) {
		printf("ERROR\n");
	}

	int cury,curx;
	getyx(stdscr, cury, curx);
	char word[255];
	sprintf(word, "%s %d",restPtr->name, restPtr->rating);
	move(cury,curx + shift);
	
	printw("%s", word);

	refresh();

	return;
}

void simplePrint (void * data) {
	Restaurant * restPtr = (Restaurant*) data;

	if (data == NULL) {
		printf("ERROR\n");
	}

	printf("%s %d\n",restPtr->name, restPtr->rating);

	return;
}
