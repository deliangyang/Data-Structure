
/*
 *		Hast Table ADT
 *		Author: Deliang Yang
 *		Start: 2014/8/9 09:20 Saturday
 *		Stop:  2014/8/9 11:52 Saturday
 *
 *
 *		Array<Linked<T>> 	Linked<T>
 *		hash[0]				[data|next]->[data|next]->[data|NULL]
 *		hash[1]				NULL
 *		hash[2] 			[data|next]->[data|NULL]
 *		hash[3] 			[data|next]->[data|next]->[data|NULL]
 *		hash[4] 			[data|next]->[data|NULL]
 *		hash[5] 			[data|next]->[data|next]->[data|NULL]
 *
 *
 */


#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

#include "List.h"						// adt list
#include "Linked.h"    					// adt linked
#include "Array.h"						// adt array
#include "Iterator.h"					// abstract base class iterator

template<class T>
class HashTableIterator;

template<class T>
class HashTable:public List<T>
{
public:
	// constructor, hash table's size and hash function
	HashTable(int nbuckets, unsigned long hashf(T key));
	// destructor
	~HashTable(void);
	// table operator function
	virtual void Insert(const T& key);
	virtual int Find(T& key);
	virtual void Delete(const T& key);
	virtual void ClearList(void);
	void Update(const T& key);
	// iterator friend link
	friend class HashTableIterator<T>;
protected:
	// buckets' number, means hash table size
	int numBuckets;
	// hash table's linked array
	Array<Linked<T> > buckets;		// 是否应该考虑将Array用Linked 实现
	// hash function
	unsigned long (*hf)(T key);
	// current pointer
	T * current;
};

template<class T>
HashTable<T>::HashTable(int nbuckets, unsigned long hashf(T key))
{
	//buckets=new Array<Linked<T>>(nbuckets);
	numBuckets=nbuckets;			// didn't init this element, make me test n times
	hf=hashf;
}


template<class T>
void HashTable<T>::Insert(const T &key)
{
	int hashval=int(hf(key)%numBuckets);		// get hash value
	// avoid subscript find value;
	Linked<T> &lst=buckets[hashval];			// get hash value subscript
	// then traver the subscript linked, if find this value do nothing
	for(lst.Reset(); !lst.EndOfList(); lst.Next())	
	{
		if(lst.Data()==key)
		{
			lst.Data()=key;
			current=&lst.Data();
			return;
		}
	}
	// else add data after linked
	lst.InsertAfter(key);
	current=&lst.Data();
	size++;
}

template<class T>
int HashTable<T>::Find(T &key)
{
	// the same way with insert
	int hashval=int(hf(key)%numBuckets);
	Linked<T> &lst=buckets[hashval];
	// traver linked
	for(lst.Reset(); !lst.EndOfList(); lst.Next())
	{
		if(lst.Data()==key)
		{
			key=lst.Data();
			current=&lst.Data();
			return 1;
		}
	}
	return 0;
}

template<class T>
void HashTable<T>::Delete(const T& key)
{
	// the same way with insert
	int hashval=int(hf(key)%numBuckets);
	Linked<T> &lst=buckets[hashval];
	// traver linked
	for(lst.Reset(); !lst.EndOfList(); lst.Next())
	{
		if(lst.Data()==key)
			lst.DeleteAt();
	}
}

template<class T>
void HashTable<T>::ClearList(void)
{
	int i;
	for(i=0; i<numBuckets; i++)
		buckets[i].ClearList();
}

template<class T>
HashTable<T>::~HashTable(void)
{
	ClearList();
}

#endif

