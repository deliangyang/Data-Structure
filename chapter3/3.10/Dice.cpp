
#include <iostream>
#include <time.h>

using namespace std;

class Dice
{
public:
	Dice(void);
	Dice(int n);
	~Dice(void);
	void Toss(void);
	int Total(void)const;
	void DisplayToss(void);
private:
	int * arr;
	int n;
};

Dice::Dice(void)
{
	n=2;
	arr=new int[2];
}

Dice::Dice(int n)
{
	this->n=n;
	arr=new int[n];
}

Dice::~Dice(void)
{
	delete[] arr;
}

void Dice::Toss(void)
{
	int i;
	srand((unsigned int)rand()%1000);
	for(i=0; i<n; i++)
		arr[i]=(rand()%6+1);
}

int Dice::Total(void)const
{
	int i;
	int result=0;
	for(i=0; i<n; i++)
		result+=arr[i];
	return result;
}

void Dice::DisplayToss(void)
{
	int i;
	for(i=0; i<n; i++)
		std::cout<<arr[i]<<" ";
	std::cout<<std::endl;
}

int operator>(Dice& dice1, Dice& dice2)
{
	return dice1.Total()>dice1.Total();
}

void Sort(Dice *arr[], int n)
{
	Dice * temp;
	temp=new Dice(5);
	int i, j;
	for(i=0; i<n-1; i++)
	{
		for(j=0; j<n-i-1; j++)
		{
			if(arr[j]->Total()>arr[j+1]->Total())
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

int sum(Dice * arr[], int n)
{
	int result=0;
	int i;
	for(i=0; i<n; i++)
		result+=arr[i]->Total();
	return result;
}

int main(int argc, char *argv[])
{
	//Dice dice(5);
	int countRepeat[30];
	memset(countRepeat, 0, sizeof(int)*30);
	int count=0;
	Dice *dice[30];
	int i;
	for(i=0; i<30; i++)
		dice[i]=new Dice(5);
	for(i=0; i<30; i++)
		dice[i]->Toss();


	for(i=0; i<30; i++)
		if(dice[i]->Total()==5 || dice[i]->Total()==12)
			count++;
	std::cout<<"5 and 12 has been toss: "<<count<<std::endl;


	for(i=0; i<30; i++)
		countRepeat[dice[i]->Total()]++;
	for(i=0; i<30; i++)
	{
		if(countRepeat[i]>1)
			std::cout<<i<<" has been repeat: "<<countRepeat[i]-1<<" times"<<std::endl;
	}

	// fantastic really, i can't continue
	Dice * temp;
	temp=new Dice(5);
	temp=dice[0];
	for(i=1; i<30; i++)
		if(dice[i]->Total()>temp->Total())
			temp=dice[i];
	std::cout<<"max total: "<<temp->Total()<<std::endl;

	// sort them
	Sort(dice, 30);
	std::cout<<"total sort: ";
	for(i=0; i<30; i++)
		std::cout<<dice[i]->Total()<<" ";
	std::cout<<std::endl;
	std::cout<<"sum: "<<sum(dice, 30)<<std::endl;


	for(int i=0; i<30; i++)
		delete dice[i];
	//for(i=0; i<30; i++)
	//	dice[i]->DisplayToss();
	std::system("pause");
	return 0;
}

