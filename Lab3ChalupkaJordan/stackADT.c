#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
	void * data;
	struct stack * next;
} stack;

void stack_push (stack ** head, void * data);
void stack_pop (stack ** head);

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
	top = *head;
	*head = top->next;
	free(top);

	return;
}

int main (void) {
	stack *s = NULL;
	int i, *tmp;

	printf("Pushing...\n");
	for (i = 0; i < 10; i++) {
		tmp = malloc(sizeof(*tmp));
		if (tmp == NULL) {
			fputs("Not enough memory", stderr);
			abort();
		}
		*tmp = i;
		printf("%d ",*tmp);
		stack_push(&s, tmp);
	}

	printf("\nPopping...\n");
	while (i-->0) {
		printf("%d ",*(int*)s->data);
		stack_pop(&s);
		free(tmp);
	}
	
	return 0;
}