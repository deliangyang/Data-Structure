#include <iostream>

void OctIn(unsigned int& n);
int pow(int num, int n);

int main(int argc, char *argv[])
{
	unsigned int arr[5]={7, 177, 127, 1776, 177777};
	int i;
	for(i=0; i<5; i++)
	{
		std::cout<<arr[i]<<": ";
		OctIn(arr[i]);
	}
	
	std::system("pause");
	return 0;
}

int pow(int num, int n)
{
	int result=1;
	while(n)
	{
		result*=num;
		n--;
	}
	return result;
}

void OctIn(unsigned int& n)
{
	int count=0, result=0; 
	int mod;
	while(n)
	{
		mod=n%10;
		result+=(mod*pow(8, count));
		n/=10;
		count++;
	}
	std::cout<<result<<std::endl;
}
