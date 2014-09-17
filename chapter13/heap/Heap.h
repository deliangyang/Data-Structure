

#ifndef _HEAP_H__
#define _HEAP_H__


const int DefHeapSize=30;

template<class T>
class Heap
{
public:
	// constructor
	Heap(int size=DefHeapSize);
	Heap(T arr[], int n);
	Heap(const Heap<T> &hp);
	// destructor
	~Heap(void);
	// table method
	void Insert(const T & item);
	T Delete(void);

	const T& operator[](int index);
	Heap<T>& operator=(const Heap<T> &hp);
private:
	T * arr;
	int heapsize;
	int maxheap;
	void FilterDown(int i);
	void FilterUp(int i);
};

template<class T>
Heap<T>::Heap(T arr[], int n)
{
	if(n<=0)
	{
		std::cerr<<"Heap: out of memory"<<std::endl;
		exit(1);
	}
	int currentpos;
	heapsize=n;
	maxheap=n;
	this->arr=arr;
	currentpos=(heapsize-2)/2;
	while(currentpos>=0)
	{
		FilterDown(currentpos);
		currentpos--;
	}

}

template<class T>
void Heap<T>::FilterDown(int i)
{
	int currentpos=i;
	int childpos=i*2+1;
	T target=arr[currentpos];

	while(childpos<heapsize)
	{
		// if left child element more and equal than right child element
		if((childpos+1<heapsize) && (arr[childpos+1]<=arr[childpos]))
			childpos=childpos+1;
		// if parent less and equal than child
		if(target<=arr[childpos])
			break;
		else
		{
			arr[currentpos]=arr[childpos];
			currentpos=childpos;
			childpos=currentpos*2+1;
		}
	}
	arr[currentpos]=target;
}

template<class T>
void Heap<T>::FilterUp(int i)
{
	int currentpos=i;
	int parentpos=(i-1)/2;
	T target=arr[currentpos];		// current element

	while(currentpos!=0)
	{
		if(target<arr[parentpos])	// if current element < parent element
		{
			arr[currentpos]=arr[parentpos];
			currentpos=parentpos;
			parentpos=(currentpos-1)/2;
		}
		else
			break;
	}
	arr[currentpos]=target;
}

template<class T>
Heap<T>::Heap(int size)
{
	arr=new T[size];
	heapsize=0;
	maxheap=size;
}

template<class T>
void Heap<T>::Insert(const T &item)
{
	if(heapsize==maxheap)
	{
		std::cerr<<"Insert: Heap Full"<<std::endl;
		return;
	}
	arr[heapsize]=item;
	FilterUp(heapsize);
	heapsize++;
}

template<class T>
T Heap<T>::Delete(void)
{
	if(heapsize==0)
	{
		std::cerr<<"Delete: Heap Empty"<<std::endl;
		exit(1);
	}
	T temp;
	temp=arr[0];
	arr[0]=arr[heapsize-1];
	heapsize--;
	FilterDown(0);
	return temp;
}

template<class T>
const T& Heap<T>::operator[](int index)
{
	if(index<0 || index>=heapsize)
	{
		std::cerr<<"Operator: out of range"<<std::endl;
		exit(1);
	}
	return arr[index];
}

template<class T>
Heap<T>::~Heap(void)
{
	delete[] arr;
}

#endif

