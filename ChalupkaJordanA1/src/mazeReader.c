/*
    Jordan Chalupka
    0928258
*/

#include "mazeReader.h"

/* Open the file containing the maze*/
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

/*Removes all of the new line characters and replaces then with null terminating characters*/
void removeNewLines (char input[255]) {
	for (int i = 0; i < strlen(input); i++) {
		if (input[i] == '\n') {
			input [i] = '\0';
		}
	}
}

/*Convert the maze file into a 2D array of characters`*/
Maze * convertMaze (FILE * mazeFile) {
	char input[255];
	char (*maze)[255] = malloc(255*255);
	/*Repeat for each line in the file*/
	int height = 0;
	int width = 0;

	while (fgets(input,254,mazeFile) != NULL) {
		if (height == 0) {
			width = strlen(input) -1;
		}
		removeNewLines(input);
		for (int i = 0; i < width; i++) {
			maze[height][i] = input[i];
		}	
		height++;
	}
	
	Maze * mazeStruct = malloc(sizeof(Maze));
	mazeStruct->height = height;
	mazeStruct->width = width;
	mazeStruct->mazeMap = maze;
	return mazeStruct;
}

/*Convert the maze to a simpler integer model with 1 being wall, -1 being start/end and 0 being free space*/
void convertBinary (Maze * maze) {
	maze->mazeBinary = malloc(255*255);
	for (int i = 0; i < maze->height; i++) {
		for (int j = 0; j < maze->width; j++) {
			char mazeChar = maze->mazeMap[i][j];
			if (mazeChar == '+'||mazeChar == '-'||mazeChar == '|') {
				/*Error here*/
				maze->mazeBinary[i][j] = 1;
			}
			else if (mazeChar == 'S' || mazeChar == 'F') {
				maze->mazeBinary[i][j] = -1;
			}
			else {
				maze->mazeBinary[i][j] = 0;
			}
		}
	}
}

/*Print the binary model (This was used for testing)*/
void printBinary (Maze * maze) {
	/*Convert the maze file to a 2D array*/
	
	for (int i = 0; i < maze->height; i++) {
		for (int j = 0; j < maze->width; j++) {
			if (maze->mazeBinary[i][j] > 0) {
				printf("X");
			}
			else if (maze->mazeBinary[i][j]) {
				printf("@");
			}
			else {
				printf(" ");
			}
		}
	printf("\n");
	}
}

/*Retrive the maze file and convert to a FILE pointer*/
Maze * getMaze (void) {
	/*Pointer to the maze file*/
	FILE * mazeFile = openFile("doc/maze.txt");
	/*Convert the maze file to a 2D array*/
	Maze * maze = convertMaze(mazeFile);
	convertBinary(maze);
			printf("Made it\n");
	
	return maze;
}
