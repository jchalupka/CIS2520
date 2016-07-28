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



int test_openFile (void) {
	makeTest("File does not exist");
	if (openFile("ThisFileDoesNotExist.txt")) {
		return 1;
	}
	else {
		return 0;
	}
}

int main (void) {
	int numTests = 1;
	int numIncorrect = 0;

	numIncorrect += checkError(test_openFile());
	return 0;
}