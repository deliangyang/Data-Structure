

#ifndef _STRING_H
#define _STRING_H

#include <fstream>

const int STRSIZE=256;

class String
{
public:
	String(char s[]="");
	int length(void)const;

	friend std::ostream& operator<<(std::ostream& os, const String& s);
	friend std::istream& operator>>(std::istream& is, String& s);
	int operator==(String& s)const;
	String operator+(String& s);
private:
	char str[256];
	int len;
};

#endif
