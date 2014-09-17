

#ifndef	_BASEBALL_H
#define _BASEBALL_H

class Baseball
{
public:
	Baseball(int n=-1, int ab=0, int h=0);
	void ReadPlayer(void);
	void WritePlayer(void);
	float GetBatAve(void)const;
private:
	int playerno;			// player no
	int atbats;				// total times
	int hits;				// hits the target
	float batave;			// average
	float ComputeBatAve(void)const
	{
		if(playerno==-1||atbats==0)
			return 0;
		else
			return(float(hits)/atbats);
	}
};

#endif
