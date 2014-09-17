
#include <iostream>
#include "CPU.h"
#include "../PQueue.h"

int main(int argc, char *argv[])
{
	PQueue<ProcessRequestRecord> queue(10);

	MakeRecord(queue, 10);

	ProcessRequestRecord process;
	int i;
	for(i=0; i<10; i++)
	{
		process=queue.PQDelete();
		std::cout<<process.name<<std::endl;
	}

	std::system("pause");
	return 0;
}
