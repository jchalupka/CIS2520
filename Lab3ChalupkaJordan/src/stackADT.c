#include "stackADT.h"

void * stack_peek (stack * head) {
	void * data = head->data;
	return data;
}

void stack_destroy (stack ** head) {
	while (*head != NULL) {
		stack_pop(head);
	}
	*head = NULL;
	printf("\n");

	return;
}

stack * stack_create (void) {
	stack *s = NULL;
	return s;
}

int stack_isEmpty (stack * head) {
	if (head == NULL) {
		return 1;
	}
	return 0;
}

void stack_push (stack ** head, void * data) {
	stack * node = malloc(sizeof(*node));
	if (node == NULL) {
		fputs("Not enough memory",stderr);
		abort();
	}
	node->data = data;
	node->next = *head;

	*head = node;

	return;
}

void stack_pop (stack ** head) {
	stack * top;
	void * value;
	top = *head;
	value = top->data;
	*head = top->next;
	
	free(value);
	free(top);

	return;
}

void check_empty(stack * s) {
	if (stack_isEmpty(s)) {
		printf("stack empty\n");
	}

	return;
}
