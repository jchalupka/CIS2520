// Jordan Chalupka 0928258

#ifndef __JCHALUPKA_RESTAURANT__
#define __JCHALUPKA_RESTAURANT__


#include "fileIO.h"
#include "treeInterface.h"
#include "printTree.h"
#include <curses.h>

// Struct for storing information about restaurants
typedef struct restaurant {
	char * name;
	char * type;
	int rating;
} Restaurant;

// Functionality for Restaurant struct

/*
Create restourant struct and malloc associated members.
Pre:
Post
*/
Restaurant * createRestaurant (char * name, char * type, int rating);

/*

Pre:
Post
*/
void destroyRestaurant (void * toDestroy);

/*

Pre:
Post
*/
int compareName (void * data1, void * data2);

/*

Pre:
Post
*/
int compareRating (void * data1, void * data2);

/*

Pre:
Post
*/
int compareType (void * data1, void * data2);

/*

Pre:
Post
*/
void printData (void * data, int shift);

#endif
