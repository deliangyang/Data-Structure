
#include <iostream>
//#include "8.1/DynamicClass.h"

#include "ReadFile.h"

using namespace std;

//void LineNum(ReadFile& f);
int CopyLine(ReadFile& f, char * copyline);


int main(int argc, char *argv[])
{
	char line[60];
	int i=1;
	ReadFile readfile("main.cpp", 60);
	//std::cout<<copy();
	//LineNum(readfile);
	//while(CopyLine(readfile, line));
	while(CopyLine(readfile, line))
	{
		std::cout.setf(std::ios::right);
		std::cout.width(3);
		std::cout<<i++<<" ";
		std::cout<<line<<std::endl;
	}
	/*while(CopyLine(readfile, line))
	{
		std::cout.setf(std::ios::right);
		std::cout.width(3);
		std::cout<<i++<<" ";
		std::cout<<line<<std::endl;
	}*/
	std::system("pause");
	return 0;
}

/*void LineNum(ReadFile& f)
{
	//f.read();
	int i=1;
	while(f.read())
	{
		std::cout.setf(std::ios::right);
		std::cout.width(3);
		std::cout<<i++<<" ";
		f.Printbuffer();
	}
}*/


int CopyLine(ReadFile& f, char * copyline)
{
	//int i=20;
	//while(i--)
	//	std::cout<<f.read()<<std::endl;
	//char temp='a';
	//while(f.read())
	char * str=NULL;
	str=f.read();
	if(str==NULL)
		return 0;
	
	while(*str!=NULL)
	{
		*copyline++=*str;
		str++;
	}
	*copyline=NULL;
	return 1;
	//if(copyline!=NULL)
	//	return 1;
	//return 0;
		//std::cout<<f.read()<<std::endl;
		//std::cout<<f.read()<<std::endl;
	//return 0;
}

