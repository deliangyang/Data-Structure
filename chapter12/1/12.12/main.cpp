
#include <iostream>

#include "NodeShape.h"
#include "CircleFigure.h"
#include "RectangleFigure.h"
#include "RightTriangleFigure.h"

int main(int argc, char *argv[])
{

	NodeShape header, * p, * ptrNew;
	float x, y, radius;
	x=10;
	y=20;
	radius=10;
	p=&header;

	int i;
	ptrNew=new CircleFigure(x, y, radius, 4);
	p->InsertAfter(ptrNew);
	p=p->Next();
	ptrNew=new RectangleFigure(100, 100, 5);
	p->InsertAfter(ptrNew);
	p=p->Next();

	ptrNew=new RightTriangleFigure(300, 300, 1);
	p->InsertAfter(ptrNew);
	p=p->Next();

	p=header.Next();
	while(p!=&header)
	{
		p->Draw();
		p=p->Next();
	}
	
	p=header.Next();
	while(p!=&header)
	{
		ptrNew=p;
		p=p->Next();
		delete ptrNew;
	}

	std::system("pause");
	return 0;
}

