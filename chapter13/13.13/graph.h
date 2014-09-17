
/*
 *
 *				ADT Adjacency List
 *
 *
 *
 *
 */

#ifndef __GRAPH_H__
#define __GRAPH_H__

#include "SeqList.h"
#include "SeqListIterator.h"
#include "Stack.h"
#include "PQueue.h"
#include "Queue.h"

#include "Array.h"

const int UnDirectedGraph 	= 0;			// undirected graph
const int DirectedGraph 	= 1;			// directed graph

const int NonExsit			= -200;			// non exsit vertex

template<class T>
struct Edge
{
	T vertex;
	int weight;
};

template<class T>
struct Vertex
{
	T vertex;
	SeqList<Edge<T> > list;
};
// compare the vertex, because of the seqlist.Find() to find element
// is exsit or not
// int operator=(Edge &edge1, Edge &edge2)const
// {
// 	return edge1.vertex==edge2.vertex;
// }

template<class T>
class Graph
{
public:
	// constructor
	Graph(int sz);
	// table method
	void InsertVertex(const T& vertex);
	void InsertEdge(const T& vertex1, const T& vertex2, int weight);
	// graph attribute
	int GetWeight(const T& vertex1, const T& vertex2);
	// to traver graph
	SeqList<T> &DepthFirstSearch(const T& beginVertex);
	SeqList<T> &BreadthFirstSearch(const T& beginVertex);
	int MinimumPath(const T& startVertex, const T& endVertex);
private:	
	// set graph top element number
	int graphsize;
	// make SeqList array to storage each top link
	Array<Vertex<T> > arr;
	// cout arr size;
	int arrsize;
	// table private mothod
	int GetVertexPos(const T& vertex);
	Edge<T> GetVertexPos2(int pos, const T& vertex2);
	int FindVertex(SeqList<Edge<T> > lt, const T& vertex);
	int FindList(SeqList<T> lt, const T& vertex);
	SeqList<Edge<T> >& GetNeighbors(const T& vertex);
};



template<class T>
Graph<T>::Graph(int sz)
{
	graphsize	=sz;				// init graph size
	arrsize		=0;					// init array size
}

template<class T>
void Graph<T>::InsertVertex(const T& vertex)
{
	int pos=GetVertexPos(vertex);

	if(pos==-1)			// if not exsit vertex, add this vertex
	{
		arr[arrsize].vertex=vertex;
		arrsize++;	
	}


	/*SeqList<T> &temp=arr[pos];		// get arr index seqlist
	if(temp.Find(vertex))			// if exsit return
		return;
	temp.Insert(vertex);*/
}

template<class T>
void Graph<T>::InsertEdge(const T& vertex1, const T& vertex2, int weight)
{
	int pos=GetVertexPos(vertex1);

	if(pos==-1)			
	{
		std::cout<<"InsertEdge: vertex isn't in this graph"<<std::endl;
		return;
	}
	SeqList<Edge<T> > &temp=arr[pos].list;
	SeqListIterator<Edge<T> > iterator(temp);
	for(iterator.Reset(); !iterator.EndOfList(); iterator.Next())
		if(iterator.Data().vertex==vertex2)
			return;
	Edge<T> edge;				// state edge and then add this int to current array
	edge.vertex=vertex2;
	edge.weight=weight;
	temp.Insert(edge);
}

template<class T>
int Graph<T>::GetVertexPos(const T& vertex)		// if find vertex return current subscript index, else return -1
{
	int pos=0;
	int i;
	for(i=0; i<arrsize; i++)
	{
		if(arr[i].vertex==vertex)
			return pos;
		pos++;
	}
	if(pos>arrsize-1)
		return -1;
	/*int pos=0;
	int i;
	SeqList<T> &temp;
	for(i=0; i<arrsize; i++)
	{
		temp=arr[i];
		if(arr[i]==vertex)
			return pos;
		pos++;
	}
	if(pos>arrsize-1)
		return -1;*/
}

template<class T>
int Graph<T>::GetWeight(const T& vertex1, const T& vertex2)
{
	int pos=GetVertexPos(vertex1);
	if(pos==-1)
	{
		std::cout<<"GetWeight: one or no vertex in this graph"<<std::endl;
		return -1;
	}

	Edge<T> temp=GetVertexPos2(pos, vertex2);
	return temp.weight;	
}

template<class T>
Edge<T> Graph<T>::GetVertexPos2(int pos, const T& vertex2)
{
	SeqList<Edge<T> > &temp=arr[pos].list;
	SeqListIterator<Edge<T> > iterator(temp);
	for(iterator.Reset(); !iterator.EndOfList(); iterator.Next())
		if(iterator.Data().vertex==vertex2)
			return iterator.Data();
	Edge<T> edge;
	edge.weight=NonExsit;

	return edge;
}

template<class T>
SeqList<Edge<T> >& Graph<T>::GetNeighbors(const T& vertex)
{
	int pos=GetVertexPos(vertex);
	SeqList<Edge<T> > *lt;
	lt=new SeqList<Edge<T> >;
	if(pos==-1)
	{
		std::cout<<"GetNeighbors: one or no vertex in this graph"<<std::endl;
		return *lt;
	}

	SeqListIterator<Edge<T> > iterator(arr[pos].list);
	while(!iterator.EndOfList())
	{
		(*lt).Insert(iterator.Data());
		iterator.Next();
	}

	return *lt;
}

