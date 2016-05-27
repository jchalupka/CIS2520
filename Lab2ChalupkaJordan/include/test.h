/*
    Jordan Chalupka
    0928258
*/
#ifndef __TEST__
#define __TEST__

#include <stdio.h>
#include "ListADT.h"

void testAddFront(int num, node * list);
/*
Pre: Test will reveal the correctness of the addFront function
Post: None
*/
node * testCreate(void);
/*
Pre: Test will reveal the correctness of the createList function
Post: None
*/
void testGetFrontValue(node * list);
/*
Pre: Test will reveal the correctness of the getFrontValue function
Post: None
*/
void testGetLength(int length, node * list);
/*
Pre: Test will reveal the correctness of the getLength function
Post: None
*/
void testPrintList(char * strList, node * list);
/*
Pre: Test will reveal the correctness of the printList function
Post: None
*/
void testRemoveFront(node * list);
/*
Pre: Test will reveal the correctness of the removeFront function
Post: None
*/
void testAddFour(node * list);
/*
Pre: Test will reveal the correctness of the addFour function
Post: None
*/

#endif
