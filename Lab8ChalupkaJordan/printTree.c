#include "printTree.h"

int findMiddleX(int maxX, char * word) {
	int pos = (maxX/2) - (strlen(word)/2);

	return pos;
}

void printTrees (int level, int curWidth, int initWidth, int leftOrRight) {
	// Recursive function to print trees
	if (level == 6) {
		return;
	}

	// Print the left tree
	printTrees (level + 1, curWidth/2, initWidth, 1);

	//if (leftOrRight) {
		//left
		mvprintw(level, findMiddleX(curWidth, "X"),"X");
	//} else {
		// right
		mvprintw(level, findMiddleX(curWidth, "X") + curWidth/2, "X");
	//}

	// Print the right tree
	printTrees (level + 1, curWidth/2, initWidth, 0);

	return;
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
	printTrees(0, maxX, maxX, 0);
	refresh();
	// Exit the program
	getchar();
	clear();
	endwin();

	return 0;
}
