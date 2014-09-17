
#include <iostream>

#include "Dict.h"
#include "SeqListIterator.h"
#include "test.h"
#include <fstream>
#include <string>
using namespace std;

using namespace std;

int main(int argc, char *argv[])
{
	Dict<string, string> dict("");
	dict["nihao"]+="hello";
	dict["a"]+="this is";
	dict["world"]+="Hello world";

	ifstream fin("dict.txt");
	if(!fin)
	{
		std::cout<<"can't open this file"<<std::endl;
		exit(1);
	}
	MakeDict(fin, dict);		// read data from file("dict.txt")
	PrintDict(dict);
	
	//Linked<KeyValue<string, string> > lst=dict.list;
	
	
	std::system("pause");
	return 0;
}
