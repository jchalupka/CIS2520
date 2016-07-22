#include "printTree.h"

int findMiddleX(int maxX, char * word) {
	int pos = (maxX/2) - (strlen(word)/2);

	return pos;
}


void printTree (int level, int startPos, int endPos) {
	if (level >= 16) {
		return;
	}
	static int count = 0;
	count ++;
	mvprintw(50,50,"%d",count);
	int newSplit = (startPos + endPos)/2;
	printTree (level + 4, startPos, newSplit);
	
	int wordX = findMiddleX((endPos + startPos),"name(ranking)");
	int midX = findMiddleX((endPos + startPos), "@");

	mvvline(level-4, midX,'@',4);
	if (count%2) {
		mvhline(level-4, midX,'@',5);
	}
	mvprintw (level, wordX,"name(ranking)");

	printTree (level + 4, newSplit, endPos);
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
