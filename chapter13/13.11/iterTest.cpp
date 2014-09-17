
#include <iostream>

#include "BinSTree.h"
#include "LevelorderIterator.h"
#include "TreeNodeFun.h"

using namespace std;

int main(int argc, char *argv[])
{
	BinSTree<int> bin;
	int i;
	int temp;
	std::cout<<"orign tree: ";
	for(i=0; i<10; i++)
	{
		temp=rand()%10;
		bin.Insert(temp);
		std::cout<<temp<<" ";
	}
	std::cout<<std::endl;

	std::cout<<"Test element: ";
	PrintTree(bin.GetRoot(), 2);
	std::cout<<std::endl;

	LevelorderIterator<int> iterator(bin.GetRoot());
	for(iterator.Reset(); !iterator.EndOfList(); iterator.Next())
		std::cout<<iterator.Data()<<" ";
	std::cout<<std::endl;

	std::system("pause");
	return 0;
}
