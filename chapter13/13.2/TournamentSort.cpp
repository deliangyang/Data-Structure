
#include <iostream>

#include <string>
#include "../toursort.h"

using namespace std;

int main(int argc, char *argv[])
{
	string str[]={"class", "object", "public", "private", "derived", "base", "inherit", "method", "contructor", "abstrct"};

	TournamentSort(str, 10);

	int i;
	for(i=0; i<10; i++)
		std::cout<<str[i]<<std::endl;

	std::system("pause");
	return 0;
}
