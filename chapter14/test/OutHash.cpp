
#include <iostream>

#include "OutHash.h"

#include "BinFile.h"

using namespace std;

int main(int argc, char *argv[])
{
	long arr[10];
	FileDataRecord dr;
	int i, item, request;
	BinFile<FileDataRecord> datafile("fdr.dat", INOUT);

	// init hash table
	for(i=0; i<10; i++)
		arr[i]=Empty;
	// add rand number
	for(i=0; i<50; i++)
	{
		item=rand()%1000;
		dr.data=item;
		LoadRecord(datafile, arr[item%10], dr);
	}
	// get data
	std::cout<<"Enter hash table index: ";
	std::cin>>request;
	std::cout<<"pirnt list: "<<std::endl;
	PrintList(datafile, arr[request]);

	std::system("pause");
	return 0;
}
