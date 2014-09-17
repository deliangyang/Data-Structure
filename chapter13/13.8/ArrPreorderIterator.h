

#ifndef __ARRPREORDERITERATOR_H__
#define __ARRPREORDERITERATOR_H__

#include "Iterator.h"
#include "Stack.h"

template<class T>
class ArrPreorderIterator:public Iterator<T>
{
public:
	ArrPreorderIterator(T *arr, int n);
	virtual void Reset(void);
	virtual void Next(void);
	virtual T &Data(void);
private:
	Stack<int> stack;
	T * A;
	int arraysize;
	int current;
	int  GoLeft(int root);
};

template<class T>
int ArrPreorderIterator<T>::GoLeft(int root)
{
	while(root*2+1r<arraysize)
	{
		stack.push(root);
		root=root*2+1;
	}	
	return root;
}

template<class T>
void GetPreorder(T arr, int start, int end, Stack<int> &stack)
{
	if(start<end)
	{
		stack.push(start);
		GetPreorder(arr, start*2+1, end, stack);
		GetPreorder(arr, start*2+2, end, stack);
	}
}

template<class T>
ArrPreorderIterator<T>::ArrPreorderIterator(T *arr, int n)
{
	iterationComplete=0;
	A=arr;
	arraysize=n;
	current=0;
}

template<class T>
void ArrPreorderIterator<T>::Reset(void)
{
	iterationComplete=0;
	current=0;

	current=GoLeft(current);
	std::cout<<"Reset: "<<current<<std::endl;
	//GetPreorder(A, 0, arraysize, stack);
}

template<class T>
void ArrPreorderIterator<T>::Next(void)
{
	if(current*2+2<arraysize)
		current=GoLeft(current*2+2);
	else if(!stack.isEmpty())
		current=stack.pop();
	else
		iterationComplete=1;
	//if(stack.isEmpty())
	//	iterationComplete=1;
	//std::cout<<"current: "<<current<<std::endl;
	//current++;
	
}

template<class T>
T &ArrPreorderIterator<T>::Data(void)
{
	return A[current];
}
#endif

