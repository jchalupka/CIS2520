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

FILE * openFile (char * fileName);
void removeNewLines (char input[255]);
Node * collectFile (FILE * file, Node * list);
void addSortedLast (Node * list, ContactInfo * info);

#endif