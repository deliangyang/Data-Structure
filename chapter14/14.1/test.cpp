
#include <iostream>

#include "DNodeFun.h"

using namespace std;

int main(int argc, char *argv[])
{
	int n;
	std::cout<<"Please Enter the Array size: ";
	std::cin>>n;
	int i;

	int * arr;
	arr=new int[n];

	for(i=0; i<n; i++)
		arr[i]=rand()%1000;
	//int arr[]={3, 1, 0, 30, 3, 32, 10, 20, 123, 44};
	std::cout<<"Before double sort: ";
	PrintArray(arr, n);
	std::cout<<"After double sort: ";
	DoubleSort(arr, n);

	PrintArray(arr, n);

	// free arr pointer
	delete[] arr;

	std::system("pause");
	return 0;
}
