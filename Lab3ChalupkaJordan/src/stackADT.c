/*
    Jordan Chalupka
    0928258

    This file contains a generic Stack ADT, made using a Linked List ADT
*/
#include "stackADT.h"

/*Get the top value of the stack*/
void * stack_peek (Stack * top) {
	void * data = getFrontValue(top);
	return data;
}

/*Null the stack and free all of the memory*/
void stack_destroy (Stack ** top) {
	destroyList(top);
	return;
}

/*Create a new stack*/
Stack * stack_create (void) {
	return createList();
}

/*Check if the stack is empty*/
int stack_isEmpty (Stack * top) {
	return listIsEmpty(top);
}

/*Push a new item onto the stack*/
void stack_push (Stack * top, void * data) {
	addFront(top, data);

	return;
}

/*Remove the top item on the stack*/
void stack_pop (Stack * top) {
	removeFront(top);

	return;
}

/*Print a message if the stack is empty*/
void check_empty(Stack * s) {
	if (stack_isEmpty(s)) {
		printf("stack empty\n");
	}

	return;
}
