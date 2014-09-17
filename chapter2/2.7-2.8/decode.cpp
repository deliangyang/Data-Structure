
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
void Decode(ifstream& fin);

const char letterEncode[]={'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
const char letterDecode[]={'d', 'e', 'f', 'm', 'n', 'o', 'p', 'g', 'h', 'i', 'j', 'k', 'l', 
'q', 't', 'u', 'v', 'w', 'x', 'r', 's', 'a', 'b', 'c', 'y', 'z'};


int main(int argc, char *argv[])
{
	ifstream fin;
	fin.open("cipher.txt", ios::in);
	if(!fin)
	{
		cout<<"con't open this file"<<endl;
		exit(1);
	}
	Decode(fin);

	fin.close();

	std::system("pause");
	return 0;
}

void Encode(ifstream& fin, ofstream & fout)
{
	char ch;
	while(fin.get(ch)!=NULL)
	{
		if(isalpha(ch))
		{
			ch=ch-'a';
			ch=letterEncode[(int)ch];
			cout<<ch;
			fout<<ch;
		}
		else
		{
			cout<<ch;
			fout<<ch;
		}
	}
}

void Decode(ifstream& fin)
{
	char ch;
	int index;
	int i;
	while(fin.get(ch)!=NULL)
	{
		if(isalpha(ch))
		{
			for(i=0; i<26; i++)
				if(ch==letterDecode[i])
				{
					index=i;
					break;
				}
			ch=letterEncode[index];
			cout<<ch;
		}
		if(ch==' ')
		{
			ch=' ';
			cout<<ch;
		}
	}
}
