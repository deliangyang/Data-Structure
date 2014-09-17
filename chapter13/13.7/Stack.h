
#ifndef __STACK_H__
#define __STACK_H__

#include "Priority.h"
#include "PQueue.h"

const int DefStackSize=20;

template<class T>
class Stack
{
public:
	Stack(int size=DefStackSize);
	~Stack();
	void push(const T& item);
	T pop(void);
private:
	Queue<T> * queue;	
};

template<class T>
Stack<T>::Stack(int size)
{
	queue=new Queue<T>(size);
}

template<class T>
void Stack<T>::push(const T& item)
{
	queue->Insert(item);
}

template<class T>
T Stack<T>::pop(void)
{
	return queue->Delete();
}

template<class T>
Stack<T>::~Stack(void)
{
	delete queue;
}

#endif
