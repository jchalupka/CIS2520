/*
    Jordan Chalupka
    0928258
*/

#ifndef __JCHALUPKA_MAZEREADER__
#define __JCHALUPKA_MAZEREADER__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct maze {
	int height;
	int width;
	char (*mazeMap)[255];
	int (*mazeBinary)[255];
} Maze;

/*
Open the maze file.
Pre: The name of the file is passed in as a string.
Post: A FILE pointer is returned.
*/
FILE * openFiile (char * fileName);

/*
Removes the new lines from the string and replaces them with a null terminating character.
Pre: 2D character array is passed in.
Post: New line characters are removes and replaced with null terminating characters.
*/
void removeNewLines (char input[255]);

/*
Convert maze from the FILE pointer to a 2D character array.
Pre: FILE pointer is pointing to the maze file.
Post: 2D character array is returned.
*/
Maze * convertMaze (FILE * mazeFile);

/*
Convert from 2D character array to 2D integer array.
Pre: Maze struct has the maze map initialized.
Post: Maze struct has the maze binary map initialized.
*/
void convertBinary (Maze * maze);

/*
Print out the binary version of the maze map.
Pre: Maze binary map has been initialized.
Post: The binary version of the maze is printed.
*/
void printBinary(Maze * maze);

/*
Initializes all of the maze struct variables.
Pre: None
Post: Maze struct is initialized and memory has been allocated.
*/
Maze * getMaze (void);

#endif
