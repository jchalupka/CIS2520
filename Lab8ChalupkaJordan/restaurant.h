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
void destroyRestaurant (Restaurant * toDestroy);

// Compare by name
int compareName (void * data1, void * data2);

// Compare by rating
int compareOrder (void * data1, void * data2);

#endif
