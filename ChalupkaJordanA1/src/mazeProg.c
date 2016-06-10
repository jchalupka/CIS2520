/*
    Jordan Chalupka
    0928258
*/

// This file is used as a way for the user to select which maze file they would like to solve

#include "mazeSolver.h"

int main (int argc, char * argv[]) {
	if (argc != 2) {
		printf("Please enter the location of the maze you would like to solve.\n");
		exit(1);
	}
	char * mazeName = malloc(sizeof(char)*255);
	strcpy(mazeName, argv[1]);
	solveMaze(mazeName);
	free(mazeName);

	return 0;
}
