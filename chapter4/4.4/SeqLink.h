
#ifndef _SEQLINK_H
#define _SEQLINK_H

const int MaxSize = 50;

enum ErrorType{LinkFull, LinkEmpty, NoMemoryAllocate};

const char * ErrorMSG[]={"Link Full", "Link Empty", "No Memory Allocate"};

template<class T>
class SeqLink
{
public:
	SeqLink();
	SeqLink(int size);
	~SeqLink();
	void Insert(const T& item);
	void Delete(const T& item);
	int Find(T item)const;
	int Size(void)const;
	T GetData(int position)const;
	int isEmpty(void)const;
	int isFull(void)const;
	void Clear(void);
private:
	T * data;
	int size;
	int count;
	void Error(ErrorType type);
};

template<class T>
SeqLink<T>::SeqLink()
{
	size=MaxSize;
	data=new T[size];
	count=0;
}

template<class T>
SeqLink<T>::SeqLink(int size)
{
	this->size=size;
	data=new T[size];
	count=0;
}

template<class T>
SeqLink<T>::~SeqLink()
{
	delete[] data;
}

template<class T>
int SeqLink<T>::isEmpty()const
{
	return count==0;
}

template<class T>
int SeqLink<T>::isFull()const
{
	return count==size;
}

template<class T>
int SeqLink<T>::Size(void)const
{
	return count;
}

template<class T>
void SeqLink<T>::Insert(const T& item)
{
	if(isFull())
	{
		Error(LinkFull);
		return;
	}
	data[count]=item;
	count++;
}

template<class T>
void SeqLink<T>::Delete(const T& item)
{
	if(isEmpty())
	{
		Error(LinkEmpty);
		return;
	}
	int i=0;
	while(i<count && !(data[i]==item))
		i++;
	if(i<count)
	{
		while(i<count-1)
		{
			data[i]=data[i+1];
			i++;
		}
		count--;
	}
}

template<class T>
T SeqLink<T>::GetData(int position)const
{
	if(position>count && position<0)
		std::cerr<<"out of range"<<std::endl;
	return data[position];
}

template<class T>
int SeqLink<T>::Find(T item)const
{
	if(isEmpty())
		return 0;
	int i=0;
	while(i<count && !(data[i]==item))
		i++;
	if(i<count && i!=0)
		return 1;
	return 0;
}

template<class T>
void SeqLink<T>::Clear(void)
{
	count=0;		// clear to 0, it isn't mean free data
}

template<class T>
void SeqLink<T>::Error(ErrorType type)
{
	std::cout<<ErrorMSG[type]<<std::endl;
}

#endif
