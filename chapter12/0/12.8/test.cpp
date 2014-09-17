
#include <iostream>

#include "OutPut.h"

using namespace std;

int main(int argc, char *argv[])
{
	
	Base B("Base Class", 1);
	Derived2 D;

	B.OutPut();
	D.OutPut();
	std::system("pause");
	return 0;
}

/*
	Output:

	1 Base Class
	2 1 0 Base
	请按任意键继续. . .


*/
