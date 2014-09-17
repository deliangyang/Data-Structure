
#ifndef __DICT_H__
#define __DICT_H__

#include "HashTable.h"
#include "KeyValue.h"
#include "HashTableIterator.h"
#include "Linked.h"

template<class K, class V>
class Dict:public HashTable<KeyValue<K, V> >
{
public:
	// destructor
	Dict(const V &defval, unsigned long hashf(KeyValue<K, V> key));
	// operator method
	V &operator[](const K &key);
	// adjust the element is exsit or not
	int InDict(const K &key);
	// delete the element if exsit
	void DeleteKey(const K &key);
private:
	V defvalue;
};

template<class K, class V>
Dict<K, V>::Dict(const V &defval, unsigned long hashf(KeyValue<K, V> key)):
		HashTable<KeyValue<K, V> >(26, hashf), defvalue(defval)
{}

template<class K, class V>
V &Dict<K, V>::operator [](const K &key)
{
	KeyValue<K, V> temp(key, defvalue);
	if(!Find(temp))
		Insert(temp);		// is not find
	int hashval=int(hf(temp)%numBuckets);			// get hash code
	Linked<KeyValue<K, V> > &lst=buckets[hashval];
	for(lst.Reset(); !lst.EndOfList(); lst.Next())
		if(lst.Data()==temp)
			return lst.Data().value;
	/*
	HashTableIterator<KeyValue<K, V> > iterator(temp);
	for(iterator.Reset(); !iterator.EndOfList(); iterator.Next())
		if(iterator.Data()==temp)
			return iterator.Data().value;
	*/		
	//return defvalue;
}

template<class K, class V>
int Dict<K, V>::InDict(const K &key)
{
	KeyValue<K, V> temp(key, defvalue);
	if(Find(temp))
		return 1;
	return 0;
}

template<class K, class V>
void Dict<K, V>::DeleteKey(const K &key)
{
	KeyValue<K, V> temp(key, defvalue);
	if(Find(temp))
		Delete(temp);
}

#endif

