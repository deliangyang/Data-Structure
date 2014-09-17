
#include <iostream>

#include "Heap.h"

using namespace std;

int main(int argc, char *argv[])
{
	
	Heap<int> heap(10);
	int i;
	for(i=0; i<10; i++)
		heap.Insert(rand()%10);

	for(i=0; i<10; i++)
		std::cout<<heap[i]<<std::endl;
	std::cout<<std::endl;

	for(i=0; i<10; i++)
		std::cout<<heap.Delete()<<" ";
	std::cout<<std::endl;

	std::system("pause");
	return 0;
}
