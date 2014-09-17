
#include <iostream>

#include "InorderIterator.h"
#include "BinSTree.h"

using namespace std;

int main(int argc, char *argv[])
{
	BinSTree<int> bin;
	int i;

	for(i=0; i<25; i++)
		bin.Insert(rand()%100);
	InorderIterator<int> iterator(bin.GetRoot());
	while(!iterator.EndOfList())
	{
		std::cout<<iterator.Data()<<" ";
		iterator++;
	}

	std::cout<<std::endl;

	std::system("pause");
	return 0;
}
