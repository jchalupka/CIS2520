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
    printf("%s: \tCORRECT\n", funcName);
    return 0;
}

/*Function used for incorrect test responses*/
int incorrectOutput (char * funcName) {
    printf("%s: \tINCORREECT\n", funcName);
    return 1;
}

/*Test the stackCreate function*/
int testCreate (void) {
    char * funcName = "stackCreate";
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
    char * funcName = "stackPush";
    Stack *s = stackCreate();
    
    int numPtr = 5;
    char charPtr = 'c';
    char *stringPtr = malloc(sizeof(char)*15);
    strcpy(stringPtr, "string");

    stackPush(s, &numPtr);
    stackPush(s, &charPtr);
    stackPush(s, &stringPtr);

    int correct;
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
    stackPop(s);
    if (*(char*)stackPeek(s) == 'c') {
        correct += 1;
    }
    else correct += -999;
    stackPop(s);
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
    char * funcName = "testDestroy";
    Stack *s = stackCreate();
    
    int numPtr = 5;
    char charPtr = 'c';
    char *stringPtr = malloc(sizeof(char)*15);
    strcpy(stringPtr, "string");


    stackPush(s, &numPtr);
    stackPush(s, &charPtr);
    stackPush(s, &stringPtr);

    stackDestroy (&s);
    stackDestroy (&s);
    free(stringPtr);
    if (s == NULL) {
        return correctOutput(funcName);
    }
    return incorrectOutput(funcName);   
}

/*Test the stackIsEmpty function*/
int testIsEmpty (void) {
    char * funcName = "testIsEmpty";
    Stack *s = stackCreate();

    int numPtr = 5;

    int correct = 0;

    if (stackIsEmpty(s)) {
        correct += 1;
    }   else correct += -999;

    stackPush(s, &numPtr);

    if (!stackIsEmpty(s)) {
        correct += 1;
    }   else correct += -999;

    stackPop(s);

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
    char * funcName = "testPop";
    Stack *s = stackCreate();
    
    int numPtr = 5;

    char charPtr = 'c';

    stackPush(s, &numPtr);
    int correct = 0;
    if (*(int*)stackPeek(s) == 5) {
        correct += 1;
    } else correct += -999;
    
    stackPush(s, &charPtr);
    if (*(char*)stackPeek(s) == 'c') {
        correct += 1;
    } else correct += -999;

    stackDestroy(&s);

    if (correct == 2) {
        return correctOutput(funcName);
    }
    return incorrectOutput(funcName);
}
