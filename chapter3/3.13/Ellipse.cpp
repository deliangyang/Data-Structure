
#include <iostream>

using namespace std;

const float PI=3.14;

class Ellipse
{
public:
	Ellipse(float a, float b);
	float Area(void)const;
private:
	float a;
	float b;
};

Ellipse::Ellipse(float a, float b):a(a),b(b){}

float Ellipse::Area(void)const
{
	return PI*a*b;
}

class Rectangle
{
public:
	Rectangle(float a, float b);
	float Area(void)const;
private:
	float a;
	float b;
};

Rectangle::Rectangle(float a, float b):a(a),b(b){}

float Rectangle::Area(void)const
{
	return a*b;
}

int main(int argc, char *argv[])
{
	float a=80, b=60;
	float cost=25000.0;
	//std::cout<<"please enter the height and width: ";
	Rectangle rectangle(a, b);
	Ellipse ellipse(a/2, b/2);
	cost+=(rectangle.Area()-ellipse.Area())*0.5;
	std::cout<<"cost: "<<cost<<std::endl;
	std::system("pause");
	return 0;
}
