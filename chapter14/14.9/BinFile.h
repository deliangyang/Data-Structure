/*
 *  	BinFile class
 * 
 *
 *
 *
 *
 */

#ifndef __BINFILE_H__
#define __BINFILE_H__

#include <iostream>
#include <fstream>
#include <string>	
#include <stdlib.h>

using namespace std;

// visit file way
enum Access{IN, OUT, INOUT};

enum SeekType{BEG, CUR, END};

template<class T>
class BinFile
{
public:
	// constructor and assignment
	BinFile(const char * filename, Access atype=OUT);
	BinFile(BinFile<T> & bf);
	// destructor
	~BinFile(void);
	// some funtion of file operation
	void Clear(void);		// remove all the data about file
	void Delete(void);		// close file and remove file
	void Close(void);		// close file
	int EndFile(void);		// adjust the seek is last?
	long Size(void);		// return the file size
	void Reset(void);		// set seek at first data
	long Seek(long pos, SeekType mode);
	// read n data to address of A
	int Read(T *A, int n);
	// write n data into file
	void Write(T *A, int n);
	// get current data
	T peek(void);
	// copy data into file, at the pos
	void Write(const T& data, long pos);
	// read data at the postion of pos
	T Read(long pos);
	// append data into file record
	void Append(T item);

private:
	fstream f;
	Access accessType;		// the way of visit file
	string fname;			// file name
	int fileOpen;			// adjust file is or not open
	int Tsize;				// the size ofrecord data
	int fileSize;			// the size of file
	// print error msg
	void error(char *msg);
};

template<class T>
BinFile<T>::BinFile(const char * filename, Access atype)
{
	if(atype==IN)
		f.open(filename, ios::in | ios::binary);
	else if(atype==OUT)
		f.open(filename, ios::out | ios::app | ios::binary);
	else
		f.open(filename, ios::in | ios::out | ios::binary);
	if(!f)
		error("can't open this file");
	else
		fileOpen=1;
	accessType=atype;
	// data size;
	Tsize=sizeof(T);
	if(accessType==IN || accessType==INOUT)
	{
		f.seekg(0, ios::end);
		fileSize=f.tellg()/Tsize;
		f.seekg(0, ios::beg);
	}
	else
		fileSize=0;
	fname=filename;
}

template<class T>
BinFile<T>::BinFile(BinFile<T> & bf)
{
	error("Pass file parameter by reference only");
}

template<class T>
void BinFile<T>::Reset(void)
{
	if(!fileOpen)
		error("file closed");
	if(accessType == OUT)
    	f.seekp(0, ios::beg);
   	else
    	f.seekg(0, ios::beg);
}

template<class T>
void BinFile<T>::Write(const T& data, long pos)
{
	if(!fileOpen)
		error("file closed");
	if(accessType==IN)
		error("Invalid file access operation");
	else if(pos<0)
		error("Invalid file access operation");
	// 
	f.seekp(pos*Tsize, ios::beg);
	f.write((char *)&data, Tsize);
	f.seekg(0, ios::end);
	fileSize=f.tellg()/Tsize;
	f.seekg(pos*Tsize, ios::beg);
}

// from file and read something
template<class T>
int BinFile<T>::Read(T *A, int n)
{
	long currpos;
	int nread;

	if(accessType==OUT)
		error("Indival: can't write");
	else if (n < 0) 
      	error("Invalid record count");
   	
   	if(!fileOpen)
      	error("BinFile Read(T *A, int n): file closed");
    currpos=f.tellg()/Tsize;
    if(n==0 || currpos>fileSize)
    	return 0;
    // 当前位置+需要读取的字节>文件的大小？
   nread = int((currpos+n <= fileSize) ? n : fileSize-currpos);
   f.read((char *)A, nread*Tsize);
   if(accessType==IN)
   		if(f.tellg()/Tsize>=fileSize)
   			f.clear(ios::eofbit);
   	return nread;
}

