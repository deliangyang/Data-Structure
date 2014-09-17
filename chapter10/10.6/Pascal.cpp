
#include <iostream>

using namespace std;

int f(int i, int j)
{
	int a;
	if(j==1 || i==j)
		a=1;
	else
		a=f(i-1, j-1)+f(i-1, j);
	return a;
}

void Pascal(int n)
{
	n=n+1;
	int i, j;
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=i; j++)
		{
			if(i==n)
			{
				std::cout<<f(i, j)<<"x ** "<<n-j;
				if(j<i)
					std::cout<<" + ";
			}
		}															//std::cout<<f(i, j)<<" ";
																//std::cout<<std::endl;
	}

/*	int i, j;
	for(i=1; i<=n+1; i++)
	{
		for(j=0; j<i; j++)
		{
			std::cout<<i<<" ";
		}
		std::cout<<std::endl;
	}*/
}

int main(int argc, char *argv[])
{
	std::cout<<"Complete square difference"<<std::endl;
	Pascal(2);
	std::cout<<endl;
	
	std::system("pause");
	return 0;
}
