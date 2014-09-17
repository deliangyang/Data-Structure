

#ifndef __BINFILE_H__
#define __BINFILE_H__

#include <fstream>

using namespace std;

enum Access
{
	IN, OUT, INOUT			// only read, only write, can read and write
};

const int True=1;
const int False=0;

template<class T>
class BinFile
{
public:
	BinFile(const char * fname, Access mode=OUT);
	// write number n element into address A
	void Write(T * A, int n);
	void Read(T * A, int n);
	void Write(const T &data, int pos);
	~BinFile(void);
private:
	// create fstream to start
	fstream f;
	// adjust file is open
	int fileopen;
	// data size
	int Tsize;
	// count file size
	unsigned long filesize;
	// deal erroe message
	void error(const char * msg);
	// file access type
	Access accessType;
};

template<class T>
BinFile<T>::BinFile(const char * fname, Access mode)
{
	if(mode==IN)
		f.open(fname, ios::in | ios::binary);
	else if(mode==OUT)
		f.open(fname, ios::out | ios::binary);
	else	// can write and read
		f.open(fname, ios::out | ios::in | ios::binary);
	if(!f)
		error("Initailization: can't open this file");
	accessType=accessType;
	fileopen=True;
	Tsize=sizeof(T);		// get the data T's size
	if(mode==IN || mode==INOUT)
	{
		f.seekg(0, ios::end);
		filesize=f.tellg()/Tsize;
		f.seekg(0, ios::beg);
	}
	else
		filesize=0;
}

// OUT
template<class T>
void BinFile<T>::Write(T *A, int n)
{
	if(accessType==IN)
		error("Write: can't write");
	if(!fileopen)
		error("Write: file is closed");
	f.write((char *)A, n*Tsize);
}
// OUT put write: write element after index
template<class T>
void BinFile<T>::Write(const T &data, int pos)
{
	if(accessType==IN)
		error("Write: can't write");
	if(!fileopen)
		error("Write: file is closed");
	if(pos<0)
		error("Write: out of file");
	f.seekp(Tsize*pos, ios::beg);
	f.write((char *)&data, Tsize);
	f.seekg(0,ios::end);
   	fileSize = f.tellg()/Tsize;
   	f.seekg(pos*Tsize,ios::beg);
}

// IN
template<class T>
void BinFile<T>::Read(T *A, int n)
{
	if(accessType==OUT)
		error("Write: can't read");
	if(!fileopen)
		error("Write: file is closed");
	f.read((char *)A, n*Tsize);
}

template<class T>
T BinFile<T>::Read(long pos)
{
	T data;

	f.seekg(pos*Tsize, ios::beg);
   	f.read((char *)&data, Tsize);

   return data;
}

template<class T>
BinFile<T>::~BinFile(void)
{
	if(fileopen)
		f.close();
}

template<class T>
void BinFile<T>::error(const char * msg)
{
	std::cerr<<msg<<std::endl;
	exit(1);
}


#endif

