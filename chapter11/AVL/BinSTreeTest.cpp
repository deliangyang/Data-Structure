

#include <iostream>


#include "String.h"
#include "BinSTree.h"

#include "TreeNodeFun.h"

using namespace std;

template<class T>
T FindMax(BinSTree<T> &root)
{
	TreeNode<T> * t=root.GetRoot();
	if(t==NULL)
		return -1;
	while(t->Right()!=NULL)
		t=t->Right();
	return t->data;
}

int main(int argc, char *argv[])
{
	BinSTree<String> bin;
	String str[]={String("for"), String("case"), String("while"), String("class"),
				String("protected"), String("virtual"), String("public"), String("private"),
				String("do"), String("template"), String("int"), String("const"), String("if")};
	int i;
	for(i=0; i<13; i++)
		bin.Insert(str[i]);

	PrintByLevel(bin.GetRoot());
	std::cout<<std::endl;
	Inorder(bin.GetRoot(), visit);
	std::cout<<std::endl;
	Postorder(bin.GetRoot(), visit);

	std::cout<<std::endl;
	Preorder(bin.GetRoot(), visit);


	/*BinSTree<int> bin;
	TreeNode<int> * tree;
	TreeNode<int> * parent;
	
	bin.Insert(4);
	bin.Insert(50);
	bin.Insert(10);
	bin.Insert(30);
	bin.Insert(200);
	bin.Insert(3);
	
	int temp=50;
	int test=bin.Find(temp);
	if(test)
		std::cout<<"find: "<<temp<<std::endl;

	std::cout<<"length: "<<bin.length()<<std::endl;

	std::cout<<"find min: "<<bin.FindMin()<<std::endl;

	std::cout<<"find max:"<<FindMax(bin)<<std::endl;

	//Inorder(bin.GetRoot(), visit);
	//LevelScan(bin.GetRoot(), visit);
	PrintByLevel(bin.GetRoot());
	std::cout<<"\ntest Update"<<std::endl;
	bin.Update(50);
	PrintByLevel(bin.GetRoot());

	std::cout<<"\ntest delete"<<std::endl;
	bin.Delete(50);
	PrintByLevel(bin.GetRoot());*/
	
	std::system("pause");
	return 0;
}
