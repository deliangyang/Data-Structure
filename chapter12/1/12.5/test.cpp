
#include <iostream>

#include "Array.h"

using namespace std;

int main(int argc, char *argv[])
{
	Array<int> arr(10);
	int i;
	for(i=0; i<10; i++)
		arr[i]=rand()%10;
	for(i=0; i<10; i++)
		std::cout<<arr[i]<<" ";
	//std::endl;
	std::system("pause");
	return 0;
}

