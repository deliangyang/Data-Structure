

#ifndef __ARRAY_H__
#define __ARRAY_H__

#include "../List.h"

const int DefArraySize=30;

template<class T>
class Array:public List<T>
{
public:
	Array(int sz=DefArraySize);
	Array(const Array<T> & A);
	~Array(void);
	T& operator[](int ops);
	int Find(T &item);
private:
	T * arr;
};

template<class T>
Array<T>::Array(int sz)
{
	arr=new T[sz];
	size=sz;
}

template<class T>
Array<T>::Array(const Array<T> &A)
{
	int n=A.ListSize();
	arr=new T[n];
	T* dest=A.arr;
	T* src=arr;
	while(n--)
		*src++=*dest++;
}

template<class T>
int Array<T>::Find(T &item)
{
	int i;
	for(i=0; i<size; i++)
		if(arr[i]==item)
			return i;
}

template<class T>
T& Array<T>::operator[](int pos)
{
	if(pos<0 || pos>size-1)
	{
		std::cerr<<"Data: out of range"<<std::endl;
		exit(1);
	}
	return arr[pos];
}

template<class T>
Array<T>::~Array(void)
{
	delete[] arr;
}

#endif
