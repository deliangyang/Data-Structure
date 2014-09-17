
#include <iostream>

int main(int argc, char *argv[])
{
	int i, j, k;
	std::cout<<"Enter three var(i, j, K): ";
	std::cin>>i>>j>>k;
	std::cout<<"dec: "<<std::dec<<i<<", "<<j<<", "<<k<<std::endl;
	std::cout<<"hex: "<<std::hex<<i<<", "<<j<<", "<<k<<std::endl;

	std::system("pause");
	return 0;
}
