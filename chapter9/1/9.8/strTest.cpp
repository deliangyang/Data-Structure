
#include <iostream>

#include "String.h"

#include "../Linked.h"

using namespace std;

template<class T>
void PrintLink(Linked<T> &link)
{
	for(link.Reset(); !link.EndOfList(); link.Next())
		std::cout<<link.Data()<<std::endl;
}

int main(int argc, char *argv[])
{
	String read="run -t -includelist linkdemo";
	Linked<String> tokenlist;
	Linked<String> optionlist;
	
	char s[]="hello world";
	String test=s;
	std::cout<<test;

	char str[50];
	int i=0;
	std::cout<<read.length()<<std::endl;
	while(read[i]!='\0')
	{
		int j=0;
		if(read[i]!='-')
		{
			while(read[i]!=' ' && read[i]!='\0')
				str[j++]=read[i++];
			str[j]='\0';
			String temp=str;
			tokenlist.InsertAfter(temp);
		}
		else
		{
			while(read[i]!=' ' && read[i]!='\0')
				str[j++]=read[i++];
			str[j]='\0';
			String temp=str;
			//std::cout<<str<<endl;
			optionlist.InsertAfter(temp);
			//PrintLink(optionlist);
		}
		std::cout<<"|"<<str<<"|"<<endl;
		if(read[i]!='\0')
			i++;
	}
	PrintLink(tokenlist);
	//PrintLink(optionlist);
	/*Linked<String> l;
	String stre="hell world";
	l.InsertAfter(stre);
	PrintLink(l);*/

	std::system("pause");
	return 0;
}
