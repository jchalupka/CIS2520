// Jordan Chalupka 0928528
#ifndef __JCHALUPKA_OPTIONS__
#define __JCHALUPKA_OPTIONS__

#include "BinaryTree.h"
#include "printTree.h"
#include <ncurses.h>


/*Moves the current parent directory
 *Pre: Tree is initialized
 *Post: Parent directory is moved
*/
void moveOption (void);

/*Deletes a node on the tree
 *Pre: Tree is initialized
 *Post: Node is deleted
*/
void deleteOption (BinTree * tree, void * toDelete);

/*Renames a node on the tree
 *Pre: Tree is initialized
 *Post: Node is renamed
*/
void renameOption (BinTree * tree, void * oldName, void * newName);

/*Insert a node onto the tree
 *Pre: Tree is initialized
 *Post: Node is inserted onto tree
*/
void insertOption (BinTree * tree, void *toInsert, void * toInsertPath);

/*View a list of all the nodes on the tree
 *Pre: Tree is initialized
 *Post: List is printed into for user
*/
void viewTreeOption (BinTree * tree);

#endif
