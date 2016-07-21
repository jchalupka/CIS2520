#include "printTree.h"

int findMiddleX(int maxX, char * word) {
	int pos = (maxX/2) - (strlen(word)/2);

	return pos;
}


void printTree (int level, int startPos, int endPos) {
	if (level == 4) {
		return;
	}

	printTree (level, startPos, (startPos + endPos)/2);
	mvprintw (level + 1, (findMiddleX(endPos + startPos, "X")),"X");
	getchar();
	refresh();
	printTree (level + 1, (startPos + endPos)/2, endPos);
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
	int endPos = maxX;
	int startPos = 0;
	printTree (startPos, startPos, endPos);
	refresh();
	// Exit the program
	getchar();
	clear();
	endwin();

	return 0;
}
