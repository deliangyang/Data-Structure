#ifndef __TEST_H__
#define __TEST_H__

#include "Dict.h"
#include <string>
#include <fstream>

using namespace std;

void MakeDict(ifstream &fin, Dict<string, string> &dict)
{
	string str;
	char def[256];
	while(fin>>str)
	{
		fin.getline(def, 256, '\n');
		dict[str]+=def;
	}

}
void PrintEntry(KeyValue<string, string> kv)
{
	std::cout<<kv.Key()<<": "<<kv.value<<std::endl;
}

void PrintDict(Dict<string, string> &dict)
{
	SeqListIterator<KeyValue<string, string> > iterator(dict);
	for(iterator.Reset(); !iterator.EndOfList(); iterator.Next())
		PrintEntry(iterator.Data());
}


#endif