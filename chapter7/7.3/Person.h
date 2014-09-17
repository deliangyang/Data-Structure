
#define NAMELEN 50

struct Person
{
	char name[NAMELEN];
	int age;
	int height;
};

int operator==(Person& p1, Person& p2)
{
	return strcmp(p1.name, p2.name)==0;
}

void PrintPerson(Person person)
{
	std::cout<<person.name<<" "<<person.age<<" "<<person.height<<std::endl;
}
