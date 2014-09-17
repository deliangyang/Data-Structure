
#include <iostream>

using namespace std;

class Accumulator
{
public:
	Accumulator();
	Accumulator(int n);
	void Add(int n);
	void Print(void);
	int data;
};
Accumulator::Accumulator():data(0){};
Accumulator::Accumulator(int n):data(n){};

void Accumulator::Add(int n)
{
	data=data+n;
}

void Accumulator::Print(void)
{
	std::cout<<data<<std::endl;
}


int main(int argc, char *argv[])
{
	int select=0;
	int balance;
	int debits=0;
	int credits=0;
	std::cout<<"Please init the Balance:";
	std::cin>>balance;
	Accumulator Balance(balance);
	Accumulator Debits(debits);				// jie
	Accumulator Credits(credits);			// dai
	std::cout<<"Enter 1 select debits(0, credits): ";
	std::cin>>select;
	while(Balance.data!=0)
	{
		if(select==1)
		{
			std::cout<<"debits how mach: ";
			std::cin>>debits;
			Debits.Add(-debits);
		}
		if(select==0)
		{
			std::cout<<"credits how mach: ";
			std::cin>>credits;
			Credits.Add(credits);
		}
		Balance.Add(-debits);
		Balance.Add(credits);
		std::cout<<"balance: ";
		Balance.Print();
		std::cout<<"debits:  ";
		Debits.Print();
		std::cout<<"credits: ";
		Credits.Print();
		std::cout<<std::endl;
		if(Balance.data!=0)
		{
			std::cout<<"Enter 1 select debits: ";
			std::cin>>select;
		}
		credits=0;
		debits=0;
	}
	std::system("pause");
	return 0;
}
