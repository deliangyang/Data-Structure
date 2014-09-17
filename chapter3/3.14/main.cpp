
#include <iostream>

#include "Baseball.h"

using namespace std;

Baseball FindMax(Baseball baseball[], int n)
{
	Baseball temp;
	int i;
	for(i=0; i<n; i++)
		if(baseball[i].GetBatAve()>temp.GetBatAve())
			temp=baseball[i];
	return temp;
}

int main(int argc, char *argv[])
{

	Baseball baseball[4];
	baseball[0]=Baseball(10, 100, 30);
	baseball[1]=Baseball(44, 0, 0);
	baseball[1].ReadPlayer();
	baseball[2].ReadPlayer();

	baseball[0].WritePlayer();
	baseball[1].WritePlayer();
	baseball[2].WritePlayer();

	std::cout<<"find the heigher one: ";
	baseball[3]=FindMax(baseball, 3);
	baseball[3].WritePlayer();

	std::system("pause");
	return 0;
}
