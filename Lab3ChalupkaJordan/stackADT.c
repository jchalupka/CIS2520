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


void * stack_peek (stack * head) {
	return head->data;
}

void stack_destroy (stack ** head) {
	for (int i = 0; i < 10; i++) {
		stack_pop(head);
	}
	free(*head);
	printf("\n");
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
}

int main (void) {
	stack *s = stack_create();
	check_empty(s);
	int *tmp;
	printf("Pushing...\n");
	for (int i = 0; i < 10; i++) {
		tmp = malloc(sizeof(*tmp));
		*tmp = i;
		stack_push(&s, tmp);
		// Create function to view int, string, etc
		printf("%d ",*(int*)stack_peek(s));
	}
	printf("\n");
	check_empty(s);
	stack_destroy(&s);

	check_empty(s);
	char * word;
	word = malloc(sizeof(char)*15);
	stack_push(&s, word);
	strcpy(word,"Hello");
	check_empty(s);
	printf("%s\n", (char*)stack_peek(s));
	free(word);

}
