
#include "String.h"

String::String(char s[])
{
	len=0;
	while(s[len]!='\0')
	{
		str[len]=s[len];
		len++;
		if(len==256)
			break;
	}
}

int String::length(void)const
{
	int len=0;
	while(str[len]!='\0')
		len++;
	return len;
}

std::ostream& operator<<(std::ostream& os, const String& s)
{
	os<<s.str;
	return os;
}

std::istream& operator>>(std::istream& is, String& s)
{
	is>>s.str;
	return is;
}

String String::operator+(String& x)
{
	int i=0;
	int j=0;
	String temp;
	while(str[i]!='\0')
	{
		if(temp.len==256)
			break;
		temp.str[temp.len]=str[i];
		temp.len++;
		i++;
	}
	while(x.str[j]!='\0')
	{
		if(temp.len==256)
			break;
		temp.str[temp.len]=x.str[j];
		temp.len++;
		j++;
	}
	return temp;
}
