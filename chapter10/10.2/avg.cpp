
#include <iostream>

using namespace std;

float avg(float a[], int n)
{
	int count=n;
	float temp=a[n-1]/count;
	while(n>1)
	{
		temp+=a[n-2]/count;
		n--;
	}
	return temp;
}

int main(int argc, char *argv[])
{
	float arr[]={10, 3, 1, 10, 3};
	float temp=avg(arr, 5);
	std::cout<<temp<<std::endl;

	
	std::system("pause");
	return 0;
}
