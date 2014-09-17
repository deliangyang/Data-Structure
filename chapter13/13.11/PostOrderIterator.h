
#ifndef __INORDERITERATOR_H__
#define __INORDERITERATOR_H__

#include "TreeNode.h"
#include "Iterator.h"
#include "Stack.h"

template<class T>
class PostOrderIterator:public Iterator<T>
{
public:
	// constructor
	PostOrderIterator(TreeNode<T> * tree);
	// base method
	virtual void Next(void);
	virtual void Reset(void);
	virtual T &Data(void);
	void operator++(int num);
	// set new tree
	void SetTree(TreeNode<T> * tree);
private:
	// storage TreeNode address
	Stack<TreeNode<T> * > stack;
	//	tree root and current node
	TreeNode<T> * root, * current;
	// Traver left and next
	TreeNode<T> * GoFarRight(TreeNode<T> * t);
};

template<class T>
PostOrderIterator<T>::PostOrderIterator(TreeNode<T> * tree):root(tree), Iterator<T>()
{
	iterationComplete=(root == NULL);
	current=GoFarRight(root);
}

// return last left node and storage all -1 left node
template<class T>
TreeNode<T> * PostOrderIterator<T>::GoFarRight(TreeNode<T> * t)
{
	if(t==NULL)
		return NULL;
	while(t->Right()!=NULL)
	{
		stack.push(t);
		t=t->Right();
	}
	return t;
}

template<class T>
void PostOrderIterator<T>::Next(void)
{
	if(iterationComplete)
	{
		std::cerr<<"Next: iterator has passed the end of list";
		exit(1);
	}

	if(current->Left()!=NULL)
		current=GoFarRight(current->Left());
	else if(!stack.isEmpty())
		current=stack.pop();
	else
		iterationComplete=1;
}

template<class T>
void PostOrderIterator<T>::operator++(int num)
{
	Next();
	/*if(iterationComplete)
	{
		std::cerr<<"Next: iterator has passed the end of list";
		exit(1);
	}

	if(current->Right()!=NULL)
		current=GoFarRight(current->Right());
	else if(!stack.isEmpty())
		current=stack.pop();
	else
		iterationComplete=1;*/
}

template<class T>
void PostOrderIterator<T>::Reset(void)
{
	// clear stack
	while(!stack.isEmpty())
		stack.pop();
	iterationComplete=(root==NULL);
	current=GoFarRight(root);
}

template<class T>
T& PostOrderIterator<T>::Data(void)
{
	if(root==NULL || iterationComplete)
	{
		std::cerr<<"Data: invalid refrence"<<std::endl;
		exit(1);
	}

	return current->data;
}

template<class T>
void PostOrderIterator<T>::SetTree(TreeNode<T> * t)
{
	// clear stack
	while(!stack.isEmpty())
		stack.pop();

	root=t;
	current=GoFarRight(root);
	iterationComplete=(root==NULL);
}

#endif
