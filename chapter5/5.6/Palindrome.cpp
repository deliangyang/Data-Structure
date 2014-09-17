
#include <iostream>
#include "../Stack.h"
#include "../Queue.h"

using namespace std;

#define STRLEN 30

int main(int argc, char *argv[])
{
	Stack<char> stack;
	Queue<char> queue;
	char str[STRLEN];
	int i;

	for(i=0; i<2; i++)
	{
		std::cout<<"Please enter string to adjust is or not palindrome: ";
		std::cin.getline(str, STRLEN, '\n');
		int k=0;
		while(str[k]!='\0')
		{
			if(isalpha(str[k]))
			{
				stack.push(str[k]);
				queue.Insert(str[k]);
			}
			k++;
		}
		int adjust=0;
		while(!stack.isEmpty())
		{
			if(stack.pop()!=queue.Delete())
			{
				adjust=1;
				break;
			}
			else
				adjust=2;
		}
		while(!stack.isEmpty())
			stack.pop();
		while(!queue.isEmpty())
			queue.Delete();
		if(adjust==2)
			std::cout<<"is palindrome"<<std::endl;			
		else
			std::cout<<"is not palindrome"<<std::endl;
	}
	

	std::system("pause");
	return 0;
}
