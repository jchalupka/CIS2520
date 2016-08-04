#include "rename.h"
#include <libgen.h> // Get the dir and base names 
// Functions required for rename functionality
BinNode * renameNode (BinTree * tree, void * oldName, void * newName) {
	BinNode * nodeToChange = searchTree(tree, oldName);
	nodeToChange->data = newName;

	return nodeToChange;
}

// Function for moving

/*
What are we moving

Where are we going to (Just insert this node)

Move it (Copy the name)

Delete the old
*/



BinNode * moveNode (BinTree * tree, void * toMove, void * destinationPath) {

	BinNode * nodeToMove = searchTree(tree, toMove);

	if (nodeToMove == NULL) return NULL;

	// Get just the part after the last bracket
	char * base = basename(nodeToMove->data);
	char * newPath;
	sprintf(newPath, "%s/%s", destinationPath, base);
	printf("Moving to: %s\nName will now be: %s\n", destinationPath, newPath);

	insertBinTree(tree, newPath);
	destroyNode(tree, tree->root, nodeToMove->data);
	return nodeToMove;
}