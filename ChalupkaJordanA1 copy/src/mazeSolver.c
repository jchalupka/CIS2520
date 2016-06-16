#include "mazeSolver.h"

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

Solver * initSolver (void) {
	Solver * solver = malloc(sizeof(Solver));
	solver->route = malloc(sizeof(Stack));

	solver->solved = 0;
	return solver;
}

void pushPos (Solver * solver, Maze * maze) {
	Position current = solver->current;
	int y = current.y;
	int x = current.x;
	maze->mazeBinary[y][x] = 1;
	
	Position * curAdr = malloc(sizeof(Position));
	*curAdr = current;
	stack_push(solver->route, curAdr);

	return;
}

void popPos (Solver * solver) {
	Position current = solver->current;
	int y = current.y;
	int x = current.x;
	stack_pop(solver->route);
	checkIfImpossible(solver);
	solver->current = *(Position*)stack_peek(solver->route);

	return;
}

void checkIfImpossible (Solver * solver) {
	if (stack_peek(solver->route) == NULL) {
		printf("This maze cannot be solved.\n");
		exit(1);
	}
}

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
	if (maze->mazeBinary[y][x] <= 0) {
		// Put this before?
		maze->mazeBinary[y][x] = 1;
		solver->current.x = x;
		solver->current.y = y;
		
		return 1;
	}  else {
		return 0;
	}
}

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
		popPos(solver);
	}
	return;
}

void printMaze (Maze * maze) {
	for (int i = 0; i < maze->height; i++) {
		for (int j = 0; j < maze->width; j++) {
			printf("%c",maze->mazeMap[i][j]);
		}
		printf("\n");
	}
}

void checkSolved (Solver * solver) {
	if (solver->end.x == solver->current.x && solver->end.y == solver->current.y) {
		solver->solved =1;
		printf("Solved!\n");
	}
}

void printRoute (Solver * solver, Maze * maze) {
	int x;
	int y;

	while (!stack_isEmpty(solver->route)) {
		x = (*(Position*)stack_peek(solver->route)).x;
		y = (*(Position*)stack_peek(solver->route)).y;
		if (maze->mazeMap[y][x] != 'S' && maze->mazeMap[y][x] != 'F') {
			maze->mazeMap[y][x] = '@';
		}
		stack_pop(solver->route);
	}
	return;
}

int main (void) {
	// Initialize the solver struct
	Solver * solver = initSolver();
	// Get the maze struct
	Maze * maze = getMaze();
	// Get the important positions from the maze
	getPosition(solver,maze);
	// Create a route stack
	solver->route = stack_create();
	solver->current = solver->start;
	pushPos(solver, maze);
	while (!solver->solved) {
		movePos(solver,maze);
		checkSolved(solver);
	}
	printRoute(solver,maze);
	printMaze(maze);

	return 0;
}
















