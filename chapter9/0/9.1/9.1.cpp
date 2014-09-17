
#include <iostream>
#include "../Node.h"

using namespace std;

int main(int argc, char *argv[])
{
	std::system("color 2");
	Node<int> * p1, *p2;
	p1=new Node<int>(2);
	p2=new Node<int>(3);

	std::cout<<"a: ";
	std::cout<<p1->data<<" "<<p2->data<<std::endl;

	std::cout<<"b: ";
	p1->data=5;
	p1->InsertAfter(p2);
	cout<<p1->data<<" "<<p1->NextNode()->data<<std::endl;

	std::cout<<"c: ";
	p1->data=7;
	p2->data=9;
	p2=p1;
	cout<<p1->data<<" "<<p2->data<<std::endl;

	std::cout<<"d: ";
	p1->data=8;
	p1->data=15;
	p2->InsertAfter(p1);
	cout<<p1->data<<" "<<p2->NextNode()->data<<std::endl;

	std::cout<<"e: ";
	p1->data=77;
	p1->data=17;
	p1->InsertAfter(p2);
	p2->InsertAfter(p1);
	cout<<p1->data<<" "<<p2->NextNode()->data<<std::endl;

	
	std::system("pause");
	return 0;
}
