#include "Employee.h"

Employee createEmployee(char* firstName, char* lastName, char* phoneNumber, double salary)
{
	Employee employee;
	employee.firstName = firstName;
	employee.lastName = lastName;
	employee.phoneNumber = phoneNumber;
	employee.salary = salary;
	return employee;
}

void setFirstName(Employee& employee, char* firstName)
{
	employee.firstName = firstName;
}

void setLastName(Employee& employee, char* lastName)
{
	employee.lastName = lastName;
}

void setPhoneNumber(Employee& emplyee, char* phoneNumber)
{
	emplyee.phoneNumber = phoneNumber;
}

void setSalary(Employee& employee, double salary)
{
	employee.salary = salary;
}

char* getFirstName(Employee employee)
{
	return employee.firstName;
}

char* getLastName(Employee employee)
{
	return employee.lastName;
}

char* getPhoneNumber(Employee employee)
{
	return employee.phoneNumber;
}

double getSalary(Employee employee)
{
	return employee.salary;
}