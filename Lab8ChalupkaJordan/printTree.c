#include "printTree.h"

int main (void) {
	// Set up ncureses
	initscr();
	noecho();
	cbreak();
	curs_set(0);

	// Get the size of the treee
	int maxY, maxX;
	getmaxyx(stdscr,maxY,maxX);
	mvprintw(15,0,"%d %d",maxY,maxX);

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
