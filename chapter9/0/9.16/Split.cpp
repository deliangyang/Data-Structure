
#include <iostream>

#include "../Linked.h"

using namespace std;

template<class T>
void Split(Linked<T>& l, Linked<T>& l1, Linked<T>& l2)
{
	for(l.Reset(); !l.EndOfList(); l.Next())
	{
		if(l.Data()%2==1)
			l1.InsertAfter(l.Data());
		else
			l2.InsertAfter(l.Data());
	}
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
	Linked<int> l;
	Linked<int> l1;
	Linked<int> l2;

	// create link l
	for(i=0; i<10; i++)
		l.InsertAfter(i);
	std::cout<<"Split Odd and Even Numver: "<<std::endl;
	std::cout<<"l: ";
	PrintLink(l);
	Split(l, l1, l2);
	std::cout<<"l1: ";
	PrintLink(l1);
	std::cout<<"l2: ";
	PrintLink(l2);
	
	std::system("pause");
	return 0;
}
