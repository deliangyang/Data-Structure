
#include <iostream>

#include "../Node.h"

using namespace std;

template<class T>
void DeleteKey(Node<T> * &head, T key)
{
	Node<T> * ptrCurrent=head;
	Node<T> * ptrPrev=NULL;
	if(ptrCurrent->data==key)
	{
		head=head->NextNode();
		return;
	}
	ptrPrev=ptrCurrent;
	ptrCurrent=ptrCurrent->NextNode();
	while(ptrCurrent!=NULL)
	{
		
		if(ptrCurrent->data==key)
		{
			ptrPrev->DeleteAfter();
			ptrCurrent=ptrPrev;
		}
		else
		{
			ptrPrev=ptrCurrent;
			ptrCurrent=ptrCurrent->NextNode();	
		}
	}
}

int main(int argc, char *argv[])
{

	Node<int> * head=NULL;
	int i;
	int num;
	for(i=0; i<10; i++)
		InsertTail(head, rand()%10);
	PrintList(head);
	std::cout<<std::endl;
	std::cout<<"enter a num you want to delete: ";
	std::cin>>num;
	std::cout<<"you want to delete "<<num<<": "<<std::endl;
	DeleteKey(head, num);
	PrintList(head);
	std::cout<<std::endl;

	
	std::system("pause");
	return 0;
}
