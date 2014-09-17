
#include <iostream>

using namespace std;

const double PI=3.14;

class Circle
{
public:
	Circle(double r);
	Circle(double r, double angle=0);
	double Area(void)const;
	double Perimeter(void)const;
private:
	double r;
	double angle;
};

Circle::Circle(double r)
{
	this->angle=0;
	this->r=r;
}

Circle::Circle(double r, double angle)
{
	this->r=r;
	this->angle=angle;
}

double Circle::Area(void)const
{
	if(angle==0)
		return PI*r*r;
	return (angle/360)*PI*r*r;
}

double Circle::Perimeter(void)const
{
	double per=2*PI*r;
	if(angle==0)
		return per;
	return per*(angle/300)+2*r;
}

int main(int argc, char *argv[])
{
	double angle=30;
	double area;
	double rolls;
	double cost;
	Circle circle(100, angle);
	area=circle.Area();
	rolls=area/16;
	cost=rolls*4.00;
	std::cout<<"cost: "<<cost<<std::endl;
	std::system("pause");
	return 0;
}
