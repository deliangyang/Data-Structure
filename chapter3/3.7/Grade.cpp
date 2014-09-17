
#include <iostream>
#include <string.h>

using namespace std;

class Grade
{
public:
	Grade(char student[], float score);
	Grade(void);
	int Compare(char s[]);
	void Read(void);
	void Write(void);
private:
	char name[30];
	float score;
};

Grade::Grade(char student[], float score)
{
	strcpy(this->name, student);
	this->score=score;
}

Grade::Grade(void)
{
	name[0]='\0';
	score=0.0;
}

int Grade::Compare(char s[])
{
	return strcmp(name, s)==0;
}

void Grade::Read(void)
{
	std::cout<<name<<": "<<score<<std::endl;
}

int Search(Grade Arr[], int n, char keyname[]);

int main(int argc, char *argv[])
{
	int i;
	int index;
	char name[30];
	Grade students[5]={Grade("John", 78.3), Grade("Sally", 86.5), 
					Grade("Lili", 70.4), Grade("Bob", 58.9), Grade("Donna", 98.3)};
	students[4].Read();

	for(i=0; i<3; i++)
	{
		std::cout<<"Enter your find name: ";
		std::cin>>name;
		index=Search(students, 5, name);
		if(index>=0)
			students[i].Read();
		else
			std::cout<<"Sorry, con't find!"<<std::endl;
	}
	std::system("pause");
	return 0;
}

int Search(Grade Arr[], int n, char keyname[])
{
	int i;
	//Grade grade=Arr[0];
	for(i=0; i<n; i++)
		if(Arr[i].Compare(keyname))
			return i;
	return -1;
}
