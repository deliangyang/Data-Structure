
#ifndef __CLIST_H__
#define __CLIST_H__

#include "../CNode.h"

// define one CNode header with rear pointer
template<class T>
struct CList
{													//	[header|rear]
	CNode<T> header;
	CNode<T> * rear;
};

template<class T>
void InsertFront(CList<T> &L， CNode<T> *p)
{
	p->InsertAfter(&L.header);
	L.header=p;
}

template<class T>
void InsertRear(CList<T> &L, CNode<T> *p)
{
	if(L.header==NULL)
		return;
	CNode<T> * ptrTemp=L.header;
	while(ptrTemp->NextNode!=NULL)
		ptrTemp=ptrTemp->NextNode();
	ptrTemp.InsertAfter(P);
}

template<class T>
CNode<T> *DeleteFront(CList<T> &L)
{
	if(L.header==NULL)
		return NULL;
	CNode<T> * ptrTemp =&L.header;
	ptrTemp=L.header->NextNode();
	L.header=ptrTemp;
}

template<class T>
void Clear(CList<T> &L)
{
	CNode<T> * ptrTemp=&L.header;
	while(ptrTemp!=L.rear)
	{
		delete 
		ptrTemp=ptrTemp->NextNode();
	}
}

#endif