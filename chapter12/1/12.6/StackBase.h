

template<class T>
class StackBase
{
public:
	StackBase(void);
	virtual void push(T& item)=0;
	virtual T& pop(void)=0;
	virtual int StackEmpty(void)const=0;
protected:
	int numElements;
};

template<class T>
StackBase<T>::StackBase(void):numElements(-1)
{}
