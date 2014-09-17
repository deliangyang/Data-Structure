
#include <iostream>
//#include "8.1/DynamicClass.h"

#include "ReadFile.h"

using namespace std;

void LineNum(ReadFile& f);

int main(int argc, char *argv[])
{
	ReadFile readfile("main.cpp", 60);
	LineNum(readfile);
	std::system("pause");
	return 0;
}

void LineNum(ReadFile& f)
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
}
