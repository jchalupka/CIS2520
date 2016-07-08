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

SOURCE = $(SRCDIR)sorting.c $(SRCDIR)testing.c
#The list of object files is below.  The object file names here must match the file names of your source code 
# except with .o instead of .c.   Make changes as appropriate


OBJ    = $(OBJDIR)sorting.o $(OBJDIR)testing.o


#The names of the binary programs that will be produced.  
#
TEST_PROGNAME     = $(BINDIR)test

default : testLink

testLink: testCompile
	$(CC) $(LIBDIRS) $(LDFLAGS) -o $(TEST_PROGNAME) $(OBJ) $(LIBS)

testCompile: 
	$(CC) $(CFLAGS) -c $(SOURCE) $(INCLUDES)
	mv *.o obj/
clean:
	rm obj/*.o
	rm bin/*