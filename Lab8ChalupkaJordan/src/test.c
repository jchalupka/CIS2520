/*int main (void) {
	FILE * file = openFile("testFiles/data.txt");

	Tree * nameTree = createBinTree(compareName, destroyRestaurant);
	Tree * ratingTree = createBinTree(compareRating, destroyRestaurant);
	if (!(nameTree && ratingTree)) {
		printf("ERROR CREATING TREE\n");
	}
	collectFile(file, nameTree, ratingTree);

	initNCurses();

	traversePreOrder(nameTree, 0);
	traverseInOrder(ratingTree,0);

	
	printInOrder(ratingTree, simplePrint);
	printf("Here\n");

	redrawwin(stdscr);
	wrefresh(stdscr);

	exitNCurses();


	destroyBinTree(nameTree);	
	destroyBinTree(ratingTree);


	return 0;
}*/

#include "test.h"

void makeTest (char * testName) {
	printf("Testing: %s\n"
		   "Output: ", testName);
}

int checkError (int error) {
	if (error) printf("ERROR\n\n");
	else printf("CORRECT\n\n");

	return error;
}

// *********** Test Functions ***********
int test_openFile (void) {
	printf("Testing openFile\n");
	makeTest("File does not exist");
	if (openFile("ThisFileDoesNotExist.txt")) {
		return 1;
	}
	else {
		return 0;
	}
}

int test_collectFile (void) {
	printf("Testing collectFile");
	FILE * badfile = NULL;
	FILE * goodfile = openFile("testFiles/data.txt");
	Tree * nameTree = createBinTree(compareName, destroyRestaurant);
	Tree * ratingTree = createBinTree(compareRating, destroyRestaurant);


	makeTest("File does not exist");

	if (!collectFile(badfile, nameTree, ratingTree)) {
		return 1;
	}


	return 0;
}
// *************************************

int main (void) {
	int numTests = 1;
	int numIncorrect = 0;

	numIncorrect += checkError(test_openFile());
	numIncorrect += checkError(test_collectFile());
	return 0;
}





















