// Jordan Chalupka 0928258

#ifndef __JCHALUPKA_PRINTTREE__
#define __JCHALUPKA_PRINTTREE__

#include <curses.h>
#include "restaurant.h"
#include "treeInterface.h"

int getNumRoots (Tree * tree);
int numLinesDown (Tree * tree);
int numLinesUp (Tree * tree);
int wordStrlen (Tree * tree);
void drawConnection (Tree * tree);
void traverseInOrder (Tree * tree, int shift);

#endif