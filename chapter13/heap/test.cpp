

#include <iostream>

#include "LongRunFilter.h"

int main(int argc, char *argv[])
{
	int arr[]={3, 4, 5, 1, 100, 30, 32, 21, 100};
	LongRunFilter<int> run(arr, 9, 5);
	std::cout<<"count: "<<run.CountRuns()<<std::endl;
	run.PrintRuns();
	run.LoadRuns();

	std::system("pause");
	return 0;
}