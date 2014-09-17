

#ifndef _SEQLIST_H
#define _SEQLIST_H

#include "Person.h"

typedef Person DataType;

const int DefineSize = 30;

class SeqList
{
public:
	SeqList(void);
	SeqList(int size);
	void Insert(DataType item);
	DataType Delete(void);
	void Delete(DataType item);
	DataType DeleteFront(void);
	DataType GetLastItem(void)const;
	int Find(DataType& item)const;
	DataType GetData(int position)const;
	int isEmpty(void)const;
	int isFull(void)const;
	int Length(void)const;
	~SeqList(void);
	void ClearList(void);
private:
	DataType * list;
	int size;
	int count;					// count the members of item
};

SeqList::SeqList(void)
{
	size=DefineSize;
	count=-1;
	list=new DataType[DefineSize];
}

SeqList::SeqList(int size)
{
	this->size=size;
	count=-1;
	list=new DataType[size];
}

SeqList::~SeqList(void)
{
	delete[] list;
}

void SeqList::Insert(DataType item)
{
	count++;
	list[count]=item;
}

DataType SeqList::Delete(void)
{
	DataType temp;
	temp=list[count];
	count--;
	return temp;
}

DataType SeqList::GetLastItem(void)const
{
	if(!isFull())
		return list[count];
	exit(0);
}

int SeqList::isFull(void)const
{
	return count==size-1;
}

int SeqList::isEmpty(void)const
{
	return count==-1;
}

int SeqList::Find(DataType& item)const
{
	int i;
	for(i=0; i<=count; i++)
		if(list[i]==item)
			return i;
	return -1;
}

DataType SeqList::GetData(int position)const
{
	if(position>=0 && position<=count)
		return list[position];
}

DataType SeqList::DeleteFront(void)
{
	if(isEmpty())
	{
		std::cout<<"empty list"<<std::endl;
		exit(0);
	}
	int i;
	DataType temp=list[0];
	for(i=0; i<count; i++)
		list[i]=list[i+1];
	count--;
	return temp;
}

void SeqList::Delete(DataType item)
{
	int i;
	int j;
	for(i=0; i<count; i++)
		if(list[i]==item)
			break;
	for(j=i; j<count; j++)
		list[j]=list[j+1];
}

int SeqList::Length(void)const
{
	return count+1;
}

#endif
