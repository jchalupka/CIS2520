#ifndef __JCHALUPKA_OPTIONS__
#define __JCHALUPKA_OPTIONS__

#include "BinaryTree.h"
#include "printTree.h"
#include <ncurses.h>

void moveOption (void);
void deleteOption (BinTree * tree, void * toDelete);
void renameOption (BinTree * tree, void * oldName, void * newName);
void insertOption (BinTree * tree, void *toInsert, void * toInsertPath);
void viewTreeOption (BinTree * tree);

#endif
