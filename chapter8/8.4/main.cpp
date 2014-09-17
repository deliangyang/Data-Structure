
#include <iostream>
#include "CrrCL.h"
#include <exception>
#include "arrsort.h"

using namespace std;

int main(int argc, char *argv[])
{
	CrrCL<int> crrcl(10);
	int i;
	for(i=0; i<10; i++)
		crrcl[i]=rand()%100;

	
	try
	{
		crrcl[10]=10;
	}
	catch(exception& e)
	{
		std::cout<<e.what()<<std::endl;
	}


	std::system("pause");
	return 0;
}
