#include <iostream>
#include <windows.h>
#include "UI.h"
using namespace std;

int main()
{
	char* fName = "Denis";
	char* lName = "Styopkin";
	char* phone = "(093)563-99-92";
	double salary = 100500;

	Employee* base = createDataBase(10);
	Employee* base2 = createDataBase(3);

	Employee employee0 = createEmployee(fName, lName, phone, salary);
	Employee employee1 = createEmployee("Vasyo", "Vasiliev", "(099)999-99-99", salary);
	Employee employee2 = createEmployee("Vahtang", "Bondarenkov", "(099)999-99-99", salary);
	Employee employee3 = createEmployee("Mira", "Bondarenko", "(099)999-99-99", salary);
	Employee employee4 = createEmployee("Vlada", "Mozoleva", "(099)999-99-99", salary);
	Employee employee5 = createEmployee("Irina", "Vikherko", "(099)999-99-99", salary);

	
	push(base, employee2);
	push(base, employee0);
	push(base, employee1);
	push(base, employee3);
	

	cout << pop(base, 0).lastName << endl;
	cout << pop(base, 1).lastName << endl;
	cout << pop(base, 2).lastName << endl;
	cout << pop(base, 3).lastName << endl;

	remove(base, 2);

	cout << "Next empty " << getNextEmptyElement(base) << endl;
	push(base, employee4);

	for (int i = 0; i < getLenght(base); i++)
		cout << pop(base, i).lastName << endl;

	sort(base); 
	
	for (int i = 0; i < getLenght(base); i++)
		cout << pop(base, i).lastName << endl;

	push(base, employee5);
	push(base, employee1);

	for (int i = 0; i < getLenght(base); i++)
		cout << pop(base, i).lastName << endl;
	
	sort(base);

	for (int i = 0; i < getLenght(base); i++)
		cout << pop(base, i).lastName << endl;

	increaseDataBaseSize(base2);

	copyDataBase(base, base2);

	for (int i = 0; i < getLenght(base2); i++)
		cout << pop(base2, i).lastName << endl;

	return 0;
}