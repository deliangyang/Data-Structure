
#include <iostream>

#include "../Arrayoder.h"
#include "ArrPreorderIterator.h"

using namespace std;

int main(int argc, char *argv[])
{
	int arr[10]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	ArrPreorderIterator<int> iterator(arr, 10);

	std::cout<<"iterator: ";
	for(iterator.Reset(); !iterator.EndOfList(); iterator.Next())
		std::cout<<iterator.Data()<<" ";
	std::cout<<std::endl;
	std::cout<<"level scan: ";
	Preorder(arr, 0, 10);
	std::cout<<std::endl;
	std::system("pause");
	return 0;
}
