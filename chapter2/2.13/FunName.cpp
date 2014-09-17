

#include <iostream>
#include <fstream>

using namespace std;

int isAdd(char ch)
{
	switch(ch)
	{
	case '+':
	case '-':
		return -1;
	case 'x':
		return 2;
	default:
		return 1;
	}
}

int main(int argc, char *argv[])
{
	ofstream fout;
	int i=0, j=0;
	fout.open("funcs.val");
	if(!fout)
		cout<<"con't opent it"<<endl;
	int len;
	char head;
	char str[40];
	char temp[40];
	while(cin.getline(str, sizeof(str)))
	{
		if(strcmp(str, "#")==0)break;
		len=strlen(str);
		cout<<"len: "<<len<<"sizeof(str)"<<sizeof(str)<<endl;
		int len2=0;
		int count=0;
		sprintf(temp, "%c%s", str[0], "(x) = ");
		for(i=1; i<=len; i++)
		{
			cout<<str[i]<<" "<<count<<" "<<isAdd(str[i])<<" "<<i<<endl;
			if(isAdd(str[i])==2)
			{
				count++;
				continue;
			}
			
			len2=strlen(temp);
			sprintf(&temp[len2], "%s%d", "x* *", count);
			len2=strlen(temp);
			sprintf(&temp[len2], "%c", str[i]);
			cout<<temp<<endl;
			count=0;	
		}
		fout<<temp<<endl;
	}
	fout.close();
	std::system("pause");
	return 0;
}
