#include <iostream>
#include <windows.h>
#include "UI.h"
#include "Constants.h"
using namespace std;

char* firstNameInput()
{
	cout << "Enter Your first name: ";
	return nameInput();
}

char* secondNameInput()
{
	cout << "Enter Your second name: ";
	return nameInput();
}

char* nameInput()
{
	char* name = new char[20];
	cin >> name;
	system("cls");
	return name;
}

char* phoneInput()
{
	char* phoneNumber = new char[13];
	cout << "Enter valid phone number in format of: (0XX)XXX-XX-XX: ";
	cin >> phoneNumber;
	if (isPhoneCorrect(phoneNumber))
	{
		system("cls");
		return phoneNumber;
	}
	else
		phoneInput();
}

bool isPhoneCorrect(char* input)
{
	if (input[0] == '(' && input[4] == ')' && input[1] == '0' && input[8] == '-' && input[11] == '-' && input[14] == '\0')
		return true;
	else
	{
		cout << "Phone number is not valid." << endl;
		Sleep(3000);
		system("cls");
		return false;
	}
}

double salaryInput()
{
	double salary;
	cout << "Enter salary: ";
	cin >> salary;
	system("cls");
	return salary;
}


void menu()
{
	int selection;
	int subSelection;

	cout << "Welcome to employee database creation:" << endl << endl;
	cout << "What would You like to do?" << endl;
	//---------------------------------------------------
	cout << "Create new data base - select \'1\'" << endl;
	cout << "Read data base from file - select \'2\'" << endl;
	cout << "Save data base to file - select \'3\'" << endl;
	cout << "Print out employee database - select \'4\'" << endl;
	//---------------------------------------------------
	cout << "Create new employee - select \'1\'" << endl;
	
	cout << "Select one existing by second name - select \'3\'" << endl;
	cout << "Select by salary range select \'4\'" << endl;
	cout << "Delete one existing - select \'5\'" << endl;
	cout << "Sort database - select \'6\'" << endl;
	
	cin >> selection;

	switch (selection)
	{
	case 1:
		createDataBase(INITIAL_SIZE);
		cout << "Data base created with initial size of " << INITIAL_SIZE << " elements" << endl;
		system("cls");

		break;
	case 2:
		// readFormFile func
		break;
	case 3:
		// saveToFile func
		break;
	case 4:
		//print();
	default:
		;
		break;
	}
}

void* selectMenuItem(int selection)
{
	return 0;
}

void print(Employee* dataBase)
{
	for (int i = 0; i < getLenght(dataBase); i++)
	{
		cout << getFirstName(dataBase[i]) << endl;
		cout << getLastName(dataBase[i]) << endl;
		cout << getPhoneNumber(dataBase[i]) << endl;
		cout << getSalary(dataBase[i]) << endl;
	}
}
