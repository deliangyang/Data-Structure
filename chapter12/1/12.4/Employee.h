

#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

#include <string>

class Employee
{
public:
	Employee(string n, int s);
	void PrintEmplyeeInfo(void);
protected:
	string name;
	int ssn;
};

Employee::Employee(string n, int s):name(n), ssn(s)
{}

void Employee::PrintEmplyeeInfo(void)
{
	std::cout<<name<<" "<<ssn;
}

#endif
