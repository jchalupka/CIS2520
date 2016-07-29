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
	if (toDestroy == NULL) {
		printf("Pointer cannot be NULL\n");

		return;
	}
	Restaurant * restPtr = (Restaurant *)toDestroy;
	free(restPtr->name);
	free(restPtr->type);
	free(restPtr);

	toDestroy = NULL;

	return;
}

int compareName (void * data1, void * data2) {
	Restaurant * restPtr1 = (Restaurant*) data1;
	Restaurant * restPtr2 = (Restaurant*) data2;

	if (data1 == NULL || data2 == NULL) {
		printf("Error, NULL value entered\n");

		return -1;
	}

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

	if (!(data1 && data2)) {
		printf("Error, NULL value entered\n");

		return -1;
	}

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

	if (!(data1 && data2)) {
		printf("Error, NULL value entered\n");

		return -1;
	}


	char * type1 = restPtr1->type;
	char * type2 = restPtr2->type;

	int order = strcmp(type1,type2);
	// At this point, it is known that the names, and ratings are the same.
	// So we can simply return the order (If the order is zero, they are the same restaurants)
	
	return order;	
}

void simplePrint (void * data) {
	Restaurant * restPtr = (Restaurant*) data;

	if (data == NULL) {
		printf("ERROR\n");
	}

	printf("Name: %15s, Type: %15s, Rating: %15d\n",restPtr->name, restPtr->type, restPtr->rating);

	return;
}
