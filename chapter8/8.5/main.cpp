
#include <iostream>

#include "../Stack.h"

using namespace std;

int main(int argc, char *argv[])
{
	Stack<int> stack(100);
	int i;
	int temp;
	for(i=0; i<100; i++)
		stack.push(i);
	for(i=0; i<100; i++)
	{
		temp=stack.pop();
		if((i+1)%10==0)
			std::cout<<temp<<" ";
	}
	std::cout<<std::endl;
	std::system("pause");
	return 0;
}
