
#include <iostream>

#include "../toursort.h"

using namespace std;

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
	int i;
	int arr[100];
	for(i=0; i<100; i++)
		arr[i]=rand()%1000;

	TournamentSort(arr, 100);
	PrintArray(arr, 100);

	
	std::system("pause");
	return 0;
}
