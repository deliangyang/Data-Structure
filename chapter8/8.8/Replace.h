
#ifndef __REPLACE_H__
#define __REPLACE_H__


#include "../String.h"
//void Replace(String& source, int pos, const String& repstr);

void Replace(String& source, int pos, const String& repstr)
{
	int srclen=source.Length();
	int replen=repstr.Length();

	int chalen=(srclen-pos) > replen ?	replen : (srclen-pos);
	int i=0;
	while(i<chalen)
	{
		source[pos+i]=repstr[i];
		i++;
	}

	/*int i=0;
	if((srclen-pos)>replen)
	{
		while(i<replen)
		{
			source[pos+i]=repstr[i];
			i++;
		}
	}
	else
	{
		while(i<(srclen-pos))
		{
			source[pos+i]=repstr[i];
			i++;
		}
	}*/

	/*int chalen=	(srclen-pos) > replen ?	replen : (srclen-pos);
	int i;

	for(i=0; i<chalen-1; i++)
		source[pos+i]=repstr[i];
	std::cout<<(srclen-pos)<<": "<<replen<<std::endl;
	if((srclen-pos)<replen)			// 8<5
		source[pos+replen-1]='\0';*/
	
}

void Center(String & S)
{
	Replace(S, S.Length()/2, "%");
}

#endif
