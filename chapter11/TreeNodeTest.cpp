
#include <iostream>

#include "TreeNode.h"

using namespace std;

int main(int argc, char *argv[])
{

	TreeNode<int> * root, * left, * right;
	right=new TreeNode<int>(40);
	left=new TreeNode<int>(100);
	root=new TreeNode<int>(30, left, right);
	TreeNode<int> * tnew;


	std::cout<<root->data<<std::endl;

	Preorder(root, visit);
	std::cout<<std::endl;
	Inorder(root, visit);
	std::cout<<std::endl;
	Postorder(root, visit);
	std::cout<<std::endl;

	int count=0;
	CountLeaf(root, count);
	std::cout<<count<<std::endl;

	std::cout<<"level: "<<Depth(root)<<std::endl;

	PrintTree(root, Depth(root));
	tnew=CopyTree(root);

	PrintTree(tnew, Depth(tnew));

	LevelScan(root, visit);
	std::cout<<std::endl;
	//PrintVTree(root, 32, 32);
	PrintByLevel(root);
	ClearTree(root);
	ClearTree(tnew);
	PrintTree(root, Depth(root));
	
	std::system("pause");
	return 0;
}

