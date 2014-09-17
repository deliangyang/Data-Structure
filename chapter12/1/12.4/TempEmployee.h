

#ifndef __TEMPEMPLOYEE_H__
#define __TEMPEMPLOYEE_H__

#include "Employee.h"

class TempEmployee:public Employee
{
public:
	TempEmployee(float hourpay, float hourwork);
	void PrintEmployeeInfo(void);
private:
	float hourpay;
	float hourwork;
};

TempEmployee::TempEmployee(float hourpay, float hourwork):hourpay(hourpay), hourwork(hourwork):Employee()
{}

void TempEmployee::PrintEmployeeInfo(void)
{
	Employee::PrintEmployeeInfo();
	std::cout<<hourpay<<"*"<<hourwork<<std::endl;
}

#endif
