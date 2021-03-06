/*
    Jordan Chalupka
    0928258
*/
#ifndef __JCHALUPKA_STACKADT__
#define __JCHALUPKA_STACKADT__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListADT.h"

typedef Node Stack;

/*
Push a node onto the stack ADT
Pre: An initialized stack ADT
Post: The stack's head is now the data pointer
*/
void stackPush (Stack * top, void * data);

/*
Pop a node off of the stack ADT
Pre: An initialized stack ADT
Post: The top node of the stack is free'd (if no nodes then the stack remains the same)
and the data of the original top node is returned to the user.
*/
void * stackPop (Stack * top);

/*
Initialize a new stack ADT
Pre: None
Post: A stack ADT is created and memory is malloced for it
*/
Stack * stackCreate (void);

/*
Free all of the memory on the stack ADT
Pre: An initialized stack ADT
Post: All memory is free'd that was used in the stack ADT
*/
void stackDestroy (Stack ** top);

/*
Check if the stack ADT is empty
Pre: An initialized stack ADT
Post: An integer is returned: 1 for empty, 0 for non empty
*/
int stackIsEmpty (Stack * top);

/*
Get the first node's data of the stack ADT
Pre: An initialized stack ADT with atleast one node
Post: Returns a pointer to the top node
*/
void * stackPeek (Stack * top);

#endif
