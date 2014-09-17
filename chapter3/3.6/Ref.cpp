
#include <iostream>

using namespace std;

class Ref
{
public:
	Ref(void);
	void Count(int x);
	void Write(void);
private:
	int positiveCount;
	int negativeCount;
};

Ref::Ref(void):positiveCount(0),negativeCount(0){}

void Ref::Count(int x)
{
	if(x>0)
		positiveCount++;
	else if(x<0)
		negativeCount++;
}

void Ref::Write(void)
{
	std::cout<<"positiveCount: "<<positiveCount<<", negativeCount: "<<negativeCount<<std::endl;
}

void PassByValue(Ref v);
void PassByReference(Ref& ref);

int main(int argc, char *argv[])
{
	Ref ref;
	Ref ref1;
	std::cout<<"By Reference: "<<std::endl;
	PassByReference(ref);
	ref.Write();
	std::cout<<"By Value: "<<std::endl;
	PassByValue(ref1);
	ref1.Write();
	std::system("pause");
	return 0;
}


void PassByValue(Ref ref)
{
	int num;
	int i;
	std::cout<<"Please enter number to adjust is positive or negative: "<<std::endl;
	for(i=0; i<5; i++)
	{
		cin>>num;
		ref.Count(num);
	}
}

void PassByReference(Ref& ref)
{
	int num;
	int i;
	std::cout<<"Please enter number to adjust is positive or negative: "<<std::endl;
	for(i=0; i<5; i++)
	{
		cin>>num;
		ref.Count(num);
	}
}
