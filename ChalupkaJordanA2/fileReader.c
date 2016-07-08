/*
    Jordan Chalupka
    0928258
*/
#include "fileReader.h"

FILE * openFile (char * fileName) {
	FILE * file;
	/*Put in a file validator maybe*/
	file = fopen(fileName,"r");
	if (file == NULL) {
		printf("The file does not exist\n");
		return NULL;
	}

	return file;
}

void removeNewLines (char input[255]) {
	for (int i = 0; i < strlen(input); i++) {
		if (input[i] == '\n') {
			input [i] = '\0';
		}
	}

	return;
}

void addSortedFirst (Node * list, ContactInfo * info) {
	char * firstName = info->firstName;
	char * firstOrderName = (char*)((ContactInfo*)getFrontValue(list))->firstName;
	if (strcmp(firstName,firstOrderName) ==  0) {
		// If the names are identical, just put this name first
		addFront(list,info);
	}
	else if (strcmp(firstName,firstOrderName) < 0) {
		addFront(list,info);
	}
	else {
		list = list->next;
		addSortedLast(list,info);
	}
}

void addSortedLast (Node * list, ContactInfo * info) {
	// If this is the first item in the list no sorting is needed
	if (getFrontValue(list) == NULL) {
		addFront(list,info);
		return;
	}
	//Pick a spot to insert the new name
	char * lastName = info->lastName;
	char * orderName = (char*)((ContactInfo*)getFrontValue(list))->lastName;

	if (strcmp(lastName,orderName) == 0) {
		// Sort by first name
		addSortedFirst(list,info);
	}
	else if (strcmp(lastName,orderName) < 0) {
		// Exit recursive
		addFront(list,info);
	}else {
		list = list->next;
		// Recursive
		addSortedLast(list,info);
	}

	return;
}

Node * collectFile (FILE * file, Node * list) {
	char input[255];
	while (fgets(input, 254, file) != NULL) {
		removeNewLines(input);
		char * search, * token;
		// Use commas as the deliminator
		search = ",";

		// Contact info will hold lastName, firstName, and phoneNumber
		ContactInfo * info = malloc(sizeof(ContactInfo));
		token = malloc(sizeof(char)*255);

		// Get the lastName
		token = strtok(input, search);
		info->lastName = malloc(sizeof(char)*255);
		strcpy(info->lastName,token);

		// Get the firstName
		token = strtok(NULL,search);
		info->firstName = malloc(sizeof(char)*255);
		strcpy(info->firstName, token);

		// Get the phoneNumber
		token = strtok(NULL, search);
		info->phoneNumber = malloc(sizeof(char)*255);
		strcpy(info->phoneNumber,token);

		// Sort and add to the linkedList
		addSortedLast(list, info);
	}

	return list;
}

