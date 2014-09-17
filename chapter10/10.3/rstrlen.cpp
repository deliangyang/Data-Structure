
#include <iostream>

using namespace std;

int rstrlen(char s[])
{
	int len=0;
	while(s[len]!='\0')
		len++;
	return len;
}

int main(int argc, char *argv[])
{

	char s[]="hello world";
	std::cout<<s<<std::endl;
	std::cout<<"length: "<<rstrlen(s)<<std::endl;
	std::cout<<"strlen: "<<strlen(s)<<std::endl;
	
	std::system("pause");
	return 0;
}