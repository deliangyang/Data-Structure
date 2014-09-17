
#include <iostream>

#include "Spell.h"
#include "HashTable.h"
#include <string>
#include <fstream>

using namespace std;

unsigned long HF(string str)
{
	unsigned long total;
	if(isUppercase(str[0]))
		total=(unsigned long)(str[0]-'A');
	if(isLowercase(str[0]))
		total=(unsigned long)(str[0]-'a');
	return total%26;
}

int main(int argc, char *argv[])
{
	ifstream fin;
	fin.open("Spell.h");
	if(!fin)
	{
		std::cout<<"can't open this file"<<std::endl;
		exit(1);
	}
	HashTable<string> hash(30, HF);

	initHash(hash, fin);

	PrintHash(hash);

	std::system("pause");
	return 0;
}
