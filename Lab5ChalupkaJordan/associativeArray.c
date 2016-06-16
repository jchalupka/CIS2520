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

int hashIndex (AArray * array, void * key) {
	//int i = atoi(key) * 33 % array->size;
	int sum = 0;
	for (int n = 0; n < strlen(key); n++) {
		sum += abs(((int*)key)[n]) * 33;
	}
	sum = abs(sum % array->size);
	printf("%d\n", sum);
	return sum;
}

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
	array->key[i] = key;
	array->data[i] = value;

	return;
}

void * hashLook (AArray * array, void * key) {
	int i = hashIndex(array, key);
	void * temp = array->data[i];
	if (strcmp(temp,key) == 0) {
		return temp;
	} else return "key not found";
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
	int * intPtr = malloc(sizeof(int));
	*intPtr = 9;
	hashInsert(array, "A","A Data");
	hashInsert(array, "B","B Data");
	hashInsert(array, "C","C Data");
	hashInsert(array, "D", "D Data");
	hashInsert(array, "E", "E Data");
	hashInsert(array, "F", "F Data");
	
	//hashRemove(array, "Apple");
	//printf("Boom: %s\n", hashLook(array, "Boom"));
	printf("Remove Boom: %s\n", hashRemove(array, "Boom"));
	printf("\n");
	printAArray(array);
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