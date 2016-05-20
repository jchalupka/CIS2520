#Made by Jordan Chalupka February 28 2016
#0928258

.PHONY: clean tab run

SOURCEDIR=src/

EXECUTABLE=test
FLAGS=-Wall -ansi
CC=gcc $(FLAGS) -Iinclude
RM=rm

LIBRARY=
SOURCES=$(wildcard src/*.c)
INCLUDES=$(wildcard include/*.h)
OBJECTS=$(SOURCES:.c=.o)

#Main target
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LIBRARY)

clean:
	$(RM) $(OBJECTS) $(EXECUTABLE)

tab: $(SOURCES) $(INCLUDES)
	/Users/JordanChalupka/my_shells/tab_shell.sh $(SOURCES) 
	/Users/JordanChalupka/my_shells/tab_shell.sh $(INCLUDES)

run: $(EXECUTABLE)
	./$(EXECUTABLE)