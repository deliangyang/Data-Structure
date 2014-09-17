
#include <fstream>
#include <iostream>
#include "Employee.h"
#include "../Node.h"

std::ostream& operator<<(std::ostream& os, Employee employee)
{
	os<<employee.idnumber<<" "<<employee.hourlyper<<" "<<employee.name<<std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Employee employee)
{
	is>>employee.name>>employee.idnumber>>employee.hourlyper;
	return is;
}

void PrintList(Node<Employee> * list)
{
	Node<Employee> * ptrCurrent=list;
	while(ptrCurrent!=NULL)
	{
		std::cout<<ptrCurrent->data;
		ptrCurrent=ptrCurrent->NextNode();
	}
}


