
#include <iostream>

using namespace std;

struct Year
{
	int yy;
	int mm;
	int dd;
};

class Calendar
{
public:
	Calendar(Year year, int leapyr);
	int NumDays(int mm, int dd);
	int Leapyear(void)const;
	void PrintDate(int days);
private:
	Year year;
	int leapyr;
};

Calendar::Calendar(Year year, int leapyr)
{
	this->year=year;
	this->leapyr=leapyr;
}

int Calendar::NumDays(int mm, int dd)
{
	unsigned int monthday[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int i=mm-1;
	int j=year.mm-1;
	int totalDays=0;
	int toyear=0;
	while(i)
	{
		i--;
		totalDays+=monthday[i];
	}
	totalDays+=dd;
	while(j)
	{
		j--;
		toyear+=monthday[i];
	}
	toyear+=year.dd;
	if(leapyr && mm>2)
		totalDays+=1;
	if(leapyr && year.mm>2)
		toyear+=1;
	if(toyear>totalDays)
		return -1;
	totalDays-=toyear;
	
	return totalDays;
}

void Calendar::PrintDate(int days)
{
	Year years;
	unsigned int monthday[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	years.yy=year.yy;
	int i=0;
	if(Leapyear())
			monthday[1]=29;
	while(days>monthday[i])
	{
		days-=monthday[i];
		i++;
	}
	years.mm=i+1;
	years.dd=days;
	std::cout<<years.yy<<"/"<<years.mm<<"/"<<years.dd<<std::endl;
}

int Calendar::Leapyear(void)const
{
	return ((year.yy%400==0 || year.yy%4==0) && (year.yy%100!=0));
}

int main(int argc, char *argv[])
{
	Year year={2012, 1, 0};
	Calendar calendar(year, 1);
	std::cout<<"is leap year(1 yes): "<<calendar.Leapyear()<<std::endl;	
	std::cout<<"Christmas day: "<<calendar.NumDays(12, 25)<<std::endl;
	calendar.PrintDate(calendar.NumDays(12, 25));
	Year today={2014, 7, 29};
	Calendar tod(today, 0);
	std::cout<<"today to Christmas day: "<<tod.NumDays(12, 25)<<std::endl;
	Year twos={2014, 2, 1};
	Calendar two(twos, 0);
	std::cout<<"2.1-3.1: "<<two.NumDays(3, 1)<<std::endl;
	std::system("pause");
	return 0;
}
