
#include <iostream>


using namespace std;

long fac(long n)
{
	int result=1, i;
	if(n>0)
		for(i=n; i>0; i--)
			result*=i;
	return result;
}

long fact(long n)
{
	if(n==0)
		return 1;
	std::cout<<"do"<<std::endl;
	return fact(n-1)*n;
}

long fib(int n)
{
	if(n==1 || n==2)
		return 1;
	std::cout<<"do"<<std::endl;
	return fib(n-1)+fib(n-2);
}

void hanoi(int n, char *start, char *mid, char *end)
{
	if(n==1)
		std::cout<<start<<"-->"<<end<<endl;
	else
	{
		hanoi(n-1, start, end, mid);
		std::cout<<start<<"-->"<<mid<<std::endl;
		hanoi(n-1, mid, start, end);
	}
}

int main(int argc, char *argv[])
{
	//std::cout<<fact(3);
	//hanoi(3, "A", "B", "C");
	std::cout<<fib(5);
	std::system("pause");
	return 0;
}

