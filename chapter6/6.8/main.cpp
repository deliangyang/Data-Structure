
#include <iostream>
#include "String.h"

using namespace std;

int main(int argc, char *argv[])
{
	String str("hello w");
	String str1("orld");
	String str2;
	
	str2=str+str1;

	std::cout<<str<<std::endl;
	std::cout<<str1<<std::endl;
	std::cout<<str2<<std::endl;

	std::cout<<str2.length()<<std::endl;
	std::system("pause");
	return 0;
}
