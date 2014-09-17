
#include <iostream>

#include "Queue.h"
#include "QueueIterator.h"

using namespace std;

template<class T>
T GetRear(Queue<T> &q)
{
	int len=q.Length()-1;
	return q.GetData(len);
}

int main(int argc, char *argv[])
{
	Queue<int> queue(10);

	int i;
	for(i=0; i<10; i++)
		queue.Insert(rand()%10);
	std::cout<<"last element: "<<GetRear(queue)<<std::endl;
	QueueIterator<int> iterator(queue);
	std::cout<<"orign: ";
	for(iterator.Reset(); !iterator.EndOfList(); iterator.Next())
		std::cout<<iterator.Data()<<" ";
	std::cout<<std::endl;
	std::system("pause");
	return 0;
}
