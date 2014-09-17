
#include <iostream>

int main(int argc, char *argv[])
{
	double D=1.0;
	double level=10.0;
	while(1+D!=1.0)
	{
		D=1/level;
		level*=10;
		std::cout<<"D: "<<D<<", level: "<<level<<std::endl;
	}

	std::system("pause");
	return 0;
}

