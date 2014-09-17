
#include <iostream>

#include "../TreeNode.h"
#include "../TreeNodeFun.h"

using namespace std;

int main(int argc, char *argv[])
{
	//  a.
	TreeNode<char> * sub;			// -
	TreeNode<char> * add;			// +
	TreeNode<char> * a;
	TreeNode<char> * div;			// / 
	TreeNode<char> * mul;			// *
	TreeNode<char> * b;
	TreeNode<char> * c;
	TreeNode<char> * d;
	TreeNode<char> * e;
	TreeNode<char> * equal;			// root

	a=new TreeNode<char>('a');
	d=new TreeNode<char>('d');
	e=new TreeNode<char>('e');
	b=new TreeNode<char>('b');
	c=new TreeNode<char>('c');
	mul=new TreeNode<char>('*', c, d);			// c*d
	
	div=new TreeNode<char>('+', mul, e);		// c*d+e
	
	add=new TreeNode<char>('+', a, b);			// a+b
	
	equal=new TreeNode<char>('=', add, div);	// a+b=c*d+e

	std::cout<<"preorder: ";
	Preorder(equal, visit);
	std::cout<<std::endl;

	std::cout<<"Inorder: ";
	Inorder(equal, visit);
	std::cout<<std::endl;

	std::cout<<"Postorder: ";
	Postorder(equal, visit);
	std::cout<<std::endl;

	ClearTree(equal);			// free memory


	std::system("pause");
	return 0;
}
