
#include <iostream>

#include "../Node.h"

using namespace std;

template <class T>
void DeleteKey(Node<T> *& head, T key)
{
	Node<T> * ptrCurrent=head;
	Node<T> * ptrPrev;
	Node<T> * ptrDel;
	if(ptrCurrent==NULL)
		return;
	if(ptrCurrent->data==key)
	{
		if(ptrCurrent->NextNode()==NULL)
		{
			delete head;
			head=NULL;
		}
		else
		{
			ptrDel=head;
			head=head->NextNode();
			delete ptrDel;
			ptrDel=NULL;
		}
	}
	else
	{
		ptrPrev=ptrCurrent;
		ptrCurrent=ptrCurrent->NextNode();
		while(ptrCurrent!=NULL)
		{
			if(ptrCurrent->data==key)
			{
				ptrDel=ptrPrev->DeleteAfter();			// get the delete node
				ptrCurrent=ptrPrev;
				delete ptrDel;							// free delete node
				ptrDel=NULL;
			}
			else
			{
				ptrPrev=ptrCurrent;
				ptrCurrent=ptrCurrent->NextNode();
			}
			/*if(ptrCurrent->data==key)
				ptrPrev->DeleteAfter();
			ptrCurrent=ptrCurrent->NextNode();*/
		}
	}
}


template<class T>
void DeleteLess(Node<T> * &head, T key)
{
	Node<T> * ptrCurrent=head;
	while(ptrCurrent!=NULL)
	{
		if(ptrCurrent->data>key)
		{
			DeleteKey(head, ptrCurrent->data);
			break;
		}
		ptrCurrent=ptrCurrent->NextNode();
	}
}


int main(int argc, char *argv[])
{

	int i;
	int arr[]={3, 5, 1, 2, 4};
	Node<int> * head=NULL;
	for(i=1; i<=5; i++)
	{
		InsertFront(head, i);
		DeleteLess(head, i);
		std::cout<<i<<" ";
	}
	std::cout<<"--------------------------"<<std::endl;
	PrintList(head);
	std::cout<<std::endl;
	ClearList(head);

	for(i=5; i>=0; i--)
	{
		InsertFront(head, i);
		DeleteLess(head, i);
		std::cout<<i<<" ";
	}
	std::cout<<"--------------------------"<<std::endl;
	PrintList(head);
	std::cout<<std::endl;
	ClearList(head);

	for(i=0; i<5; i++)
	{
		InsertFront(head, arr[i]);
		DeleteLess(head, arr[i]);
		std::cout<<arr[i]<<" ";
	}
	std::cout<<"--------------------------"<<std::endl;
	PrintList(head);
	std::cout<<std::endl;
	ClearList(head);
	
	std::system("pause");
	return 0;
}
