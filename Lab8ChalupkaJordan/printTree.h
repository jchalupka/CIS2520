// Jordan Chalupka 0928258

#ifndef __JCHALUPKA_PRINTTREE__
#define __JCHALUPKA_PRINTTREE__


#include "restaurant.h"
#include "treeInterface.h"
#include <curses.h>

/*

Pre:
Post
*/
int getNumRoots (Tree * tree);

/*

Pre:
Post
*/
int numLinesDown (Tree * tree);

/*

Pre:
Post
*/
int numLinesUp (Tree * tree);

/*

Pre:
Post
*/
int wordStrlen (Tree * tree);

/*

Pre:
Post
*/
void drawConnection (Tree * tree);

/*

Pre:
Post
*/
void traverseInOrder (Tree * tree, int shift);

#endif
