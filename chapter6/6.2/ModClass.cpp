
#include <iostream>
#include "ModClass.h"

using namespace std;


int main(int argc, char *argv[])
{
	ModClass a(10);
	ModClass b(20);
	ModClass c(30);
	ModClass temp(0);
	temp=a*(b+c);
	std::cout<<temp.GetValue()<<std::endl;
	temp=a*b+a*c;
	std::cout<<temp.GetValue()<<std::endl;
	std::system("pause");
	return 0;
}


