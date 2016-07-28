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
	if (error) printf("ERROR IN TESTS\n\n");
	else printf("ALL TESTS CORRECT\n\n");

	return error;
}

void reviewTests (int numTests, int numIncorrect) {
	int numCorrect = numTests-numIncorrect;

	printf("Overview: %d/%d Tests Correct\n", numCorrect,numTests);
}

// *********** Test Functions ***********
int test_openFile (void) {
	printf("*** Testing openFile ***\n");
	makeTest("File does not exist");
	if (openFile("ThisFileDoesNotExist.txt")) {
		return 1;
	}
	else {
		return 0;
	}
}

int test_collectFile (void) {
	printf("*** Testing collectFile ***\n");

	FILE * file = openFile("testFiles/data.txt");
	Tree * nameTree = createBinTree(compareName, destroyRestaurant);
	Tree * ratingTree = createBinTree(compareRating, destroyRestaurant);


	makeTest("File does not exist");
	if (!collectFile(NULL, nameTree, ratingTree)) {
		return 1;
	}

	makeTest("Tree does not exist");
	if (!collectFile(file, NULL, ratingTree)) {
		return 1;
	}

	return 0;
}

int test_createRestaurant (void) {
	printf("***  Testing createRestaurant ***\n");

	makeTest("Incorrect pointer input");
	if (createRestaurant("Hello", NULL,5)) {
		return 1;
	}
	makeTest("Correct Input");
	if (!createRestaurant("Name","Type",60)) {
		return 1;
	}

	return 0;
}

int test_destroyRestaurant (void) {
	printf("***  Testing destroyRestaurant ***\n");

	makeTest("Destroying NULL");
	printf("No Errors\n");

	makeTest("Destroying Restaurant");
	Restaurant * rest = createRestaurant("Name","Type",60);
	destroyRestaurant(rest);
	if (rest == NULL) {
		printf("Restaurant is NULL\n");
		return 1;
	}

	return 0;
}

// *************************************

int main (void) {
	int numTests = 4;
	int numIncorrect = 0;

	numIncorrect += checkError(test_openFile());
	numIncorrect += checkError(test_collectFile());
	numIncorrect += checkError(test_createRestaurant());
	numIncorrect += checkError(test_destroyRestaurant());

	reviewTests(numTests,numIncorrect);
	return 0;
}





















