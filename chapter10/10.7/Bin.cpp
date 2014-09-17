
#include <iostream>

using namespace std;


int count=0;

void Bin(long n, int b)
{
	if(n==0)
		return;
	else
	{
		Bin(n/b, b);
		std::cout<<n%b;
		if(count%2==0 && n%b==1)						// 第一位为1开始
		{
			if(n%b==1)
		}
		count++
		return;
	}
}

int main(int argc, char *argv[])
{


	
	std::system("pause");
	return 0;
}
