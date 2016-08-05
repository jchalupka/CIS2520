// Jordan Chalupka 0928528

#include "getDir.h"

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

int closeDirectory (DIR *stream) {
	int closed = closedir(stream);
 

	return closed;
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
