/*
  Jordan Chalupka
  0928258

  This file contains the test program for the function ADT.
  Included in this file is tests for each individual function, as well
  as tests that use a combination of all of the functions.

  The test program is thorough as it tests each individual function
  in the ADT.  This ensures that each function is working properly.

  Also this test program runs randomized tests which rely on the 
  correctness of all of the functions working together.
  The randomized tests are currently set to run 10 tests,
  but this value can and has been changed to test up to 100,000
  test cases with zero errors.  The values in the randomized tests
  can and has also been changed to include very large values as well
  as small values, as well as positives and negative values, to ensure
  correctness.

  Zero has previously been included in the test program, but has been removed
  due to obvious errors it causes when placed in the denominator.
  See question 2 for implementation of a program that solves zero-denominators.
  Zero does function properly when placed as a numerator in previous tests.
*/
#include "test.h"

/*Use these variables to change the testing*/
#define NUM_TESTS 10  /* Number of tests you would like to run*/
#define LARGEST_VALUE 10 /* The largest random value to be used in the test cases*/

/*Testing Outputs*/
int correct_output (char * test_type) {
    fprintf(stderr, "Testing \"%s\" ... CORRECT\n", test_type);
    return 0;
}

int incorrect_output (char * test_type, char * expected_out, char * actual_out) {
    fprintf(stderr, "Testing \"%s\" ... ERROR\n"
            "\tExpected Output: %s\n"
            "\tActual Output: %s\n", test_type, expected_out, actual_out);
    return 0;
}

/*Test Individual Functions*/
/* Tests the create_fraction function*/
int test_create (void) {
    Fraction * test_0 = create_fraction(50,2);
    if (test_0 != NULL) {
        correct_output("create_fraction");
    } 
    else incorrect_output("create_fraction", "Pointer to fraction", "Null Pointer");
    return 0;
}
/* Tests the destroy_fraction function*/
int test_destroy (void) {
    Fraction * test_0 = create_fraction(89,9);
    destroy_fraction(&test_0);
    if (test_0 == NULL) {
        correct_output("destroy_fraction");
    }
    else incorrect_output("destroy_fraction", "Destroyed fraction", "Fraction not destroyed");
    return 0;
}
/*Tests the get_numerator function*/
int test_numerator (void) {
    Fraction * test_0 = create_fraction(88,98);
    int numerator = get_numerator(test_0);
    if (numerator == 88) {
        correct_output("get_numerator");
    } else {
        char buffer[20];
        sprintf(buffer,"%d",numerator);
        incorrect_output("get_numerator","88", buffer);
    }
    return 0;
}
/*Tests the get_denominator function*/
int test_denominator (void) {
    Fraction * test_0 = create_fraction(87,-13);
    int numerator = get_denominator(test_0);
    if (numerator == -13) {
        correct_output("get_denominator");
    } else {
        char buffer[20];
        sprintf(buffer,"%d",numerator);
        incorrect_output("get_denominator","-13", buffer);
    }
    return 0;
}
/* Tests the add_fraction function*/
int test_add (void) {
    Fraction * test_0 = create_fraction(1,2);
    Fraction * test_1 = create_fraction(3,4);

    Fraction * test_sum = add_fraction(test_0, test_1);
    int numerator, denominator;
    numerator = get_numerator(test_sum);
    denominator = get_denominator(test_sum);
    if ((numerator == 10) && (denominator == 8)) {
        correct_output("add_fraction");
    } else {
        char num_string[20], denom_string[20], * output;

        sprintf(num_string,"%d",numerator);
        sprintf(denom_string,"%d",denominator);
        output = strcat(num_string,"/");
        output = strcat(output,denom_string);
        incorrect_output("add_fraction","10/8",output);
    }
    return 0;
}
/*Tests the mult_fraction function*/
int test_multiply (void) {
    Fraction * test_0 = create_fraction(10,5);
    Fraction * test_1 = create_fraction(1,2);

    Fraction * test_sum = mult_fraction(test_0, test_1);
    int numerator, denominator;
    numerator = get_numerator(test_sum);
    denominator = get_denominator(test_sum);
    if ((numerator == 10) && (denominator == 10)) {
        correct_output("mult_fraction");
    } else {
        char num_string[20], denom_string[20], * output;

        sprintf(num_string,"%d",numerator);
        sprintf(denom_string,"%d",denominator);
        output = strcat(num_string,"/");
        output = strcat(output,denom_string);
        incorrect_output("mult_fraction","10/10",output);
    }
    return 0;
}

/* This will run through a test for each of the functions in the ADT*/
int check_functions (void) {
    test_create();
    test_destroy();
    test_numerator();
    test_denominator();
    test_add();
    test_multiply();

    return 0;
}

/* Generates a random number*/
int get_number (void) {
    int num, negative;
    num = (rand()%LARGEST_VALUE)+1;
    /*Zero is not included in the random number generation
    Zero has been tested as numerator, but leads to oddities
    when randomly placed at denominator.  See Question two for
    implementation plans non-zero denominator*/
    negative = rand()%2;
    if (negative) num *= -1;

    return num;
}

/* Generates a random operation (add or multiply)*/
functionPtr get_operation (int operation) {
    functionPtr ptr;  /*Function pointer that will point to either the add or multiply functions*/
    if (operation) {
        ptr = &add_fraction;
    } 
    else ptr = &mult_fraction;
    
    return ptr;
}

/* Runs one test*/
int run_test (int i) {
    printf("Running Test %d\n", i);
    int a,b,c,d;
    /* These four numbers will be used to generate the fractions*/
    a = get_number();
    b = get_number();
    c = get_number();
    d = get_number();
    /*Create two fractions*/
    Fraction * first = create_fraction(a,b);
    Fraction * second = create_fraction(c,d);
    /* num will be used for binary probability (negative or postive and add or multiply)*/
    int num = rand()%2;
    char operation_char;
    double total;
    /* Set variables that are dependant on the binary probability for add or multiply*/
    if (num) {
        operation_char = '+';
        total = ((double)a/b) + ((double)c/d);
    } else {
        operation_char = '*';
        total = ((double)a/b) * ((double)c/d);
    }
    /* Get the function pointer*/
    functionPtr operation = get_operation(num);
    /* Run the function*/
    Fraction * sum_fraction = operation(first, second);

    int sum_numerator, sum_denominator;
    sum_numerator = get_numerator(sum_fraction);
    sum_denominator = get_denominator(sum_fraction);
    /* Print out the equation*/
    printf("\t%d/%d %c %d/%d = %d/%d\n", a,b,operation_char,c,d,sum_numerator,sum_denominator);

    double total_fraction = (double) sum_numerator / sum_denominator;
    /* The less than is used due to floating point error with equality*/
    destroy_fraction(&first);
    destroy_fraction(&second);
    destroy_fraction(&sum_fraction);
    if (fabs(total - total_fraction) < 0.001) {
        printf("\tCorrect\n");
        return 1;
    } else {
        printf("\tIncorrect, %f != %f\n",total, total_fraction);
        return 0;
    }
}

int test_example (void) {
    /* Seed random number generator */
    srand(time(NULL));
    int num_tests,correct;
    /* Number of tests to be run*/
    num_tests = NUM_TESTS;
    correct = 0; 
    /* Run the tests*/
    for (int i = 0; i < num_tests; i++) {
        correct += run_test(i);
    }
    /* Give the test results*/
    printf("%d/%d Tests Correct\n", correct, num_tests);
    return 0;
}

int main (void) {
    /* Check each individual function*/
    check_functions();
    /* Use the functions all together with randomness*/
    test_example();
    return 0;
}
