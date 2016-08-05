// This program will take a directory as input and print out all
// of the subdirectories and files.
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <errno.h>

#include "BinaryTree.h"
#include "printTree.h"
#include "rename.h"

// Macro for error reporter
#define REPORT_ERROR()											\
do { 															\
	fprintf(stderr, "ERROR: %s\n"								\
	"LINE: %d\n"												\
	"FILE: %s\n"												\
	"%s %s\n\n", 												\
	strerror(errno), __LINE__, __FILE__, __TIME__, __DATE__);	\
} while (0);  // Fixed issue with trailing semicollon & else statement
// End of maco for error reporter

DIR* openDirectory (char * dir) {
	// Try to open (This will confirm if this is a directory)
	DIR *stream = opendir(dir);
	if (stream == NULL) {
		switch (errno) {
			case ENOTDIR:
				fprintf(stdout, "Not a directory.\n");
				break;

			case  EACCES:
				fprintf(stdout, "You do not have access to this directory.\n");
				break;

			case ENOENT:
				fprintf(stdout, "Directory \"%s\" does not exist.\n",dir);
				break;

			default:
				fprintf(stderr,"There was an error when opening the file.\n");
		}
	}

	return stream;
}

void closeDirectory (DIR *stream) {
	int closed = closedir(stream);

	// Will return -1 on Error
	if (closed == -1) REPORT_ERROR();

	return;
}

BinTree* traverseDir (BinTree * tree, char * dir) {
	DIR *stream = openDirectory(dir);
	
	if (stream == NULL) {
		return NULL;
	}
	struct dirent *currentDir;
	do {
		currentDir = readdir(stream);
		if (currentDir != NULL) {
			if (currentDir->d_type == 4 /*DT_DIR*/  && strcmp(currentDir->d_name, ".") && strcmp(currentDir->d_name, "..")) {
				char * newDir = malloc(sizeof(char)*255);
				sprintf(newDir, "%s/%s", dir, currentDir->d_name);
				insertBinTree(tree, newDir);
				traverseDir(tree, newDir);
			} else if (currentDir->d_type == 8/*DT_REG*/) {
				// Add to the tree here
				char * path = malloc(sizeof(char)*255);
				sprintf(path, "%s/%s", dir, currentDir->d_name);
				//sprintf(path, "%s", currentDir->d_name);
				insertBinTree(tree, path);
			}
		}
			
	} while (currentDir != NULL);

	closeDirectory(stream);

	return tree;
}

// int main (int argc, char * argv[]) {
// 	if (argc != 2) {
// 		fprintf(stdout, "Error, incorrect input\n");
// 		return -1;
// 	}
// 	char *dirName = malloc(sizeof(char)*255);
// 	char *dir = malloc(sizeof(char)*255);
// 	sprintf(dir, "%s", argv[1]);
// 	sprintf(dirName, "%s", argv[1]);

// 	BinTree *tree = createBinTree(compareStrings, destroyBinTree);
// 	insertBinTree(tree, dirName);
// 	traverseDir(tree, dir);

// 	// BinNode * node = rightMost(tree->root);
// 	// printf("%s\n", node->data);
	
	
// 	moveNode(tree,"A/B/D","ThisIsAlot");
// 	initNCurses();
// 	traverseInOrder(tree->root,0);
// 	getchar();
// 	exitNCurses();
	

// 	char * word = malloc(sizeof(char)*255);
// 	fgets(word, 255, stdin);
// 	printf("%s\n", word);
// 	//destroyBinTree(tree);
// 	printTree(tree->root);
// 	//BinNode * node = rightMost(tree->root);
// 	//printf("%s\n", node->data);
// 	return 0;
// }























