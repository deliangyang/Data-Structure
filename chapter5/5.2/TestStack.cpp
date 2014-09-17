

#include <iostream>
#include "../Stack.h"

using namespace std;

int main(int argc, char *argv[])
{
	Stack<int> stack;
	std::cout<<"Original Data: "<<std::endl;
	for(int i=0; i<10; i++)
	{
		std::cout<<i<<" ";
		stack.push(i);
	}
	std::cout<<std::endl;

	std::cout<<"Pass Stack: "<<std::endl;
	for(int i=0; i<10; i++)
		std::cout<<stack.pop()<<" ";
	std::cout<<std::endl;

	std::system("pause");
	return 0;
}
