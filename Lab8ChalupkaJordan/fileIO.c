// Jordan Chalupka 0928258

#include "fileIO.h"

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
void collectFile (FILE * file, Tree * nameTree, Tree * ratingTree) {
	char input[255];
	while (fgets(input, 254, file) != NULL) {
		removeNewLines(input);
		char * search, * token;
		// Use commas as the deliminator
		search = ",";

		// Restaurant info will hold name, foodtype, and rating
		token = malloc(sizeof(char)*255);

		// Get the name
		token = strtok(input, search);
		char * name = malloc(sizeof(char)*255);
		strcpy(name,token);

		// Get the foodtype
		token = strtok(NULL,search);
		char * foodtype = malloc(sizeof(char)*255);
		strcpy(foodtype, token);

		// Get the rating
		token = strtok(NULL, search);
		int rating;
		rating = atoi(token);

		printf("%s\n", name);
		getchar();

		Restaurant * restPtr = createRestaurant(name, foodtype, rating);
		addToTree(nameTree, restPtr);
		addToTree(ratingTree,restPtr);
		//printData(restPtr);
		free(name);
		free(foodtype);

	}

	return;
}

