
#include <iostream>
#include <time.h>

using namespace std;

void ExchangeSort(int * arr, int n)
{
	int i, j;
	int temp;
	long times=clock();
	for(i=0; i<n-1; i++)
		for(j=0; j<n-i-1; j++)
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
	std::cout<<"use time: "<<clock()-times<<" ms"<<std::endl;
}

void PrintArray(int * arr, int n)
{
	int i;
	for(i=0; i<n; i++)
		std::cout<<arr[i]<<" ";
	std::cout<<std::endl;
}

void MakeArray(int n)
{
	int arr[n];
	int i;
	for(i=0; i<n; i++)
		arr[i]=rand()%1000;
	ExchangeSort(arr, n);
	//PrintArray(arr, n);
}

int main(int argc, char *argv[])
{
	int n;
	int i;
	std::cout<<"Enter your number to allocate array: ";
	std::cin>>n;
	int arr[n];
	for(i=0; i<n; i++)
		arr[i]=rand()%1000;
	//long times=clock();
	ExchangeSort(arr, n);
	PrintArray(arr, n);

	int narr[4]={50, 500, 1000, 10000};
	for(i=0; i<4; i++)
		MakeArray(narr[i]);

	std::system("pause");
	return 0;
}
