/*
Jordan Chalupka 0928258
This file contains functions used to manipulate the phone book.
*/
#include "tools.h"

// Sort by first name
void addSortedFirst (Node * list, ContactInfo * info) {
	char * firstName = info->firstName;
	char * firstOrderName = (char*)((ContactInfo*)getFrontValue(list))->firstName;
	if (strcmp(firstName,firstOrderName) ==  0) {
		// If the names are identical, just put this name first
		addFront(list,info);
	}
	else if (strcmp(firstName,firstOrderName) < 0) {
		addFront(list,info);
	}
	else {
		list = list->next;
		addSortedLast(list,info);
	}

	return;
}

// Sort by last name (This function is recursive)
void addSortedLast (Node * list, ContactInfo * info) {
	// If this is the first item in the list no sorting is needed
	if (getFrontValue(list) == NULL) {
		addFront(list,info);

		return;
	}
	//Pick a spot to insert the new name
	char * lastName = info->lastName;
	char * orderName = (char*)((ContactInfo*)getFrontValue(list))->lastName;

	if (strcmp(lastName,orderName) == 0) {
		// Sort by first name
		addSortedFirst(list,info);
	}
	else if (strcmp(lastName,orderName) < 0) {
		// Exit recursive
		addFront(list,info);
	}else {
		list = list->next;
		// Recursive Function
		addSortedLast(list,info);
	}

	return;
}

// Creates an associated array for the phone book and enters the list into the hashtable
AArray * makeAArray (Node * list) {
	Node * listTemp = list;
	AArray * hashTable = createAAray(getLength(list));
	while (listTemp->next != NULL) {
		char * phoneNumber = ((ContactInfo*)getFrontValue(listTemp))->phoneNumber;
		
		ContactInfo * thisData = malloc(sizeof(ContactInfo));
		thisData->lastName = ((ContactInfo*)getFrontValue(listTemp))->lastName;
		thisData->firstName = ((ContactInfo*)getFrontValue(listTemp))->firstName;
		hashInsert(hashTable, phoneNumber, thisData);
		listTemp = listTemp->next;
	}

	return hashTable;
}
