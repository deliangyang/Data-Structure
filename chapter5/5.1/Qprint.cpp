
#include <iostream>
#include <fstream>
#include <iomanip>
#include "../Queue.h"

using namespace std;

void Qprint(void)
{
	Queue<double> queue;
	ifstream fin;
	double read;
	fin.open("double.txt", ios::in);
	if(!fin)
	{
		std::cout<<"can't open this file"<<std::endl;
		exit(0);
	}
	int i=0;
	while(fin>>read)
		queue.Insert(read);
	while(!queue.isEmpty())
	{
		std::cout.setf(ios::left);
		std::cout.width(15);
		std::cout<<setprecision(10)<<queue.Delete();
		if((i+1)%4==0)
			std::cout<<std::endl;
		i++;
	}
	fin.close();
}

int main(int argc, char *argv[])
{
	Qprint();
	std::system("pause");
	return 0;
}
