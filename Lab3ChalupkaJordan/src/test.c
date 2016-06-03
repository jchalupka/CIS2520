/*
    Jordan Chalupka
    0928258

    This file contains the test program for the Stack ADT.
    Included in this file is tests for each individual function, as well as
    tests that use a combination of all of the functions.

    The test program is thorough as it tests each individual function in the ADT.
    This ensures each function is working properly.

    This program also tests each function for NULL, to ensure proper functionality even
    when the pre conditions for the functions are not met. (The use of uninitialized lists)

    Not included in this test file are tests completed using valgrind, showing that the
    same number of frees and allocs were made, and that no leaks are possible.
*/
#include "test.h"

int main (void) {
	int numErrors;
	numErrors = test_functions();

	if (numErrors == 0) {
		printf("All function tests succesful\n");
	}
	else {
		printf("%d function tests unsuccesful\n", numErrors);
	}
	//test_null();
    return 0;
}

/*Test the stackADT function*/
int test_functions (void) {
	int testErrors = 0;
	testErrors += test_create();
	testErrors += test_push();
	testErrors += test_pop();
	testErrors += test_destroy();
	testErrors += test_isEmpty();
	testErrors += test_peek();

	return testErrors;
}

int test_null (void) {
	printf("Testing all functions with NULL\n");
	stack_peek(NULL);
	correctOutput("stack_peek");
	stack_destroy(NULL);
	correctOutput("stack_destroy");
	stack_isEmpty(NULL);
	correctOutput("stack_isEmpty");

	return 1;
}
/*Function used for correct test responses*/
int correctOutput (char * funcName) {
	printf("%s: \tCORRECT\n", funcName);
	return 0;
}

/*Function used for incorrect test responses*/
int incorrectOutput (char * funcName) {
	printf("%s: \tINCORREECT\n", funcName);
	return 1;
}

/*Test the stack_create function*/
int test_create (void) {
	char * funcName = "stack_create";
	Stack *s = stack_create();
	int correct = 0;
	if (s != NULL) {
		correct++;
	}
	stack_destroy(&s);
	if (correct == 1) {
		return correctOutput(funcName);
	}
	return incorrectOutput(funcName);
}

/*Test the stack_push function*/
int test_push (void) {
	char * funcName = "stack_push";
	Stack *s = stack_create();
	int * numPtr;
	*numPtr = 5;

	char * charPtr;
	*charPtr = 'c';

	char ** stringPtr;
	strcpy(*stringPtr, "string");


	stack_push(s, numPtr);
	stack_push(s, charPtr);
	stack_push(s, stringPtr);

	int correct;
	if (strcmp(*(char**)stack_peek(s),"string") == 0) {
		correct = 1;
	}
	else correct = 0;
	stack_destroy(&s);

	if (correct) {
		return correctOutput(funcName);
	}
	return incorrectOutput(funcName);
}

/*Test the stack_pop function*/
int test_pop (void) {
	char * funcName = "test_pop";
	Stack *s = stack_create();
	
	int * numPtr;
	*numPtr = 5;

	char * charPtr;
	*charPtr = 'c';

	char ** stringPtr;
	strcpy(*stringPtr, "string");


	stack_push(s, numPtr);
	stack_push(s, charPtr);
	stack_push(s, stringPtr);

	stack_pop(s);
	int correct = 0;
	if (*(char*)stack_peek(s) == 'c') {
		correct += 1;
	}
	else correct += -999;

	stack_pop(s);
	if (*(int*)stack_peek(s) == 5) {
		correct += 1;
	}
	stack_pop(s);
	stack_pop(s);

	stack_destroy(&s);

	if (correct == 2) {
		return correctOutput(funcName);
	}
	return incorrectOutput(funcName);
}

/*Test the stack_destroy function*/
int test_destroy (void) {
	char * funcName = "test_destroy";
	Stack *s = stack_create();
	
	int * numPtr;
	*numPtr = 5;

	char * charPtr;
	*charPtr = 'c';

	char ** stringPtr;
	strcpy(*stringPtr, "string");


	stack_push(s, numPtr);
	stack_push(s, charPtr);
	stack_push(s, stringPtr);

	stack_destroy (&s);
	stack_destroy (&s);

	if (s == NULL) {
		return correctOutput(funcName);
	}
	return incorrectOutput(funcName);	
}

/*Test the stack_isEmpty function*/
int test_isEmpty (void) {
	char * funcName = "test_isEmpty";
	Stack *s = stack_create();

	int * numPtr;
	*numPtr = 5;

	int correct = 0;

	if (stack_isEmpty(s)) {
		correct += 1;
	}	else correct += -999;

	stack_push(s, numPtr);

	if (!stack_isEmpty(s)) {
		correct += 1;
	}	else correct += -999;

	stack_pop(s);

	if (stack_isEmpty(s)) {
		correct += 1;
	}	else correct += -999;

	stack_destroy(&s);

	if (correct == 3) {
		return correctOutput(funcName);
	}
	return incorrectOutput(funcName);
}

/*Test the stack_peek function*/
int test_peek (void) {
	char * funcName = "test_pop";
	Stack *s = stack_create();
	
	int * numPtr;
	*numPtr = 5;

	char * charPtr;
	*charPtr = 'c';

	stack_push(s, numPtr);
	int correct = 0;
	if (*(int*)stack_peek(s) == 5) {
		correct += 1;
	} else correct += -999;
	
	stack_push(s, charPtr);
	if (*(char*)stack_peek(s) == 'c') {
		correct += 1;
	} else correct += -999;

	stack_destroy(&s);

	if (correct == 2) {
		return correctOutput(funcName);
	}
	return incorrectOutput(funcName);
}
