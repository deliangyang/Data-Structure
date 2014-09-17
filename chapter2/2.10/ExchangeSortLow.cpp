
#include <iostream>

void swap(int * a, int * b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

void ExchangeSort(int * arr, int n)
{
	int i, j;
	for(i=0; i<n-1; i++)
		for(j=0; j<n-1; j++)
			if(arr[j]<arr[j+1])
				swap(&arr[j], &arr[j+1]);
}

void printArray(int * arr, int n)
{
	int i;
	for(i=0; i<n; i++)
		std::cout<<arr[i]<<" ";
	std::cout<<std::endl;
}

int main(int argc, char *arg[])
{
	int arr[5]={32, 1, 10, 310, 4};
	printArray(arr, 5);
	ExchangeSort(arr, 5);
	printArray(arr, 5);

	std::system("pause");
	return 0;
}
