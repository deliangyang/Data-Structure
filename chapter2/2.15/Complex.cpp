
#include <iostream>

using namespace std;

class Complex
{
public:
	float real;
	float imag;
	Complex();
	Complex(float real, float imag);
	Complex cadd(Complex& x, Complex& y);
	Complex csub(Complex& x, Complex& y);
	Complex cmul(Complex& x, Complex& y);
	Complex cdiv(Complex& x, Complex& y);
	void Display(void);
private:
};

Complex::Complex():real(0.0),imag(0.0)
{}

Complex::Complex(float real, float imag)
{
	this->real=real;
	this->imag=imag;
}

Complex Complex::cadd(Complex& x, Complex& y)
{
	Complex complex;
	complex.real=x.real+y.real;
	complex.imag=y.imag+y.imag;
	return complex;
}

Complex Complex::csub(Complex& x, Complex& y)
{
	Complex complex;
	complex.real=x.real-y.real;
	complex.imag=y.imag-y.imag;
	return complex;
}

Complex Complex::cmul(Complex& x, Complex& y)
{
	Complex complex;
	complex.real=x.real*y.real-x.imag*y.imag;
	complex.imag=x.real*y.imag+x.imag*y.real;
	return complex;
}

Complex Complex::cdiv(Complex& x, Complex& y)
{
	Complex complex;
	float mul=y.real*y.real+y.imag*y.imag;
	complex.real=(x.real*y.real+x.imag*y.imag)/mul;
	complex.imag=(x.imag*y.real-x.real*y.imag)/mul;
	return complex;
}

void Complex::Display(void)
{
	std::cout<<"("<<real<<", "<<imag<<")"<<std::endl;
}

void GetF(Complex complex);

int main(int argc, char *argv[])
{
	Complex complex1(2.0, 3.0);
	GetF(complex1);
	std::cout<<std::endl;
	Complex complex2(-1.0, 1.0);
	GetF(complex2);
	std::cout<<std::endl;
	std::cout<<"The last three complex is the F(z)'s root"<<std::endl;
	Complex complex3(1.0, 1.0);
	GetF(complex3);
	std::cout<<std::endl;
	Complex complex4(1.0, -1.0);
	GetF(complex4);
	std::cout<<std::endl;
	Complex complex5(1.0, 0.0);
	GetF(complex5);
	std::cout<<std::endl;
	std::system("pause");
	return 0;
}


void GetF(Complex complex)
{
	std::cout<<"f(z)=z^3-3*z^2+4*z-2 and z=("<<complex.real<<", "<<complex.imag<<")"<<std::endl;
	//Complex complex(2.0, 3.0);
	Complex r;
	Complex r1;
	Complex r2;
	Complex r3;
		
	Complex result;
	r=r.cmul(complex, complex);
	r1=r1.cmul(r, complex);

	// (3, 0)*z*z
	Complex r5(3, 0);
	r2=r2.cmul(r5, r);
	
	// (4, 0)*z
	Complex r6(4, 0);
	r3=r3.cmul(r6, complex);
	// (2, 0)
	result=result.csub(r1, r2);
	result=result.cadd(result, r3);
	Complex r4(2, 0);
	result=result.csub(result, r4);
	result.Display();
}
