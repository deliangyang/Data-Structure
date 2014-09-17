

#ifndef __SEQLISTITERATOR_H__
#define __SEQLISTITERATOR_H__

#include "SeqList.h"
#include "Iterator.h"

template<class T>
class SeqListIterator:public Iterator<T>
{
public:
	SeqListIterator(SeqList<T> & lst);
	virtual void Next(void);
	virtual void Reset(void);
	virtual T& Data(void);
	void SetList(SeqList<T> & lst);
private:
	SeqList<T> * ptrList;
	Node<T> * ptrPrev, * ptrCurrent;
};

template <class T>
SeqListIterator<T>::SeqListIterator(SeqList<T> & lst):
		Iterator<T>(), ptrList(&lst)
{
	iterationComplete=ptrList->list.ListEmpty();
	Reset();
}

template<class T>
void SeqListIterator<T>::Reset(void)
{
	iterationComplete=ptrList->list.ListEmpty();
	if(ptrList->list.front==NULL)
		return;
	ptrPrev=NULL;
	ptrCurrent=ptrList->list.front;				// SeqList need to read pivate list element private 
}

template<class T>
void SeqListIterator<T>::SetList(SeqList<T>& lst)
{
	ptrList=&lst;
	Reset();
}

template<class T>
T& SeqListIterator<T>::Data(void)
{
	if(ptrList->list.ListEmpty() ||  ptrCurrent==NULL)
	{
		std::cerr<<"Data: invalid reference"<<std::endl;
		exit(1);
	}
	return ptrCurrent->data;
}

template<class T>
void  SeqListIterator<T>::Next(void)
{
	if(ptrCurrent==NULL)
		return;
	ptrPrev=ptrCurrent;
	ptrCurrent=ptrCurrent->NextNode();
	if(ptrCurrent==NULL)
		iterationComplete=1;
}

#endif
