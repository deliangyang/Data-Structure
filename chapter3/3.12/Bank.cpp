
#include <iostream>

using namespace std;

// i can't understand this question

class Event
{
public:
	Event();
	//int GetEvent(void)const;
	void Sever(int time);
	int GetTimeCount(void)const;
private:
	int timeCount;
};

Event::Event()
{
	timeCount=0;
}

void Event::Sever(int time)
{
	timeCount+=time;
}

int Event::GetTimeCount(void)const
{
	return timeCount;
}


int main(int argc, char *argv[])
{
	Event event;
	int i;
	int times;
	for(i=0; i<10; i++)
	{
		std::cin>>times;
		event.Sever(times);
	}

	std::cout<<"total time: "<<event.GetTimeCount()<<std::endl;

	std::system("pause");
	return 0;
}
