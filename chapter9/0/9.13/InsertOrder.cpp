

#include <iostream>

#include "../Node.h"

using namespace std;

template<class T>
void InsertOrder(Node<T>* &head)
{
	T item;
	std::cout<<"enter number(q quit): ";
	std::cin>>item;
	while(cin)
	{
		Node<T> * ptrCurrent=head;
		Node<T> * ptrPrev=NULL;
		Node<T> * ptrNew;
		while(ptrCurrent!=NULL)
		{
			if(item<ptrCurrent->data)
				break;
			ptrPrev=ptrCurrent;
			ptrCurrent=ptrCurrent->NextNode();
		}
		if(ptrPrev==NULL)
			InsertFront(head, item);
		else
		{
			ptrNew=GetNode(item);
			ptrPrev->InsertAfter(ptrNew);
		}
		std::cout<<"enter number(q quit): ";
		std::cin>>item;
	}
}

int main(int argc, char *argv[])
{

	Node<int> * head=NULL;
	InsertOrder(head);
	PrintList(head);
	std::cout<<std::endl;

	std::system("pause");
	return 0;
}
