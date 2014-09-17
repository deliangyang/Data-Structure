
#ifndef _STACK_H
#define _STACK_H

const int DefStackSize = 30;

template<class T>
class Stack
{
public:
	Stack(void);
	Stack(int size);
	void push(T item);
	T pop(void);
	int isEmpty(void)const;
	int isFull(void)const;
	~Stack(void);
private:
	T * data;
	int size;
	int top;
	//void Error(ErrorType type);
};

template<class T>
Stack<T>::Stack(void)
{
	size=DefStackSize;
	top=-1;
	data=new T[size];
}

template<class T>
Stack<T>::Stack(int size)
{
	this->size=size;
	top=-1;
	data=new T[size];
}

template<class T>
Stack<T>::~Stack(void)
{
	delete[] data;
}

template<class T>
void Stack<T>::push(T item)
{
	if(top==size-1)
	{
		std::cerr<<"Stack Full"<<std::endl;
		return;
	}
	top++;
	data[top]=item;
}

template<class T>
T Stack<T>::pop(void)
{
	if(top==-1)
	{
		std::cerr<<"Stack Empty"<<std::endl;
		exit(0);
	}
	T temp=data[top];
	top--;
	return temp;
}

template<class T>
int Stack<T>::isEmpty(void)const
{
	return top==-1;
}

template<class T>
int Stack<T>::isFull(void)const
{
	return top==(size-1); 
}

#endif
