

#ifndef _DATASTORE_H
#define _DATASTORE_H

const int DefStoreSize=5;

template<class T>
class DataStore
{
public:
	DataStore(void);
	int Insert(T elt);
	int Find(T elt);
	int Numelts(void);
	T& GetData(int n);
private:
	int count;
	T data[DefStoreSize];
};

template<class T>
DataStore<T>::DataStore(void)
{
	count=0;
}

template<class T>
int DataStore<T>::Insert(T elt)
{
	if(count>4)
	{
		std::cerr<<"out of range"<<std::endl;
		exit(0);
	}
	data[count]=elt;
	count++;
	return 1;
}

template<class T>
int DataStore<T>::Find(T elt)
{
	int i;
	for(i=0; i<count; i++)
		if(data[i]==elt)
			return i;
	return -1;
}

template<class T>
int DataStore<T>::Numelts(void)
{
	return count;
}

template<class T>
T& DataStore<T>::GetData(int n)
{
	if(n<0 || n>4)
	{
		std::cerr<<"out of range"<<std::endl;
		exit(0);
	}
	return data[n];
}

#endif
