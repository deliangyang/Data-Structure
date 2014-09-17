

#include <iostream>

#include "Priority.h"

#include <string>

int main(int argc, char *argv[])
{
/*	Queue<int> queue(5);
	int i;
	for(i=0; i<5; i++)
		queue.Insert(rand()%10);
/**/
	Queue<std::string> queue(5);
	int i;
	queue.Insert("pause");
	queue.Insert("thisisda");
	queue.Insert("asdfasf");
	queue.Insert("dsadd");
	queue.Insert("cfadff");

	for(i=0; i<5; i++)
		std::cout<<queue.Delete()<<std::endl;



	std::system("pause");
	return 0;
}
