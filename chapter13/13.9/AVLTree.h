/*
 *
 *      AVL ADT and class create
 *		Author: Deliang Yang
 *		start:2014/8/5 15:49 Tues
 *		stop:
 *
 */

#ifndef __AVLTREE_H__
#define __AVLTREE_H__

#include "BinSTree.h"
#include "AVLTreeNode.h"

const int leftheavy = -1;
const int blanced 	= 0;
const int rightheavy= 1;


template<class T>
class AVLTree:public BinSTree<T>
{
public:
	AVLTree(void);
	AVLTree(const AVLTree<T> &tree);
	AVLTree<T>&operator=(const AVLTree<T>& tree);

	virtual void Insert(const T& item);

	//virtual void Delete(const T& item);
private:
	AVLTreeNode<T> * GetAVLTreeNode(const T& item, AVLTreeNode<T> *ptrL, AVLTreeNode<T> *ptrR);

	AVLTreeNode<T> * CopyTree(AVLTreeNode<T> * t);
	// insert and delete to reconstruction
	void SingleRotateLeft(AVLTreeNode<T> * &p);
	void SingleRotateRight(AVLTreeNode<T> * &p);
	void DoubleRotateLeft(AVLTreeNode<T> * &p);
	void DoubleRotateRight(AVLTreeNode<T> * &p);
	// update tree
	void UpdateLeftTree(AVLTreeNode<T> * &tree, int &reviseBlanceFactor);
	void UpdateRightTree(AVLTreeNode<T> * &tree, int &reviseBlanceFactor);
	// insert and delete function
	void AVLInsert(AVLTreeNode<T> * &tree, AVLTreeNode<T> * newNode,
								int &reviseBlanceFactor);
	void AVLDelete(AVLTreeNode<T> * &tree, AVLTreeNode<T> * newNode,
								int &reviseBlanceFactor);
};

template<class T>
AVLTree<T>::AVLTree(void)
{} 

template<class T>
AVLTreeNode<T> * AVLTree<T>::GetAVLTreeNode(const T& item, AVLTreeNode<T> *ptrL, AVLTreeNode<T> *ptrR)
{
	AVLTreeNode<T> * p;
	p=new AVLTreeNode<T>(item, ptrL, ptrR);
	if(p==NULL)
	{
		std::cerr<<"No Memory Allocate"<<std::endl;
		exit(1);
	}
	return p;
}

template<class T>
void AVLTree<T>::Insert(const T& item)
{
	AVLTreeNode<T> * treeRoot=(AVLTreeNode<T> *)GetRoot(), 
				   * newNode;
	int reviseBlanceFactor=0;
	newNode=GetAVLTreeNode(item, NULL, NULL);
	AVLInsert(treeRoot, newNode, reviseBlanceFactor);
	root=treeRoot;
	current=newNode;
	size++;
}

template<class T>
void AVLTree<T>::AVLInsert(AVLTreeNode<T> * &tree, AVLTreeNode<T> * newNode,
									int &reviseBlanceFactor)
{
	int reblanceCurrentNode;
	// check empty tree, and add new node
	if(tree==NULL)
	{		
		tree=newNode;
		tree->blanceFactor=blanced;
		reviseBlanceFactor=1;
	}
	// if new node value is less than current node value, then traver left child tree
	else if(newNode->data<tree->data)	
	{
		AVLInsert(tree->Left(), newNode, reblanceCurrentNode);
		if(reblanceCurrentNode)
		{
			if(tree->blanceFactor==leftheavy)			// if left child heavy add right child
				UpdateLeftTree(tree, reviseBlanceFactor);
			else if(tree->blanceFactor==blanced)		// if balance
			{
				tree->blanceFactor=leftheavy;
				reviseBlanceFactor=1;
			}
			else
			{
				tree->blanceFactor=blanced;
				reviseBlanceFactor=0;
			}
		}
		else
			reviseBlanceFactor=0;
	}
	else			// else traver right child tree
	{
		AVLInsert(tree->Right(), newNode, reblanceCurrentNode);
		if(reblanceCurrentNode)
		{
			if(tree->blanceFactor==leftheavy)
			{
				tree->blanceFactor=blanced;
				reviseBlanceFactor=0;
			}
			else if(tree->blanceFactor==blanced)
			{
				tree->blanceFactor=rightheavy;
				reviseBlanceFactor=1;
			}
			else
				UpdateRightTree(tree, reviseBlanceFactor);
		}
		else
			reviseBlanceFactor=0;
	}
}		

