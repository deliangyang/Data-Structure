
#ifndef __PRINTTAB_H__
#define __PRINTTAB_H__

#include "../Array.h"
#include "String.h"

#include <fstream.h>

void PrintTab(void)
{
	for(int i=0; i<4; i++)
		std::cout<<" ";
}

void GetLine(ifstream &fin, Array<String> &A)
{
	char word[100];
	int i=0;
	while(fin.getline(A[i], 100, '\n'))
	{
		std::cout<<A[i];
		i++;
	}
}


#endif
