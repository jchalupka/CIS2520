/*
  Jordan Chalupka
  0928258
*/
#ifndef __JCHALUPK_FRACTION__
#define __JCHALUPK_FRACTION__

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int numer;
    int denom;
} Fraction;

Fraction * create_fraction (int numer, int denom);
/*
Pre: none
Post: a fraction is created with the given numerator and denominator
*/

void destroy_fraction (Fraction ** fract);
/*
Pre: The fraction parameter is initialized
Post: The fraction is destroyed and memory is released if necessary
*/

int get_numerator (Fraction * fract);
/*
Pre: The fraction parameter is initialized
Post: none
*/

int get_denominator (Fraction * fract);
/*
Pre: The fraction parameter is initialized
Post: none
*/

Fraction * add_fraction (Fraction * fract1, Fraction * fract2);
/*
Pre: Both fractions passed in are initialized
Post: The two fractions are added and the result is placed in a new fraction that is returned
*/

Fraction * mult_fraction (Fraction * fract1, Fraction * fract2);
/*
Pre: Both fractions passed in are initialized
Post: The two fractions are multiplied and the result is placed in a new fraction this is returned
*/

#endif
