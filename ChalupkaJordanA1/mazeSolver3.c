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

typedef struct tile {
	int left;
	int right;
	int up;
	int down;
	// May need to be pointer
	Position position;
} Tile;

typedef struct solver {
	int solved;
	Stack * route;
	Tile * tile;
	// These may need to be pointers
	Position previous;
	Position start;
	Position end;
} Solver;


#endif

void getPosition (Solver * solver, Maze * maze) {
	for (int i = 0; i < maze->height; i++) {
		for (int j = 0; j < maze->width; j++) {
			char mazeChar = maze->mazeMap[i][j];
			if (mazeChar == 'S') {
				solver->start.y = i;
				solver->start.x = j;
			}
			if (mazeChar == 'F') {
				solver->end.y = i;
				solver->end.x = j;
			}
		}
	}

	return;
}

Solver * initSolver (void) {
	Solver * solver = malloc(sizeof(Solver));
	solver->solved = 0;
	return solver;
}

void unlockMoves (Tile * tile) {
	tile->left = 1;
	tile->right = 1;
	tile->up = 1;
	tile->down = 1;

	return;
}

Tile * createTile (void) {
	Tile * tile = malloc(sizeof(Tile));
	unlockMoves(tile);
	return tile;
}

void closeDir (Tile * tile, int dir) {
	switch (dir) {
		case 0:
			printf("Closing left\n");
			tile->left = 0;
			break;
		case 1:
			printf("Closing right\n");
			tile->right = 0;
			break;
		case 2:
			printf("Closing up\n");
			tile->up = 0;
			break;
		case 3:
			printf("Closing down\n");
			tile->down = 0;
			break;
	}

	return;
}

int checkMove (Solver * solver, Maze * maze, int dir) {
	Tile * tile = solver->tile;
	int x = tile->position.x;
	int y = tile->position.y;
	switch (dir) {
		// left
		case 0:
			if (x > 0 ) {
				x--;
			}
			else {
				tile->left = 0;
				return 0;
			}
			break;
		// right
		case 1:
			if (x < maze->width-1 ) {
				x++;
			}
			else {
				tile->right = 0;
				return 0;
			}
			break;
		// up
		case 2:
			if (y > 0 ) {
				y--;
			}
			else {
				tile->up = 0;
				return 0;
			}
			break;
		// down
		case 3:
			if (y < maze->height-1 ) {
				y++;
			}
			else {
				tile->down = 0;
				return 0;
			}
			break;
		default:
			break;
	}
	if (maze->mazeBinary[y][x] <= 0) {
		// Put this before?
		maze->mazeBinary[tile->position.y][tile->position.x] = 1;
		tile->position.x = x;
		tile->position.y = y;
		
		return 1;
	}  else {
		closeDir(tile,dir);
		maze->mazeMap[y][x] = '8';
		return 0;
	}
}

void pushTile (Solver * solver, Maze * maze) {
	// Put tile on the maze
	Tile * tile = solver->tile;
	int y = tile->position.y;
	int x = tile->position.x;
	maze->mazeMap[y][x] = '@';
	maze->mazeBinary[y][x] = 1;
	solver->previous = solver->tile->position;
	stack_push(solver->route, tile);
	solver->tile = createTile();
	solver->tile->position = solver->previous;

	printf("Pushing\n");
	return;
}

void popTile (Solver * solver, Maze * maze) {
	// Pop tile from the maze
	Tile * tile = (Tile*)stack_peek(solver->route);
	int y = tile->position.y;
	int x = tile->position.x;
	maze->mazeMap[y][x] = '!';
	stack_pop(solver->route);
	solver->tile = (Tile*)stack_peek(solver->route);
	//maze->mazeMap[y][x] = '!';
	y = solver->tile->position.y;
	x = solver->tile->position.x;
	
	//maze->mazeBinary[y][x] = 0;

	if (solver->tile == NULL) {
		printf("This maze has no solution\n");
		exit(1);
	}	
	printf("Poping\n");

	return;
}

void moveTile (Solver * solver, Maze * maze) {
	if (checkMove(solver,maze,0)) {
		// Move is clear
		pushTile(solver, maze);
		//solver->tile->right = 0;
		printf("LEFT\n");

	} else if (checkMove(solver,maze,1)) {
		pushTile(solver, maze);
		//solver->tile->left = 0;
		printf("RIGHT\n");

	} else if (checkMove(solver,maze,2)) {
		pushTile(solver, maze);
		//solver->tile->down = 0;
		printf("UP\n");

	} else if (checkMove(solver,maze,3)) {
		pushTile(solver, maze);
		//solver->tile->up = 0;
		printf("DOWN\n");
	} else {
		//popTile(solver);
		popTile(solver, maze);


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
	if (solver->end.x == solver->previous.x && solver->end.y == solver->previous.y) {
		solver->solved =1;
		printf("Solved! %d %d\n",solver->previous.x, solver->previous.y);
	}
}

void printRoute (Solver * solver, Maze * maze) {
	int x;
	int y;

	while (!stack_isEmpty(solver->route)) {
		x = ((Tile*)stack_peek(solver->route))->position.x;
		y = ((Tile*)stack_peek(solver->route))->position.y;
		printf("%d %d\n",x,y);
		if (maze->mazeMap[y][x] != 'S' && maze->mazeMap[y][x] != 'F') {
			maze->mazeMap[y][x] = 'X';
		}
		stack_pop(solver->route);
		
	}

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
	// Create a tile struct
	solver->tile = createTile();
	// Give the solver struct the current position
	solver->tile->position.y = solver->start.y;
	solver->tile->position.x = solver->start.x;
	pushTile(solver, maze);
	while (!solver->solved) {
		//getchar();
		// The tile will be moved each turn
		moveTile(solver,maze);
		printf("%d %d\n",solver->tile->position.y, solver->tile->position.x);
		printf("left %d right %d up %d down %d\n",solver->tile->left, solver->tile->right, solver->tile->up, solver->tile->down);
		//printBinary(maze);
		printMaze(maze);
		checkSolved(solver);
	}
	maze = getMaze();
	printRoute(solver,maze);
	printMaze(maze);
	stack_destroy(&solver->route);
	free(solver);
	free(maze->mazeBinary);
	free(maze->mazeMap);
	free(maze);

	return 0;
}