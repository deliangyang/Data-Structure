

#ifndef __GRAPH_H__
#define __GRAPH_H__

#include "../SeqList.h"
#include "../Stack.h"
#include "../SeqListIterator.h"

template<class T>
class VertexIterator;

const int MaxGrahpSize=25;

template<class T>
class Graph
{
public:
	Graph(void);
	// adjust graph's state
	int GraphEmpty(void)const;
	int GraphFull(void)const;
	// visit data
	int NumberOfVertex(void)const;
	void NumberOfEdge(void)const;
	int GetWeight(const T& verterx1, const T& verterx2);
	SeqList<T> &GetNeighbors(const T& verterx);
	// review graph
	void InsertVertex(const T& verterx);
	void InsertEdge(const T& verterx1, const T& verterx2, int weight);
	void DeleteVertex(const T& verterx);
	void DeleteEdge(const T& verterx1, const T& verterx2);
	// example
	void ReadGraph(char * filename);
	int MinimumPath(const T& sVertex, const T& eVertex);
	SeqList<T> &DepthFirstSearch(const T& beginVertex);
	SeqList<T> &BreadthFirstSearch(const T& beginVertex);
	void Print(void);
	// iterator
	friend class VertexIterator<T>;
private:
	SeqList<T> vertexList;
	int edge[MaxGrahpSize][MaxGrahpSize];
	// count vertex number
	int graphsize;
	int FindVertex(SeqList<T> &L, const T& verterx);
	int GetVertexPos(const T& verterx);
};

template<class T>
void Graph<T>::Print(void)
{
	for(int i=0; i<MaxGrahpSize; i++)
	{
		for(int j=0; j<MaxGrahpSize; j++)
		{
			if(edge[i][j]==0)
			{
				std::cout<<" "<<" ";
				continue;
			}
			std::cout<<edge[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
}

// init
template<class T>
Graph<T>::Graph(void)
{
	for(int i=0; i<MaxGrahpSize; i++)
		for(int j=0; j<MaxGrahpSize; j++)
			edge[i][j]=0;							// memset zero to init
	graphsize=0;
}

template<class T>
int Graph<T>::GraphEmpty(void)const
{
	return graphsize==0;
}

template<class T>
void Graph<T>::InsertVertex(const T& vertex)
{
	vertexList.Insert(vertex);
}

template<class T>
void Graph<T>::InsertEdge(const T& verterx1, const T& verterx2, int weight)
{
	// insert edge must have two vertex, so zero or one vertex will get error message
	int pos1=GetVertexPos(verterx1);
	int pos2=GetVertexPos(verterx2);
	//if(pos1==-1 || pos2==-1)
	//	return;					// two vertex, one vertex or zero vertex exsit;
	edge[pos1][pos2]=weight;
	graphsize++;
}

template<class T>
void Graph<T>::DeleteVertex(const T& vertex)
{
	int pos=GetVertexPos(vertex);
	int row, col;
	// if it hasn't target vertext, return
	if(pos==-1)
	{
		std::cerr<<"DeleteVertex: vertex is not in graph"<<std::endl;
		return;
	}
	vertexList.Delete(vertex);
	graphsize--;
	// split three area
	for(row=0; row<pos; row++)						// area one
		for(col=pos+1; col<graphsize; col++)
			edge[row][col-1]=edge[row][col];

	for(row=pos+1; row<graphsize; row++)			// area two
		for(col=pos+1; col<graphsize; col++)
			edge[row-1][col-1]=edge[row][col];

	for(row=pos+1; row<graphsize; row++)			// area three
		for(col=0; col<pos; col++)
			edge[row-1][col]=edge[row][col];
}

// DFS start at begin vertex
template<class T>
SeqList<T> &Graph<T>::DepthFirstSearch(const T& beginVertex)
{
	Stack<T> stack;
	SeqList<T> *L, adjl;
	SeqListIterator<T> iterator(adjl);
	T vertex;
	L=new SeqList<T>;
	stack.push(beginVertex);
	while(!stack.isEmpty())
	{
		vertex=stack.pop();
		if(!FindVertex(*L, vertex))
		{
			(*L).Insert(vertex);
			adjl=GetNeighbors(vertex);
			iterator.SetList(adjl);
			for(iterator.Reset(); !iterator.EndOfList(); iterator.Next())
				if(!FindVertex(*L, iterator.Data()))
				{
					stack.push(iterator.Data());
				}
		}
	}
	return *L;
}

template<class T>
SeqList<T>& Graph<T>::GetNeighbors(const T& verter)
{
	SeqList<T> * list;
	SeqListIterator<T> iterator(vertexList);

	list=new SeqList<T>;

	int pos=GetVertexPos(verter);
	if(pos==-1)
	{
		std::cout<<"GetNeighbors: vertex is not in graph"<<std::endl;
		return *list;
	}

	int i;

	for(i=0; i<graphsize; i++)
	{
		if(edge[pos][i]>0)
			list->Insert(iterator.Data());
		iterator.Next();
	}
	return *list;
}

template<class T>
int Graph<T>::FindVertex(SeqList<T> &L, const T& vertex)
{
	int ret=0;
	SeqListIterator<T> iterator(L);
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

// get top vertex position
template<class T>				// for example: vertext={A, B, C, D, E}, if get A return 0, B return 1
int Graph<T>::GetVertexPos(const T& vertex)
{
	SeqListIterator<T> iterator(vertexList);
	int pos=0;					// so position start at -1, if get first vertex, then return 0;
	while(!iterator.EndOfList() && iterator.Data()!=vertex)
	{
		pos++;
		iterator.Next();
	}
	if(iterator.EndOfList())
	{
		std::cerr<<"GetVertexPos: the vertex is not in graph"<<std::endl;
		pos=-1;
	}
	return pos;
}

template<class T>
int Graph<T>::GetWeight(const T& verterx1, const T& verterx2)
{
	int pos1=GetVertexPos(verterx1);
	int pos2=GetVertexPos(verterx2);
	if(pos1==-1 || pos2==-1)
	{
		std::cerr<<"GetWeight: a vertex is not in graph"<<std::endl;
		return -1;
	}
	return edge[pos1][pos2];
}


template<class T>
int Graph<T>::GraphFull(void)const
{
	return graphsize==MaxGrahpSize;
}

template<class T>
int Graph<T>::NumberOfVertex(void)const
{
	return graphsize;
}

#endif


