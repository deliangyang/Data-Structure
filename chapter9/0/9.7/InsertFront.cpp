
#include <iostream>

#include "../Node.h"

using namespace std;

int main(int argc, char *argv[])
{

	Node<int> * head=NULL;
	int i;
	for(i=1; i<=5; i++)
		InsertTail(head, i);
	PrintList(head);

	std::cout<<std::endl;
	std::cout<<"insert front: ";
	InsertFront(head, 100);
	PrintList(head);

	std::cout<<std::endl;
	std::cout<<"delete front: ";
	DeleteFront(head);
	PrintList(head);

	std::cout<<std::endl;

	
	std::system("pause");
	return 0;
}
