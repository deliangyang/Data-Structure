
#include "ShellSort.h"

#include <iostream>

#include <iomanip>

void PrintArray(int * arr, int n)
{
	int i;
	for(i=0; i<n; i++)
		std::cout<<arr[i]<<" ";
	std::cout<<std::endl;
}


void PrintTenNumOneLine(int * arr, int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		std::cout<<std::setw(4)<<arr[i]<<" ";
		if((i+1)%10==0)
			std::cout<<std::endl;
	}
}

int main(int argc, char *argv[])
{
	//int arr[]={4, 1, 42, 10, 32, 100, 42};
	int arr[40];
	int i;
	for(i=0; i<40; i++)
		arr[i]=rand()%40;
	//InsertionSort(arr, 40);
	ShellSort(arr, 40);
	//PrintArray(arr, 40);
	PrintTenNumOneLine(arr, 40);
	std::system("pause");
	return 0;
}
