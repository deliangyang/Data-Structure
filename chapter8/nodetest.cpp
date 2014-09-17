
#include <iostream>

#include "Node.h"
#include "Linked.h"
#include "Queue.h"

#include "SeqList.h"

using namespace std;

int main(int argc, char *argv[])
{
	Linked<int> link;
	link.InsertFront(100);
	for(int i=0; i<5; i++)
		link.InsertAfter(i+4);
	//link.Reset(3);
	link.DeleteAt();

	link.InsertFront(200);
	for(link.Reset(0); !link.EndOfList(); link.Next())
		std::cout<<link.Data()<<" ";
	/*SeqList<int> list;
	for(int i=0; i<5; i++)
		list.Insert(i);
	//list.Delete(4);
	list.Delete(2);
	for(int i=0; i<4; i++)
		std::cout<<list.DeleteFront()<<std::endl;*/
	/*Queue<int> queue;
	for(int i=0; i<5; i++)
		queue.Insert(i);
	
	queue.Insert(100);
	queue.Insert(200);
	//queue.Clear();
	queue.Insert(100);
	queue.Insert(200);
	std::cout<<"size: "<<queue.Length()<<std::endl;
	//queue.Clear();
	//queue.Insert(3002);
	for(int i=0; i<7; i++)
		std::cout<<queue.Delete()<<" ";*/
	/*Linked<int> link;
	link.InsertFront(100);
	for(int i=0; i<5; i++)
		link.InsertAfter(i+4);
	//link.DeleteAt();
	link.InsertFront(200);
	int temp=link.DeleteFront();
	for(link.Reset(0); !link.EndOfList(); link.Next())
		std::cout<<link.Data()<<" ";
	link.ClearList();
	for(link.Reset(0); !link.EndOfList(); link.Next())
		std::cout<<link.Data()<<" ";
	std::cout<<temp<<std::endl;*/
	/*std::system("color 2");
	Node<int> * head=NULL;
	for(int i=0; i<10; i++)
		InsertOrder(head, rand()%100);
	InsertOrder(head, 100);
	InsertOrder(head, 300);
	//DeleteFront(head);
	
	
	InsertOrder(head, 400);
	//InsertTail(head, 1000);
	//InsertTail(head, 50);
	InsertOrder(head, 5);
	//Delete(head, 5);
	//Delete(head, 50);
	PrintList(head);
	ClearList(head);
	PrintList(head);*/

	std::system("pause");
	return 0;
}
