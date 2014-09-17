

#include <iostream>
#include "../Node.h"

using namespace std;

template<class T>
void MergeList(Node<T> * l1, Node<T> * l2, Node<T> *& head)		// head->l1->l2
{	
	head=l1;
	Node<T> * ptrCurrent=head;
	Node<T> * ptrPrev=NULL;
	Node<T> * ptrMerge;
	if(l1==NULL)							// make sure l1 is ro not null
	{
		head=l2;
		return;
	}
	while(ptrCurrent!=NULL)						// loop end last node
	{
		ptrPrev=ptrCurrent;
		ptrCurrent=ptrCurrent->NextNode();
	}
	ptrCurrent=l2;
	while(ptrCurrent!=NULL)
	{
		ptrMerge=ptrCurrent->NextNode();
		ptrPrev->InsertAfter(ptrCurrent);						// add node l2's header
		ptrPrev=ptrCurrent;
		ptrCurrent=ptrMerge;
		//l2=ptrMerge;
	}					
	/*if(l1!=NULL)												// i can't get l1's last next
	{
		head=l1;
		Node<T> * ptrCurrent=head;
		Node<T> * ptrPrev;
		Node<T> * ptrMerge;										// Merge l2's node
		while(ptrCurrent!=NULL)
		{
			ptrPrev=ptrCurrent;
			ptrCurrent=ptrCurrent->NextNode();
		}
		if(l2!=NULL)
		{
			ptrCurrent=l2;
			while(ptrCurrent!=NULL)
			{
				ptrMerge=l2->NextNode();							// get he l2's next node
				ptrPrev->InsertAfter(l2);
				ptrPrev=l2;
				ptrCurrent=ptrMerge;
				l2=ptrMerge;
			}
		}
	}*/
}


/*template<class T>
void PrintList(Node<T> * head)
{
	Node<T> * ptrCurrent=head;
	while(ptrCurrent!=NULL)
	{
		std::cout<<ptrCurrent->data<<" ";
		ptrCurrent=ptrCurrent->NextNode();
	}
}*/

template<class T>
void Clear(Node<T> * & head)
{
	Node<T> * ptrDel;
	while(head!=NULL)
	{
		ptrDel=head;
		head=head->NextNode();
		delete ptrDel;
		ptrDel=NULL;
	}
	head=NULL;
}

int main(int argc, char *argv[])
{
	Node<int> * l1=NULL;
	Node<int> * l2=NULL;
	Node<int> * head=NULL;
	int i;
	for(i=1; i<=10; i++)
		InsertTail(l1, i);
	for(i=10; i<=20; i++)
		InsertTail(l2, i);
	PrintList(l1);
	std::cout<<std::endl;
	PrintList(l2);
	std::cout<<std::endl;
	MergeList(l1, l2, head);

	PrintList(head);

	//std::cout<<"------------"<<std::endl;
	//Clear(l1);
	//Clear(l2);
	//PrintList(l1);					// 1 - 20
	//PrintList(l2);					// 10 - 20
	///Clear(l2);
	Clear(l1);
	//PrintList(l2);
	//Clear(l1);
	//PrintList(l1);
	//PrintList(l1);

	
	std::system("pause");
	return 0;
}
