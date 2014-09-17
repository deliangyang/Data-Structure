
#include <iostream>

#include "../Linked.h"

using namespace std;

template<class T>
void DeleteTail(Linked<T>& l)
{
	l.DeleteTail();
}

void PrintLink(Linked<int> &link)
{
	for(link.Reset(); !link.EndOfList(); link.Next())
		std::cout<<link.Data()<<" ";
	std::cout<<std::endl;
}

int main(int argc, char *argv[])
{
	int i;
	for(i=1; i<1; i++)
		std::cout<<i<<std::endl;
	Linked<int> l;
	for(i=1; i<=10; i++)
		l.InsertAfter(i);
	//PrintLink(l);
	//std::cout<<l.ListSize()<<std::endl;
	for(i=1; i<=10; i++)
		l.DeleteTail();
	//std::cout<<std::endl;
	PrintLink(l);
	
	std::system("pause");
	return 0;
}
