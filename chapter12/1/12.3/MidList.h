

#ifndef __MIDLIST_H__
#define __MIDLIST_H__

#include "../SeqList.h"

template<class T>
class MidList:public SeqList<T>
{
public:
	MidList(void);
	virtual void Insert(const T& item);
	virtual void Delete(void);
};

template<class T>
MidList<T>::MidList(void)
{}

template<class T>
void MidList<T>::Insert(const T& item)
{
	int pos=Length()/2+1;
	InsertAt(item, pos);
}

template<class T>
void MidList<T>::Delete(void)
{
	int pos=Length()/2+1;
	DeleteAt(pos);
}

#endif

