// Jordan Chalupka 0928258

#ifndef __JCHALUPK_SORTING__
#define __JCHALUPK_SORTING__
#include <stdio.h>

/*
Swap two integers in memory.
Pre: None.
Post: The integers are swapped.
*/
void swap (int * x, int * y);

/*
Perform a standard bubble sort on the integer array.
Pre: None.
Post: The integer array is sorted.
*/
void bubbleSort (int a[], int n);

/*
Perform a recursive bubble sort on the integer array.
Pre: None.
Post: The integer array is sorted.
*/
void rbubbleSort (int a[], int n);

#endif
