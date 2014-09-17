
#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "QueueBase.h"

template<class T>
class Queue:public QueueBase<T>
{
public:
	Queue(int sz);
	~Queue();
	virtual void Insert(const T& item);
	virtual T& Delete(void);

	T& GetData(int pos)const;

	virtual int Length(void)const;

private:
	T * q;
	int maxsize;
};

template<class T>
Queue<T>::Queue(int sz)
{
	maxsize=sz;
	q=new T[sz];
}

template<class T>
void Queue<T>::Insert(const T& item)
{
	if(size>maxsize-1)
	{
		std::cerr<<"Insert: out of range"<<std::endl;
		return;
	}
	q[size]=item;
	size++;
}

template<class T>
T& Queue<T>::Delete(void)
{
	if(size<0)
	{
		std::cerr<<"Delete: out of range"<<std::endl;
		exit(1);
	}
	T temp=q[0];
	int i;
	for(i=1; i<size; i++)
		q[i-1]=q[i];
	size--;
	return temp;
}

template<class T>
int Queue<T>::Length(void)const
{
	// bug solved,
	//std::cout<<"size::"<<size<<std::endl;
	return size;
}

template<class T>
Queue<T>::~Queue(void)
{
	delete[] q;
}

template<class T>
T& Queue<T>::GetData(int pos)const
{
	return q[pos];
}

#endif
