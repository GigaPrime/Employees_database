#include <malloc.h>
#include <iostream>
#include "EmployeeBase.h"
using namespace std;

Employee* createDataBase(int initialSize)
{
	Employee* initialDataBase = new Employee[initialSize];
	for (int i = 0; i < initialSize; i++)
	{
		remove(initialDataBase, i);
	}
	return initialDataBase;
}

int getLenght(Employee* dataBase)
{
	return	_msize(dataBase) / sizeof(Employee);
}

bool isEmpty(Employee* dataBase)
{
	for (int i = 0; i < getLenght(dataBase); i++)
		if (dataBase[i].firstName == '\0' && dataBase[i].lastName == '\0')
			return true;
		else
			return false;
}

bool isInRange(Employee* dataBase, int index)
{
	if (index - 1 <= getLenght(dataBase))
		return true;
	else
		return false;
}

bool isElementEmpty(Employee* dataBase, int index)
{
	if (dataBase[index].firstName == '\0' && dataBase[index].lastName == '\0' && isInRange(dataBase, index))
		return true;
	else
		return false;
}

int getNextEmptyElement(Employee* database)
{
	for (int i = 0; i < getLenght(database); i++)
		if (isElementEmpty(database, i))
			return i;
}

Employee* increaseDataBaseSize(Employee* initialBase)
{
	const int increaseCoef = 2;
	Employee* increasedDataBase = new Employee[getLenght(initialBase) * increaseCoef];
	return increasedDataBase;
}

Employee* copyDataBase(Employee* initialBase, Employee* copiedBase)
{
	try 
	{
		if (_msize(initialBase) > _msize(copiedBase))
			throw "Not enough memory in target base";
	}
	catch (char* exeption) { cout << exeption << endl; }
	for (int i = 0; i < getLenght(initialBase); i++)
		copiedBase[i] = initialBase[i];
}

Employee pop(Employee* dataBase, int index)
{
	try
	{
		if (!isInRange(dataBase, index))
			throw "Out of range";
		else if (dataBase[index].firstName == '\0' && dataBase[index].lastName == '\0')
			throw "No such record";
		else
			return dataBase[index];
	}
	catch (char* exeption) { cout << exeption << endl; }
}

Employee* pop(Employee* database, double salary)
{
	int range = 0;

	for (int i = 0; i < getLenght(database); i++)
		if (database[i].salary == salary)
			range++;

	Employee* newDataBase = createDataBase(range);

	for (int i = 0; i < getLenght(database); i++)
	{
		if (database[i].salary == salary)
			newDataBase[getNextEmptyElement(newDataBase)] = database[i];
	}
	return newDataBase;
}
	
void push(Employee* dataBase, Employee newEmployee)
{
	dataBase[getNextEmptyElement(dataBase)] = newEmployee;
}

void remove(Employee* dataBase, int index)
{
	try
	{
		if (!isInRange(dataBase, index))
			throw "Out of range";
		else
		{
			dataBase[index].firstName = '\0';
			dataBase[index].lastName = '\0';
		}
	}
	catch (char* exeption) { cout << exeption << endl; }
}

void sort(Employee* dataBase)
{
	Employee tmp;
	int lenght = getLenght(dataBase);
	int counter = 1;

	for (int i = 0; i < lenght - 1; i++)
	{
		for (int j = 0; j < lenght - counter; j++)
			if (isNameBigger(dataBase, j, j + 1) == j)
			{
				tmp = dataBase[j];
				dataBase[j] = dataBase[j + 1];
				dataBase[j + 1] = tmp;
			}
		counter++;
	}
}

int isNameBigger(Employee* dataBase, int firstIndex, int secondIndex)
{
	int nameLenght1 = 0;
	do nameLenght1++;
	while (dataBase[firstIndex].lastName[nameLenght1] != '\0');

	int nameLenght2 = 0;
	do nameLenght2++;
	while (dataBase[secondIndex].lastName[nameLenght2] != '\0');

	int smaller = nameLenght1 < nameLenght2 ? nameLenght1 : nameLenght2;

	for (int i = 0; i < smaller; )
	{
		if (dataBase[firstIndex].lastName[i] == dataBase[secondIndex].lastName[i])
			i++;
		else if (dataBase[firstIndex].lastName[i] > dataBase[secondIndex].lastName[i])
			return firstIndex;
		else
			return secondIndex;
	}
}