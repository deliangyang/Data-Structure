

#ifndef __DICT_H__
#define __DICT_H__

#include "Hash.h"

template<class K, class V>
class Dict:public Hash<KeyValue<K, V> >
{
public:
	Dict();
	~Dict();
private:

};

#endif

