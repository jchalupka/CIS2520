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
	
	
	
	printInOrder(ratingTree, simplePrint);
	printf("Here\n");

	
	getchar();
	exitNCurses();


	destroyBinTree(nameTree);	
	destroyBinTree(ratingTree);


	return 0;
}

int main () {

	printTree("testFiles/data.txt", 0);
	print
	return 0;
}
