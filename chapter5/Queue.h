
#ifndef _QUEUE_H
#define _QUEUE_H

const int DefQueueSize=30;

template<class T>
class Queue
{
public:
	Queue(void);
	Queue(int size);
	~Queue(void);
	void Insert(T item);
	T Delete(void);
	int isFull(void)const;
	int isEmpty(void)const;
private:
	T * data;
	int front;
	int tail;
	int size;
	int count;
};

template<class T>
Queue<T>::Queue(void)
{
	size=DefQueueSize;
	data=new T[size];
	front=0;
	tail=0;
	count=0;
}

template<class T>
Queue<T>::Queue(int size)
{
	this->size=size;
	data=new T[size];
	fornt=0;
	tail=0;
	count=0;
}

template<class T>
void Queue<T>::Insert(T item)
{
	if(count==size)
	{
		std::cerr<<"Queue Full"<<std::endl;
		return;
	}
	count++;
	data[tail]=item;
	tail=(tail+1)%size;
}

template<class T>
T Queue<T>::Delete(void)
{
	if(count==0)
	{
		std::cerr<<"Queue Empty"<<std::endl;
		exit(0);
	}
	T temp=data[front];
	count--;
	front=(front+1)%size;
	return temp;
}

template<class T>
int Queue<T>::isEmpty(void)const
{
	return count==0;
}

template<class T>
int Queue<T>::isFull(void)const
{
	return count==size;
}

template<class T>
Queue<T>::~Queue(void)
{
	delete[] data;
}

#endif
