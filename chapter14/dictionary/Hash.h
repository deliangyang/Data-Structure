
#ifndef __HASH_H__
#define __HASH_H__

template<class T>
class Hash
{
public:
	Hash();
	~Hash();
private:
	// using Array<SeqList<T> > storage the data
	Array<SeqList<T> > arr;
};


#endif
