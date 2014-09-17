

#ifndef __RIGHTTRIANGLEFIGURE_H__
#define __RIGHTTRIANGLEFIGURE_H__

#include "NodeShape.h"

class RightTriangleFigure:public NodeShape
{
public:
	RightTriangleFigure(float h, float v, int fill);
	virtual void Draw(void)const;	
};

RightTriangleFigure::RightTriangleFigure(float h, float v, int fill):NodeShape(h, v, fill)
{}

void RightTriangleFigure::Draw(void)const
{
	NodeShape::Draw();
	std::cout<<"RightTriangleFigure draw(h, v, fill): "<<x<<", "<<y<<", "<<fillpat<<std::endl;
}

#endif
