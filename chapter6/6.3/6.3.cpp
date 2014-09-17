
#include <iostream>
#include "ModClass.h"

using namespace std;

void Solve(ModClass a, ModClass& x, ModClass b);

int main(int argc, char *argv[])
{
	ModClass a[]={ModClass(4), ModClass(10), ModClass(50)};
	for(int i=0; i<3; i++)
		std::cout<<a[i]<<" "<<int(a[i])<<std::endl;

	ModClass a1(4);
	ModClass x(0);
	ModClass b(3);
	Solve(a1, x, b);
	std::cout<<"ModClass(4)*x=ModClass(3): ";
	std::cout<<x<<std::endl;
	std::system("pause");
	return 0;
}

void Solve(ModClass a, ModClass& x, ModClass b)
{
	x=b*a.Inverse(a);
}
