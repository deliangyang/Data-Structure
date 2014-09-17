
#include <iostream>

#include "../SeqList.h"
#include "../Array.h"
#include "../SeqListIterator.h"
#include "../ArrayIterator.h"

using namespace std;

char Max(SeqList<char> &list)
{
	SeqListIterator<char> iterator(list);
	char temp='a';
	for(iterator.Reset(); !iterator.EndOfList(); iterator.Next())
		if(temp<iterator.Data())
			temp=iterator.Data();
	return temp;
}

int Max(Array<int> &arr)
{
	ArrayIterator<int> iterator(arr);
	int temp=0;
	for(iterator.Reset(); !iterator.EndOfList(); iterator.Next())
		if(temp<iterator.Data())
			temp=iterator.Data();
	return temp;
}

int main(int argc, char *argv[])
{
	Array<int> arr(10);
	SeqList<char> list;
	int i;
	for(i=0; i<10; i++)
		arr[i]=i+1;
	for(i=0; i<5; i++)
		list.Insert(char('a'+i));

	std::cout<<"array max: "<<Max(arr)<<std::endl;
	std::cout<<"seqlist max: "<<Max(list)<<std::endl;

	std::system("pause");
	return 0;
}
