#include <malloc.h>
#include <iostream>
#include "EmployeeBase.h"
using namespace std;

Employee* createDataBase(int initialSize)
{
	Employee* initialDataBase = new Employee[initialSize] ;
	for (int i = 0; i < initialSize; i++)
	{
		initialDataBase[i] = createEmployee();
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
		if (dataBase[i].firstName == nullptr && dataBase[i].lastName == nullptr)
			return true;
		else
			return false;
}

bool isInRange(Employee* dataBase, int index)
{
	if (index <= getLenght(dataBase))
		return true;
	else
		return false;
}

bool isElementEmpty(Employee* dataBase, int index)
{
	if (dataBase[index].firstName == "\0" && dataBase[index].lastName == "\0" && isInRange(dataBase, index))
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
	Employee* increasedDataBase = new Employee[getLenght(initialBase) * INCREASE_COEF];
	return increasedDataBase;
}

Employee* copyDataBase(Employee* initialBase, Employee* copiedBase)
{
	try 
	{
		if (_msize(initialBase) > _msize(copiedBase))
			throw "--Not enough memory in target base--";
	}
	catch (char* exeption) { cout << exeption << endl; }
	for (int i = 0; i < getLenght(initialBase); i++)
		copiedBase[i] = initialBase[i];
	return copiedBase;
}

Employee shrinkToFit(Employee dataBase)
{
	return dataBase;
}

Employee pop(Employee* dataBase, int index)
{
	Employee blank = createEmployee();

	if (!isInRange(dataBase, index))
	{
		cout << OUT_OF_RANGE;
		return blank;
	}
	else if (dataBase[index].firstName == "\0" && dataBase[index].lastName == "\0")
	{
		cout << EMPTY_RECORD;
		return blank;
	}
	else
		return dataBase[index];
}

Employee* pop(Employee* database, double salary)
{
	int range = 0;

	for (int i = 0; i < getLenght(database); i++)
		if (database[i].salary == salary)
			range++;

	Employee* newDataBase = createDataBase(range);

	for (int i = 0; i < getLenght(database); i++)
		if (database[i].salary == salary)
			newDataBase[getNextEmptyElement(newDataBase)] = database[i];
	
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
			throw OUT_OF_RANGE;
		else
			dataBase[index] = createEmployee();
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
	int nameLenght2 = 0;
	int nameLenght1 = 0;

	do nameLenght1++;
	while (dataBase[firstIndex].lastName[nameLenght1] != '\0');
	
	do nameLenght2++;
	while (dataBase[secondIndex].lastName[nameLenght2] != '\0');

	int smaller = nameLenght1 < nameLenght2 ? nameLenght1 : nameLenght2;

	for (int i = 0; i < smaller; )
	{
		if (dataBase[firstIndex].lastName[i] == dataBase[secondIndex].lastName[i] || dataBase[firstIndex].lastName == "\0" || dataBase[secondIndex].lastName == "\0")
			i++;
		else if (dataBase[firstIndex].lastName[i] > dataBase[secondIndex].lastName[i])
			return firstIndex;
		else
			return secondIndex;
	}
}