

#include <iostream>
#include "AVLTree.h"
#include "InorderIterator.h"

int main(int argc, char *argv[])
{
	AVLTree<int> avl;
	avl.Insert(20);
	avl.Insert(40);
	avl.Insert(3);

	InorderIterator<int> iterator(avl.GetRoot());
	for(iterator.Reset(); !iterator.EndOfList(); iterator.Next())
		std::cout<<iterator.Data()<<" ";
	std::cout<<std::endl;

	std::system("pause");
	return 0;
}
