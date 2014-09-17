
#include <iostream>

#include "Person.h"
#include "DataStore.h"

using namespace std;

int main(int argc, char *argv[])
{
	DataStore<Person> data;
	Person person[5]={{"lili", 20, 168}, {"72hn", 25, 72}, {"xiaomi", 31, 176},
								{"xixi", 18, 167}, {"lisai", 20, 170}};
	int i;
	for(i=0; i<5; i++)
		data.Insert(person[i]);

	int index=data.Find(person[1]);
	if(index!=-1)
		PrintPerson(person[index]);
	std::system("pause");
	return 0;
}
