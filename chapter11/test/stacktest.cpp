
#include "../Stack.h"

#include <iostream>

int main(int argc, char *argv[])
{
	Stack<int> stack;
	int i;
	for(i=0; i<30; i++)
		stack.push(i);
	std::cout<<"is empty: "<<stack.isEmpty()<<std::endl;
	std::cout<<"is full: "<<stack.isFull()<<std::endl;
	for(i=0; i<30; i++)
		std::cout<<stack.pop()<<" ";
	std::cout<<std::endl;

	std::cout<<"is empty: "<<stack.isEmpty()<<std::endl;
	std::cout<<"is full: "<<stack.isFull()<<std::endl;

	std::system("pause");
	return 0;
}