template<class T>
void AVLTree<T>::UpdateLeftTree(AVLTreeNode<T> * &p, int &reviseBlanceFactor)
{
	AVLTreeNode<T> * lc;
	lc=p->Left();
	if(lc->blanceFactor==leftheavy)					// if left heavy single rotate
	{
		SingleRotateRight(p);
		reviseBlanceFactor=0;
	}
	else if(lc->blanceFactor==rightheavy)			// if right heavy double rotate
	{
		DoubleRotateRight(p);
		reviseBlanceFactor=0;
	}
}					

template<class T>
void AVLTree<T>::SingleRotateRight(AVLTreeNode<T> * &p)
{
	AVLTreeNode<T> * lc;					// RR type
	lc=p->Left();
	p->blanceFactor=blanced;				// change parent blance
	lc->blanceFactor=blanced;
	p->Left()=lc->Right();					// let left node pointer to lc's right
	lc->Right()=p;
	p=lc;
}

template<class T>
void AVLTree<T>::DoubleRotateRight(AVLTreeNode<T> * &p)
{
	// changed two child node
	AVLTreeNode<T> * lc, * np;			// LR type
	lc=p->Left();						// two parent left child
	np=lc->Right();						// lc's right child

	if(np->blanceFactor==rightheavy)	
	{
		p->blanceFactor=blanced;
		lc->blanceFactor=rightheavy;
	}
	else if(np->blanceFactor==blanced)
	{
		p->blanceFactor=blanced;
		lc->blanceFactor=blanced;
	}
	else
	{
		p->blanceFactor=rightheavy;
		lc->blanceFactor=blanced;
	}
	np->blanceFactor=blanced;

	lc->Right()=np->Left();
	np->Left()=lc;
	p->Left()=np->Right();
	np->Right()=p;
	p=np;
}

/*
 
type of	RR	A  				  B		type of RL      A 					C
			 \				 / \				   / \ 				   / \
			  B 	--->	A   C				      B  --------->   A   B
			   \ 								     /
			    C 								    C


*/


template<class T>
void AVLTree<T>::UpdateRightTree(AVLTreeNode<T>* &p, int &reviseBlanceFactor)
{					
	AVLTreeNode<T> * lc;		
	lc=p->Right();				// get parent right node
	if(lc->blanceFactor==rightheavy)		// RR 
	{
		SingleRotateLeft(p);
		reviseBlanceFactor=0;
	}
	else if(lc->blanceFactor==leftheavy)	// RL
	{
		DoubleRotateLeft(p);
		reviseBlanceFactor=0;
	}
}

template<class T>
void AVLTree<T>::SingleRotateLeft(AVLTreeNode<T> * &p)
{
	AVLTreeNode<T> * lc;			// LL type
	lc=p->Right();
	p->blanceFactor=blanced;
	lc->blanceFactor=blanced;
	p->Right()=lc->Left();
	lc->Left()=p;
	p=lc;
}

template<class T>
void AVLTree<T>::DoubleRotateLeft(AVLTreeNode<T> * &p)
{
	AVLTreeNode<T> * lc, * np;			// RL type
	lc=p->Right();						// son right
	np=lc->Left();						// grade son left

	if(np->blanceFactor==leftheavy)		 
	{
		p->blanceFactor=blanced;
		lc->blanceFactor=rightheavy;
	}
	else if(np->blanceFactor=blanced)
	{
		p->blanceFactor=blanced;
		lc->blanceFactor=blanced;
	}
	else
	{
		p->blanceFactor=leftheavy;
		lc->blanceFactor=blanced;
	}
	np->blanceFactor=blanced;

	lc->Left()=np->Right();
	np->Right()=lc;
	p->Right()=np->Left();
	np->Left()=p;
	p=np;
}

#endif

