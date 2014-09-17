/*
 *
 *		Iterator is the table traver alogrithm
 *		Base function:
 *			1.	Reset()		:	Set first element
 *			2. 	Next()		:	Continue next element
 *			3. 	EndOfList() :	The last element
 *			4.	Data()		:	Current element
 *		Author:	Deliang Yang
 *		start :	2014/8/6 8:21 Wed
 *		stop  :
 *
 */

#ifndef __ITERATOR_H__
#define __ITERATOR_H__

template<class T>
class Iterator
{
protected:
	// adjust is or not reach the tail
	int iterationComplete;
public:
	Iterator(void);
	// next node
	virtual void Next(void)=0;
	// reset start node
	virtual void Reset(void)=0;
	// current item
	virtual T& Data(void)=0;
	// is last
	virtual int EndOfList(void)const;	
};

template<class T>
Iterator<T>::Iterator(void):iterationComplete(0)
{}

template<class T>
int Iterator<T>::EndOfList(void)const
{
	return iterationComplete;
}

#endif

