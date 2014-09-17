
#include <iostream>
#include "Date.h"

using namespace std;

int main(int argc, char *argv[])
{
	Date date0(6, 6, 44);
	Date date1("1-1-99");
	Date date2(12, 25, 76);
	Date date3(7, 4, 76);
	
	date0.PrintDate();

	date1.PrintDate();

	date2.PrintDate();

	date3.PrintDate();

	std::cout<<"-----------------------------------"<<std::endl;
	if(date0>date1)
		date0.PrintDate();
	else
		date1.PrintDate();
	if(date2>date3)
		date2.PrintDate();
	else
		date3.PrintDate();

	std::cout<<(date1>date2)<<std::endl;
	std::system("pause");
	return 0;
}
