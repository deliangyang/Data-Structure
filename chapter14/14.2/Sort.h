

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



template<class T>
void Merge(T a[], int n, T b[], int m, T c[])
{
	int i=0, j=0, k=0;
	while(i<n && j<m)
	{
		if(a[i]<b[j])
			c[k++]=a[i++];
		else
			c[k++]=b[j++];
	}
	while(i<n)
		c[k++]=a[i++];
	while(j<m)
		c[k++]=b[j++];
}

template<class T>
void PrintArray(T arr[], int n)
{
	int i;
	for(i=0; i<n; i++)
		std::cout<<arr[i]<<" ";
	std::cout<<std::endl;
}

template<class T>
void ShellSort(T arr[], int n)
{
	int j, g;
	for(g=n/2; g>0; g/=2)
		for(j=g; j<n; j++)
			if(arr[j]<arr[j-g])
			{
				T temp=arr[j];
				int k=j-g;
				while(k>=0 && arr[k]>temp)
				{
					arr[k+g]=arr[k];
					k-=g;
				}
				arr[k+g]=temp;
			}
}
