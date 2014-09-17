
#include <iostream>

#include "Node.h"

using namespace std;

void MergeLists(Node<int> * l1, Node<int> * l2, Node<int> *& l3)
{
	Node<int> * ptrTemp;
	Node<int> * ptrCurrent=l1;
	Node<int> * ptrPrev;
	while(ptrCurrent!=NULL)
	{
		ptrPrev=ptrCurrent;
		ptrCurrent=ptrCurrent->NextNode();
	}
	if(ptrPrev!=NULL)
		ptrPrev->next=l2;
	l3=l1;

}

int main(int argc, char *argv[])
{

	Node<int> * head=NULL;
	Node<int> * p1=NULL;
	Node<int> * p2=NULL;

	int i;
	for(i=0; i<5; i++)
		InsertTail(p1, i);
	std::cout<<"\np1 list: ";
	PrintList(p1);

	for(i=10; i<15; i++)
		InsertTail(p2, i);
	std::cout<<"\np2 list: ";
	PrintList(p2);

	MergeLists(p1, p2, head);

	std::cout<<"\nhead after merge list: ";
	PrintList(head);
	
	std::system("pause");
	return 0;
}
