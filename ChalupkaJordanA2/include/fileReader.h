/*
Jordan Chalupka 0928258
*/

#ifndef __JCHALUPKA_FILEREADER__
#define __JCHALUPKA_FILEREADER__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListADT.h"

typedef struct contactInfo {
	char * phoneNumber;
	char * firstName;
	char * lastName;
} ContactInfo;

/*
A file is opened to read 
Pre: The file name is known
Post: The file is opened to read and the FILE pointer is returned
*/
FILE * openFile (char * fileName);

/*
New line characters are removed and replaced with null characters
Pre: String is passed in 255 characters or less
Post: New line characters are removed
*/
void removeNewLines (char input[255]);

/*
Information is extracted from the file
Pre: FILE pointer is pointing to a read file, list is created
Post: Information in file is added to the list
*/
Node * collectFile (FILE * file, Node * list);

/*
Sort by last name
Pre: List is initialize and contact info is initialized
Post: List is sorted correctly and info is added to list
*/
void addSortedLast (Node * list, ContactInfo * info);

#endif
