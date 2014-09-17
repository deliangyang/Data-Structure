
#include <iostream>

using namespace std;

int max(int x, int y)
{
	return x>y?x:y;
}

int arraymax(int arr[], int n)
{
	int temp;
	temp=arr[n-1];
	while(n>1)
	{
		temp=max(temp, arr[n-2]);
		n--;
	}
	return temp;
}


int main(int argc, char *argv[])
{
	int arr[]={3111, 4, 31, 43, 10, 12, 2};
	int temp=arraymax(arr, 7);
	std::cout<<temp;

	
	std::system("pause");
	return 0;
}
