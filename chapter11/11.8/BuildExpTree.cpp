
#include <iostream>

#include "../TreeNode.h"
#include "../TreeNodeFun.h"
#include "../Queue.h"
#include "../Stack.h"

using namespace std;

int isOperator(char ch)
{
	switch(ch)
	{
		case '+':
		case '-':
		case '*':
		case '/':
			return 1;
		default:
			return 0;
	}
}


void BuildExpTree(TreeNode<T> * t, char * &exp)
{
	Queue<char> queue;						// storage char
	Stack<char> stack;						// storage operator
	Stack<TreeNode<char> *> s;
	TreeNode<char> * ptrNew;
	TreeNode<char> * opr1;
	TreeNode<char> * opr2;
	TreeNode<char> * current=t;
	while(*exp!='\0')
	{
		if(isdigit(*exp))			// is current char is digit
			queue.Insert(*exp);
		if(isOperator(*exp))		// is current char is operator
			stack.push(*exp);
		exp++;
	}
	while(!stack.isEmpty())
	{
		opr1=GetTreeNode(queue.Delete());
		opr2=GetTreeNode(queue.Delete());
		ptrNew=GetTreeNode(stack.pop(), opr1, opr2);
		s.push(ptrNew);
	}
}


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
