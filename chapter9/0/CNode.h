
#ifndef __CNODE_H__
#define __CNODE_H__


template<class T>
class CNode
{
public:
	// element
	T data;
	// constructures
	CNode(void);
	CNode(const T& item);
	// insert and delete element after current node
	void InsertAfter(CNode<T> *p);		
	CNode<T> * DeleteAfter(void);
	// next node area
	CNode<T> * &NextNode(void);
private:
	// next node area
	CNode<T> * next;          			
};

template<class T>
CNode<T>::CNode(void)
{
	next=this;
}

template<class T>
CNode<T>::CNode(const T& item)
{
	next=this;				// pointer back header
	data=item;
}

template<class T>
void CNode<T>::InsertAfter(CNode<T> *p)
{
	p->next=next;			//  [data|next] [p->data|p->next] p->next become next node address
	next=p;					//		 -next-	------- p -------
}

template<class T>
CNode<T> * CNode<T>::DeleteAfter(void)
{
	CNode<T> * ptrTemp=next;
	if(next==this)
		return NULL;	/// if the node address is the header, need not to delete
	next=ptrTemp->next;
	return ptrTemp;		/// return delete node address
}

template<class T>
CNode<T> * &CNode<T>::NextNode(void)
{
	return next;		/// return next node address
}


#endif	

