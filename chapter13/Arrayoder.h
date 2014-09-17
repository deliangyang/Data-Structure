

#ifndef __ARRAYORDER_H__
#define __ARRAYORDER_H__

void Preorder(int * tree, int start, int end)
{
	if(start<end)
	{
		std::cout<<tree[start]<<" ";
		Preorder(tree, 2*start+1, end);
		Preorder(tree, 2*start+2, end);
	}
}

void Inorder(int * tree, int start, int end)
{
	if(start<end)
	{
		Inorder(tree, 2*start+1, end);
		std::cout<<tree[start]<<" ";
		Inorder(tree, 2*start+2, end);
	}
}

void Postorder(int * tree, int start, int end)
{
	if(start<end)
	{
		Postorder(tree, 2*start+1, end);
		Postorder(tree, 2*start+2, end);
		std::cout<<tree[start]<<" ";
	}
}

void CountLeaf(int * tree, int &count, int start, int end)
{
	if(start<end)
	{
		CountLeaf(tree, count, 2*start+1, end);
		CountLeaf(tree, count, 2*start+2, end);
		if(2*start+1>end || 2*start+2>end)
			count++;
	}
}

void CountTwoChild(int * tree, int &count, int start, int end)
{
	int c=0;
	CountLeaf(tree, c, start, end);

	count=c-1;
}

void CountOnlyOneChild(int * tree, int &count, int start, int end)
{
	int c=0;
	CountLeaf(tree, c, start, end);

	if(c%2==1)
		count=1;
	else
		count=0;
}



#endif

