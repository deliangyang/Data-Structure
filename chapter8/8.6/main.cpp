
#include <iostream>
//#include "8.1/DynamicClass.h"
#include <string>
#include "ReadFile.h"
#include "../Array.h"

using namespace std;

//void LineNum(ReadFile& f);
int CopyLine(ReadFile& f, Array<string>& copyline);


int main(int argc, char *argv[])
{
	Array<string> line(200);
	int start=0;

	//char line[60];
	//int i=1;
	int i;
	//for(i=0; i<50; i++)
	//	line[i]="aaabbb";

	ReadFile readfile("main.cpp", 60);
	/*while(CopyLine(readfile, line[start]))
	{
		std::cout<<line[start]<<std::endl;
		start++;
	}*/
	int lines;
	lines=CopyLine(readfile, line);
	line.Resize(lines);

	int n;
	std::cout<<"what last lines do you want to display: ";
	std::cin>>n;
	
	n=(lines-n)>0?(lines-n):0;    		// last line

	for(int i=n; i<line.length(); i++)
	{
		std::cout.setf(std::ios::right);
		std::cout.width(3);
		std::cout<<i+1<<" ";
		std::cout<<line[i]<<std::endl;
	}
	//std::cout<<copy();
	//LineNum(readfile);
	//while(CopyLine(readfile, line));
	/*while(CopyLine(readfile, line))
	{
		std::cout.setf(std::ios::right);
		std::cout.width(3);
		std::cout<<i++<<" ";
		std::cout<<line<<std::endl;
	}*/
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


int CopyLine(ReadFile& f, Array<string>& copyline)
{
	int i=0;
	copyline[i]=f.read();
	while(!f.eof())
	{
		i++;
		copyline[i]=f.read();
	}
	return i;
	/*int i;
	for(i=0; i<10; i++)
		copyline[i]=f.read();*/
	//int i=20;
	//while(i--)
	//	std::cout<<f.read()<<std::endl;
	//char temp='a';
	//while(f.read())
	/*copyline=f.read();
	if(copyline.length()==0)
		return 0;
	return 1;*/
	/*char * str=NULL;
	str=f.read();
	if(str==NULL)
		return 0;
	
	while(*str!=NULL)
	{
		*copyline++=*str;
		str++;
	}
	*copyline=NULL;
	return 1;*/
	//if(copyline!=NULL)
	//	return 1;
	//return 0;
		//std::cout<<f.read()<<std::endl;
		//std::cout<<f.read()<<std::endl;
	//return 0;
}

