/*
 *
 *				TreeNode.h 
 *				this is the ADT of the TreeNode and some function of ADT (out of class)
 *				start: 2014/8/4 9:57 Mon
 *				stop:   
 *
 */

#ifndef __TREENODE_H__
#define __TREENODE_H__

#include <iomanip>
#include "Queue.h"

template<class T>
class BinSTree;

template<class T>
class TreeNode
{
public:
	T data;
	TreeNode(const T& item, TreeNode<T> * left=NULL, TreeNode<T> * right=NULL);
	TreeNode<T> * Left(void)const;
	TreeNode<T> * Right(void)const;
	
	friend class BinSTree<T>;
private:
	TreeNode<T> * left;
	TreeNode<T> * right;
};

template<class T>
TreeNode<T>::TreeNode(const T& item, TreeNode<T> * ptrL, 
				TreeNode<T> * ptrR):data(item),left(ptrL),right(ptrR)
{}

template<class T>
TreeNode<T> * TreeNode<T>::Left(void)const
{
	return left;
}

template<class T>
TreeNode<T> * TreeNode<T>::Right(void)const
{
	return right;
}

#endif
