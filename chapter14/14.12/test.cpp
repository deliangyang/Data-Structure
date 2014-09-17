
#include <iostream>

#include "Dict.h"
#include <string>
#include <fstream>
#include "test.h"
using namespace std;

unsigned long HF(KeyValue<string, string> key)
{
	string str=key.Key();
	return (unsigned long)str[0]%26;
}

int main(int argc, char *argv[])
{
	Dict<string, string> dict("", HF);
	//dict["word"]+="hello world";
	ifstream fin;
	fin.open("dict.txt");
	if(!fin)
	{
		std::cout<<"open file filure"<<std::endl;
		exit(1);
	}
	MakeDict(fin, dict);
	PrintDict(dict);

	std::system("pause");
	return 0;
}
