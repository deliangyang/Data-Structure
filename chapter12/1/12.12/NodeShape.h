
#ifndef __NODESHAPE_H__
#define __NODESHAPE_H__

class NodeShape
{
public:
	NodeShape(float h=0, float v=0, int fill=0);

	virtual void Draw(void)const;
	// do
	void InsertAfter(NodeShape *p);
	NodeShape * DeleteAfter(void);
	NodeShape * Next(void);
protected:
	float x, y;
	int fillpat;
	NodeShape * next;	
};

NodeShape::NodeShape(float h, float v, int fill):x(h), y(v), fillpat(fill)
{
	next = this;
}

void NodeShape::InsertAfter(NodeShape * p)
{
	p->next=next;
	next=p;
}

NodeShape * NodeShape::DeleteAfter(void)
{
	NodeShape * ptrDel=next;
	if(next==this)
		return NULL;
	next=ptrDel->next;
	return ptrDel;
}

NodeShape * NodeShape::Next(void)
{
	return next;
}


void NodeShape::Draw(void)const
{
	std::cout<<"draw"<<std::endl;
}

#endif
