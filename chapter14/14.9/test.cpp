
#include <iostream>
#include "Person.h"

#include "BinFile.h"

using namespace std;

int main(int argc, char *argv[])
{
	char buffer[30];
	//char first[NAMELEN], last[NAMELEN], id[5];
	int i;
	Person p;

	BinFile<char> bin("recl.out", OUT);
	for(i=0; i<5; i++)
	{
		std::cout<<"first name: ";
		std::cin>>p.first;
		std::cout<<"last name: ";
		std::cin>>p.last;
		std::cout<<"id: ";
		std::cin>>p.id;
		
		DelimRec(p, buffer);
		Write(bin, buffer);
	}	
	
	bin.Close();
	
	std::system("pause");
	return 0;
}

