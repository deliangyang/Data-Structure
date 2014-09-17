


#ifndef __PRIORITY_H__
#define __PRIORITY_H__

#include "PQueue.h"

template<class T>
struct PriorityData
{
	T data;
	int priority;
};

template<class T>
int operator>=(const PriorityData<T>& PriData1, const PriorityData<T>& PriData2)
{
	return PriData1.priority>=PriData2.priority;
}

template<class T>
class Queue
{
public:
	Queue(int size);
	~Queue(void);
	void Insert(const T& item);
	T Delete(void);
private:
	int priority;
	int PL;
	PQueue<PriorityData<T> > * queue;
};

template<class T>
Queue<T>::Queue(int size)//:queue(new PQueue<PriorityData<T> >(size)),PL(0)
{
	queue=new PQueue<PriorityData<T> >(size);
	PL=0;
}

template<class T>
void Queue<T>::Insert(const T& item)
{
	PriorityData<T> priData;
	priData.data=item;
	priData.priority=PL;
	queue->PQInsert(priData);
	PL=PL+1;
}

template<class T>
T Queue<T>::Delete(void)
{
	PriorityData<T> priData=queue->PQDelete();
	//queue->PQDelete();
	return priData.data;
}

template<class T>
Queue<T>::~Queue(void)
{
	delete queue;
}

#endif

