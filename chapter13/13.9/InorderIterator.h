
#ifndef __INORDERITERATOR_H__
#define __INORDERITERATOR_H__

#include "TreeNode.h"
#include "Iterator.h"
#include "Stack.h"

template<class T>
class InorderIterator:public Iterator<T>
{
public:
	// constructor
	InorderIterator(TreeNode<T> * tree);
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
	TreeNode<T> * GoFarLeft(TreeNode<T> * t);
};

template<class T>
InorderIterator<T>::InorderIterator(TreeNode<T> * tree):root(tree), Iterator<T>()
{
	iterationComplete=(root == NULL);
	current=GoFarLeft(root);
}

// return last left node and storage all -1 left node
template<class T>
TreeNode<T> * InorderIterator<T>::GoFarLeft(TreeNode<T> * t)
{
	if(t==NULL)
		return NULL;
	while(t->Left()!=NULL)
	{
		stack.push(t);
		t=t->Left();
	}
	return t;
}

template<class T>
void InorderIterator<T>::Next(void)
{
	if(iterationComplete)
	{
		std::cerr<<"Next: iterator has passed the end of list";
		exit(1);
	}

	if(current->Right()!=NULL)
		current=GoFarLeft(current->Right());
	else if(!stack.isEmpty())
		current=stack.pop();
	else
		iterationComplete=1;
}

template<class T>
void InorderIterator<T>::operator++(int num)
{
	Next();
	/*if(iterationComplete)
	{
		std::cerr<<"Next: iterator has passed the end of list";
		exit(1);
	}

	if(current->Right()!=NULL)
		current=GoFarLeft(current->Right());
	else if(!stack.isEmpty())
		current=stack.pop();
	else
		iterationComplete=1;*/
}

template<class T>
void InorderIterator<T>::Reset(void)
{
	// clear stack
	while(!stack.isEmpty())
		stack.pop();
	iterationComplete=(root==NULL);
	current=GoFarLeft(root);
}

template<class T>
T& InorderIterator<T>::Data(void)
{
	if(root==NULL || iterationComplete)
	{
		std::cerr<<"Data: invalid refrence"<<std::endl;
		exit(1);
	}

	return current->data;
}

template<class T>
void InorderIterator<T>::SetTree(TreeNode<T> * t)
{
	// clear stack
	while(!stack.isEmpty())
		stack.pop();

	root=t;
	current=GoFarLeft(root);
	iterationComplete=(root==NULL);
}

#endif
