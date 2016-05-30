#include <stdio.h>
#include "stackADT.h"

int correctOutput (char * funcName) {
	printf("%s: CORRECT\n", funcName);
	return 0;
}

int incorrectOutput (char * funcName) {
	printf("%s: INCORREECT\n", funcName);
	return 1;
}

int test_create () {
	char * funcName = "stack_create";
	stack *s = stack_create();
	if (s != NULL) {
		return correctOutput(funcName);
	}
	return incorrectOutput(funcName);
}

int test_push () {
	stack *s = stack_create();
	int * numPtr = malloc(sizeof(*numPtr));
	*numPtr = 5;

	char * charPtr = malloc(sizeof(*charPtr));
	*charPtr = 'c';


	char ** stringPtr = malloc(sizeof(char*));
	*stringPtr = malloc(sizeof(char)*15);
	strcpy(*stringPtr, "string");


	stack_push(&s, numPtr);
	stack_push(&s, charPtr);
	stack_push(&s, stringPtr);

	if (strcmp(*(char**)s->data,"string") == 0) {
		return 0;
	}

	stack_destroy(&s);
	return 1;
}

int test_pop () {

	return 0;
}

int test_destroy () {
	
	return 0;
}

int test_isEmpty () {

	return 0;
}

int test_peek () {

	return 0;
}

int test_functions () {
	int testErrors = 0;
	testErrors += test_create();
	testErrors += test_push();
	testErrors += test_pop();
	testErrors += test_destroy();
	testErrors += test_isEmpty();
	testErrors += test_peek();

	return testErrors;
}

int main (void) {
	int numErrors;
	numErrors = test_functions();

	if (numErrors == 0) {
		printf("All function tests succesful\n");
	}
	else {
		printf("%d function tests unsuccesful\n", numErrors);
	}
    return 0;
}
