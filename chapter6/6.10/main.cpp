
#include <iostream>
#include "Set.h"

using namespace std;

int fillSet(void);

int main(int argc, char *argv[])
{
	int i;
	int count=0;
	
	for(i=0; i<100000; i++)
		if(fillSet()==1)
			count++;
	std::cout<<"all in S(the P): "<<count<<std::endl;
	std::system("pause");
	return 0;
}

int fillSet(void)
{
	int arr[5];
	int i;
	int count=0;
	//srand((unsigned int)rand()%100000);
	static int arr0[]={1, 5, 7, 12, 24, 36, 45, 103, 355, 499};
	static Set S(arr0, 10);
	for(i=0; i<5; i++)
		arr[i]=rand()%500;
	for(i=0; i<5; i++)
		if(arr[i]^S)
			count++;
	if(count==5)
		return 1;
	return -1;
}
