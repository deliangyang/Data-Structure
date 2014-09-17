
#include <iostream>

using namespace std;

enum Sex{M, F};

const char sex[]={'M', 'F'};

class Info
{
public:
	Info(const char sex);
	int GetId(void)const;
	int GetAge(void)const;
	char GetSex(void)const;
	void Read(int id, int age, char sex);
	void Print(void);
private:
	int id;
	int age;
	char sex;
};

Info::Info(const char sex)
{
	id=0;
	age=0;
	this->sex=sex;
}

void Info::Read(int id, int age, char sex)
{
	this->id=id;
	this->age=age;
	this->sex=sex;
}

void Info::Print(void)
{
	std::cout<<"id: "<<id<<", age: "<<age<<", sex: "<<sex<<std::endl;
}

int Info::GetId(void)const
{
	return id;
}
int Info::GetAge(void)const
{
	return age;
}
char Info::GetSex(void)const
{
	return sex;
}

int operator>(Info& info1, Info& info2)
{
	return (info1.GetAge()>info2.GetAge() && (info1.GetAge()>0 && info2.GetAge()>0));
}

int operator<(Info& info1, Info& info2)
{
	return info1.GetAge()<info2.GetAge();
}


int main(int argc, char *argv[])
{
	std::cout<<"Change the young women and old man: "<<std::endl;
	Info youngWomen('F');
	Info oldMan('M');
	Info temp('M');
	int id, age;
	char sex;
	std::cout<<"Enter info(0 quit): ";
	std::cout<<"id: ";
	while(std::cin>>id && id!=0)
	{
		std::cout<<"age: ";
		std::cin>>age;
		std::cout<<"sex(M or F): ";
		std::cin>>sex;

		temp.Read(id, age, sex);
		if(sex=='M')
		{
			if(oldMan<temp)
				oldMan=temp;
			else
				oldMan.Read(id, age, sex);
		}
		if(sex=='F')
		{
			if(youngWomen>temp)
				youngWomen=temp;
			else
				youngWomen.Read(id, age, sex);
		}

		std::cout<<"Enter info(0 quit): ";
		std::cout<<"id: ";
	}
	oldMan.Print();
	youngWomen.Print();
	std::system("pause");
	return 0;
}
