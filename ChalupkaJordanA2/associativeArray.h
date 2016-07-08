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

AArray * createAAray (int size);
int hashIndex (AArray * array, void * key);
int hashInsert (AArray * array, void * key, void * value);
void * hashLook (AArray * array, void * key);
void * hashRemove (AArray * array, void * key);
void destroyAArray (AArray * array);
void printAArray (AArray * array);
void printCollisions (int * collision, int size);

#endif