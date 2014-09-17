
#include <iostream>

#include "../TreeNode.h"
#include "../TreeNodeFun.h"

using namespace std;

int main(int argc, char *argv[])
{
	//  a.
	TreeNode<char> * head;			// -
	TreeNode<char> * add;			// +
	TreeNode<char> * a;
	TreeNode<char> * div;			// / 
	TreeNode<char> * mul;			// *
	TreeNode<char> * b;
	TreeNode<char> * c;
	TreeNode<char> * d;
	TreeNode<char> * e;

	b=new TreeNode<char>('b');
	c=new TreeNode<char>('c');
	mul=new TreeNode<char>('*', b, c);
	d=new TreeNode<char>('d');
	div=new TreeNode<char>('/', mul, d);
	a=new TreeNode<char>('a');
	add=new TreeNode<char>('+', a, div);
	e=new TreeNode<char>('e');
	head=new TreeNode<char>('-', add, e);

	std::cout<<"preorder: ";
	Preorder(head, visit);
	std::cout<<std::endl;

	std::cout<<"Inorder: ";
	Inorder(head, visit);
	std::cout<<std::endl;

	std::cout<<"Postorder: ";
	Postorder(head, visit);
	std::cout<<std::endl;

	ClearTree(head);			// free memory


	std::system("pause");
	return 0;
}
