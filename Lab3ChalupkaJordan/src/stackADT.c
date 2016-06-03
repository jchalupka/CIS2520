/*
    Jordan Chalupka
    0928258
*/
#include "stackADT.h"

/*Get the top value of the stack*/
void * stack_peek (stack * head) {
	void * data = getFrontValue(head);
	return data;
}

/*Null the stack and free all of the memory*/
void stack_destroy (stack ** head) {
	destroyList(head);
	return;
}

/*Create a new stack*/
stack * stack_create (void) {
	return createList();
}

/*Check if the stack is empty*/
int stack_isEmpty (stack * head) {
	if (head->next == NULL) {
		return 1;
	}
	return 0;
}

/*Push a new item onto the stack*/
void stack_push (stack * head, void * data) {
	addFront(head, data);

	return;
}

/*Remove the top item on the stack*/
void stack_pop (stack * head) {
	removeFront(head);

	return;
}

/*Print a message if the stack is empty*/
void check_empty(stack * s) {
	if (stack_isEmpty(s)) {
		printf("stack empty\n");
	}

	return;
}
