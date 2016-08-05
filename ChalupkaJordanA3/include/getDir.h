// Jordan Chalupka 0928528
#ifndef __JCHALUPKA_GETDIR__
#define __JCHALUPKA_GETDIR__

#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <errno.h>

#include "BinaryTree.h"
#include "printTree.h"

/*Open the directory
 *Pre: Dir is the directory to be opened
 *Post: If dir is a directory, directory is opened
*/
DIR* openDirectory (char * dir);

/*Close the directory
 *Pre: Stream is the DIR struct of the directories you want to close.
 *Post: The directory stream is closed.
*/
int closeDirectory (DIR *stream);

/*Fill the tree struct with all of the directories and files
 *Pre: Tree is initialized
 *Post: Tree is filled with directories NOTE, add the top dir manually
*/
BinTree* traverseDir (BinTree * tree, char * dir);

#endif
