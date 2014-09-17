

#ifndef __STRING_H__
#define __STRING_H__

const int StrLen= 256;

#include <fstream>

class String
{
public:
	String(int size=StrLen);
	String(const char * s);
	int length(void)const;
	~String(void);

	String operator+(const String& s);
	String operator+(const char * s1);

	char operator[](unsigned int index)const;
	String operator=(char * s);

	friend std::ostream& operator<<(std::ostream& os, const String& s);
	friend std::istream& operator>>(std::istream& is, String& s);
private:
	char * str;	
	int size;
	int len;
};

String::String(int size):len(0)
{
	str=new char[size];
}

String::String(const char  * s)
{
	size=StrLen;
	len=0;
	str=new char[size];
	while(*s!='\0')
	{
		str[len]=*s++;
		len++;
	}
	str[len]='\0';
}

String::~String(void)
{
	delete[] str;
}

int String::length(void)const
{
	return len;
}

String String::operator+(const String& s)
{
	char * dest=s.str;
	while(*dest!='\0' && len<size)
	{
		str[len]=*dest++;
		len++;
	}
	str[len]='\0';
	return(String(str));
}

String String::operator+(const char* str1)
{
	const char * dest=str1;
	while(*dest!='\0' && len<size)
	{
		str[len]=*dest++;
		len++;
	}
	str[len]='\0';
	return(String(str));
}

char String::operator[](unsigned int index)const
{
	if(index<0 || index>size)
	{
		std::cerr<<"out of range"<<std::endl;
		exit(1);
	}
	return str[index];
}

String String::operator=(char * s)
{
	return(String(s));
}

std::ostream& operator<<(std::ostream& os, const String& s)
{
	os<<s.str;
	return os;
}

std::istream& operator>>(std::istream& is, String& s)
{
	is.getline(s.str, s.length(), '\n');
	return is;
}

#endif
