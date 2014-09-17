

#ifndef __LEVELORDERITERATOR_H__
#define __LEVELORDERITERATOR_H__

#include "Iterator.h"
#include "TreeNode.h"
#include "Queue.h"

template<class T>
class LevelorderIterator:public Iterator<T>
{
public:
	LevelorderIterator(TreeNode<T> * t);
	virtual void Next(void);
	virtual void Reset(void);
	virtual T &Data(void);

	TreeNode<T> * GoLeft(TreeNode<T> * t);
private:
	// traver node and storage node
	Queue<TreeNode<T> * > queue;
	// get root and the current pointer use of the travering
	TreeNode<T> * root, * current;
};

template<class T>
TreeNode<T> *LevelorderIterator<T>::GoLeft(TreeNode<T> *t)
{
	if(t==NULL)
		return NULL;
	if(t->Left()!=NULL)
	{
		queue.Insert(t);
		t=t->Left();
	}
	return t;
}


template<class T>
LevelorderIterator<T>::LevelorderIterator(TreeNode<T> *t):root(t),Iterator<T>()
{
	iterationComplete=(root==NULL);
	current=root;
	queue.Insert(root);
	//current=GoLeft(root);
}

template<class T>
void LevelorderIterator<T>::Next(void)
{
	if(iterationComplete)
	{
		std::cout<<"Next: traver complete"<<std::endl;
		iterationComplete=1;
	}
	//if(!queue.isEmpty() && current==root)
	if(!queue.isEmpty())
	{
		current=queue.Delete();
		if(current->Left()!=NULL)
			queue.Insert(current->Left());
		if(current->Right()!=NULL)
			queue.Insert(current->Right());
		if(current==root)
			current=queue.Delete();
	}
	else
		iterationComplete=1;

	/*if(current->Right()!=NULL)
		current=GoLeft(current->Right());
	else if(!queue.isEmpty())
		current=queue.Delete();
	else
		iterationComplete=1;*/
	//std::cout<<"current: "<<current->data<<std::endl; 
}

template<class T>
void LevelorderIterator<T>::Reset(void)
{
	while(!queue.isEmpty())
		queue.Delete();
	iterationComplete=(root==NULL);
	current=root;
	queue.Insert(root);
	//current=GoLeft(root);
}

template<class T>
T &LevelorderIterator<T>::Data(void)
{
	if(iterationComplete || root==NULL)
	{
		std::cout<<"Data: treaver complete"<<std::endl;
		exit(1);
	}
	return current->data;
}

#endif

