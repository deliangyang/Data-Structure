
#include <iostream>

#include "TreeNode.h"

using namespace std;

int main(int argc, char *argv[])
{

	TreeNode<int> * root, * left, * right;
	right=new TreeNode<int>(40);
	left=new TreeNode<int>(100);
	root=new TreeNode<int>(30, left, right);

	std::cout<<root->data<<std::endl;


	
	std::system("pause");
	return 0;
}

