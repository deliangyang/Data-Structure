
#ifndef _STUDENT_H
#define _STUDENT_H

#define NAME 30

struct Test
{
	char name[NAME];
	int testNumber;
};

int operator==(const Test& a, const Test& b)
{
	return strcmp(a.name, b.name)==0;
}

#include "SeqLink.h"


void PutPapper(SeqLink<Test>& test)
{
	char name[NAME];
	Test t;
	std::cout<<"Enter your name: ";
	std::cin>>name;
	strcpy(t.name, name);
	std::cout<<"t.name: "<<t.name<<std::endl;
	t.testNumber=test.Size()+1;
	test.Insert(t);
}

void PrintPaper(SeqLink<Test>& test)
{
	Test t;
	for(int i=0; i<test.Size(); i++)
	{
		t=test.GetData(i);
		std::cout<<"id: "<<t.testNumber<<" "<<t.name<<std::endl;
	}
}

void BackPapper(SeqLink<Test>& submit, SeqLink<Test>& borrow)
{
	Test t;
	char name[NAME];
	std::cout<<"Enter your name: ";
	std::cin>>name;
	strcpy(t.name, name);
	std::cout<<"borrow.Find(t): "<<borrow.Find(t)<<std::endl;
	if(borrow.Find(t)==1)
	{
		borrow.Delete(t);
		t.testNumber=submit.Size()+1;
		submit.Insert(t);
	}
	else
		std::cout<<"no your name"<<std::endl;
}

void BorrowPapper(SeqLink<Test>& submit, SeqLink<Test>& borrow)
{
	Test t;
	char name[NAME];
	std::cout<<"Enter your name: ";
	std::cin>>name;
	strcpy(t.name, name);
	if(submit.Find(t)==1)
	{
		submit.Delete(t);
		t.testNumber=submit.Size()+1;
		borrow.Insert(t);
	}
	else
		std::cout<<"Sorry, no your paper"<<std::endl;
}

void ExitPaper(SeqLink<Test>& submit, SeqLink<Test>& borrow)
{
	int i;
	Test t;
	for(i=0; i<borrow.Size(); i++)
	{
		t=borrow.GetData(i);
		submit.Insert(t);
	}
	borrow.Clear();
	PrintPaper(submit);
}

#endif
