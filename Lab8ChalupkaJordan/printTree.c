#include "printTree.h"

int main (void) {
	// Set up ncureses
	initscr();
	noecho();
	cbreak();

	// Print hello world
	mvaddstr(0,0,"Hello World");
	vline('@',10);
	refresh();

	// Exit the program
	getchar();
	clear();
	endwin();

	return 0;
}
