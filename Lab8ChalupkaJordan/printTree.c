#include "printTree.h"

int findMiddleX(int maxX, char * word) {
	int pos = (maxX/2) - (strlen(word)/2);

	return pos;
}

int main (void) {
	// Set up ncureses
	initscr();
	noecho();
	cbreak();
	curs_set(0);

	// Get the size of the treee
	int maxY, maxX;
	getmaxyx(stdscr,maxY,maxX);
	char * word = malloc(sizeof(char)*255));
	sprintf(word,"%d %d",maxY,maxX);
	mvprintw(15,findMiddleX(maxX,word),word);

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
