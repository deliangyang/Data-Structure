
#include <iostream>

#include "Queue.h"
#include "QueueIterator.h"

using namespace std;

int main(int argc, char *argv[])
{
	
	Queue<int> queue(10);
	
	for(int i=0; i<10; i++)
	{
		queue.Insert(i);
		std::cout<<i<<" ";
	}
	std::cout<<"queue Length: "<<queue.Length()<<std::endl;
	std::cout<<std::endl;
	QueueIterator<int> iterator(queue);			// must state after add element, else queue.length is zero
	for(iterator.Reset(); !iterator.EndOfList(); iterator.Next())
	{
		std::cout<<iterator.Data()<<" ";
		std::cout<<"----------"<<std::endl;
	}
	/*for(int i=0; i<10; i++)
		std::cout<<queue.Delete()<<" ";*/
	std::cout<<std::endl;


	std::system("pause");
	return 0;
}
