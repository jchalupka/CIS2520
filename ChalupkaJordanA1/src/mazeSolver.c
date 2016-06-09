/*
    Jordan Chalupka
    0928258
*/

#include "mazeSolver.h"

// Get the start and end positions of the maze and add them to the solver struct
void getPosition (Solver * solver, Maze * maze) {
	int foundS = 0;
	int foundF = 0;
	for (int i = 0; i < maze->height; i++) {
		for (int j = 0; j < maze->width; j++) {
			char mazeChar = maze->mazeMap[i][j];
			if (mazeChar == 'S') {
				foundS++;
				solver->start.y = i;
				solver->start.x = j;
			}
			if (mazeChar == 'F') {
				foundF++;
				solver->end.y = i;
				solver->end.x = j;
			}
		}
	}
	if (foundS != 1 || foundF != 1) {
		printf("Incorrect Start(S) and Finish(F) Positions\n");
		printf("This maze cannot be solved\n");
		exit(1);
	}

	return;
}

// Create initiate variables and allocate memory for the solver struct
Solver * initSolver (void) {
	Solver * solver = malloc(sizeof(Solver));
	solver->route = malloc(sizeof(Stack));
	solver->solved = 0;

	return solver;
}

// Push the current position onto the stack
void pushPos (Solver * solver, Maze * maze) {
	Position current = solver->current;
	int y = current.y;
	int x = current.x;
	maze->mazeBinary[y][x] = 1;
	
	Position * curAdr = malloc(sizeof(Position));
	*curAdr = current;
	stackPush(solver->route, curAdr);

	return;
}

// Pop the stack to remove the current position and move back
void popPos (Solver * solver) {
	stackPop(solver->route);
	checkIfImpossible(solver);
	solver->current = *(Position*)stackPeek(solver->route);

	return;
}

// Check if this maze has a possible sollution
void checkIfImpossible (Solver * solver) {
	if (stackPeek(solver->route) == NULL) {
		printf("This maze cannot be solved.\n");
		exit(1);
	}
	
	return;
}

// Check if the move is inside the maze boundaries and not hitting any walls
int checkMove (Solver * solver, Maze * maze, int dir) {
	Position current = solver->current;
	int x = current.x;
	int y = current.y;
	switch (dir) {
		// left
		case 0:
			if (x > 0 ) {
				x--;
			}
			else {
				return 0;
			}
			break;
		// right
		case 1:
			if (x < maze->width-1 ) {
				x++;
			}
			else {
				return 0;
			}
			break;
		// up
		case 2:
			if (y > 0 ) {
				y--;
			}
			else {
				return 0;
			}
			break;
		// down
		case 3:
			if (y < maze->height-1 ) {
				y++;
			}
			else {
				return 0;
			}
			break;
		default:
			break;
	}
	// Check if any walls are being hit
	if (maze->mazeBinary[y][x] <= 0) {
		// Walls are 1, Empty is 0, and Start and end are both -1
		maze->mazeBinary[y][x] = 1;
		solver->current.x = x;
		solver->current.y = y;
		
		return 1;
	}

	return 0;
}

// Move the current position
void movePos (Solver * solver, Maze * maze) {
	if (checkMove(solver,maze,0)) {
		// Move is clear
		pushPos(solver, maze);

	} else if (checkMove(solver,maze,1)) {
		pushPos(solver, maze);

	} else if (checkMove(solver,maze,2)) {
		pushPos(solver, maze);

	} else if (checkMove(solver,maze,3)) {
		pushPos(solver, maze);
	} else {
		// Move back
		popPos(solver);
	}
	return;
}

// Print out the maze
void printMaze (Maze * maze) {
	for (int i = 0; i < maze->height; i++) {
		for (int j = 0; j < maze->width; j++) {
			printf("%c",maze->mazeMap[i][j]);
		}
		printf("\n");
	}

	return;
}

// Check if the maze is solved
void checkSolved (Solver * solver) {
	if (solver->end.x == solver->current.x && solver->end.y == solver->current.y) {
		solver->solved =1;
		printf("Solved!\n");
	}

	return;
}

// Print out the current route
void printRoute (Solver * solver, Maze * maze) {
	int x;
	int y;

	while (!stackIsEmpty(solver->route)) {
		x = (*(Position*)stackPeek(solver->route)).x;
		y = (*(Position*)stackPeek(solver->route)).y;
		if (maze->mazeMap[y][x] != 'S' && maze->mazeMap[y][x] != 'F') {
			maze->mazeMap[y][x] = '@';
		}
		stackPop(solver->route);
	}
	printMaze(maze);

	return;
}

void solveMaze (void) {
	// Initialize the solver struct
	Solver * solver = initSolver();
	// Get the maze struct
	Maze * maze = getMaze();
	// Get the important positions from the maze
	getPosition(solver,maze);
	// Create a route stack
	solver->route = stackCreate();
	// Set the current position to the start of the maze
	solver->current = solver->start;
	pushPos(solver, maze);
	while (!solver->solved) {
		movePos(solver,maze);
		checkSolved(solver);
	}
	printRoute(solver,maze);
}

int main (void) {
	solveMaze();

	return 0;
}
















