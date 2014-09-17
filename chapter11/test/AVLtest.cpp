
#include <iostream>

#include "../AVLTree.h"

using namespace std;

int main(int argc, char *argv[])
{
	
	AVLTree<int> avl;
	int i;
	int temp;
	for(i=0; i<10; i++)
	{
		temp=rand()%10;
		avl.Insert(temp);
		std::cout<<temp<<" ";
	}

	

	std::cout<<std::endl;

	std::system("pause");
	return 0;
}


