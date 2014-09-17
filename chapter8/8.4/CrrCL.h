

#ifndef _CRRCL_H
#define _CRRCL_H

const int DefCrrCLSize=50;

template<class T>
class CrrCL
{
public:
	CrrCL(int size=DefCrrCLSize);
	int length(void)const;
	T& operator[](int n);
	//operator T*(void);
	~CrrCL();
private:
	T * data;
	int size;
};


template<class T>
CrrCL<T>::CrrCL(int size)
{
	data=new T[size];
}

template<class T>
int CrrCL<T>::length(void)const
{
	return size;
}

template<class T>
CrrCL<T>::~CrrCL(void)
{
	delete[] data;
}

template<class T>
T& CrrCL<T>::operator[](int n)
{
	return data[n];
}


#endif

