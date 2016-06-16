/*
    Jordan Chalupka
    0928258
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE * openFile (char * fileName) {
	FILE * file;
	/*Put in a file validator maybe*/
	file = fopen(fileName,"r");
	if (file == NULL) {
		printf("The file does not exist\n");
		exit(1);
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

void collectStruct (FILE * file) {
	char input[255];
	while (fgets(input, 254, file) != NULL) {
		removeNewLines(input);
		char * search, * token;
		search = ",";

		token = strtok(input,search);
		while (token != NULL) {
			printf("%s\n", token);
			token = strtok(NULL, search);
		}
	}
}

int main (void) {
	FILE * file = openFile("test.txt");
	collectStruct(file);
	return 0;
}