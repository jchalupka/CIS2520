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

	initNCurses();

	if (order == 0) {
		printInOrder(ratingTree, simplePrint(nameTree));
	} else {
		printPreOrder(nameTree, simplePrint(nameTree));
	}
	
	
	
	printInOrder(ratingTree, simplePrint);
	printf("Here\n");

	
	getchar();
	exitNCurses();

	fclose(file);

	return 0;
}

int main (void) {
	getOrderTree("testFiles/data.txt",0);
	getOrderTree("testFiles/data2.txt",0);
	getOrderTree("testFiles/data3.txt",0);
	return 0;
}