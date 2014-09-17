
#include <iostream>

#include "../Node.h"
#include "Employee.h"



using namespace std;

int operator==(Employee& a, Employee& b)
{
	return a.idnumber==b.idnumber;
}

int operator>(Employee& a, Employee& b)
{
	return a.hourlyper>b.hourlyper;
}

template<class T>
int Find(Node<T> * &list, T& key)
{
	int result=0;
	Node<T> * ptrCurrent=list;
	while(ptrCurrent!=NULL)
	{
		if(ptrCurrent->data==key)
		{
			result++;
			ptrCurrent->data.hourlyper+=3;				// there is the problem, i can't reach the increment of structure
			break;
		}
		ptrCurrent=ptrCurrent->NextNode();
	}
	return result;
}

/*template<class T>
void DeleteKey(Node<T>* & head, T key)
{
	Node<T> * ptrCurrent=head;
	Node<T> * ptrPrev;
	Node<T> * ptrDel;
	Node<T> * ptrTemp;
	if(ptrCurrent==NULL)
		return;
	if(ptrCurrent->data==key)
	{
		if(ptrCurrent->NextNode()==NULL)			// 如果只有一个节点
		{
			delete head;
			head=NULL;
		}
		else										// 如果是第一个元素，它的下一个节点不是NULL
		{
			std::cout<<ptrCurrent->data;
			std::cout<<"--------------"<<std::endl;
			ptrDel=head;
			head=head->NextNode();
			//ptrCurrent=head;
			//ptrPrev=NULL;
			delete ptrDel;
		}
	}
	else
	{
		ptrPrev=ptrCurrent;
		ptrCurrent=ptrCurrent->NextNode();
		while(ptrCurrent->NextNode()!=NULL)
		{
			
			if(ptrCurrent->data==key)
			{
				std::cout<<ptrCurrent->data;
				std::cout<<"-------------"<<std::endl;
				ptrDel=ptrPrev->DeleteAfter();			// get the delete node
				ptrCurrent=ptrPrev;
				delete ptrDel;							// free delete node
				ptrDel=NULL;
			}
			else
			{
				ptrPrev=ptrCurrent;
				ptrCurrent=ptrCurrent->NextNode();
			}
		}
	}
}*/

template<class T>
void DeleteKey(Node<T> *& head, T& key)
{
	Node<T> * ptrCurrent=head;
	Node<T> * ptrPrev=NULL;
	Node<T> * ptrDel=NULL;
	if(ptrCurrent==NULL)
		return;
	if(ptrCurrent->data==key)			// think the element show at first
	{
		if(ptrCurrent->NextNode()==NULL)
		{
			delete head;
			head=NULL;
		}
		else
		{
			ptrDel=head;
			head=head->NextNode();
			delete ptrDel;
			ptrDel=NULL;
		}
	}
	else								// second 
	{
		ptrPrev=ptrCurrent;
		ptrCurrent=ptrCurrent->NextNode();
		while(ptrCurrent!=NULL)
		{
			if(ptrCurrent->data==key)
				ptrPrev->DeleteAfter();
			ptrCurrent=ptrCurrent->NextNode();
		}
	}
}

template<class T>
void DeleteMoreNine(Node<T> * &head, T& key)
{
	Node<T> * ptrCurrent=head;
	while(ptrCurrent!=NULL)
	{
		if(ptrCurrent->data>key)
			DeleteKey(head, ptrCurrent->data);
		ptrCurrent=ptrCurrent->NextNode();
	}
}

template<class T>
void Clear(Node<T> * &head)				// clear the node
{
	Node<T> * ptrDel;
	while(head!=NULL)
	{
		ptrDel=head;
		head=head->NextNode();
		delete ptrDel;
		ptrDel=NULL;
	}
	head=NULL;
}

int main(int argc, char *argv[])
{

	Node<Employee> * head=NULL;

	Employee temp;

	Employee employee[3]={{"Dennis Williams", 40, 9.50}, {"Harold Barry", 10, 6.00}, 
					{"Steve Walker", 25, 8.750}};
	int i;
	for(i=0; i<3; i++)
		InsertTail(head, employee[i]);
	std::cout<<"id hourpay name"<<std::endl;
	PrintList(head);

	int num;
	std::cout<<"\nselect the id(to low pay money): ";
	std::cin>>num;
	temp.idnumber=num;
	Find(head, temp);
	PrintList(head);

	std::cout<<"delete the pay money more than 9 each hour: "<<std::endl;
	temp.hourlyper=9.0;
	DeleteMoreNine(head, temp);
	PrintList(head);

	Clear(head);
	std::cout<<"------just test clear list-------------";
	PrintList(head);
	std::system("pause");
	return 0;
}
