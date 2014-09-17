#include <iostream>
#include "CharRec.h"

using namespace std;

int main(int argc, char *argv[])
{
	CharRec cr[26];
	BinFile<CharRec> bin("CharRer.out", INOUT);
	StorageLetter(bin, cr, 26);
	ifstream fin;
	fin.open("CharRec.h");
	if(!fin)
	{
		std::cout<<"open file failer"<<std::endl;
		exit(1);
	}
	StartRead(fin, cr, 26);
	PrintCK(cr, 26);
	std::cout<<std::endl;
	QuickSort(cr, 0, 25);
	PrintCK(cr, 26);
	std::cout<<std::endl;
	std::cout<<"Letter Count: "<<CountLetter(cr, 26)<<std::endl;
	std::system("pause");
	return 0;
}
