

#ifndef _VECTOR_H
#define _VECTOR_H

#include <fstream>

class Vector
{
public:
	Vector(double x, double y);
	double operator*(Vector& v)const;
	Vector operator+(Vector& v)const;
	Vector operator-(void)const;

	friend Vector operator* (const double c, const Vector& v);
	friend std::ostream& operator<<(std::ostream& os, const Vector& v);
private:
	double x;
	double y;
};

#endif
