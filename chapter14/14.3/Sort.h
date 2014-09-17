

template<class T>
void Swap(T& a, T& b)
{
	T temp=a;
	a=b;
	b=temp;
}

template<class T>
void SelectSort(T arr[], int n)
{
	int i, j;
	int index;
	for(i=0; i<n; i++)
	{
		index=i;
		for(j=i+1; j<n; j++)
			if(arr[index]>arr[j])
				index=j;
		Swap(arr[i], arr[index]);
	}
}

template<class T>
void BubbleSort(T arr[], int n)
{
	int i, j;
	for(i=0; i<n-1; i++)
		for(j=0; j<n-i-1; j++)
			if(arr[j]>arr[j+1])
				Swap(arr[j], arr[j+1]);
}

// O(n^2)
template<class T>
void InsertionSort(T arr[], int n)
{
	int i, j;
	T temp;
	int index;
	for(i=1; i<n; i++)
	{
		j=i;
		temp=arr[i];
		while(j>0 && temp<arr[j-1])
		{
			arr[j]=arr[j-1];
			j--;
		}
		arr[j]=temp;
	}
}

template<class T>
void QuickSort(T arr[], int low, int height)
{
	if(low<height)
	{
		int i=low, j=height;
		T x=arr[low];
		while(i<j)
		{
			while(i<j && arr[j]>=x)
				j--;
			if(i<j)
				arr[i++]=arr[j];
			while(i<j && arr[i]<x)
				i++;
			if(i<j)
				arr[j--]=arr[i];
		}
		arr[i]=x;
		QuickSort(arr, low, i-1);
		QuickSort(arr, i+1, height);
	}
}
