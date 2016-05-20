/*
    Jordan Chalupka
    0928258
*/
#ifndef __JCHALUPK_TEST__
#define __JCHALUPK_TEST__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "fraction.h"

typedef Fraction* (*functionPtr)(Fraction*,Fraction*);

int correct_output (char * test_type);
/*
Pre:  The test for a particular function has been completed succesfully
Post:  None
*/

int incorrect_output (char * test_type, char * expected_out, char * actual_out);
/*
Pre:  The test for a particular function has not been completed succesfully
Post:  None
*/

int test_create (void);
/*
Pre:  None
Post:  Test will reveal the correctness of the create_fraction function
*/

int test_destroy (void);
/*
Pre: None
Post:  Test will reveal the correctness of the destroy_fraction function
*/

int test_numerator (void);
/*
Pre: None
Post: Test will reveal the correctness of the get_numerator function
*/

int test_denominator (void);
/*
Pre: None
Post: Test will reveal the correctness of the get_denominator function
*/

int test_add (void);
/*
Pre: None
Post: Test will reveal the correctness of the add_fraction function
*/

int test_multiply (void);
/*
Pre:  None
Post:  Test will reveal the correctness of the mult_fraction function
*/

int check_functions (void);
/*
Pre:  None
Post:  All of the tests for individual functions will be run and their outputs known
*/

int get_number (void);
/*
Pre:  There is a seed for the random number generator (srand)
Post:  Produces a random number that can be positive or negative
*/

functionPtr get_operation (int operation);
/*
Pre:  None
Post:  The function pointer has been set to either the add or multiply function (50% probability to each)
*/

int run_test (int i);
/*
Pre:  None
Post:  Runs one test
*/

int test_example (void);
/*
Pre:  None
Post:  Runs through tests that rely on the combination of all of the functions and their correctness
*/

#endif
