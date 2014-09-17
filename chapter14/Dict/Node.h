

#ifndef _NODE_H
#define _NODE_H

template<class T>
class Node
{
public:
	T data;
	Node(const T& item, Node<T> * ptrNext=NULL);
	void InsertAfter(Node<T> * p);
	Node<T> * DeleteAfter(void);
	Node<T> * NextNode(void)const;
private:
	Node<T> * next;
};

template<class T>
Node<T>::Node(const T& item, Node<T>* ptrNext):data(item),next(ptrNext){}

template<class T>
void Node<T>::InsertAfter(Node<T> * p)
{
	p->next=next;
	next=p;
}

template<class T>
Node<T> * Node<T>::DeleteAfter(void)
{
	Node<T> * ptrTemp=next;

	if(ptrTemp==NULL)
		return NULL;
	next=ptrTemp->NextNode();

	return ptrTemp;
}

template<class T>
Node<T> * Node<T>::NextNode(void)const
{
	return next;
}

template<class T>
Node<T> * GetNode(const T& item, Node<T> * ptrNext=NULL)
{
	Node<T> * ptrNew;
	ptrNew=new Node<T>(item, ptrNext);
	if(ptrNew==NULL)
	{
		std::cerr<<"No Memory Allocate"<<std::endl;
		exit(1);
	}

	return ptrNew;
}

template<class T>
void InsertFront(Node<T> *& head, T item)
{
	head=GetNode(item, head);
}

template<class T>
void PrintList(Node<T> * head)
{
	Node<T> * ptrTemp=head;
	while(ptrTemp!=NULL)
	{
		std::cout<<ptrTemp->data<<" ";
		ptrTemp=ptrTemp->NextNode();
	}
}

template<class T>
void InsertTail(Node<T> *& head, T item)
{
	Node<T> * ptrCurrent=head;
	Node<T> * ptrNew;
	if(ptrCurrent==NULL)
		InsertFront(head, item);
	else
	{
		while(ptrCurrent->NextNode()!=NULL)
			ptrCurrent=ptrCurrent->NextNode();
		ptrNew=GetNode(item);
		ptrCurrent->InsertAfter(ptrNew);
	}
}

template<class T>
void DeleteFront(Node<T> *& head)
{
	Node<T> * ptrCurrent=head;
	if(ptrCurrent!=NULL)
	{
		head=ptrCurrent->NextNode();
		delete ptrCurrent;
		ptrCurrent=NULL;
	}
}

template<class T>
void Delete(Node<T> *& head, T key)
{
 	Node<T> * ptrCurrent=head;
 	Node<T> * ptrPrev=NULL;
 	if(ptrCurrent==NULL)
 		return;
 	while(ptrCurrent!=NULL && ptrCurrent->data!=key)
 	{
 		ptrPrev=ptrCurrent;
 		ptrCurrent=ptrCurrent->NextNode();
 	}
 	if(ptrCurrent!=NULL)
 	{
 		if(ptrPrev==NULL)
 			head=head->NextNode();
 		else
 			ptrPrev->DeleteAfter();
 		delete ptrCurrent;
 	}
}

template<class T>
void InsertOrder(Node<T>* &head, T item)
{
	Node<T> * ptrCurrent=head;
	Node<T> * ptrPrev=NULL;
	Node<T> * ptrNew;
	while(ptrCurrent!=NULL)
	{
		if(item<ptrCurrent->data)
			break;
		ptrPrev=ptrCurrent;
		ptrCurrent=ptrCurrent->NextNode();
	}
	if(ptrPrev==NULL)
		InsertFront(head, item);
	else
	{
		ptrNew=GetNode(item);
		ptrPrev->InsertAfter(ptrNew);
	}
}

template<class T>
void ClearList(Node<T> *& head)
{
	Node<T> * ptrCurrent;
	while(head!=NULL)
	{	
		ptrCurrent=head->NextNode();
		delete head;
		head=ptrCurrent;
	}
	head=NULL;
}

#endif
