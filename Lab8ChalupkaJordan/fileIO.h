// Jordan Chalupka 0928258

#ifndef __JCHALUPKA_FILEIO__
#define __JCHALUPKA_FILEIO__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "restaurant.h"
#include "treeInterface.h"

/*

Pre:
Post
*/
FILE * openFile (char * fileName);

/*

Pre:
Post
*/
void removeNewLines (char input[255]);

/*

Pre:
Post
*/
void collectFile (FILE * file, Tree * nameTree, Tree * ratingTree);

#endif
