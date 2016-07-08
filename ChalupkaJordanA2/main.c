#ifndef __JCHALUPK_MAIN__
#define __JCHALUPK_MAIN__

#include "fileReader.h"
#include "ListADT.h"
#include "associativeArray.h"

void loadFile (Node * list) {
	char * fileName = malloc(sizeof(char)*255);
	printf("Enter the name of the file you would like to open:\n");
	scanf("%s",fileName);
	getchar();
	FILE * file = openFile(fileName);
	if (file == NULL) {
		return;
	} 
	list = collectFile(file, list);

	return;
}

void addSingleEntry (Node * list) {
	char * lastName, * firstName, * phoneNumber;
	lastName = malloc(sizeof(char)*255);
	firstName = malloc(sizeof(char)*255);
	phoneNumber = malloc(sizeof(char)*255);
	printf("Enter Last Name: ");
	scanf("%s",lastName);
	getchar();
	printf("Enter First Name: ");
	scanf("%s",firstName);
	getchar();
	printf("Enter Phone Number: ");
	scanf("%s",phoneNumber);
	getchar();

	ContactInfo * info = malloc(sizeof(ContactInfo));
	info->lastName = lastName;
	info->firstName = firstName;
	info->phoneNumber = phoneNumber;

	addSortedLast(list,info);
	return;
}

void printPhoneList (Node * list) {
	Node * tempList = list;
	while (tempList->next != NULL) {
		char * lastName = ((ContactInfo*)getFrontValue(tempList))->lastName;
		char * firstName = ((ContactInfo*)getFrontValue(tempList))->firstName;
		char * phoneNumber = ((ContactInfo*)getFrontValue(tempList))->phoneNumber;

		printf("%s, %s, %s\n", lastName, firstName, phoneNumber);
		tempList = tempList->next;
	}

	return;
}

AArray * makeAArray (Node * list) {
	Node * listTemp = list;
	AArray * hashTable = createAAray(getLength(list));
	while (listTemp->next != NULL) {
		char * phoneNumber = ((ContactInfo*)getFrontValue(listTemp))->phoneNumber;
		
		ContactInfo * thisData = malloc(sizeof(ContactInfo));
		thisData->lastName = ((ContactInfo*)getFrontValue(listTemp))->lastName;
		thisData->firstName = ((ContactInfo*)getFrontValue(listTemp))->firstName;
		hashInsert(hashTable, phoneNumber, thisData);
		listTemp = listTemp->next;
	}
	return hashTable;
}

void lookUpName (Node * list) {
	AArray * hashTable = makeAArray(list);
	char * input = malloc(sizeof(char)*255);
	printf("Enter the phone number of the person you would like to look up:\n");
	scanf("%s",input);
	getchar();

	void * data = hashLook(hashTable, input);
	if (data == NULL) {
		return;
	}
	char * lastName = ((ContactInfo*)getFrontValue(data))->lastName;
	printf("%s\n",lastName);
	return;
}

void optionsMessage (void) {
	printf("Choose an option:\n"
		   "[1] Load File\n"
		   "[2] Add Single Entry\n"
		   "[3] Print List\n"
		   "[4] Look Up Name\n"
		   "[EXIT] Exit the Program\n");
}

int makeChoice (Node * list) {
	char *  input = malloc(sizeof(char)*50);
	printf("Enter Your Choice:\n");
	fgets(input, 8, stdin);
	input[strlen(input)-1] = '\0';
	if (strcmp(input,"exit") == 0 || strcmp(input,"EXIT") == 0) {
		return 0;
	}
	int choice = atoi(input);
	
	switch (choice) {
		case 1:
			printf("Loading file ...\n");
			loadFile(list);
			break;
		case 2:
			printf("Adding single entry ...\n");
			addSingleEntry(list);
			break;
		case 3:
			printf("Printing list ...\n");
			printPhoneList(list);
			break;
		case 4:
			printf("Looking up name ...\n");
			lookUpName(list);
			break;
		default:
			printf("Input is not a valid choice.\n");
	}
	return 1;
	printf("\n");
}

int optionMenu (Node * list) {
	optionsMessage();
	int choice = makeChoice(list);
	return choice;
}

int main (void) {
	int running = 1;

	Node * list = malloc(sizeof(Node));
	list = createList();

	while (running) {
		running = optionMenu(list);
	}
	printf("Exiting the program\n");
	return 0;
}

#endif
