/*
    Jordan Chalupka
    0928258
*/
#ifndef __JCHALUPKA__STACK_TEST__
#define __JCHALUPKA__STACK_TEST__

#include <stdio.h>
#include "stackADT.h"

int correctOutput (char * funcName);
/*
Pre: The function test showed the function to be correct
Post: A message is given to the used reflecting the function's correctness
*/
int incorrectOutput (char * funcName);/*
Pre: The function test showed the function to be incorrect 
Post: A message is given to the user reflecting the function is not correct
*/
int test_create (void);
/*
Pre: None
Post: The correctness of the stack_create function is known
*/
int test_push (void);
/*
Pre: None
Post: The correctness of the stack_push function is known
*/
int test_pop (void);
/*
Pre: None
Post: The correctness of the stack_pop function is known
*/
int test_destroy (void);
/*
Pre: None
Post: The correctness of the stack_destroy function is known
*/
int test_isEmpty (void);
/*
Pre: None
Post: The correctness of the stack_isEmpty function is known 
*/
int test_peek (void);
/*
Pre: None
Post: The correctness of the stack_peek function is known
*/
int test_functions (void);
/*
Pre: None
Post: The correctness of functions in the stack ADT is known
*/

#endif
