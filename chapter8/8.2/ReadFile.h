
#include <fstream>

class ReadFile
{
public:
	ReadFile(char * name, int size);
	ReadFile(const ReadFile& f);
	int read(void);
	void Printbuffer(void);
	~ReadFile();
private:
	int buffersize;
	char * buffer;
	std::ifstream fin;	
};

ReadFile::ReadFile(char* name, int size)
{
	fin.open(name, std::ios::in);
	if(!fin)
	{
		std::cerr<<"open file failure"<<std::endl;
		exit(0);
	}
	buffersize=size;
	buffer=new char[buffersize];
}

int ReadFile::read(void)
{
	if(fin)
	{
		fin.getline(buffer, buffersize);
		return sizeof(buffersize);
	}
	else
		return 0;
	/*while(fin)
	{
		fin.getline(buffer, buffersize);
		std::cout<<buffer<<std::endl;
	}*/
}

void ReadFile::Printbuffer(void)
{
	std::cout<<buffer<<std::endl;
}

ReadFile::~ReadFile(void)
{
	delete buffer;
	buffer=NULL;
	fin.close();
}

