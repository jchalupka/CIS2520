/*
  Jordan Chalupka
  0928258
*/
#include "fraction.h"

// Return a fraction ADT
Fraction * create_fraction (int numer, int denom) {
    Fraction * temp_fract = malloc(sizeof(Fraction));
    if (temp_fract == NULL) {
        fprintf(stderr, "Not enough memory, program ending");
        exit(-1);
    }
    temp_fract->numer = numer;
    temp_fract->denom = denom;

    return(temp_fract);
}

// Clean up the memory used by the fraction ADT
void destroy_fraction (Fraction ** fract) { 
    free(*fract);
    *fract = NULL; // Point to NULL for testing purposes
    return;
}

// Return the fraction's numerator
int get_numerator (Fraction * fract) {
    int numer = fract->numer;

    return numer;
}

// Return the fraction's denominator
int get_denominator (Fraction * fract) {
    int denom = fract->denom;

    return denom;
}

// Add two fractions together
Fraction * add_fraction (Fraction * fract1, Fraction * fract2) {
    Fraction * result = malloc(sizeof(Fraction));
    if (result == NULL) {
        fprintf(stderr, "Not enough memory, program ending");
        exit(-1);
    }
    int numerator, left_numerator, right_numerator;
    // Find each fraction's new numerator
    left_numerator = fract1->numer * fract2->denom;
    right_numerator = fract2->numer * fract1->denom;
    // Get the sum of these numerators
    numerator = left_numerator + right_numerator;
    result->numer = numerator;

    // Use the largest common denominator to get the new denominator
    int largeCommonDenom = fract1->denom * fract2->denom;
    result->denom = largeCommonDenom;

    return result;
}

// Multiply two fractions
Fraction * mult_fraction (Fraction * fract1, Fraction * fract2) {
    Fraction * result = malloc(sizeof(Fraction));
    if (result == NULL) {
        fprintf(stderr, "Not enough memory, program ending");
        exit(-1);
    }
    // Cross multiply
    result->numer = fract1->numer * fract2->numer;
    result->denom = fract1->denom * fract2->denom;

    return(result);
}
