
#include <iostream>


#include "../Node.h"
#include "IntEntry.h"

using namespace std;

template<class T>
int Find(Node<T> * head, T& key)
{
	int result=0;
	Node<T> * ptrCurrent=head;
	while(ptrCurrent!=NULL)
	{
		if(ptrCurrent->data==key)
		{
			ptrCurrent->data.count++;
			result++;
			break;
		}
		ptrCurrent=ptrCurrent->NextNode();
	}
	return result;
}

template<class T>
void DeleteKey(Node<T>* & head, T key)
{
	Node<T> * ptrCurrent=head;
	Node<T> * ptrPrev;
	Node<T> * ptrDel;
	if(ptrCurrent==NULL)
		return;
	if(ptrCurrent->data==key)
	{
		delete head;
		head=NULL;
	}
	else
	{
		ptrPrev=ptrCurrent;
		ptrCurrent=ptrCurrent->NextNode();
		while(ptrCurrent->NextNode()!=NULL)
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
		}
	}

}

template<class T>
void DeleteMoreThanNode(Node<T> * &head, T& key)
{
	Node<T> * ptrCurrent=head;
	while(ptrCurrent!=NULL)
	{
		if(ptrCurrent->data>key)
			DeleteKey(head, ptrCurrent->data);
		ptrCurrent=ptrCurrent->NextNode();
	}
}

template<class T>
void Clear(Node<T> *& head)					// clear the  node
{
	Node<T> * ptrCurrent=head;
	Node<T> * ptrDel;
	while(ptrCurrent!=NULL)					// until the node is not null
	{
		ptrDel=ptrCurrent;
		ptrCurrent=ptrCurrent->NextNode();
		delete ptrDel;
		ptrDel=NULL;
	}
	head=NULL;
}

int main(int argc, char *argv[])
{
	Node<IntEntry> * head=NULL;
	//struct IntEntry intEntry[10]={{0, 0}};
	int i;
	IntEntry temp;
	for(i=0; i<10; i++)
	{
		temp.value=rand()%10;
		std::cout<<temp.value<<std::endl;
		if(Find(head, temp))
			;
		else
		{
			temp.count=1;
			InsertTail(head, temp);
		}
	}

	PrintIntEntry(head);
	int number;
	std::cout<<std::endl;
	std::cout<<"delte more your number: ";
	std::cin>>number;
	temp.value=number;
	DeleteMoreThanNode(head, temp);
	PrintIntEntry(head);
	Clear(head);
	//PrintIntEntry(head);
	
	std::system("pause");
	return 0;
}
