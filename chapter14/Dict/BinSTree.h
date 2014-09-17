
/*
 *
 *			Bin Search Tree ADT
 *			this is the ADT of BinSTree
 *			start: 2014/8/4 13:10 Mon
 *			stop:
 *
 */


#ifndef __BINSTREE_H__
#define __BINSTREE_H__

#include <iostream>
#include <stdlib.h>

#ifndef NULL
const int NULL=0;
#endif

#include "TreeNode.h"

template<class T>
class BinSTree
{
protected:
	TreeNode<T> * root;
	TreeNode<T> * current;
	int size;
	TreeNode<T> * GetTreeNode(const T& item, TreeNode<T> * ptrL, TreeNode<T> * ptrR);
	void FreeTreeNode(TreeNode<T> * p);
	TreeNode<T> * CopyTree(TreeNode<T> * t);
	void Delete(TreeNode<T> * t);
	TreeNode<T> * FindNode(const T& item, TreeNode<T> *& parent)const;
public:
	// constructors
	BinSTree(void);
	BinSTree(const BinSTree<T> &tree);
	// destructor
	~BinSTree(void);

	BinSTree<T>&operator=(const BinSTree<T> & rhs);
	int Find(T& item);
	void Insert(const T& item);
	void Delete(const T& item);
	void ClearTree(void);
	int isEmpty(void)const;
	int length(void)const;
	void Update(const T& item);
	TreeNode<T> * GetRoot(void)const;

	T FindMin(void)const;
};

template<class T>
BinSTree<T>::BinSTree(void):size(0)
{
	root=NULL;
	current=NULL;
}

template<class T>
BinSTree<T>::~BinSTree(void)
{
	if(root!=NULL)
	{
		FreeTreeNode(root->Left());
		FreeTreeNode(root->Right());
		delete root;
		root=NULL;
	}
}

template<class T>
TreeNode<T> * BinSTree<T>::GetTreeNode(const T& item, TreeNode<T> * ptrL, TreeNode<T> * ptrR)
{
	TreeNode<T> * ptrNew;
	ptrNew=new TreeNode<T>(item, ptrL, ptrR);
	if(ptrNew==NULL)
	{
		std::cerr<<"No Memory Allocate"<<std::endl;
		exit(1);
	}
	return ptrNew;
}

// warning, didn't test this funciton
template<class T>
TreeNode<T> * BinSTree<T>::CopyTree(TreeNode<T> * t)
{
	return &t;
}

// the assignment operator
template<class T>
BinSTree<T>& BinSTree<T>::operator=(const BinSTree<T> & rhs)
{
	if(this==&rhs)
		return *this;
	ClearTree();
	root=CopyTree(rhs.root);
	current=root;
	size=rhs.size;
	return *this;
}

// if find item, return node address and this parent node, else return NULL
template<class T>
TreeNode<T> * BinSTree<T>::FindNode(const T& item, TreeNode<T> *& parent)const
{
	TreeNode<T> * t=root;
	parent=NULL;
	while(t!=NULL)
	{
		if(item==t->data)				// if find item, quit
			break;
		else
		{
			parent=t;					// change parent
			if(item<t->data)
				t=t->left;
			else
				t=t->right;
		}
	}
	return t;
}

// find item, if item exist, return 1, else return 0;
template<class T>
int BinSTree<T>::Find(T& item)
{
	TreeNode<T> * parent;
	current=FindNode(item, parent);					// return item parent node
	if(current!=NULL)
	{
		item=current->data;							// assignment item to item, why???
		return 1;
	}
	else
		return 0;
}

// insert item to the tree, if new tree node more than parent, add right leaf, else add to left leaf
template<class T>
void BinSTree<T>::Insert(const T& item)
{
	TreeNode<T> * t=root, * parent=NULL, * ptrNew;
	while(t!=NULL)
	{
		parent=t;
		if(item<t->data)			// if item less than root, add to left leaf
			t=t->left;
		else
			t=t->right;
	}
	ptrNew=GetTreeNode(item, NULL, NULL);		// allocate memory
	if(parent==NULL)
		root=ptrNew;
	else if(item<parent->data)
		parent->left=ptrNew;
	else
		parent->right=ptrNew;
	current = ptrNew;
	size++;
}

template<class T>
void BinSTree<T>::Delete(const T& item)
{
	// ptrDel --------- pointer delete node address
	// ptrParent ------ pointer parent node address
	// ptrReplace	--- pointer replace node address
	TreeNode<T> * ptrDel, * ptrParent, * ptrReplace;
	if((ptrDel=FindNode(item, ptrParent))==NULL)		
		return;
	// one leaf have node
	if(ptrDel->left==NULL)
		ptrReplace=ptrDel->right;
	else if(ptrDel->right==NULL)
		ptrReplace=ptrDel->left;
	// two leaf have node
	else
	{	
		TreeNode<T> * ptrPof=ptrDel;			// pointer to the same level node
		ptrReplace=ptrDel->left;				// one case: delete left node
		while(ptrReplace->right!=NULL)
		{
			ptrPof=ptrReplace;
			ptrReplace=ptrReplace->right;
		}
		if(ptrPof==ptrDel)					// if ptrpof address is equal to delete node
			ptrReplace->right=ptrDel->right;
		else
		{
			ptrPof->right=ptrReplace->right;
			ptrReplace->left=ptrDel->left;
			ptrReplace->right=ptrDel->right;
		}
	}
	if(ptrParent==NULL)
		root=ptrReplace;
	else if(ptrDel->data<ptrParent->data)
		ptrParent->left=ptrReplace;
	else
		ptrParent->right=ptrReplace;
	FreeTreeNode(ptrDel);
	size--;
}

template<class T>
void BinSTree<T>::FreeTreeNode(TreeNode<T> * p)
{
	delete p;
	p=NULL;
}

template<class T>
void BinSTree<T>::Update(const T& item)					// update current address data
{
	if(current!=NULL && current->data==item)
		current->data=item;
	else
		Insert(item);
}

template<class T>
int BinSTree<T>::length(void)const
{
	return size;
}

// return the top root
template<class T>
TreeNode<T> * BinSTree<T>::GetRoot(void)const
{
	return root;
}

// find minimum value
template<class T>
T BinSTree<T>::FindMin(void)const
{
	TreeNode<T> * t=root;
	if(t==NULL)
		return -1;
	while(t->left!=NULL)
		t=t->left;
	return t->data;
}



#endif

