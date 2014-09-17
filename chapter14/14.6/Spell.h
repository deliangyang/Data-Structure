
#ifndef __SPELL_H__
#define __SPELL_H__

#include <fstream>

#include "HashTable.h"
#include "HashTableIterator.h"

const int len=30;

int GetWord(std::ifstream& fin, char word[])
{
	char c;
	int i=0;
	while(fin.get(c) && !isalpha(c))
		;
	if(fin.eof())
		return 0;
	word[i++]=c;
	while(fin.get(c) && (isalpha(c)||(isdigit(c))))
		word[i++]=c;
	word[i]='\0';

	return 1;
}

void initHash(HashTable<std::string> & hash, std::ifstream &fin)
{
	char word[len];
	while(GetWord(fin, word))
		hash.Insert(word);
}

int isUppercase(char ch)
{
	if(ch>'A' && ch<'Z')
		return 1;
	return 0;
}

int isLowercase(char ch)
{
	if(ch>'a' && ch<'z')
		return 1;
	return 0;
}

void PrintHash(HashTable<std::string> hash)
{
	int i=0;
	HashTableIterator<std::string> iterator(hash);
	for(iterator.Reset(); !iterator.EndOfList(); iterator.Next())
	{
		std::cout<<iterator.Data()<<"\t";
		if((i+1)%5==0)
			std::cout<<std::endl;

	}
	std::cout<<std::endl;
}



#endif

