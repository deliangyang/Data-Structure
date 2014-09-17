
#ifndef __INSORT_H__
#define __INSORT_H__

#include "BinFile.h"
#include "Sort.h"

template<class T>
void Merge(BinFile<T> &fA, BinFile<T> &fB, T arr[], int n)
{
	int curA=1, curB=1;

	T dataA, dataB;
	int haveA, haveB;

	fA.Reset();
	fB.Reset();

	fA.Read(&dataA, 1);
	fB.Read(&dataB, 1);
	int i=0;
	for(;;)
	{
		if(dataA<=dataB)
		{
			arr[i++]=dataA;
			// if go go to file last
			if((haveA=fA.Read(&dataA, 1))==0 || ++curA>n)
			{
				arr[i++]=dataB;
				curB++;
				CopyTail(fB, arr, curB, n, i);
				if(!haveA)
					break;
				curA=1;
				//  fb last
				if((haveB=fB.Read(&dataB, 1))==0)
				{
					arr[i++]=dataA;
					curA=2;
					break;
				}
				curB=1;
			}
		}
		else
		{
			arr[i++]=dataB;
			if((haveB=fB.Read(&dataB, 1))==0 || ++curB>n)
			{
				arr[i++]=data;
				curA++;
				CopyTail(fA, arr, curA, n, i);
				if(!haveA)
				{
					curA=1;
					break;
				}
				curB=1;
				if((haveA=fA.Read(&dataA, 1))==0)
					break;
				curA=1;
			}
		}
	}
}

// merge sort size k*blocksize
template<class T>
void Split(BinFile<T> &fA, BinFile<T> &fB, T arr[], int k, int blocksize, int arrsize)
{
	int useA=1;
	int i=0;
	int j=0;
	int readCount;

	fA.Clear();
	fB.Clear();

	while(i<arrsize)
	{
		if(useA)
			fA.Write(arr, blocksize);
		else
			fB.Write(arr, blocksize);
		i+=blocksize;
		if(++j==k)
		{
			i=0;
			useA=!useA;
		}
	}
	// copy last (i-arrsize)
	if((i-arrsize)<blocksize)
	{
		if(useA)
			fA.Write(arr, (i-arrsize));
		else
			fB.Write(arr, (i-arrsize));
	}
}

template<class T>
void MergeSort(T arr[], int blocksize, int arrsize)
{
	BinFile<T> &fA("fa", INOUT);
	BinFile<T> &fB("fb", INOUT);

	// change a and b
	int useA=1;
	// get file size
	int size=blocksize;
	// restart arr
	int i=0;
	// memory temp array
	T * data;
	data=new T[size];
	while(i<arrsize)
	{
		CoprArray(arr, data, i, i+size);

		QuickSort(data, 0, size-1);

		if(useA)
			fA.Write(&data, size);
		else
			fB.Write(&data, size);
		useA=!useA;
		i+=size;
	}
	delete[] data;
	if((i-arrsize)<size)
	{
		data=new T[i-arrsize];
		CoprArray(arr, data, 2*arrsize-i, arrsize);
		QuickSort(data, 0, i-arrsize-1);

		if(useA)
			fA.Write(&data, i-arrsize);
		else
			fB.Write(&data, i-arrsize);
		delete[] data;
	}

	Merge(fA, fB, arr, arrsize);
}


template<class T>
void CopyTail(BinFile<T> &fx, T arr[], int &current, int n, int &arrpos)
{
	T data;
	while(current<=n)
	{
		if(fx.Read(&data, 1)==0)
			return;
		current++;
		arr[arrpos++]=data;
	}
}

template<class T>
void CoprArray(T arr[], T temp[], int start, int end)
{
	int i, j=0;
	for(i=start; i<end; i++)
		temp[j++]=arr[i];
}


#endif
