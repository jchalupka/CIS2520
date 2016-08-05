// Jordan Chalupka 0928528
#include "main.h"


char * getStdin (char * word) {
	fgets(word, 255, stdin);
	word[strlen(word)-1] = '\0';

	return word;
}

char * getInitialDir (void) {
	char * dirName = malloc(sizeof(char)*255);

	do {
		fprintf(stdout, "Enter a Directory Path: ");
		getStdin(dirName);
	} while (openDirectory(dirName) == NULL);

	return dirName;
}

char * changeParentDir (char * dir) {
	int changed = chdir(dir);
	if (changed == -1) {

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
	getPartentDir(parentDir);
	// Menu here


	int start = 1;
	char * currentDir = malloc(sizeof(char)*255);
	strcpy(currentDir, parentDir);

	char * choice[] = {"Move", "Delete", "Rename", "Insert", "View Tree [Diagram]", "View Tree [List]"};

	while (start) {
		fprintf(stdout, "PARENTDIR: %s\n", parentDir);
		//fprintf(stdout, "Currently at: %s\n",getPartentDir(parentDir));
		fprintf(stdout, "Would you like to:\n");
		for (int i = 0; i < 6; i++) {
			fprintf(stdout, "  %d: %s\n", i, choice[i]);
		}		

		int input = getchar() - '0';
		cleanStdin();
		switch (input) {
			case 0:
				fprintf(stdout, "Moving\n");
				//Change the current working directory
				char * toMove = malloc(sizeof(char)*255);
				printf("Where would you like to move?\n");
				getStdin(toMove);
				char * temp = malloc(sizeof(char)*255);
				sprintf(temp, "./%s", toMove);
				
				
				if (openDirectory(temp) != NULL) {
					printf("This is what I said %s\n", temp);
					//strcpy(toMove, temp);
					printf("Current dir changed\n");
					printf("Updating Tree\n");
					tree = createBinTree(compareStrings,destroyBinTree);
					insertBinTree(tree, temp);
					traverseDir(tree, temp);
					getPartentDir(temp);
					

				}
				else printf("This is not a directory\n");


				moveOption();
				break;

			case 1:
				fprintf(stdout, "Delete\n");
				char * toDelete = malloc(sizeof(char)*255);
				printf("Which file would you like to delete?\n");
				getStdin(toDelete);
				deleteOption(tree, toDelete);
				break;

			case 2:
				fprintf(stdout, "Rename\n");
				
				char* fileName, *newName;

				fileName = malloc(sizeof(char)*255);
				newName = malloc(sizeof(char)*255);

				printf("What file would you like to rename?\n");
				getStdin(fileName);


				printf("What would you like to name it?\n");
				getStdin(newName);
				

				renameOption(tree, fileName, newName);
				break;

			case 3:
				fprintf(stdout, "Insert\n");

				char * toInsert = malloc(sizeof(char)*255);
				printf("What would you like to insert?\n");
				getStdin(toInsert);

				char * toInsertPath = malloc(sizeof(char)*255);
				printf("Where would you like to insert %s?\n", toInsert);
				getStdin(toInsertPath);

				insertOption(tree, toInsert, toInsertPath);
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
	}
	


	return 0;
}
