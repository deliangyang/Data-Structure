
#include <iostream>
#include "BinSTree.h"

#include "Stack.h"
#include "TreeNode.h"
#include "TreeNodeFun.h"

using namespace std;

template<class T>
void Postorder_I(TreeNode<T> * t, void visit(T &item))
{
	Stack<TreeNode<T> * > stack;
	TreeNode<T> * child;
	int state=0, scanOver=0;
	while(!scanOver)
	{
		if(state==0)
		{
			if(t!=NULL)
			{
				stack.push(t);
				t=t->Left();
			}
			else
				state=1;
		}
		else
		{
			if(stack.isEmpty())
				scanOver=1;
			else
			{
				child=t;
				t=stack.peek();
				if(child==t->Left() && t->Right()!=NULL)
				{
					t=t->Right();
					state=0;
				}
				else
				{
					visit(t->data);
					stack.pop();
				}
			}
		}
	}
}

int main(int argc, char *argv[])
{
	BinSTree<int> bin;

	int i;
	for(i=0; i<10; i++)
		bin.Insert(rand()%10);

	PrintTree(bin.GetRoot(), 4);
	std::cout<<std::endl;
	std::cout<<"postorder: ";
	Postorder(bin.GetRoot(), visit);
	std::cout<<std::endl;
	Postorder_I(bin.GetRoot(), visit);

	std::system("pause");
	return 0;
}
