
#include <iostream>

#include "Virtual.h"

using namespace std;

int main(int argc, char *argv[])
{
	Base * p = new Derived();
	delete p;
	std::system("pause");
	return 0;
}


/*
	Base * p = new Derived() 
	output:

	Base constructor called
	Derived constructor called
	Base Destructor called
	请按任意键继续. . .
	
	base class use virtual function
	output:
	Base constructor called
	Derived constructor called
	Derived Destructor called
	Base Destructor called
	请按任意键继续. . .






*/
