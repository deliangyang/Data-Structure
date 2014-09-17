

#ifndef __DICT_H__
#define __DICT_H__

#include "KeyValue.h"
#include "OrdList.h"

template<class K, class V>
class Dict: public OrderedList<KeyValue<K, V> >
{
public:
	Dict(const V &defval);
	V &operator[](const K &key);
	int InDict(const K &key);
	void DeleteKey(const K &key);
private:
	V defvalue;
};

template<class K, class V>
Dict<K, V>::Dict(const V &defval):defvalue(defval), OrderedList<KeyValue<K, V> >()
{}

template<class K, class V>
V &Dict<K, V>::operator[](const K &key)
{
	KeyValue<K, V> temp(key, defvalue);
	if(!Find(temp))
		Insert(temp);
	for(list.Reset(); !list.EndOfList(); list.Next())
		if(list.Data()==temp)
			return list.Data().value;
}

template<class K, class V>
int Dict<K, V>::InDict(const K &key)
{
	KeyValue<K, V> temp(key, defvalue);
	if(Find(temp))
		return 1;
	return 0;	// if not exsit 
}

template<class K, class V>
void Dict<K, V>::DeleteKey(const K &key)
{
	KeyValue<K, V> temp(key, defvalue);
	if(Find(temp))
		Delete(temp);
}




#endif

