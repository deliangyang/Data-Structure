

template<class T>
void Swap(T& a, T& b)
{
	T temp=a;
	a=b;
	b=temp;
}

template<class T>
void ExchangeSort(T arr[], int n)
{
	T temp;
	int i, j;
	for(i=0; i<n-1; i++)
		for(j=0; j<n-i-1; j++)
			if(arr[j]>arr[j+1])
				Swap(arr[j], arr[j+1]);
}

template<class T>
void PrintArray(T arr[], int n)
{
	int i;
	for(i=0; i<n; i++)
		std::cout<<arr[i]<<" ";
	std::cout<<std::endl;
}
