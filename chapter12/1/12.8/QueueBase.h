
#ifndef __QUEUEBASE_H__
#define __QUEUEBASE_H__

template<class T>
class QueueBase
{
public:
	QueueBase(void);
	virtual int isEmpty(void)const;
	virtual int Length(void)const;
	virtual void Insert(const T& item)=0;
	virtual T& Delete(void)=0;
protected:
	int size;
};

template<class T>
QueueBase<T>::QueueBase(void)
{
	size=0;
}

template<class T>
int QueueBase<T>::isEmpty(void)const
{
	return size==0;
}

template<class T>
int QueueBase<T>::Length(void)const
{
	return size;
}

#endif
