
#include <iostream>
#include <fstream>

using namespace std;

int pal(char a[], int s, int e)
{
	if(s>=e)
		return 1;
	if(a[s]-a[e])
		return 0;
	return pal(a, s+1, e-1);
}

int GetWords(ifstream& fin, char word[])
{
	char ch;
	int i=0;
	while(fin.get(ch) && !isalpha(ch))
		;
	if(fin.eof())
		return 0;
	word[i++]=ch;
	while(fin.get(ch) && (isalpha(ch) || isdigit(ch)))
		word[i++]=ch;
	word[i]='\0';
	return 1;
}

int main(int argc, char *argv[])
{
	char word[30];
	ifstream fin;
	fin.open("test.dat");
	if(!fin)
	{
		std::cout<<"can't open this file"<<std::endl;
		exit(1);
	}
	while(GetWords(fin, word))
		if(pal(word, 0, strlen(word)-1))
			std::cout<<word<<std::endl;

	fin.close();
	
	std::system("pause");
	return 0;
}
