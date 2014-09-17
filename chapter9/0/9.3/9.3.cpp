
#include <iostream>

#include "../Node.h"

using namespace std;

int main(int argc, char *argv[])
{
	std::system("color 2");

	int i;
	Node<int> * head=NULL;
	for(i=1; i<=20; i++)
		InsertTail(head, i);

	PrintList(head);

	
	std::system("pause");
	return 0;
}
