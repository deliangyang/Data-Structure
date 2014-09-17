

#ifndef __PRINT_H__
#define __PRINT_H__

class Print
{
public:
	Print(void);
	void Identify(void);
};

Print::Print(void)
{
	std::cout<<"Base Print construtor called"<<std::endl;
}

void Print::Identify(void)
{
	std::cout<<"Base Print Identify called"<<std::endl;
}

class Derived:public Print
{
public:
	Derived(void);
	void Identify(void);
};

Derived::Derived(void)
{
	std::cout<<"Derived construtor called"<<std::endl;
}

void Derived::Identify(void)
{
	std::cout<<"Derived Identify called"<<std::endl;
	Print::Identify();
}

#endif


