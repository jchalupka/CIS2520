// Jordan Chalupka 0928258

// Includes
#include <stdio.h>
#include <string.h>

// DIR struct
#include <dirent.h>

// Get the path (current working directory)
#include <unistd.h>

// Error handling
#include <errno.h>

#include <stdlib.h>

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

void getPath (char * path ) {
	getcwd(path, sizeof(char)*255);

	if (path == NULL)
		 REPORT_ERROR();
	
	return;
}

DIR * openPath (char * path) {
	DIR *stream = opendir(path);
	
	if (stream == NULL) REPORT_ERROR();

	return stream;
}


void closePath (DIR *stream) {
	int closed = closedir(stream);

	// Will return -1 on Error
	if (closed == -1) REPORT_ERROR();

	return;
}

void readPath (DIR *stream) {
	struct dirent *dp;
	do {
		dp = readdir(stream);
		if (dp != NULL) {
			printf("%d %s\n", dp->d_type, dp->d_name); //d_name is name
		}

	} while (dp != NULL);
	printf("\n");
	return;
}

void changePath (char * path) {
	int changed = chdir(path);
	if (changed == -1) REPORT_ERROR();

	return;
}

int getType () {

	return 1;
}

void readDir (DIR *stream) {
	struct dirent *dp;
	do {
		dp = readdir(stream);
		if (dp != NULL && dp->d_type == DT_DIR)
			printf("%s\n", dp->d_name);
	} while (dp != NULL);
	printf("\n");

	return;
}

void recursivePart (DIR *stream) {


	return;
}

void traverseDir(char * dir) {
	DIR *stream = openPath(dir);
	struct dirent *dp;
	do {
		dp = readdir(stream);
		if (dp != NULL) {
			if (dp->d_type == DT_DIR && strcmp(dp->d_name, ".") && strcmp(dp->d_name, "..")) {
				
				char newDir[255];
				sprintf(newDir, "%s/%s",dir,dp->d_name);
				printf("%s\n",newDir);
				traverseDir(newDir);
			}
				
			if (dp->d_type == DT_REG) 
				printf("%s\n",dp->d_name);
		}
	} while (dp != NULL);

	closePath(stream);

	return;
}

int main (void) {
	traverseDir(".");

	
	return 0;
}
