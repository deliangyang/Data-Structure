

#ifndef __BOX_H__
#define __BOX_H__


#include "Rectangle.h"

class Box:public Rectangle
{
public:
	Box(float length, float width, float height);
	virtual float Volume(void)const;
private:
	float length;
	float height;
	float width;	
};


Box::Box(float length, float width, float height):length(length),
				width(width), height(height)
{}

float Box::Volume(void)const
{
	return length*width*height;
}


#endif
