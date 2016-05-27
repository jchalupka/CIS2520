/*
    Jordan Chalupka
    0928258
*/
#ifndef __TEST__
#define __TEST__

#include <stdio.h>
#include "ListADT.h"

int testAddFront(int num, node * list);
/*
Pre: Test will reveal the correctness of the addFront function
Post: None
*/
node * testCreate(void);
/*
Pre: Test will reveal the correctness of the createList function
Post: None
*/
int testGetFrontValue(node * list);
/*
Pre: Test will reveal the correctness of the getFrontValue function
Post: None
*/
int testGetLength(int length, node * list);
/*
Pre: Test will reveal the correctness of the getLength function
Post: None
*/
int testPrintList(char * strList, node * list);
/*
Pre: Test will reveal the correctness of the printList function
Post: None
*/
int testRemoveFront(node * list);
/*
Pre: Test will reveal the correctness of the removeFront function
Post: None
*/
int testAddFour(node * list);
/*
Pre: Test will reveal the correctness of the addFour function
Post: None
*/

#endif
