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

	return;
}

/*Convert the maze file into a 2D array of characters`*/
Maze * convertMaze (FILE * mazeFile) {
	char input[255];
	char (*maze)[255] = malloc(sizeof(char)*255*255);
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
	maze->mazeBinary = malloc(sizeof(int)*255*255);
	for (int y = 0; y < maze->height; y++) {
		for (int x = 0; x < maze->width; x++) {
			char mazeChar = maze->mazeMap[y][x];
			if (mazeChar == '+'||mazeChar == '-'||mazeChar == '|') {
				maze->mazeBinary[y][x] = 1;
			}
			else if (mazeChar == 'S' || mazeChar == 'F') {
				maze->mazeBinary[y][x] = -1;
			}
			else {
				maze->mazeBinary[y][x] = 0;
			}
		}
	}
	
	return;
}

/*Print the binary model (This was used for testing)*/
void printBinary (Maze * maze) {
	/*Convert the maze file to a 2D array*/
	
	for (int y = 0; y < maze->height; y++) {
		for (int x = 0; x < maze->width; x++) {
			if (maze->mazeBinary[y][x] > 0) {
				printf("X");
			}
			else if (maze->mazeBinary[y][x]) {
				printf("@");
			}
			else {
				printf(" ");
			}
		}
	}

	return;
}

/*Retrive the maze file and convert to a FILE pointer*/
Maze * getMaze (void) {
	/*Pointer to the maze file*/
	FILE * mazeFile = openFile("doc/maze.txt");
	/*Convert the maze file to a 2D array*/
	Maze * maze = convertMaze(mazeFile);
	convertBinary(maze);
	fclose(mazeFile);
	return maze;
}
