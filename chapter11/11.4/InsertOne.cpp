
#include <iostream>

#include "../BinSTree.h"
#include "../TreeNode.h"
#include "../TreeNodeFun.h"

using namespace std;

template<class T>
void * InsertOne(BinSTree<T> &t, T item)
{
	if(!t.Find(item))
		t.Insert(item);
	return NULL;
}

int main(int argc, char *argv[])
{

	BinSTree<int> bin;
	int i;
	for(i=0; i<8; i++)
		bin.Insert(rand()%8);

	PrintTree(bin.GetRoot(), 3);
	std::cout<<std::endl;

	InsertOne(bin, 7);

	PrintTree(bin.GetRoot(), 3);
	
	std::system("pause");
	return 0;
}
