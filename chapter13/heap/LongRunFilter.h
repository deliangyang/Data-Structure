
#ifndef __LONGRUNFILTER_H__
#define __LONGRUNFILTER_H__

#include "../PQueue.h"

template<class T>
class LongRunFilter
{
public:
	// constructor
	LongRunFilter(T arr[], int n, int sz);
	// destructor
	~LongRunFilter(void);
	// create long run filter
	void LoadRuns(void);
	// Assessment long run filter
	void PrintRuns(void);
	int CountRuns(void)const;

private:
	// A is the table, and two priority queue two storage
	T * A;
	PQueue<T> * pq1, * pq2;
	int loadIndex;
	int arraysize;
	int filtersize;
	// copy pq2 to pq1
	void CopyPQ(void);
	// put A into pq1
	void LoadPQ(void);
};

template<class T>
LongRunFilter<T>::LongRunFilter(T arr[], int n ,int sz):
								arraysize(n), A(arr), filtersize(sz)
{
	if(filtersize!=0)
	{
		pq1=new PQueue<T>(filtersize);
		pq2=new PQueue<T>(filtersize);
		loadIndex=0;
		// move array element to pq1
		LoadPQ();
	}
}

template<class T>
void LongRunFilter<T>::CopyPQ(void)
{
	// 复制pq2中的数据到pq1
	T temp;
	while(!pq2->PQEmpty())
	{
		temp=pq2->PQDelete();
		pq1->PQInsert(temp);
	}
}

template<class T>
void LongRunFilter<T>::LoadPQ(void)
{
	int k;
	// first 复制pq2中的数据到pq1
	CopyPQ();
	k=pq1->PQLength();
	// fill out pq1
	while(k<filtersize && loadIndex<arraysize)
	{
		pq1->PQInsert(A[loadIndex++]);
		k++;
	}
}

template<class T>
void LongRunFilter<T>::LoadRuns(void)
{
	T value;
	int currentIndex=0;
	if(filtersize==0)
		return;
	A[currentIndex]=pq1->PQDelete();

	while(currentIndex<arraysize)
	{
		value=A[loadIndex++];
		if(A[currentIndex]<=value)
			pq1->PQInsert(value);
		else
			pq2->PQInsert(value);

		if(pq1->PQEmpty())
			CopyPQ();
		
		if(!pq1->PQEmpty())
			A[++currentIndex]=pq1->PQDelete();
	}
	while(!pq1->PQEmpty())
		A[++currentIndex]=pq1->PQDelete();
	while(!pq2->PQEmpty())
		A[++currentIndex]=pq2->PQDelete();
}

template<class T>
LongRunFilter<T>::~LongRunFilter(void)
{
	if(filtersize!=0)
	{
		delete[] pq1, pq2;
	}
}

template<class T>
void LongRunFilter<T>::PrintRuns(void)
{
	int i = 1;
   	std::cout<<A[0]<<"  ";

   	do
   	{
      if(A[i]<A[i-1])
         std::cout<<std::endl;
      std::cout<<A[i++]<<"   ";
   	}
   	while(i<arraysize);
   	std::cout<<std::endl;
}

template<class T>
int LongRunFilter<T>::CountRuns(void)const
{
	int count=1, i=1;

	if(arraysize==0)
		return 0;

	while(i<arraysize)
	{
		if(A[i]<A[i-1])
			count++;
		i++;
	}

	return count;
}

#endif
