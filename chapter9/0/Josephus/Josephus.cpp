
#include <iostream>

#include "../CNode.h"

using namespace std;

void CreateList(CNode<int> * header, int n)
{
	CNode<int> * ptrCurrent=header, * ptrNew;
	int i;
	for(i=1; i<=n; i++)
	{
		ptrNew=new CNode<int>(i);
		ptrCurrent->InsertAfter(ptrNew);
		ptrCurrent=ptrNew;
	}
}

void Josephus(CNode<int> * header, int n, int m)
{
	CNode<int> * ptrPrev=header, * ptrCurrent=header->NextNode();
	CNode<int> * ptrDel;

	int i, j;
	for(i=0; i<n-1; i++)
	{
		for(j=0; j<m-1; j++)
		{
			ptrPrev=ptrCurrent;
			ptrCurrent=ptrCurrent->NextNode();
			if(ptrCurrent==header)
			{
				ptrPrev=header;
				ptrCurrent=ptrCurrent->NextNode();
			}
		}
		std::cout<<"Delete person: "<<ptrCurrent->data<<std::endl;
		ptrDel=ptrCurrent;
		ptrCurrent=ptrCurrent->NextNode();
		ptrPrev->DeleteAfter();
		delete ptrDel;
		if(ptrCurrent==header)
		{
			ptrPrev=ptrCurrent;
			ptrCurrent=ptrCurrent->NextNode();
		}
	}
	std::cout<<std::endl<<"Person "<<ptrCurrent->data<<" wins the game"<<std::endl;
	ptrDel=header->DeleteAfter();
	delete ptrDel;
}


int main(int argc, char *argv[])
{
	CNode<int> list;
	int n, m;

	std::cin>>n;
	m=rand()%n+1;
	CreateList(&list, n);	
	Josephus(&list, n, m);

	
	std::system("pause");
	return 0;
}
