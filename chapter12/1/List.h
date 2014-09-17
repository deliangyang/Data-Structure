

#ifndef __LIST_H__
#define __LIST_H__

template<class T>
class List
{
protected:
	int size;  				// list size
public:
	List(void);
	// virtual function
	virtual int ListSize(void)const;
	virtual int ListEmpty(void)const;
	// A pure virtual function
	virtual int Find(T& item)=0;
	//virtual void Insert(const T& item)=0;
	//virtual void Delete(const T& item)=0;
	//virtual void ClearList(void)=0;	
};

template<class T>
List<T>::List(void)
{
	size=0;
}

template<class T>
int List<T>::ListSize(void)const
{
	return size;
}

template<class T>
int List<T>::ListEmpty(void)const
{
	return size==0;
}

#endif		
