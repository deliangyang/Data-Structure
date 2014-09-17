
#include <iostream>

#include "PostOrderIterator.h"
#include "BinSTree.h"

using namespace std;

int main(int argc, char *argv[])
{
	BinSTree<int> bin;

	int i;
	for(i=0; i<20; i++)
		bin.Insert(rand()%50);

	PostOrderIterator<int> iterator(bin.GetRoot());
	for(iterator.Reset(); !iterator.EndOfList(); iterator.Next())
		std::cout<<iterator.Data()<<" ";
	std::cout<<std::endl;
	std::system("pause");
	return 0;
}
