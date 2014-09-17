
#include "Set.h"
#include <iostream>

Set::Set(void)
{
	size=DefSetSize;
	member=new int[size];
	memset(member, 0, sizeof(int)*size);
}

Set::Set(int size)
{
	this->size=size;
	member=new int[size];
	memset(member, 0, sizeof(int)*size);
}

Set::Set(int arr[], int n)
{
	size=DefSetSize;
	member=new int[size];
	memset(member, 0, sizeof(int)*size);
	int i;
	for(i=0; i<n; i++)
		member[arr[i]]=TRUE;
}

Set::~Set(void)
{
	delete[] member;
}

// [0, size-1];
void Set::Insert(int item)
{
	if(item<0 || item>=size)
	{
		std::cout<<"out of range"<<std::endl;
		exit(0);
	}
	member[item]=1;
}

void Set::Delete(int n)
{
	if(n<0 || n>=size)
	{
		std::cout<<"out of range"<<std::endl;
		exit(0);
	}
	member[n]=0;
}

std::ostream& operator<<(std::ostream& os, const Set& set)
{
	int i;
	
	os<<"{";
	int curr=0;
	for(i=0; i<set.size; i++)
	{
		if(set.member[i]==TRUE && curr==0)
		{
			curr=1;
			os<<i;
			continue;
		}
		if(set.member[i]==TRUE && curr==1)
		{
			os<<", ";
			os<<i;
		}			
	}
	os<<"}"<<std::endl;
	return os;
}

Set Set::operator+(Set set)const
{
	Set s;
	for(int i=0; i<size; i++)
		if(member[i]==TRUE)
			s.Insert(i);
	for(int i=0; i<set.size; i++)
		if(set.member[i]==TRUE)
			s.Insert(i);
	return s;
}

Set Set::operator*(Set set)const
{
	Set s;
	for(int i=0; i<DefSetSize; i++)
		if(member[i]==set.member[i] && member[i]==TRUE)
			s.Insert(i);
	return s;
}

int operator^(int elt, Set x)
{
	if(x.member[elt]==TRUE)
		return 1;
	return 0;
}
