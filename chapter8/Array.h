

const int DefArraySize=30;

template<class T>
class Array
{
public:
	Array(int size=DefArraySize);
	Array(const Array<T>& a);
	T& operator[](int n);
	int length(void)const;
	void Resize(int sz);
	operator T*(void)const;
	~Array(void);
public:
	T * arr;
	int size;
};

template<class T>
Array<T>::Array(int size)
{
	this->size=size;
	if(size<=0)
		exit(0);
	arr=new T[size];
}

template<class T>
Array<T>::Array(const Array<T>& a)
{
	int n=a.size;
	arr=new T[n];
	T* temp=a.arr;
	T* destPtr=arr;
	while(n--)
		*destPtr++=*temp++;
}

template<class T>
int Array<T>::length(void)const
{
	return size;
}

template<class T>
T& Array<T>::operator[](int n)
{
	if(n<0 || n>size)
		exit(0);
	return arr[n];
}

template<class T>
Array<T>::~Array(void)
{
	delete[] arr;
}

template<class T>
Array<T>::operator T*(void)const
{
	return arr;
}

template<class T>
void Array<T>::Resize(int sz)
{
	if(sz<=0 || sz==size)
		return;
	T * newlist=new T[sz];
	if(newlist==NULL)
		return;
	int n=sz<=size?sz:size;
	T * srcPrt=arr;
	T * destPtr=newlist;
	while(n--)
		*destPtr++=*srcPrt++;
	delete[] arr;
	arr=newlist;
	size=sz;
}
