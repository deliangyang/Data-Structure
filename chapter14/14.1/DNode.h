/*
 *
 *			Double Link Node ADT
 *			example: [left|data|right] <------> [left|data|right]
 *					 --------a-------- ---------b-------
 *					a->right=b b->left=a	
 *			Author: Deliang Yang
 *			Start: 2014/8/6 14:19 Wednesday
 *			Stop:
 *
 */

#ifndef __DNODE_H__
#define __DNODE_H__

template<class T>
class DNode
{
public:
	// element
	T data;
	// constructures
	DNode(void);
	DNode(const T& item);
	// the function of table changing
	void InsertRight(DNode<T> *p);
	void InsertLeft(DNode<T> * p);
	DNode<T> * DeleteNode(void);
	// return left or right address
	DNode<T> * Left(void)const;
	DNode<T> * Right(void)const;
private:
	// pointer of left and right
	DNode<T> * left;
	DNode<T> * right;
};

template<class T>
DNode<T>::DNode(void)
{
	left=right=this;
}

template<class T>
DNode<T> * DNode<T>::Left(void)const
{
	return left;
}

template<class T>
DNode<T> * DNode<T>::Right(void)const
{
	return right;
}

template<class T>
DNode<T>::DNode(const T& item)
{
	left=right=this;
	data=item;
}

template<class T>
void DNode<T>::InsertRight(DNode<T> *p)		// [left|data|right] <---[left|data|right]---> [left|data|right]
{											//			this				p    					right
	p->right=right;
	right->left=p;
	
	p->left=this;
	right=p;
}

template<class T>
void DNode<T>::InsertLeft(DNode<T> *p)		// [left|data|right] <---[left|data|right]---> [left|data|right]
{											//			right				p    					this
	// cureent node contact left
	p->left=left;
	left->right=p;
	// back
	p->right=this;
	left=p;
}

template<class T>
DNode<T> * DNode<T>::DeleteNode(void)		// [left|data|right] <---[left|data|right]---> [left|data|right]
{											//			left	  		current node    		 right
	// right pointer back to left
	right->left=left;
	// left pointer back to right
	left->right=right;
	return this;
}


#endif


