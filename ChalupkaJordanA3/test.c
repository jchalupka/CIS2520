// Jordan Chalupka 0928258

// Includes
#include <stdio.h>
#include <string.h>

// DIR struct
#include <dirent.h>
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

char * getPath (void) {
	char * path = getcwd(path, sizeof(char)*255);

	if (path != NULL)
		fprintf(stdout, "current dir %s\n", path);
	else
		 REPORT_ERROR();
	
	return path;
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
			printf("%s\n", dp->d_name);
		}

	} while (dp != NULL);
	printf("\n");
	return;
}

int main (void) {
	// Get the file path of the current directory
	char * path = getPath();

	// Open the directory
	DIR *stream = openPath(path);

	// Read the directory
	readPath(stream);

	// Open another dir?
	DIR * newStream = openPath("..");
	readPath(newStream);

	// Close the directory (maybe not)
	closePath(stream);
	closePath(newStream);

	
	return 0;
}