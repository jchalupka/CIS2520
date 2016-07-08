// Jordan Chalupka 0928258

#ifndef __JCHALUPKA_TESTING__
#define __JCHALUPKA_TESTING__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sorting.h"

// Function pointer for sorting functions
typedef void (sortFunction)(int a[], int n);

/*
Creates an array of integers based on the min, max, and size parameters.
Pre: Random number generator is seeded.
Post: Array is created with size number of randomly generated integers all within the min and max bounds.
*/
int * createArray (int min, int max, int size);

/*
Prints out an array of integers.
Pre: Array contains integers.
Post: Integers are printed.
*/
void printArray (int * array, int size);

/*
Calculate the elapsed time it takes to run the sorting functions.
Pre: Array contains unsorted integers.
Post: Time in milliseconds is returned.
*/
float elapsedTime (sortFunction function, int * array, int size);

/*
Given the dimensions of an array will perform the testing of the two sorting functions on the array.
Pre: None.
Post: The array is tested and performance is printed for the user.
*/
void testSorting (int min, int max, int size);

#endif
