// Jordan Chalupka 0928258

#ifndef __JCHALUPKA_PRINTTREE__
#define __JCHALUPKA_PRINTTREE__


#include "restaurant.h"
#include "treeInterface.h"
#include <curses.h>

/*
Returns the number of roots (Nodes) in a tree.  Used to draw the connections for the tree.
Pre: Tree is initialized.
Post: Number of roots outward from the tree passed in is returned.
*/
int getNumRoots (Tree * tree);

/*
Calculates the number of lines that will be below a root for printing purposes.
Pre: Tree is initialized.
Post:  Number of lines that will be below the root passed in is returned.
*/
int numLinesDown (Tree * tree);

/*
Calculates the number of lines that will be above a root for printing purposes.
Pre: Tree is initialized.
Post:  Number of lines that will be above the root passed in is returned.
*/
int numLinesUp (Tree * tree);

/*
For the current root passed in, calculates the length of the restaurant name and rating. (What will be put on the screen)
Pre: Tree is initialized and has a data parameter.
Post: The length of the restaurant name and rating is returned.
*/
int wordStrlen (Tree * tree);

/*
Draw the connection for the current root.
Pre: The tree is initialized.
Post: The connection is drawn.
*/
void drawConnection (Tree * tree);

/*
Initialize the ncurses environment.
Pre: The ncurses environment is not yet initialized.
Post: The ncurses environment is initialized.
*/
int initNCurses (void);

/*
Exit the ncurses environment.
Pre:  The ncurses environment is already initialized.
Post: The ncurses environment is exited.
*/
int exitNCurses (void);

/*
Traverse the tree in order.
Pre: Tree and ncurses environment are initialized.
Post: The tree is traversed in order and printed to the screen.
*/
void traverseInOrder (Tree * tree, int shift);

#endif
