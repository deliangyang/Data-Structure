
#include <iostream>

#include "../BinSTree.h"
#include "../TreeNodeFun.h"
#include "../TreeNode.h"
#include "../String.h"

using namespace std;

struct Word
{
	String str;
	int count;
};

int main(int argc, char *argv[])
{
	Word word;
	BinSTree<Word> bin;
	word.count=0;
	bin.Insert(word);

	
	std::system("pause");
	return 0;
}
