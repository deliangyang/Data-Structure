

#ifndef __READSTRING_H__
#define __READSTRING_H__

#include <fstream.h>
#include "../String.h"

void ReadString(std::ifstream &f, String * &str, int n)
{
	str=new String[n];
	int i=0;
	while(i<n)
	{
		f.getline(str[i], 60, '\n');
		i++;
	}
}

void Replace(String &src, int pos, String rep)
{
	src.Insert(rep, pos);
}


void ChangeString(String *& str, int n, String & change, String & change2)
{
	int i, j=0;
	for(i=0; i<n; i++)
	{
		int index=0;
		String &temp(str[i]);
		while(temp[j]!='\0')
		{
			if(temp[j]=='#')
				Replace(temp, index, change);
			if(temp[j]=='&')
				Replace(temp, index, change2);
			index++;
			j++;
		}
	}
}

/*
void GetWord(String &str, char word[])
{
	int i=0;
	while(str[i]!='\0')
	{


		if(str[i]==' ' || str[i]=='\0')
			
		i++;
	}
}*/

void PrintString(String * str, int n)
{
	int i;
	for(i=0; i<n; i++)
		std::cout<<str[i]<<std::endl;
}

void DeleteString(String * &str)
{
	delete[] str;
}

#endif
