

#ifndef __HEAP_H__
#define __HEAP_H__

const int outOfMemory=0, indexError=1, Empty=2, Full=3;

template<class T>
class Heap
{
public:
	Heap(int maxsize);
	Heap(T arr[], int n);
	Heap(const Heap<T> & H);
	~Heap(void);
	Heap<T>& operator=(const Heap<T>& H);
	const T& operator[](int i);

	// some attribute
	int Size(void)const;
	int isEmpty(void)const;
	int isFull(void)const;

	void Insert(T& item);
	T Delete(void);
	void ClearHeap(void);	
private:
	T * hlist;
	int inarray;
	int maxheapsize;			// max element can cantian
	int heapsize;				// table tail	
	void error(int errorType, int badIndex=0)const;
	void FilterUp(int i);
	void FilterDown(int i);
};

template<class T>
Heap<T>::Heap(int maxsize):heapsize(0)
{
	hlist=new T[maxsize];
}

template<class T>
Heap<T>::Heap(T arr[], int n)
{
	int currentpos;
	if(n<=0)
		error(outOfMemory);
	maxheapsize=n;
	heapsize=n;
	hlist=arr;
	currentpos=(heapsize-2)/2;
	while(currentpos>=0)
	{
		FilterDown(currentpos);
		currentpos--;
	}
	inarray=1;
}

template<class T>
Heap<T>::Heap(const Heap<T>& H)
{
	int n=H.heapsize;
	heapsize=H.heapsize;
	maxheapsize=H.maxheapsize;
	arr=new T[n];
	while(n--)
		arr[n]=H.arr[n];
	inarray=0;
}

template<class T>
Heap<T>::~Heap<T>(void)
{
	delete hlist;
}

template<class T>
void Heap<T>::error(int errorType, int badIndex)const
{
	if(errorType==outOfMemory)
		std::cerr<<"Out Of Memory"<<std::endl;
	else if(errorType==indexError)
		std::cerr<<"Index "<<badIndex<<" Out Of Index"<<std::endl;
	else
		std::cerr<<"Heap Empty"<<std::endl;
	exit(1);
}

template<class T>				
void Heap<T>::FilterUp(int i)					// make little heap
{
	int currentpos, parentpos;
	T target;

	currentpos=i;
	parentpos=(i-1)/2;
	target=hlist[i];

	while(currentpos!=0)
	{
		if(target>=hlist[parentpos])			// if current node more than parent node value, break
			break;
		else									// else continue up
		{
			hlist[currentpos]=hlist[parentpos];
			currentpos=parentpos;
			parentpos=(currentpos-1)/2;			// continue gradparents' node
		}
	}
	hlist[currentpos]=target;
}

template<class T>
void Heap<T>::Insert(T& item)
{
	if(hlist==maxsize)
		return;
	hlist[heapsize]=item;
	FilterUp(heapsize);
	heapsize++;
}

template<class T>
void Heap<T>::FilterDown(int i)
{
	int currentpos, childpos;
	T target;

	currentpos=i;
	target=hlist[i];
	childpos=2*i+1;

	while(childpos<heapsize)			// check is or not end
	{
		if((childpos+1<heapsize) && (hlist[childpos+1]<=hlist[childpos]))
			childpos+=1;
		if(target<=hlist[childpos])
			break;
		else
		{
			hlist[currentpos]=hlist[childpos];
			currentpos=childpos;
			childpos=2*currentpos+1;
		}
	}
	hlist[currentpos]=target;
}

template<class T>
T Heap<T>::Delete(void)
{
	T temp;
	if(heapsize==0)
		error(Empty);
	temp=hlist[0];
	hlist[0]=hlist[heapsize-1];
	heapsize--;
	FilterDown(0);
	return temp;
}

#endif
