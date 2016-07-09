/*
Jordan Chalupka 0928258
*/
#ifndef __ASSOCIATIVEARRAY__
#define __ASSOCIATIVEARRAY__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "ListADT.h"
#include "fileReader.h"

typedef struct AArray {
	int size;
	void ** key;
	void ** data;
} AArray;

/*
Creates an associated array ADT
Pre: Desired size is known
Post: AArray is created
*/
AArray * createAAray (int size);

/*
Gets the hash index for the key
Pre: AArray is created
Post: Returns the hash index for the specified key
*/
int hashIndex (AArray * array, void * key);

/*
Insert a value into the AArray
Pre: AAray is created
Post: Value is added to the hashtable with the key
Returns the position in the hashtable of the insert
*/
int hashInsert (AArray * array, void * key, void * value);

/*
Looks at the value in the hash table for the location of a key
Pre: Hash is created and the key has inserted a value into the hash table
Post: The value is returned if it has been stored, or NULL is returned
*/
void * hashLook (AArray * array, void * key);

/*
Remove a value from the hash table
Pre: AArray is created
Post: Value at index of key is removed (or nothing is removed if nothing was there).
*/
void * hashRemove (AArray * array, void * key);

/*
Destroy an AArray
Pre: AArray is created.
Post: AArray is destroyed and memory associated with AArray is free'd.
*/
void destroyAArray (AArray * array);

/*
Print the AArray (this works for strings in value only)
Pre: AArray is created
Post: Entire AArray is printed for the user to see
*/
void printAArray (AArray * array);

/*
Prints the collisions the hash table encountered
Pre: An array of the collisions is needed.
Post: The number of collisions is known to the user.
*/
void printCollisions (int * collision, int size);

#endif
