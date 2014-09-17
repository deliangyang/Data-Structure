

#ifndef _PRIORITYQUEUE_H
#define _PRIORITYQUEUE_H

const int DefPQueue = 30;

template<class T>
class PQueue
{
public:
	PQueue(void);
	PQueue(int size);
	void Insert(T item);
	T Delete(void);
	int isFull(void)const;
	int isEmpty(void)const;
	~PQueue(void);
private:
	T * data;
	int count;
	int size;
};

template<class T>
PQueue<T>::PQueue(void)
{
	size=DefPQueue;
	data=new T[size];
	count=0;
}

template<class T>
PQueue<T>::PQueue(int size)
{
	this->size=size;
	data=new T[size];
	count=0;
}

template<class T>
void PQueue<T>::Insert(T item)
{
	if(count==size)
	{
		std::cerr<<"Priority Queue Is Full"<<std::endl;
		return;
	}
	data[count]=item;
	count++;
}

template<class T>
T PQueue<T>::Delete(void)
{
	if(count<0)
	{
		std::cerr<<"Priority Queue Is Empty"<<std::endl;
		exit(0);
	}
	int i;
	T temp;
	int minIndex=0;
	temp=data[0];
	for(i=1; i<count; i++)	
		if(temp>data[i])
		{
			temp=data[i];
			minIndex=i;
		}

	data[minIndex]=data[count-1];
	count--;
	return temp;
}

template<class T>
int PQueue<T>::isEmpty(void)const
{
	return count==0;
}

template<class T>
int PQueue<T>::isFull(void)const
{
	return count==size;
}

template<class T>
PQueue<T>::~PQueue(void)
{
	delete[] data;
}

#endif
