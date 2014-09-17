

#include "Vector.h"

Vector::Vector(double x, double y):x(x),y(y){}

double Vector::operator*(Vector& v)const
{
	return(v.x*x+v.y*y);
}

Vector Vector::operator+(Vector& v)const
{
	double vX=x+v.x;
	double vY=y+v.y;
	return(Vector(vX, vY)); 
}

Vector Vector::operator-(void)const
{
	return Vector(-x, -y);
}

Vector operator* (const double c, const Vector& v)
{
	return(Vector(c*v.x, c*v.y));
}

std::ostream& operator<<(std::ostream& os, const Vector& v)
{
	os<<"("<<v.x<<", "<<v.y<<")"<<std::endl;
	return os;
}
