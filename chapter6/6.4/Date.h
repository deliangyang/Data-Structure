
#include <string>
#include <strstream>

using namespace std;

class Date
{
public:
	Date(int month=1, int day=1, int year=0);
	Date(char *dstr);
	void PrintDate(void);
	friend int operator>(Date& date1, Date& date2);
	//friend int operator<=(Date& date1, Date& date2)const;
	//friend int operator!=(Date& date1, Date& date2)const;
private:
	int month;
	int day;
	int year;
};

Date::Date(int month, int day, int year):month(month),day(day)
{
	this->year=year+1900;
}

//   format month-day-year
Date::Date(char *dstr)
{
	char buffer[16];
	char ch;
	strcpy(buffer, dstr);
	istrstream input(buffer, sizeof(buffer));
	input>>month>>ch>>day>>ch>>year;
	year+=1900;
}

void Date::PrintDate(void)
{
	std::cout<<month<<"/"<<day<<"/"<<year<<std::endl;
}

int operator>(Date& date1, Date& date2)
{
	if(date1.year>date2.year)
		return 0;
	else if(date1.year<date2.year)
		return 1;
	else			// year equal
	{
		if(date1.month>date2.month)
			return 0;
		else if(date1.month<date2.month)
			return 1;
		else
		{
			if(date1.day>date2.day)
				return 0;
			else
				return 1;
		}
	}
}
