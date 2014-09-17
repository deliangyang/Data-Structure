
#include "Complex.h"

Complex::Complex(double real, double imag):real(real),imag(imag){}

Complex Complex::operator*(Complex x)const
{
	double r=real*x.real-imag*x.imag;
	double i=real*x.imag+imag*x.real;
	return(Complex(r, i));
}

Complex Complex::operator+(Complex x)const
{
	return(Complex(real+x.real, imag+x.imag));
}

Complex Complex::operator-(Complex x)const
{
	return(Complex(real-x.real, imag-x.imag));
}

Complex Complex::operator/(Complex x)const
{
	double temp=x.real*x.real+x.imag*x.imag;
	double r=(real*x.real + imag*x.imag)/temp;
	double i=(imag*x.real - real*x.imag)/temp;
	return(Complex(r, i));
}

Complex Complex::operator-(void)const
{
	return(Complex(-real, -imag));
}

std::ostream& operator<<(std::ostream& os, const Complex& x)
{
	os<<"("<<x.real<<", "<<x.imag<<")"<<std::endl;
	return os;
}
