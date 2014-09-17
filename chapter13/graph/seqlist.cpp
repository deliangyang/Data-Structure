



#include "SeqList.h"

#include <iostream>


int main(int argc, char *aragv[])
{
	SeqList<int> list;
	int i;
	int temp;
	for(i=0; i<10; i++)
		list.Insert(i);
	//if((temp=list.Find(5))!=0)
	//	std::cout<<
	for(i=-1; i<11; i++)
		std::cout<<"Find: "<<list.Find(i)<<std::endl;
	std::system("pause");
	return 0;
}
