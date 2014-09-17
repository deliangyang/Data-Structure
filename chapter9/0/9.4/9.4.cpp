
#include <iostream>

#include "../Node.h"

using namespace std;

int main(int argc, char *argv[])
{
	Node<char> * head=NULL;
	Node<char> *p, *q;
	head=new Node<char>('B');
	head=new Node<char>('A', head);
	q=new Node<char>('C');
	p=head;
	p=p->NextNode();
	p->InsertAfter(q);
	std::cout<<p->data<<" "<<p->NextNode()->data<<std::endl;
	q=p->DeleteAfter();
	delete q;
	q=head;
	head=head->NextNode();
	delete q;

	PrintList(head);

	
	std::system("pause");
	return 0;
}
