
#include <iostream>

using namespace std;

#define NAMELEN 30

enum unit{metric, English};


// 1 inch to 2.54cm
class Height
{
public:
	Height();
	Height(char nm[], float h, unit m);
	void PrintHeight(void);
	void ReadHeight(void);
	float GetHeight(void)const;
	void Convert(unit m);			// change the unit
private:
	char name[NAMELEN];
	unit measureType;
	float h;
};

Height::Height()
{
	memset(name, 0, NAMELEN);
	measureType=metric;
	h=0;
}

Height::Height(char nm[], float h, unit m)
{
	strcpy(this->name, nm);
	this->h=h;
	measureType=m;
}

void Height::PrintHeight(void)
{
	std::cout<<name<<" "<<h<<std::endl;
}

void Height::ReadHeight(void)
{
	float h;
	char name[NAMELEN];
	unit m;

	std::cout<<"name: ";
	std::cin>>name;
	std::cout<<"h: ";
	std::cin>>h;
	std::cout<<"m: ";
	std::cin>>(int&)m;

	this->h=h;
	this->measureType=m;
	strcpy(this->name, name);
}

void Height::Convert(unit m)
{
	if(measureType!=m && m==English)		// measureType == metric
		h=1/2.54*h;
	if(measureType!=m && m==metric)
		h=2.54*h;
}

float Height::GetHeight(void)const
{
	return h;
}

void ChangeUnit(Height height[], int n, unit u);
void SortHeight(Height height[], int n);
Height FindMax(Height height[], int n);


#define ARRAYLEN 5

int main(int argc, char *argv[])
{
	int i;
	Height height[ARRAYLEN];
	Height temp;
	height[0]=Height("li", 144.1, English);
	height[1]=Height("wang", 182.13, metric);
	height[2]=Height("system", 183.1, metric);
	height[3].ReadHeight();
	height[4].ReadHeight();
	ChangeUnit(height, ARRAYLEN, metric);
	for(i=0; i<ARRAYLEN; i++)
		height[i].PrintHeight();

	SortHeight(height, ARRAYLEN);
	for(i=0; i<ARRAYLEN; i++)
		height[i].PrintHeight();

	temp=FindMax(height, ARRAYLEN);
	std::cout<<"max: "<<temp.GetHeight()<<std::endl;


	std::system("pause");
	return 0;
}

void ChangeUnit(Height height[], int n, unit u)
{
	int i;
	for(i=0; i<n; i++)
		height[i].Convert(u);
}

void SortHeight(Height height[], int n)
{
	int i, j;
	Height hgt;
	for(i=0; i<n-1; i++)
		for(j=0; j<n-i-1; j++)
		{
			if(height[j].GetHeight()>height[j+1].GetHeight())
			{
				hgt=height[j];
				height[j]=height[j+1];
				height[j+1]=hgt;
			}
		}
}

Height FindMax(Height height[], int n)
{
	int i;
	Height hgt;
	for(i=1; i<n; i++)
	{
		hgt=height[0];
		if(hgt.GetHeight()<height[i].GetHeight())
			hgt=height[i];
	}
	return hgt;
}

