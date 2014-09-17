

#include "graph.h"

#include "SeqList.h"
#include "SeqListIterator.h"

#include <iostream>


template<class T>
int PathConnect(Graph<T> G, T v, T w)
{	
	SeqList<T> t;
	t=G.DepthFirstSearch(v);
	if(t.Find(w))
		return 1;
	return 0;
}

int main(int argc, char *aragv[])
{
	Graph<int> g(30);
	g.InsertVertex(10);
	g.InsertVertex(20);
	g.InsertVertex(30);
	g.InsertVertex(40);
	g.InsertVertex(50);

	g.InsertEdge(10, 20, 100);
	g.InsertEdge(20, 30, 10);
	g.InsertEdge(10, 40, 20);
	g.InsertEdge(30, 10, 300);

	std::cout<<"weight: "<<g.GetWeight(10, 20)<<std::endl;
	//g.DepthFirstSearch(10);
	SeqList<int> list;
	list=g.DepthFirstSearch(10);

	std::cout<<"path connect: "<<PathConnect(g, 20, 30)<<std::endl;

	std::cout<<"Minimum Path: "<<g.MinimumPath(10, 30)<<std::endl;

	SeqListIterator<int> iterator(list);
	for(iterator.Reset(); !iterator.EndOfList(); iterator.Next())
		std::cout<<iterator.Data()<<" ";
	std::cout<<std::endl;

	list.ClearList();






	SeqList<int> * temp;
	temp=&g.BreadthFirstSearch(10);
	SeqListIterator<int> iterator1(*temp);
	for(iterator1.Reset(); !iterator1.EndOfList(); iterator1.Next())
		std::cout<<iterator1.Data()<<" ";
	std::cout<<std::endl;

	std::system("pause");
	return 0;
}
