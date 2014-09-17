
#include <iostream>

#include <string>

using namespace std;

class Human
{
public:
	void run(int step);
	void sleep(void);
	void Print(void)
	{
		std::cout<<"Human"<<std::endl;
	}
private:
	int sex;
	string name;
};

class Man:public Human
{
public:
	Man(string name, int sex);
private:

};



int main(int argc, char *argv[])
{
	
	std::system("pause");
	return 0;
}
