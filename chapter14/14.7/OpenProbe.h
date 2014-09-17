
#ifndef __OPENPROBE_H__
#define __OPENPROBE_H__

#include "List.h"

template<class T>
class OpenProbeIterator;

template<class T>
struct TableRecord
{
	// adjust data is exsit or not
	int available;
	T data;
};

template<class T>
class OpenProbe:public List<T>
{
public:
	OpenProbe(int ts, unsigned long hashf(T key));
	~OpenProbe(void);
	// some base method
	virtual void Insert(const T &key);
	virtual void Delete(const T &key);
	virtual int Find(const T &key);
	virtual void ClearList(void);
	// Modify table
	void Update(const T &key);

	friend class OpenProbeIterator<T>;
protected:
	TableRecord<T> * table;
	int tablesize;
	unsigned long (*hf)(T key);
	// visit last subcript index element
	int lastIndex;
};

template<class T>
OpenProbe<T>::OpenProbe(int ts, unsigned long hashf(T key))
{	
	table=new TableRecord<T>[ts];
	tablesize=ts;
	hf=hashf;
	lastIndex=ts;
}

template<class T>
void OpenProbe<T>::Insert(const T &key)
{
	int hashval=int(hf(key)%tablesize);
	TableRecord<T> &tr=table[hashval];
	if(tr.available==1)
		return;
	else
	{
		tr.available=1;
		tr.data=key;
	}
}

template<class T>
int OpenProbe<T>::Find(const T &key)
{
	int i;
	for(i=0; i<tablesize; i++)
	{
		TableRecord<T> tr=table[i];
		if(key==tr.data)
			return i;
	}
	return -1;
}

template<class T>
void OpenProbe<T>::Delete(const T &key)
{
	int hashval=int(hf(key)%tablesize);
	TableRecord<T> &tr=table[hashval];
	if(tr.available==1)
		tr.available=-2;
	else
		return;
}

template<class T>
void OpenProbe<T>::ClearList(void)
{
	delete [] table;
}

// free memory
template<class T>
OpenProbe<T>::~OpenProbe(void)
{
	delete[] table;
}



#endif
