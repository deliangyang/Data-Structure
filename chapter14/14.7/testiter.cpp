
#include <iostream>

#include "OpenProbe.h"

#include "OpenProbeIterator.h"

using namespace std;

unsigned long HF(int key)
{
	return key%101;
}

int main(int argc, char *argv[])
{
	OpenProbe<int> open(101, HF);
	int i;
	for(i=0; i<20; i++)
		open.Insert(rand()%10);

	if(open.Find(8))
		std::cout<<"find"<<std::endl;

	OpenProbeIterator<int> iterator(open);

	for(iterator.Reset(); !iterator.EndOfList(); iterator.Next())
		std::cout<<iterator.Data()<<" ";
	std::cout<<std::endl;

	std::system("pause");
	return 0;
}


/*	
test print:

	find
0 101: 0
1 101: 1
2 101: 2
0 101: 3
4 101: 4
5 101: 5
6 101: 6
7 101: 7
8 101: 8
9 101: 9
0 101: 10





*/