template <class T>
void BinFile<T>::Append(T data)
{
   if(!fileOpen)
      error("BinFile Append: file closed");

   if (accessType == IN)
      error("Invalid file access operation");
   if (accessType == OUT)
		f.seekp(0, ios::end);
   else
		f.seekg(0, ios::end);
   f.write((char *)&data,Tsize);
   fileSize++;
}

// read data at record pos
template<class T>
T BinFile<T>::Read(long pos)
{
	T data;

	if(!fileOpen)
		error("Read(long pos): file closed");
	if(accessType==OUT)
		error("Invalid file access operation");
	else if(pos < 0 || pos >= fileSize)
      	error("Invalid file access operation");
     // move seek
    f.seekg(pos*Tsize, ios::beg);
    f.write((char *)&data, Tsize);

    if(accessType==IN)
    	if(f.tellg()/Tsize>=fileSize)
    		f.clear(ios::beg);

    return data;
}

// seek
template<class T>
long BinFile<T>::Seek(long pos, SeekType mode)
{
	ios fromWhere;
	long retval;

	if(!fileOpen)
		error("file closed");
	switch(mode)
   {
      case BEG:
	       fromWhere = ios::beg;
	       break;
      case CUR:
	       fromWhere = ios::cur;
	       break;
      case END:
	       fromWhere = ios::end;
	       break;
   }
   if (accessType == OUT)
   {
      f.seekp(pos*Tsize,fromWhere);
      retval = f.tellp();
   }
   else
   {
      f.seekg(pos*Tsize,fromWhere);
      retval = f.tellg();
   }
   return retval;
}

template<class T>
T BinFile<T>::peek(void)
{
	T data;
   
   if(!fileOpen)
      error("BinFile Peek: file closed");

   if (accessType == OUT)
      error("Invalid file access operation");
   else if (fileSize == 0)
      error("File is empty");
   f.read((char *)&data,Tsize);
   f.seekg(-Tsize, ios::cur);
   return data;
}

template <class T>
void BinFile<T>::Write(T *A, int n)
{
   long previousRecords;
 
   if(accessType==IN)
      error("Invalid file access operation");
   
   if(!fileOpen)
      error("BinFile Write(T *A, int n): file closed");

   previousRecords = f.tellp()/Tsize;
   if (previousRecords + n > fileSize)
      fileSize += previousRecords + n - fileSize;

   f.write((char *)A,Tsize*n);
}

template<class T>
void BinFile<T>::Clear(void)
{
	if(accessType==IN)
		error("");
	f.close();
	if(accessType==OUT)
		f.open(fname, ios::out | ios::trunc | ios::binary);
	else
		f.open(fname, ios::in | ios::out | ios::trunc | ios::binary);
	if(!f)
		error();
	fileSize=0;
}

#ifdef __THINKC__
#include <unix.h>
#endif   // __THINKC__

#ifdef __BORLANDC__
#include <io.h>
#endif   // __BORLANDC__

#ifdef __GNUC__
#include <unistd.h>
#endif   // __GNUC__

// Delete closes file and removes it from the file system
template <class T>
void BinFile<T>::Delete(void)
{
   if (!fileOpen)
	  error("BinFile Delete: file closed");

   // close the file
   f.close();
   fileOpen = 0;
   
   // remove it from the file system
   unlink(fname);
}

template<class T>
BinFile<T>::~BinFile(void)
{
	if(!fileOpen)
	{
		f.close();
		fileOpen=0;
	}	
}

template<class T>
long BinFile<T>::Size(void)
{
	if(!fileOpen)
		error("file closed");
	return fileSize;
}

template<class T>
int BinFile<T>::EndFile(void)
{
	if(!fileOpen)
		error("file closed");
	return f.eof();
}

template<class T>
void BinFile<T>::error(char *msg)
{
	std::cerr<<msg<<std::endl;
	exit(1);
}

template <class T>
void BinFile<T>::Close(void)
{
   if (!fileOpen)
	  error("BinFile Close: file closed");

   f.close();
   fileOpen = 0;
}

#endif

