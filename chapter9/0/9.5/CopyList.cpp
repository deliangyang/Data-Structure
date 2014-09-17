
#include <iostream>

#include "../Node.h"

using namespace std;

template<class T>
Node<T> * Copy(Node<T> * p)
{
	Node<T> * ptrTemp=p;
	if(p==NULL)
		exit(1);
	return p;
}

int main(int argc, char *argv[])
{
	Node<int> * head=NULL;
	Node<int> * newHead=NULL;
	int i;
	for(i=0; i<5; i++)
		InsertTail(head, i);

	newHead=Copy(head);
	PrintList(newHead);


	
	std::system("pause");
	return 0;
}
