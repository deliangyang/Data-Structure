
const int DulSize=30;

template<class T>
class DulStack
{
public:
	DulStack();
	DulStack(int size);
	~DulStack();
	void Push(T item, int n);
	T Pop(int n);
	int isEmpty(int n)const;
	int isFull(int n)const;
private:
	int top1, top2;
	T * data;
};

template<class T>
DulStack<T>::DulStack()
{
	data=new T[DulSize];
	top1=DulSize/2;
	top2=DulSize/2+1;
}

template<class T>
DulStack<T>::DulStack(int size)
{
	data=new T[size];
	top1=DulSize/2;
	top2=DulSize/2+1;
}

template<class T>
DulStack<T>::~DulStack()
{
	delete[] data;
}

template<class T>
void DulStack<T>::Push(T item, int n)
{
	if(n%2==0)		// Å¼Êý
	{
		data[top2]=item;
		top2++;
	}
	else
	{
		data[top1]=item;
		top1--;
	}
}

template<class T>
T DulStack<T>::Pop(int n)
{
	if(n%2==0)
	{
		top2--;
		return data[top2];
	}
	else
	{
		top1++;
		return data[top1];
	}
}

template<class T>
int DulStack<T>::isEmpty(int n)const
{
	if(n%2==0)
	{
		return top2==DulSize/2+1;		
	}
	else
	{
		return top1==DulSize/2;
	}
}

template<class T>
int DulStack<T>::isFull(int n)const
{
	if(n%2==0)
	{
		return top2==DulSize-1;
	}
	else
		return top1==0;
}
