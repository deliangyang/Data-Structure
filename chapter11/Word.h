

#ifndef __WORD_H__
#define __WORD_H__

#include <fstream>
#include <iostream>
#include <iomanip>

#include "String.h"
#include "Linked.h"

class Word
{
public:
	Word(void);
	void CountWord(void);
	String& Key(void);
	int operator==(const Word& w)const;
	int operator<(const Word& w)const;

	//friend std::istream&>>(std::istream& is, Word& w);
	//friend std::ostream&<<(std::ostream& os, const Word& w);
private:
	String wordText;
	int count;										// word show times
	static int lineno; 								// line number
	int lastlineno;
	Linked<int> lineNumbers;
};

Word::Word(void):count(0),lastlineno(-1){}

int Word::operator==(const Word& w)const
{
	return wordText==w.wordText;
}

int Word::operator<(const Word& w)const
{
	return wordText<w.wordText;
}

void Word::CountWord(void)
{
	count++;
	if(count==1 || lastlineno!=lineno)
	{
		lineNumbers.InsertAfter(lineno);
		lastlineno=lineno;
	}
}

/*std::istream&>>(std::istream& is, Word& w)
{
	char c;
	char wd[30];
	int i=0;
	while(is.get(c) && !isalpha(c))
		if(c=='\n')
			w.lineno++;
	if(!is.eof())
	{
		c=tolower(c);
		wd[i++]=c;
		while(is.get(c) && (isalpha(c) || isdigit(c)))
			wd[i++]=tolower(c);
		wd[i]='\0';
		if(c=='\n')
			is.putback(c);
		w.wordText=wd;
		w.count=0;
		w.lastlineno=w.lineno;
	}
	return is;
}

std::ostream&<<(std::ostream& os, const Word& w)
{
	os<<w.wordText;
	os.fill('.');
	os<<setw(25-w.wordText.Length())<<w.count<<" : ";
	os.fill(' ');
	for(w.lineNumbers.Reset(); !w.lineNumbers.EndOfList();
						w.lineNumbers.Next())
		os<<w.lineNumbers.Data()<<" ";
	os<<std::endl;

	return os;
}*/

#endif
