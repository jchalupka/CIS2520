/*
    Jordan Chalupka
    0928258

    This file contains a generic List ADT, made using a Linked List method.
*/
#include "ListADT.h"

/*Return a list ADT*/
Node * createList (void) {
    Node * list;
    list = malloc(sizeof(Node));
    if (list == NULL) {
        printf("An error has occured, not enough memory available.\n");
        return NULL;
    }
    list->data = NULL;
    list->next = NULL;


    return list;
}

/*Destory the list, freeing all of the associated memory*/
void destroyList (Node ** theList) {
    if ((theList == NULL) || (*theList == NULL)) {
        return;
    }
    while (*theList != NULL) {
        Node * temp;
        temp = *theList;
        *theList = (*theList)->next;
        if (temp->data != NULL) {
            free(*(temp->data));
            free(temp->data);
        }
        free(temp); 
    }
    *theList = NULL;

    return;
}

/*Initialize a node, mallocing all of the needed memory*/
Node * initNode (void * value) {
    Node * newNode = malloc(sizeof(Node));
    void ** dataPtr = malloc(sizeof(value));
    *dataPtr = value;
    newNode->data = dataPtr;
    
    return newNode;
}

void addFront (Node * theList, void * value) {
    if (!isInit(theList)) {
        return;
    }
    Node * newNode = initNode(value);
    newNode->next = theList->next;
    theList->next = newNode;

    return;
}

/*Get the value of the front of the list*/
void * getFrontValue (Node * theList) {
    if (!isInit(theList)) {
        return NULL;
    }
    Node * firstNode;
    firstNode = theList->next;
    if (firstNode == NULL) {
        return NULL;
    }
    void ** frontValue;
    frontValue = firstNode->data;

    return *frontValue;
}

/*Get the length of the list*/
int getLength (Node * theList) {
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
void printList (Node * theList) {
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
void removeFront (Node * theList) {
    if (!isInit(theList)) {
        return;
    }

    if (theList->next == NULL) {
        return;
    }

    Node * firstNode = theList->next;
    theList->next = firstNode->next;
    free(*(firstNode->data));
    free(firstNode->data);
    free(firstNode);
    firstNode = NULL;

    return;
}

/*Check if the node is initialized*/
int isInit(Node * theList) {
    if (theList == NULL) {
        return 0;
    }
    return 1;
}

int listIsEmpty (Node * theList) {
    if ((theList == NULL)||(theList->next == NULL)) {
        return 1;
    }

    return 0;
}
