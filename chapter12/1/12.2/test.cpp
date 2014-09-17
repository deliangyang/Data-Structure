
#include <iostream>

#include "Rectangle.h"
#include "Box.h"

using namespace std;

int main(int argc, char *argv[])
{
	Rectangle rect(100, 100);
	std::cout<<rect.Area()<<std::endl;

	Box box(100, 10, 200);
	std::cout<<box.Volume()<<std::endl;
	std::system("pause");
	return 0;
}
