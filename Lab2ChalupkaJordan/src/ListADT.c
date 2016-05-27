/*
	Jordan Chalupka
	0928258
*/
#include "ListADT.h"

/*Return a list ADT*/
node * createList (void) {
	node * list;
	list = malloc(sizeof(node));
	if (list == NULL) {
		printf("An error has occured, not enough memory available.\n");
		return NULL;
	}
	list->next = NULL;

	return list;
}

/*Destory the list, freeing all of the associated memory*/
void destroyList (node * theList) {
	if (!isInit(theList)) {
		return;
	}
	theList = theList->next;
	while (theList != NULL) {
		//printf("%d\n",(theList->next)->nodeValue);
		node * temp;
		temp = theList;
		theList = theList->next;

		free(temp);		
	}

	return;
}

/*Initialize a node, mallocing all of the needed memory*/
node * initNode (int value) {
	node * newNode = malloc(sizeof(node));
	newNode->nodeValue = value;
	return newNode;
}

void addFront (node * theList, int value) {
	if (!isInit(theList)) {
		return;
	}
	node * newNode = initNode(value);
	newNode->next = theList->next;
	theList->next = newNode;

	return;
}

/*Get the value of the front of the list*/
int getFrontValue (node * theList) {
	if (!isInit(theList)) {
		srand(time(NULL));
		return rand();
	}
	node * firstNode;
	firstNode = theList->next;
	int frontValue;
	frontValue = firstNode->nodeValue;

	return frontValue;
}

/*Get the length of the list*/
int getLength (node * theList) {
	if (!isInit(theList)) {
		return 0;
	}	
	int length = 0;
	while (theList->next != NULL) {
		length++;
		theList = theList->next;
	}

	return length;
}

/*Print out each of the nodes in the list*/
void printList (node * theList) {
	if (!isInit(theList)) {
		return;
	}
	printf("LIST: ");
	theList = theList->next;
	while (theList != NULL) {
		printf("[%d]",theList->nodeValue);
		theList = theList->next;
	}
	printf("\n");

	return;
}

/*Remove the first item in the list*/
void removeFront (node * theList) {
	if (!isInit(theList)) {
		return;
	}
	if (theList->next == NULL) {
		return;
	}
	node * firstNode = theList->next;
	theList->next = firstNode->next; 

	return;
}

/*Check if the node is initialized*/
int isInit(node * theList) {
	if (theList == NULL) {
		printf("Error: List uninitialized\n");
		return 0;
	}
	return 1;
}
