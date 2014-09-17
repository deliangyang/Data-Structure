

#include <fstream>

template<class T>
class Set
{
public:
	Set(int sz);
	Set(const Set<T>& x);
	Set<T>& operator=(const Set<T>& rhs);
	int isMember(const T& elt);
	int operator==(const T& elt)const;
	Set operator+(const Set<T>& x)const;
	Set operator*(const Set<T>& x)const;
	void Insert(const T& elt);
	void Delete(const T& elt);
	~Set();

	friend std::istream& operator>>(std::istream& is, const Set<T>& x);
	friend std::ostream& operator<<(std::ostream& os, const Set<T>& x);
private:
	int setrange;
	int arrsize;
	unsigned short * member;
	int ArrayIndex(const T& elt)const;
	unsigned short BitMask(const T& elt)const;	
};

template<class T>
Set<T>::Set(int sz):setrange(sz)
{
	arrsize=(setrange+15)>>4;
	int i;
	member=new unsigned short[arrsize];
	for(i=0; i<arrsize; i++)
		member[i]=0;
}

template<class T>
Set<T>::Set(const Set<T>& x)
{
	member=x.member;
}

template<class T>
int Set<T>::ArrayIndex(const T& elt)const
{
	return int(elt)>>4;

}

template<class T>
unsigned short Set<T>::BitMask(const T& elt)const
{
	return 1<<(int(elt)&15);
}

template<class T>
Set<T>::~Set(void)
{
	delete[] member;
}

template<class T>
Set<T> Set<T>::operator+(const Set<T>& x)const
{
	Set<T> temp(setrange);
	int i;
	for(i=0; i<arrsize; i++)
		temp.member[i]=member[i]|x.member[i];
	return temp;
}
