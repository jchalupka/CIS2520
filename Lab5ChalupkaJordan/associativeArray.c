#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
		sum += abs(((int*)key)[n]) * 33;
	}
	sum = abs(sum % array->size);
	return sum;
}

// Insert a key into the hash table and associate it with some value
void hashInsert (AArray * array, void * key, void * value) {
	int i = hashIndex(array, key);
	if (array->key[i] != NULL) {
		printf("COLLISION! %d %s %s\n",i,key,value);
		int counter = 0;
		while (array->key[i] != NULL) {
			i = (i+1) % array->size;
			if (counter == array->size) {
				printf("Full!\n");
				return;
			}
			counter ++;		
		}
	}
	//printf("%d Key: %s Data: %s\n",i, key, value);
	array->key[i] = key;
	array->data[i] = value;

	return;
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

int main (void) {
	AArray * array = createAAray(10);
	//hashInsert(array, "Hello", "World");
	char * A = "Apple";
	char * B = "Apples";
	char * C = "Carrot";
	char * D = "Dubstep";
	char * E = "Elephant";
	char * F = "Fruit";
	char * Dog = "DOG";
	hashInsert(array, A,"Pineapple");
	hashInsert(array, B,B);
	hashInsert(array, "Dog",Dog);
	hashInsert(array, D,D);
	hashInsert(array, E, E);
	hashInsert(array, F, F);

	//hashRemove(array, "Apple");
	//printf("Boom: %s\n", hashLook(array, "Boom"));
	printf("Remove Apple: %s\n", hashRemove(array, "Apple"));
	printf("This is apple: %s\n",hashLook(array,"Apple"));
	//printAArray(array);
	destroyAArray(array);
	//char * phrase = (char*) hashRemove(array,"Apple");
	//printf("%s\n", hashLook(array, "Hello"));

	return 0;
}


/*
insertAArray

removeAArray

lookupAArray

updateAArray
*/