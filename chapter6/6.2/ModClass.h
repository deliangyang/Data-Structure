
class ModClass
{
public:
	ModClass(int a);
	ModClass operator+(ModClass& a)const;
	ModClass operator*(ModClass& a)const;
	operator int(void);
	ModClass Inverse(ModClass& x);
	int GetValue(void)const
	{
		return a;
	}
private:
	int a;
};

ModClass::ModClass(int a)
{
	this->a=a;
}
ModClass ModClass::operator*(ModClass& a)const
{
	return this->a*a.a;
}
ModClass ModClass::operator+(ModClass& a)const
{
	return this->a+a.a;
}

ModClass::operator int(void)
{
	return this->a;
}

ModClass ModClass::Inverse(ModClass& x)
{
	return 1/x;
}
