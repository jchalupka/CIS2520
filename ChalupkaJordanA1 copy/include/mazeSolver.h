#ifndef __JCHALUPKA_MAZESOLVER__
#define __JCHALUPKA_MAZESOLVER__

#include <stdlib.h>
#include "mazeReader.h"
#include "StackADT.h"
#include "ListADT.h"

typedef struct position {
	int y;
	int x;
} Position;

typedef struct solver {
	int solved;
	Stack * route;
	Position current;
	Position start;
	Position end;
} Solver;

void getPosition (Solver * solver, Maze * maze);
Solver * initSolver (void);
void pushPos (Solver * solver, Maze * maze);
void popPos (Solver * solver);
void checkIfImpossible (Solver * solver);
int checkMove (Solver * solver, Maze * maze, int dir);
void movePos (Solver * solver, Maze * maze);
void printMaze (Maze * maze);
void checkSolved (Solver * solver);
void printRoute (Solver * solver, Maze * maze);



#endif