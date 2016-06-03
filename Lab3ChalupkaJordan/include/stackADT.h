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

typedef node stack;

void stack_push (stack * head, void * data);
/*
Pre: An initialized stack ADT
Post: The stack's head is now the data pointer
*/
void stack_pop (stack * head);
/*
Pre: An initialized stack ADT
Post: The top node of the stack is free'd (if no nodes then the stack remains the same)
*/
stack * stack_create (void);
/*
Pre: None
Post: A stack ADT is created and memory is malloced for it
*/
void stack_destroy (stack ** head);
/*
Pre: An initialized stack ADT
Post: All memory is free'd that was used in the stack ADT
*/
int stack_isEmpty (stack * head);
/*
Pre: An initialized stack ADT
Post: An integer is returned: 1 for empty, 0 for non empty
*/
void * stack_peek (stack * head);
/*
Pre: An initialized stack ADT with atleast one node
Post: Returns a pointer to the top node
*/

#endif
