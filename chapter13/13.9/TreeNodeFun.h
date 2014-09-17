


/*
 *
 *		some function of ADT
 *
 *
 *
 */

// get new tree node, just by allocate new memory
#include <iomanip>
#include "TreeNode.h"

 template<class T>
 TreeNode<T> * GetTreeNode(const T& item, TreeNode<T> * ptrL=NULL, TreeNode<T> * ptrR=NULL)
 {
 	TreeNode<T> * ptrNew;
 	ptrNew=new TreeNode<T>(item, ptrL, ptrR);
 	if(ptrNew==NULL)
 	{
 		std::cerr<<"No Memory Allocate"<<std::endl;
 		exit(1);
 	}
 	return ptrNew;
 }

// preorder traversal
 template<class T>
 void Preorder(TreeNode<T> * t, void visit(T& item))
 {
 	if(t!=NULL)
 	{
 		visit(t->data);
 		Preorder(t->Left(), visit);
 		Preorder(t->Right(), visit);
 	}
 }

// inorder traversal
template<class T>
void Inorder(TreeNode<T> * t, void visit(T& item))
{
	if(t!=NULL)
	{
		Inorder(t->Left(), visit);
		visit(t->data);
		Inorder(t->Right(), visit);
	}
}

// after the traversal
template<class T>
void Postorder(TreeNode<T> * t, void visit(T& item))
{
	if(t!=NULL)
	{
		Postorder(t->Left(), visit);
		Postorder(t->Right(), visit);
		visit(t->data);
	}
}


template<class T>
void visit(T & item)
{
	std::cout<<item<<" ";
}

// count last level's node
template<class T>
void CountLeaf(TreeNode<T> * t, int& count)
{
	if(t!=NULL)
	{
		CountLeaf(t->Left(), count);
		CountLeaf(t->Right(), count);
		if(t->Left()==NULL && t->Right()==NULL)
			count++;
	}
}

// count level depth
template<class T>
int Depth(TreeNode<T> * t)
{
	int depthL, depthR, depthVal;
	if(t==NULL)
		return -1;
	else
	{	
		depthL=Depth(t->Left());
		depthR=Depth(t->Right());
		depthVal=1+(depthL>depthR?depthL:depthR);
	}
	return depthVal;
}

const int indentBlock=6;

void IndentBlank(int num)
{
	for(int i=0; i<num; i++)
		std::cout<<" ";
}

template<class T>
void PrintTree(TreeNode<T> * t, int level)
{
	if(t!=NULL)
	{
		PrintTree(t->Right(), level+1);
		IndentBlank(indentBlock*level);
		std::cout<<t->data<<std::endl;
		PrintTree(t->Left(), level+1);
	}
}

template<class T>
void DeleteTree(TreeNode<T> * t)
{
	if(t!=NULL)
	{
		DeleteTree(t->Left());
		DeleteTree(t->Right());
		FreeNode(t);
	}
}

template<class T>
void ClearTree(TreeNode<T> * &t)
{
	DeleteTree(t);
	t=NULL;
}

 template<class T>
 void FreeNode(TreeNode<T> * p)
 {
 	delete p;
 	p=NULL;
 }

template<class T>
TreeNode<T> * CopyTree(TreeNode<T> * t)
{
	TreeNode<T> * ptrL, * ptrR;
	TreeNode<T> * ptrNew;
	if(t==NULL)
		return NULL;
	if(t->Left()!=NULL)
		ptrL=CopyTree(t->Left());
	else
		ptrL=NULL;
	if(t->Right()!=NULL)
		ptrR=CopyTree(t->Right());
	else
		ptrR=NULL;
	ptrNew=GetTreeNode(t->data, ptrL, ptrR);
	return ptrNew;
}

template<class T>
void LevelScan(TreeNode<T> * t, void visit(T& item))
{
	if(t!=NULL)
	{
		Queue<TreeNode<T> *> queue;
		TreeNode<T> * p;
		queue.Insert(t);			// insert root tree node
		while(!queue.isEmpty())
		{
			p=queue.Delete();
			visit(p->data);
			if(p->Left()!=NULL)
				queue.Insert(p->Left());
			if(p->Right()!=NULL)
				queue.Insert(p->Right());
		}
	}
}

struct NodeInfo  				
{
	int indent, level;
};

template<class T>
void PrintVTree(TreeNode<T> * t, int dataWidth, int screenWidth)
{
	Queue<TreeNode<T> *> queue;
	Queue<NodeInfo> nodeInfo;				// store the current node info(index, level)
	TreeNode<T> * p;
	NodeInfo node;

	int nodelevel, nodeindent;
	int currentIndent=0, currentLevel=0;

	int posChange, deltaChange, i;

	node.indent=screenWidth/2;
	node.level=0;
								// offset of the node
	nodeInfo.Insert(node);
	queue.Insert(t);
	
	while(!queue.isEmpty())
	{
		p=queue.Delete();	
		node=nodeInfo.Delete();

		nodeindent=node.indent;
		nodelevel=node.level;

		if(node.level>currentLevel)						// new line
		{
			std::cout<<std::endl;
			currentLevel++;
			currentIndent=0;
		}

		posChange=(nodeindent>currentIndent)?nodeindent - currentIndent:nodeindent;
		for(i=0; i<posChange-dataWidth; i++)
			cout<<" ";
		cout<<setw(dataWidth)<<p->data;

		currentIndent=nodeindent;

		deltaChange	= screenWidth / (1 << (nodelevel + 2) );
		deltaChange	= deltaChange < 2 ? 2 : deltaChange;


		std::cout<<p->data;

		if(p->Left()!=NULL)
		{
			node.level+=1;
			node.indent=deltaChange - nodeindent;
			queue.Insert(p->Left());
			nodeInfo.Insert(node);
		}
		if(p->Right()!=NULL)
		{
			node.level+=1;
			node.indent=deltaChange + nodeindent;
			queue.Insert(p->Right());
			nodeInfo.Insert(node);
		}
	}
}

template<class T>
void PrintLevel(TreeNode<T> * t, int level)
{
	if(t==NULL || level<0)
		return;
	if(level==1)
	{
		std::cout<<std::setw(10)<<t->data<<" ";
		return;
	}
	PrintLevel(t->Left(), level-1);
	PrintLevel(t->Right(), level-1);
}

template<class T>
void PrintByLevel(TreeNode<T> * t)
{
	int level=Depth(t)+1;
	for(int i=1; i<=level; i++)
	{
		PrintLevel(t, i);
		std::cout<<std::endl;
	}
}

