
#include <iostream>

#include "../Queue.h"

using namespace std;

template<class T>
void PrintQueue(Queue<T> &queue)
{
	std::cout<<"Current Element: ";
	while(!queue.isEmpty())
		std::cout<<queue.Delete()<<" ";
	std::cout<<std::endl;
}

int main(int argc, char *argv[])
{
	
	Queue<int> queue;
	for(int i=0; i<10; i++)
	{
		queue.Insert(i);
		std::cout<<i<<" ";
	}
	std::cout<<std::endl;
	std::cout<<"Delete test: ";

	std::cout<<"isEmpty: "<<queue.isEmpty()<<std::endl;

	std::cout<<"length: "<<queue.Length()<<std::endl;

	PrintQueue(queue);

	std::cout<<"isEmpty: "<<queue.isEmpty()<<std::endl;

	std::system("pause");
	return 0;
}
