/*This function will read in the maze file and create a 2D array of the maze
In the maze, 1 will mean wall (+,-,|), and 0 will mean free space*/
#include "mazeReader.h"

FILE * openFile (char * fileName) {
	FILE * file;
	/*Put in a file validator maybe*/
	file = fopen(fileName,"r");
	if (file == NULL) {
		printf("The file does not exist\n");
		abort();
	}
	return file;
}

/*Removes all of the new line characters and replaces then with NULL characters*/
void removeNewLines (char input[255]) {
	for (int i = 0; i < strlen(input); i++) {
		if (input[i] == '\n') {
			input [i] = '\0';
		}
	}
}

/*First convert the map into a 2D array*/
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

Maze * getMaze (void) {
	/*Pointer to the maze file*/
	FILE * mazeFile = openFile("maze.txt");
	/*Convert the maze file to a 2D array*/
	Maze * maze = convertMaze(mazeFile);
	convertBinary(maze);
	
	return maze;
}
