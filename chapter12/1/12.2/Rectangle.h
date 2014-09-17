
#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

class Rectangle
{
public:
	Rectangle(void);
	Rectangle(float height, float width);
	float Area(void)const;
	virtual float Volume(void)const;
private:
	float height;
	float width;	
};

Rectangle::Rectangle(void)
{}

Rectangle::Rectangle(float width, float height):width(width),height(height)
{}

float Rectangle::Area(void)const
{
	return width*height;
}

float Rectangle::Volume(void)const
{
	return 0;
}


#endif
