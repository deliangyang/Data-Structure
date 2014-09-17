
#include <iostream>


using namespace std;

int add(int a, int b)
{
	return a+b;
}

int main(int argc, char *argv[])
{
	int count;
	int i;
	int a, b;
	cin>>count;
	for(i=0; i<count; i++)
	{
		cin>>a>>b;
		cout<<add(a, b);
	}
	
	return 0;
}
