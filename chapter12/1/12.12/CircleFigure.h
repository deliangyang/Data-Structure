

#ifndef __CIRCLEFIGURE_H__
#define __CIRCLEFIGURE_H__

#include "NodeShape.h"

class CircleFigure:public NodeShape
{
public:
	CircleFigure(float h, float v, float r, int fill);
	virtual void Draw(void)const;
protected:
	float radius;
};

CircleFigure::CircleFigure(float h, float v, float r, int fill):NodeShape(h, v, fill),radius(r)
{}

void CircleFigure::Draw(void)const
{
	NodeShape::Draw();
	std::cout<<"CircleFigure draw(h, v, r): "<<x<<", "<<y<<", "<<radius<<std::endl;
}

#endif
