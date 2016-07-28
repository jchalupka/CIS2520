CC          =	gcc
# Flags that are sent to the compiler
# Do not change these
CFLAGS      =	-std=c99 -Wall -g
LDFLAGS     =

#Directories where the compiler can find things
INCLUDES    = -Iinclude -ItestFiles
LIBDIRS     = lib/libbintree.a
LIBS        = -lncurses

# add directory names here if you want to separate files by directories
BINDIR = bin/
SRCDIR = src/
OBJDIR = obj/

#Put the names of your source code file in the lines below.  

SOURCE = $(SRCDIR)fileIO.c $(SRCDIR)printTree.c $(SRCDIR)restaurant.c 

#The list of object files is below.  The object file names here must match the file names of your source code 
# except with .o instead of .c.   Make changes as appropriate


OBJ    = $(OBJDIR)fileIO.o $(OBJDIR)printTree.o $(OBJDIR)restaurant.o 

#The names of the binary programs that will be produced.  
#
FUNCTION_TEST	= $(BINDIR)test_f
TREE_TEST	= $(BINDIR)test_t
ORDER_TEST	= $(BINDER)test_o

default : link_function_test link_tree_test link_order_test

link_function_test: compile_function_test
	$(CC) $(LDFLAGS) -o $(FUNCTION_TEST) $(OBJ) $(LIBDIRS) $(LIBS) $(OBJDIR)test.o

compile_function_test:
	$(CC) $(CFLAGS) -c $(SOURCE) $(INCLUDES) $(SRCDIR)test.c
	mv *.o obj/

link_tree_test: compile_tree_test
	$(CC) $(LDFLAGS) -o $(TREE_TEST) $(OBJ) $(LIBDIRS) $(LIBS) $(OBJDIR)printTreeDiagram.o

compile_tree_test:
	$(CC) $(CFLAGS) -c $(SOURCE) $(INCLUDES) $(SRCDIR)printTreeDiagram.c
	mv *.o obj/

link_order_test: compile_order_test
	$(CC) $(LDFLAGS) -o $(ORDER_TEST) $(OBJ) $(LIBDIRS) $(LIBS) $(OBJDIR)order.o

compile_order_test:
	$(CC) $(CFLAGS) -c $(SOURCE) $(INCLUDES) $(SRCDIR)order.c
	mv *.o obj/

clean:
	rm obj/*.o
	rm bin/*

test_f:
	$(FUNCTION_TEST)

test_t:
	$(TREE_TEST)

test_o:
	$(ORDER_TEST)
