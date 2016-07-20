// Jordan Chalupka 0928258

#ifndef __JCHALUPKA_RESTAURANT__
#define __JCHALUPKA_RESTAURANT__

#include "fileIO.h"
#include "treeInterface.h"

// Struct for storing information about restaurants
typedef struct restaurant {
	char * name;
	char * type;
	int rating;
} Restaurant;

// Functionality for Restaurant struct

// Create
Restaurant * createRestaurant (char * name, char * type, int rating);

// Destroy
void destroyRestaurant (void * toDestroy);

// Compare by name
int compareName (void * data1, void * data2);

// Compare by rating
int compareRating (void * data1, void * data2);

// Compare by type
int compareType (void * data1, void * data2);

void printData (void * data);

#endif
