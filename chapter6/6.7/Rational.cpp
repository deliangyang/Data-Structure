
#include "Rational.h"

Rational::Rational(int num, long den):num(num), den(den)
{
	if(den==0)
	{
		std::cerr<<"den can't be zero"<<std::endl;
		exit(0);
	}
}

Rational::Rational(double x)
{
	double val1, val2;	
	val1=100000000L*x;
	val2=10000000L *x;
	num=long(val1-val2);
	den= 90000000L;
	Reduce();
}

void Rational::Reduce(void)
{
	int bigdivisor, tempnumberator;
	tempnumberator=(num<0)?-num:num;
	if(num==0)
		den=1;
	else
	{
		bigdivisor=gcd(tempnumberator, den);
		if(bigdivisor>1)
		{
			num/=bigdivisor;
			den/=bigdivisor;
		}
	}
}

long Rational::gcd(long n, long m)const
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

std::ostream& operator<<(std::ostream& os, const Rational& rational)
{
	os<<rational.num<<"/"<<rational.den;
	return os;
}


Rational Rational::operator-(Rational r2)const
{
	Rational temp;
	temp.num=num*r2.den-den*r2.num;
	temp.den=den*r2.den;
	temp.Reduce();
	return temp;
}

Rational::operator double(void)const
{
	return double(num)/den;
}

