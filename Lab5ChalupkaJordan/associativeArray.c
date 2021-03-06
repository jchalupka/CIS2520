#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "ListADT.h"

typedef struct AArray {
	int size;
	void ** key;
	void ** data;
} AArray;

// Create a new structure of the type AAray
AArray * createAAray (int size) {
	AArray * array = calloc(1,sizeof(AArray));
	array->key = calloc(size,sizeof(void *));
	array->data = calloc(size,sizeof(void *));
	array->size = size;

	return array;
}

// Get the hash index for a key
int hashIndex (AArray * array, void * key) {
	int sum = 0;
	for (int n = 0; n < strlen(key); n++) {
		sum += abs((char)((char*)key)[n])+(sum*33);
		//printf("%c\n", (char)((char*)key)[n]);
	}
	sum = abs(sum % array->size);
	return sum;
}

// Insert a key into the hash table and associate it with some value
int hashInsert (AArray * array, void * key, void * value) {
	int i = hashIndex(array, key);
	if (array->key[i] != NULL) {
		printf("COLLISION! %d %s %s\n",i,key,value);
        // Handle the collision here
        addFront(array->data[i],value);
	}
	//printf("%d Key: %s Data: %s\n",i, key, value);
	array->key[i] = malloc(sizeof(int));
	*(int*)array->key[i] = *(int*)key;
	array->data[i] = createList();
    addFront(array->data[i],value);

	return i;
}

// Look at the value associated with a key
void * hashLook (AArray * array, void * key) {
	int i = hashIndex(array, key);
	int counter = 0;
	while (array->key[i] == NULL || strcmp(array->key[i],key) != 0) {
		i = (i+1) % array->size;
		if (counter == array->size) {
				printf("Not found\n");
				return NULL;
		}
		counter++;
	} 

	return array->data[i];
}

void * hashRemove (AArray * array, void * key) {
	int i = hashIndex(array, key);
	if (strcmp(array->key[i],key) != 0) {
		printf("key not found\n");
		return NULL;
	}
	void * temp = array->data[i];

	array->key[i] = NULL;
	array->data[i] = NULL;


	return temp;
}

void destroyAArray (AArray * array) {
	free(array->key);
	free(array->data);
	free(array);
	return;
}

void printAArray (AArray * array) {
	for (int i = 0; i < array->size; i++) {
		printf("%d Key: %s Data: %s\n",i, array->key[i], array->data[i]);
	}

	return;
}

void printCollisions (int * collision, int size) {
	for (int i = 0; i < size; i++) {
		int collisions = collision[i];
		if (collisions) {
			collisions--;
		}
		printf("%d,%d\n", i, collisions);
	}
}

void random_string (char * string, int length) {
	int i;
	for (i = 0; i < length-1; ++i) {
		string[i] = rand() % (26) + 65;
	}
	string[length-1] = '\0';
	
	return;
}

void lowerCaseString (char * string, char * lowerString) {
	int i = 0;
	
	while (string[i] != '\0') {
		lowerString[i] = string[i] + 32;
		i++;
	}
	return;
}

int main (void) {
	int size = 250;
	AArray * array = createAAray(size);
	int * collision = calloc(size,sizeof(int));;
	
	
	// Purposely giving the random number generator the same seed each time
	// to show that that algorithm is consitantly giving the same output for
	// the same input.
	srand(5);
	// Add 300 items
	int pos = 0;
	for (int i = 0; i < 300; i++) { 
		char string[255], lowerString[255];
		random_string(string, 10);
		lowerCaseString(string,lowerString);
		pos = hashInsert(array,string,lowerString);
		++collision[pos];
	}
	//printCollisions(collision, size);
	//printAArray(array);
	
	return 0;
}


/*
insertAArray

removeAArray

lookupAArray

updateAArray
*/