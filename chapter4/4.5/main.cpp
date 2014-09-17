
#include <iostream>
#include <iomanip>


#include "Student.h"


int main(int argc, char *argv[])
{
	int choice;
	SeqLink<Test> Submitted(30);
	SeqLink<Test> Borrowed(30);
	std::cout<<"1:����"<<std::setw(10)<<"2:ѧ�����"<<std::endl;
	std::cout<<"3:���ؽ�����Ծ�"<<std::setw(5)<<"4:�˳�"<<std::endl;

	std::cout<<"Enter your choice: ";
	std::cin>>choice;
	while(choice!=0)
	{
		switch(choice)
		{
		case 1:
			PutPapper(Submitted);
			break;
		case 2:
			BorrowPapper(Submitted, Borrowed);
			break;
		case 3:
			BackPapper(Submitted, Borrowed);
			break;
		case 4:
			ExitPaper(Submitted, Borrowed);
			break;
		default:
			break;
		}
		std::cout<<"Enter your choice: ";
		std::cin>>choice;
	}

	std::system("pause");
	return 0;
}