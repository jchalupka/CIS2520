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
Pre: None.
Post: Inputs are malloced and stored in restaurant struct.
*/
Restaurant * createRestaurant (char * name, char * type, int rating);

/*
Destory restaurant struct.
Pre: Restaurant struct is passed in to be destroyed.
Post: Restaurant struct is destroyed, and associated memory free'd.
*/
void destroyRestaurant (void * toDestroy);

/*
Compare names, returns > 0 if data1 comes before data2.
Pre: data1 and data2 are restaurant structs.
Post: Integer is returned determining the order.
*/
int compareName (void * data1, void * data2);

/*
Compare rating, returns > 0 if data1 comes before data2.
Pre: data1 and data2 are restaurant structs.
Post: Integer is returned determining the order.
*/
int compareRating (void * data1, void * data2);

/*
Compare type, returns > 0 if data1 comes before data2.
Pre: data1 and data2 are restaurant structs.
Post: Integer is returned determining the order.
*/
int compareType (void * data1, void * data2);

/*
Prints the data using ncurses.
Pre: Ncurses is initialized.
Post: Data is printed to the screen.
*/
void printData (void * tree, int shift);

/*
Prints the data using printf.
Pre: None.
Post: Data is printed to the screen.
*/
void simplePrint (void * data)

#endif
