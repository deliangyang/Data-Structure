
#include <iostream>
#include <time.h>

#include "Sort.h"

using namespace std;

template<class T>
void DoSort(T arr[], int n)
{
	T * a, * b;
	int len=n/2;
	int len2=n-len;

	a=new T[len];
	b=new T[len2];

	int i;
	for(i=0; i<len; i++)
		a[i]=arr[i];
	for(i=0; i<len2; i++)
		b[i]=arr[i+len];

	SelectSort(a, len);
	SelectSort(b, len2);

	Merge(a, len, b, len2, arr);

	delete a, b;
}

const int LEN=20000;

int main(int argc, char *argv[])
{
	int arr[10];
	int i;
	std::cout<<"First SelectSort, last MergeSort: "<<std::endl;
	for(i=0; i<10; i++)
		arr[i]=rand()%10;
	std::cout<<"Before Sort: ";
	PrintArray(arr, 10);

	DoSort(arr, 10);
	std::cout<<"After Sort: ";
	PrintArray(arr, 10);

	int a[LEN];
	for(i=0; i<LEN; i++)
		a[i]=rand()%20000;

	std::cout<<"20000 number sort, compare SelectSort and SelectMergesort: "<<std::endl;
	long start=clock();
	SelectSort(a, LEN);
	std::cout<<"SelectSort use time: "<<clock()-start<<" ms"<<std::endl;

	start=clock();
	DoSort(a, LEN);
	std::cout<<"SelectMergesort use time: "<<clock()-start<<" ms"<<std::endl;


	std::system("pause");
	return 0;
}
