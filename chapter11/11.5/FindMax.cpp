
#include <iostream>

#include "../BinSTree.h"
#include "../TreeNode.h"
#include "../TreeNodeFun.h"

using namespace std;

template<class T>
T FindMax(BinSTree<T> &bin)
{
	TreeNode<T> * t=bin.GetRoot();
	if(t!=NULL)
	{
		while(t->Right()!=NULL)
			t=t->Right();
		return t->data;
	}
	return -1;
}

int main(int argc, char *argv[])
{

	BinSTree<int> bin;
	int i;
	for(i=0; i<500; i++)
		bin.Insert(rand()%10000+1);
	std::cout<<"find min: "<<bin.FindMin()<<std::endl;
	std::cout<<"find max: "<<FindMax(bin)<<std::endl;

	
	std::system("pause");
	return 0;
}
