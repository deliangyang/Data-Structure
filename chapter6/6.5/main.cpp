
#include <iostream>
#include "Vector.h"

using namespace std;

int main(int argc, char *argv[])
{
	double a, b;
	std::cout<<"a, b: ";
	std::cin>>a>>b;
	Vector vector(a, b);
	Vector vector1(b, -a);
	std::cout<<vector;
	std::cout<<vector1;
	if(vector1*vector==0)
		std::cout<<"there are vertival"<<std::endl;
	else
		std::cout<<"there are not vertival"<<std::endl;
	std::system("pause");
	return 0;
}
