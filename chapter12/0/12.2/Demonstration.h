

class Base1
{
public:
	Base1(void)
	{
		std::cout<<"Base1 constructor called"<<std::endl;
	}
	~Base1(void)
	{
		std::cout<<"Base1 destructor called"<<std::endl;
	}
};

class Base2
{
public:
	Base2(void)
	{
		std::cout<<"Base2 constructor called"<<std::endl;
	}
	~Base2(void)
	{
		std::cout<<"Base2 destructor called"<<std::endl;
	}
};

class Derived:public Base1, public Base2
{
public:
	Derived(void):Base1(),Base2()
	{
		std::cout<<"Derived class constructor called"<<std::endl;
	}
	~Derived(void)
	{
		std::cout<<"Derived class destructor called"<<std::endl;
	}
};


