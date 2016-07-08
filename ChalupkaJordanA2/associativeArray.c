#include "associativeArray.h"

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
	}
	if (!array->size) array->size = array->size + 1; 
	sum = abs(sum % array->size);
	return sum;
}

// Insert a key into the hash table and associate it with some value
int hashInsert (AArray * array, void * key, void * value) {
	int i = hashIndex(array, key);
    
	if (array->key[i] != NULL) {
        addFront(array->data[i],value);
        addFront(array->key[i],key);
        
        return i;
    }

    array->key[i] = createList();
    addFront(array->key[i],key);
    array->data[i] = createList();
    addFront(array->data[i],value);

	return i;
}

// Look at the value associated with a key
void * hashLook (AArray * array, void * key) {
	//Fix none found
	int i = hashIndex(array, key);
	char * keyFound = getFrontValue(array->key[i]);

	if (keyFound == NULL) {
		return NULL;
	}

	int counter = 0;
	while (strcmp(keyFound,key) != 0 && getFrontValue(array->key[i])!= NULL) {
		array->key[i] = ((Node*)array->key[i])->next;
		array->data[i] = ((Node*)array->data[i])->next;
		keyFound = getFrontValue(array->key[i]);
		counter++;
		if (counter > getLength(array->key[i])) {
			return NULL;
		}
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
        
        int length = getLength(array->data[i]);
        void * data = array->data[i];
        void * key = array->key[i];
        printf("%d\n",i);
        for (int n = 0; n < length;n++){
        	char * lastName = ((ContactInfo*)getFrontValue(data))->lastName;
        	char * firstName = ((ContactInfo*)getFrontValue(data))->firstName;
            printf("Key: %s Data: %s, %s\n",getFrontValue(key),lastName,firstName);
            printf("%s %p\n",getFrontValue(key), getFrontValue(data));
            data = ((Node*)data)->next;
            key = ((Node*)key)->next;
        }
        printf("\n");
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
