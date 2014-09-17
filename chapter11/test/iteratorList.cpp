
#include <iostream>


#include "../SeqListIterator.h"
#include "../SeqList.h"

using namespace std;

int main(int argc, char *argv[])
{

	SeqList<int> lst;
	int i;
	for(i=0; i<10; i++)
		lst.Insert(i+2);

	SeqListIterator<int> iterator(lst);

	for(iterator.Reset(); !iterator.EndOfList(); iterator.Next())
		std::cout<<iterator.Data()<<" ";
	
	std::system("pause");
	return 0;
}
