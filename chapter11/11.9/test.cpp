
#include <iostream>

#include "TCopyTree.h"
#include "../TreeNodeFun.h"

using namespace std;

int main(int argc, char *argv[])
{
	BinSTree<int> bin;
	BinSTree<int> temp;
	int i;
	for(i=0; i<10; i++)	
		bin.Insert(rand()%10);
	PrintTree(bin.GetRoot(), 4);
	std::cout<<"\n-----------------------after copying-----------------------------"<<std::endl;
	TCopyTree(temp, bin.GetRoot());
	PrintTree(temp.GetRoot(), 4);
	std::cout<<std::endl;
	std::system("pause");
	return 0;
}
