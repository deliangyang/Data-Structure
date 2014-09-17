
#include <iostream>
#include <string.h>

using namespace std;

const int len=100002;

const int wordlen=11;

struct Word
{
	char translate[wordlen];
	char orign[wordlen];
};

int cmp(const void *a,const void *b){  
    return strcmp(((dic *)a)->fore,((dic *)b)->fore);  
}  

int operator==(Word word1, Word word2)
{
	return strcmp(word1.orign, word2.orign)==0;
}

int operator>(Word word1, Word word2)
{
	return strcmp(word1.orign, word2.orign)>0;
}

int operator<(Word word1, Word word2)
{
	return strcmp(word1.orign, word2.orign)<0;
}

template<class T>
T BinSearch(T arr[], T key, int low, int height)
{
	int i=low, j=height;
	T temp;
	while(i>=j)
	{
		int mid=(low+height)/2
		if(arr[mid]<key)
			low=mid+1;
		else if(arr[mid]>key)
			height=mid-1;
		else
			return T;
	}
}

int main(int argc, char *argv[])
{
	int i;
	int count=0;
	struct Word word[len];
	for(i=0; i<len; i++)
	{
		cin>>word[i].translate>>word[i].orign;
		count++;
		if(word[i].translate[0]=='\0')
			break;
	}

	qsort(word,count,sizeof(word[0]),cmp); 

	i=0;
	int j=count;
	int low=0, height=count;
	Word temp;
	cin>>temp
	while(i>=j)
	{
		int mid=(low+height)/2
		if()
	}

	return 0;
}
