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
#include "stackTest.h"

int main (void) {
    int numErrors;
    numErrors = testFunctions();

    if (numErrors == 0) {
        printf("All function tests succesful\n");
    }
    else {
        printf("%d function tests unsuccesful\n", numErrors);
    }
    if (testNull()) {
        printf("All null function tests succesful\n");
    }else {
        printf("ERROR: Not all functions passed null test\n");
    }
    return 0;
}

/*Test the stackADT function*/
int testFunctions (void) {
    printf("Testing all functions for correctness\n");
    int testErrors = 0;
    testErrors += testCreate();
    testErrors += testPush();
    testErrors += testPop();
    testErrors += testDestroy();
    testErrors += testIsEmpty();
    testErrors += testPeek();

    return testErrors;
}

int testNull (void) {
    printf("Testing all functions with NULL\n");
    stackPeek(NULL);
    correctOutput("stackPeek");
    stackDestroy(NULL);
    correctOutput("stackDestroy");
    stackIsEmpty(NULL);
    correctOutput("stackIsEmpty");
    stackPush(NULL,NULL);
    correctOutput("stackPush");
    stackPop(NULL);
    correctOutput("stackPop");
    return 1;
}
/*Function used for correct test responses*/
int correctOutput (char * funcName) {
    printf("%s: \tCORRECT\n\n", funcName);
    return 0;
}

/*Function used for incorrect test responses*/
int incorrectOutput (char * funcName) {
    printf("%s: \tINCORREECT\n\n", funcName);
    return 1;
}

/*Test the stackCreate function*/
int testCreate (void) {
    char * funcName = "stackCreate";
    printf("Testing testCreate\n");
    printf("Creating stack ...\n");
    Stack *s = stackCreate();
    int correct = 0;
    if (s != NULL) {
        correct++;
    }
    stackDestroy(&s);
    if (correct == 1) {
        return correctOutput(funcName);
    }
    return incorrectOutput(funcName);
}

/*Test the stackPush function*/
int testPush (void) {
    printf("Testing testPush\n");
    char * funcName = "stackPush";
    Stack *s = stackCreate();
    
    int numPtr = 5;
    char charPtr = 'c';
    char *stringPtr = malloc(sizeof(char)*15);
    strcpy(stringPtr, "string");

    printf("Pushing int onto stack ...\n");
    stackPush(s, &numPtr);
    printf("Pushing char onto stack ...\n");
    stackPush(s, &charPtr);
    printf("Pushing string onto stack ...\n");
    stackPush(s, &stringPtr);

    int correct;
    printf("Checking if top of stack is string ...\n");
    if (strcmp(*(char**)stackPeek(s),"string") == 0) {
        correct = 1;
    }
    else correct = 0;
    free(stringPtr);
    stackDestroy(&s);

    if (correct) {
        return correctOutput(funcName);
    }
    return incorrectOutput(funcName);
}

/*Test the stackPop function*/
int testPop (void) {
    printf("Testing testPop\n");
    char * funcName = "testPop";
    Stack *s = stackCreate();
    
    int numPtr = 5;
    char charPtr = 'c';
    char *stringPtr = malloc(sizeof(char)*15);
    strcpy(stringPtr, "string");

    stackPush(s, &numPtr);
    stackPush(s, &charPtr);
    stackPush(s, &stringPtr);

    int correct = 0;
    printf("Popping string from stack ...\n");
    stackPop(s);
    printf("Checking if top of stack is character ...\n");
    if (*(char*)stackPeek(s) == 'c') {
        correct += 1;
    }
    else correct += -999;
    stackPop(s);
    printf("Popping char from stack ...\n");
    printf("Checking if top of stack is int ...\n");
    if (*(int*)stackPop(s) == 5) {
        correct += 1;
    }

    stackPop(s);
    free(stringPtr);
    stackDestroy(&s);

    if (correct == 2) {
        return correctOutput(funcName);
    }
    return incorrectOutput(funcName);
}

/*Test the stackDestroy function*/
int testDestroy (void) {
    printf("Testing testDestroy\n");
    char * funcName = "testDestroy";
    Stack *s = stackCreate();
    
    int numPtr = 5;
    char charPtr = 'c';
    char *stringPtr = malloc(sizeof(char)*15);
    strcpy(stringPtr, "string");

    printf("Pushing int, char, and string onto stack ...\n");
    stackPush(s, &numPtr);
    stackPush(s, &charPtr);
    stackPush(s, &stringPtr);
    printf("Destroying stack ...\n");
    stackDestroy (&s);
    printf("Destroying destroyed stack ...\n");
    stackDestroy (&s);
    free(stringPtr);
    printf("Checking that destroyed stack is NULL ...\n");
    if (s == NULL) {
        return correctOutput(funcName);
    }
    return incorrectOutput(funcName);   
}

/*Test the stackIsEmpty function*/
int testIsEmpty (void) {
    printf("Testing testIsEmpty\n");
    char * funcName = "testIsEmpty";
    Stack *s = stackCreate();

    int numPtr = 5;

    int correct = 0;
    printf("Checking if newly created stack is empty ...\n");
    if (stackIsEmpty(s)) {
        correct += 1;
    }   else correct += -999;

    printf("Pushing int onto stack ...\n");
    stackPush(s, &numPtr);

    printf("Checking if stack is empty ...\n");
    if (!stackIsEmpty(s)) {
        correct += 1;
    }   else correct += -999;
    printf("Popping stack ...\n");
    stackPop(s);
    printf("Checking if stack is empty ...\n");
    if (stackIsEmpty(s)) {
        correct += 1;
    }   else correct += -999;

    stackDestroy(&s);

    if (correct == 3) {
        return correctOutput(funcName);
    }
    return incorrectOutput(funcName);
}

/*Test the stackPeek function*/
int testPeek (void) {
    printf("Testing testPeek\n");
    char * funcName = "testPop";
    Stack *s = stackCreate();
    
    int numPtr = 5;

    char charPtr = 'c';
    printf("Pushing int onto stack ...\n");
    stackPush(s, &numPtr);
    int correct = 0;
    printf("Checking if top of stack is int ...\n");
    if (*(int*)stackPeek(s) == 5) {
        correct += 1;
    } else correct += -999;
    printf("Pushing char onto stack ...\n");
    stackPush(s, &charPtr);
    printf("Checking if top of stack is char ...\n");
    if (*(char*)stackPeek(s) == 'c') {
        correct += 1;
    } else correct += -999;

    stackDestroy(&s);

    if (correct == 2) {
        return correctOutput(funcName);
    }
    return incorrectOutput(funcName);
}
