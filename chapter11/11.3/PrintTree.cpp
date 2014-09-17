
#include <iostream>

#include "../TreeNode.h"
#include "../TreeNodeFun.h"
#include "../BinSTree.h"

using namespace std;

int main(int argc, char *argv[])
{
	int i;
	BinSTree<int> bin;
	for(i=0; i<10; i++)
		bin.Insert(rand()%10);

	PrintTree(bin.GetRoot(), 4);
	std::cout<<std::endl;
	
	std::system("pause");
	return 0;
}
