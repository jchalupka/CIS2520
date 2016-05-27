/*
	Jordan Chalupka
	0928258

	This file contains the test program for the linked list ADT.
	Included in this file is tests for each individual function, as well as
	tests that use a combination of all of the functions.

	The test program is thorough as it tests each individual function in the ADT.
	This ensures each function is working properly.

	This program also tests each function for NULL, to ensure proper functionality even
	when the pre conditions for the functions are not met. (The use of uninitialized lists)
*/
#include "test.h"

/*Test addFront function*/
void testAddFront(int num, node * list) {
	printf("Adding \'%d\' to the front of the list.\n", num);
	addFront(list,num);

	return;
}

/*Test create function*/
node * testCreate(void) {
	printf("Creating a list.\n\n");
	node* list = createList();

	return list;
}

/*Test getFrontValue function*/
void testGetFrontValue(node * list) {
	printf("Getting front value.\n");
	printf("Correct Output: 54");
	printf("Actual Output: %d", getFrontValue(list));
}

/*Test getLength function*/
void testGetLength(int length, node * list) {
	printf("Checking the length of the list.\n");
	printf("Correct Output: %d\n",length);
	printf("Actual Output: %d\n\n", getLength(list));

	return;
}

/*Test printList function*/
void testPrintList(char * strList, node * list) {
	printf("Printing out the list.\nCorrect Output: LIST: %s\n",strList);
	printf("Actual Output: ");
	printList(list);
	printf("\n");

	return;
}

/*Test removeFront function*/
void testRemoveFront(node * list) {
	printf("Removing from the front of the list.\n\n");
	removeFront(list);

	return;
}

/*Test all of the functions for NULL inputs*/
void testForNull (void) {
	/*Test functions for uninitialized lists*/
	printf("Running NULL tests, correct output is 7 iterations of \"Error: List uninitialized\"\nOUTPUT:\n");
	node * list;
	destroyList(list);
	addFront(NULL,1);
	getFrontValue(NULL);
	getLength(NULL);
	printList(NULL);
	removeFront(NULL);
	isInit(NULL);
	printf("Finished NULL tests.\n\n");

	return;
}

/*Add several nodes and then print the list*/
void addFour (node * list) {
	printf("********** ADDING FOUR NODES **********\n");
	testAddFront(5,list);\
	testAddFront(-2,list);
	testAddFront(9000000,list);
	testAddFront(892347847,list);
	testPrintList("[892347847][9000000][-2][5]",list);
	printf("***************************************\n\n");

	return;
}

/*Add several nodes and ensure that the length is increases by one each time*/
void addAndGetLength (node * list) {
	printf("********** Adding and Getting the Length **********\n");
	testGetLength(4,list);
	testAddFront(54,list);
	testGetLength(5,list);
	printf("***************************************************\n\n");

	return;
}

/*Remove several nodes and ensure that the length is decreasing by one each time*/
void removeAndGetLength (node * list) {
	printf("********** Removing and Getting the Length **********\n");
	testPrintList("[54][892347847][9000000][-2][5]", list);
	testRemoveFront(list);
	testPrintList("[-892347847][9000000][-2][5]", list);
	testGetLength(4,list);
	testRemoveFront(list);
	testGetLength(3,list);
	testRemoveFront(list);
	testGetLength(2,list);
	printf("*****************************************************\n\n");

	return;
}

/*Add and remove nodes and ensure that outcome is correct*/
void randomAddAndRemove (node * list) {
	printf("********** Adding and Removing **********\n");
	testPrintList("[-2][5]",list);
	testAddFront(2389,list);
	testPrintList("[2389][-2][5]",list);
	testGetLength(3,list);
	testRemoveFront(list);
	testGetLength(2,list);
	testRemoveFront(list);
	printf("*****************************************\n\n");

	return;
}

/*Remove more nodes than exist in the list*/
void removePastZero (node * list) {
	printf("********** Removing Past Zero Length **********\n");
	testGetLength(1,list);
	testRemoveFront(list);
	testGetLength(0,list);
	testPrintList("",list);
	testRemoveFront(list);
	testGetLength(0,list);
	printf("***********************************************\n\n");

	return;
}

int main (void) {
	/*Testing functions*/
	testForNull();

	node * list = testCreate();

	addFour(list);

	addAndGetLength(list);

	removeAndGetLength(list);

	randomAddAndRemove(list);

	removePastZero(list);

	testDestroy(list);

	return 0;
}
