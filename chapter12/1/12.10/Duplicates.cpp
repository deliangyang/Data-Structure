
#include <iostream>

using namespace std;

void RemoveDuplicates(Array<int> &A)
{
	ArrayIterator<int> iterator1(A);
	ArrayIterator<int> iterator2(A);

	for(iterator1.Reset(); !iterator1.EndOfList(); iterator1.Next())
	{
		for(iterator2.Reset(); !iterator2.EndOfList(); iterator2.Next())
		{
			
		}
	}

}


int main(int argc, char *argv[])
{
	
	std::system("pause");
	return 0;
}
