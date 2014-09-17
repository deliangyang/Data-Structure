
#define NAME 20

struct Person
{
	char name[NAME];
	int age;
	char gender;
};

int operator==(Person x, Person y)
{
	return strcmp(x.name, y.name)==0;
}
