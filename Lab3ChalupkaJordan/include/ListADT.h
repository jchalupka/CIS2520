/*
    Jordan Chalupka
    0928258
*/
#ifndef __LIST_ADT__
#define __LIST_ADT__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct listNode {
    void * data;
    struct listNode * next;
} node;

node * createList (void);
/*
Pre: None
Post: An initialized list ADT
*/
void destroyList (node **);
/*
Pre: Initialized list ADT
Post: Memory freed for list ADT
*/
void addFront (node *, void *);
/*
Pre: Initialized list ADT
Post: New node added to front of list ADT, length increased by one
*/
void * getFrontValue (node *);
/*
Pre: Initialized list ADT
Post: None
*/
int getLength (node *);
/*
Pre: Initialized list ADT
Post: None
*/
void printList (node *);
/*
Pre: Initialized list ADT
Post: None
*/
void removeFront (node *);
/*
Pre: Initialized list ADT
Post: Node removed from the front of the list ADT, length decreased by one
*/
int isInit (node *);
/*
Pre: Pointer to initialized or uninitialized list ADT
Post: None
*/
#endif
