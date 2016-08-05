// Jordan Chalupka 0928258

#ifndef __JCHALUPKA_PRINTTREE__
#define __JCHALUPKA_PRINTTREE__

#include "BinaryTree.h"
#include <stdlib.h>
#include <curses.h>


/*
Returns the number of roots (Nodes) in a tree.  Used to draw the connections for the tree.
Pre: Tree is initialized.
Post: Number of roots outward from the tree passed in is returned.
*/
int getNumRoots (BinNode * tree);

/*
Calculates the number of lines that will be below a root for printing purposes.
Pre: Tree is initialized.
Post:  Number of lines that will be below the root passed in is returned.
*/
int numLinesDown (BinNode * tree);

/*
Calculates the number of lines that will be above a root for printing purposes.
Pre: Tree is initialized.
Post:  Number of lines that will be above the root passed in is returned.
*/
int numLinesUp (BinNode * tree);

/*
For the current root passed in, calculates the length of the restaurant name and rating. (What will be put on the screen)
Pre: Tree is initialized and has a data parameter.
Post: The length of the restaurant name and rating is returned.
*/
int wordStrlen (BinNode * tree);

/*
Draw the connection for the current root.
Pre: The tree is initialized.
Post: The connection is drawn.
*/
void drawConnection (BinNode * tree);

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
void traverseInOrder (BinNode * tree, int shift);

/*
Traverse the tree in pre order.
Pre: Tree and ncurses environment are initialized.
Post: The tree is traversed in order and printed to the screen.
*/
void traversePreOrder (BinNode * tree, int shift);

/*Calculate the balance factor of node
 *Pre: Node is part of tree.
 *Post: Balance factor is returned.
*/
int balanceFactor (BinNode * tree);

#endif
