/* 
 *			CopyRight(2014)
 *			Author: Deliang Yang
 *			Introduction:
 *			This is linked table, ADT and some function create
 *			
 *			start: 2014/8/5 8:42 Tuesday
 *			stop:  2014/8/6 10:13 Wednesday
 *
 *
 *			Bug: DeleteAt(), if you want to delete current node element, it'll 
 *				break out, if you want to use this function, you need to Reset() 
 *				position to delete element, else use another funcion.
 *
 *				others function is normal run.
 *
 */


#ifndef _LINKED_H
#define _LINKED_H

#include "Node.h"
#include <iostream>

template<class T>
class SeqList;

template<class T>
class SeqListIterator;

template<class T>
class Linked
{
public:
	Linked(void);
	Linked(const Linked<T>& L);
	~Linked(void);
	Linked<T>& operator=(const Linked<T>& L);
	int ListSize(void)const;
	int ListEmpty(void)const;

	// traver
	void Reset(int pos=0);
	void Next(void);
	int EndOfList(void)const;

	void InsertFront(const T& item);
	void InsertAt(const T& item);
	void InsertAfter(const T& item);

	T DeleteFront(void);
	void DeleteAt(void);
	void DeleteTail(void);
	T Delete(void);
	void DeleteItem(T item);

	T& Data(void);
	void ClearList(void);

	friend class SeqList<T>;
	friend class SeqListIterator<T>;
private:
	Node<T> * front, * tail;
	Node<T> * ptrPrev, * ptrCurrent;
	int size;
	int position;
	Node<T> * GetNode(const T& item, Node<T> * ptrNext=NULL);
	void FreeNode(Node<T> * &p);
	void CopyList(const Linked<T>& L);
};

template<class T>
Linked<T>::Linked(void):front(NULL),tail(NULL),
			ptrPrev(NULL),ptrCurrent(NULL),size(0),position(-1)
{}

template<class T>
Linked<T>::Linked(const Linked<T>& L):front(NULL),tail(NULL),
			ptrPrev(NULL),ptrCurrent(NULL),size(0),position(-1)
{
	CopyList(L);
}

template<class T>
void Linked<T>::CopyList(const Linked<T>& L)
{
	Node<T> * p=L.front;
	while(p!=NULL)
	{
		InsertAfter(p->data);			// insert first element
		p=p->NextNode();				// let p equal to p next node address
	}
	if(position==-1)					// list is is empty
		return;
	ptrPrev=NULL;
	ptrCurrent=front;
	for(int pos=0; pos!=position; pos++)
	{
		ptrPrev=ptrCurrent;
		ptrCurrent=ptrCurrent->NextNode();
	}
	tail=ptrCurrent;
}

template <class T>
Linked<T>& Linked<T>::operator=(const Linked<T>& L)
{
   if (this == &L)      // Can't assign list to itself
      return *this;

   ClearList();
   CopyList(L);
   return *this;
}

template<class T>
void Linked<T>::Reset(int pos)			// reset to current node
{
	int startpos;
	if(front==NULL)						// if null link, return
		return;
	if(pos<0 || pos>size-1)				// out of range, return
	{
		std::cout<<"Reset: Invalid list position"<<std::endl;
		return;
	}
	if(pos==0)							// the position of pos in the first
	{
		ptrCurrent=front;
		ptrPrev=NULL;
		position=0;
	}
	else								// the second position
	{
		ptrCurrent=front->NextNode();
		ptrPrev=front;
		startpos=1;
		// util startpos is equal to pos
		for(position=startpos; position!=pos; position++)
		{
			ptrPrev=ptrCurrent;
			ptrCurrent=ptrCurrent->NextNode();
		}
	}
}

template<class T>
void Linked<T>::Next(void)					// get next element
{
	if(ptrCurrent!=NULL)
	{
		ptrPrev=ptrCurrent;
		ptrCurrent=ptrCurrent->NextNode();
		position++;
	}
}

template<class T>
int Linked<T>::EndOfList(void)const
{
	if(front==NULL || ptrCurrent==NULL)
		return 1;
	return 0;
}

template<class T>
T& Linked<T>::Data(void)
{
	if(ptrCurrent==NULL && size==0)
	{
		std::cerr<<"Data: invalid refrence!"<<std::endl;
		exit(1);
	}
	return ptrCurrent->data;
}

template<class T>
Node<T> * Linked<T>::GetNode(const T& item, Node<T> * ptrNext)
{
	Node<T> * ptrNew;
	ptrNew=new Node<T>(item, ptrNext);
	if(ptrNew==NULL)
	{
		std::cerr<<"No Memory Allocate"<<std::endl;
		exit(1);
	}
	return ptrNew;
}

