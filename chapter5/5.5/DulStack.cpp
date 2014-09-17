
#include <iostream>
#include "../DulStack.h"

using namespace std;

int main(int argc, char *argv[])
{
	DulStack<int> dulStack;
	for(int i=0; i<20; i++)
	{
		dulStack.Push(i, i);
	}
	while(!dulStack.isEmpty(0))
		std::cout<<dulStack.Pop(0)<<" ";
	std::cout<<std::endl;
	while(!dulStack.isEmpty(1))
		std::cout<<dulStack.Pop(1)<<" ";
	std::cout<<std::endl;

	std::system("pause");
	return 0;
}

