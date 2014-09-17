
#include <iostream>

#include "SalaryEmployee.h"
#include "TempEmployee.h"

using namespace std;


int main(int argc, char *argv[])
{
	SalaryEmployee salary("lis", 1);
	salary.SalaryPrintInfo();
	std::system("pause");
	return 0;
}
