#include "stackADT.h"

void * stack_peek (stack * head) {
	void * data = getFrontValue(head);
	return data;
}

void stack_destroy (stack ** head) {
	destroyList(head);

	return;
}

stack * stack_create (void) {
	return createList();
}

int stack_isEmpty (stack * head) {
	if (head->next == NULL) {
		return 1;
	}
	return 0;
}

void stack_push (stack * head, void * data) {
	addFront(head, data);

	return;
}

void stack_pop (stack * head) {
	removeFront(head);

	return;
}

void check_empty(stack * s) {
	if (stack_isEmpty(s)) {
		printf("stack empty\n");
	}

	return;
}
