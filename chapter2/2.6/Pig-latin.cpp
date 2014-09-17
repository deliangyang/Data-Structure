
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>

enum Vowel{a, e, i, o, u};
const char vowel[]={'a', 'e', 'i', 'o', 'u'};

using namespace std;
// from file get one word
int GetWord(ifstream & fin, char word[]);
// adjust first word is or not vowel
int isVowelStart(char word[]);
// delete first word
void DeleteFirstWord(char word[]);

#define LEN 32;

int main(int argc, char *argv[])
{
	char word[32];
	char c;
	char suffix[4];		// use ot word suffix
	ifstream fin;
	fin.open("test.txt", ios::in);
	if(!fin)
	{
		std::cout<<"con't open this file!"<<std::endl;
		exit(1);
	}
	while(GetWord(fin, word))
	{
		cout<<word<<": ";
		if(isVowelStart(word))
			sprintf(suffix, "%s", "ay\0");
		else
		{
			c=word[0];
			DeleteFirstWord(word);
			sprintf(suffix, "%c%s", c, "ay\0");
		}
		strcat(word, suffix);
		std::cout<<word<<std::endl;
	}
	fin.close();

	std::system("pause");
	return 0;
}

int GetWord(ifstream& fin, char word[])
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

int isVowelStart(char word[])
{
	switch(word[0])
	{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			return 1;
		default:
			return 0;
	}
}

void DeleteFirstWord(char word[])
{
	int len=strlen(word)-1;
	int i=0;
	while(i<len)
	{
		word[i]=word[i+1];
		i++;
	}
	word[i]='\0';
}
