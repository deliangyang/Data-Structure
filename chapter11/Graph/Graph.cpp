
#include <iostream>

#include "Graph.h"
#include "../SeqList.h"

#include "../SeqListIterator.h"

using namespace std;

int main(int argc, char *argv[])
{
	Graph<int> graph;
	
	
	graph.InsertVertex(20);
	graph.InsertVertex(1);
	graph.InsertVertex(10);
	graph.InsertVertex(5);

	graph.InsertEdge(10, 20, 100);
	graph.InsertEdge(1, 20, 10);
	graph.InsertEdge(10, 5, 130);
	std::cout<<"vertex length: "<<graph.NumberOfVertex()<<std::endl;
	graph.Print();

	std::cout<<"GetWeight: "<<graph.GetWeight(10, 20)<<std::endl;

	SeqList<int> list;
	list=graph.DepthFirstSearch(20);
	SeqListIterator<int> iterator(list);
	for(iterator.Reset(); !iterator.EndOfList(); iterator.Next())
		std::cout<<iterator.Data()<<" ";
	std::cout<<std::endl;

	
	std::system("pause");
	return 0;
}