template<class T>
SeqList<T> &Graph<T>::DepthFirstSearch(const T& beginVertex)
{
	Stack<T> stack;
	SeqList<T> * L;
	SeqList<Edge<T> > neighbors;
	L=new SeqList<T>;

	int pos=GetVertexPos(beginVertex);
	if(pos==-1)
	{
		std::cout<<"DepthFirstSearch: one or no vertex in this graph"<<std::endl;
		return *L;
	}
	SeqListIterator<Edge<T> > iterator(neighbors);
	stack.push(arr[pos].vertex);			// storage graph vertex
	
	T vertex;

	while(!stack.isEmpty())
	{
		vertex=stack.pop();								// get next vertex
		
		if(!FindList(*L, vertex))
		{
			//std::cout<<"insert: "<<vertex<<std::endl;
			(*L).Insert(vertex);

			/*SeqListIterator<T> it(*L);
			for(it.Reset(); !it.EndOfList(); it.Next())
				std::cout<<it.Data()<<" ";
			std::cout<<std::endl;*/

			neighbors=GetNeighbors(vertex);				// get the neighbors
			
			iterator.SetList(neighbors);
			for(iterator.Reset(); !iterator.EndOfList(); iterator.Next())
				if(!FindList(*L, iterator.Data().vertex))
					stack.push(iterator.Data().vertex);
		}
	}
	
	return *L;
}

template<class T>
SeqList<T> &Graph<T>::BreadthFirstSearch(const T& beginVertex)
{
	int pos=GetVertexPos(beginVertex);

	SeqList<T> * L;
	L=new SeqList<T>;
	if(pos==-1)
	{
		std::cout<<"DepthFirstSearch: one or no vertex in this graph"<<std::endl;
		return *L;
	}
	Queue<T> queue;
	SeqList<Edge<T> > neighbors;
	T vertex;

	SeqListIterator<Edge<T> > iterator(neighbors);

	queue.Insert(arr[pos].vertex);
	while(!queue.isEmpty())
	{
		vertex=queue.Delete();

		if(!FindList(*L, vertex))
		{
			(*L).Insert(vertex);
			neighbors=GetNeighbors(vertex);
			iterator.SetList(neighbors);
			for(iterator.Reset(); !iterator.EndOfList(); iterator.Next())
				if(!FindList(*L, iterator.Data().vertex))
					queue.Insert(iterator.Data().vertex);
		}
	}
	return *L;

}

template<class T>
int Graph<T>::FindVertex(SeqList<Edge<T> > lt, const T& vertex)
{
	int ret=0;
	SeqListIterator<Edge<T> > iterator(lt);
	while(!iterator.EndOfList())
	{
		if(iterator.Data().vertex==vertex)
		{
			ret=1;
			break;
		}
		iterator.Next();
	}
	return ret;
}

template<class T>
int Graph<T>::FindList(SeqList<T> lt, const T& vertex)
{
	int ret=0;
	SeqListIterator<T> iterator(lt);
	while(!iterator.EndOfList())
	{
		if(iterator.Data()==vertex)
		{
			ret=1;
			break;
		}
		iterator.Next();
	}
	return ret;
}

template<class T>
struct VertexInfo
{
	T start, end;
	int cost;						// storage two vertex weight
};

template<class T>
int operator<=(const VertexInfo<T>& vertex1, const VertexInfo<T>& vertex2)
{
	return vertex1.cost<=vertex2.cost;
}

// get minimum path
template<class T>
int Graph<T>::MinimumPath(const T& startVertex, const T& endVertex)
{
	PQueue<VertexInfo<T> > queue(graphsize);			// create prioprity queue to storage the vertex and edge info

	int pos=GetVertexPos(startVertex);		// get the start pos
	int pos2=GetVertexPos(endVertex);
	if(pos==-1 || pos2==-1)
	{
		std::cout<<"MinimumPath: this vertex is not in this graph"<<std::endl;
		exit(1);
	}

	SeqList<T> L;
	SeqList<Edge<T> > adjust;					// storage edge, weight and vertex info
	SeqListIterator<Edge<T> > iterator(adjust);
	int mincost=0;
	T sv=startVertex;
	T ev=endVertex;
	VertexInfo<T> vertexInfo;

	 // init the start vertex info
	vertexInfo.start=startVertex;
	vertexInfo.end=startVertex;
	vertexInfo.cost=0;

	queue.PQInsert(vertexInfo);

	while(!queue.PQEmpty())
	{
		vertexInfo=queue.PQDelete();
		ev=vertexInfo.end;
		mincost=vertexInfo.cost;

		// if reach the start vertex, break;
		if(ev==endVertex)
			break;
		// if the vertex is not exsit int the link
		if(!FindList(L, ev))
		{
			L.Insert(ev);
			sv=ev;
			adjust=GetNeighbors(sv);
			iterator.SetList(adjust);
			for(iterator.Reset(); !iterator.EndOfList(); iterator.Next())
			{
				ev=iterator.Data().vertex;
				if(!FindList(L, ev))
				{
					vertexInfo.start=sv;
					vertexInfo.end 	=ev;
					vertexInfo.cost =mincost+GetWeight(sv, ev);
					queue.PQInsert(vertexInfo);
				}
			}
		}
	}

	if(ev==endVertex)
		return mincost;
	return -1;

}

#endif


