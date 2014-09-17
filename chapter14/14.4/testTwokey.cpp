
#include <iostream>

#include "TwoKey.h"

using namespace std;

const int len=100;

int main(int argc, char *argv[])
{
	TwoKey twokey[len];

	initTwoKey(twokey, len);
	SortPrimary(twokey, len);
	SortSecondary(twokey, len);
	PrintTwoKey(twokey, len);

	std::system("pause");
	return 0;
}
