
#include <iostream>
#include <string.h>

class Base
{
public:
	Base(char s[], int m=0):n(m)
	{
		strcpy(msg, s);
	}
	void OutPut(void)
	{
		std::cout<<n<<" "<<msg<<std::endl;
	}
private:
	char msg[30];
protected:
	int n;
};

class Derivedl:public Base
{
public:
	Derivedl(int m=1):Base("Base", m-1), n(m)
	{}
	void OutPut(void)
	{
		std::cout<<n<<" ";
		Base::OutPut();
	}
private:
	int n;
};

class Derived2:public Derivedl
{
public:
	Derived2(int m=2):Derivedl(m-1), n(m)
	{}
	void OutPut(void)
	{
		std::cout<<n<<" ";
		Derivedl::OutPut();
	}	
private:
	int n;
};
