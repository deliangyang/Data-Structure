

#include <iostream>
#include "Complex.h"

using namespace std;

void CountComplex(Complex complex);

int main(int argc, char *argv[])
{
	Complex complex(0, 1);
	std::cout<<"i^2 is or not -1: "<<complex*complex;

	int i;
	Complex root[5]={Complex(2, 3),	Complex(-1, 1),
					Complex(1, 1),	Complex(1, -1),
					Complex(1, 0),
				};
	for(i=0; i<5; i++)
	{
		std::cout<<root[i]<<" result: ";
		CountComplex(root[i]);
	}

	
	std::system("pause");
	return 0;
}


void CountComplex(Complex complex)
{
	Complex temp;
	temp=complex*complex*complex-complex*complex*Complex(3, 0)+complex*Complex(4, 0)-Complex(2, 0);
	std::cout<<temp;
}
