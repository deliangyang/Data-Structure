
#include <iostream>

using namespace std;

void intout(long N, int B)
{
	if(N==0)
		return;
	else
	{
		intout(N/B, B);
		std::cout<<N%B;
		return;
	}
}

void printArray(int arr[], int n)
{
	int i;
	for(i=0; i<n; i++)
		std::cout<<arr[i]<<" ";
	std::cout<<endl;
}

int main(int argc, char *argv[])
{
	int N[]={312, 12, 10, 22, 46};
	int B[]={2, 3, 5, 7, 8};
	std::cout<<"N: ";
	printArray(N, 5);
	std::cout<<"B: ";
	printArray(B, 5);
	int i;
	for(i=0; i<5; i++)
	{
		std::cout<<N[i]<<"--"<<B[i]<<": ";
		intout(N[i], B[i]);
		std::cout<<std::endl;
	}

	
	std::system("pause");
	return 0;
}
