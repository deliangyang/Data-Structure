

#ifndef _SET_H
#define _SET_H

#include <fstream>

#define TRUE 1
#define FALSE 0

const int DefSetSize=500;

class Set
{
public:
	Set(void);
	Set(int size);
	Set(int arr[], int n);
	void Insert(int item);
	void Delete(int n);				// delete item n
	Set operator+(Set set)const;
	Set operator*(Set set)const;
	friend int operator^(int elt, Set x);
	friend std::ostream& operator<<(std::ostream& os, const Set& set);
	~Set(void);
private:
	int * member;
	int size;
};

#endif
