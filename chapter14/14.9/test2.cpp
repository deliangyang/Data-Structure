
#include <iostream>

#include "Person.h"
using namespace std;

int main(int argc, char *argv[])
{

	char word[40];
	ifstream fin;
	fin.open("recl.out");
	if(!fin)
	{
		std::cout<<"can't open this file"<<std::endl;
		exit(1);
	}	
	while(Read(fin, word))
	{
		std::cout<<word<<std::endl;
	}
	std::system("pause");
	return 0;
}
