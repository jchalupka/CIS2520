CC          =	gcc
# Flags that are sent to the compiler
# Do not change these
CFLAGS      =	-std=c99 -Wall -g
LDFLAGS     =

#Directories where the compiler can find things
INCLUDES    = -Iinclude -Ilib
LIBDIRS     = 
LIBS        = -lncurses

# add directory names here if you want to separate files by directories
BINDIR = bin/
SRCDIR = src/
OBJDIR = obj/

#Put the names of your source code file in the lines below.  

SOURCE = $(SRCDIR)main.c $(SRCDIR)getDir.c $(SRCDIR)printTree.c $(SRCDIR)avl.c $(SRCDIR)destroyFunctions.c $(SRCDIR)options.c $(SRCDIR)ErrorMacro.c $(SRCDIR)BinaryTree.c 

#The list of object files is below.  The object file names here must match the file names of your source code 
# except with .o instead of .c.   Make changes as appropriate


OBJ    = $(OBJDIR)main.o $(OBJDIR)getDir.o $(OBJDIR)printTree.o $(OBJDIR)avl.o $(OBJDIR)destroyFunctions.o $(OBJDIR)options.o $(OBJDIR)ErrorMacro.o $(OBJDIR)BinaryTree.o

#The names of the binary programs that will be produced.  

FILE_MANAGER	= $(BINDIR)fileManager

default : link_fileManager

link_fileManager: compile_fileManager
	$(CC) $(LDFLAGS) -o $(FILE_MANAGER) $(OBJ) $(LIBDIRS) $(LIBS) 

compile_fileManager:
	$(CC) $(CFLAGS) -c $(SOURCE) $(INCLUDES)
	mv *.o obj/

clean:
	rm obj/*.o
	rm bin/*

run:
	./bin/fileManager
