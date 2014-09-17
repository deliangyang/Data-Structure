


#include <iostream>
#include <iomanip>
#include "InSort.h"

#include "BinFile.h"

using namespace std;

const int len = 1000;

void PrintArray(float arr[], int n)
{
	int i, k=0;
	for(i=0; i<n; i++)
	{
		if(i<20 || i>n-20)
		{
			std::cout<<setprecision(4)<<arr[i]<<"\t";
			k++;
		}
		if((k%5==0) && (i<20 || i>n-20))
			std::cout<<std::endl;
	}
}

int main(int argc, char *argv[])
{
	//BinFile<float> ba("fa", INOUT);
	//BinFile<float> bb("fb", INOUT);

	float arr[len];
	int i;
	for(i=0; i<len; i++)
		arr[i]=float((rand()%10)/100.0);
	//MergeSort(ba, bb, arr, )
	MergeSort(arr, 20, len);
	PrintArray(arr, len);

	std::system("pause");
	return 0;
}
