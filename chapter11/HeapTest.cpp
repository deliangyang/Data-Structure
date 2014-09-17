
#include <iostream>

#include "Heap.h"

using namespace std;

template<class T>
void HeapSort(T arr[], int n)
{
	Heap<T> heap(arr, n);
	T elt;
	int i;
	for(i=n-1; i>=1; i--)
	{
		elt=heap.Delete();
		arr[i]=elt;
	}
}

template<class T>
void PrintArray(T arr[], int n)
{
	int i;
	for(i=0; i<n; i++)
		std::cout<<arr[i]<<" ";
	std::cout<<std::endl;
}

int main(int argc, char *argv[])
{

	int arr[]={4, 1, 55, 20, 319, 2};
	HeapSort(arr, 6);
	PrintArray(arr, 6);
	std::system("pause");
	return 0;
}
