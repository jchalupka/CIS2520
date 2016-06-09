/*
    Jordan Chalupka
    0928258
*/
#ifndef __LIST_ADT__
#define __LIST_ADT__

#include <stdio.h>
#include <stdlib.h>

typedef struct listNode {
    void ** data;
    struct listNode * next;
} Node;

/*
Create a new List ADT
Pre: None
Post: An initialized list ADT
*/
Node * createList (void);

/*
Free all of the memory associated with the List ADT
Pre: Initialized list ADT
Post: Memory freed for list ADT
*/
void destroyList (Node **);

/*
Add a new node to the front of the List ADT
Pre: Initialized list ADT
Post: New node added to front of list ADT, length increased by one
*/
void addFront (Node *, void *);

/*
Get the first node value of the List ADT
Pre: Initialized list ADT
Post: None
*/
void * getFrontValue (Node *);

/*
Get the length of the List ADT
Pre: Initialized list ADT
Post: None
*/
int getLength (Node *);

/*
Print the list ADT
Pre: Initialized list ADT
Post: None
*/
void printList (Node *);

/*
Remove the front node of the list ADT
Pre: Initialized list ADT
Post: Node removed from the front of the list ADT, length decreased by one
*/
void removeFront (Node *);

/*
Check if the list ADT is initialized
Pre: Pointer to initialized or uninitialized list ADT
Post: None
*/
int isInit (Node *);

/*
Check if the list ADT is initialized and has atleast one node
Pre: Pointer to initialized or uninitialized list ADT
Post: None
*/
int listIsEmpty (Node * theList);

#endif
