

#ifndef __MERGESORT_H__
#define __MERGESORT_H__

#include "BinFile.h"
#include "Sort.h"

template<class T>
void MergeSort(BinFile<T> &fc, int blocksize)
{
	BinFile<T> fA("fa", INOUT);
	BinFile<T> fB("fb", INOUT);

	int size=int(fc.Size()), n=blocksize;
	int k=1, useA=1, readCount;
	T * A;
	// reset file
	fc.Reset();

	if(size<=blocksize)
	{
		A=new T[size];
		if(A==NULL)
		{
			std::cerr<<"MergeSort: memory error"<<std::endl;
			exit(1);
		}
		fc.Read(A, size);
		QuickSort(A, 0, (int)size-1);
		fc.Clear();					// clear file fc
		fc.Write(A, size);
		delete [] A;
		return;
	}
	else
	{
		A=new T[size];
		if(A==NULL)
		{
			std::cerr<<"MergeSort: memory error"<<std::endl;
			exit(1);
		}
		while(!fc.EndFile())
		{
			readCount=fc.Read(A, blocksize);
			if(readCount==0)
				break;
			QuickSort(A, 0, readCount-1);
			if(useA)
				fA.Write(A, readCount);
			else
				fB.Write(A, readCount);
			useA=!useA;
		}
		delete [] A;
	}
}


#endif
