/*
    Jordan Chalupka
    0928258
*/
#ifndef __JCHALUPKA__STACK_TEST__
#define __JCHALUPKA__STACK_TEST__

#include <stdio.h>
#include "StackADT.h"

/*
Gives correct test responce to user
Pre: The function test showed the function to be correct
Post: A message is given to the used reflecting the function's correctness
*/
int correctOutput (char * funcName);
/*
Gives incorrect test response to user
Pre: The function test showed the function to be incorrect 
Post: A message is given to the user reflecting the function is not correct
*/
int incorrectOutput (char * funcName);
/*
Test the stack_create function
Pre: None
Post: The correctness of the stack_create function is known
*/
int testCreate (void);
/*
Test the stack_push function
Pre: None
Post: The correctness of the stack_push function is known
*/
int testPush (void);
/*
Test the stack_pop function
Pre: None
Post: The correctness of the stack_pop function is known
*/
int testPop (void);
/*
Test the stack_destroy function
Pre: None
Post: The correctness of the stack_destroy function is known
*/
int testDestroy (void);
/*
Test the stack_isEmpty function
Pre: None
Post: The correctness of the stack_isEmpty function is known 
*/
int testIsEmpty (void);
/*
Test the stack_peek function
Pre: None
Post: The correctness of the stack_peek function is known
*/
int testPeek (void);
/*
Test the functions for the stack ADT
Pre: None
Post: The correctness of functions in the stack ADT is known
*/
int testFunctions (void);
/*
Test the functions for the stack ADT for NULL parameters
Pre: None
Post: The correctness of functions with NULL parameters is known
*/
int testNull(void);

#endif
