
/*
 *
 *			ADT  storage KeyValue into BinSTree
 *					[KeyValue<K, V>]
 *					/				\
 *		[KeyValue<K, V>]		[KeyValue<K, V>]
 *			/					  /			  \
 *		NULL		[KeyValue<K, V>]		   NULL
 */


#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__

#include "BinSTree.h"
#include "KeyValue.h"

template<class K, class V>
class Dict:public BinSTree<KeyValue<K, V> >
{
public:
	// constructor
	Dict(const V &defVal);
	// subscript operator
	V &operator[](const K &index);
	// other operator function
	int InDict(const K &keyVal);
	void DeleteKey(const K &keyVal);
private:
	V defaultValue;
};

template<class K, class V>
Dict<K, V>::Dict(const V &defVal):BinSTree<KeyValue<K, V> >(), defaultValue(defVal)
{}

template<class K, class V>
V& Dict<K, V>::operator[](const K &index)
{
	KeyValue<K, V> targetKey(index, defaultValue);
	if(!Find(targetKey))
	{
		std::cout<<"after insert"<<std::endl;
		Insert(targetKey);
		std::cout<<"belong to insert"<<std::endl;
	}
	return current->data.value;
}

template<class K, class V>
int Dict<K, V>::InDict(const K &keyVal)
{
	KeyValue<K, V> tmep(keyVal, defaultValue);
	int retval=1;
	if(!Find(temp))
		retval=0;
	return retval;
}

template<class K, class V>
void Dict<K, V>::DeleteKey(const K &keyVal)
{
	KeyValue<K, V> temp(keyVal, defaultValue);
	Delete(temp);
}

#endif

