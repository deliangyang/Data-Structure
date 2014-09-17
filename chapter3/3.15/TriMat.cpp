

#include <iostream>

using namespace std;

#define LEN 5

int TriMatAdd(int arr[LEN][LEN])
{
	int i, j;
	int result=0;
	for(i=0; i<LEN; i++)
		for(j=0; j<LEN; j++)
			if(j>=i)
				result+=arr[i][j];
	return(result);
}

void TriMatSub(int (*arr)[LEN], int arr1[LEN][LEN])
{
	int i, j;
	for(i=0; i<LEN; i++)
		for(j=0; j<LEN; j++)
			arr[i][j]-=arr1[i][j];
}

int RowColumMul(int arr[LEN][LEN], int arr1[LEN][LEN], int i, int j)
{
	int k;
	int result=0;
	for(k=0; k<LEN; k++)
		result+=arr[i][k]*arr1[k][j];
	return result;
}

void TriMatMul(int arr[LEN][LEN], int arr1[LEN][LEN], int arr2[LEN][LEN])
{
	int i, j;
	for(i=0; i<LEN; i++)
		for(j=0; j<LEN; j++)
			arr[i][j]=RowColumMul(arr1, arr2, i, j);
}

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

int main(int argc, char *argv[])
{
	int arr[LEN][LEN];
	int arr1[LEN][LEN];
	int arr2[LEN][LEN];
	int result;

	memset(arr, 0, sizeof(int)*LEN*LEN);
	memset(arr1, 0, sizeof(int)*LEN*LEN);
	memset(arr2, 0, sizeof(int)*LEN*LEN);

	MakeTriMat(arr);
	MakeTriMat(arr1);

	PrintTriMat(arr);
	std::cout<<std::endl;
	PrintTriMat(arr1);	
	std::cout<<std::endl;

	TriMatMul(arr2, arr, arr1);
	TriMatSub(arr, arr1);

	std::cout<<"sub: "<<std::endl;
	PrintTriMat(arr);
	std::cout<<"mul: "<<std::endl;
	PrintTriMat(arr2);
	std::system("pause");
	return 0;
}
