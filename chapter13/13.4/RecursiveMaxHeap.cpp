
#include <iostream>
#include "Heap.h"

int main(int argc, char *argv[])
{
	int arr[10];
	int i;
	for(i=0; i<10; i++)
		arr[i]=rand()%100;
	Heap<int> heap(arr, 9);

	for(i=0; i<9; i++)
		std::cout<<heap.Delete()<<" ";
	std::cout<<std::endl;

	std::system("pause");
	return 0;
}
