// Jordan Chalupka 0928258

#ifndef __JCHALUPKA_FILEIO__
#define __JCHALUPKA_FILEIO__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "restaurant.h"
#include "treeInterface.h"

FILE * openFile (char * fileName);
void removeNewLines (char input[255]);
void collectFile (FILE * file, Tree * tree);

#endif