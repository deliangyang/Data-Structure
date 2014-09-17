
#include <iostream>

#include "Stack.h"
#include "../Linked.h"

using namespace std;

template<class T>
void PrintLink(Linked<T> &link)
{
	for(link.Reset(); !link.EndOfList(); link.Next())
		std::cout<<link.Data()<<" ";
	std::cout<<std::endl;
}

template<class T>
void ActionS(Linked<T>& l)
{
	Stack<T> stack;
	for(l.Reset(); !l.EndOfList(); l.Next())
		stack.push(l.Data());
	l.Reset();
	while(!stack.isEmpty())
	{
		l.Data()=stack.pop();
		l.Next();
	}
}

int main(int argc, char *argv[])
{
	Linked<int> link;
	int i;

	for(i=0; i<10; i++)
		link.InsertAfter(i);
	std::cout<<"orign: ";
	PrintLink(link);
	ActionS(link);
	std::cout<<"changed: ";
	PrintLink(link);

	
	std::system("pause");
	return 0;
}
