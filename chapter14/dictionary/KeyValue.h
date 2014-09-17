
/*
 *   	ADT of Dictionaries, throught the key to find value definition
 *		and the key is const value, we con't change the key
 *
 *		look like:
 *		
 *		storage struct like this:
 *		<Key, Value> 	
 *		
 *			
 *		
 *
 *
 */


#ifndef __KEYVALUE_H__
#define __KEYVALUE_H__

template<class K, class V>
class KeyValue
{
protected:
	const K key;
public:
	// public visit value
	V value;
	// constructor
	KeyValue(K keyValue, V dataValue);
	// assignment operator, and const key
	KeyValue<K, V> &operator=(const KeyValue<K, V> &rhs);
	// compare operator, based on two different key
	int operator==(const KeyValue<K, V> &val)const;
	int operator==(const K &keyValue)const;
	int operator<(const KeyValue<K, V> &val)const;
	int operator<(const K &keyValue)const;
	// out class to get value
	K Key(void)const;
};

template<class K, class V>
KeyValue<K, V>::KeyValue(K keyValue, V dataValue):key(keyValue)
{
	value=dataValue;
}

template<class K, class V>
KeyValue<K, V>& KeyValue<K, V>::operator=(const KeyValue<K, V> &rhs)
{
	value=rhs.value;
	return *this;
}

template<class K, class V>
int KeyValue<K, V>::operator==(const KeyValue<K, V> &val)const
{
	return key==val.Key();
}

template<class K, class V>
int KeyValue<K, V>::operator==(const K &keyVal)const
{
	return key==keyValue;
}

template<class K, class V>
int KeyValue<K, V>::operator<(const KeyValue<K, V> &val)const
{
	return key<val.Key();
}

template<class K, class V>
int KeyValue<K, V>::operator<(const K &keyValue)const
{
	return key<keyValue;
}

template<class K, class V>
K KeyValue<K, V>::Key(void)const
{
	return key;
}

#endif