template<class T>
void Linked<T>::InsertFront(const T& item)
{
	front=GetNode(item, front);
	position=0;
	size++;
	ptrCurrent=front;
	//Node<T> * ptrNew;
	//ptrNew=GetNode(ptrNew, item);
	//InsertFront(ptrNew);
}

template<class T>
void Linked<T>::InsertAfter(const T& item)
{
	Node<T> * p=front;
	Node<T> * ptrNew;
	if(p==NULL)
		InsertFront(item);
	else
	{
		while(p->NextNode()!=NULL)
			p=p->NextNode();
		ptrNew=GetNode(item);
		p->InsertAfter(ptrNew);
		ptrCurrent=ptrNew;
		tail=ptrNew;
	}
	size++;
	position++;
}

template<class T>
void Linked<T>::InsertAt(const T& item)
{
	Node<T> * ptrNew;
	// insert front
	if(ptrPrev==NULL)
	{
		ptrNew=GetNode(item, front);
		front=ptrNew;
	}
	else		// insert list mid
	{
		ptrNew=GetNode(item);
		ptrPrev->InsertAfter(ptrNew);
	}
	if(ptrPrev==tail)
	{
		tail=ptrNew;
		position=size;
	}
	ptrCurrent=ptrNew;
	size++;
}

template<class T>
T Linked<T>::DeleteFront(void)
{
	Node<T> * p=front;
	if(p==NULL)
	{
		std::cerr<<"Data:Invalid delete"<<std::endl;
		exit(1);
	}
	T temp=p->data;
	front=front->NextNode();

	delete p;
	p=NULL;
	size--;
	//std::cout<<temp<<std::cout;
	position=0;
	return temp;
}

template<class T>
void Linked<T>::DeleteAt(void)				// delete current node element
{
	Node<T> * p;
	if(ptrCurrent=NULL)
	{
		std::cerr<<"Invalid deletion"<<std::endl;
		exit(1);
	}
	// the front or mid
	if(ptrPrev==NULL)
	{
		p=front;
		front=front->NextNode();
	}
	else
		p=ptrPrev->DeleteAfter();
	if(p==tail)
	{
		tail=ptrPrev;
		position--;
	}
	ptrCurrent=p->NextNode();				// pointer delete elements' next element address
	FreeNode(p);
	size--;
}

template<class T>
void Linked<T>::DeleteTail(void)
{
	Node<T> * ptrTemp=front;
	Node<T> * prev;
	Node<T> * ptrDel;
	if(ptrTemp==NULL)
		return;
	if(ptrTemp->NextNode()==NULL)
	{
		delete front;
		front=NULL;
		tail=NULL;
		position=0;
	}
	else
	{
		while(ptrTemp->NextNode()!=NULL)
		{
			prev=ptrTemp;
			ptrTemp=ptrTemp->NextNode();
		}
		ptrDel=prev->DeleteAfter();
		tail=prev;
		FreeNode(ptrDel);
	}
	size--;
}

template<class T>
T Linked<T>::Delete(void)
{
	Node<T> * ptrTemp=front;
	Node<T> * prev;
	Node<T> * ptrDel;
	T temp;
	if(ptrTemp==NULL)
	{
		std::cerr<<"link emptry"<<std::endl;
		exit(1);
	}
	if(ptrTemp->NextNode()==NULL)
	{
		temp=ptrTemp->data;
		delete front;
		front=NULL;
		tail=NULL;
		position=0;
	}
	else
	{
		while(ptrTemp->NextNode()!=NULL)
		{
			prev=ptrTemp;
			ptrTemp=ptrTemp->NextNode();
		}
		temp=ptrTemp->data;
		ptrDel=prev->DeleteAfter();
		tail=prev;
		FreeNode(ptrDel);
	}
	size--;
	return temp;
}

template<class T>
void Linked<T>::DeleteItem(T item)
{
	for(Reset(); !EndOfList(); Next())
		if(Data()==item)
		{
			DeleteAt();
			break;
		}
	Reset();
}

template<class T>
Linked<T>::~Linked(void)
{
	ClearList();
}

template<class T>
void Linked<T>::ClearList(void)
{
	Node<T> * currentPos=front;
	while(front!=NULL)
	{
		currentPos=front->NextNode();
		delete front;
		front=NULL;
		front=currentPos;
	}
	front=tail=NULL;
	ptrCurrent=ptrPrev=NULL;
	size=0;
	position=-1;
}

template<class T>
void Linked<T>::FreeNode(Node<T> * &p)
{
	delete p;
	p=NULL;
}

template<class T>
int Linked<T>::ListSize(void)const
{
	return size-1;
}

template<class T>
int Linked<T>::ListEmpty(void)const
{
	return size==0;
}

#endif
