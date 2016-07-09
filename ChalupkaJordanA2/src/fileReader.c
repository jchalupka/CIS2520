/*
    Jordan Chalupka 0928258
    This file reads in the input file and collects the information
*/
#include "fileReader.h"

// Open the input file as read only and return the FILE pointer
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

// Remove the new line character from each line
void removeNewLines (char input[255]) {
	for (int i = 0; i < strlen(input); i++) {
		if (input[i] == '\n') {
			input [i] = '\0';
		}
	}

	return;
}

// Collect the relevent information from the FILE pointer
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

