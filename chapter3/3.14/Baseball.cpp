
#include "Baseball.h"
#include <iostream>

Baseball::Baseball(int n, int ab, int h)
{
	this->playerno=n;
	this->atbats=ab;
	this->hits=h;
}

void Baseball::ReadPlayer(void)
{
	int playerno;
	int atbats;
	int hits;
	if(this->playerno!=-1)
	{
		std::cout<<"enter atbats: ";
		std::cin>>atbats;
		std::cout<<"enter hits: ";
		std::cin>>hits;

		this->atbats=atbats;
		this->hits=hits;
	}
	else
	{
		std::cout<<"enter player no: ";
		std::cin>>playerno;
		std::cout<<"enter atbats: ";
		std::cin>>atbats;
		std::cout<<"enter hits: ";
		std::cin>>hits;

		this->playerno=playerno;
		this->atbats=atbats;
		this->hits=hits;
	}
}

void Baseball::WritePlayer(void)
{
	std::cout<<"Player: "<<playerno<<" Average: "<<((int)GetBatAve())*100<<std::endl;
}

float Baseball::GetBatAve(void)const
{
	return ComputeBatAve();
}
