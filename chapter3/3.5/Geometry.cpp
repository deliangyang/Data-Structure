

#include <iostream>
#include <math.h>

using namespace std;

enum Figure{Circle, Rectangle};
const double PI=3.14;

class Geometry
{
public:
	Geometry(double radius);
	Geometry(double l, double w);
	double Border(void)const;
	double Area(void)const;
	double Diagonal(void)const;
private:
	double v1, v2;
	Figure figuretype;
};

Geometry::Geometry(double radius)
{
	figuretype=Circle;
	v1=radius;
}

Geometry::Geometry(double l, double w)
{
	figuretype=Rectangle;
	v1=l;
	v2=w;
}

double Geometry::Border(void)const
{
	if(figuretype==Circle)
		return 2*PI*v1;
	return (v1+v2)*2;
}

double Geometry::Area(void)const
{
	if(figuretype==Circle)
		return PI*v1*v1;
	return v1*v2;
}

double Geometry::Diagonal(void)const
{
	if(figuretype==Circle)
		return 2*v1;
	return sqrt(v1*v1+v2*v2);
}

int main(int argc, char *argv[])
{
	double r;
	double R;
	std::cout<<"Please enter small circle's radius: ";
	std::cin>>r;
	Geometry smallCircle(r);
	Geometry rectangle(r, r);
	R=rectangle.Diagonal();
	Geometry bigCircle(R);
	std::cout<<"small circle's object info: ";
	std::cout<<smallCircle.Border()<<"\t "<<smallCircle.Area()<<"\t "<<smallCircle.Diagonal()<<std::endl;
	std::cout<<"rectangle's object info: ";
	std::cout<<rectangle.Border()<<"\t "<<rectangle.Area()<<"\t "<<rectangle.Diagonal()<<std::endl;
	std::cout<<"big circle's object info: ";
	std::cout<<bigCircle.Border()<<"\t "<<bigCircle.Area()<<"\t "<<bigCircle.Diagonal()<<std::endl;	
	std::cout<<std::endl;
	std::cout<<"the ring's area: "<<(bigCircle.Area()-smallCircle.Area())<<std::endl;
	std::cout<<"x's perimeter: "<<((1/4)*bigCircle.Area()+2*r)<<std::endl;
	std::system("pause");
	return 0;
}
