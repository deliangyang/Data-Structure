
/*
 *						Array Iterator for traver array, it's convienet for get element
 *						Author: Deliang Yang
 *						Start: 2014/8/7 8:20 Thursday
 *						Stop: 
 *
 */


#ifndef __ARRAYITERATOR_H__
#define __ARRAYITERATOR_H__

#include "Iterator.h"
#include "Array.h"

template<class T>
class ArrayIterator:public Iterator<T>
{
public:
	ArrayIterator(Array<T> & A, int start=0, int finish=-1);
	// basic function about modifing;
	virtual void Reset(void);
	virtual void Next(void);
	virtual T& Data(void);
private:
	// set target for array, start, current adn finish
	int startIndex, currentIndex, finishIndex;
	// need to traver array object
	Array<T> * arr;
};

template<class T>
ArrayIterator<T>::ArrayIterator(Array<T>& A, int start, int finish):arr(&A)
{
	int ilast=A.length()-1;				// get last elements' subscript
	currentIndex=startIndex=start;
	finishIndex=finish==-1?ilast:finish;// set finish index
	if(!(startIndex>=0 && startIndex<=ilast) &&
		finishIndex>=0 && finishIndex<=ilast &&
		startIndex<finishIndex)
	{
		std::cout<<"Data: out of range"<<std::endl;
		exit(1);
	} 
}

template<class T>
void ArrayIterator<T>::Reset(void)
{
	currentIndex=startIndex;			// make current Index to Start
	iterationComplete=0;
}

template<class T>
void ArrayIterator<T>::Next(void)
{
	if(!iterationComplete)
	{
		currentIndex++;					// offset next target
		if(currentIndex>finishIndex)
			iterationComplete=1;		// finish traver
	}
	
}

template<class T>
T& ArrayIterator<T>::Data(void)
{
	if(iterationComplete)
	{
		std::cout<<"Data: out of range"<<std::endl;
		exit(1);
	}
	return (*arr)[currentIndex];			// get current data
}

#endif
