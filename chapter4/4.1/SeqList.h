
#ifndef _SEQLIST_H
#define _SEQLIST_H

typedef int DataType;

const int DefineSize = 30;

class SeqList
{
public:
	SeqList(void);
	SeqList(int size);
	void Insert(DataType item);
	DataType Delete(void);
	DataType GetLastItem(void)const;
	int isEmpty(void)const;
	int isFull(void)const;
	~SeqList(void);
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
	return count<0;
}

#endif
