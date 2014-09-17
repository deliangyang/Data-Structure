
#include <iostream>
#include "SeqList.h"

using namespace std;


void PrintByGender(const SeqList& l, char sex)
{
	int i;
	for(i=0; i<l.Length(); i++)
		if(l.GetData(i).gender==sex)
			std::cout<<l.GetData(i).name<<" "
						<<l.GetData(i).age<<" "<<l.GetData(i).gender<<std::endl;
}

int Inlist(const SeqList& l, char *nm, Person& p)
{
	strcpy(p.name, nm);
	return (l.Find(p)!=-1);
}


void PrintList(SeqList& l)
{
	int i;
	for(i=0; i<l.Length(); i++)
		std::cout<<l.GetData(i).name<<" "
						<<l.GetData(i).age<<" "<<l.GetData(i).gender<<std::endl;
	std::cout<<std::endl;
}

int main(int argc, char *argv[])
{
	SeqList list;
	char name[20];
	Person p;
	Person person[3]={{"yang", 20, 'B'}, {"libai", 100, 'B'}, 
										{"lili", 24, 'G'}};
	int i;
	for(i=0; i<3; i++)
		list.Insert(person[i]);
	PrintList(list);

	std::cout<<"find name(1 yes): ";
	std::cin>>name;
	std::cout<<Inlist(list, name, p)<<std::endl;
	std::system("pause");
	return 0;
}
