
#include <iostream>

using namespace std;

template<class T>
int FastSeqSearch(T a[], int n, T key)
{
	int i;
	for(i=0; i<n; i++)
		if(a[i]==key)
			return i;
	return -1;
}

void PrintArray(int a[], int n)
{
	int i;
	std::cout<<"array list: "<<std::endl;
	for(i=0; i<n; i++)
		std::cout<<a[i]<<" ";
	std::cout<<std::endl;
}

int main(int argc, char *argv[])
{
	int arr[]={1, 3, 4, 5, 7, 8};
	PrintArray(arr, 6);
	int index=FastSeqSearch(arr, 6, 7);
	if(index!=-1)
		std::cout<<"number 7 index is: "<<index<<std::endl;
	else
		std::cout<<"is not exsit"<<std::endl;
	std::system("pause");
	return 0;
}
