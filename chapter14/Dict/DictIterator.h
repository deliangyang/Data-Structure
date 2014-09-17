

#ifndef __DICTITERATOR_H__
#define __DICTITERATOR_H__

#include "InorderIterator.h"
#include "Dictionary.h"

template<class K, class V>
class DictIterator:public InorderIterator<KeyValue<K, V>>
{
public:
	DictIterator(Dict<K, V> &dict);
	void SetList(Dict<K, V> &dict);	
};

#endif

