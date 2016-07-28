// Jordan Chalupka 0928258

#include "order.h"

int getOrderTree (char * fileName, int order) {
	FILE * file = openFile(fileName);

	Tree * nameTree = createBinTree(compareName, destroyRestaurant);
	Tree * ratingTree = createBinTree(compareRating, destroyRestaurant);
	
	if (!(nameTree && ratingTree)) {
		printf("ERROR CREATING TREE\n");
	}
	collectFile(file, nameTree, ratingTree);
printf("Here\n");

	if (order == 0) {
		printInOrder(ratingTree, simplePrint);
	} else {
		printPreOrder(ratingTree, simplePrint);
	}
	return 0;
}

int main (void) {
	getOrderTree("testFiles/data2.txt",0);
	getOrderTree("testFiles/data.txt",0);
	printf("Done\n");
	
	printf("Done\n");
	getOrderTree("testFiles/data3.txt",0);
	return 0;
}