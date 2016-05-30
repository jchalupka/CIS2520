#ifndef __JCHALUPKA_STACKADT__
#define __JCHALUPKA_STACKADT__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack {
	void * data;
	struct stack * next;
} stack;

void stack_push (stack ** head, void * data);
void stack_pop (stack ** head);
stack * stack_create (void);
void stack_destroy (stack ** head);
int stack_isEmpty (stack * head);
void * stack_peek (stack * head);

#endif