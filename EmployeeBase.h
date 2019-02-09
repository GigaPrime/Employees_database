#pragma once
#include "Employee.h"

Employee* createDataBase(int);					//+		// creates new database with selected size

int getLenght(Employee*);						//+		// returns employees quantity
bool isEmpty(Employee*);						//+		// checks if database is empty
bool isInRange(Employee*, int);					//+		// chaecks if element is within database borders
bool isElementEmpty(Employee*, int);			//+		// cheks if selected element is empty
int getNextEmptyElement(Employee*);				//+		// returns index of first empty element in database

Employee* increaseDataBaseSize(Employee*);				// increases size of the database
Employee* copyDataBase(Employee*, Employee*);			// copies the database

Employee pop(Employee*, int);					//+
Employee* pop(Employee*, double);				//+		// pops by salary
void push(Employee*, Employee);					//+
void remove(Employee*, int);					//+
void sort(Employee*);							//+		// sorts by second name
int isNameBigger(Employee*, int, int);			//+		// compares two structs by name field & returns bigger one