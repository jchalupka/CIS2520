/*
    Jordan Chalupka
    0928258

    This file contains a generic Stack ADT, made using a Linked List ADT
*/
#include "StackADT.h"

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

/*Remove the top item on the stack and return the value of that item*/
void * stack_pop (Stack * top) {
	void * data = getFrontValue(top);
    removeFront(top);

    return data;
}

/*Print a message if the stack is empty*/
void check_empty(Stack * s) {
    if (stack_isEmpty(s)) {
        printf("stack empty\n");
    }

    return;
}
