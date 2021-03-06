
#ifndef _LINKED_H
#define _LINKED_H

#include "Node.h"

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
	void InsertTail(const T& item);
	void InsertAt(const T& item);
	void InsertAfter(const T& item);

	T DeleteFront(void);
	void DeleteAt(void);

	T& Data(void);
	void ClearList(void);
private:
	Node<T> * front, * tail;
	Node<T> * ptrPrev, * ptrCurrent;
	int size;
	int position;
	Node<T> * GetNode(const T& item, Node<T> * ptrNext=NULL);
	void FreeNode(Node<T> * p);
	void CopyList(const Linked<T>& L);
};

template<class T>
Linked<T>::Linked(void):front(NULL),tail(NULL),
			ptrPrev(NULL),ptrCurrent(NULL),size(0),position(-1)
{}

template<class T>
void Linked<T>::CopyList(const Linked<T>& L)
{
	Node<T> * p=L.front;
	if(p!=NULL)
	{
		InsertTail(p->data);
		p=p->NextNode();
	}
	if(position==-1)
		return;
	ptrPrev=NULL;
	ptrCurrent=front;
	for(int pos=0; pos!=position; pos++)
	{
		ptrPrev=ptrCurrent;
		ptrCurrent=ptrCurrent->NextNode();
	}
}

template<class T>
void Linked<T>::ClearList(void)
{
	Node<T> * currentPosition, * nextPosition;
	currentPosition=front;
	while(currentPosition!=NULL)
	{
		nextPosition=currentPosition->NextNode();
		FreeNode(currentPosition);
		currentPosition=nextPosition;
	}
	front=tail=NULL;
	ptrCurrent=ptrPrev=NULL;
	size=0;
	position=-1;
}

template<class T>
void Linked<T>::Reset(int pos)
{
	int startpos;
	if(front==NULL)
		return;
	if(pos<0 || pos>size-1)
	{
		std::cout<<"Reset: Invalid list position"<<std::endl;
		return;
	}
	if(pos==0)				// the position of pos in the first
	{
		ptrCurrent=front;
		ptrPrev=NULL;
		position=0;
	}
	else					// the second position
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
void Linked<T>::Next(void)
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
	return ptrCurrent==NULL;
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
		p=ptrPrev->NextNode();
	if(p==tail)
	{
		tail=ptrPrev;
		position--;
	}
	ptrCurrent=p->NextNode();
	FreeNode(p);
	size--;
}

template<class T>
void Linked<T>::FreeNode(Node<T> * p)
{
	delete p;
	p=NULL;
}

template<class T>
Linked<T>::~Linked(void)
{
	ClearList();
	ptrCurrent=NULL;
	ptrPrev=NULL;
	tail=NULL;
	front=NULL;
}

#endif
