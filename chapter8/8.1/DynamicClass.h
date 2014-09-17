
#ifndef _DYNAMICCLASS_H
#define _DYNAMICCLASS_H

template<class T>
class DynamicClass
{
public:
	DynamicClass(const T& m1, const T& m2);
	DynamicClass(const DynamicClass<T>& obj);
	DynamicClass<T>& operator=(const DynamicClass<T>& obj);
	~DynamicClass(void);
private:
	T member1;
	T * member2;
};

template <class T>
DynamicClass<T>::DynamicClass(const T& m1, const T& m2)
{
	member1=m1;
	member2=new T(m2);
}

template<class T>
DynamicClass<T>::DynamicClass(const DynamicClass<T>& obj)
{
	member1=obj.member1;
	member2=new T(*obj.member2);
}

template<class T>
DynamicClass<T>& DynamicClass<T>::operator=(const DynamicClass<T>& obj)
{
	member1=obj.member1;
	*member2=*obj.member2;
	return *this;
}

template<class T>
DynamicClass<T>::~DynamicClass(void)
{
	delete member2;
}

#endif

