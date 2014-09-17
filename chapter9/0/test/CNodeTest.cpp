
#include <iostream>

#include "../CNode.h"

using namespace std;

void CreateList(CNode<int> * header, int n)
{
	CNode<int> * current=header, * ptrNew;
	for(int i=0; i<n; i++)
	{
		ptrNew=new CNode<int>(i);
		current->InsertAfter(ptrNew);
		current=ptrNew;
	}
}

void PrintList(CNode<int> * header)
{
	// if header's next node is null, mean empty cnode
	std::cout<<header<<std::endl;
	CNode<int> * current=header->NextNode();
	while(current!=header)
	{
		std::cout<<current<<std::endl;
		std::cout<<current->data<<" ";
		current=current->NextNode();
	}
	std::cout<<current<<std::endl;
	std::cout<<std::endl;
}

template<class T>
void Clear(CNode<T> * header)
{
	CNode<T> * rear=header;
	header=header->NextNode();			// header's next node 
	CNode<T> * ptrTemp=header;
	while(header!=rear)
	{
		ptrTemp=header->NextNode();
		delete header;
		header=ptrTemp;
	}										
	header->NextNode()=header;
}

int main(int argc, char *argv[])
{
	CNode<int> header;
	CreateList(&header, 10);
	std::cout<<"do"<<std::endl;
	PrintList(&header);
	Clear(&header);
	PrintList(&header);						// bugs free list will loop print
	std::cout<<"end"<<std::endl;
	std::system("pause");
	return 0;
}
