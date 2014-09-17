

#ifndef __SHELLSORT_H__
#define __SHELLSORT_H__

template<class T>
void InsertionSort(T * arr, int n)
{
	int i, j;
	T temp;
	for(i=1; i<n; i++)
	{
		temp=arr[i];				// get first element
		j=i-1;
		while(j>=0 && arr[j]>temp)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=temp;
	}
}

template<class T>
void ShellSort(T arr[], int n)
{
	int j, g;
	for(g=n/3; g>0; g/=3)
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

#endif

