


#include <iostream>

#include "../TreeNodeFun.h"
#include "../TreeNode.h"
#include "../Queue.h"

using namespace std;

template<class T>
int CountEdgs(TreeNode<T> * tree)
{
	int count=0;
	Queue<TreeNode<T> *> queue;
	TreeNode<T> * t;
	queue.Insert(tree);
	while(!queue.isEmpty())
	{
		t=queue.Delete();
		if(t->Left()!=NULL)
		{
			queue.Insert(t->Left());
			count++;
		}
		if(t->Right()!=NULL)
		{
			queue.Insert(t->Right());
			count++;
		}
	}
	return count;
}

int main(int argc, char *argv[])
{
	TreeNode<int> * root, * left, * right;
	TreeNode<int> * node1, *node2;
	node1=new TreeNode<int>(50);
	node2=new TreeNode<int>(3);
	right=new TreeNode<int>(40, node1, node2);
	left=new TreeNode<int>(100);
	root=new TreeNode<int>(30, left, right);

	int count=CountEdgs(root);
	std::cout<<"the number of edgs(5 nodes is four): "<<count<<std::endl;

	ClearTree(root);

	
	std::system("pause");
	return 0;
}

