#include "main.h"

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

char * getInitialDir (void) {
	char * dirName = malloc(sizeof(char)*255);

	do {
		fprintf(stdout, "Enter a Directory Path: ");
		fgets(dirName, 255, stdin);
		dirName[strlen(dirName)-1] = '\0';
	} while (openDirectory(dirName) == NULL);

	return dirName;
}

char * changeParentDir (char * dir) {
	int changed = chdir(dir);
	if (changed == -1) {
		REPORT_ERROR();
		return NULL;
	}

	return dir;
}

char * getPartentDir (char * buffer) {
	getcwd(buffer,255);

	return buffer;
}


void cleanStdin (void) {
	while (getchar() != '\n');
	return;
}

int main (int argc, char * argv[]) {
	
	char * parentDir = malloc(sizeof(char)*255);

	//Make sure the arguements are correct
	if (argc == 2 && openDirectory(argv[1])) {
		strcpy(parentDir, argv[1]);
	} else {
		parentDir = getInitialDir();
	}

	
	BinTree * tree = createBinTree(compareStrings, destroyBinTree);
	insertBinTree(tree, parentDir);
	traverseDir(tree, parentDir);
	changeParentDir(parentDir);
	// Menu here


	int start = 1;
	char * currentDir = malloc(sizeof(char)*255);
	strcpy(currentDir, parentDir);

	char * choice[] = {"Move", "Delete", "Rename", "Insert", "View Tree", "Print Tree"};

	printTree(tree->root);
	while (start) {
		//fprintf(stdout, "Currently at: %s\n",getPartentDir(parentDir));
		fprintf(stdout, "Would you like to:\n");
		for (int i = 0; i < 6; i++) {
			fprintf(stdout, "  %d: %s\n", i, choice[i]);
		}
		int input = -1;
		if (input == -1) {
			scanf("%d", &input);
			cleanStdin();
		}
		
		

		switch (input) {
			case 0:
				fprintf(stdout, "Moving\n");
				moveOption();
				break;

			case 1:
				fprintf(stdout, "Delete\n");
				deleteOption();
				break;

			case 2:
				fprintf(stdout, "Rename\n");
				
				char* fileName, *newName;

				fileName = malloc(sizeof(char)*255);
				newName = malloc(sizeof(char)*255);

				printf("What file would you like to rename?\n");
				scanf("%s", fileName);
				

				printf("What would you like to name it?\n");
				scanf("%s", newName);
				

				renameOption(tree, fileName, newName);
				printf("%s %s\n", fileName, newName);
				break;

			case 3:
				fprintf(stdout, "Insert\n");
				insertOption();
				break;

			case 4:
				fprintf(stdout, "View Tree\n");
				viewTreeOption(tree);
				break;

			case 5:
				fprintf(stdout, "Print Tree\n");
				printTree(tree->root);
				break;

			default:
				printf("Invalid, this is not an option, try again.\n");	
				continue;	
		}

		// Don't touch
		getchar();
	}
	


	return 0;
}