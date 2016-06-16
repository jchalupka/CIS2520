/*
    Jordan Chalupka
    0928258
*/

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

/*
Get the start and end positions of the maze.
Pre:  Solver struct and maze struct are initialized.
Post: Start and end positions are added to solver struct, or if they are not found the program exits.
*/
void getPosition (Solver * solver, Maze * maze);

/*
Malloc memory and initiate variables for the solver struct.
Pre: None.
Post: Memory is malloced and assigned to the solver struct, solved is set to false.
*/
Solver * initSolver (void);

/*
Push the current position onto the stack.
Pre: Solver struct and maze struct are initialized, and the stack in solver has been created.
Post: The top of the stack is now the current position, and the map of the current position is set to 1 (not enterable).
*/
void pushPos (Solver * solver, Maze * maze);

/*
Pop the top of the stack, setting the current position to the previous position on the stack.
Pre: Solver struct has been initialized, and the struct stack has been created and pushed atleast once.
Post: The top of the stack is now the previous position.
*/
void popPos (Solver * solver);

/*
Check if the maze can be solved, a maze cannot be solved if a pop is attempted on an empty stack.
Pre: Solver struct is initialized.
Post: If the maze cannot be solved a message is given and the program is exited.
*/
void checkIfImpossible (Solver * solver);

/*
Check if the move being attempted is allowed.
Pre: Solver struct, and maze struct are initialized and the dir is between 0 and 3.
Post: An integer is returned, 1: move is allowed, 0: move is not allowed.
*/
int checkMove (Solver * solver, Maze * maze, int dir);

/*
Move the current position either left, right, up, down, or back.
Pre: Solver and maze structs are initialized.
Post:  The current position is moved either left, right, up, down or back.
*/
void movePos (Solver * solver, Maze * maze);

/*
Print the maze onto the screen.
Pre: Maze struct is initialed maze->mazeMap is populated.
Post: Maze is printed to the screen.
*/
void printMaze (Maze * maze);

/*
Check if the maze is solved.
Pre: Solver struct is initialized.
Post: If the maze is solved, solver->solved is set to 1.
*/
void checkSolved (Solver * solver);

/*
Put the characters for the route of the sollution to the maze onto the maze struct.
Pre: The solver and maze struct are initialized, and the solver struct route stack is created.
Post: The route is now represented on the maze map.
*/
void printRoute (Solver * solver, Maze * maze);

/*
Solves the maze, calling all other functions.
Pre: The name of the maze is entered as a string
Post: The maze has been solved and a correct solution is output to the screen.
*/
void solveMaze (char * mazeName);

#endif
