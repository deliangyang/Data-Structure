
#include <iostream>

#include "../Linked.h"

using namespace std;

template<class T>
void PrintLinked(Linked<T> &link)
{
	for(link.Reset(); !link.EndOfList(); link.Next())
		std::cout<<link.Data()<<" ";
	std::cout<<std::endl;
}

int main(int argc, char *argv[])
{

	Linked<int> l1;
	Linked<int> l2;
	Linked<int> temp;
	int i;
	for(i=0; i<10; i++)
		l1.InsertAfter(rand()%100);

	for(i=0; i<20; i++)
		l2.InsertAfter(rand()%100+100);

	PrintLinked(l1);
	PrintLinked(l2);

	//temp=l1+l2;
	//PrintLinked(temp);
	//li

	
	std::system("pause");
	return 0;
}
