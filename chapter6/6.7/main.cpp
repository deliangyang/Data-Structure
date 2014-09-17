
#include <iostream>
#include "Rational.h"

using namespace std;

long gcd(long n, long m)
{
	int result=1;
	int remain=1;
	while(remain)
	{
		remain=n%m;
		n=m;
		if(remain==0)
			result=m;
		m=remain;
	}
	return result;
}

const double PI=3.14159265;

int main(int argc, char *argv[])
{
	Rational rational(PI);
	Rational temp;
	temp=rational-Rational(22, 7);
	std::cout<<temp<<std::endl;
	//rational.Reduce();

	std::cout<<PI-float(Rational(22, 7))<<std::endl;
	std::system("pause");
	return 0;
}
