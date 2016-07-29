// Jordan Chalupka 0928258

#include "order.h"

int getOrderTree (char * fileName, int order) {
	FILE * file = openFile(fileName);

	Tree * nameTree = createBinTree(&compareName, destroyRestaurant);
	Tree * ratingTree = createBinTree(&compareRating, destroyRestaurant);

	if (!(nameTree && ratingTree)) {
		printf("ERROR CREATING TREE\n");
	}
	collectFile(file, nameTree, ratingTree);

	if (order == 0) {
		printInOrder(ratingTree, &simplePrint);
	} else {
		printPreOrder(ratingTree, &simplePrint);
	}
	
	fclose(file);
	return 0;
}

int main (int argc, char * argv[]) {
	if (argc != 2) {
		printf("Error, please enter the directory of the data file you would like to use.\n");
	}

	getOrderTree(argv[1], 0);

	return 0;
}