
#include <iostream>
#include <string.h>

enum DaysOfWeek{Sun, Mon, Tues, Wed, Thurs, Fri, Sat};
const char *days[]={"Sun", "Mon", "Tues", "Wed", "Thurs", "Fri", "Sat"};

void GetDay(DaysOfWeek& day);
void PutDay(DaysOfWeek day);

int main(int argc, char *argv[])
{
	DaysOfWeek day;
	GetDay(day);
	PutDay(day);

	std::system("pause");
	return 0;
}

void GetDay(DaysOfWeek& day)
{
	char Days[10];
	int i;
	std::cout<<"Enter your day(Sun, Mon, Tues, and so on): ";
	std::cin>>Days;
	for(i=0; i<7; i++)
		if(strcmp(Days, days[i])==0)
		{
			day=(DaysOfWeek)i;
			break;
		}
}

void PutDay(DaysOfWeek day)
{
	std::cout<<"Get the day: "<<days[day]<<std::endl;
}
