
#include <iostream>

#include "Sort.h"

using namespace std;

void PrintArray(int arr[], int n)
{
	int i;
	for(i=0; i<n; i++)
		std::cout<<arr[i]<<" ";
	std::cout<<std::endl;
}

int main(int argc, char *argv[])
{
	int arr[]={3, 4, 0, 11, 21, 7};
	//BubbleSort(arr, 6);
	//SelectSort(arr, 6);
	//InsertionSort(arr, 6);
	QuickSort(arr, 0, 5);
	PrintArray(arr, 6);

	
	std::system("pause");
	return 0;
}
