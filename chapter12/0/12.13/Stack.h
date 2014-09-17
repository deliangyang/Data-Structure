

#include "StackBase.h"

#define LEN 30

template<class T>
class Stack:public StackBase<T>
{
public:
	Stack(int size=LEN);
	~Stack(void);
	void push(T& item);
	T& pop();
	int length(void)const;
	int StackFull(void)const;
	int StackEmpty(void)const;
private:
	int numElements;			// start numElements equal -1
	int size;
	int * arr;
};

template<class T>
Stack<T>::Stack(int size)
{
	arr=new T[size];
	numElements=-1;
}

template<class T>
void Stack<T>::push(T& item)
{
	if(numElements>=size-1)
	{
		std::cout<<"Stack: push full"<<std::endl;
		return;
	}
	arr[numElements]=item;
	numElements++;
}

template<class T>
T& Stack<T>::pop(void)
{
	if(numElements<=-1)
	{
		std::cout<<"Stack: pop empty"<<std::endl;
		exit(1);
	}
	numElements--;
	return arr[numElements];
}

template<class T>
int Stack<T>::length(void)const
{
	return numElements+1;
}

template<class T>
int Stack<T>::StackEmpty(void)const
{
	return numElements==-1;
}

template<class T>
Stack<T>::~Stack(void)
{
	delete[] arr;
}
