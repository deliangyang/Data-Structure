#include <iostream>

#include "MidList.h"
#include "../SeqListIterator.h"

using namespace std;

template<class T>
void Print(MidList<T> &l)
{
	SeqListIterator<T> iterator(l);
	for(iterator.Reset(); !iterator.EndOfList(); iterator.Next())
		std::cout<<iterator.Data()<<" ";
	std::cout<<std::endl;
}


int main(int argc, char *argv[])
{
	MidList<int> midlist;
	int i;
	for(i=0; i<5; i++)
		midlist.Insert(i);
	midlist.Delete();
	Print(midlist);
	std::system("pause");
	return 0;
}
