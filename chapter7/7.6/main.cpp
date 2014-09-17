
#include <iostream>
#include "DataInfo.h"

using namespace std;


int main(int argc, char *argv[])
{
	int n;
	//int * arr;
	int i;
	int temp;
	std::cout<<"Enter element's number: ";
	std::cin>>n;

	// allocate memory for array (arr)
	//arr=new int[n];
	//for(i=0; i<n; i++)
	//	std::cin>>arr[i];

	DataInfo<int> datalist;
	/*
	for(i=0; i<n; i++)
	{
		std::cout<<"enter the number: ";
		std::cin>>temp;
		if(SeqSearch(datalist, n, temp)!=-1)
			datalist[i].Increment();
		else
			datalist[i].Set(temp);
	}
*/
	//for(i=0; i<n; i++)
		std::cout<<datalist;//[i];
		



	// free
	//delete[] arr;


	std::system("pause");
	return 0;
}
