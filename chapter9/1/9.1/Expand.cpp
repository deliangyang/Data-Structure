
#include <iostream>

#include "../Node.h"

using namespace std;

template<class T>
Node<T> * DeleteRear(Node<T> *& head)
{
	Node<T> * ptrCurrent=head;
	Node<T> * ptrPrev;
	if(ptrCurrent==NULL)
		return NULL;
	if(ptrCurrent->NextNode()==NULL)
		return ptrCurrent->DeleteAfter();
	ptrPrev=ptrCurrent;
	ptrCurrent=ptrCurrent->NextNode();
	while(ptrCurrent->NextNode()!=NULL)
	{
		ptrPrev=ptrCurrent;
		ptrCurrent=ptrCurrent->NextNode();
	}
	return ptrPrev->DeleteAfter();
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
void Clear(Node<T> * &head)
{
	Node<T> * ptrCurrent=head;
	Node<T> * ptrDel;
	while(ptrCurrent!=NULL)
	{
		ptrDel=ptrCurrent;
		ptrCurrent=ptrCurrent->NextNode();
		delete ptrDel;
		ptrDel=NULL;
	}
	delete ptrCurrent;
	ptrCurrent=NULL;
	head=NULL;
}

template<class T>
void Traver(Node<T> * head)
{
	int n=0;
	Node<T> * ptrCurrent=head;
	while(ptrCurrent!=NULL)
	{
		n++;
		std::cout<<ptrCurrent->data<<" ";
		ptrCurrent=ptrCurrent->NextNode();
	}
	if(n!=0)
		std::cout<<std::endl;
}

int main(int argc, char *argv[])
{
	Node<int> * head=NULL;
	int i;
	for(i=1; i<=10; i++)
		InsertTail(head, i);
	std::cout<<"init: ";
	Traver(head);
	std::cout<<"after delete last:\n";
	std::cout<<"delete: "<<DeleteRear(head)->data<<std::endl;
	
	Traver(head);

	Node<int> * temp=NULL;
	for(i=1; i<=10; i++)
		InsertTail(temp, rand()%10);
	Traver(temp);
	int n;
	std::cout<<"what's number do you want to delte: ";
	std::cin>>n;
	DeleteKey(temp, n);
	Traver(temp);

	Clear(temp);
	Clear(head);
	Traver(temp);
	

	
	std::system("pause");
	return 0;
}
