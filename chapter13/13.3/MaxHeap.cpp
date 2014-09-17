
#include <iostream>
#include "Heap.h"

int main(int argc, char *argv[])
{
	int arr[]={23, 1, 42, 10, 3, 12, 32, 40, 23};
	Heap<int> heap(arr, 9);
	int i;
	for(i=0; i<9; i++)
		std::cout<<heap.Delete()<<" ";
	std::cout<<std::endl;

	std::system("pause");
	return 0;
}
