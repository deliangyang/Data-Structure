
#include <string.h>
#include <iostream>
#include <fstream>

#define STRINGLEN 32

struct FilmData
{
	char filename[STRINGLEN];
	char customername[STRINGLEN];
};

int operator==(const FilmData& a, const FilmData& b)
{
	return strcmp(a.filename, b.filename)==0;
}

#include "SeqLink.h"

void GetFilmInfo(SeqLink<FilmData>& film)
{
	ifstream fin;
	FilmData fd;
	fin.open("test.txt", ios::in);
	if(!fin)
		std::cout<<"error, con't open it"<<std::endl;
	while(fin.getline(fd.filename, 32, '\n'))
		film.Insert(fd);
	fin.close();
}

void WriteInfo(SeqLink<FilmData>& film)
{
	ofstream fout;
	FilmData fd;
	int i=0;
	fout.open("test.txt", ios::out);
	if(!fout)
		std::cout<<"error, con't open it"<<std::endl;
	while(!film.isEmpty())
	{
		fd=film.GetData(i);
		fout<<fd.filename<<std::endl;
		i++;
	}
	fout.close();
}

void PrintFilmInfo(SeqLink<FilmData>& film)
{
	int i;
	FilmData fd;
	for(i=0; i<film.Size(); i++)
	{
		fd=film.GetData(i);
		std::cout<<fd.filename<<endl;
	}
}

void PrintCustomerList(SeqLink<FilmData>& film)
{
	int i;
	FilmData fd;
	for(i=0; i<film.Size(); i++)
	{
		fd=film.GetData(i);
		std::cout<<fd.customername<<"("<<fd.filename<<")"<<std::endl;
	}
}




