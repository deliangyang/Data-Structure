
#include <iostream>

#include "../Linked.h"

using namespace std;

void PrintLink(Linked<int> &link)
{
	for(link.Reset(); !link.EndOfList(); link.Next())
		std::cout<<link.Data()<<" ";
	std::cout<<std::endl;
}

int main(int argc, char *argv[])
{

	Linked<int> link;
	int val;
	int i;

	std::cout<<"A(Insert Front): ";
	for(i=1; i<=5; i++)
		link.InsertFront(2*i);
	PrintLink(link);

	std::cout<<"B(Insert After): ";
	for(i=1; i<=5; i++)
		link.InsertAfter(2*i);
	PrintLink(link);

	std::cout<<"C(Insert At): ";
	for(i=1; i<=5; i++)
		link.InsertAt(3*i);
	PrintLink(link);

	std::cout<<"D(many many): ";
	for(i=1; i<=5; i++)
	{
		link.InsertAt(i);
		link.Next();
		link.InsertAt(4*i);
		val=link.DeleteFront();
	}
	PrintLink(link);

	std::cout<<"create link 50  40 ... 10: ";
	Linked<int> e;
	for(i=1; i<=5; i++)
		e.InsertFront(i*10);
	PrintLink(e);

	std::cout<<"insert at link 50  40 ... 10: ";
	for(i=1; i<=5; i++)
		e.InsertAt(i*10);
	PrintLink(e);

	std::cout<<"insert after link 50  40 ... 10: ";
	for(i=1; i<=5; i++)
		e.InsertAfter(i*10);
	PrintLink(e);

	std::system("pause");
	return 0;
}
