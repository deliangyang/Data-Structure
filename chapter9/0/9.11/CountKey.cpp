
#include <iostream>

#include "../Node.h"

using namespace std;

template<class T>
void CountKey(Node<T> * head, T key)
{
	Node<T> * ptrCurrent=head;
	int count=0;
	while(ptrCurrent!=NULL)
	{
		if(key==ptrCurrent->data)
			count++;
		ptrCurrent=ptrCurrent->NextNode();
	}
	std::cout<<key<<": "<<count<<" times"<<std::endl;
}

int main(int argc, char *argv[])
{
	Node<int> * head=NULL;

	int i;
	for(i=0; i<5; i++)
		InsertTail(head, rand()%5);

	for(i=0; i<5; i++)
		CountKey(head, i);

	
	std::system("pause");
	return 0;
}
