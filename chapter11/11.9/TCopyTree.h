

#ifndef __TCOPYTREE_H__
#define __TCOPYTREE_H__

#include "../BinSTree.h"
#include "../TreeNode.h"

void TCopyTree(BinSTree<int> &copy, TreeNode<int> * t)
{
	if(t!=NULL)
	{
		copy.Insert(t->data);
		if(t->Left()!=NULL)
			TCopyTree(copy, t->Left());
		if(t->Right()!=NULL)
			TCopyTree(copy, t->Right());
	}
}


#endif
