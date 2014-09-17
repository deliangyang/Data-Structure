

#include "Linked.h"

template<class T>
class Queue
{
public:
	Queue(void);
	void Insert(const T& elt);
	T Delete(void);
	T DFront(void);
	int Length(void)const;
	int isEmptry(void)const;
	void Clear(void);
	~Queue(void);
private:
	Linked<T> list;
	int size;
};

template<class T>
Queue<T>::Queue(void):size(0)
{}

template<class T>
Queue<T>::~Queue(void)
{}

template<class T>
void Queue<T>::Insert(const T& elt)
{
	size++;
	list.InsertAfter(elt);
}

template<class T>
T Queue<T>::Delete(void)
{
	if(size<=0)
	{
		std::cerr<<"Calling Delete for an emptry queue"<<std::endl;
		exit(1);
	}
	size--;
	return list.DeleteFront();
}

template<class T>
int Queue<T>::isEmptry(void)const
{
	return size==0;
}

template<class T>
int Queue<T>::Length(void)const
{
	return size;
}

template<class T>
void Queue<T>::Clear(void)
{
	list.ClearList();
	size=0;
}

