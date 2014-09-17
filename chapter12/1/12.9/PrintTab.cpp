
#include <iostream>

#include "String.h"
#include "PrintTab.h"
#include <fstream.h>
#include "ArrayIterator.h"
#include "../Array.h"

using namespace std;

int main(int argc, char *argv[])
{
	ifstream fin;
	Array<String> arr(81);
	fin.open("ArrayIterator.h");
	if(!fin)
	{
		std::cout<<"can't open this file"<<std::endl;
		exit(1);
	}
	GetLine(fin, arr);
	
	ArrayIterator<String> iterator(arr);
	for(iterator.Reset(); !iterator.EndOfList(); iterator.Next())
	{
		int i=0;
		std::cout<<iterator.Data();
		String str(iterator.Data());
		std::cout<<str<<std::endl;
		while(str[i]!='\n')
		{
			if(str[i]=='\t')
				PrintTab();
			else
				std::cout<<str[i];
			i++;
		}
	}
	std::system("pause");
	return 0;
}
