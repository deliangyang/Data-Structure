#include <iostream>

struct Month
{
	char name[10];
	int monthnum;
};

int operator >(Month& month1, Month& month2);

template<class T>
void ExchangeSort(T a[], int n)
{
	int i, j;
	T temp;
	for(i=0; i<n-1; i++)
	{
		for(j=0; j<n-i-1; j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}

void SortByName(Month months[], int n);
void SortByDays(Month months[], int n);
void Sort2ByDays(Month months[], int n);
void PrintMonth(Month months[], int n);
int isDayEqual(Month months[], int n);

#define LEN 4

int main(int argc, char *argv[])
{
	Month month[LEN]={{"May", 31},{"June", 30}, {"Feb", 28}, {"Jan", 32}};
	PrintMonth(month, LEN);
	std::cout<<std::endl;
	std::cout<<"Sort By Name"<<std::endl;
	SortByName(month, LEN);
	PrintMonth(month, LEN);
	std::cout<<std::endl;
	std::cout<<"Sort By Days"<<std::endl;
	SortByDays(month, LEN);
	PrintMonth(month, LEN);

	std::cout<<std::endl;
	std::cout<<"Adjust month.monthnum is equal, yes: do sort name"<<std::endl;
	Month month2[LEN]={{"May", 31},{"June", 31}, {"Feb", 31}, {"Jan", 31}};
	PrintMonth(month2, LEN);
	std::cout<<std::endl;
	std::cout<<"Because of the same days"<<std::endl;
	Sort2ByDays(month2, LEN);
	PrintMonth(month2, LEN);

	std::system("pause");
	return 0;
}

int operator >(Month& month1, Month& month2)
{
	if(strcmp(month1.name, month2.name)>0)
		return 1;
	return 0;
}

void SortByName(Month months[], int n)
{
	ExchangeSort(months, n);
}

void SortByDays(Month months[], int n)
{
	int i, j;
	Month temp;
	for(i=0; i<n-1; i++)
	{
		for(j=0; j<n-i-1; j++)
		{
			if(months[j].monthnum>months[j+1].monthnum)
			{
				temp=months[j];
				months[j]=months[j+1];
				months[j+1]=temp;
			}
		}
	}
}

void Sort2ByDays(Month months[], int n)
{
	if(isDayEqual(months, LEN))
		SortByName(months, n);
	else
		SortByDays(months, n);
}

void PrintMonth(Month months[], int n)
{
	int i;
	for(i=0; i<n; i++)
		std::cout<<months[i].name<<": "<<months[i].monthnum<<std::endl;
}

int isDayEqual(Month months[], int n)
{
	Month month;
	int i;
	for(i=1; i<n; i++)
	{
		month=months[0];
		if(months[i].monthnum!=month.monthnum)
			return 0;
	}
	return 1;
}
