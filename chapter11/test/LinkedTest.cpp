
#include <iostream>

#include "../Linked.h"

using namespace std;

template<class T>
void PrintList(Linked<T> &link)					// 如果不使用引用的话，在函数内就会将数据销毁（构造函数）
{
	std::cout<<"Current element: ";
	for(link.Reset(); !link.EndOfList(); link.Next())
		std::cout<<link.Data()<<" ";
	std::cout<<std::endl;
}

int main(int argc, char *argv[])
{
	Linked<int> link;
	int i;
	std::cout<<"Input: ";
	for(i=0; i<5; i++)
	{
		link.InsertFront(i);
		std::cout<<i<<" ";
	}
	std::cout<<std::endl;
	std::cout<<"Insert Front: ";
	PrintList(link);
	std::cout<<"Insert At: ";
	for(i=5; i<10; i++)
		link.InsertAt(i);
	PrintList(link);

	std::cout<<"Insert At(Reset(1), insert two element), ";
	link.Reset(1);
	link.InsertAt(10);
	link.InsertAt(11);
	PrintList(link);

	std::cout<<"Insert After, ";
	for(i=12; i<15; i++)
		link.InsertAfter(i);
	PrintList(link);
	std::cout<<"ClearList: ";
	link.ClearList();
	std::cout<<"Insert After test, ";
	for(i=0; i<10; i++)
		link.InsertAfter(i);
	PrintList(link);

	std::cout<<"Delete Front: "<<link.DeleteFront()<<std::endl;
	PrintList(link);

	std::cout<<"Delete At, Reset(2): ";
	link.Reset(2);
	link.DeleteAt();
	PrintList(link);

	std::cout<<"Delete Tail 2 times: ";
	link.DeleteTail();
	link.DeleteTail();
	PrintList(link);

	std::cout<<"Delete (2 times): ";
	std::cout<<link.Delete()<<" ";
	std::cout<<link.Delete()<<std::endl;
	PrintList(link);

	std::cout<<"Delete Pointer Item(4): ";
	link.DeleteItem(4);
	PrintList(link);
	std::cout<<"Delete Pointer Item(5): ";
	link.DeleteItem(5);
	PrintList(link);

	std::cout<<"InsertAfter 100: ";
	link.InsertAt(100);
	PrintList(link);

	std::cout<<"List Size: "<<link.ListSize()<<std::endl;

	std::cout<<"-----------------------------------------"<<std::endl;
	std::cout<<"link2 copy link: ";
	Linked<int> link2=link;
	std::cout<<"link2 insert after 3: ";
	link2.InsertAfter(3);
	PrintList(link2);
	std::cout<<"link2 length: "<<link2.ListSize()<<std::endl;

	std::cout<<"ClearList: ";
	link.ClearList();
	PrintList(link);



	std::cout<<"----------- test success -------------"<<std::endl;

	
	std::system("pause");
	return 0;
}


