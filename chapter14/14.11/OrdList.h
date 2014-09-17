

#ifndef __ORDEREDLIST_H__
#define __ORDEREDLIST_H__

#include "SeqList.h"

template <class T>
class OrderedList: public SeqList<T>
{
   public:
      // constructor
      OrderedList(void);
      
     	// override Insert to form an ordered list.
     	virtual void Insert(const T& item);
};

// constructor. initialize the base class
template <class T>
OrderedList<T>::OrderedList(void): SeqList<T>()
{}

// insert item into the list in ascending order
template <class T>
void OrderedList<T>::Insert(const T& item)
{
   // use the linked list traversal mechanism to locate the
   // insertion point
   	for(list.Reset();!list.EndOfList();list.Next())
       	if (item < list.Data())
        	break;
         
   // insert item at the current list location
   list.InsertAt(item);
   size++;
}


#endif
