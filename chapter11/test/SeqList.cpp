
#include <iostream>

#include "../SeqList.h"

#include "../SeqListIterator.h"

using namespace std;

int main(int argc, char *argv[])
{

	SeqList<int> list;
	int i;
	std::cout<<"Current array: ";
	for(i=0; i<10; i++)
	{
		list.Insert(i);
		std::cout<<i<<" ";
	}
	std::cout<<std::endl;

	SeqListIterator<int> iterator(list);
	for(iterator.Reset(); !iterator.EndOfList(); iterator.Next())
		std::cout<<iterator.Data()<<" ";
	std::cout<<std::endl;


	std::cout<<"Get Data test(3):"<<list.GetData(3)<<std::endl;

	std::cout<<"SeqList length: "<<list.Length()<<std::endl;

	std::cout<<"Find item(4): "<<list.Find(4)<<std::endl;

	std::cout<<"Delete test(6)"<<std::endl;
	//list.Delete(6);

	std::cout<<"Is Empty: "<<list.isEmpty()<<std::endl;

	std::cout<<"SeqList length: "<<list.Length()<<std::endl;


	std::cout<<"Delete test, which isn't exsit(11)"<<std::endl;

	std::cout<<"SeqList length: "<<list.Length()<<std::endl;


	for(i=0; i<list.Length(); i++)
		std::cout<<list.DeleteFront()<<" ";
	std::cout<<std::endl;

	std::cout<<"Is Empty: "<<list.isEmpty()<<std::endl;

	std::system("pause");
	return 0;
}
