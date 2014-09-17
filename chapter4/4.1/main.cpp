
#include <iostream>
#include "SeqList.h"

using namespace std;

void InsertMax(SeqList& l, int elt)
{
	if(l.isEmpty())
	{
		l.Insert(elt);
		return;
	}
	if(elt>l.GetLastItem())
		l.Insert(elt);
}

void PrintSeqList(SeqList l)
{
	while(!l.isEmpty())
		std::cout<<l.Delete()<<" ";
	std::cout<<std::endl;
}

int main(int argc, char *argv[])
{
	int i;
	int temp;
	SeqList list;
	for(i=0; i<10; i++)
	{
		temp=rand()%100;
		std::cout<<temp<<" ";
		InsertMax(list, temp);
	}
	std::cout<<std::endl;
	PrintSeqList(list);
	std::system("pause");
	return 0;
}
