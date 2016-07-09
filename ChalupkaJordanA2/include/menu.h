/*
Jordan Chalupka 0928258
*/
#ifndef __JCHALUPKA_MENU__
#define __JCHALUPKA_MENU__

#include <stdio.h>
#include "associativeArray.h"
#include "ListADT.h"
#include "fileReader.h"
#include "tools.h"

/*
Loads a file and calls a function to open and collect the information
Pre: List is created
Post: File is loaded and information is added to list node
*/
void loadFile (Node * list);

/*
A single entry is added to the list
Pre: List is created
Post: A single entry is added to the list
*/
void addSingleEntry (Node * list);

/*
Print the entire phone list in alphabetical order
Pre: List is created
Post: Phone list is printed in alphabetical order
*/
void printPhoneList (Node * list);

/*
Look up a name using a phone number
Pre: List is created
Post: Name is looked up
*/
void lookUpName (Node * list);

/*
Displays options to the user
Pre: None
Post: None
*/
void optionsMessage (void);

/*
Allows the user to make choice on what they want to do
Pre: List is created
Post: A choice is made
*/
int makeChoice (Node * list);

/*

Pre:
Post:
*/
int optionMenu (Node * list);

#endif