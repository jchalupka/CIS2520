// Jordan Chalupka 0928258

#ifndef __JCHALUPKA_FILEIO__
#define __JCHALUPKA_FILEIO__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "restaurant.h"
#include "treeInterface.h"

/*
Takes a filename as input and returns a pointer to the FILE
Pre: The filename is known.
Post: A FILE pointer is returned, or an error is sent to the user.
*/
FILE * openFile (char * fileName);

/*
Removes all of the new line characters and replaces them with NULL terminating characters
Pre: A string of up to 255 characters is input.
Post: The new line characters are replaced with NULL terminating characters.
*/
void removeNewLines (char input[255]);

/*
Collect all of the information from the input FILE, and add it to both the nameTree and the ratingTree
Pre: FILE points to a file, and the Tree structs have been created using createBinTree().
Post: File is collected and all of the data is stored in the binary trees.
*/
int collectFile (FILE * file, Tree * nameTree, Tree * ratingTree);

#endif
