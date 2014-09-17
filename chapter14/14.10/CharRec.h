

#ifndef __CHARREC_H__
#define __CHARREC_H__
#include <fstream>
using namespace std;

#include "BinFile.h"

struct CharRec
{
	char Key;		// storage key
	int count;		// count nubmer
};

void StorageLetter(BinFile<CharRec> &bin, CharRec cr[], int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		cr[i].Key=char('A'+i);
		cr[i].count=0;
	}
	bin.Write(cr, n);
}

void StartRead(ifstream &fin, CharRec cr[], int n)
{
	char ch;
	while(fin>>ch)
	{
		if(isalpha(ch))
		{
			if(islower(ch))
				ch=char(ch-32);
			cr[int(ch-'A')].count++;
		}
		
	}
}

void PrintCK(CharRec cr[], int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		std::cout<<cr[i].Key<<": "<<cr[i].count<<"\t";
		if((i+1)%7==0)
			std::cout<<std::endl;
	}
	std::cout<<std::endl;
}

int CountLetter(CharRec cr[], int n)
{
	int i;
	int result=0;
	for(i=0; i<n; i++)
		result+=cr[i].count;
	return result;
}


int operator>=(const CharRec &a, const CharRec &b)
{
	return a.count>=b.count;
}

int operator<(const CharRec &a, const CharRec &b)
{
	return a.count<b.count;
}

template<class T>
void QuickSort(T arr[], int low, int height)
{
	if(low<height)
	{
		int i=low, j=height;
		T x=arr[low];
		while(i<j)
		{
			while(i<j && arr[j]>=x)
				j--;
			if(i<j)
				arr[i++]=arr[j];
			while(i<j && arr[i]<x)
				i++;
			if(i<j)
				arr[j--]=arr[i];
		}
		arr[i]=x;
		QuickSort(arr, low, i-1);
		QuickSort(arr, i+1, height);
	}
}
#endif

