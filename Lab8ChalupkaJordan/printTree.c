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

	/*
	How to print a word

	char * word = malloc(sizeof(char)*255);
	sprintf(word,"%d %d",maxY,maxX);
	
	mvprintw(15,findMiddleX(maxX,word),word);
	refresh();
	*/
	// Print hello world
	

	// Print some trees
	char * word = "name(rating)";
	mvprintw(0, findMiddleX(maxX,word),word);
	for (int i = 1; i <= 3; i++) {]
		mvprintw(i, findMiddleX(maxX/(2*i),word),word);
		
	}
	refresh();
	// Exit the program
	getchar();
	clear();
	endwin();

	return 0;
}
