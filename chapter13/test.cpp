

#include <iostream>

#include "PQueue.h"

#include <string>

int main(int argc, char *argv[])
{
	int i;
	PQueue<int> queue(20);
	for(i=0; i<20; i++)
		queue.PQInsert(rand()%10);
	for(i=0; i<20; i++)
		std::cout<<queue.PQDelete()<<" ";
	std::cout<<std::endl;


	std::system("pause");
	return 0;
}
