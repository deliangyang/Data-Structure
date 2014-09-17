
#ifndef _DATAINFO_H
#define _DATAINFO_H

#include <fstream>

template<class T>
class DataInfo
{
public:
	DataInfo(void);
	DataInfo(T data);
	void Increment(void);
	void Set(T data);

	int operator==(const DataInfo<T>& w);
	int operator<(const DataInfo<T>& w);

	friend std::istream& operator>>(std::istream& is, const DataInfo<T>& w);
	friend std::ostream& operator<<(std::ostream& os, const DataInfo<T>& w);
private:
	T data;
	int frequency;
};

template<class T>
DataInfo<T>::DataInfo(void)
{
	this->data=-1;
	frequency=0;
}

template<class T>
DataInfo<T>::DataInfo(T data)
{
	this->data=data;
	frequency=1;
}

template<class T>
void DataInfo<T>::Increment(void)
{
	frequency++;
}

template<class T>
void DataInfo<T>::Set(T data)
{
	this->data=data;
	frequency=1;
}

template<class T>
int DataInfo<T>::operator==(const DataInfo<T>& w)
{
	return w.data==data;
}

template<class T>
int DataInfo<T>::operator<(const DataInfo<T>& w)
{
	return data<w.data;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const DataInfo<T>& w)
{
	os<<w.data<<":"<<w.frequency<<std::endl;
	return os;
}

template<class T>
std::istream& operator>>(std::istream& is, const DataInfo<T>& w)
{
	is>>w.data;
	frequency++;
	return is;
}

template<class T>
int SeqSearch(T arr[], int n, T key)
{
	int i;
	for(i=0; i<n; i++)
		if(arr[i]==key)
			return i;
	return -1;
}

template<class T>
void ExchangeSort(T arr[], int n)
{
	T temp;
	int i, j;
	for(i=0; i<n-1; i++)
	{
		for(j=0; j<n-i-1; j++)
		{
			if(arr[j]<arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

#endif
