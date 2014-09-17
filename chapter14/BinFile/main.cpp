

#include "BinFile.h"

#include <iostream>
#include <fstream>

int main(int argc, char const *argv[])
{
	
	BinFile<int> bin("hello.txt", IN);
	//BinFile<int> bin("hello.txt", OUT);
	///int arr[]={3, 4, 5, 1, 5, 6};
	//bin.Write(arr, 6);
	int arr[6];
	//bin.Read(arr, 6);
	bin.Read(arr, 6);
	int i;
	for(i=0; i<6; i++)
		std::cout<<arr[i]<<" ";
	std::cout<<std::endl;
	
	//bin.Reset();
	//bin.Write(&a, 3);
	//bin.Delete();

	std::system("pause");
	return 0;
}
