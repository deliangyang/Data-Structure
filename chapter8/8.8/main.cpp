
#include <iostream>


#include "Replace.h"

int main(int argc, char *argv[])
{
	String str="hello world";
	String test="nihafadsasf";
	std::cout<<str<<std::endl;
	std::cout<<test<<std::endl;
	std::cout<<"start Replace Replace(str, 3, test):"<<std::endl;

	Replace(str, 3, test);
	std::cout<<str<<std::endl;

	std::cout<<"(%) center void Center(String & S): ";
	Center(str);
	std::cout<<str<<std::endl;

	std::system("pause");
	return 0;
}
