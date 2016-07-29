// Jordan Chalupka 0928258

#include "printTreeDiagram.h"

int printTree (char * fileName, int treeType) {
	FILE * file = openFile(fileName);

	Tree * nameTree = createBinTree(compareName, destroyRestaurant);
	Tree * ratingTree = createBinTree(compareRating, destroyRestaurant);
	if (!(nameTree && ratingTree)) {
		printf("ERROR CREATING TREE\n");
	}
	collectFile(file, nameTree, ratingTree);

	initNCurses();

	if (treeType == 0) {
		traverseInOrder(ratingTree,0);
	} else {
		traverseInOrder(nameTree,0);
	}
	
	getchar();
	exitNCurses();

	fclose(file);

	return 0;
}

int main (void) {
	printTree("testFiles/data2.txt", 0);
	printTree("testFiles/data.txt", 0);
	printTree("testFiles/data.txt", 1);
	printTree("testFiles/data3.txt",1);

	return 0;
}
