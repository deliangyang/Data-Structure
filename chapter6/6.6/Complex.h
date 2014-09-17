
#ifndef _COMPLEX_H
#define _COMPLEX_H

#include <fstream>

class Complex
{
public:
	Complex(double real=0.0, double imag=0.0);
    Complex operator*(Complex x)const;
    Complex operator+(Complex x)const;
    Complex operator-(Complex x)const;
    Complex operator/(Complex x)const;

    Complex operator-(void)const;

    friend std::ostream& operator<<(std::ostream& os, const Complex& x);
private:
	double real;
	double imag;
};

#endif

