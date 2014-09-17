

#ifndef __AVLTREENODE_H__
#define __AVLTREENODE_H__

#include "TreeNode.h"

template<class T>
class AVLTree;

template<class T>
class AVLTreeNode:public TreeNode<T>
{
public:
	AVLTreeNode(void);
	AVLTreeNode(const T& item, AVLTreeNode<T> * ptrL=NULL, 
								AVLTreeNode<T> * ptrR=NULL, int blance=0);
	AVLTreeNode<T> * Left(void)const;
	AVLTreeNode<T> * Right(void)const;
	int GetBalanceFactor(void);

	friend class AVLTree<T>;
private:
	int blanceFactor;
	AVLTreeNode<T> * &Left(void);
	AVLTreeNode<T> * &Right(void);
};

template<class T>
AVLTreeNode<T>::AVLTreeNode(const T& item, AVLTreeNode<T> * ptrL, 
								AVLTreeNode<T> * ptrR, int blance):TreeNode<T>(item, ptrL, ptrR), 
										blanceFactor(blance)
{}

template<class T>
AVLTreeNode<T> *& AVLTreeNode<T>::Left(void)
{
	return (AVLTreeNode<T> *)left;
}

template<class T>
AVLTreeNode<T> * &AVLTreeNode<T>::Right(void)
{
	return (AVLTreeNode<T> *)right;
}

// return left after casting it to an AVLTreeNode pointer
template <class T>
AVLTreeNode<T>* AVLTreeNode<T>::Left(void) const
{
   return (AVLTreeNode<T> *)left;
}

// return right after casting it to an AVLTreeNode pointer
template <class T>
AVLTreeNode<T>* AVLTreeNode<T>::Right(void) const
{
   return (AVLTreeNode<T> *)right;
}

template<class T>
int AVLTreeNode<T>::GetBalanceFactor(void)
{
   return balanceFactor;
}



#endif

