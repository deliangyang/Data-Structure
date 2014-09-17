
#ifndef __PQUEUE_H__
#define __PQUEUE_H__

#include "Heap.h"

template<class T>
class PQueue
{
public:
	PQueue(int sz);
	// table method
	void PQInsert(const T& item);
	T PQDelete(void);

	void Clear(void);
	// get PQueue attribute
	int PQEmpty(void)const;
	int PQFull(void)const;
	int PQLength(void)const;
private:
	Heap<T> * ptrHeap;
};

template<class T>
PQueue<T>::PQueue(int sz)
{
	ptrHeap=new Heap<T>(sz);
}

template<class T>
void PQueue<T>::PQInsert(const T& item)
{
	ptrHeap->Insert(item);
}

template<class T>
T PQueue<T>::PQDelete(void)
{
	return ptrHeap->Delete();
}

template<class T>
int PQueue<T>::PQEmpty(void)const
{
	return ptrHeap->isEmpty();
}

template<class T>
int PQueue<T>::PQFull(void)const
{
	return ptrHeap->isFull();
}

template<class T>
int PQueue<T>::PQLength(void)const
{
	return ptrHeap->Size();
}

#endif

