#ifndef __JCHALUPKA_MAIN__
#define __JCHALUPKA_MAIN__

#include <stdio.h>
#include <dirent.h>
#include "BinaryTree.h"
#include "getDir.h"
#include <unistd.h>
#include "options.h"


/*Basically fgets, but removes trailing return key
 *Pre: Word is malloced
 *Post: Word is filled with word from stdin (user)
*/
char * getStdin (char * word);

/*When the user starts, get the parent dir
 *Pre: None
 *Post: Returns the string of the parent dir (function checks that this is viable dir)
*/
char * getInitialDir (void);

/*Change the parent directory
 *Pre: Input the name of the directory you would like to move to (can use relational dir, eg .. or ../otherDir)
 *Post: If input is a dir, dir is changed.  Else dir stays the same.
*/
char * changeParentDir (char * dir);

/*Gets the parent directory (string)
 *Pre: A buffer to put the string in is passed in
 *Post: The parent directroy is placed in the buffer (and returned)
*/
char * getPartentDir (char * buffer);

// The main function
int main (int argc, char * argv[]);

#endif