/*
Jordan Chalupka 0928258
*/
#ifndef __JCHALUPKA_TOOLS__
#define __JCHALUPKA_TOOLS__

#include "ListADT.h"
#include "associativeArray.h"
#include "fileReader.h"

/*
Sort the item being added into the list by first name
Pre: List is initialized and contact info is populated
Post: The Contact info is placed in the list at the correct position
*/
void addSortedFirst (Node * list, ContactInfo * info);

/*
Sort the item being added into the list by last name
This function is recursive
Pre: List is initialized and contact info is populated
Post: The Contact info is placed in the list at the correct position
*/
void addSortedLast (Node * list, ContactInfo * info);

/*
This function creates an associative array correctly for use in the phone book.
It acts as a wrapper for the AArray ADT function
Pre:  List is initialized
Post: AArray is created and the list is hashed according to the phone number
*/
AArray * makeAArray (Node * list);

#endif
