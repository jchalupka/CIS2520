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

SOURCE = $(SRCDIR)ListADT.c $(SRCDIR)associativeArray.c $(SRCDIR)fileReader.c $(SRCDIR)menu.c $(SRCDIR)tools.c

#The list of object files is below.  The object file names here must match the file names of your source code 
# except with .o instead of .c.   Make changes as appropriate


OBJ    = $(OBJDIR)ListADT.o $(OBJDIR)associativeArray.o $(OBJDIR)fileReader.o $(OBJDIR)menu.o $(OBJDIR)tools.o


#The names of the binary programs that will be produced.  
#
RUN_PROGNAME     = $(BINDIR)run

default : link

link: compile
	$(CC) $(LIBDIRS) $(LDFLAGS) -o $(RUN_PROGNAME) $(OBJ) $(LIBS)

compile:
	$(CC) $(CFLAGS) -c $(SOURCE) $(INCLUDES)
	mv *.o obj/

clean:
	rm obj/*.o
	rm bin/*