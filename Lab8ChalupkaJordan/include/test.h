// Jordan Chalupka 0928258

#ifndef __JCHALUPKA_TEST__
#define __JCHALUPKA_TEST__

#include "fileIO.h"

/*
Print out template for making a test.
Pre: None.
Post: A message is shown to the user given information about the test.
*/
void makeTest (char * testName);

/*
Show stats about how succesful the tests were.
Pre: Tests are all run.
Post: Stats are printed to screen.
*/
void reviewTests (int numTests, int numIncorrect);

/*
Test the openFile function.
*/
int test_openFile (void);

/*
Test the collectFile function.
*/
int test_collectFile (void);

/*
Test the createRestaurant function.
*/
int test_createRestaurant (void);

/*
Test the destroyRestaurant function.
*/
int test_destroyRestaurant (void);

/*
Test the compareName function.
*/
int test_compareName (void);

#endif
