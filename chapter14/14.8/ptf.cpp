
#include <iostream>

#include <fstream>

using namespace std;

void ToUppercase(char &ch)
{
	if(ch>='a' && ch<='z')
		ch=char(ch-32);
}

void write(ifstream & fin, ofstream & fout)
{
	char ch;
	while(fin>>ch)
	{
		ToUppercase(ch);
		fout<<ch;
	}
}

int main(int argc, char *argv[])
{
	ifstream fin("ptf.cpp");
	ofstream fout("ptf.out");
	if(!fin || !fout)
	{
		std::cout<<"can't open this file"<<std::endl;
		exit(1);
	}
	write(fin, fout);
	fin.close();
	fout.close();

	ifstream f("ptf.out");
	if(!f)
	{
		std::cout<<"can't open this file"<<std::endl;
		exit(1);
	}	
	char ch;
	while(f>>ch)
		std::cout<<ch;
	f.close();
	std::system("pause");
	return 0;
}
