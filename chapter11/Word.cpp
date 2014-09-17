
#include <iostream>

#include <fstream>

#include "Word.h"
#include "BinSTree.h"

using namespace std;

void PrintWord(Word& w)
{
	//std::cout<<w;
}

int main(int argc, char *argv[])
{
	BinSTree<Word> concordTree;
	ifstream fin;

	Word w;

	fin.open("Word.h");
	if(!fin)
	{
		std::cerr<<"can't open this file"<<std::endl;
		exit(1);
	}
	while(1)//fin>>w)
	{
		if(concordTree.Find(w)==0)
		{
			w.CountWord();
			concordTree.Insert(w);
		}
		else
		{
			w.CountWord();
			concordTree.Update(w);
		}
	}
	Inorder(concordTree.GetRoot(), PrintWord);

	
	std::system("pause");
	return 0;
}
