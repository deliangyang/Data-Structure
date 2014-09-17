
#include <iostream>

#include "ArrayIterator.h"
#include "../Array.h"

using namespace std;

int main(int argc, char *argv[])
{
	
	Array<int> arr(10);
	ArrayIterator<int> iterator(arr);
	int i;
	for(i=0; i<10; i++)
	{
		arr[i]=rand()%10;
		std::cout<<arr[i]<<" ";
	}
	std::cout<<std::endl;

	for(iterator.Reset(); !iterator.EndOfList(); iterator.Next())
		std::cout<<iterator.Data()<<" ";
	std::cout<<std::endl;


	std::system("pause");
	return 0;
}
