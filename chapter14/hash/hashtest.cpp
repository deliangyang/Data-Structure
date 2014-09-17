

#include "HashTable.h"
#include "HashTableIterator.h"

#include <iostream>

unsigned long HF(int key)
{
	return key%11;
}

int main(int argc, char *argv[])
{
	HashTable<int> hash(30, HF);
	hash.Insert(77);
	hash.Insert(89);
	hash.Insert(45);
	hash.Insert(99);
	int e=89;
	int item=45;
	if(hash.Find(item) && hash.Find(e))
		std::cout<<"find 45"<<std::endl;
	else
		std::cout<<"nothing, quit"<<std::endl;

	HashTableIterator<int> iterator(hash);
	for(iterator.Reset(); !iterator.EndOfList(); iterator.Next())
		std::cout<<iterator.Data()<<" ";
	std::cout<<"delete<<"<<std::endl;
	hash.Delete(45);
	//iterator.SetList(hash);
	for(iterator.Reset(); !iterator.EndOfList(); iterator.Next())
		std::cout<<iterator.Data()<<" ";
	hash.ClearList();

	
	std::system("pause");
	return 0;
}
