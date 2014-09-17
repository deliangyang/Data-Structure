

#ifndef _RATIONAL_H
#define _RATIONAL_H

#include <iostream>
#include <fstream>

class Rational
{
public:
	Rational(int num=0, long den=1);
	Rational(double x);
  	void Reduce(void);
  	Rational operator-(Rational r2)const;
  	operator double(void)const;
  	
  	friend std::ostream& operator<<(std::ostream& os, const Rational& rational);
private:
	long num;
	long den;
	long gcd(long n, long m)const;

};

#endif
