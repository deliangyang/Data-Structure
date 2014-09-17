
#include <iostream>

using namespace std;

class SummerStudent
{
public:
	SummerStudent(int id, int rank, int socre);
	void SetId(int id);
	void SetRank(int rank);
	void SetSocre(int socre);
	int GetId(void)const;
	int GetRank(void)const;
	int GetSocre(void)const;
	void Print(void);
private:
	int id;
	int rank;
	int socre;	
};

SummerStudent::SummerStudent(int id, int rank, int score)
{
	this->id=id;
	this->rank=rank;
	this->socre=score;
}

void SummerStudent::SetId(int id)
{
	this->id=id;
}
void SummerStudent::SetRank(int rank)
{
	this->rank=rank;
}
void SummerStudent::SetSocre(int socre)
{
	this->socre=socre;
}

int SummerStudent::GetId(void)const
{
	return id;
}
int SummerStudent::GetRank(void)const
{
	return rank;
}
int SummerStudent::GetSocre(void)const
{
	return socre;
}
void SummerStudent::Print(void)
{
	std::cout<<"id: "<<id<<", rank: "<<rank<<", score: "<<socre<<std::endl;
}

int main(int argc, char *argv[])
{
	int i;
	SummerStudent student1(1047, 120, 40);
	SummerStudent student2(3050, 75, 20);
	SummerStudent student3(0020, 100, 75);

	student1.Print();
	student2.Print();
	student3.Print();

	student3.SetRank(40);
	student3.SetSocre(20);
	student3.Print();

	std::system("pause");
	return 0;
}
