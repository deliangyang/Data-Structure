

#ifndef __TWOKEY_H__
#define __TWOKEY_H__

struct TwoKey
{
	int primary;
	int secondary;
};

void initTwoKey(TwoKey twoKey[], int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		twoKey[i].primary=rand()%10;
		twoKey[i].secondary=rand()%100;
	}
}

void SortPrimary(TwoKey twoKey[], int n)
{
	int i, j;
	int temp;
	int index;
	for(i=1; i<n; i++)
	{
		j=i;
		temp=twoKey[i].primary;
		while(j>0 && temp<twoKey[j-1].primary)
		{
			twoKey[j].primary=twoKey[j-1].primary;
			j--;
		}
		twoKey[j].primary=temp;
	}
}

void SortSecondary(TwoKey twoKey[], int n)
{
	int i, j;
	int temp;
	int index;
	for(i=1; i<n; i++)
	{
		j=i;
		temp=twoKey[i].secondary;
		while(j>0 && temp<twoKey[j-1].secondary)
		{
			twoKey[j].secondary=twoKey[j-1].secondary;
			j--;
		}
		twoKey[j].secondary=temp;
	}
}

void PrintTwoKey(TwoKey twoKey[], int n)
{
	int i;
	for(i=0; i<n; i++)
		std::cout<<twoKey[i].primary<<"("<<twoKey[i].secondary<<")"<<"\t";
	std::cout<<std::endl;
}

#endif

