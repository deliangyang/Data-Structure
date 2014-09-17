
#include <iostream>
#include <string>

using namespace std;

void Swap(double& a, double& b)
{
	double temp=a;
	a=b;
	b=temp;
}

void Swap(string& a, string& b)
{
	string temp=a;
	a=b;
	b=temp;
}



int main(int argc, char *argv[])
{
	double a, b;
	string str1, str2;
	std::cout<<"enter double: ";
	std::cin>>a>>b;
	std::cout<<"enter string: ";
	std::cin>>str1>>str2;
	std::cout<<a<<" "<<b<<std::endl;
	std::cout<<str1<<" "<<str2<<std::endl;
	Swap(a, b);
	Swap(str1, str2);
	std::cout<<a<<" "<<b<<std::endl;
	std::cout<<str1<<" "<<str2<<std::endl;
	std::system("pause");
	return 0;
}
