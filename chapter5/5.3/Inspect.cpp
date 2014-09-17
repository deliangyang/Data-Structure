
#include <iostream>
#include "../Stack.h"
#include <string>

using namespace std;


int main(int argc, char *argv[])
{
	Stack<char> order;
	Stack<char> inverted;

	int i, j=0;
	int len;
	char str[30];
	for(i=0; i<5; i++)
	{
		std::cout<<"Model(string1#1gnirts): ";
		std::cin>>str;
		int len=strlen(str)-1;
		int i=0;
		while(str[i]!='#' && str[i]!='\0')
		{
			order.push(str[i]);
			inverted.push(str[len-i]);
			i++;
		}
		int adjust;
		while(!order.isEmpty())
		{
			if(order.pop()!=inverted.pop())
			{
				adjust=1;
				break;
			}
			adjust=0;
		}
		if(adjust==0)
			std::cout<<"match mode"<<std::endl;
		if(adjust==1)		
			std::cout<<"can't match mode"<<std::endl;
		while(!order.isEmpty())
			order.pop();
		while(!inverted.isEmpty())
			inverted.pop();
	}

	std::system("pause");
	return 0;
}
