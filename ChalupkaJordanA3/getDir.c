// This program will take a directory as input and print out all
// of the subdirectories and files.
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <errno.h>

#include "BinaryTree.h"
#include "printTree.h"

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
				fprintf(stdout, "This does not exist.\n");
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

void traverseDir (char * dir, BinTree * tree) {
	DIR *stream = openDirectory(dir);
	
	if (stream == NULL) {
		abort();
	}
	struct dirent *currentDir;
	do {
		currentDir = readdir(stream);
		if (currentDir != NULL) {
			if (currentDir->d_type == DT_DIR  && strcmp(currentDir->d_name, ".") && strcmp(currentDir->d_name, "..")) {
				char newDir[255];
				sprintf(newDir, "%s/%s", dir, currentDir->d_name);
				traverseDir(newDir, tree);
			} else if (currentDir->d_type == DT_REG) {
				// Add to the tree here
				char * path = malloc(sizeof(char)*255);
				sprintf(path, "%s/%s\n", dir, currentDir->d_name);
				insertBinTree(tree, path);
			}
		}
			
	} while (currentDir != NULL);

	closeDirectory(stream);

	return;
}

int main (int argc, char * argv[]) {
	if (argc != 2) {
		fprintf(stdout, "Error, incorrect input\n");
		return -1;
	}
	char dir[255];
	strcpy(dir, argv[1]);

	BinTree *tree = createBinTree(compareStrings, destroyStub);
	traverseDir(dir, tree);
	printTree(tree->root);

	tree = destroyBinTree(tree);
	return 0;
}























