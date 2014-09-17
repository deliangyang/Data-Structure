
#include <iostream>
#include "Set.h"

using namespace std;

int main(int argc, char *argv[])
{
	// init data
	int arr0[]={1, 5, 7, 12, 24, 36, 45, 103, 355, 499};
	int arr1[]={2, 3, 5, 7, 8, 9, 12, 15, 36, 45, 56, 103, 255, 355, 498};
	int arr2[50];
	int i;
	for(i=0; i<50; i++)
		arr2[i]=i+1;
	// set 
	Set S(arr0, 10);
	Set T(arr1, 15);
	Set U(arr2, 50);

	Set st=S+T;
	Set temp=S*T;
	Set su=S*U;
	
	std::cout<<st;
	std::cout<<temp;
	std::cout<<su;

	T.Delete(8);
	T.Delete(36);
	T.Delete(103);
	T.Delete(498);
	std::cout<<T;

	int randNum=rand()%10+1;
	if(randNum^T)
		std::cout<<randNum<<" in T"<<std::endl;
	else
		std::cout<<randNum<<" isn't in T"<<std::endl;

	std::system("pause");
	return 0;
}

