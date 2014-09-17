
#include <iostream>

#include "../BinSTree.h"
#include "../TreeNodeFun.h"
#include "../TreeNode.h"
#include "../Array.h"

using namespace std;


template<class T>
void RNL(TreeNode<T> * root, Array<T> & a, int &d)
{
	TreeNode<T> * t=root;
	if(t!=NULL)
	{
		RNL(t->Left(), a, d);
		a[d++]=t->data;
		RNL(t->Right(), a, d);
	}
}

template<class T>
void TreeSort(Array<T> & a)
{
	int d=0;
	BinSTree<T> bin;
	int i;
	for(i=0; i<a.length(); i++)
		bin.Insert(a[i]);
	RNL(bin.GetRoot(), a, d);
}

template<class T>
void TreeSort(Array<T> & a)
{

}

template<class T>
void PrintArray(Array<T> &a)
{
	int i;
	for(i=0; i<a.length(); i++)
		std::cout<<a[i]<<" ";
	std::cout<<std::endl;
}

int main(int argc, char *argv[])
{
	Array<int> a(10);
	int i;
	for(i=0; i<10; i++)
		a[i]=rand()%10;
	PrintArray(a);
	TreeSort(a);
	PrintArray(a);


	
	std::system("pause");
	return 0;
}
