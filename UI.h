#pragma once
#include "EmployeeBase.h"

char* firstNameInput();
char* secondNameInput();
char* nameInput();
char* phoneInput();
bool isPhoneCorrect(char*);
double salaryInput();

void menu();

void* selectMenuItem(int);
void print(Employee*);
