

#include "../Linked.h"

template<class T>
class Stack
{
public:
	Stack(void);
	void push(T item);
	T pop(void);

	int length(void)const;
	int isEmpty(void)const;
	void Clear(void);
	void Print(void);
private:
	Linked<T> link;
};

template<class T>
Stack<T>::Stack(void){}

template<class T>
void Stack<T>::push(T item)
{
	link.InsertAfter(item);
}

template<class T>
T Stack<T>::pop(void)
{
	if(link.ListSize()<=0)
	{
		std::cerr<<"Pop: stack emptry"<<std::endl;
		exit(1);
	}
	return link.Delete();
}

template<class T>
int Stack<T>::length(void)const
{
	return link.ListSize();
}

template<class T>
int Stack<T>::isEmpty(void)const
{
	return link.ListSize()==0;
}

template<class T>
void Stack<T>::Print(void)
{
	for(link.Reset(); !link.EndOfList(); link.Next())
		std::cout<<link.Data()<<" ";
	std::cout<<std::endl;
}

