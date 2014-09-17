
#include <iostream>

#include "Demonstration.h"

using namespace std;

int main(int argc, char *argv[])
{
	Derived derived;
	std::system("pause");
	return 0;
}


/*
		print result:

				Base1 constructor called
				Base2 constructor called
				Derived class constructor called
				请按任意键继续. . .
				Derived class destructor called
				Base2 destructor called
				Base1 destructor called
				
	先继承谁，就先分配谁的内存，因为先继承的是Base1，然后是Base2，所以先打印base1
	的构造函数，然后是Base2的构造函数，

	然后是析构函数，先释放自身的内存，然后逐级先上释放。
*/
