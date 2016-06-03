/*
    Jordan Chalupka
    0928258
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
	stack *s = stack_create();
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
	stack *s = stack_create();
	int * numPtr = malloc(sizeof(*numPtr));
	*numPtr = 5;

	char * charPtr = malloc(sizeof(*charPtr));
	*charPtr = 'c';

	char ** stringPtr = malloc(sizeof(char*));
	*stringPtr = malloc(sizeof(char)*15);
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
	free(numPtr);
	free(charPtr);
	free(*stringPtr);
	free(stringPtr);


	if (correct) {
		return correctOutput(funcName);
	}
	return incorrectOutput(funcName);
}

/*Test the stack_pop function*/
int test_pop (void) {
	char * funcName = "test_pop";
	stack *s = stack_create();
	
	int * numPtr = malloc(sizeof(*numPtr));
	*numPtr = 5;

	char * charPtr = malloc(sizeof(*charPtr));
	*charPtr = 'c';

	char ** stringPtr = malloc(sizeof(char*));
	*stringPtr = malloc(sizeof(char)*15);
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
	free(numPtr);
	free(charPtr);
	free(*stringPtr);
	free(stringPtr);
	if (correct == 2) {
		return correctOutput(funcName);
	}
	return incorrectOutput(funcName);
}

/*Test the stack_destroy function*/
int test_destroy (void) {
	char * funcName = "test_destroy";
	stack *s = stack_create();
	
	int * numPtr = malloc(sizeof(*numPtr));
	*numPtr = 5;

	char * charPtr = malloc(sizeof(*charPtr));
	*charPtr = 'c';

	char ** stringPtr = malloc(sizeof(char*));
	*stringPtr = malloc(sizeof(char)*15);
	strcpy(*stringPtr, "string");


	stack_push(s, numPtr);
	stack_push(s, charPtr);
	stack_push(s, stringPtr);

	stack_destroy (&s);
	stack_destroy (&s);
	
	free(numPtr);
	free(charPtr);
	free(*stringPtr);
	free(stringPtr);

	if (s == NULL) {
		return correctOutput(funcName);
	}
	return incorrectOutput(funcName);	
}

/*Test the stack_isEmpty function*/
int test_isEmpty (void) {
	char * funcName = "test_isEmpty";
	stack *s = stack_create();

	int * numPtr = malloc(sizeof(*numPtr));
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
	free(numPtr);


	if (correct == 3) {
		return correctOutput(funcName);
	}
	return incorrectOutput(funcName);
}

/*Test the stack_peek function*/
int test_peek (void) {
	char * funcName = "test_pop";
	stack *s = stack_create();
	
	int * numPtr = malloc(sizeof(*numPtr));
	*numPtr = 5;

	char * charPtr = malloc(sizeof(*charPtr));
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
	free(numPtr);
	free(charPtr);
	if (correct == 2) {
		return correctOutput(funcName);
	}
	return incorrectOutput(funcName);
}
