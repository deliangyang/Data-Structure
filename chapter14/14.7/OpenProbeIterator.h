
#ifndef __OPENPROBEITERATOR_H__
#define __OPENPROBEITERATOR_H__

#include "OpenProbe.h"
#include "Iterator.h"

template<class T>
class OpenProbeIterator:public Iterator<T>
{
public:
	OpenProbeIterator(OpenProbe<T> &open);
	virtual void Reset(void);
	virtual void Next(void);
	virtual T &Data(void);
	void SetList(OpenProbe<T> &open);
	//~OpenProbeIterator();
private:
	OpenProbe<T> * open;
	int current;
};

template<class T>
OpenProbeIterator<T>::OpenProbeIterator(OpenProbe<T> &open):open(&open), Iterator<T>()
{
	iterationComplete=0;
	current=0;
}

template<class T>
void OpenProbeIterator<T>::Reset(void)
{
	current=0;
	iterationComplete=0;
	TableRecord<T> tb=open->table[current];
	while(tb.available!=1)
	{
		current++;
		tb=open->table[current];
	}	
}

template<class T>
void OpenProbeIterator<T>::Next(void)
{
	if(current>=open->tablesize)
		iterationComplete=1;
	TableRecord<T> tb=open->table[current];
	if(tb.available!=1)
	{
		while(tb.available!=1)
		{
			current++;
			tb=open->table[current];
		}	
	}
	else
		current++;
}

template<class T>
T &OpenProbeIterator<T>::Data(void)
{
	if(iterationComplete || current>=open->tablesize)
	{
		iterationComplete=1;
		exit(1);
	}
	TableRecord<T> tb=open->table[current];

	return tb.data;
}

template<class T>
void OpenProbeIterator<T>::SetList(OpenProbe<T> &open)
{
	this->open=open;
	iterationComplete=0;
	current=0;
}

#endif
