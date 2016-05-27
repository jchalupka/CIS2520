CC          =	gcc
# Flags that are sent to the compiler
# Do not change these
CFLAGS      =	-c -Wall -ansi
LDFLAGS     =

#Directories where the compiler can find things
INCLUDES    = -Iinclude
LIBDIRS     = 
LIBRARYS    = 

# add directory names here if you want to separate files by directories
BINDIR = bin/
SOURCEDIR   = src/
INCLUDEDIR  = include/
OBJDIR      = obj/

#Put the names of your source code file in the lines below.  

SOURCES = $(wildcard $(SOURCEDIR)*c)

#The list of object files is below.  The object file names here must match the file names of your source code 
# except with .o instead of .c.   Make changes as appropriate

OBJECTS = $(SOURCES:.c=.o)

#The names of the binary programs that will be produced.  
#
PROGNAME = $(BINDIR)test


all : $(PROGNAME)

$(PROGNAME): $(OBJECTS)
	$(CC) $(LIBDIRS) $(LDFLAGS) $(addprefix $(OBJDIR),$(notdir $(OBJECTS))) $(LIBS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $(OBJDIR)$(notdir $@) $(INCLUDES)

.PHONY: clean run

clean:
	rm obj/*.o
	rm bin/test

run:
	./bin/test
