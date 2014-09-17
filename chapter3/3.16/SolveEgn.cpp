
#include <iostream>

using namespace std;

#define LEN 5

void MakeTriMat(int arr[LEN][LEN])
{
	int i, j;
	for(i=0; i<LEN; i++)
		for(j=0; j<LEN; j++)
			if(j>=i)
				arr[i][j]=rand()%20;
}

void PrintTriMat(int arr[LEN][LEN])
{
	int i, j;
	for(i=0; i<LEN; i++)
	{
		for(j=0; j<LEN; j++)
		{
			std::cout.setf(ios::left);
			std::cout.width(4);
			std::cout<<arr[i][j]<<" ";
		}
		std::cout<<std::endl;
	}

}


void SolveEgn(double x[], double c[])
{
	int arr[LEN][LEN];
	MakeTriMat(arr);
	int i, j;
	for(i=LEN-1; i>=0; i++)
}

int main(int argc, char *argv[])
{

	std::system("pause");
	return 0;
}