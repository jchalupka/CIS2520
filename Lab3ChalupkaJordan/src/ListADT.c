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
    list->data = NULL;
    list->next = NULL;


    return list;
}

/*Destory the list, freeing all of the associated memory*/
void destroyList (node ** theList) {
    if (!isInit(*theList)) {
        return;
    }
    while (*theList != NULL) {
        node * temp;
        temp = *theList;
        *theList = (*theList)->next;
        if (temp->data != NULL) {
            free(temp->data);
        }
        free(temp); 
    }
    *theList = NULL;

    return;
}

/*Initialize a node, mallocing all of the needed memory*/
node * initNode (void * value) {
    node * newNode = malloc(sizeof(node));
    void ** dataPtr = malloc(sizeof(*value));
    *dataPtr = value;
    newNode->data = dataPtr;
    
    return newNode;
}

void addFront (node * theList, void * value) {
    if (!isInit(theList)) {
        return;
    }
    node * newNode = initNode(value);
    newNode->next = theList->next;
    theList->next = newNode;

    return;
}

/*Get the value of the front of the list*/
void * getFrontValue (node * theList) {
    if (!isInit(theList)) {
        return NULL;
    }
    node * firstNode;
    firstNode = theList->next;
    void * frontValue;
    frontValue = firstNode->data;

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
        printf("[%d]",*(int*)theList->data);
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
    free(firstNode);
    firstNode = NULL;


    return;
}

/*Check if the node is initialized*/
int isInit(node * theList) {
    if (theList == NULL) {
        return 0;
    }
    return 1;
}