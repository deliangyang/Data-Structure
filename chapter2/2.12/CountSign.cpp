
#include <iostream>
#include <fstream>

struct Symbol
{
	char symbol;
	int count;
};

using namespace std;

#define LEN 4

void CountSymbol(ifstream& fin, Symbol symbol[]);
void PrintSymbol(Symbol symbols[], int n);

int main(int argc, char *argv[])
{
	Symbol symbols[]={{'.', 0}, {',', 0}, {'!', 0}, {'?', 0}};
	ifstream fin;
	fin.open("data.txt", ios::in);
	if(!fin)
	{
		std::cout<<"con't open this file"<<std::endl;
		exit(0);
	}
	CountSymbol(fin, symbols);
	PrintSymbol(symbols, LEN);
	std::system("pause");
	return 0;
}

void CountSymbol(ifstream& fin, Symbol symbol[])
{
	char ch;
	while(fin.get(ch)!=NULL)
	{
		switch(ch)
		{
			case '.':
				symbol[0].count++;
				break;
			case ',':
				symbol[1].count++;
				break;
			case '!':
				symbol[2].count++;
				break;
			case '?':
				symbol[3].count++;
				break;
			default:
				break;
		}
	}
}

void PrintSymbol(Symbol symbols[], int n)
{
	int i;
	std::cout<<"In file, count('.', ',', '!', '?'): "<<std::endl;
	for(i=0; i<n; i++)
		std::cout<<symbols[i].symbol<<" : "<<symbols[i].count<<std::endl;
}
