
#include <iostream>
#include "AVLTree.h"
#include "AVLTreeNode.h"

#include "TreeNodeFun.h"

using namespace std;


int main(int argc, char *argv[])
{

	AVLTree<int> avl;
	//for(int i=0; i<10; i++)
	//	avl.Insert(rand()%100);
	avl.Insert(200);
	avl.Insert(10);
	avl.Insert(20);
	avl.Insert(30);
	avl.Insert(4);
	avl.Insert(200);
	avl.Insert(10);
	avl.Insert(20);
	avl.Insert(30);
	avl.Insert(4);
	PrintTree(avl.GetRoot(), 5);
	//PrintByLevel(avl.GetRoot());
	std::cout<<std::endl;
	std::cout<<"length: "<<avl.length()<<std::endl;
	std::cout<<"find min: "<<avl.FindMin()<<std::endl;

	Inorder(avl.GetRoot(), visit);
	std::cout<<std::endl;

	std::system("pause");
	return 0;
}
