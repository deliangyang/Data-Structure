
#ifndef __SALARYEMPLOYEE_H__
#define __SALARYEMPLOYEE_H__

#include "Employee.h"

class SalaryEmployee:public Employee
{
public:
	SalaryEmployee(string name, int s, float salary);
	void PrintEmployeeInfo(void);
private:	
	float salary;
};

SalaryEmployee::SalaryEmployee(void):Employee()
{}

void SalaryEmployee::PrintEmployeeInfo(void)
	Employee::PrintEmployeeInfo();
	std::cout<<salary<<std::endl;
}

#endif
