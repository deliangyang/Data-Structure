
#include <iostream>

using namespace std;

#define LEN 5

void MakeArray(int arr[LEN][LEN]);
int Trace(int arr[LEN][LEN]);
void PrintArray(int arr[LEN][LEN]);

int main(int argc, char *argv[])
{
	int arr[LEN][LEN];
	int result;
	std::cout<<"Make Array"<<std::endl;
	MakeArray(arr);
	PrintArray(arr);
	std::cout<<std::endl;
	result=Trace(arr);
	std::cout<<"The result is: "<<result<<std::endl;

	std::system("pause");
	return 0;
}

void MakeArray(int arr[LEN][LEN])
{
	int i, j;
	for(i=0; i<LEN; i++)
		for(j=0; j<LEN; j++)
			arr[i][j]=rand()%100;
}

int Trace(int arr[LEN][LEN])
{
	int i, j;
	int result=0;
	for(i=0; i<LEN; i++)
		for(j=0; j<LEN; j++)
			if(i==j)
				result+=arr[i][j];
	return result;
}

void PrintArray(int arr[LEN][LEN])
{
	int i, j;
	for(i=0; i<LEN; i++)
	{
		for(j=0; j<LEN; j++)
		{
			std::cout.setf(ios::left);
			std::cout.width(3);
			std::cout<<arr[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
}
