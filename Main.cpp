#include <iostream>
#include <windows.h>
#include "EmployeeBase.h"
#include "UI.h"
using namespace std;

int main()
{
	char* fName = "Denis";
	char* lName = "Styopkin";
	char* phone = "(093)563-99-92";
	double salary = 100500;

	Employee* base = createDataBase(4);

	Employee employee0 = createEmployee(fName, lName, phone, salary);
	Employee employee1 = createEmployee("Vasyo", "Vasiliev", "(099)999-99-99", salary);
	Employee employee2 = createEmployee("Vahtang", "Bondarenkov", "(099)999-99-99", salary);
	Employee employee3 = createEmployee("Mira", "Bondarenko", "(099)999-99-99", salary);

	push(base, employee2);
	push(base, employee0);
	push(base, employee1);
	push(base, employee3);
	
	cout << pop(base, 0).lastName << endl;
	cout << pop(base, 1).lastName << endl;
	cout << pop(base, 2).lastName << endl;
	cout << pop(base, 3).lastName << endl;
	
	sort(base); 

	cout << endl << pop(base, 0).lastName << endl;
	cout << pop(base, 1).lastName << endl;
	cout << pop(base, 2).lastName << endl;
	cout << pop(base, 3).lastName << endl;

	return 0;
}

// массив указателей на функции для работы с каждой записью.