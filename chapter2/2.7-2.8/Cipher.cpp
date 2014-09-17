
#include <iostream>
#include <fstream>

using namespace std;

void printLetter(void)
{
	int i;
	for(i=0; i<26; i++)
		cout<<"'"<<(char)(i+'a')<<"'"<<", ";
}

void Encode(ifstream& fin, ofstream & fout);

const char letterEncode[]={'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
const char letterDecode[]={'d', 'e', 'f', 'm', 'n', 'o', 'p', 'g', 'h', 'i', 'j', 'k', 'l', 
'q', 't', 'u', 'v', 'w', 'x', 'r', 's', 'a', 'b', 'c', 'y', 'z'};


int main(int argc, char *argv[])
{
	ifstream fin;
	ofstream fout;
	fout.open("cipher.txt", ios::out);
	fin.open("data.txt", ios::in);
	if(!fin || !fout)
	{
		cout<<"con't open this file"<<endl;
		exit(1);
	}
	Encode(fin, fout);

	fin.close();
	fout.close();

	std::system("pause");
	return 0;
}

void Encode(ifstream& fin, ofstream & fout)
{
	char ch;
	char temp;
	int index;
	while(fin.get(ch)!=NULL)
	{
		if(isalpha(ch))
		{
			index=(int)(ch-'a');
			temp=letterDecode[index];
			cout<<temp;
			fout<<temp;
		}
		else
		{
			cout<<ch;
			fout<<ch;
		}
	}
}
