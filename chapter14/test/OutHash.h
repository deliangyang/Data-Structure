

#ifndef __OUTHASH_H__
#define __OUTHASH_H__

#include "BinFile.h"

const long Empty=-1;

struct FileDataRecord
{
	int data;
	long nextIndex;
};

void LoadRecord(BinFile<FileDataRecord> &bf, long &startindex, FileDataRecord &dr)
{
	dr.nextIndex=startindex;
	startindex=bf.Size();
	bf.Append(dr);
}

void PrintList(BinFile<FileDataRecord> &bf, long startindex)
{
	long index=startindex;
	FileDataRecord fr;
	while(index!=Empty)
	{
		fr=bf.Read(index);
		std::cout<<fr.data<<" ";
		index=fr.nextIndex;
	}
	std::cout<<std::endl;
}

#endif
