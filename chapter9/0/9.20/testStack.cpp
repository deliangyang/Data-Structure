
#include <iostream>

#include "Stack.h"

using namespace std;

int main(int argc, char *argv[])
{
	Stack<int> stack;
	int i;
	for(i=1; i<=10; i++)
		stack.push(i);
	stack.Print();
	std::cout<<"length: "<<stack.length()<<std::endl;
	for(i=1; i<=10; i++)
		std::cout<<stack.pop()<<" ";
	std::cout<<std::endl;
	std::cout<<"empty is: "<<stack.isEmpty()<<std::endl;

	
	std::system("pause");
	return 0;
}
