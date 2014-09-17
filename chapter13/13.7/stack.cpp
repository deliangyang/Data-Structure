
#include <iostream>

#include "Stack.h"

int main(int argc, char *argv[])
{
	std::cout<<"use priority queue and max heap to make stack, input(0-19), output(19-0):"<<std::endl;
	Stack<int> stack(20);
	int i;
	for(i=0; i<20; i++)
		stack.push(i);
	for(i=0; i<20; i++)
		std::cout<<stack.pop()<<" ";
	std::cout<<std::endl;

	std::system("pause");
	return 0;
}
