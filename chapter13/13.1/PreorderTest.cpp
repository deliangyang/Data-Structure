
#include <iostream>

#include "../Arrayoder.h"

using namespace std;

int main(int argc, char *argv[])
{
	int arr[]={1, 2, 3, 4 , 5, 6, 7, 8, 9, 10};

	std::cout<<"Preorder: ";
	Preorder(arr, 0, 10);

	std::cout<<std::endl;

	std::cout<<"Inorder: ";
	Inorder(arr, 0, 10);

	std::cout<<std::endl;

	std::cout<<"Postorder: ";
	Postorder(arr, 0, 10);

	std::cout<<std::endl;

	int count=0;
	CountLeaf(arr, count, 0, 10);
	std::cout<<"Count Leaf: "<<count<<std::endl;

	int c=0;
	CountOnlyOneChild(arr, c, 0, 10);
	std::cout<<"Count Only One Child: "<<c<<std::endl;

	c=0;
	CountTwoChild(arr, c, 0, 10);
	std::cout<<"Count Two Child: "<<c<<std::endl;

	//int i;
	//for(i=0; i<10; i++)


	std::system("pause");
	return 0;
}
