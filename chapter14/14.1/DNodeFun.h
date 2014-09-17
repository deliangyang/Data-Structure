

#ifndef __DNODEFUN_H__
#define __DNODEFUN_H__

#include "DNode.h"

template<class T>
void InsertLow(DNode<T> * header, DNode<T> * &current, T item)
{
	DNode<T> * newNode=new DNode<T>(item);
	DNode<T> * p;

	p=current;
	while(p!=header && item<p->data)
		p=p->Left();
	p->InsertRight(newNode);
	current=newNode;
}

template<class T>
void InsertHeight(DNode<T> * header, DNode<T> * &current, T item)
{
	DNode<T> * newNode=new DNode<T>(item);
	DNode<T> * p;

	p=current;
	while(p!=header && item>p->data)
		p=p->Right();
	p->InsertLeft(newNode);
	current=newNode;
}


template<class T>
void DoubleSort(T a[], int n)
{
	DNode<T> header;
	DNode<T> * current;
	int i;
	DNode<T> * newNode=new DNode<T>(a[0]);
	header.InsertRight(newNode);
	current=newNode;

	for(i=1; i<n; i++)
		if(a[i]<current->data)
			InsertLow(&header, current, a[i]);
		else
			InsertHeight(&header, current, a[i]);
	current=header.Right();
	i=0;
	while(current!=&header)
	{
		a[i++]=current->data;
		current=current->Right();
	}
	while(header.Right()!=&header)
	{
		current=(header.Right())->DeleteNode();
		delete current;
	}
}

template<class T>
void PrintArray(T arr[], int n)
{
	int i;
	for(i=0; i<n; i++)
		std::cout<<arr[i]<<" ";
	std::cout<<std::endl;
}

#endif
