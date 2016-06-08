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
	Position currentPos;
	Position startPos;
	Position endPos;
} Solver;
#endif

typedef struct tile {
	int left;
	int right;
	int up;
	int down;
	Position position;
} Tile;

void unlockMoves (Solver * solver) {
	Tile * tile = (Tile*)solver->route;
	tile-> left = 1;
	tile-> right = 1;
	tile-> up = 1;
	tile-> down = 1;
	return;
}

Solver * initSolver (void) {
	Solver * solver = malloc(sizeof(Solver));
	unlockMoves(solver);
	solver-> solved = 0;
	return solver;
}

int checkForward (Solver * solver, Maze * maze, int dir) {
	/*Check if the direction is valid*/
	int x = solver->currentPos.x;
	int y = solver->currentPos.y;
	switch (dir) {
		// left
		case 0:
		/*Switch these to x and y*/
			if (x > 0) {
				x--;
			}
			else {
				return 0;
			}
			break;
		// right
		case 1:
			if (x < maze->width-1) {
				x++;
			}
			else {
				return 0;
			}
			break;
		// up
		case 2:
			if (y > 0) {
				y--;
			}
			else {
				return 0;
			}
			break;
		// down
		case 3:
			if (y < maze->height-1) {
				y++;
			}
			else {
				return 0;
			}
			break;
		default:
			break;
	}
	int preX = ((Tile*)stack_peek(solver->route))->position.x;
	int preY = ((Tile*)stack_peek(solver->route))->position.y;
	int repeatMove = 0;
	if (preX == x && preY == y) {
		printf("Repeat found\n");
		repeatMove = 1;
	}
	//printf("%d,%d vs %d,%d\n",preX,preY,x,y);
	if (maze->mazeBinary[y][x] <= 0 && !repeatMove) {
		solver->currentPos.x = x;
		solver->currentPos.y = y;
		return 1;
	}
	else {
		/*Just set back to original here*/
		return 0;
	}
	return 0;
}

void zeroMove (Solver * solver, int dir) {
	switch (dir) {
		case 0:
			solver->left = 0;
			break;
		case 1:
			solver->right = 0;
			break;
		case 2:
			solver->up = 0;
			break;
		case 3:
			solver->down = 0;
			break;
		default:
			break;
	}
	return;
}

void zeroOpposite (Solver * solver, int dir) {
	switch (dir) {
		case 0:
			solver->right = 0;
			break;
		case 1:
			solver->left = 0;
			break;
		case 2:
			solver->down = 0;
			break;
		case 3:
			solver->up = 0;
			break;
	}
}

int noMove (Solver * solver) {
	int right = solver->right;
	int left = solver->left;
	int up = solver->up;
	int down = solver->down;
	if (!(right || left || up || down)) {
		return 1;
	}
	else return 0;
}

void popMove(Solver * solver) {
	stack_pop(solver->route);
}

void moveBack (Solver * solver) {
	while (noMove(solver)) {
		popMove(solver);
	}
	return;
}

void checkSolved (Solver * solver) {
	int curX = solver->currentPos.x;
	int curY = solver->currentPos.y;
	int endX = solver->endPos.x;
	int endY = solver->endPos.y;
	if (curX == endX && curY == endY) {
		solver->solved = 1;
		printf("SOLVED\n");
	}
	printf("%d,%d\n",curX,curY);
	return;
}

void getPosition (Solver * solver, Maze * maze) {
	for (int i = 0; i < maze->height; i++) {
		for (int j = 0; j < maze->width; j++) {
			char mazeChar = maze->mazeMap[i][j];
			if (mazeChar == 'S') {
				solver->startPos.y = i;
				solver->startPos.x = j;
				solver->currentPos = solver->startPos;

			}
			if (mazeChar == 'F') {
				solver->endPos.y = i;
				solver->endPos.x = j;
			}
		}
	}

	return;
}

void pushPos (Solver * solver) {
	/*Push the current position onto the stack*/
	Tile * tile = malloc(sizeof(Tile));

	tile->position = solver->currentPos;

	stack_push(solver->route,tile);

}

void pushMoves (Solver * solver) {
	Tile * tile = (Tile*)stack_peek(solver->route);
	tile->left = solver->left;
	tile->right = solver->right;
	tile->up = solver->up;
	tile->down = solver->down;

}

void moveForward (Solver * solver, Maze * maze, int dir) {
	/*Take this step out, just one step*/
	if (checkForward(solver, maze, dir)) {
		/*Move is valid*/
		
		/*Move forward*/
		/*Make all moves valid again*/
		unlockMoves(solver);
		zeroOpposite(solver,dir);
		/*Push the position onto the stack*/
		pushPos(solver);
		pushMoves(solver);
	

		/*Check if solved*/
		checkSolved(solver);
		return;
	}
	/* ELSE Move is invalid*/
	zeroMove(solver, dir);
	pushMoves(solver);
	return;	
}

int main (void) {
	Solver * solver = initSolver();
	Maze * maze = getMaze();
	getPosition(solver, maze);
	/*Push the current position onto the stack*/
	solver->route = stack_create();
	pushPos(solver);
	/*Didn't make it here*/
	printf("Made it\n");
	/*Check if the maze is at the end*/
	while (!solver->solved) {
		/*Check available directions*/
		/*Push (FORWARD)*/
		Tile * tile = (Tile*)stack_peek(solver->route);
		if (tile->left) {
			moveForward(solver,maze,0);
		}
		else if (tile->right) {
			moveForward(solver,maze,1);
		}
		else if (tile->up) {
			moveForward(solver,maze,2);
		}
		else if (tile->down) {
			moveForward(solver,maze,3);
		}
		/*Or Pop (BACK)*/
		else {
			printf("This happened\n");
			moveBack(solver);
		}
	}

	return 0;
}

