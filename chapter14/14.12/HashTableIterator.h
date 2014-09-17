

#ifndef __HASHTABLEITERATOR_H__
#define __HASHTABLEITERATOR_H__

#include "Iterator.h"
#include "HashTable.h"
#include "Linked.h"

template<class T>
class HashTableIterator:public Iterator<T>
{
public:
	// constructor
	HashTableIterator(HashTable<T> &hf);
	// base iterator funciton
	virtual void Next(void);
	virtual void Reset(void);
	virtual T &Data(void);
	// traver another hash table
	void SetList(HashTable<T> &lst);
private:
	// traver pointer
	HashTable<T> * hashTable;
	// tarvered pointer and subscript
	int currentBucket;
	Linked<T> * currentBucketPtr;
	// next node
	void SreachNextNode(int cb);
};

template<class T>
HashTableIterator<T>::HashTableIterator(HashTable<T> &hf)
{
	hashTable=&hf;
	SreachNextNode(0);
}

template<class T>
void HashTableIterator<T>::SetList(HashTable<T> &lst)
{
	iterationComplete=0;
	hashTable=&lst;
	SreachNextNode(0);
}

template<class T>
void HashTableIterator<T>::Next(void)
{
	currentBucketPtr->Next();
	if(currentBucketPtr->EndOfList())
		SreachNextNode(++currentBucket);
	// flag currentBucket is last or not, if last iterationComplete is -1
	// else if is true
	iterationComplete=currentBucket==-1;
}

template<class T>
void HashTableIterator<T>::Reset(void)
{
	iterationComplete=0;
	SreachNextNode(0);
}

template<class T>
T& HashTableIterator<T>::Data(void)
{
	return currentBucketPtr->Data();
}

template<class T>
void HashTableIterator<T>::SreachNextNode(int cb)
{
	currentBucket=-1;
	int i;
	if(cb>hashTable->numBuckets)
		return;
	// how much hash bucket, how times loop
	for(i=cb; i<hashTable->numBuckets; i++)
	{
		if(!hashTable->buckets[i].ListEmpty())		// is current buckets is not empty
		{
			currentBucketPtr=&hashTable->buckets[i];
			currentBucketPtr->Reset();
			currentBucket=i;
			return;
		}

	}
}




#endif
