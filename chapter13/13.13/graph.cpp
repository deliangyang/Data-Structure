
#include <iostream>

#include "graph.h"

using namespace std;

template<class T>
int VertexLength(Graph<T> &g, const T &v1, const T &v2)
{
	return g.MinimumPath(v1, v2);
}

int main(int argc, char *argv[])
{
	Graph<char> A(8);
	Graph<char> B(8);
	
	char arr[]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

	int i;
	for(i=0; i<8; i++)
		A.InsertVertex(arr[i]);

	A.InsertEdge('A', 'B', 12);
	A.InsertEdge('B', 'D', 11);
	A.InsertEdge('D', 'A', 10);
	A.InsertEdge('A', 'C', 20);
	A.InsertEdge('C', 'F', 430);
	A.InsertEdge('F', 'E', 32);
	A.InsertEdge('E', 'C', 10);
	A.InsertEdge('H', 'F', 20);
	A.InsertEdge('H', 'G', 12);
	A.InsertEdge('G', 'D', 4);

	for(i=0; i<8; i++)
	{
		std::cout<<arr[0]<<"--->"<<arr[i]<<": ";
		std::cout<<VertexLength(A, arr[0], arr[i])<<std::endl;
	}

	std::system("pause");
	return 0;
}
