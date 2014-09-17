
#include <iostream>

#include "Stack.h"

using namespace std;

int main(int argc, char *argv[])
{
	
	Stack<int> stack;
	int i;
	int temp;
	for(i=0; i<10; i++)
	{
		temp=rand()%10;
		stack.push(temp);
		std::cout<<temp<<" ";
	}
	std::cout<<std::endl;
	while(!stack.StackEmpty())
		std::cout<<stack.pop()<<" ";
	std::cout<<std::endl;

	std::system("pause");
	return 0;
}
