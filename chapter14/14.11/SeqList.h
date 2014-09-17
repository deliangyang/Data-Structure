

#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include "Linked.h"

template<class T>
class SeqListIterator;

template<class T>
class SeqList
{
public:
	SeqList(void);

	int Length(void)const;
	int isEmpty(void)const;
	int Find(T item);
	T GetData(int pos);

	void Insert(T item);
	void Delete(T item);
	T DeleteFront(void);
	void ClearList(void);

	friend class SeqListIterator<T>;
protected:
	Linked<T> list;	
	int size;
};

template<class T>
SeqList<T>::SeqList(void):size(0){}

template<class T>
int SeqList<T>::Length(void)const
{
	return size;
}

template<class T>
int SeqList<T>::isEmpty(void)const
{
	return size==0;
}

template<class T>
int SeqList<T>::Find(T item)		// find element
{
	int result=0;
	for(list.Reset(); !list.EndOfList(); list.Next())
		if(item==list.Data())
		{
			result++;
			break;
		}
	return result;
}

template<class T>
T SeqList<T>::GetData(int pos)
{
	if(pos<0 || pos>size-1)
	{
		std::cerr<<"position out of range"<<std::endl;
		exit(1);
	}
	list.Reset(pos);
	return list.Data();
}

template<class T>
void SeqList<T>::Insert(T item)
{
	list.InsertAfter(item);
	size++;
}

template<class T>
void SeqList<T>::Delete(T item)
{
	if(size<=0)
	{
		std::cerr<<"Calling Delete for an emptry queue"<<std::endl;
		exit(1);
	}
	int result=0;
	for(list.Reset(); !list.EndOfList(); list.Next())
	{
		if(list.Data()==item)
			break;
		result++;
	}
	list.Reset(result);
	list.DeleteAt();
	size--;
}

template<class T>
T SeqList<T>::DeleteFront(void)
{
	if(size<=0)
	{
		std::cerr<<"Calling Delete for an emptry queue"<<std::endl;
		exit(1);
	}
	size--;
	return list.DeleteFront();
}


#endif
