

class Base
{
public:
	Base(void)
	{
		std::cout<<"Base constructor called"<<std::endl;
	}
	virtual ~Base(void)
	{
		std::cout<<"Base Destructor called"<<std::endl;
	}
};


class Derived:public Base
{
public:
	Derived(void)
	{
		std::cout<<"Derived constructor called"<<std::endl;
	}
	~Derived(void)
	{
		std::cout<<"Derived Destructor called"<<std::endl;
	}
};



