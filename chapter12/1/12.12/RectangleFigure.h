
#ifndef __RECTANGLEFIGURE_H__
#define __RECTANGLEFIGURE_H__

#include "NodeShape.h"

class RectangleFigure:public NodeShape
{
public:
	RectangleFigure(float h, float v, int fill);
	virtual void Draw(void)const;	
};

RectangleFigure::RectangleFigure(float h, float v, int fill):NodeShape(h, v, fill)
{}

void RectangleFigure::Draw(void)const
{
	NodeShape::Draw();
	std::cout<<"RectangleFigure draw(h, v): "<<x<<", "<<y<<std::endl;
}

#endif

