

#ifndef __PERSON_H__
#define __PERSON_H__

#define NAMELEN 20

#include "BinFile.h"

#include <fstream>
using namespace std;

struct Person
{
	char first[NAMELEN];
	char last[NAMELEN];
	char id[5];
};


void DelimRec(Person &p, char * buffer)
{
	int i=0;
	char * str=p.first;
	while(*str!='\0')
		buffer[i++]=*str++;
	buffer[i++]='|';
	str=p.last;
	while(*str!='\0')
		buffer[i++]=*str++;
	buffer[i++]='|';
	str=p.id;
	while(*str!='\0')
		buffer[i++]=*str++;
	buffer[i++]='|';
	buffer[i]='\0';
}

void Write(BinFile<char> &bin, char word[])
{
	bin.Write(word, strlen(word));
}

int Read(ifstream &fin, char word[])
{
	int i=0;
	char ch;
	int k=0;
	if(fin.eof())
		return 0;
	while((i+1)%4!=0 && fin>>ch)
	{
		if(ch=='|')
		{
			i++;
			word[k++]='\t';
			continue;
		}
		word[k++]=ch;
	}
	word[k]='\0';
	return 1;
}

#endif

