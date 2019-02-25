#pragma once
#include "Constants.h"

struct Employee
{
	char* firstName = new char[MAX_FIRST_NAME_LENGHT];
	char* lastName = new char[MAX_LAST_NAME_LENGHT];
	char* phoneNumber = new char[MAX_PHONE_LENGHT];
	double salary;
};

Employee createEmployee();
Employee createEmployee(char*, char*, char*, double);		//+
void setFirstName(Employee&, char*);						//+
void setLastName(Employee&, char*);							//+
void setPhoneNumber(Employee&, char*);						//+
void setSalary(Employee&, double);							//+
char* getFirstName(Employee);								//+
char* getLastName(Employee);								//+
char* getPhoneNumber(Employee);								//+
double getSalary(Employee);									//+