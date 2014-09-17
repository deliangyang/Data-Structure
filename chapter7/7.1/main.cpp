
#include <iostream>

using namespace std;

template<class T>
T Max(T a, T b)
{
	return a>b?a:b;
}

int main(int argc, char *argv[])
{
	string str="hello wrld";
	string str1="good";
	if(str>str1)
		std::cout<<"\"hello world\" is big than \"good\""<<std::endl;
	else if(str<str1)
		std::cout<<"\"hello world\" is less than \"good\""<<std::endl;
	else
		std::cout<<"\"hello world\" is equal \"good\""<<std::endl;
	std::system("pause");
	return 0;
}



