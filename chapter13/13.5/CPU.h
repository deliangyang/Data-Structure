
#ifndef __CPU_H__
#define __CPU_H__



#include <string>

struct ProcessRequestRecord
{
	int priority;
	std::string name;
};

int operator<=(const ProcessRequestRecord& process1, const ProcessRequestRecord& process2)
{
	return process1.priority<=process2.priority;
}

#include "../PQueue.h"

void MakeRecord(PQueue<ProcessRequestRecord> &queue, int n)
{
	ProcessRequestRecord process;
	int i;
	
	for(i=0; i<n; i++)
	{
		std::string name;
		process.priority=rand()%40;
		name+=(char)('A'+i);
		process.name="process"+name;
		queue.PQInsert(process);
	}
}


#endif
