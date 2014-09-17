
#include <iostream>

#include "../BinSTree.h"
#include "../TreeNodeFun.h"
#include "../TreeNode.h"

using namespace std;

template<class T>
void RNL(TreeNode<T> * tree, void visit(T& item))
{
	TreeNode<T> * t=tree;
	if(t!=NULL)
	{
		RNL(t->Right(), visit);
		visit(t->data);
		RNL(t->Left(), visit);
	}
}

int main(int argc, char *argv[])
{

	BinSTree<int> bin;
	int i;
	std::cout<<"orign: ";
	for(i=0; i<10; i++)
	{ 
		int temp=rand()%100;
		bin.Insert(temp);
		std::cout<<temp<<" ";
	}
	std::cout<<std::endl;
	std::cout<<"Level: ";
	PrintByLevel(bin.GetRoot());
	std::cout<<std::endl;
	std::cout<<"RNL: ";
	RNL(bin.GetRoot(), visit);
	std::cout<<std::endl;

	PrintTree(bin.GetRoot(), 4);

	std::cout<<std::endl;
	
	
	std::system("pause");
	return 0;
}
