CC          =	gcc
# Flags that are sent to the compiler
# Do not change these
CFLAGS      =	-std=c99 -Wall -g
LDFLAGS     =

#Directories where the compiler can find things
INCLUDES    = -Iinclude
LIBDIRS     = 
LIBS        = 

# add directory names here if you want to separate files by directories
BINDIR = bin/
SRCDIR = src/
OBJDIR = obj/

#Put the names of your source code file in the lines below.  

SOURCE = $(SRCDIR)ListADT.c $(SRCDIR)StackADT.c $(SRCDIR)mazeReader.c 

#The list of object files is below.  The object file names here must match the file names of your source code 
# except with .o instead of .c.   Make changes as appropriate


OBJ    = $(OBJDIR)ListADT.o $(OBJDIR)StackADT.o $(OBJDIR)mazeReader.o


#The names of the binary programs that will be produced.  
#
MAZE_PROGNAME     = $(BINDIR)solveMaze
STACK_PROGNAME    = $(BINDIR)testStack
TESTMAZE_PROGNAME = $(BINDIR)testMaze


default : mazeLink stackLink mazeTestLink

mazeLink: mazeCompile
	$(CC) $(LIBDIRS) $(LDFLAGS) -o $(MAZE_PROGNAME) $(OBJ) obj/mazeSolver.o obj/mazeProg.o $(LIBS)

stackLink: stackCompile
	$(CC) $(LIBDIRS) $(LDFLAGS) -o $(STACK_PROGNAME) $(OBJ) obj/stackTest.o $(LIBS)

mazeTestLink: mazeTestCompile
	$(CC) $(LIBDIRS) $(LDFLAGS) -o $(TESTMAZE_PROGNAME) $(OBJ) obj/mazeSolver.o obj/mazeTest.o $(LIBS)

mazeCompile: 
	$(CC) $(CFLAGS) -c $(SOURCE) $(INCLUDES) src/mazeSolver.c src/mazeProg.c
	mv *.o obj/

stackCompile:
	$(CC) $(CFLAGS) -c $(SOURCE) $(INCLUDES) src/stackTest.c
	mv *.o obj/

mazeTestCompile:
	$(CC) $(CFLAGS) -c $(SOURCE) $(INCLUDES) src/mazeSolver.c src/mazeTest.c
	mv *.o obj/

clean:
	rm obj/*.o
	rm bin/*