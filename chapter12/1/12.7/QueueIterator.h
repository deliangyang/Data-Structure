

#ifndef __QUEUEITERATOR_H__
#define __QUEUEITERATOR_H__

#include "Iterator.h"
#include "Queue.h"

template<class T>
class QueueIterator:public Iterator<T>
{
public:
	QueueIterator(Queue<T> &queue, int start=0, int finish=-1);
	virtual void Reset(void);
	virtual void Next(void);
	virtual T& Data(void);
private:
	int startIndex, currentIndex, finishIndex;
	Queue<T> * Q;
};

template<class T>
QueueIterator<T>::QueueIterator(Queue<T> &queue, int start, int finish):Q(&queue)
{
	int len=queue.Length()-1;
	currentIndex=startIndex=start;
	finishIndex=finish==-1?len:finish;
	if(!(startIndex>=0 && startIndex<=len) &&
		finishIndex>=0 && finishIndex<=len &&
		startIndex<finishIndex)
	{
		std::cout<<"Data: out of range"<<std::endl;
		exit(1);
	} 
}

template<class T>
void QueueIterator<T>::Reset(void)
{
	currentIndex=startIndex;			// make current Index to Start
	iterationComplete=0;
}

template<class T>
T& QueueIterator<T>::Data(void)
{
	if(iterationComplete)
	{
		std::cout<<"Data: out of range"<<std::endl;
		exit(1);
	}
	return (*Q).GetData(currentIndex);
}

template<class T>
void QueueIterator<T>::Next(void)
{
	if(!iterationComplete)
	{
		currentIndex++;					// offset next target
		if(currentIndex>finishIndex)
			iterationComplete=1;		// finish traver
	}
}



#endif
