
#include <iostream>
#include "../PriorityQueue.h"

using namespace std;

int main(int argc, char *argv[])
{
	PQueue<int> queue;
	for(int i=0; i<30; i++)
		queue.Insert(rand()%100);
	std::cout<<queue.isFull()<<std::endl;
	for(int i=0; i<30; i++)
		std::cout<<queue.Delete()<<" ";
	std::cout<<queue.isEmpty()<<std::endl;
	/*Queue<int> queue;
	for(int i=0; i<30; i++)
	{
		std::cout<<i<<" ";
		queue.Insert(i);
	}
	if(queue.isFull())
		std::cout<<"is Full"<<std::endl;
	for(int i=0; i<10; i++)
		std::cout<<queue.Delete()<<" ";
	std::cout<<std::endl;*/
	std::system("pause");
	return 0;
}
