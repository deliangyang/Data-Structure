
#include <iostream>

#include "Stack.h"

using namespace std;

void isPal(char * str)
{
	Stack<char> stack;
	int adjust=0;
	int i=0;
	while(str[i]!='\0')
	{
		stack.push(str[i]);
		i++;
	}
	i=0;
	while(str[i]!='\0')
	{
		if(str[i]!=stack.pop())
		{
			adjust=1;
			break;
		}
		i++;
	}
	if(adjust==1)
		std::cout<<"is not pal"<<std::endl;
	else
		std::cout<<"is pal"<<std::endl;
}

int main(int argc, char *argv[])
{
	int i=0;
	char str[]="did";
	char str1[]="hello world";

	isPal(str);
	isPal(str1);

	std::system("pause");
	return 0;
}
