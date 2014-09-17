
#include <iostream>

#include "BinFile.h"

using namespace std;

int main(int argc, char *argv[])
{
	int arr[]={3, 1, 3, 4};
	BinFile<int> bin("hello.dat", OUT);
	bin.Write(arr, 4);
	/*int arr[4];
	BinFile<int> bin("hello.txt", IN);
	bin.Read(arr, 4);
	int i;
	for(i=0; i<4; i++)
		std::cout<<arr[i]<<" ";*/
	std::system("pause");
	return 0;
}
