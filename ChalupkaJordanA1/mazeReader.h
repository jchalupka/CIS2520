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

Maze * getMaze (void);
void printBinary(Maze * maze);

#endif