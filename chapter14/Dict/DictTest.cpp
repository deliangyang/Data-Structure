

#include <iostream>
#include <string>
//#include "String.h"
#include "Dictionary.h"
#include "KeyValue.h"
//#include "TreeNodeFun.h"

template<class T>
void PrintTree(TreeNode<T> * t, int level)
{
	if(t!=NULL)
	{
		PrintTree(t->Right(), level+1);
		//IndentBlank(indentBlock*level);
		std::cout<<t->data.Key()<<": "<<t->data.value<<std::endl;
		PrintTree(t->Left(), level+1);
	}
}

using namespace std;

int main(int argc, char *argv[])
{
	//string k="qw";
	//string v="hello";
	/*int a=100;
	KeyValue<String, int> data("hello", a);*/
	//Dict<String, int> dict(a);
	Dict<string, string> dict("");
	//KeyValue<string, string> a("hello", "world");
	//dict.Insert(a);
	//dict.Insert(a);
	//std::cout<<dict.length()<<std::endl;
	std::cout<<"error after"<<std::endl;
	//dict[k]+=v;
	dict["qw"]+="hello";
	PrintTree(dict.GetRoot(), 3);
	//dict["qw"]+="hello world";
	//dict["sextet"]+="A group of six";
	//dict["q"]="hello";

	std::system("pause");
	return 0;
}
