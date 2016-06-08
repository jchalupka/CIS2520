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

Solver * initSolver (void) {
	Solver * solver = malloc(sizeof(Solver));
	solver->solved = 0;
	return solver;
}

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

void pushPos (Solver * solver) {
	Tile * tile = solver->tile;
	stack_push(solver->route, tile);
	//printf("Move Made\n");

	return;
}

void closeDir (Tile * tile, int dir) {
	switch (dir) {
		case 0:
			tile->left = 0;
			break;
		case 1:
			tile->right = 0;
			break;
		case 2:
			tile->up = 0;
			break;
		case 3:
			tile->down = 0;
			break;
	}

	return;
}	

int noOption (Solver * solver) {
	int options = 4;
	printf("Made it\n");
	Tile* tile = solver->tile;
	if (tile->left) {
		options--;
	}
	if (!tile->right) {
		options--;
	}
	if (!tile->up) {
		options--;
	}
	if (!tile->down) {
		options--;
	}
	if (options == 0) {
		return 1;
	}
	return 0;
}
// Check that the move is valid
void checkMove (Solver * solver, Maze * maze, int dir) {
	Tile * tile = solver->tile;
	int x = tile->position.x;
	int y = tile->position.y;
	switch (dir) {
		// left
		case 0:
			if (x > 0) {
				x--;
			}
			else {
				tile->left = 0;
			}
			break;
		// right
		case 1:
			if (x < maze->width-1) {
				x++;
			}
			else {
				tile->right = 0;
			}
			break;
		// up
		case 2:
			if (y > 0) {
				y--;
			}
			else {
				tile->up = 0;
			}
			break;
		// down
		case 3:
			if (y < maze->height-1) {
				y++;
			}
			else {
				tile->down = 0;
			}
			break;
		default:
			break;
	}
	if (maze->mazeBinary[y][x] == 0 || maze->mazeMap[y][x] == 'F') {
		tile->position.x = x;
		tile->position.y = y;
	}  else {
		closeDir(tile,dir);
		maze->mazeMap[y][x] = '8';
	}

	return;
}

void popPos (Solver * solver) {
	stack_pop(solver->route);
	printf("Poped\n");
	//solver->tile = (Tile*)stack_peek(solver->route);

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

// Move the current position
void movePosition (Solver * solver, Maze * maze) {
	Tile * tile = solver->tile;
	int dir;
	int x = tile->position.x;
	int y = tile->position.y;
	if (tile->left) {
		dir = 0;
	} else if (tile->right) {
		dir = 1;
	} else if (tile->up) {
		dir = 2;
	} else if (tile->down) {
		dir = 3;
	} 
	//printf("DIRECTION %d\n",dir);
	checkMove(solver, maze, dir);
	// If the tile has moved push
	if (x != tile->position.x || y != tile->position.y) {
		pushPos(solver);
		printf("Push\n");
		//printf("Push ALL SHOULD NOW BE 1\n");
		solver->previous = tile->position;
		
			solver->tile = createTile();
			if (dir == 0) {
				solver->tile->right = 0;
			}
			if (dir == 1) {
				solver->tile->left = 0;
			}
			if (dir == 2) {
				solver->tile->down = 0;
			}
			if (dir == 3) {
				solver->tile->up =0;
			}
		
		solver->tile->position = solver->previous;
		int tileX = tile->position.x;
        int tileY = tile->position.y;
        maze->mazeMap[tileY][tileX] = '$';
		
	} 
	// Else border was hit
	printf("POSITION %d %d\n",tile->position.x,tile->position.y);
	return;
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
			maze->mazeMap[y][x] = '@';
		}
		stack_pop(solver->route);
		
	}

}


int main (void) {
	// Initialize the solver struct
	Solver * solver = initSolver();
	// Get the maze struct
	Maze * maze = getMaze();
	Maze * mazeCpy = getMaze();
	// Get the important positions from the maze
	getPosition(solver,mazeCpy);
	// Create a route stack
	solver->route = stack_create();
	// Create a tile struct
	solver->tile = createTile();
	// Give the solver struct the current position
	solver->tile->position.x = solver->start.x;
	solver->tile->position.y = solver->start.y;
	pushPos(solver);

	// Begin maze solving algorithm
	while (!solver->solved) {
		getchar();
		// Each loop will move the position
		Tile * tile = solver->tile;
		int* left = &(tile->left);
		int* right = &(tile->right);
		int* up = &(tile->up);
		int* down = &(tile->down);
		
		int tileX = solver->tile->position.x;
		int tileY = solver->tile->position.y;
		// Check if there needs to be a pop
		if ((*left || *right || *up || *down) && !solver->solved) {
			movePosition(solver,mazeCpy);
			
		} 
		// There needs to be a pop
		else if (!solver->solved){
			int tileX = solver->tile->position.x;
			int tileY = solver->tile->position.y;
			// Update Maze
			mazeCpy->mazeBinary[tileY][tileX] = 1;
			// Pop the tile
			//printf("THIS IS WHERE I POPPED %d %d\n",tileX,tileY);
			mazeCpy->mazeBinary[tileY][tileX] = 1;
			popPos(solver);
			tileX = solver->tile->position.x;
			tileY = solver->tile->position.y;
			
			//printf("THIS IS WHERE I POPPED %d %d\n",tileX,tileY);
			solver->tile = stack_peek(solver->route);
		}
		checkSolved(solver);
		printMaze(mazeCpy);
		// Update the tile
		tile = (Tile*)stack_peek(solver->route);
		left = &(tile->left);
		right = &(tile->right);
		up = &(tile->up);
		down = &(tile->down);

		//printf("left %d right %d up %d down %d\n", *left, *right, *up, *down);

		// Only push when a new move has been made
		// This will lock in all of the last tried directions


		// Each push will be the first time in the next tile
		// So each tile will need to have all of the moves unlocked after the last push (Except for the direction it came from)


		// Otherwise just keep altering the current top
		// Make the tried direction 0;
	}

	printRoute(solver, maze);
	printMaze(maze);

}